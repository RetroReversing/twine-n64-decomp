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

extern int D_800E1368;
extern int D_800E136C;
extern int D_80112F68;
extern int D_800E1500;
extern int D_80112F6C;
extern int D_800E1504;
extern int D_80112F70;
extern int D_800E1508;
extern int D_80112F74;
extern int D_800E150C;
extern int D_80112F78;
extern int D_800E1510;
extern int D_80112F7C;
extern int D_800E1514;
extern int D_80112F80;
extern int D_800E1518;
extern int D_80112F84;
extern int D_800E151C;
s32 func_80007160();
extern char D_800E1328[];
extern char D_800E14B0[];
extern char D_80100198[];
extern s32 D_801002EC;
extern s32 D_801002F0;
extern char D_80102EB8[];
extern char D_8010A4C0[];
extern char D_80115088[];
extern char D_80115091[];
extern char D_80115092[];

void func_8002CE18(void) {
    s32 *var_a2;
    s32 *var_a2_3;
    s32 *var_a3;
    s32 *var_a3_2;
    s32 *var_a3_3;
    s32 temp_a1;
    s32 temp_a2;
    s32 temp_a0;
    s32 var_t1;
    s32 var_v1;
    s8 temp_a3;
    void *temp_v0;
    void *temp_v1;
    void *var_a2_2;

    var_a3 = D_8010A4C0;
    var_a2 = D_800E1328;
    do {
        M2C_FIELD(var_a3, s32 *, 0) = (s32) M2C_FIELD(var_a2, s32 *, 0);
        M2C_FIELD(var_a3, s32 *, 4) = (s32) M2C_FIELD(var_a2, s32 *, 4);
        M2C_FIELD(var_a3, s32 *, 8) = (s32) M2C_FIELD(var_a2, s32 *, 8);
        M2C_FIELD(var_a3, s32 *, 0xC) = (s32) M2C_FIELD(var_a2, s32 *, 0xC);
        var_a2 += 0x10;
        var_a3 += 0x10;
    } while (var_a2 != (D_800E1328 + 0x40));
    D_801002EC = D_800E1368;
    D_801002F0 = D_800E136C;
    var_a3_2 = D_80100198;
    var_a2_2 = D_800E1368 + 8;
    do {
        M2C_FIELD(var_a3_2, s32 *, 0) = (s32) M2C_FIELD(var_a2_2, s32 *, 0);
        M2C_FIELD(var_a3_2, s32 *, 4) = (s32) M2C_FIELD(var_a2_2, s32 *, 4);
        M2C_FIELD(var_a3_2, s32 *, 8) = (s32) M2C_FIELD(var_a2_2, s32 *, 8);
        M2C_FIELD(var_a3_2, s32 *, 0xC) = (s32) M2C_FIELD(var_a2_2, s32 *, 0xC);
        var_a2_2 += 0x10;
        var_a3_2 += 0x10;
    } while (var_a2_2 != (D_800E1368 + 0x148));
    var_a3_3 = D_80102EB8;
    var_a2_3 = D_800E14B0;
    do {
        M2C_FIELD(var_a3_3, s32 *, 0) = (s32) M2C_FIELD(var_a2_3, s32 *, 0);
        M2C_FIELD(var_a3_3, s32 *, 4) = (s32) M2C_FIELD(var_a2_3, s32 *, 4);
        M2C_FIELD(var_a3_3, s32 *, 8) = (s32) M2C_FIELD(var_a2_3, s32 *, 8);
        M2C_FIELD(var_a3_3, s32 *, 0xC) = (s32) M2C_FIELD(var_a2_3, s32 *, 0xC);
        var_a2_3 += 0x10;
        var_a3_3 += 0x10;
    } while (var_a2_3 != (D_800E14B0 + 0x50));
    D_80112F68 = (s32) D_800E1500;
    D_80112F6C = (s32) D_800E1504;
    D_80112F70 = (s32) D_800E1508;
    D_80112F74 = (s32) D_800E150C;
    D_80112F78 = (s32) D_800E1510;
    D_80112F7C = (s32) D_800E1514;
    D_80112F80 = (s32) D_800E1518;
    D_80112F84 = (s32) D_800E151C;
    var_t1 = 0;
    var_v1 = 0 & 0xFFFF;
    do {
        temp_a0 = var_v1 * 0xA0;
        temp_v0 = (var_v1 * 0xA) + (D_800E1500 + 0x20);
        temp_v1 = temp_a0 + D_80115088;
        temp_a1 = M2C_UNALIGNED32(M2C_FIELD(temp_v0, s32 *, 0));
        temp_a2 = M2C_UNALIGNED32(M2C_FIELD(temp_v0, s32 *, 4));
        temp_a3 = M2C_FIELD(temp_v0, s8 *, 8);
        M2C_FIELD(temp_v1, s32 *, 0) = temp_a1;
        M2C_FIELD(temp_v1, s32 *, 4) = temp_a2;
        M2C_FIELD(temp_v1, s8 *, 8) = temp_a3;
        M2C_FIELD(temp_v1, s8 *, 9) = (s8) M2C_FIELD(temp_v0, s8 *, 9);
        var_t1 += 1;
        *(D_80115092 + temp_a0) = (s16) *(D_80115091 + temp_a0);
        var_v1 = var_t1 & 0xFFFF;
    } while ((u32) (var_t1 & 0xFFFF) < 4U);
    func_80007160(temp_a0, temp_a1, temp_a2, temp_a3);
}
