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

extern char D_80102CE0[];
extern char D_80102CE1[];
extern char D_8010957D[];
extern u16 D_80109B1C;
extern char D_8010A51A[];
extern char D_8010A51C[];

void func_80098A18(void *arg0) {
    s32 temp_a1_3;
    u16 temp_a1_4;
    u8 temp_a1;
    u8 temp_a1_2;
    void *temp_a0;
    void *temp_a2;

    temp_a2 = (M2C_FIELD(arg0, u8 *, 0x63) * 4) + D_80102CE0;
    if (M2C_FIELD(temp_a2, u16 *, 2) == 1) {
        temp_a1 = M2C_FIELD(temp_a2, u8 *, 0);
        if (temp_a1 != 0xFF) {
            *(D_80102CE1 + (temp_a1 * 4)) = M2C_FIELD(temp_a2, u8 *, 1);
        } else {
            *(D_8010957D + M2C_FIELD(arg0, u8 *, 0x2E)) = M2C_FIELD(temp_a2, u8 *, 1);
        }
        temp_a1_2 = M2C_FIELD(temp_a2, u8 *, 1);
        if (temp_a1_2 != 0xFF) {
            *(D_80102CE0 + (temp_a1_2 * 4)) = M2C_FIELD(temp_a2, u8 *, 0);
            M2C_FIELD(temp_a2, u16 *, 2) = 0U;
            return;
        }
        if (M2C_FIELD(temp_a2, u8 *, 0) == temp_a1_2) {
            temp_a0 = (M2C_FIELD(arg0, u8 *, 0x2E) * 4) + D_8010A51A;
            temp_a1_3 = M2C_FIELD(temp_a0, u16 *, 2);
            if (temp_a1_3 != 0xFFFF) {
                *(s16 *)(D_8010A51A + ((temp_a1_3 *= 4))) = M2C_FIELD(temp_a0, u16 *, 0);
            } else {
                D_80109B1C = M2C_FIELD(temp_a0, u16 *, 0);
            }
            temp_a1_4 = M2C_FIELD(temp_a0, u16 *, 0);
            if (temp_a1_4 != 0xFFFF) {
                *(s16 *)(D_8010A51C + (temp_a1_4 * 4)) = M2C_FIELD(temp_a0, u16 *, 2);
            }
        }
        M2C_FIELD(temp_a2, u16 *, 2) = 0U;
    }
}
