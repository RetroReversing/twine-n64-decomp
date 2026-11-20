u32 func_80045CF8(s32);
extern u8 D_80102EE8;

s32 func_80017490(u32 arg0, u32 arg1, u32 arg2) {
    u32 chance;
    s32 ret;

    switch (D_80102EE8) {
    case 2:
        chance = arg2;
        break;
    case 0:
    default:
        chance = arg0;
        break;
    case 1:
        chance = arg1;
        break;
    }
    if (arg0 == 0 && arg1 == 0 && arg2 == 0) {
        chance = 100;
    }
    if (chance == 100) {
        ret = 1;
    } else if (chance == 0) {
        ret = 0;
    } else {
        ret = func_80045CF8(100) < chance;
    }
    return ret;
}
