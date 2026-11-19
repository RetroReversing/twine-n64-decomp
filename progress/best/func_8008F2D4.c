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

s32 func_80098710();
s32 func_800993A4();
s32 func_80099C40();
extern s32 D_800E42B0;
extern s8 D_801032AD;
extern char D_80107ED4[];
extern char D_80107ED8[];
extern char D_80107EE0[];
extern char D_80107EE8[];
extern char D_80107EEC[];
extern s32 D_8010821C;
extern s32 D_80108244;
extern s8 D_801083C0;
extern s32 D_80109A5C;
extern s32 D_8010A514;
extern char D_8010D724[];
extern char D_8010D748[];
extern char D_8010D74C[];
extern char D_8010D752[];
extern char D_8010D754[];
extern char D_8010D75C[];
extern char D_8010D764[];
extern char D_8010D768[];
extern char D_8010D76C[];
extern char D_8010D76D[];
extern char D_8010D76E[];
extern char D_8010D784[];
extern char D_8010D78C[];
extern char D_8010D7B0[];
extern char D_8010D7BC[];
extern char D_8010D7BD[];
extern char D_8010D7BE[];
extern char D_8010D7E1[];
extern char D_8010D7E2[];
extern char D_8010D890[];
extern char D_8010D894[];
extern char D_8010D89C[];
extern char D_8010D8A0[];
extern s16 D_80112EDC;

void func_8008F2D4(s32 arg0) {
    char *var_v0_2;
    s32 var_a1;
    
    s32 var_a1_3;
    
    s32 var_v0;
    s32 var_v1;
    s32 var_v1_2;

    var_v1 = 0;
    var_a1 = 0;
    D_80109A5C = 0x2800;
    D_8010A514 = arg0;
    D_800E42B0 = 0x1800;
    D_801032AD = 0;
    do {
        *(s32 *)(D_8010D784 + var_v1) = -1;
        *(s32 *)(D_8010D724 + var_v1) = 0;
        *(s32 *)(D_8010D748 + var_v1) = 0;
        *(s32 *)(D_8010D74C + var_v1) = 0;
        *(D_8010D752 + var_v1) = 0;
        *(s16 *)(D_8010D78C + var_v1) = 0;
        *(D_8010D76E + var_v1) = 0xFF;
        *(s32 *)(D_8010D754 + var_v1) = 0;
        *(D_8010D7BD + var_v1) = 0x80;
        *(D_8010D7BE + var_v1) = 0;
        *(s32 *)(D_8010D75C + var_v1) = 0x3F0000;
        *(s32 *)(D_8010D764 + var_v1) = 0;
        *(s32 *)(D_8010D768 + var_v1) = 0;
        *(D_8010D76C + var_v1) = 0;
        *(D_8010D76D + var_v1) = 0;
        *(D_8010D7E1 + var_v1) = 0;
        *(D_8010D7E2 + var_v1) = 0x17;
        *(s32 *)(D_8010D890 + var_v1) = 0;
        *(s16 *)(D_8010D894 + var_v1) = 0;
        *(s32 *)(D_8010D89C + var_v1) = 0;
        *(s16 *)(D_8010D8A0 + var_v1) = 0;
        *(s32 *)(D_8010D7B0 + var_v1) = 0x64;
        *(D_8010D7BC + var_v1) = 0;
        var_a1 += 1;
        var_v1 += 0x1A0;
    } while (var_a1 < 0x20);
    var_a1 = 0;
    var_v1_2 = 0;
    do {
        *(s32 *)(D_80107ED4 + var_v1_2) = 0;
        *(s32 *)(D_80107ED8 + var_v1_2) = 0;
        *(s32 *)(D_80107EE0 + var_v1_2) = 0;
        *(D_80107EE8 + var_v1_2) = 4;
        *(s32 *)(D_80107EEC + var_v1_2) = 0x7F0000;
        var_a1 += 1;
        var_v1_2 += 0x28;
    } while (var_a1 < 0x20);
    D_801083C0 = 1;
    var_a1_3 = 7;
    var_v0 = 0x4B0;
    do {
        *(D_80107EE8 + var_v0) = 0;
        var_a1_3 -= 1;
        var_v0 -= 0x28;
    } while (var_a1_3 >= 0);
    D_8010821C = 0x7F0000;
    D_80108244 = 0x7F0000;
    func_80098710(0x7F0000, var_a1_3);
    func_800993A4();
    var_a1 = 0xF;
    var_v0_2 = &D_80112EDC;
    do {
        *(s16 *)var_v0_2 = 0;
        var_a1 -= 1;
        var_v0_2 -= 2;
    } while (var_a1 >= 0);
    func_80099C40();
}
