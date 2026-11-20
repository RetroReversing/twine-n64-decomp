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

s32 func_8000A310();
s32 func_80011938();
s32 func_800218EC();
s32 func_80021938();
s32 func_80022DBC();
s32 func_800283B0();
s32 func_8002B000();
s32 func_8002B9CC();
s32 func_8003099C();
s32 func_80045130();
extern char D_800BD680[];
extern char D_800C3CF8[];
extern char D_8010019C[];
extern s8 D_801002A3;
extern u8 D_801002A4;
extern s8 D_801002AC;
extern s8 D_801002AD;
extern s32 D_801002B4;
extern s32 D_801002C4;
extern s32 D_801002C8;
extern s32 D_801002CC;
extern s32 D_801002D0;
extern s8 D_80102EB9;
extern s32 D_80102ED8;
extern s8 D_80102EDD;
extern s8 D_80102EDE;
extern u8 D_80102EE0;
extern u8 D_80102EE8;
extern s32 D_80102EEC;
extern s32 D_80102EF0;
extern char D_80102EFC[];
extern void *D_80102F2C;
extern s32 D_801176D8;
extern s32 D_801176DC;
extern s16 D_801176E0;
extern s16 D_801176E2;
extern s16 D_801176E4;

void func_8001ED10(void) {
    s16 temp_a0;
    s32 var_a0;
    s32 var_s0;
    s32 var_s1;
    
    u8 var_a0_2;

    D_80102EDD = 1;
    if (D_80102EEC == 0) {
        if ((D_80102F2C != NULL) && (temp_a0 = M2C_FIELD(D_80102F2C, s16 *, 0x7A), (temp_a0 != 0xF))) {
            if (temp_a0 != 0xE) {
                M2C_FIELD(D_80102F2C, s16 *, 0x7A) = 0xE;
            }
        } else {
            var_s1 = 0;
            D_801176D8 = 0;
            D_801176DC = 0;
            D_801176E0 = 0;
            D_801176E2 = 0;
            D_801176E4 = 0;
            D_80102EB9 = 0xB;
            {
                u16 __repair_i;
                for (__repair_i = 0; __repair_i < 4; __repair_i++) {
                    func_80011938(__repair_i, 0);
                }
            }
            func_8002B000(D_80102EFC, 0x1E);
            if (D_80102ED8 != 0) {
                D_801002AC = 0;
                D_801002A3 = 0;
                D_801002AD = 0;
                D_801002CC = D_801002C4;
                D_801002D0 = D_801002C8;
                D_80102EF0 = 0;
                var_s1 = 0;
                if (D_801002B4 > 0) {
                    var_s0 = 0 & 0xFFFF;
                    do {
                        *((var_s0 * 2) + D_800BD680) = *(s32 *)(D_800C3CF8 + (func_8002B9CC(*(s16 *)(D_8010019C + ((func_80022DBC(var_s0) & 0xFFFF) * 0x18))) * 0xC));
                        var_s1 += 1;
                        var_s0 = var_s1 & 0xFFFF;
                    } while ((var_s1 & 0xFFFF) < D_801002B4);
                }
                *(s16 *)(D_800BD680 + ((var_s1 & 0xFFFF) * 2)) = -1;
                var_a0_2 = D_801002A4;
            } else {
                var_a0_2 = D_80102EE0;
                D_80102EF0 = 1;
            }
            func_80045130(var_a0_2);
            D_80102EDE = 0;
            func_800283B0();
            func_8000A310();
            func_800218EC();
            func_80021938();
            func_8003099C(D_80102EE0, D_80102EE8);
        }
    }
}
