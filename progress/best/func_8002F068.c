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

extern unsigned short D_800BFC94;
extern unsigned short D_800BFC96;
void *func_80027408();
s32 func_800278AC();
s32 func_80027CE0();
s32 func_8002B050();
s32 func_8002B150();
s32 func_8002FBD4();
s32 func_80087100();
extern char D_800BD640[];
extern char D_800BD8C4[];
extern u16 D_800BFC92;
extern void *D_800E1560;
extern char D_800E1584[];
extern s32 D_80102EBC;
extern u8 D_80102EDC;
extern u8 D_80102EDE;
extern void *D_80102F2C;
extern void *D_80109BB0;

void func_8002F068(s32 arg0, s32 arg1) {
    s32 var_a2;
    s32 var_a3;
    s32 *var_v0;
    s32 temp_v0;
    s32 temp_v1;
    u16 temp_v1_2;
    void *temp_v0_2;

    if (!(func_80027CE0(0x23) & 0xFF) && !(func_80027CE0(0x2A) & 0xFF) && (D_80102EDE == 0)) {
        temp_v0 = func_80087100(0x2E9);
        temp_v1 = D_800BFC92 & 1;
        var_a2 = 0xDC;
        if (temp_v1 != 0) {
            var_a2 = 0xA0;
        }
        var_a3 = 0x45;
        if (temp_v1 != 0) {
            var_a3 = 0xB0;
        }
        temp_v0_2 = func_80027408(temp_v0, 0, var_a2, var_a3);
        D_800E1560 = temp_v0_2;
        temp_v1_2 = D_800BFC94 & 0x3F;
        D_800BFC96 = temp_v1_2;
        if (temp_v1_2 >= 0x20U) {
            D_800BFC96 = (u16) (0x3F - temp_v1_2);
        }
        if (D_800BFC92 & 1) {
            var_v0 = D_800BD640 + 4;
        } else {
            var_v0 = D_800BD640 + 0x24;
        }
        M2C_FIELD(temp_v0_2, s32 *, 0x10) = (s32) (*var_v0 & ~0xFF);
        M2C_FIELD(D_800E1560, s32 *, 0x10) = (s32) ((M2C_FIELD(D_800E1560, s32 *, 0x10) & ~0xFF) | (D_800BFC96 * 8));
        D_800BFC94 = (u16) (D_800BFC94 + 1);
        if (D_80102EDC != 0) {
            func_8002B050(D_800E1584, 1, temp_v0_2);
        }
    } else {
        D_800BFC94 = 0U;
        M2C_FIELD(D_80109BB0, s32 **, 0xC) = D_800BD8C4;
        func_800278AC(1, D_80102EBC & ~0xFF, M2C_FIELD(D_80102F2C, u16 *, 0x7A));
        func_80027408(func_80087100(3), 0x40, 0xA0, 0xCC);
        func_8002B150(D_800E1584, 0, 0);
        func_8002FBD4(arg1, 4);
    }
}
