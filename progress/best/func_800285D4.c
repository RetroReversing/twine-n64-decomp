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

s32 func_80026D40();
s32 func_800274BC();
s32 func_8002778C();
s32 func_80027848();
s32 func_80027A7C();
extern void *D_800E1090;
extern s32 D_800E1094;
extern char D_801002E6[];
extern void *D_80102F2C;
extern void *D_80109BB0;

void func_800285D4(void) {
    s32 (*temp_v0_2)();
    s32 (*temp_v0_3)();
    u8 temp_a2_2;
    u8 temp_v1;
    void *temp_a2;
    void *temp_v0;

    if (!(func_80027848(0x2D) & 0xFF)) {
        M2C_FIELD(D_80109BB0, s8 *, 0x29) = 0;
        if (D_80109BB0 != NULL) {
            temp_v0 = M2C_FIELD(D_80109BB0, void **, 0x10);
            if (temp_v0 != NULL) {
                temp_v0_2 = M2C_FIELD(temp_v0, s32 (**)(), 0x10);
                if (temp_v0_2 != NULL) {
                    temp_v0_2();
                }
            }
        }
    } else {
        if (M2C_FIELD(D_80109BB0, void **, 0x10) != NULL) {
            temp_a2 = M2C_FIELD(D_80109BB0, void **, 0x18);
            if (temp_a2 != NULL) {
                M2C_FIELD(temp_a2, s32 *, 0x24) = M2C_UNALIGNED32(D_801002E6);
            }
        }
        func_80026D40(D_800E1090, D_800E1094 & ~0xFF);
        if (D_800E1090 != NULL) {
            temp_v1 = M2C_FIELD(D_800E1090, u8 *, 4);
            if ((u8) M2C_FIELD(D_800E1090, u8 *, 5) >= temp_v1) {
                M2C_FIELD(D_80109BB0, u8 *, 8) = temp_v1;
            } else {
                M2C_FIELD(D_80109BB0, u8 *, 8) = 0U;
            }
            temp_a2_2 = M2C_FIELD(D_80109BB0, u8 *, 8);
            M2C_FIELD(D_80109BB0, void **, 0x18) = (void *) (M2C_FIELD(D_800E1090, s32 *, 0) + (temp_a2_2 * 0x28));
            func_800274BC(0x101, 0xFF, temp_a2_2, D_80109BB0);
            temp_v0_3 = M2C_FIELD(D_800E1090, s32 (**)(), 0x10);
            if (temp_v0_3 != NULL) {
                temp_v0_3();
            }
            M2C_FIELD(D_80109BB0, u8 *, 7) = (u8) M2C_FIELD(D_80109BB0, u8 *, 8);
            func_80027A7C(M2C_FIELD(D_80109BB0, s32 *, 0x1C), M2C_FIELD(D_80109BB0, void **, 0x18), 0);
        } else {
            func_8002778C();
        }
        M2C_FIELD(D_80102F2C, s16 *, 0x7A) = 0x15;
    }
}
