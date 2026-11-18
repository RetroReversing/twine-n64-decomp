/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */
#ifndef M2C_DEFINES
#define M2C_DEFINES
typedef s32 M2C_UNK;
typedef s8 M2C_UNK8;
typedef s16 M2C_UNK16;
typedef s32 M2C_UNK32;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define M2C_CARRY 0
#define M2C_OVERFLOW(a) (0)
#endif

s32 func_80034928();
extern u8 D_801002E5;
extern u8 D_80100774;
extern u8 D_80100775;
extern u8 D_80100776;
extern u8 D_80100777;
extern u8 D_80100778;
extern u8 D_80100779;
extern u8 D_8010077A;
extern u8 D_8010077B;
extern u8 D_8010077C;
extern u8 D_801007CC;
extern u8 D_801007CD;
extern u8 D_801007CE;
extern u8 D_801007CF;
extern u8 D_801007D0;
extern u8 D_801007D1;
extern u8 D_801007D2;
extern u8 D_801007D3;
extern u8 D_801007D4;
extern u8 D_80102F38;
extern u8 D_801032A4;
extern u8 D_80108F74;
extern u8 D_801093A0;
extern u8 D_8010A3C4;
extern u8 D_8010A4B8;
extern void *D_8010A4D8;
extern u8 D_80110CA8;
extern u8 D_80110DB1;
extern void *D_80115328;

void func_800349B4(void *arg0) {
    s32 temp_v1;
    u8 var_s1;
    u8 var_s2;
    u8 var_s3;
    void *temp_a0;
    void *temp_a3;

    var_s2 = 0;
    var_s1 = 0;
    var_s3 = 0;
    if (M2C_FIELD(arg0, s32 *, 0x100) & 1) {
        M2C_FIELD(arg0, u8 *, 0x145) = 0U;
        M2C_FIELD(arg0, u8 *, 0x144) = 0U;
        M2C_FIELD(arg0, u8 *, 0x143) = 0U;
        M2C_FIELD(arg0, u8 *, 0x146) = 0xFFU;
        func_80034928(arg0, D_8010A4D8);
    }
    if (M2C_FIELD(arg0, s32 *, 0x100) & 4) {
        M2C_FIELD(arg0, u8 *, 0x143) = (u8) D_801093A0;
        M2C_FIELD(arg0, u8 *, 0x144) = (u8) D_801002E5;
        M2C_FIELD(arg0, u8 *, 0x146) = 0xFFU;
        M2C_FIELD(arg0, u8 *, 0x145) = (u8) D_80110CA8;
        func_80034928(arg0, D_8010A4D8);
    }
    if (M2C_FIELD(arg0, s32 *, 0x100) & 2) {
        M2C_FIELD(arg0, u8 *, 0x143) = (u8) D_8010A3C4;
        M2C_FIELD(arg0, u8 *, 0x144) = (u8) D_8010A4B8;
        M2C_FIELD(arg0, u8 *, 0x146) = 0xFFU;
        M2C_FIELD(arg0, u8 *, 0x145) = (u8) D_80110DB1;
        func_80034928(arg0, (void *)2);
    }
    temp_a3 = D_80115328;
    D_80115328 = temp_a3 + 8;
    M2C_FIELD(temp_a3, s32 *, 0) = 0xFB000000;
    M2C_FIELD(temp_a3, s32 *, 4) = (s32) ((M2C_FIELD(arg0, u8 *, 0x143) << 0x18) | (M2C_FIELD(arg0, u8 *, 0x144) << 0x10) | (M2C_FIELD(arg0, u8 *, 0x145) << 8) | M2C_FIELD(arg0, u8 *, 0x146));
    temp_v1 = M2C_FIELD(arg0, s32 *, 0x100);
    if (temp_v1 & 2) {
        var_s2 = 0;
        M2C_FIELD(temp_a3, s32 *, 8) = 0xDB080000;
        D_80115328 = temp_a3 + 0x10;
        M2C_FIELD(temp_a3, s32 *, 0xC) = (s32) (((D_801007CD + 0x7530) << 0x10) | ((D_801007CE - 0x7530) & 0xFFFF));
        var_s1 = (D_801007CF + D_801007D0 + D_801007D1) / 3;
    } else if (temp_v1 & 4) {
        var_s2 = 0;
        M2C_FIELD(temp_a3, s32 *, 8) = 0xDB080000;
        var_s1 = 0;
        M2C_FIELD(temp_a3, s32 *, 0xC) = (s32) (((D_801007CD + (D_801007CC * 0x78)) << 0x10) | (((D_801007CC * -0x78) + D_801007CE) & 0xFFFF));
        D_80115328 = temp_a3 + 0x10;
        D_80102F38 = D_801007D2;
        D_80108F74 = D_801007D3;
        D_801032A4 = D_801007D4;
        var_s3 = 0x40;
    } else {
        if (temp_v1 & 1) {
            var_s2 = D_801007CF;
            var_s1 = D_801007D0;
            var_s3 = D_801007D1;
            M2C_FIELD(temp_a3, s32 *, 8) = 0xDB080000;
            M2C_FIELD(temp_a3, s32 *, 0xC) = (s32) (((D_801007CD + (D_801007CC * 0x78)) << 0x10) | (((D_801007CC * -0x78) + D_801007CE) & 0xFFFF));
            D_80115328 = temp_a3 + 0x10;
            D_80102F38 = D_801007D2;
            D_80108F74 = D_801007D3;
            D_801032A4 = D_801007D4;
        }
        if (M2C_FIELD(arg0, s32 *, 0x100) & 8) {
            var_s2 = D_80100777;
            var_s1 = D_80100778;
            var_s3 = D_80100779;
            M2C_FIELD(D_80115328, s32 *, 0) = 0xDB080000;
            M2C_FIELD(D_80115328, s32 *, 4) = (s32) (((D_80100775 + (D_80100774 * 0x78)) << 0x10) | (((D_80100774 * -0x78) + D_80100776) & 0xFFFF));
            D_80115328 += 8;
            D_80102F38 = D_8010077A;
            D_80108F74 = D_8010077B;
            D_801032A4 = D_8010077C;
        }
    }
    temp_a0 = D_80115328;
    D_80115328 = temp_a0 + 8;
    M2C_FIELD(temp_a0, s32 *, 0) = 0xF8000000;
    M2C_FIELD(temp_a0, s32 *, 4) = (s32) ((var_s2 << 0x18) | ((var_s1 & 0xFF) << 0x10) | (var_s3 << 8) | 0xFF);
}
