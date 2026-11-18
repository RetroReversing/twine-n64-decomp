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

void *func_800956E0();
extern s16 D_800F3894;
extern void *D_800F38B0;
extern void *D_800F38B4;
extern s32 D_800F38EC;
extern char D_800F38F0[];
extern char D_800F38F8[];
extern s32 func_800986CC;

s32 func_8009835C(s16 arg0, void *arg1) {
    s32 var_s0;
    s32 var_s2;
    void *temp_v0;

    D_800F3894 = arg0;
    var_s2 = 0;
    if (D_800F38EC > 0) {
        var_s0 = 0;
loop_2:
        temp_v0 = func_800956E0(&D_800F3894, *(u16 *)(D_800F38F0 + var_s0), *(u16 *)(D_800F38F8 + var_s0), 0x1C, &func_800986CC);
        D_800F38B0 = temp_v0;
        var_s2 += 1;
        if (temp_v0 != NULL) {
            M2C_FIELD(arg1, s32 *, 0) = (s32) M2C_FIELD(temp_v0, s32 *, 0xC);
            M2C_FIELD(arg1, s32 *, 8) = 0;
            M2C_FIELD(arg1, s32 *, 4) = (s32) M2C_FIELD(temp_v0, s32 *, 8);
            M2C_FIELD(arg1, s32 *, 0x10) = (s32) M2C_FIELD(temp_v0, s32 *, 0x14);
            M2C_FIELD(arg1, s32 *, 0xC) = (s32) (M2C_FIELD(temp_v0, s32 *, 0x10) & 0xFFFFFF);
            D_800F38B4 = temp_v0 + 0xC;
            M2C_FIELD(arg1, s32 *, 0x14) = (s32) M2C_FIELD(temp_v0, s32 *, 0x18);
            M2C_FIELD(arg1, u8 *, 0x18) = (u8) M2C_FIELD(temp_v0, s32 *, 0x10);
            return 0;
        }
        var_s0 += 0xC;
        if (var_s2 >= D_800F38EC) {
            goto block_5;
        }
        goto loop_2;
    }
block_5:
    return -1;
}
