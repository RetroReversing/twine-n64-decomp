extern s16 D_800CF330[];
extern s16 D_800CF334[];
extern f32 D_800CF534[];
extern f64 D_800D67C0;
extern f64 D_800D67C8;
extern f64 D_800D67D0;
extern f64 D_800D67D8;
extern f64 D_800D67E0;
extern f64 D_800D67E8;

void func_8008C870(s16 *arg0, s16 *arg1, u32 arg2, u32 arg3, u32 arg4, s16 *arg5, u32 arg6, s16 *arg7) {
    u32 a2 = arg2;
    u32 t3 = arg6;
    if (a2 > 0x7F0000U) a2 = 0x7F0000;
    *arg5 = (s16)(s32)(((1.0f - (f32)((f64)(a2 & 0xFFFF) * 0.000015258789)) ) * 0.0f);
}
