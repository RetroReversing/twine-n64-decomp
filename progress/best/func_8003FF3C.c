#define FLD(p, t, o) (*(t *)((u8 *)(p) + (o)))
#define BE16(p) ((u16)(((p)[0] << 8) | (p)[1]))

void buildPlaneFromPoints(void *, s32, s32, s32);

void func_8003FF3C(void *arg0, u8 *arg1, s16 *arg2) {
    register void *var_t1 = arg0;
    register u8 *var_s0 = arg1;
    register s16 *var_t0 = arg2;
    register unsigned long var_s7 = 3;
    u8 *var_s1 = NULL;
    s16 *var_s6 = NULL;
    u8 *var_s5 = NULL;
    register u8 *var_s2;
    s16 *var_s4;
    register u8 var_t2;
    u32 var_fp;
    u8 *var_s3;
    s32 a2_2, a3_2, v1_2;
    s32 a2, a3, v1;
    unsigned int base;
    u32 sp10[3];
    register unsigned long tmp8;
    u16 t16, t16b, t16c;

    if (FLD(var_t1, u8, 0x48) & 4) {
        var_s6 = FLD(var_t1, s16 *, 0x3C);
    } else {
        var_s5 = FLD(var_t1, u8 *, 0x3C);
    }
    goto loop_48;
dispatch:
    switch (var_s0[0]) {
    case 9:
        var_s0 += 4;
        goto loop_48;
    case 0:
        var_s1 = var_s0 + 2;
        ++var_s0;
        var_s7 = 0;
        var_s0 += 1 + var_s0[0] * 3;
        goto loop_48;
    case 1:
        var_s1 = var_s0 + 2;
        ++var_s0;
        var_s7 = 1;
        var_s0 += 1 + var_s0[0] * 6;
        goto loop_48;
    case 3:
        var_s1 = var_s0 + 2;
        ++var_s0;
        var_s7 = 3;
        var_s0 += 1 + var_s0[0] * 1;
        goto loop_48;
    case 2:
        var_s1 = var_s0 + 2;
        ++var_s0;
        var_s7 = 2;
        var_s0 += 1 + var_s0[0] * 2;
        goto loop_48;
    case 6:
        {
            u8 value = var_s0[1];
            var_s0 += 2;
            FLD(var_t1, u8, 0x44) = value;
        }
        goto block_15;
    case 7: {
        u8 value = var_s0[1];
        ++var_s0;
        FLD(var_t1, u8, 0x44) = value;
        goto block_15;
    }
    case 8:
        var_s0 += 3;
    case 5:
block_15:
        var_t2 = var_s0[1];
        var_s0 += 2;
        var_fp = 0;
        if (var_t2) {
            var_s4 = var_s6 + 4;
            var_s3 = var_s5 + 2;
            var_s2 = var_s0 + 2;
            do {
                switch (var_s7) {
                case 3:
                    tmp8 = var_s1[var_s0[0]];
                    *var_s5 = tmp8;
                    tmp8 = var_s1[var_s2[-1]];
                    a2 = var_s1[var_s0[0]] & 0xFF;
                    var_s3[-1] = tmp8;
                    var_s5 += 3;
                    tmp8 = var_s1[var_s2[0]];
                    a3 = tmp8 & 0xFF;
                    goto block_27;
                case 2:
                    t16 = BE16(var_s1 + var_s0[0] * 2);
                    *var_s6 = t16;
                    t16b = BE16(var_s1 + var_s2[-1] * 2);
                    var_s4[-2] = t16b;
                    a2 = t16 & 0xFFFF;
                    var_s6 += 3;
                    tmp8 = var_s2[0];
                    t16c = BE16(var_s1 + tmp8 * 2);
                    v1 = t16c & 0xFFFF;
                    a3 = t16b & 0xFFFF;
                    var_s4[0] = t16c;
                    var_s4 += 3;
                    break;
                case 0:
                    tmp8 = var_s1[var_s0[0] * 3];
                    a2 = var_s1[var_s0[0] * 3] & 0xFF;
                    *var_s5 = tmp8;
                    tmp8 = var_s1[var_s2[-1] * 3];
                    var_s3[-1] = tmp8;
                    var_s5 += 3;
                    a3 = tmp8 & 0xFF;
                    tmp8 = var_s1[var_s2[0] * 3];
                    goto block_27;
                default:
                    t16 = BE16(var_s1 + var_s0[0] * 6);
                    *var_s6 = t16;
                    t16b = BE16(var_s1 + var_s2[-1] * 6);
                    var_s4[-2] = t16b;
                    a2 = t16 & 0xFFFF;
                    var_s6 += 3;
                    tmp8 = var_s2[0] * 3;
                    t16c = BE16(var_s1 + tmp8 * 2);
                    a3 = t16b & 0xFFFF;
                    v1 = t16c & 0xFFFF;
                    var_s4[0] = t16c;
                    var_s4 += 3;
                    break;
                }
                goto after;
block_27:
                v1 = tmp8 & 0xFF;
                var_s3[0] = tmp8;
                var_s3 += 3;
after:
                var_s2 += 3;
                base = FLD(var_t1, s32, 0x34);
                buildPlaneFromPoints(&sp10, base + a2 * 12, base + a3 * 12, base + v1 * 12);
                var_s0 += 3;
                var_fp += 1;
                *var_t0 = 0;
                var_t0++;
            } while (var_fp < var_t2);
        }
        goto loop_48;
    case 4:
        switch (var_s7) {
        case 3:
            tmp8 = var_s1[var_s0[1]];
            var_s5[0] = tmp8;
            v1 = var_s1[var_s0[2]];
            var_s5[1] = (u8)v1;
            tmp8 = var_s1[var_s0[3]];
            a2_2 = var_s1[var_s0[1]] & 0xFF;
            a2_2 = var_s5[0];
            a3_2 = v1 & 0xFF;
            v1_2 = tmp8 & 0xFF;
            var_s5[2] = tmp8;
            var_s5 += 3;
            break;
        case 2:
            t16 = BE16(var_s1 + var_s0[1] * 2);
            var_s6[0] = t16;
            t16b = BE16(var_s1 + var_s0[2] * 2);
            var_s6[1] = t16b;
            tmp8 = var_s0[3];
            a2_2 = t16 & 0xFFFF;
            t16c = BE16(var_s1 + tmp8 * 2);
            a3_2 = t16b & 0xFFFF;
            v1_2 = t16c & 0xFFFF;
            var_s6[2] = t16c;
            var_s6 += 3;
            break;
        case 0:
            tmp8 = var_s1[var_s0[1] * 3];
            var_s5[0] = tmp8;
            v1 = var_s1[var_s0[2] * 3];
            var_s5[1] = (u8)v1;
            tmp8 = var_s1[var_s0[3] * 3];
            a2_2 = var_s1[var_s0[1] * 3] & 0xFF;
            a3_2 = v1 & 0xFF;
            v1_2 = tmp8 & 0xFF;
            var_s5[2] = tmp8;
            var_s5 += 3;
            break;
        default:
            t16 = BE16(var_s1 + var_s0[1] * 6);
            var_s6[0] = t16;
            t16b = BE16(var_s1 + var_s0[2] * 6);
            var_s6[1] = t16b;
            tmp8 = var_s0[3] * 3;
            a2_2 = t16 & 0xFFFF;
            t16c = BE16(var_s1 + tmp8 * 2);
            v1_2 = t16c & 0xFFFF;
            a3_2 = t16b & 0xFFFF;
            var_s6[2] = t16c;
            var_s6 += 3;
            break;
        }
        base = FLD(var_t1, s32, 0x34);
        buildPlaneFromPoints(&sp10, base + a2_2 * 12, base + a3_2 * 12, base + v1_2 * 12);
        var_s0 += 4;
        *var_t0 = 0;
        var_t0++;
        goto loop_48;
    case 10:
        FLD(var_t1, u8, 0x44) = var_s0[1];
        var_s0 += 2;
        goto loop_48;
    case 11:
        var_s0 += 2;
        goto loop_48;
    default:
        goto loop_48;
    }
loop_48:
    if (var_s0[0] != 12) goto dispatch;
}
