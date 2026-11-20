extern s16 D_80109A58;
extern struct { u32 a,b,c; } D_800D42C8;
u32 func_80045CF8();
f32 func_80045D2C(f32);
void *func_800617D8(s32, s32, s32, f32 *, f32, f32, s32, s32, s32, s32, s32);
void func_80062450(void *, f32 *);
void func_8000A830(s16, s16, s32);
f32 __sinf(f32);
f32 __cosf(f32);

void func_80062CD8(u8 *arg0, s32 arg1, f32 arg2) {
    volatile u64 framepad[1];
    f32 __repair_fzero = 0.0f;
    volatile u32 spare[2];

    s16 tb[6] = { 0x22e, 0x22f, 0x230, 0x231, 0x232, 0x22d };
    f32 vec[3]; volatile u32 junk[2];
    u32 t;
    s32 idx;
    void *obj;
    u32 i;
    unsigned long s4;
    f32 r1;
    f32 r2;
    f32 a;
    u32 cnt;

    t = func_80045CF8(0x30);
    idx = (s16)(t >> 3);
    if (idx < 0) {
        idx = 0;
    }
    if (idx >= 6) {
        idx = 5;
    }
    cnt = t; cnt += 0x30;
    s4 = (arg0[0x7F] << 24) + (arg0[0x80] << 16) + (arg0[0x81] << 8) + 0xFF;
    func_8000A830(tb[idx], D_80109A58, 0xFF);
    i = 0;
    if (cnt != 0) {
        do {
            vec[0] = __repair_fzero;
            vec[1] = __repair_fzero;
            vec[2] = __repair_fzero;
            r2 = func_80045D2C(6.2831855f);
            r1 = func_80045D2C(6.2831855f);
            a = __sinf(r1) * arg2;
            vec[0] = a * __cosf(r2);
            a = __cosf(r1) * arg2;
            vec[2] = a * __cosf(r2);
            vec[1] = __sinf(r2) * arg2;
            obj = func_800617D8(*(s32 *)(arg0 + 0x20), arg1, 0, vec, 1.0f, 0.0f, func_80045CF8(2) + 0x17, 0xFB, 0x68, s4, 4);/*__repair_call_balance*/if(i){
            func_80062450(obj, vec);}else{
            func_80062450(obj, vec);}/*__repair_loop_weight*/do {
            i += 1;} while (0);
            *(f32 *)((u8 *)obj + 0x54) = *(f32 *)((u8 *)obj + 0x54) * 16.0f;
        } while (i < cnt);
    }
}
