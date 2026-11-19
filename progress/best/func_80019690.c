/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

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
extern s32 D_801002B4;
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
    s16 temp_v1_2;
    s32 temp_s0;
    s32 var_s0;
    s32 var_s0_2;
    s32 var_s1;
    s32 var_s1_2;
    void *temp_v1;
    void *temp_v1_3;

    temp_v1 = (*(void **)((char *)(D_80109BB0) + 0x18));
    (*(u8 *)((char *)(temp_v1) + 0x1C)) |= 0x10;
    if (func_80027C60(0x23) & 0xFF) {
        (*(u8 *)((char *)(D_80109BB0) + 0x2C)) = 1U;
        (*(s8 *)((char *)(D_80109BB0) + 0x2F)) = 1;
    }
    if ((*(u8 *)((char *)(D_80109BB0) + 0x2C)) == 0) {
        func_80029068();
        return;
    }
    if (((*(s32 *)((char *)((*(void **)((char *)(D_80109BB0) + 0x18))) + 0x14)) != 0) && (D_801002B4 < 2)) {
        (*(u8 *)((char *)(D_80109BB0) + 0x2C)) = 0U;
        func_8000A894(0xEA);
        return;
    }
    if ((D_80102F2C != NULL) && (temp_v1_2 = (*(s16 *)((char *)(D_80102F2C) + 0x7A)), (temp_v1_2 != 0xF))) {
        if (temp_v1_2 != 0xE) {
            (*(s16 *)((char *)(D_80102F2C) + 0x7A)) = 0xE;
            D_800BFC32 = 0x60;
            func_80026424(D_80102F2C, 0x18);
            D_800BD690 = 0;
        }
    } else {
        func_8003099C(D_80102EE0, D_80102EE8);
        D_80102EDD = 1;
        temp_v1_3 = (*(void **)((char *)(D_80109BB0) + 0x18));
        if ((*(s32 *)((char *)(temp_v1_3) + 0x10)) != 0) {
            D_80102ED8 = (*(s32 *)((char *)(temp_v1_3) + 0x14));
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
                __repair_rows: {
                    *((var_s0 * 2) + D_800BD680) = *(s32 *)*(s32 *)(D_800C3CF8 + (func_8002B9CC(*(s32 *)(D_8010019C + ((func_80022DBC(var_s0) & 0xFFFF) * 0x18))) * 0xC));
                    var_s1_2 = var_s1 & 0xFFFF;
                    var_s1 += 1;
    var_s0 = var_s1_2;
                }
if ((var_s1 & 0xFFFF) < D_801002B4) goto __repair_rows;
            }
            *(s16 *)(D_800BD680 + ((var_s1 & 0xFFFF) * 2)) = -1;
            var_s1_2 = 0;
        } else {
            D_80102EF0 = 1;
            var_s1_2 = 0;
        }
        do {
            var_s1 = var_s1_2 & 0xFFFF;
            func_80081CC0(var_s1);
            func_80011938(var_s1, 0);
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
