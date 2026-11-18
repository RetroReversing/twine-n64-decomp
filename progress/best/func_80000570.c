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

s32 func_800068B4();
s32 func_80006E30();
s32 func_80006E78();
s32 func_80006FB4();
s32 func_80008258();
s32 func_80009F04();
s32 func_8000B828();
s32 func_80011FA4();
s32 func_80083BE0();
s32 func_80083C34();
s32 func_80083C8C();
s32 func_80086DA0();
u32 func_800A67B0();
s32 osCreateThread();
s32 osStartThread();
s32 osViBlack();
s32 osViSetMode();
s32 osViSwapBuffer();
extern char D_14977A0[];
extern char D_14A8380[];
extern char D_14BA940[];
extern char D_14CD630[];
extern s32 D_80000300;
extern s32 D_800CE800;
extern char D_800CFF60[];
extern s32 D_800D03EC;
extern char D_800D8200[];
extern char D_800D93B0[];
extern s32 D_80100304;
extern s32 D_80100308;
extern s32 D_8010030C;
extern s8 D_80100964;
extern s16 D_80108400;
extern u32 D_80108F7C;
extern s8 D_80108F95;
extern s32 D_80109A54;
extern s16 D_80109B9C;
extern char D_80109CC8[];
extern s32 D_80109CD8;
extern s32 D_80109CF0;
extern s32 D_80109CF4;
extern s32 D_80109CF8;
extern s32 D_80109D04;
extern s32 D_80109D08;
extern s32 D_80109D0C;
extern s32 D_8010A2BC;
extern s32 D_8010A2C0;
extern s32 D_8010A2C4;
extern s16 D_8010A518;
extern s16 D_80117384;
extern char D_8011FF40[];
extern s32 func_800004BC;

void func_80000570(void) {
    s32 *var_a2;
    s16 temp_v1;
    s32 temp_a1_2;
    s32 temp_s1;
    s32 var_s1;
    s32 var_s2;
    u32 temp_a0;
    u32 temp_a0_2;
    u32 temp_a1;
    u32 temp_a2;
    void *temp_a3;
    void *var_s1_2;

    osCreateThread(D_800D8200, 3, &func_800004BC, 0, D_800D93B0, 0x7F);
    osStartThread(D_800D8200);
    temp_v1 = func_800A67B0() > 0x7FFFFFU;
    D_80108400 = temp_v1;
    if (temp_v1 != 0) {
        func_80083BE0(D_8011FF40, 0x80800000);
        D_80109A54 = func_80083C34(0x4B000U, 1);
        D_80100304 = func_80083C34(0x4B000U, 0);
        D_80100308 = func_80083C34(0x4B000U, 0);
        D_8010030C = func_80083C34(0x4B000U, 0);
        D_8010A2BC = func_80083C34(0x1CB8U, 1);
        D_8010A2C0 = func_80083C34(0x1CB8U, 1);
        D_8010A2C4 = func_80083C34(0x1CB8U, 1);
        D_8010A518 = 3;
        D_80109B9C = 2;
    } else {
        func_80083BE0(D_8011FF40, 0x80400000);
        D_80109A54 = func_80083C34(0x25800U, 1);
        D_80100304 = func_80083C34(0x25800U, 0);
        D_80100308 = func_80083C34(0x25800U, 0);
        D_8010A2BC = func_80083C34(0x1CB8U, 1);
        D_8010A2C0 = func_80083C34(0x1CB8U, 1);
        D_8010A2C4 = func_80083C34(0x1CB8U, 1);
        D_8010A518 = 2;
        D_80109B9C = 0;
    }
    func_80008258();
    D_80108F7C = 1;
    temp_a2 = D_14A8380 - D_14977A0;
    temp_a0 = D_14BA940 - D_14A8380;
    temp_a1 = D_14CD630 - D_14BA940;
    if ((temp_a0 < temp_a2) & (temp_a1 < temp_a2)) {
        D_80108F7C = temp_a2;
    }
    if ((temp_a2 < temp_a0) & (temp_a1 < temp_a0)) {
        D_80108F7C = temp_a0;
    }
    if ((temp_a2 < temp_a1) & (temp_a0 < temp_a1)) {
        D_80108F7C = temp_a1;
    }
    temp_a0_2 = D_80108F7C + 0x80;
    D_80108F7C = temp_a0_2;
    D_800CE800 = func_80083C34(temp_a0_2, 1, temp_a2);
    func_80006E30();
    func_8000B828(func_80083C8C());
    func_80083C34(func_80009F04() + 0x400, 1);
    D_800D03EC = 0x3BB;
    D_80117384 = (u32) (D_80000300 - 1) < 2U;
    if (D_80000300 != 0) {
        var_s2 = 0;
        if (D_80000300 != 2) {
            var_s1 = 0 * 4;
        } else {
            var_s2 = 0x1C;
            goto block_14;
        }
    } else {
        var_s2 = 0xE;
block_14:
        var_s1 = var_s2 * 4;
    }
    temp_s1 = (var_s1 + var_s2) * 0x10;
    osViSetMode(temp_s1 + D_800CFF60);
    osViBlack(1);
    var_a2 = D_80109CC8;
    var_s1_2 = temp_s1 + (D_800CFF60 + 0x50);
    temp_a3 = var_s1_2 + 0x50;
    D_80100964 = var_s2 + 2;
    D_80108F95 = var_s2 + 6;
    do {
        temp_a1_2 = M2C_FIELD(var_s1_2, s32 *, 0xC);
        M2C_FIELD(var_a2, s32 *, 0) = (s32) M2C_FIELD(var_s1_2, s32 *, 0);
        M2C_FIELD(var_a2, s32 *, 4) = (s32) M2C_FIELD(var_s1_2, s32 *, 4);
        M2C_FIELD(var_a2, s32 *, 8) = (s32) M2C_FIELD(var_s1_2, s32 *, 8);
        M2C_FIELD(var_a2, s32 *, 0xC) = temp_a1_2;
        var_s1_2 += 0x10;
        var_a2 += 0x10;
    } while (var_s1_2 != temp_a3);
    D_80109CD8 = 0x20C;
    D_80109CF4 = 0x800;
    D_80109D08 = 0x800;
    D_80109CF0 = 0x280;
    D_80109D04 = 0x500;
    D_80109CF8 = 0x2301FD;
    D_80109D0C = 0x2501FF;
    func_80006E78(0x2301FD, temp_a1_2, var_a2, temp_a3);
    osViSwapBuffer(D_80100304);
    func_80086DA0(1);
    func_80011FA4();
    func_80006FB4();
loop_18:
    func_800068B4();
    goto loop_18;
}
