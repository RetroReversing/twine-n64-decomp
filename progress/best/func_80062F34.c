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
s32 func_80045DB4(s32, f32, f32);
s32 func_80055568();
s32 func_800617D8(s32, s32, s32, s32, f32, f32, s32, s32, s32, s32, s32);
s32 func_80062450();
extern s32 D_80102ED8;

typedef struct { unsigned char pad_0[32]; int field_20; unsigned char pad_24[60]; int field_60; unsigned char pad_64[22]; unsigned short field_7A; } __repair_record_arg0;
void func_80062F34(void *arg0) {
    f32 __repair_fzero = 0.0f;

    f32 sp30[3];
    s16 temp_v0;
    s32 temp_a1;
    s32 temp_v1;

    temp_v0 = ((__repair_record_arg0*)arg0)->field_7A + 1;
    temp_v1 = temp_v0 << 0x10;
    ((__repair_record_arg0*)arg0)->field_7A = (u16) temp_v0;
    if (temp_v0 >= 0x2C) {
        if (temp_v0 >= (func_80045CF8(0x1E, (temp_v0 << 0x10)) + 0x1E)) {
            func_80055568(arg0, arg0 + 0x24);
            ((__repair_record_arg0*)arg0)->field_60 |= 1;
        }
    } else {
        func_80044670(arg0, (temp_v0 << 0x10) >> 0x11, 0xFB);
    }
    if (D_80102ED8 == 0) {
        temp_v1 = ((__repair_record_arg0*)arg0)->field_7A;
        if (!(temp_v1 & 1) && ((s16) temp_v1 < 0x16)) {
            sp30[2] = __repair_fzero;
            sp30[1] = __repair_fzero;
            sp30[0] = __repair_fzero;
            func_80045DB4(sp30, 0.4f, 0.2f);
            if (sp30[1] < 0.0f) {
                sp30[1] = -sp30[1];
            }
            func_80062450(func_800617D8(((__repair_record_arg0*)arg0)->field_20, arg0 + 0x24, 0, sp30, 1.0f, 0.0f, func_80045CF8(1) + 0x17, 0xFB, 0x33, 0xFF0000FF, 6), sp30);
        }
    }
}
