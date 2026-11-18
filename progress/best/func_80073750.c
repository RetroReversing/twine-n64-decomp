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

s32 func_80048734();
s32 func_80073700();
extern f32 D_800C0740;
extern u8 D_801007CC;
extern u8 D_801007CD;
extern u8 D_801007CE;
extern u8 D_801007CF;
extern u8 D_801007D0;
extern u8 D_801007D1;
extern u8 D_801007D2;
extern u8 D_801007D3;
extern u8 D_801007D4;
extern s8 D_801007D5;
extern u8 D_801096A0;
extern char D_80109A60[];

void func_80073750(void *arg0) {
    s8 sp10;
    s16 temp_v1;
    u8 temp_v0;
    u8 temp_v0_2;
    void *temp_s1;

    temp_v1 = M2C_FIELD(arg0, s16 *, 0x7A);
    temp_s1 = M2C_FIELD(arg0, void **, 0x6C);
    switch (temp_v1) {                              /* irregular */
    case 0:
        if (*(D_80109A60 + M2C_FIELD(temp_s1, u8 *, 0x10)) != M2C_FIELD(temp_s1, u8 *, 0x11)) {
            M2C_FIELD(arg0, s16 *, 0x7A) = 1;
            return;
        }
        return;
    case 1:
        if ((*(D_80109A60 + M2C_FIELD(temp_s1, u8 *, 0x10)) == M2C_FIELD(temp_s1, u8 *, 0x11)) && (D_801007D5 == 0)) {
            D_801007D5 = 1;
            M2C_FIELD(arg0, s16 *, 0x7A) = 2;
            return;
        }
        break;
    case 2:
        sp10 = 0;
        D_801007CC += func_80073700(D_801007CC, M2C_FIELD(temp_s1, u8 *, 4), &sp10);
        D_801007CD += func_80073700(D_801007CD, M2C_FIELD(temp_s1, u8 *, 5), &sp10);
        D_801007CE += func_80073700(D_801007CE, M2C_FIELD(temp_s1, u8 *, 6), &sp10);
        D_801007CF += func_80073700(D_801007CF, M2C_FIELD(temp_s1, u8 *, 7), &sp10);
        D_801007D0 += func_80073700(D_801007D0, M2C_FIELD(temp_s1, u8 *, 8), &sp10);
        D_801007D1 += func_80073700(D_801007D1, M2C_FIELD(temp_s1, u8 *, 9), &sp10);
        if (M2C_FIELD(arg0, u16 *, 0x78) == 0x4E) {
            D_801007D2 += func_80073700(D_801007D2, M2C_FIELD(temp_s1, u8 *, 0xA), &sp10);
            D_801007D3 += func_80073700(D_801007D3, M2C_FIELD(temp_s1, u8 *, 0xB), &sp10);
            D_801007D4 += func_80073700(D_801007D4, M2C_FIELD(temp_s1, u8 *, 0xC), &sp10);
        } else {
            temp_v0 = M2C_FIELD(temp_s1, u8 *, 0xC);
            if (temp_v0 != 0) {
                D_801096A0 = temp_v0;
            }
            temp_v0_2 = M2C_FIELD(temp_s1, u8 *, 0xB);
            if (temp_v0_2 != 0) {
                D_800C0740 = (f32) temp_v0_2;
                func_80048734(0x42700000);
            }
        }
        if (sp10 == 0) {
            D_801007D5 = 0;
            M2C_FIELD(arg0, s16 *, 0x7A) = 0;
        }
        break;
    }
}
