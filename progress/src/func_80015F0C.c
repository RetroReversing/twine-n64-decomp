typedef struct {
    u8 pad_0[0x1E];
    s16 field_1E;
    u8 pad_20[8];
    u32 hi : 16;
    u32 b : 4;
    u32 c : 4;
    u32 lo : 8;
} Obj15F0C;

Obj15F0C *func_800168D4(void *);
extern s32 D_800B3930;
extern s32 D_8010D268;

Obj15F0C *func_80015F0C(void) {
    Obj15F0C *p;

    p = func_800168D4(&D_8010D268);
    if (p != NULL) {
        p->field_1E = 0;
        D_800B3930++;
        p->b = 1;
        p->c = 1;
    }
    return p;
}
