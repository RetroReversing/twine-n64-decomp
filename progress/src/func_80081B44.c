s32 func_800818AC(s32, s32);
f32 func_80081B44(s32 arg0, s32 arg1, s32 arg2) {
    s32 value = func_800818AC(arg0, arg1);
    if (value != 0) {
        value &= -(func_800818AC(arg0, arg2) == 0);
    } else {
        value = func_800818AC(arg0, arg2);
    }
    return (f32)value * 0.000015258789f;
}
