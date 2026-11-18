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

extern int D_8011F108;
extern int D_8011F10C;
extern int D_8011F110;
void *func_80016410();
s32 func_8003E6EC();
s32 func_80044670();
extern s32 *D_800CA31C;
extern u8 D_801002A0;

void *func_80119C2C(void *arg0, s32 arg1, s32 arg2) {
    void *temp_v0;

    if ((u32) (D_801002A0 - 4) >= 2U) {
        return NULL;
    }
    temp_v0 = func_80016410(0, arg0, arg1);
    D_8011F108 = (s32) M2C_FIELD(arg0, s32 *, 0);
    D_8011F10C = (s32) M2C_FIELD(arg0, s32 *, 4);
    D_8011F110 = (s32) M2C_FIELD(arg0, s32 *, 8);
    if (temp_v0 != NULL) {
        func_80044670(temp_v0, 0, 0xF4);
        M2C_FIELD(temp_v0, s16 *, 0x78) = 0x29;
        M2C_FIELD(temp_v0, s8 *, 0x7E) = 3;
        M2C_FIELD(temp_v0, u8 *, 0x82) = 0x80;
        M2C_FIELD(temp_v0, s8 *, 0x7F) = 0;
        M2C_FIELD(temp_v0, s8 *, 0x80) = 0;
        M2C_FIELD(temp_v0, s8 *, 0x81) = 0;
        M2C_FIELD(temp_v0, f32 *, 0x54) = (f32) (arg2 & 0xFFFF);
        M2C_FIELD(temp_v0, s16 *, 0x7A) = 0;
        M2C_FIELD(temp_v0, s32 *, 0x5C) &= ~0x200;
        func_8003E6EC(*D_800CA31C, temp_v0, 1);
    }
    return temp_v0;
}
