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

s32 func_80044670();
s32 func_80045CF8();
s32 func_80045DB4();
s32 func_80055568();
s32 func_800617D8();
s32 func_80062450();
extern s32 D_80102ED8;

void func_80062F34(void *arg0) {
    f32 sp30;
    f32 sp34;
    f32 sp38;
    s16 temp_v0;
    s32 temp_a1;
    u16 temp_v1;

    temp_v0 = M2C_FIELD(arg0, u16 *, 0x7A) + 1;
    temp_a1 = temp_v0 << 0x10;
    M2C_FIELD(arg0, u16 *, 0x7A) = (u16) temp_v0;
    if (temp_v0 >= 0x2C) {
        if (temp_v0 >= (func_80045CF8(0x1E, temp_a1) + 0x1E)) {
            func_80055568(arg0, arg0 + 0x24);
            M2C_FIELD(arg0, s32 *, 0x60) |= 1;
        }
    } else {
        func_80044670(arg0, temp_a1 >> 0x11, 0xFB);
    }
    if (D_80102ED8 == 0) {
        temp_v1 = M2C_FIELD(arg0, u16 *, 0x7A);
        if (!(temp_v1 & 1) && ((s16) temp_v1 < 0x16)) {
            sp38 = 0.0f;
            sp34 = 0.0f;
            sp30 = 0.0f;
            func_80045DB4(&sp30, 0x3ECCCCCD, 0x3E4CCCCD);
            if (sp34 < 0.0f) {
                sp34 = -sp34;
            }
            func_80062450(func_800617D8(M2C_FIELD(arg0, s32 *, 0x20), arg0 + 0x24, 0, &sp30, 1.0f, 0.0f, func_80045CF8(1) + 0x17, 0xFB, 0x33, 0xFF0000FF, 6), &sp30);
        }
    }
}
