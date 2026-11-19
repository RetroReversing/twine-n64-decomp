/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2 -fno-strength-reduce, tried by autopilot */

s32 memset();
extern char D_800CE354[];
extern s32 D_80100904;
extern s32 D_80100918;
extern s32 D_80102CB8;
extern s32 D_80109A90;
extern s32 D_8010D368;

void func_80083C98(void) {
    s32 var_v1;
    register u32 var_a0;

    var_a0 = 0;
    var_v1 = 0;
    do {
        *(s32 *)(D_800CE354 + var_v1) = 0;
        var_a0 += 1;
        var_v1 += 0xC;
    } while (var_a0 < 0x35U);
    D_80100904 = D_80100918;
    D_80102CB8 = D_8010D368;
    D_80109A90 = D_80100918;
    memset(D_80100918, 0, D_8010D368 - D_80100918);
}
