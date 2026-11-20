typedef struct { u8 pad0[0x2C]; s32 w2C; } Sub5C8C4;
typedef struct { u8 pad0[0x60]; s32 w60; u8 pad64[8]; Sub5C8C4 *sub; u8 pad70[8]; u16 h78; u8 pad7A[2]; s16 h7C; } Obj5C8C4;

void func_8000A894(s32, s32);
void func_8005B5A8(void);
void func_80073AF8(s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
s32 func_80087100(s32);
extern Obj5C8C4 *gPlayerActor;
extern s32 gTrackAxisTable;

static inline s32 check_5C8C4(void) {
    Obj5C8C4 *p = gPlayerActor;
    s32 r = 0;
    s32 v;
    Sub5C8C4 *sub;

    if (p != NULL) {
        v = p->h78;
        if (v < 0x13) {
            if (v < 0x11) {
                return r;
            }
            sub = p->sub;
            if (p->h7C == 0) {
                s32 mask = 0x08000000;
                s32 sound = 0x12E;
                p->h7C = 1;
                if (sub->w2C & mask) {
                    p->w60 |= mask;
                    func_8000A894(sound, mask);
                    func_80073AF8(0, gTrackAxisTable, func_80087100(0x160), -1, -1, 1, 0, 0, 3, 0, 0);
                }
            }
            r = 1;
        }
    }
    return r;
}

void func_8005C8C4(void) {
    if (!check_5C8C4()) {
        func_8005B5A8();
    }
}
