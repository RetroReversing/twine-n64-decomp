/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

extern unsigned char D_800E0C60;
extern unsigned char D_800E0C61;
s32 func_80025D84();
s32 func_80025E9C();
s32 func_80026004();
void *func_800262A8();
s8 func_800263B8();
s32 func_8002A644();
s32 func_8003099C();
s32 func_80030C1C();
s32 func_80030C4C();
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
/* Sets up the status/menu screen for the current map: loads its text entries, draws the title and labels, and updates the selected entry's display. */ void func_8001C400(void) {
    void *entry4000;
    register void *entry4001;
    unsigned long msgId;
    unsigned long msgArg;
    void *entry55;
    void *entryB;
    void *entryE;
    register int msgText;
    void *nextEntry;

    if ((*(u8 *)((char *)(&func_8011A7C8) + 0x3C)) != 0) {
        func_8003099C(D_800E0C60, D_800E0C61);
        func_80030C1C();
    } else {
        D_800E0C60 = (u8) (short)D_80100768;
        D_800E0C61 = func_800316B8();
    }
    D_800BD690 = 0;
    entryE = func_800262A8((((__repair_field_10 *)D_80109BB0)->value), 0xE);
    entry4000 = func_800262A8((((__repair_field_10 *)D_80109BB0)->value), 0x4000);
    entry4001 = func_800262A8((((__repair_field_10 *)D_80109BB0)->value), 0x4001);
    entry55 = func_800262A8((((__repair_field_10 *)D_80109BB0)->value), 0x55);
    entryB = func_800262A8((((__repair_field_10 *)D_80109BB0)->value), 0xB);
    func_8002A644(D_80115060, D_80100870, 0x90, 0xA, 0x45, 0xB4, 0x4B, 0xB, 0, &func_8002255C, &func_800227EC);
    D_800BD9BA = 0x10;
    if (((entry4000 != NULL) & (entryE != (s32)NULL)) && ((entry55 != (short)NULL) & (entryB != NULL)) && ((int)entry4001 != NULL)) {
        D_800B5B24 = 0;
        D_800B5B26 = 1;
        func_80026004(entry4000, "%s", func_80087100(func_80030C4C() & 0xFFFF));
        msgId = func_80030C7C() & 0xFFFF;
        if ((*(u8 *)((char *)(&func_8011A7C8) + 0x3C)) != 0) {
            msgId = 0x9E;
        }
        msgText = func_80087100(msgId);
        func_80026004(entry4001, "%s : %s", msgText, func_80087100((func_800316B8() + 0x72) & 0xFFFF));
        if (entry55 != NULL) {
            (((__repair_record_temp_s1*)entry55)->field_C) &= 0xFFF0;
            if (func_80030D40() != 5) {
                func_80025E9C(entry55, 0, entryB, entryE, 0, 9);
                (((__repair_record_temp_s1*)entry55)->field_18) = 0x190;
                nextEntry = (((__repair_field_10 *)D_80109BB0)->value);
                msgArg = 0xE;
            } else {
                D_80102F04 = 1;
                func_80025D84(entry55, 0, entryB, entryE, 0x55, 0);
                nextEntry = D_80109BB0;
                (((__repair_record_temp_s1*)entry55)->field_18) = 0xA0;
                nextEntry = ((__repair_field_10 *)nextEntry)->value;
                (*(s8 *)((char *)((((__repair_field_10 *)D_80109BB0)->value)) + 4)) = func_800263B8(((__repair_field_10 *)D_80109BB0)->value, 0x55);
                return;
            }
            (*(s8 *)((char *)((((__repair_field_10 *)D_80109BB0)->value)) + 4)) = func_800263B8(nextEntry, msgArg);
        }
    }
}
