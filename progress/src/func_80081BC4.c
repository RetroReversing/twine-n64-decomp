/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

s32 func_80082164();
extern char sBonusSlotEntries[];
extern char D_80115091[];
extern char D_80115092[];
extern char D_80115094[];
extern char D_80115095[];

void func_80081BC4(s32 arg0, s32 arg1, s32 arg2) {
    long temp_v1;
    s32 var_a2;
    

    var_a2 = arg2;
    temp_v1 = arg0 * 0xA0;
    if (*(s16 *)(D_80115092 + temp_v1) != arg1) {
        *(s16 *)(D_80115092 + temp_v1) = arg1;
        switch (arg1) {
        case 6:
        case 7:
        default:
            *(sBonusSlotEntries + (arg0 * 0xA0)) = 0;
            var_a2 = 0;
            break;
        case 0:
        case 1:
        case 4:
        case 5:
            *(sBonusSlotEntries + (arg0 * 0xA0)) = 1;
            var_a2 = 0;
            break;
        }
        temp_v1 = arg0 * 0xA0;
        do {
            var_a2 += 1;
            *(D_80115095 + temp_v1) = 0;
            *(D_80115094 + temp_v1) = *(D_80115094 + temp_v1) & 0x1D;
            temp_v1 += 2;
        } while (0x3A > var_a2);
    }
    *(D_80115091 + (arg0 * 0xA0)) = (s8) arg1;
    func_80082164(arg0);
}
