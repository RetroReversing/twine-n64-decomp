#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((u8 *)(expr) + (offset)))
extern s16 D_800F38D4;
extern s32 *D_800F38DC;
extern s32 D_800F8158;
extern s32 D_800F815C;
extern s32 func_800986EC(s32);
extern s32 *func_800956E0(s16 *, s32 *, s32, s32, s32 (*)(s32));
s32 func_8009852C(s16 arg0, u16 *arg1) {
    s32 ret;
    s16 *base;
    s32 *temp;
    base = &D_800F38D4;
    *base = arg0;
    temp = func_800956E0(base - 2, &D_800F815C, D_800F8158, 0xC, func_800986EC);
    D_800F38DC = temp;
    if (temp == NULL) {
        ret = 0;
    } else {
        *arg1 = M2C_FIELD(temp, u16 *, 6);
        ret = *D_800F38DC;
    }
    return ret;
}
