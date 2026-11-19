/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

extern s8 D_801002EA;
extern char D_80102CE2[];
extern char D_8010957D[];
extern u16 D_80109B1C;
extern s8 D_8010A930;
extern s8 D_8010D720;
extern s8 D_80110DB0;
extern s8 D_80117388;
extern char D_80117389[];
extern char D_8011738A[];
extern u8 D_801176E8;

void func_800993A4(void) {
    s32 temp_v1;
    s32 var_a0;
    s8 temp_v0;
    u32 var_a0_2;
    u32 var_v1_2;
    u8 var_v1;

    var_v1 = 0;
    if (D_801176E8 != 0) {
        var_a0 = 0 * 4;
        do {
            temp_v0 = var_v1 - 1;
            var_v1 += 1;
            (&D_80117388)[var_a0] = temp_v0;
            *(D_80117389 + var_a0) = var_v1;
            var_a0 = var_v1 * 4;
            *(u16 *)(D_8011738A + var_a0) = 1;
        } while (var_v1 < (u8) D_801176E8);
    }
    D_80117388 = 0xFF;
    *(D_80117389 + ((D_801176E8 - 1) * 4)) = 0xFF;
    D_801002EA = 0;
    temp_v1 = D_801176E8 & 0xFF;
    D_80110DB0 = D_801176E8 - 1;
    var_a0_2 = 0;
    if (temp_v1 != 0) {
        do {
            *(u16 *)(D_80102CE2 + var_a0_2) = 0;
            var_a0_2 += 4;
        } while (var_a0_2 < (u32) (temp_v1 * 4));
    }
    var_v1_2 = 0;
    do {
        *(D_8010957D + var_v1_2) = 0xFF;
        var_v1_2 += 1;
    } while (var_v1_2 < 0x100U);
    D_80109B1C = 0xFFFF;
    D_8010A930 = 0;
    D_8010D720 = 0;
}
