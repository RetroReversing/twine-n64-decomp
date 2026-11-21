typedef struct SndNode { struct SndNode *next; struct SndNode *prev; s32 id; } SndNode;
typedef struct { u32 time; s32 val; } SeqEvt;
typedef struct {
    u8 pad0[0x118];
    s32 f118;
    s32 f11C;
    s32 f120;
    u32 f124;
    u8 pad128[0xF68 - 0x128];
    s32 active;
    SeqEvt *evt;
    s32 f70;
    s32 f74;
    u8 pad78[4];
    SndNode *nodes;
} SeqPlayer;
void func_8008CDC0(s32, u8, void *);
s8 func_8008EF18(u8);
s32 func_8008FB20();
void func_8008FF80();
s32 seqUpdateNoteList();
s32 func_80090464(s32);
s32 func_8009CCB0(s32);
void updateSeqChannels();
void updateSeqChannelsAlt();
extern u8 D_800E6A84;
extern u8 D_800E6A85;
extern u8 D_800E6A88;
extern u32 D_800EDA84;
extern u8 D_800EDA87;
extern s8 D_800EDA88;
extern s32 D_801002D8;
extern s32 gAudioOutputRate;
extern SndNode *gFreeSndNodeList;
extern SeqPlayer *gSeqPlayer;
extern u8 gSoundEntities;
void func_800923D0(void) {
    s32 s5, s4, s3;
    u32 i;
    u8 *p;
    s32 off;
    SeqPlayer *pl;
    SndNode *n, *next;
    u32 t;
    if (D_801002D8 != 0) {
        p = &D_800E6A84;
        off = 0;
        for (i = 0; i < 8; i++) {
            if (*p != 0) {
                gSeqPlayer = (SeqPlayer *)(&gSoundEntities + off);
                D_800EDA84 = i;
                D_800EDA88 = func_8008EF18((&D_800E6A88)[off]);
                pl = gSeqPlayer;
                if (pl->active != 0 && pl->evt->time != -1) {
                    SeqEvt *e, *o;
                loop:
                    e = pl->evt;
                    if ((u32)(pl->f74 + pl->f120) >= e->time) {
                        s32 a0 = e->val;
                        pl->f124 = a0;
                        func_8008CDC0(a0, D_800EDA87, pl);
                        o = gSeqPlayer->evt;
                        gSeqPlayer->evt = o + 1;
                        pl = gSeqPlayer;
                        if (*(s32 *)&o[1].time != -1) goto loop;
                    }
                }
                pl = gSeqPlayer;
                t = ((u32)(((pl->f124 * 0xC00) / 60) * ((s32)(D_801002D8 << 16) / gAudioOutputRate)) >> 3) * *(u16 *)((u8 *)pl + 0xFC2);
                pl->f11C = t >> 24;
                pl->f118 = (t >> 8) & 0xFFFF;
                pl->f120 = (s32)pl->f11C >> 1;
                if (pl->active != 0) {
                    u32 v = pl->f70 + pl->f118;
                    pl->f70 = v & 0xFFFF;
                    pl->f74 = pl->f74 + ((v >> 16) + pl->f11C);
                }
                s5 = func_80090464(pl->active);
                s4 = func_8008FB20();
                updateSeqChannelsAlt();
                updateSeqChannels();
                func_8008FF80();
                n = gSeqPlayer->nodes;
                s3 = seqUpdateNoteList();
                while (n != NULL) {
                    next = n->next;
                    if (func_8009CCB0(n->id) == -1) {
                        if (n->next != NULL) n->next->prev = n->prev;
                        if (n->prev != NULL) n->prev->next = n->next;
                        else gSeqPlayer->nodes = n->next;
                        n->next = gFreeSndNodeList;
                        if (gFreeSndNodeList != NULL) gFreeSndNodeList->prev = n;
                        n->prev = NULL;
                        gFreeSndNodeList = n;
                    }
                    n = next;
                }
                if (!(s5 & 0xFF) & !(s4 & 0xFF) && !(s3 & 0xFF)) {
                    *p = 0;
                    (&D_800E6A85)[off] = 1;
                }
            }
            p += 0xFF8;
            off += 0xFF8;
        }
    }
}
