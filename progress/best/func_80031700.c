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

s32 func_800312F4();
s32 func_800313DC();
s32 func_800314E0();
s32 func_80031548();
s32 func_800315E0();
s32 func_80073AF8();
s32 func_80074F04();
s32 func_80087100();
extern s32 D_8010302C;
extern s32 D_80109688;

void func_80031700(u32 arg0) {
    s16 temp_a0;
    s16 temp_a0_2;
    s32 var_a2;

    if (arg0 != 0) {
        if (arg0 < 0xAU) {
            if ((func_800312F4((s16) arg0, 0) != 3) && (func_800312F4((s16) arg0, 0) != 1)) {
                func_80031548((s16) arg0, 1, 0);
                D_8010302C += 1;
                func_80073AF8(0, D_80109688, func_800313DC((s16) arg0, 0), -1, -1, 0, 0, 0, 3, 0, 0);
                var_a2 = func_800314E0((s16) arg0, 0);
                goto block_12;
            }
        } else {
            if (arg0 >= 0x14U) {
                temp_a0 = arg0 - 0x14;
                func_800315E0(temp_a0);
                D_8010302C += 1;
                func_80073AF8(0, D_80109688, func_80087100(0xA3), -1, -1, 0, 0, 0, 3, 0, 0);
                var_a2 = func_800314E0(temp_a0, 0);
                goto block_12;
            }
            temp_a0_2 = arg0 - 0xA;
            if ((func_800312F4(temp_a0_2, 0) != 3) && (func_800312F4(temp_a0_2, 0) != 2)) {
                func_80074F04();
                func_80031548(temp_a0_2, 2, 0);
                D_8010302C += 1;
                func_80073AF8(0, D_80109688, func_800313DC(temp_a0_2, 0), -1, -1, 0, 0, 0, 3, 0, 0);
                var_a2 = func_800314E0(temp_a0_2, 0);
block_12:
                func_80073AF8(0, D_80109688, var_a2, -1, 0, 0);
            }
        }
    }
}
