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

s32 func_8000A894();
s32 func_8005B5A8();
s32 func_80073AF8();
s32 func_80087100();
s32 sprintf();
extern u8 D_80100300;
extern u8 D_801007D8;
extern void *D_80108788;
extern s32 D_80109688;

void func_8005B958(void) {
    s32 sp30;
    s32 temp_a0_2;
s32 __repair_phase_temp_a0_2;
    s32 temp_s0;
    s32 temp_s1;
    
    s32 var_v0;
    void *temp_a0;

    temp_a0_2 = 0;
    if ((D_80108788 != NULL) && (temp_a0 = M2C_FIELD(D_80108788, void **, 0x70), (temp_a0 != NULL)) && (M2C_FIELD(D_80108788, s32 *, 0x78) == 0x5A0000)) {
        temp_a0_2 = M2C_FIELD(temp_a0, s32 *, 0x30);
        var_v0 = 0;
        if ((temp_a0_2 & 0xFFFF0) == 0x670) {
            var_v0 = 0;
            if ((temp_a0_2 & 0xFFF00000) == 0x02600000) {
                D_80100300 += 1;
                temp_s1 = func_80087100(0xF3, 0);
                __repair_phase_temp_a0_2 = func_80087100(0xFF);
                sprintf(&sp30, "%s %d %s %d %s", temp_s1, D_80100300, __repair_phase_temp_a0_2, (s32) D_801007D8, func_80087100(0xFD));
                func_80073AF8(0, D_80109688, &sp30, -1, -1, 1, 0, 0, 3, 0, 0);
                M2C_FIELD(D_80108788, s16 *, 0x7A) = 1;
                func_8000A894(0x111);
                temp_a0_2 = 1;
                goto block_6;
            }
        }
    } else {
block_6:
        var_v0 = temp_a0_2;
    }
    if (var_v0 == 0) {
        func_8005B5A8();
    }
}
