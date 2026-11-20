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
    void *p;
    s32 i;
    s32 k;
    s32 sw;

    p = M2C_FIELD(D_80109BB0, void **, 0x18);
    M2C_FIELD(p, u8 *, 0x1C) |= 0x10;
    if (func_80027C60(0x23) & 0xFF) {
        M2C_FIELD(D_80109BB0, u8 *, 0x2C) = 1;
        M2C_FIELD(D_80109BB0, s8 *, 0x2F) = 1;
    }
    if (M2C_FIELD(D_80109BB0, u8 *, 0x2C) == 0) {
        func_80029068();
        return;
    }
    if (M2C_FIELD(M2C_FIELD(D_80109BB0, void **, 0x18), s32 *, 0x14) != 0 && D_801002B4 < 2) {
        M2C_FIELD(D_80109BB0, u8 *, 0x2C) = 0;
        func_8000A894(0xEA);
        return;
    }
    if (D_80102F2C != NULL && M2C_FIELD(D_80102F2C, s16 *, 0x7A) != 0xF) {
        if (M2C_FIELD(D_80102F2C, s16 *, 0x7A) != 0xE) {
            M2C_FIELD(D_80102F2C, s16 *, 0x7A) = 0xE;
            D_800BFC32 = 0x60;
            func_80026424(D_80102F2C, 0x18);
            D_800BD690 = 0;
        }
    } else {
        func_8003099C(D_80102EE0, D_80102EE8);
        D_80102EDD = 1;
        p = M2C_FIELD(D_80109BB0, void **, 0x18);
        if (M2C_FIELD(p, s32 *, 0x10) != 0) {
            D_80102ED8 = M2C_FIELD(p, s32 *, 0x14);
        }
        if (D_80102ED8 != 0) {
            D_801002AC = 0;
            D_801002A3 = 0;
            D_801002AD = 0;
            D_801002CC = D_801002C4;
            D_801002D0 = D_801002C8;
            D_80102EF0 = 0;
            i = 0;
            if (D_801002B4 > 0) {
                do {
                    *(s16 *)(D_800BD680 + ((i & 0xFFFF) * 2)) = **(u16 **)(D_800C3CF8 + (func_8002B9CC(*(s32 *)(D_8010019C + ((func_80022DBC(i & 0xFFFF) & 0xFFFF) * 0x18))) * 0xC));
                    i++;
                } while ((i & 0xFFFF) < D_801002B4);
            }
            *(s16 *)(D_800BD680 + ((i & 0xFFFF) * 2)) = -1;
            k = 0;
        } else {
            D_80102EF0 = 1;
            k = 0;
        }
        do {
            func_80081CC0(k & 0xFFFF);
            func_80011938(k & 0xFFFF, 0);
            k++;
        } while ((k & 0xFFFF) < 4);
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
            sw = -1;
            func_80045130(D_80102EE0);
            break;
        case 2: sw = 4; break;
        case 20: sw = 0x10; break;
        case 16: sw = 0xE; break;
        case 34: sw = 0x22; break;
        case 25: sw = 0x11; break;
        case 38: sw = 0x2C; break;
        case 1: sw = 1; break;
        case 11: sw = 8; break;
        case 41: sw = 0x2F; break;
        case 40: sw = 0x31; break;
        case 28: sw = 0xC; break;
        case 18: sw = 0x25; break;
        case 29: sw = 0x18; break;
        case 33: sw = 0x1A; break;
        }
        if (sw >= 0) {
            func_8000C8BC(sw);
        }
    }
}
