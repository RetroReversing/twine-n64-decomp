s32 func_80096E7C(void *a, s32 b);
s32 func_80096F44(void *a, s32 b, s16 c);
extern s8 D_80112E9E[];

s32 func_8009ABD4(void *arg0, u8 *arg1, s32 arg2) {
    s32 s1, s0, a2, a0;
    u8 v1;
    u32 w;
    u32 idx;
u32 __repair_phase_idx;

    w = *(u32 *)(arg1 + 4);
    if (arg1[0] != 0) {
        s1 = func_80096E7C(arg0, w & 0xFF);
    } else {
        idx = w & 0x1F;
        if (idx < 0x10U) {
            s1 = *(s16 *)((s8 *)arg0 + idx * 2 + 0x180);
        } else {
            s1 = *(s16 *)(D_80112E9E + idx * 2);
        }
    }
    v1 = arg2 & 0xFF;
    if (v1 == 4) {
        a0 = *(u32 *)(arg1 + 4) >> 8;
    } else {
        w = *(u32 *)(arg1 + 4);
        if ((w >> 8) & 0xFF) {
            a0 = func_80096E7C(arg0, (w >> 16) & 0xFF);
        } else {
            idx = (w >> 16) & 0x1F;
            if (idx < 0x10U) {
                a0 = *(s16 *)((s8 *)arg0 + idx * 2 + 0x180);
            } else {
                a0 = *(s16 *)(D_80112E9E + idx * 2);
            }
        }
        v1 = arg2 & 0xFF;
    }
    switch (v1) {
    case 0:
    case 4:
        s0 = (s16)s1 + (s16)a0;
        break;
    case 1:
        s0 = (s16)s1 - (s16)a0;
        break;
    case 2:
        s0 = (s16)s1 * (s16)a0;
        break;
    case 3:
        if ((s16)a0 != 0) {
            s0 = (s16)s1 / (s16)a0;
        } else {
            s0 = 0;
        }
        break;
    }
    w = *(u32 *)arg1;
    if (s0 < -0x8000) {
        a2 = -0x8000;
    } else {
        a2 = 0x7FFF;
        if (s0 <= 0x7FFF) a2 = s0;
    }
    if ((w >> 8) & 0xFF) {
        func_80096F44(arg0, (w >> 16) & 0xFF, (s16)a2);
        return 0;
    }
    __repair_phase_idx = (w >> 16) & 0x1F;
    if (__repair_phase_idx < 0x10U) {
        *(s16 *)((s8 *)arg0 + __repair_phase_idx * 2 + 0x180) = (s16)a2;
    } else {
        *(s16 *)(D_80112E9E + __repair_phase_idx * 2) = (s16)a2;
    }
    return 0;
}
