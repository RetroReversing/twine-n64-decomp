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

s32 func_80030680();
void *func_80087100();
extern s16 D_800BFF02;
extern void *D_800BFF08;
extern u16 D_800BFF0C;
extern s32 D_800BFF10;
extern char D_800C02C0[];
extern char D_800C02D4[];
extern u16 D_800C02D8;
extern char D_800C02DA[];
extern char D_800C02DC[];
extern u16 D_800E160A;
extern s8 D_80100768;
extern u16 gEntryCount;
extern s32 gEntryTable;

void func_8003099C(s8 arg0, s32 arg1) {
    s16 var_s2_2;
    s32 temp_a0;
    s32 temp_a1;
    s32 temp_s1;
    s32 var_s0;
    s32 var_s0_2;
    s32 var_s2;
    s32 var_v0;
    u16 temp_a0_2;
    u16 temp_v0;
    u16 temp_v1_3;
    u32 temp_v1_2;
    u8 temp_v1;
    void *temp_a1_2;
    void *temp_a1_3;
    void *temp_v0_2;
    void *temp_v0_3;

    D_800BFF02 = 0;
    D_80100768 = arg0;
    D_800BFF10 = 6;
    var_s2 = 0;
    if (D_800C02D8 != 0) {
        var_v0 = 0 & 0xFFFF;
loop_2:
        temp_a1 = var_v0 << 5;
        var_s2 += 1;
        if (*(D_800C02DA + temp_a1) == (arg0 & 0xFF)) {
            temp_a0 = *(D_800C02D4 + temp_a1);
            D_800BFF08 = temp_a1 + D_800C02C0;
            gEntryTable = temp_a0;
            temp_v1 = *(D_800C02DC + temp_a1);
            D_800BFF0C = *(u16 *)(D_800C02D8 + temp_a1);
            D_800E160A = (arg1 & 0xFF) << 0xC;
            gEntryCount = (u16) temp_v1;
            temp_v1_2 = temp_v1 & 0xFFFF;
            var_s0 = 0;
            if (temp_v1_2 != 0) {
loop_5:
                if (temp_a0 != 0) {
                    temp_a1_2 = ((var_s0 & 0xFFFF) * 8) + temp_a0;
                    temp_v0 = M2C_FIELD(temp_a1_2, u16 *, 2);
                    temp_a0_2 = temp_v0 & 0xFDF0;
                    M2C_FIELD(temp_a1_2, u16 *, 2) = temp_a0_2;
                    if (temp_v0 & 0x400) {
                        M2C_FIELD(temp_a1_2, u16 *, 2) = (u16) (temp_a0_2 | 0x200);
                    }
                    var_s0 += 1;
                    if ((u32) (var_s0 & 0xFFFF) < temp_v1_2) {
                        goto loop_5;
                    }
                }
            }
            var_s0_2 = 0;
            var_s2_2 = 0;
            if (gEntryCount != 0) {
loop_10:
                temp_s1 = (var_s0_2 & 0xFFFF) * 8;
                temp_a1_3 = temp_s1 + gEntryTable;
                M2C_FIELD(temp_a1_3, s16 *, 0) = -1;
                if (gEntryTable != 0) {
                    temp_v1_3 = M2C_FIELD(temp_a1_3, u16 *, 2);
                    if (!(temp_v1_3 & 0x200) && ((u16) D_800E160A >= (u32) (temp_v1_3 & 0xF000))) {
                        M2C_FIELD(temp_a1_3, s16 *, 0) = var_s2_2;
                        temp_v0_2 = func_80087100(M2C_FIELD(temp_a1_3, u16 *, 4), temp_a1_3);
                        if (temp_v0_2 != NULL) {
                            M2C_FIELD(temp_v0_2, s8 *, 0) = 6;
                            M2C_FIELD(temp_v0_2, s8 *, 1) = -1;
                            M2C_FIELD(temp_v0_2, s8 *, 2) = (s8) (M2C_FIELD((temp_s1 + gEntryTable), u8 *, 1) + 0x41);
                        }
                        temp_v0_3 = func_80087100(M2C_FIELD((temp_s1 + gEntryTable), u16 *, 6));
                        var_s2_2 += 1;
                        if (temp_v0_3 != NULL) {
                            M2C_FIELD(temp_v0_3, s8 *, 0) = 6;
                            M2C_FIELD(temp_v0_3, s8 *, 1) = -1;
                            M2C_FIELD(temp_v0_3, s8 *, 2) = (s8) (M2C_FIELD((temp_s1 + gEntryTable), u8 *, 1) + 0x41);
                        }
                    }
                    var_s0_2 += 1;
                    if ((u32) (var_s0_2 & 0xFFFF) < (u16) gEntryCount) {
                        goto loop_10;
                    }
                }
            }
            func_80030680();
            return;
        }
        var_v0 = var_s2 & 0xFFFF;
        if (*(s32 *)(D_800C02D8 + ((var_s2 & 0xFFFF) << 5)) == 0) {
            goto block_20;
        }
        goto loop_2;
    }
block_20:
    gEntryTable = 0;
    D_80100768 = 0;
    gEntryCount = 0;
    D_800E160A = 0;
    D_800BFF0C = 3;
}
