typedef struct { u8 pad0[4]; s8 selection; } MenuList1F5C4;
typedef struct { u8 pad0[0x10]; MenuList1F5C4 *list; } MenuState1F5C4;
extern MenuState1F5C4 *gMenuState;
extern const char D_800D2A80[], D_800D2A84[];
extern s16 gExpansionPakPresent;
extern u8 D_8010A4C0, gOptionFlagA, D_8010A4FF;
char *findEntryPayload(MenuList1F5C4 *, s32);
s8 func_800263B8(MenuList1F5C4 *, s32);
void func_80025D84(void *, char *, void *, void *, u16, u16);
void func_80025E9C(void *, char *, void *, void *, u16, u16);
void formatTextEntry(char *, const char *, ...);
const char *lookupDataEntry(s32);

/* Rebuilds the three option rows of the menu list, choosing labels and selections from Expansion Pak presence and saved option flags. */ /* Rebuilds the three option rows of the menu list, choosing labels and selections based on Expansion Pak presence and saved option flags. */ void menuRefreshOptionRows(void) {
    char *a, *b, *c;
    char *baseA, *baseB, *baseC;
    s32 labelId;

    a = findEntryPayload(gMenuState->list, 0x1F);
    b = findEntryPayload(gMenuState->list, 0x19);
    c = findEntryPayload(gMenuState->list, 0x1C);
    if (c == NULL)
        c = findEntryPayload(gMenuState->list, 3);
    if (((a != NULL) & (b != NULL)) && (c != NULL)) {
    labelId = 0x1B;
    if (gOptionFlagA == 0) {
        formatTextEntry(b, D_800D2A80, lookupDataEntry(0x1A));
    } else {
        formatTextEntry(b, D_800D2A80, lookupDataEntry(labelId));
    }
    if (gExpansionPakPresent != 0) {
        u16 enabled = 1;
        baseC = c - 0x28;
        baseB = b - 0x28;
        baseA = a - 0x28;
        *(s16 *)(c - 0x28) = 3;
        func_80025E9C(baseC, c, baseB, baseA, enabled, 9);
        formatTextEntry(c, D_800D2A84);
        func_80025D84(baseA, a, baseC, baseB, 0x1F, enabled);
        gMenuState->list->selection = func_800263B8(gMenuState->list, 0x1F);
    } else {
        *(s16 *)(c - 0x28) = 0x1C;
        func_80025D84(c - 0x28, c, b - 0x28, a - 0x28, 0x1C, 1);
        if (D_8010A4FF != 0) {
            formatTextEntry(c, D_800D2A80, lookupDataEntry(0x1D));
        } else {
            formatTextEntry(c, D_800D2A80, lookupDataEntry(0x1B3));
        }
        func_80025E9C(a - 0x28, a, c - 0x28, b - 0x28, 1, 0xD);
        gMenuState->list->selection = func_800263B8(gMenuState->list, 0x19);
    }

    if (D_8010A4C0 == 0) {
        formatTextEntry(a, D_800D2A80, lookupDataEntry(0x16));
    } else if (D_8010A4C0 == 1) {
        formatTextEntry(a, D_800D2A80, lookupDataEntry(0x17));
    } else {
        formatTextEntry(a, D_800D2A80, lookupDataEntry(0x16));
    }
    }
}
