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

s32 func_80001784();
s32 func_80001D80();
s32 func_80005158();
extern s32 D_800C3924;
extern char D_800C3928[];
extern char D_800C392A[];
extern s16 D_800C39B0;
extern s32 D_800D93C0;
extern s32 D_800D93C4;
extern s32 D_800D93C8;
extern s32 D_800D93CC;
extern s32 D_800D93D0;
extern s32 D_800D93D4;
extern s32 D_800D93D8;
extern s32 D_800D93DC;
extern s32 D_800D93E0;
extern s32 D_800D93E4;
extern s32 D_800D93E8;
extern s32 D_800D93EC;
extern s32 D_800D93F0;
extern s32 D_800D93F4;
extern s32 D_800D93F8;
extern s32 D_800D93FC;
extern s32 D_800D9400;
extern s32 D_800D9404;
extern s32 D_800D9408;
extern s32 D_800D940C;
extern s32 D_800D9410;
extern s32 D_80109D18;

void func_80001AFC(void) {
    s32 var_a0;

    D_80109D18 = 0;
    func_80001784();
    func_80001D80(0);
    if (D_800C3924 != 0) {
        var_a0 = 0;
        do {
            *(D_800C392A + var_a0) = 0;
            if (*(D_800C3928 + var_a0) != D_800C39B0) {
                *(D_800C392A + var_a0) = 1;
            }
            var_a0 += 8;
        } while (*(s32 *)(D_800C3924 + var_a0) != 0);
    }
    D_800D93C0 = func_80005158(0x1D0, 4, 0);
    D_800D93C4 = func_80005158(0x331, 4, 0);
    D_800D93C8 = func_80005158(0x245, 4, 0);
    D_800D93CC = func_80005158(0x1D1, 4, 0);
    D_800D93D0 = func_80005158(0x248, 4, 0);
    D_800D93D4 = func_80005158(0x247, 4, 0);
    D_800D93D8 = func_80005158(0x1DC, 4, 0);
    D_800D93E8 = func_80005158(0x4D, 4, 0);
    D_800D93EC = func_80005158(0x65, 1, 0);
    D_800D93F0 = func_80005158(0x6B, 1, 0);
    D_800D93DC = func_80005158(0x1CE, 2, 0);
    D_800D93E0 = func_80005158(0x1D9, 4, 1);
    D_800D93E4 = func_80005158(0x1DB, 4, 1);
    D_800D93F4 = func_80005158(0x26E, 4, 0);
    D_800D93F8 = func_80005158(0xB3, 4, 0);
    D_800D93FC = func_80005158(0x91, 1, 0);
    D_800D9400 = func_80005158(0x90, 1, 0);
    D_800D9404 = func_80005158(0x94, 4, 0);
    D_800D9408 = func_80005158(0xC0, 4, 0);
    D_800D940C = func_80005158(0x1CA, 7, 0);
    D_800D9410 = func_80005158(0x1CB, 7, 0);
}
