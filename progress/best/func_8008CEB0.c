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

s32 func_8008C1B0(u32);                             /* extern */
M2C_UNK func_800968A4(u8, u8, u8);                  /* extern */
s32 func_800988D8(void *);                          /* extern */
M2C_UNK func_80099B64(M2C_UNK *);                   /* extern */
M2C_UNK voiceListRemove(void *, s32, s32, u8);      /* extern */
extern M2C_UNK D_8010D734;
extern u8 sVoiceCount;
extern M2C_UNK sVoiceTable;

s32 func_8008CEB0(s32 arg0, u8 arg1, u8 arg2) {
    u8 sp17;
    u8 sp1F;
    M2C_UNK *var_s1;
    M2C_UNK *var_s6;
    s16 temp_fp;
    s32 temp_a0;
    s32 temp_a1_2;
    s32 temp_a2;
    s32 temp_a2_2;
    s32 temp_hi;
    s32 var_s4;
    s32 var_s5;
    s32 var_s7;
    u16 temp_a1;
    u32 var_s3;
    u8 temp_a3;
    void *temp_s2;
    void *var_s0;

    var_s4 = -1;
    var_s6 = &sVoiceTable;
    var_s3 = 0;
    sp17 = arg1;
    sp1F = arg2;
    if (sVoiceCount != 0) {
        temp_fp = arg0 & 0xFF;
        var_s0 = &sVoiceTable + 0x24;
        var_s7 = 0;
        do {
            if ((M2C_FIELD(var_s0, s32 *, 0x3C) != -1) && (M2C_FIELD(var_s0, u8 *, 0x26) == sp17) && (M2C_FIELD(var_s0, u8 *, 0x27) == sp1F)) {
                temp_a0 = M2C_FIELD(var_s0, s32 *, 0);
                if ((temp_a0 & 0x10) && ((temp_a0 & 0x40000008) != 8) && (func_8008C1B0(var_s3) & 0xFF)) {
                    temp_a3 = M2C_FIELD(var_s0, u8 *, 0x2B);
                    temp_s2 = var_s7 + &sVoiceTable;
                    temp_a2 = M2C_FIELD(var_s0, s8 *, 0x9C) << 0x10;
                    temp_hi = MULT_HI(temp_a2, 0x51EB851F);
                    temp_a1 = M2C_FIELD(var_s0, u16 *, 0x2C);
                    var_s1 = var_s6;
                    M2C_FIELD(var_s0, s16 *, 0x2A) = temp_fp;
                    M2C_FIELD(var_s0, s8 *, 0x9C) = 0;
                    M2C_FIELD(var_s0, s32 *, 0x68) = 0;
                    M2C_FIELD(var_s0, s8 *, 0x9D) = (s8) M2C_FIELD(var_s0, u16 *, 0x2C);
                    temp_a2_2 = temp_a2 >> 0x1F;
                    M2C_FIELD(var_s0, u16 *, 0x2C) = (u16) (temp_fp + (M2C_FIELD(var_s0, u8 *, 0x2D) - temp_a3));
                    M2C_FIELD(var_s0, s32 *, 0) = (s32) (M2C_FIELD(var_s0, s32 *, 0) | 0x80800);
                    temp_a1_2 = (temp_a1 << 0x10) + ((temp_hi >> 5) - temp_a2_2);
                    M2C_FIELD(var_s0, s32 *, 0x70) = temp_a1_2;
                    voiceListRemove(temp_s2, temp_a1_2, temp_a2_2, temp_a3);
                    if (var_s4 == -1) {
                        M2C_FIELD(var_s1, s32 *, 0x10) = var_s4;
                        M2C_FIELD(var_s1, s32 *, 0x14) = var_s4;
                        var_s4 = func_800988D8(temp_s2);
                    } else {
                        *(&D_8010D734 + ((var_s5 & 0xFF) * 0x1A0)) = M2C_FIELD(var_s1, s32 *, 0x60);
                        M2C_FIELD(var_s1, s32 *, 0x14) = var_s5;
                    }
                    var_s5 = M2C_FIELD(var_s1, s32 *, 0x60);
                }
            }
            var_s7 += 0x1A0;
            var_s3 += 1;
            var_s0 += 0x1A0;
            var_s6 += 0x1A0;
        } while (var_s3 < (u8) sVoiceCount);
    }
    if (var_s4 != -1) {
        func_80099B64(var_s1);
        func_800968A4(M2C_FIELD(var_s1, u8 *, 0x4A), M2C_FIELD(var_s1, u8 *, 0x4B), M2C_FIELD(var_s1, u8 *, 0x51));
    }
    return var_s4;
}
