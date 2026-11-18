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

void *func_80016410();
s32 func_8003E6EC();
s32 func_80044670();
extern s32 *D_800CA31C;

void *func_800592D0(s8 arg0, s32 arg1, s32 arg2, void *arg3, void *arg4, s32 arg5, u16 arg6) {
    s32 temp_fv0;
    s16 var_v0;
    s32 temp_a0;
    u8 temp_v0_2;
    void *temp_s0;
    void *temp_v0;

    temp_v0 = func_80016410(0x50);
    if (temp_v0 != NULL) {
        temp_s0 = M2C_FIELD(temp_v0, void **, 0x6C);
        func_80044670(temp_v0, M2C_FIELD(arg3, u16 *, 0), *M2C_FIELD(arg3, s16 **, 0x28));
        temp_a0 = M2C_FIELD(temp_s0, s32 *, 0x4C) & ~0x40;
        M2C_FIELD(temp_s0, s32 *, 0x4C) = temp_a0;
        if (M2C_FIELD(arg3, s32 *, 0x3C) & 0x200000) {
            M2C_FIELD(temp_s0, s32 *, 0x4C) = (s32) (temp_a0 | 0x40);
        }
        M2C_FIELD(temp_s0, u8 *, 0x4E) = (u8) M2C_FIELD(temp_v0, u8 *, 0x7E);
        M2C_FIELD(temp_v0, s16 *, 0x78) = 0xB;
        M2C_FIELD(temp_s0, u16 *, 0x34) = (u16) M2C_FIELD(arg3, u16 *, 0x2C);
        M2C_FIELD(temp_s0, s16 *, 0x36) = (s16) M2C_FIELD(arg3, u8 *, 0x2F);
        M2C_FIELD(temp_s0, u16 *, 0x38) = (u16) M2C_FIELD(arg3, u16 *, 0x30);
        M2C_FIELD(temp_s0, u16 *, 0x3A) = (u16) M2C_FIELD(arg3, u16 *, 0x32);
        M2C_FIELD(temp_s0, u16 *, 0x3C) = (u16) M2C_FIELD(arg3, u16 *, 0x34);
        M2C_FIELD(temp_s0, u16 *, 0x3E) = (u16) M2C_FIELD(arg3, u16 *, 0x36);
        M2C_FIELD(temp_s0, u16 *, 0x40) = (u16) M2C_FIELD(arg3, u16 *, 0x38);
        M2C_FIELD(temp_s0, u16 *, 0x42) = (u16) M2C_FIELD(arg3, u16 *, 0x40);
        M2C_FIELD(temp_v0, s16 *, 0x7A) = 0;
        M2C_FIELD(temp_s0, s32 *, 8) = 0;
        temp_fv0 = M2C_FIELD(temp_s0, s32 *, 8);
        M2C_FIELD(temp_s0, void **, 4) = arg4;
        M2C_FIELD(temp_s0, u16 *, 0x44) = arg6;
        M2C_FIELD(temp_s0, s8 *, 0x4B) = 0;
        M2C_FIELD(temp_s0, s32 *, 0x4C) = (s8) (arg5 - 1);
        M2C_FIELD(temp_s0, s8 *, 0x4A) = arg0;
        M2C_FIELD(temp_s0, s32 *, 0x24) = temp_fv0;
        M2C_FIELD(temp_s0, s32 *, 0x20) = temp_fv0;
        M2C_FIELD(temp_s0, s32 *, 0x1C) = temp_fv0;
        M2C_FIELD(temp_s0, s32 *, 0x18) = temp_fv0;
        M2C_FIELD(temp_s0, s32 *, 0x14) = temp_fv0;
        M2C_FIELD(temp_s0, s32 *, 0x10) = temp_fv0;
        if (arg4 != NULL) {
            M2C_FIELD(temp_v0, s32 *, 0x24) = (s32) M2C_FIELD(arg4, s32 *, 0);
            M2C_FIELD(temp_v0, s32 *, 0x28) = (s32) M2C_FIELD(arg4, s32 *, 4);
            M2C_FIELD(temp_v0, s32 *, 0x2C) = (s32) M2C_FIELD(arg4, s32 *, 8);
            M2C_FIELD(temp_v0, f32 *, 0x3C) = (f32) (M2C_FIELD(arg4, f32 *, 0xC) * 0.0027777778f);
            M2C_FIELD(temp_v0, f32 *, 0x40) = (f32) (M2C_FIELD(arg4, f32 *, 0x10) * 0.0027777778f);
            M2C_FIELD(temp_v0, f32 *, 0x44) = (f32) (M2C_FIELD(arg4, f32 *, 0x14) * 0.0027777778f);
        }
        M2C_FIELD(temp_v0, s32 *, 0x30) = (s32) M2C_FIELD(temp_v0, s32 *, 0x24);
        M2C_FIELD(temp_v0, s32 *, 0x34) = (s32) M2C_FIELD(temp_v0, s32 *, 0x28);
        M2C_FIELD(temp_v0, s32 *, 0x38) = (s32) M2C_FIELD(temp_v0, s32 *, 0x2C);
        M2C_FIELD(temp_v0, f32 *, 0x48) = (f32) M2C_FIELD(temp_v0, f32 *, 0x3C);
        M2C_FIELD(temp_v0, f32 *, 0x4C) = (f32) M2C_FIELD(temp_v0, f32 *, 0x40);
        M2C_FIELD(temp_v0, f32 *, 0x50) = (f32) M2C_FIELD(temp_v0, f32 *, 0x44);
        M2C_FIELD(temp_s0, s8 *, 0x4D) = 0;
        M2C_FIELD(temp_s0, s32 *, 0) = 0;
        M2C_FIELD(temp_v0, s32 *, 0x5C) |= 0x600;
        M2C_FIELD(temp_v0, s32 *, 0x58) |= 0x20000;
        temp_v0_2 = M2C_FIELD(M2C_FIELD(arg3, void **, 0x24), u8 *, 0x1E);
        switch (temp_v0_2) {
        default:
            var_v0 = -1;
            break;
        case 0xA1:
        case 0xA2:
            var_v0 = 0x196;
            break;
        case 0xA3:
        case 0xA4:
            var_v0 = 0x197;
            break;
        case 0x9F:
        case 0xA0:
        case 0xA5:
        case 0xA6:
            var_v0 = 0x164;
            break;
        case 0xA7:
        case 0xA8:
            var_v0 = 0x198;
            break;
        case 0xA9:
        case 0xAA:
        case 0xAB:
        case 0xAC:
            var_v0 = 0x1AC;
            break;
        }
        M2C_FIELD(temp_s0, s16 *, 0x48) = var_v0;
        func_8003E6EC(*D_800CA31C, temp_v0, 0);
    }
    return temp_v0;
}
