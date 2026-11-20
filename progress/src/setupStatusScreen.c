/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

extern unsigned char D_800E0C60;
extern unsigned char D_800E0C61;
s32 func_80025D84();
s32 func_80025E9C();
s32 formatTextEntry();
void *findEntryById();
s8 func_800263B8();
s32 func_8002A644();
s32 func_8003099C();
s32 func_80030C1C();
s32 getCurrentMapIdx();
s32 func_80030C7C();
s32 func_80030D40();
s32 func_800316B8();
s32 func_80087100();
extern s16 D_800B5B24;
extern s16 D_800B5B26;
extern s8 D_800BD690;
extern s16 D_800BD9BA;
extern u8 D_80100768;
extern char D_80100870[];
extern s8 D_80102F04;
extern void *D_80109BB0;
extern char D_80115060[];
extern s32 func_8002255C;
extern s32 func_800227EC;
extern s32 func_8011A7C8;

typedef struct { unsigned char pad[16]; void * value; } __repair_field_10;
typedef struct { unsigned char pad_0[12]; unsigned short field_C; unsigned char pad_E[10]; short field_18; } __repair_record_temp_s1;
/* Sets up the status/menu screen for the current map: loads text entries, draws title and labels, and updates the selected entry's display. */ /* Sets up the status/menu screen for the current map: loads its text entries, draws the title and labels, and updates the selected entry's display. */ void setupStatusScreen(void) {
    void *mapNameEntry;
    register void *infoEntry;
    unsigned long msgIndex;
    unsigned long selectIndex;
    void *selectedEntry;
    void *labelEntry;
    void *headerEntry;
    register int msgText;
    void *ownerEntry;

    if ((*(u8 *)((char *)(&func_8011A7C8) + 0x3C)) != 0) {
        func_8003099C(D_800E0C60, D_800E0C61);
        func_80030C1C();
    } else {
        D_800E0C60 = (u8) (short)D_80100768;
        D_800E0C61 = func_800316B8();
    }
    D_800BD690 = 0;
    headerEntry = findEntryById((((__repair_field_10 *)D_80109BB0)->value), 0xE);
    mapNameEntry = findEntryById((((__repair_field_10 *)D_80109BB0)->value), 0x4000);
    infoEntry = findEntryById((((__repair_field_10 *)D_80109BB0)->value), 0x4001);
    selectedEntry = findEntryById((((__repair_field_10 *)D_80109BB0)->value), 0x55);
    labelEntry = findEntryById((((__repair_field_10 *)D_80109BB0)->value), 0xB);
    func_8002A644(D_80115060, D_80100870, 0x90, 0xA, 0x45, 0xB4, 0x4B, 0xB, 0, &func_8002255C, &func_800227EC);
    D_800BD9BA = 0x10;
    if (((mapNameEntry != NULL) & (headerEntry != (s32)NULL)) && ((selectedEntry != (short)NULL) & (labelEntry != NULL)) && ((int)infoEntry != NULL)) {
        D_800B5B24 = 0;
        D_800B5B26 = 1;
        formatTextEntry(mapNameEntry, "%s", func_80087100(getCurrentMapIdx() & 0xFFFF));
        msgIndex = func_80030C7C() & 0xFFFF;
        if ((*(u8 *)((char *)(&func_8011A7C8) + 0x3C)) != 0) {
            msgIndex = 0x9E;
        }
        msgText = func_80087100(msgIndex);
        formatTextEntry(infoEntry, "%s : %s", msgText, func_80087100((func_800316B8() + 0x72) & 0xFFFF));
        if (selectedEntry != NULL) {
            (((__repair_record_temp_s1*)selectedEntry)->field_C) &= 0xFFF0;
            if (func_80030D40() != 5) {
                func_80025E9C(selectedEntry, 0, labelEntry, headerEntry, 0, 9);
                (((__repair_record_temp_s1*)selectedEntry)->field_18) = 0x190;
                ownerEntry = (((__repair_field_10 *)D_80109BB0)->value);
                selectIndex = 0xE;
            } else {
                D_80102F04 = 1;
                func_80025D84(selectedEntry, 0, labelEntry, headerEntry, 0x55, 0);
                ownerEntry = D_80109BB0;
                (((__repair_record_temp_s1*)selectedEntry)->field_18) = 0xA0;
                ownerEntry = ((__repair_field_10 *)ownerEntry)->value;
                (*(s8 *)((char *)((((__repair_field_10 *)D_80109BB0)->value)) + 4)) = func_800263B8(((__repair_field_10 *)D_80109BB0)->value, 0x55);
                return;
            }
            (*(s8 *)((char *)((((__repair_field_10 *)D_80109BB0)->value)) + 4)) = func_800263B8(ownerEntry, selectIndex);
        }
    }
}
