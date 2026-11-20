void func_8003FDE0(u8 *arg0, s32 *arg1, s32 *arg2, s32 *arg3) {
    u8 *p = arg0;
    s32 raw;
s32 __repair_phase_raw;
    u32 opcode;
    
    s32 count;

    *arg1 = 0;
    *arg2 = 0;
    raw = *p;
    if ((u8)raw != 12) {
        opcode = raw & 255;
        do {
            switch (opcode) {
            case 9:
                p += 4;
                break;
            case 0:
                *arg1 = p[1] + *arg1;
                p++;
                raw = *p;
                *arg3 = 0;
                raw *= 3;
                goto skip;
            case 1:
                *arg1 = p[1] + *arg1;
                p++;
                raw = *p;
                *arg3 = 1;
                raw *= 3;
                goto double_size;
            case 3:
                *arg1 = p[1] + *arg1;
                p++;
                raw = *p;
                *arg3 = 3;
                goto skip;
            case 2:
                *arg1 = (*arg1) + (p[1]);
                p++;
                raw = *p;
                *arg3 = 2;
            double_size:
                raw *= 2;
            skip:
                p += raw + 1;
                break;
            case 6:
                p += 2;
                goto extra;
            case 7:
                p += 1;
                goto extra;
            case 8:
                p += 3;
            case 5:
            extra:
                count = p[1];
                p += 2;
                p += count * 3;
                *arg2 += count;
                break;
            case 4:
                p += 4;
                *arg2 += 1;
                break;
            case 10:
            case 11:
                p += 2;
                break;
            }
            __repair_phase_raw = *p;
            opcode = __repair_phase_raw & 255;
        } while (__repair_phase_raw != 12);
    }
}
