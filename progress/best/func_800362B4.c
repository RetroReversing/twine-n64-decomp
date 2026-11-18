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

s32 func_80014A40();
s32 func_80032630();
s32 func_8003438C();
s32 func_80034630();
s32 func_80038EE8();
s32 func_800A37C0();
s32 func_800A3940();
s32 guMtxIdentF();
extern char D_800B1A00[];
extern char D_800B1A78[];
extern char D_800B1B18[];
extern u32 D_800B1D84;
extern s32 D_801032A0;
extern void *D_80107E9C;
extern u32 D_80107EA0;
extern s32 D_8010A924;
extern s32 D_8010D538;
extern s32 D_80112E40;
extern char D_80112F90[];
extern f32 D_80112FC4;
extern void *D_80115328;
extern void *D_80117728;

void func_800362B4(void *arg0, s32 arg1) {
    s32 var_a1;
    f32 temp_fs0;
    u32 temp_v0;
    void *temp_a0;
    void *temp_a0_2;
    void *temp_a1;
    void *temp_s1;
    void *temp_v1;
    void *temp_v1_2;
    void *temp_v1_3;
    void *temp_v1_4;
    void *temp_v1_5;
    void *var_a0;
    void *var_a0_2;
    void *var_s0;
    void *var_s0_2;

    var_a0 = arg0;
    var_a1 = arg1;
    var_s0 = D_80107E9C;
    temp_s1 = var_a0;
    if (D_801032A0 != 1) {
        D_801032A0 = 1;
        if (M2C_FIELD(temp_s1, s32 *, 0x100) & 3) {
            temp_v1 = D_80115328;
            var_a0 = (void *)0xFC40FE03;
            D_80115328 = temp_v1 + 8;
            M2C_FIELD(temp_v1, s32 *, 0) = 0xFC40FE03;
            M2C_FIELD(temp_v1, s32 *, 4) = -0xC88;
        } else {
            var_a1 = 0xFC40FE03;
            temp_v1_2 = D_80115328;
            var_a0 = (void *)0xFF0FF37F;
            D_80115328 = temp_v1_2 + 8;
            M2C_FIELD(temp_v1_2, s32 *, 0) = 0xFC40FE03;
            M2C_FIELD(temp_v1_2, s32 *, 4) = 0xFF0FF37F;
        }
    }
    if (D_80112E40 != 0) {
        D_80112E40 = 0;
        func_80038EE8(var_a0, var_a1);
    }
    if (D_8010A924 != 0) {
        D_8010A924 = 0;
        if (M2C_FIELD(temp_s1, s32 *, 0x100) & 3) {
            temp_v1_3 = D_80115328;
            D_80115328 = temp_v1_3 + 8;
            M2C_FIELD(temp_v1_3, s32 *, 0) = 0xDE000000;
            M2C_FIELD(temp_v1_3, s32 **, 4) = D_800B1A00;
        } else {
            temp_v1_4 = D_80115328;
            D_80115328 = temp_v1_4 + 8;
            M2C_FIELD(temp_v1_4, s32 *, 0) = 0xDE000000;
            M2C_FIELD(temp_v1_4, s32 **, 4) = D_800B1B18;
        }
    }
    temp_a0 = D_80115328;
    M2C_FIELD(temp_a0, s32 *, 0) = 0xDA380003;
    D_80115328 = temp_a0 + 8;
    M2C_FIELD(temp_a0, s32 *, 4) = (s32) (M2C_FIELD(D_80117728, s32 *, 0x74C) - 0x80000000);
    if (var_s0 != NULL) {
        var_a0_2 = var_s0;
        do {
            func_80014A40(var_a0_2, temp_s1);
            func_8003438C(var_s0, temp_s1);
            func_80034630(var_s0, temp_s1);
            temp_a0_2 = M2C_FIELD(var_s0, void **, 0x3C);
            if (temp_a0_2 != NULL) {
                func_80032630(temp_a0_2);
            }
            var_s0 = M2C_FIELD(var_s0, void **, 0x1C);
            var_a0_2 = var_s0;
        } while (var_s0 != NULL);
    }
    if (D_8010A924 != 3) {
        temp_v1_5 = D_80115328;
        D_8010A924 = 3;
        D_80115328 = temp_v1_5 + 8;
        M2C_FIELD(temp_v1_5, s32 *, 0) = 0xDE000000;
        M2C_FIELD(temp_v1_5, s32 **, 4) = D_800B1A78;
    }
    var_s0_2 = D_80107E9C;
    if (var_s0_2 != NULL) {
loop_19:
        if (((u32) M2C_FIELD(var_s0_2, u32 *, 0x58) >> 2) & 0x200) {
            temp_fs0 = 2.0f * M2C_FIELD(M2C_FIELD(var_s0_2, void **, 0x3C), f32 *, 0x20);
            if ((u32) D_80107EA0 < (u32) D_800B1D84) {
                func_8003438C(var_s0_2, temp_s1);
                func_80034630(var_s0_2, temp_s1);
                temp_v0 = D_80107EA0 + 1;
                D_80107EA0 = temp_v0;
                D_8010D538 = M2C_FIELD(D_80117728, s32 *, 0x74C) + (temp_v0 << 6);
                guMtxIdentF(D_80112F90);
                func_800A3940(D_80112F90, 0x3F800000, 0xBF800000, 0x3F800000);
                D_80112FC4 = temp_fs0 * 64.0f;
                func_800A37C0(D_80112F90, D_8010D538);
                M2C_FIELD(D_80115328, s32 *, 0) = 0xDA380003;
                M2C_FIELD(D_80115328, s32 *, 4) = (s32) (D_8010D538 - 0x80000000);
                temp_a1 = D_80115328 + 8;
                D_80115328 = temp_a1;
                func_80032630(M2C_FIELD(var_s0_2, void **, 0x3C), temp_a1);
                goto block_22;
            }
        } else {
block_22:
            var_s0_2 = M2C_FIELD(var_s0_2, void **, 0x1C);
            if (var_s0_2 != NULL) {
                goto loop_19;
            }
        }
    }
}
