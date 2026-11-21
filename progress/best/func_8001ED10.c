void func_8000A310(void);
void func_80011938(s32, s16);
void func_800218EC(void);
void func_80021938(void);
s32 func_80022DBC(s32);
void func_800283B0(void);
void func_8002B000(void *, s32);
s32 func_8002B9CC(s32);
void func_8003099C(u8, u8);
void func_80045130(u8);
extern s16 D_800BD680;
extern s32 D_800C3CF8;
extern s32 D_8010019C;
extern s8 D_801002A3;
extern u8 D_801002A4;
extern s8 D_801002AC;
extern s8 D_801002AD;
extern s32 gSaveTotalSlots;
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
extern s32 D_80102EFC;
extern void *D_80102F2C;
extern s32 D_801176D8;
extern s32 D_801176DC;
extern s16 D_801176E0;
extern s16 D_801176E2;
extern s16 D_801176E4;

void func_8001ED10(void) {
    s32 i;
    u8 b;
    s16 t;
    s32 *__base_D_800C3CF8;

    __base_D_800C3CF8 = &D_800C3CF8;

    D_80102EDD = 1;
    if (D_80102EEC == 0) {
        if (D_80102F2C != NULL && (t = *(s16 *)((char *)D_80102F2C + 0x7A), t != 0xF)) {
            if (t != 0xE) {
                *(s16 *)((char *)D_80102F2C + 0x7A) = 0xE;
            }
        } else {
            D_801176D8 = 0;
            D_801176DC = 0;
            D_801176E0 = 0;
            D_801176E2 = 0;
            D_801176E4 = 0;
            D_80102EB9 = 0xB;
            i = 0;
            do {
                func_80011938(i & 0xFFFF, 0);
                i++;
            } while ((u32)(i & 0xFFFF) < 4U);
            func_8002B000(&D_80102EFC, 0x1E);
            if (D_80102ED8 != 0) {
                D_801002AC = 0;
                D_801002A3 = 0;
                D_801002AD = 0;
                D_801002CC = D_801002C4;
                D_801002D0 = D_801002C8;
                D_80102EF0 = 0;
                i = 0;
                if (gSaveTotalSlots > 0) {
                    __repair_rows: {
                        s32 r;
                        r = func_80022DBC(i & 0xFFFF);
                        r = func_8002B9CC(*(s32 *)((char *)&D_8010019C + (r & 0xFFFF) * 0x18));
                        *(u16 *)((char *)&D_800BD680 + ((i & 0xFFFF) << 1)) =
                            **(u16 **)((char *)__base_D_800C3CF8 + r * 12);
                        i++;
                    }
if ((i & 0xFFFF) < gSaveTotalSlots) goto __repair_rows;
                }
                *(s16 *)((char *)&D_800BD680 + ((i & 0xFFFF) << 1)) = -1;
                b = D_801002A4;
            } else {
                b = D_80102EE0;
                D_80102EF0 = 1;
            }
            func_80045130(b);
            D_80102EDE = 0;
            func_800283B0();
            func_8000A310();
            func_800218EC();
            func_80021938();
            func_8003099C(D_80102EE0, D_80102EE8);
        }
    }
}
