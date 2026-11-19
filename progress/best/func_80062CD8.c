extern s16 D_80109A58;
extern u8 D_800D42C8[];
u32 func_80045CF8();
f32 func_80045D2C(f32);
void *func_800617D8(s32, s32, s32, f32 *, f32, f32, s32, s32, s32, s32, s32);
void func_80062450(void *, f32 *);
void func_8000A830(s16, s16, s32);
f32 __sinf(f32);
f32 __cosf(f32);

void func_80062CD8(u8 *arg0, s32 arg1, f32 arg2) {
    s16 tb[6] = { 0x22e, 0x22f, 0x230, 0x231, 0x232, 0x22d };
    f32 vec[3];
    u32 t;
    s32 idx;
    u32 cnt;
    u32 i;
    s32 s4;
    f32 r1;
    f32 r2;
    f32 a;
    void *obj;

    t = func_80045CF8(0x30, D_800D42C8);
    idx = (s16)(t >> 3);
    if (idx < 0) {
        idx = 0;
    }
    if (idx >= 6) {
        idx = 5;
    }
    cnt = t + 0x30;
    s4 = (arg0[0x7F] << 24) + (arg0[0x80] << 16) + (arg0[0x81] << 8) + 0xFF;
    func_8000A830(tb[idx], D_80109A58, 0xFF);
    i = 0;
    if (cnt != 0) {
        do {
            vec[0] = 0.0f;
            vec[1] = 0.0f;
            vec[2] = 0.0f;
            r1 = func_80045D2C(6.2831855f);
            r2 = func_80045D2C(6.2831855f);
            a = __sinf(r1) * arg2;
            vec[0] = a * __cosf(r2);
            a = __cosf(r1) * arg2;
            vec[2] = a * __cosf(r2);
            vec[1] = __sinf(r2) * arg2;
            obj = func_800617D8(*(s32 *)(arg0 + 0x20), arg1, 0, vec, 1.0f, 0.0f, func_80045CF8(2) + 0x17, 0xFB, 0x68, s4, 4);
            func_80062450(obj, vec);
            i += 1;
            *(f32 *)((u8 *)obj + 0x54) = *(f32 *)((u8 *)obj + 0x54) * 16.0f;
        } while (i < cnt);
    }
}
