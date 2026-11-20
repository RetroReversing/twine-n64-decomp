s32 func_8001226C(s32);
u16 func_8001233C(void);
s32 func_80012F50();
extern u16 D_800BFC32;
extern s32 D_800E0978;
u16 func_80012A0C(s32 arg0) {
    s32 temp_a0;
    temp_a0 = arg0 & 0xFFFF;
    D_800BFC32 = 1;
    D_800E0978 = temp_a0;
    if (!(func_80012F50() & 0xFFFF)) {
        if ((func_8001226C(D_800E0978) == 0) || (D_800E0978 >= 0x10)) {
            D_800BFC32 = 0x82;
            return 0x82U;
        }
        if (!(func_8001233C() & 0xFFFF)) {
            D_800BFC32 = 1;
            return 1U;
        }
    }
    return D_800BFC32;
}
