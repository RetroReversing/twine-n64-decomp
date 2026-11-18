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

s32 func_80015D40();
void *func_80016410();
s32 func_8003E6EC();
s32 func_80044670();
extern s32 *D_800CA31C;
extern f64 D_800D4170;
extern char D_80109A60[];
extern s8 D_80109B1E;

void *func_8005DC2C(s32 arg0, s32 arg1, void *arg2, void *arg3) {
    s16 var_v0;
    s32 var_v0_2;
    u16 temp_v0_2;
    u16 var_a1;
    u16 var_a2;
    u8 temp_v1;
    void *temp_s0;
    void *temp_v0;

    temp_v0 = func_80016410(0x50, arg0, arg1);
    if (temp_v0 != NULL) {
        temp_s0 = M2C_FIELD(temp_v0, void **, 0x6C);
        M2C_FIELD(temp_s0, s32 *, 0x4C) &= ~0x40;
        temp_v1 = M2C_FIELD(M2C_FIELD(arg2, void **, 0x24), u8 *, 0x1E);
        switch (temp_v1) {                          /* irregular */
        default:
            var_v0 = 0x11;
            if (temp_v1 != 0x2D) {

            } else {
block_11:
                M2C_FIELD(temp_v0, s16 *, 0x78) = var_v0;
            }
            break;
        case 0x2F:
            var_v0 = 0x12;
            goto block_11;
        case 0x8E:
            D_80109B1E = 1;
            var_v0 = 0x5F;
            goto block_11;
        case 0x90:
            D_80109B1E = 1;
            var_v0 = 0x60;
            goto block_11;
        }
        M2C_FIELD(temp_s0, u16 *, 0x34) = (u16) M2C_FIELD(arg2, u16 *, 0x2C);
        M2C_FIELD(temp_s0, u16 *, 0x40) = (u16) M2C_FIELD(arg2, u16 *, 0x2E);
        M2C_FIELD(temp_s0, s32 *, 0x2C) = func_80015D40(M2C_FIELD(arg2, u16 *, 0x34));
        M2C_FIELD(temp_s0, u16 *, 0x36) = (u16) M2C_FIELD(arg2, u16 *, 0x36);
        M2C_FIELD(temp_s0, u16 *, 0x38) = (u16) M2C_FIELD(arg2, u16 *, 0x38);
        M2C_FIELD(temp_s0, u16 *, 0x3A) = (u16) M2C_FIELD(arg2, u16 *, 0x30);
        M2C_FIELD(temp_s0, u16 *, 0x3C) = (u16) M2C_FIELD(arg2, u16 *, 0);
        M2C_FIELD(temp_s0, s16 *, 0x42) = 0;
        M2C_FIELD(temp_s0, u16 *, 0x3E) = (u16) *M2C_FIELD(arg2, u16 **, 0x28);
        if (M2C_FIELD(temp_s0, u16 *, 0x3A) == 1) {
            var_a2 = M2C_FIELD(temp_s0, u16 *, 0x3E);
            var_a1 = M2C_FIELD(temp_s0, u16 *, 0x3C) + *(D_80109A60 + M2C_FIELD(temp_s0, u16 *, 0x34));
        } else {
            var_a1 = M2C_FIELD(arg2, u16 *, 0);
            var_a2 = (u16) (s16) *M2C_FIELD(arg2, u16 **, 0x28);
        }
        func_80044670(temp_v0, var_a1, (s16) var_a2);
        if (M2C_FIELD(arg2, u16 *, 0x40) == 0) {
            var_v0_2 = M2C_FIELD(temp_s0, s32 *, 0x4C) | 0x80;
        } else {
            var_v0_2 = M2C_FIELD(temp_s0, s32 *, 0x4C) & ~0x80;
        }
        M2C_FIELD(temp_s0, s32 *, 0x4C) = var_v0_2;
        *(D_80109A60 + M2C_FIELD(temp_s0, u16 *, 0x34)) = (s8) M2C_FIELD(arg2, u16 *, 0x32);
        M2C_FIELD(temp_s0, void **, 4) = arg3;
        temp_v0_2 = M2C_FIELD(arg2, u16 *, 4);
        M2C_FIELD(temp_s0, u16 *, 0x44) = temp_v0_2;
        if (temp_v0_2 == 0) {
            M2C_FIELD(temp_s0, u16 *, 0x44) = 0x3CU;
        }
        M2C_FIELD(temp_s0, s8 *, 0x4B) = 0;
        M2C_FIELD(temp_s0, s32 *, 0x4C) = (s8) (M2C_FIELD(arg2, u8 *, 3) - 1);
        M2C_FIELD(temp_s0, f32 *, 8) = 1.0f;
        if (arg3 != NULL) {
            M2C_FIELD(temp_v0, s32 *, 0x24) = (s32) M2C_FIELD(arg3, s32 *, 0);
            M2C_FIELD(temp_v0, s32 *, 0x28) = (s32) M2C_FIELD(arg3, s32 *, 4);
            M2C_FIELD(temp_v0, s32 *, 0x2C) = (s32) M2C_FIELD(arg3, s32 *, 8);
            M2C_FIELD(temp_v0, f32 *, 0x3C) = (f32) ((f64) M2C_FIELD(arg3, f32 *, 0xC) * D_800D4170);
            M2C_FIELD(temp_v0, f32 *, 0x40) = (f32) ((f64) M2C_FIELD(arg3, f32 *, 0x10) * D_800D4170);
            M2C_FIELD(temp_v0, f32 *, 0x44) = (f32) ((f64) M2C_FIELD(arg3, f32 *, 0x14) * D_800D4170);
        }
        M2C_FIELD(temp_v0, s32 *, 0x30) = (s32) M2C_FIELD(temp_v0, s32 *, 0x24);
        M2C_FIELD(temp_v0, s32 *, 0x34) = (s32) M2C_FIELD(temp_v0, s32 *, 0x28);
        M2C_FIELD(temp_v0, s32 *, 0x38) = (s32) M2C_FIELD(temp_v0, s32 *, 0x2C);
        M2C_FIELD(temp_v0, f32 *, 0x48) = (f32) M2C_FIELD(temp_v0, f32 *, 0x3C);
        M2C_FIELD(temp_v0, f32 *, 0x4C) = (f32) M2C_FIELD(temp_v0, f32 *, 0x40);
        M2C_FIELD(temp_v0, f32 *, 0x50) = (f32) M2C_FIELD(temp_v0, f32 *, 0x44);
        M2C_FIELD(temp_v0, s16 *, 0x7A) = 0;
        M2C_FIELD(temp_v0, s16 *, 0x7C) = 0;
        M2C_FIELD(temp_v0, s32 *, 0x5C) |= 0x600;
        func_8003E6EC(*D_800CA31C, temp_v0, 1);
    }
    return temp_v0;
}
