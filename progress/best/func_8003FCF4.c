s32 func_8003FCF4(void *arg0) {
    s32 temp_a1;
    s32 temp_a0;
    s32 var_v1;

    temp_a1 = *(s32 *)((s8 *)arg0 + 0x3C);
    var_v1 = (-((temp_a1 & 1) == 0) & 0x600) | 0x200;
    if (temp_a1 & 0x40000) {
        var_v1 &= 0x400;
    }
    if (temp_a1 & 0x100000) {
        var_v1 |= 0x20000000;
    }
    if (temp_a1 & 2) {
        var_v1 |= 0x800;
    }
    if (temp_a1 & 0x80) {
        var_v1 |= 2;
    }
    if (temp_a1 & 0x10) {
        var_v1 |= 4;
    }
    if (temp_a1 & 0x20) {
        var_v1 |= 8;
    }
    if (temp_a1 & 0x100) {
        var_v1 |= 1;
    }
    if (temp_a1 & 0x40) {
        var_v1 |= 0x10;
    }
    if (temp_a1 & 8) {
        var_v1 |= 0x20;
    }
    temp_a0 = (u16) temp_a1;
    if (temp_a0 & 0x400) {
        var_v1 |= 0x80;
    }
    if (temp_a0 & 0x200) {
        var_v1 |= 0x40;
    }
    if (temp_a0 & 0x4000) {
        var_v1 |= 0x100000;
    }
    if (temp_a0 & 0x8000) {
        var_v1 |= 0x200000;
    }
    if (temp_a1 & 0x80000) {
        var_v1 |= 0x800000;
    }
    return var_v1;
}
