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
void func_8001C400(void) {
    void *temp_s0;
    register void *temp_s4;
    unsigned long var_a0;
    unsigned long var_a1;
    void *temp_s1;
    void *temp_s2;
    void *temp_s3;
    register int temp_s0_2;
    register void *var_a0_2;

    if ((*(u8 *)((char *)(&func_8011A7C8) + 0x3C)) != 0) {
        func_8003099C(D_800E0C60, D_800E0C61);
        func_80030C1C();
    } else {
        D_800E0C60 = (u8) (short)D_80100768;
        D_800E0C61 = func_800316B8();
    }
    D_800BD690 = 0;
    temp_s3 = func_800262A8((((__repair_field_10 *)D_80109BB0)->value), 0xE);
    temp_s0 = func_800262A8((((__repair_field_10 *)D_80109BB0)->value), 0x4000);
    temp_s4 = func_800262A8((((__repair_field_10 *)D_80109BB0)->value), 0x4001);
    temp_s1 = func_800262A8((((__repair_field_10 *)D_80109BB0)->value), 0x55);
    temp_s2 = func_800262A8((((__repair_field_10 *)D_80109BB0)->value), 0xB);
    func_8002A644(D_80115060, D_80100870, 0x90, 0xA, 0x45, 0xB4, 0x4B, 0xB, 0, &func_8002255C, &func_800227EC);
    D_800BD9BA = 0x10;
    if (((temp_s0 != NULL) & (temp_s3 != (s32)NULL)) && ((temp_s1 != (short)NULL) & (temp_s2 != NULL)) && ((int)temp_s4 != NULL)) {
        D_800B5B24 = 0;
        D_800B5B26 = 1;
        func_80026004(temp_s0, "%s", func_80087100(func_80030C4C() & 0xFFFF));
        var_a0 = func_80030C7C() & 0xFFFF;
        if ((*(u8 *)((char *)(&func_8011A7C8) + 0x3C)) != 0) {
            var_a0 = 0x9E;
        }
        temp_s0_2 = func_80087100(var_a0);
        func_80026004(temp_s4, "%s : %s", temp_s0_2, func_80087100((func_800316B8() + 0x72) & 0xFFFF));
        if (temp_s1 != NULL) {
            (((__repair_record_temp_s1*)temp_s1)->field_C) &= 0xFFF0;
            if (func_80030D40() != 5) {
                func_80025E9C(temp_s1, 0, temp_s2, temp_s3, 0, 9);
                (((__repair_record_temp_s1*)temp_s1)->field_18) = 0x190;
                var_a0_2 = (((__repair_field_10 *)D_80109BB0)->value);
                var_a1 = 0xE;
            } else {
                D_80102F04 = 1;
                func_80025D84(temp_s1, 0, temp_s2, temp_s3, 0x55, 0);
                var_a0_2 = (((__repair_field_10 *)D_80109BB0)->value);
                (((__repair_record_temp_s1*)temp_s1)->field_18) = 0xA0;
                var_a1 = 0x55;
            }
            (*(s8 *)((char *)((((__repair_field_10 *)D_80109BB0)->value)) + 4)) = func_800263B8(var_a0_2, var_a1);
        }
    }
}
