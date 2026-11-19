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
    u8 padFEF[9];
} EntSnd;

extern EntSnd D_800E5AC4[];

static inline s32 find_snd(s32 id) {
    u32 i = 0;
    s32 key = id & 0x7FFFFFFF;
    s32 off = 0;

    for (; i < 8; i++, off += sizeof(EntSnd)) {
        if (*((u8 *)&D_800E5AC4[0].busy + off) == 0 && *(s32 *)((u8 *)&D_800E5AC4[0].id + off) == key) {
            return i | (id & 0x80000000);
        }
    }
    return -1;
}

extern SndNode *D_800E5AC0;
void func_80099708(s32);

void func_80090A4C(s32 arg0) {
    SndNode *n;
    EntSnd *e;
    EntSnd *f;
    SndNode *m;

    arg0 = find_snd(arg0);
    if (arg0 == -1) {
        return;
    }
    if (arg0 >= 0) {
        if (D_800E5AC4[arg0].active != 0 && D_800E5AC4[arg0].busy == 0) {
            e = &D_800E5AC4[arg0];
            D_800E5AC4[arg0].active = 0;
            for (n = e->listF78; n != NULL; n = n->next) {
                func_80099708(n->h);
            }
            for (n = e->listF7C; n != NULL; n = n->next) {
                func_80099708(n->h);
            }
            f = &D_800E5AC4[arg0];
            m = f->listF78;
            if (m != NULL) {
                while (m->next != NULL) {
                    m = m->next;
                }
                if (D_800E5AC0 != NULL) {
                    m->next = D_800E5AC0;
                    D_800E5AC0->prev = m;
                }
                D_800E5AC0 = f->listF78;
                f->listF78 = NULL;
            }
            m = f->listF7C;
            if (m != NULL) {
                while (m->next != NULL) {
                    m = m->next;
                }
                if (D_800E5AC0 != NULL) {
                    m->next = D_800E5AC0;
                    D_800E5AC0->prev = m;
                }
                D_800E5AC0 = f->listF7C;
                f->listF7C = NULL;
            }
        }
    } else {
        arg0 &= 0x7FFFFFFF;
        if (D_800E5AC4[arg0].active != 0 && D_800E5AC4[arg0].busy == 0) {
            D_800E5AC4[arg0].flags |= 8;
        }
    }
}
