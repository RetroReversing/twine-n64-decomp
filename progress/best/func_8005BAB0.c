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

s32 func_80073AF8();
s32 func_80087100();
s32 sprintf();
extern s32 D_800C4428;
extern char D_800C4434[];
extern u8 D_80102F28;
extern void *D_80108788;
extern void *D_80109688;
extern u8 D_8010A91C;

void func_8005BAB0(void) {
    s32 sp30;
    char *var_s3;
    s32 temp_s0;
    s32 temp_s1;
    u32 temp_a1;
    u32 var_s2;

    M2C_FIELD(D_80109688, s32 *, 0x100) |= 0x40;
    M2C_FIELD(D_80109688, s8 *, 0x142) = 2;
    if (D_80108788 != NULL) {
        var_s2 = 0;
        if (M2C_FIELD(D_80108788, s32 *, 0x78) == 0x5A0000) {
            var_s3 = &D_800C4428;
            do {
                temp_a1 = M2C_FIELD(M2C_FIELD(D_80108788, void **, 0x70), u32 *, 0x30);
                if ((((temp_a1 >> 4) & 0xFFFF) == *(s32 *)var_s3) && ((temp_a1 >> 0x14) == *(D_800C4434 + (var_s2 * 4)))) {
                    D_8010A91C += 1;
                    temp_s1 = func_80087100(0xFA, temp_a1);
                    temp_s0 = func_80087100(0xFF);
                    sprintf(&sp30, "%s %d %s %d %s", temp_s1, D_8010A91C, temp_s0, (s32) D_80102F28, func_80087100(0xFE));
                    M2C_FIELD(D_80108788, s16 *, 0x7A) = 1;
                    func_80073AF8(0, D_80109688, &sp30, -1, -1, 1, 0, 0, 3, 0, 0);
                }
                var_s2 += 1;
                var_s3 += 4;
            } while (var_s2 < 3U);
        }
    }
}
