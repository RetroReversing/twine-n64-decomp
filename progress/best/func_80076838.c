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

s32 func_80001D80();
s32 func_8003C710();
s32 func_80047F50();
s32 func_8004844C();
s32 func_80048794();
s32 func_800656C0();
s32 func_800658C0();
s32 func_8007659C();
s32 func_80084048();
extern s32 D_800CA31C;
extern u32 D_801002E0;
extern char D_80100BE0[];
extern s8 D_80103EB0;
extern char D_80108608[];
extern void *D_80109690;
extern char D_80109A60[];
extern u8 D_8010A4C1;
extern u8 D_8010A4C2;
extern s32 D_8010A500;
extern char D_80110B28[];

void func_80076838(void *arg0) {
    s16 temp_v1;
    s32 temp_s0;
    s32 temp_v0;
    s32 var_v0;
    u32 var_v1;
    void *temp_s1;
    void *var_a2;
    void *var_a3;

    temp_v1 = M2C_FIELD(arg0, s16 *, 0x7A);
    temp_s1 = M2C_FIELD(arg0, void **, 0x6C);
    switch (temp_v1) {                              /* irregular */
    case 0:
        if (*(D_80109A60 + M2C_FIELD(temp_s1, u8 *, 0)) != 0) {
            if (D_80103EB0 == 0) {
                var_v0 = M2C_FIELD(arg0, s32 *, 0x60) | 1;
block_24:
                M2C_FIELD(arg0, s32 *, 0x60) = var_v0;
            } else {
                temp_s0 = D_8010A500;
                D_80103EB0 = 0;
                var_a3 = (0x24) + (temp_s0);
                if (func_800658C0(temp_s0) != 0) {
                    var_a2 = temp_s0 + 0x3C;
                    var_v1 = 0;
                    if (D_801002E0 != 0) {
loop_16:
                        if (*(D_80100BE0 + var_v1) != M2C_FIELD(temp_s1, u8 *, 0)) {
                            var_v1 += 1;
                            if (var_v1 < (u32) D_801002E0) {
                                goto loop_16;
                            }
                        } else {
                            temp_v0 = var_v1 * 0xC;
                            var_a3 = (char *)(temp_v0); var_a3 += (s32)(D_80110B28);
                            var_a2 = temp_v0 + D_80108608;
                        }
                    }
                    func_800656C0(temp_s0, var_a3, var_a2);
                    func_80001D80(1);
                    M2C_FIELD(arg0, s16 *, 0x7A) = 1;
                    return;
                }
            }
        } else {
            return;
        }
        break;
    case 1:
        func_80048794(2, D_800CA31C);
        func_8003C710(D_80109690);
        func_8004844C(D_80109690, 0x43200000, 0x42F00000, 0x43A00000, 180.0f, 0, 0);
        func_80047F50(arg0, D_80109690);
        M2C_FIELD(D_80109690, s32 *, 0x100) |= 0x10;
        D_8010A4C1 = (D_8010A4C1 | 4) & 0xFE;
        D_8010A4C2 &= 0xFE;
        M2C_FIELD(temp_s1, s16 *, 0x12) = -1;
        M2C_FIELD(temp_s1, f32 *, 8) = 0.01f;
        func_80047F50(arg0, D_80109690);
        M2C_FIELD(arg0, s16 *, 0x7A) = 2;
        return;
    case 2:
        M2C_FIELD(arg0, s32 *, 0x58) |= 1;
        M2C_FIELD(temp_s1, f32 *, 8) += M2C_FIELD(temp_s1, f32 *, 0xC);
        func_8007659C(arg0, temp_s1 + 4);
        func_80047F50(arg0, D_80109690);
        if ((*(D_80109A60 + M2C_FIELD(temp_s1, u8 *, 0)) == 0) || (M2C_FIELD(temp_s1, s16 *, 0x12) >= (M2C_FIELD(temp_s1, s16 *, 0x10) - 4))) {
            M2C_FIELD(arg0, s16 *, 0x7A) = 3;
            return;
        }
        break;
    case 3:
        *(D_80109A60 + M2C_FIELD(temp_s1, u8 *, 1)) = 1;
        D_8010A4C1 |= 1;
        D_8010A4C2 |= 1;
        func_80084048(D_80109690, 0xE, &D_8010A4C1);
        D_80109690 = NULL;
        func_80001D80(0);
        D_80103EB0 = 1;
        var_v0 = M2C_FIELD(arg0, s32 *, 0x60) | 1;
        goto block_24;
    }
}
