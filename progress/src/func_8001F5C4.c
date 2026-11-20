typedef struct { u8 pad0[4]; s8 selection; } MenuList1F5C4;
typedef struct { u8 pad0[0x10]; MenuList1F5C4 *list; } MenuState1F5C4;
extern MenuState1F5C4 *D_80109BB0;
extern const char D_800D2A80[], D_800D2A84[];
extern s16 gExpansionPakPresent;
extern u8 D_8010A4C0, D_8010A4FE, D_8010A4FF;
char *func_8002638C(MenuList1F5C4 *, s32);
s8 func_800263B8(MenuList1F5C4 *, s32);
void func_80025D84(void *, char *, void *, void *, u16, u16);
void func_80025E9C(void *, char *, void *, void *, u16, u16);
void func_80026004(char *, const char *, ...);
const char *func_80087100(s32);

void func_8001F5C4(void) {
    char *a, *b, *c;
    char *baseA, *baseB, *baseC;
    s32 message;

    a = func_8002638C(D_80109BB0->list, 0x1F);
    b = func_8002638C(D_80109BB0->list, 0x19);
    c = func_8002638C(D_80109BB0->list, 0x1C);
    if (c == NULL)
        c = func_8002638C(D_80109BB0->list, 3);
    if (((a != NULL) & (b != NULL)) && (c != NULL)) {
    message = 0x1B;
    if (D_8010A4FE == 0) {
        func_80026004(b, D_800D2A80, func_80087100(0x1A));
    } else {
        func_80026004(b, D_800D2A80, func_80087100(message));
    }
    if (gExpansionPakPresent != 0) {
        u16 enable = 1;
        baseC = c - 0x28;
        baseB = b - 0x28;
        baseA = a - 0x28;
        *(s16 *)(c - 0x28) = 3;
        func_80025E9C(baseC, c, baseB, baseA, enable, 9);
        func_80026004(c, D_800D2A84);
        func_80025D84(baseA, a, baseC, baseB, 0x1F, enable);
        D_80109BB0->list->selection = func_800263B8(D_80109BB0->list, 0x1F);
    } else {
        *(s16 *)(c - 0x28) = 0x1C;
        func_80025D84(c - 0x28, c, b - 0x28, a - 0x28, 0x1C, 1);
        if (D_8010A4FF != 0) {
            func_80026004(c, D_800D2A80, func_80087100(0x1D));
        } else {
            func_80026004(c, D_800D2A80, func_80087100(0x1B3));
        }
        func_80025E9C(a - 0x28, a, c - 0x28, b - 0x28, 1, 0xD);
        D_80109BB0->list->selection = func_800263B8(D_80109BB0->list, 0x19);
    }

    if (D_8010A4C0 == 0) {
        func_80026004(a, D_800D2A80, func_80087100(0x16));
    } else if (D_8010A4C0 == 1) {
        func_80026004(a, D_800D2A80, func_80087100(0x17));
    } else {
        func_80026004(a, D_800D2A80, func_80087100(0x16));
    }
    }
}
