typedef struct SndNode { struct SndNode *next; struct SndNode *prev; s32 h; } SndNode;

typedef struct {
    s32 id;            /* 0x000 */
    u8 pad4[0x10C];
    s32 w110;          /* 0x110 */
    s32 w114;          /* 0x114 */
    u8 pad118[0x410];
    u8 tbl528[0x80];   /* 0x528 */
    u8 pad5A8[0x9D0];
    struct SndNode *listF78;   /* 0xF78 */
    struct SndNode *listF7C;   /* 0xF7C */
    u8 padF80[0x40];
    u8 active;         /* 0xFC0 */
    u8 busy;           /* 0xFC1 */
    s16 hFC2;          /* 0xFC2 */
    u8 bFC4;           /* 0xFC4 */
    u8 bFC5;           /* 0xFC5 */
    u8 padFC6[0x1E];
    s32 wFE4;          /* 0xFE4 */
    s32 wFE8;          /* 0xFE8 */
    s16 hFEC;          /* 0xFEC */
    u8 flags;          /* 0xFEE */
    u8 padFEF[1];
    s32 wFF0;          /* 0xFF0 */
    u8 padFF4[4];
} EntSnd;

extern EntSnd gSndEntities[];

static inline s32 find_snd(s32 id) {
    u32 i = 0;
    s32 key = id & 0x7FFFFFFF;
    s32 off = 0;

    for (; i < 8; i++, off += sizeof(EntSnd)) {
        if (*((u8 *)&gSndEntities[0].busy + off) == 0 && *(s32 *)((u8 *)&gSndEntities[0].id + off) == key) {
            return i | (id & 0x80000000);
        }
    }
    return -1;
}

extern SndNode *gFreeSndNodeList;
void func_80099708(s32);

/* Stops the sound entry for id: stops its active nodes and moves both node lists onto the free list; otherwise clears the entry's wFF0 when not busy. */ void func_80090CD4(s32 slot) {
    SndNode *node;
    EntSnd *ent;
    EntSnd *ent_fn;
    SndNode *tail;

    slot = find_snd(slot);
    if (slot == -1) {
        return;
    }
    if (slot >= 0) {
        if (gSndEntities[slot].active != 0 && gSndEntities[slot].busy == 0) {
            ent = &gSndEntities[slot];
            gSndEntities[slot].active = 0;
            for (node = ent->listF78; node != NULL; node = node->next) {
                func_80099708(node->h);
            }
            for (node = ent->listF7C; node != NULL; node = node->next) {
                func_80099708(node->h);
            }
            ent_fn = &gSndEntities[slot];
            tail = ent_fn->listF78;
            if (tail != NULL) {
                while (tail->next != NULL) {
                    tail = tail->next;
                }
                if (gFreeSndNodeList != NULL) {
                    tail->next = gFreeSndNodeList;
                    gFreeSndNodeList->prev = tail;
                }
                gFreeSndNodeList = ent_fn->listF78;
                ent_fn->listF78 = NULL;
            }
            tail = ent_fn->listF7C;
            if (tail != NULL) {
                while (tail->next != NULL) {
                    tail = tail->next;
                }
                if (gFreeSndNodeList != NULL) {
                    tail->next = gFreeSndNodeList;
                    gFreeSndNodeList->prev = tail;
                }
                gFreeSndNodeList = ent_fn->listF7C;
                ent_fn->listF7C = NULL;
            }
        }
        gSndEntities[slot].busy = 1;
    } else {
        slot &= 0x7FFFFFFF;
        if (gSndEntities[slot].active != 0 && gSndEntities[slot].busy == 0) {
            gSndEntities[slot].wFF0 = 0;
        }
    }
}
