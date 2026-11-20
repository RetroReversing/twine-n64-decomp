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

s32 func_8000A29C();
s32 func_8000A894();
s32 func_8000C8BC();
s32 func_80011938();
s32 func_80022DBC();
s32 func_80026424();
s32 func_80027C60();
s32 func_80029068();
s32 func_8002B02C();
s32 func_8002B9CC();
s32 func_8003099C();
s32 func_80045130();
s32 func_80081CC0();
extern char D_800BD680[];
extern s8 D_800BD690;
extern s16 D_800BFC32;
extern char D_800C3CF8[];
extern s8 D_800CA338;
extern char D_8010019C[];
extern s8 D_801002A3;
extern u8 D_801002A4;
extern s8 D_801002AC;
extern s8 D_801002AD;
extern volatile s32 D_801002B4;
extern s32 D_801002C4;
extern s32 D_801002C8;
extern s32 D_801002CC;
extern s32 D_801002D0;
extern s16 D_80102CBC;
extern s16 D_80102CBE;
extern s16 D_80102CC0;
extern s32 D_80102ED8;
extern s8 D_80102EDD;
extern u8 D_80102EE0;
extern u8 D_80102EE8;
extern s32 D_80102EF0;
extern char D_80102EFC[];
extern void *D_80102F2C;
extern void *D_80109BB0;
extern s32 D_8010A4E4;

void func_80019690(void) {
void *__repair_cached_pointer;

    s16 temp_v1_2;
    s32 temp_s0;
    u16 var_s0;
    s32 var_s0_2;
    s32 var_s1;
    s32 var_s1_2;
    void *temp_v1;
    void *temp_v1_3;

    temp_v1 = M2C_FIELD(D_80109BB0, void **, 0x18);
    M2C_FIELD(temp_v1, u8 *, 0x1C) |= 0x10;
    if (func_80027C60(0x23) & 0xFF) {
        M2C_FIELD(D_80109BB0, u8 *, 0x2C) = 1U;
        M2C_FIELD(D_80109BB0, s8 *, 0x2F) = 1;
    }
    if (M2C_FIELD(D_80109BB0, u8 *, 0x2C) == 0) {
        func_80029068();
        return;
    }
    if ((M2C_FIELD(M2C_FIELD(D_80109BB0, void **, 0x18), s32 *, 0x14) != 0) && (D_801002B4 < 2)) {
        M2C_FIELD(D_80109BB0, u8 *, 0x2C) = 0U;
        func_8000A894(0xEA);
        return;
    }
    if (((__repair_cached_pointer = D_80102F2C) != NULL) && (temp_v1_2 = M2C_FIELD(__repair_cached_pointer, s16 *, 0x7A), (temp_v1_2 != 0xF))) {
        if (temp_v1_2 != 0xE) {
            M2C_FIELD(D_80102F2C, s16 *, 0x7A) = 0xE;
            D_800BFC32 = 0x60;
            func_80026424(D_80102F2C, 0x18);
            D_800BD690 = 0;
        }
    } else {
        func_8003099C(D_80102EE0, D_80102EE8);
        D_80102EDD = 1;
        temp_v1_3 = M2C_FIELD(D_80109BB0, void **, 0x18);
        if (M2C_FIELD(temp_v1_3, s32 *, 0x10) != 0) {
            D_80102ED8 = M2C_FIELD(temp_v1_3, s32 *, 0x14);
        }
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
                { register s16 *rows = (s16 *)D_800BD680;
                __repair_rows: {
                    rows[var_s0] = **(u16 **)(D_800C3CF8 + (func_8002B9CC(*(s32 *)(D_8010019C + ((func_80022DBC(var_s0) & 0xFFFF) * 0x18))) * 0xC));
                    var_s1 += 1;
                    var_s0 = var_s1 & 0xFFFF;
                }
if ((var_s1 & 0xFFFF) < D_801002B4) goto __repair_rows;
                }
            }
            *(s16 *)(D_800BD680 + ((var_s1 & 0xFFFF) * 2)) = -1;
            var_s1_2 = 0;
        } else {
            D_80102EF0 = 1;
            var_s1_2 = 0;
        }
        do {
            temp_s0 = var_s1_2 & 0xFFFF;
            func_80081CC0(temp_s0);
            func_80011938(temp_s0, 0);
            var_s1_2 += 1;
        } while ((u32) (var_s1_2 & 0xFFFF) < 4U);
        func_8002B02C(D_80102EFC);
        func_8000A29C();
        D_80102CBC = 0;
        D_80102CBE = 0;
        D_80102CC0 = 0;
        D_8010A4E4 = 0;
        if (D_80102ED8 != 0) {
            D_800CA338 = 0;
            func_80045130(D_801002A4);
            return;
        }
        switch (D_80102EE0) {
        default:
            D_800CA338 = 0;
            var_s0_2 = -1;
            func_80045130(D_80102EE0);
            break;
        case 2:
            var_s0_2 = 4;
            break;
        case 20:
            var_s0_2 = 0x10;
            break;
        case 16:
            var_s0_2 = 0xE;
            break;
        case 34:
            var_s0_2 = 0x22;
            break;
        case 25:
            var_s0_2 = 0x11;
            break;
        case 38:
            var_s0_2 = 0x2C;
            break;
        case 1:
            var_s0_2 = 1;
            break;
        case 11:
            var_s0_2 = 8;
            break;
        case 41:
            var_s0_2 = 0x2F;
            break;
        case 40:
            var_s0_2 = 0x31;
            break;
        case 28:
            var_s0_2 = 0xC;
            break;
        case 18:
            var_s0_2 = 0x25;
            break;
        case 29:
            var_s0_2 = 0x18;
            break;
        case 33:
            var_s0_2 = 0x1A;
            break;
        }
        if (var_s0_2 >= 0) {
            func_8000C8BC(var_s0_2);
        }
    }
}
