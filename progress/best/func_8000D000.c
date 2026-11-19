/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

s32 func_80001D80();
s32 func_80008154();
s32 func_8000A2B8();
s32 func_8000A2F4();
s32 func_8000A310();
s32 func_8000B9B8();
s32 func_8000CC38();
s32 func_8000CD8C();
s32 func_8000CF14();
s32 func_800101D8();
s32 func_8003C710();
s32 func_80042CFC();
s32 func_80044BE4();
s32 func_80044D28();
s32 func_80044D84();
s32 func_80044FF0();
s32 func_8004505C();
s32 func_8004844C(s32, s32, s32, s32, f32, s32, s32);
s32 func_80048794();
void *func_80083E90();
s32 memset();
extern char D_54D910[];
extern char D_800B2640[];
extern void *D_800B2710;
extern s8 D_800B2714;
extern s8 D_800B2715;
extern void *D_800B2718;
extern s32 D_800CA31C;
extern s8 D_800CA338;
extern s16 D_800E0740;
extern s8 D_800E0742;
extern s8 D_800E0744;
extern s8 D_800E0745;
extern s8 D_800E0746;
extern s32 D_800E0748;
extern s32 D_800E074C;
extern s8 D_800E0758;
extern char D_80100B60[];
extern u8 D_80102EDE;
extern u8 D_80102EE0;
extern void *volatile D_80109688;
extern void *D_80109690;
extern u8 D_80109E68;
extern u8 D_8010A4C1;
extern u8 D_8010A4C2;

typedef struct { unsigned char pad_0[8]; int field_8; unsigned char pad_C[244]; int field_100; unsigned char pad_104[62]; signed char field_142; } __repair_record_D_80109688;
s32 func_8000D000(void) {
    s32 var_a2;
    s32 var_a0_2;
    s32 temp_v0_6;
    s32 temp_s1;
    s8 var_a0;
    u8 temp_s0;
    u8 temp_v0_5;
    u8 temp_v1_3;
    void *temp_v0;
    void *temp_v0_2;
    void *temp_v0_3;
    void *temp_v0_4;
    void *temp_v1;
    void *temp_v1_2;
    void *temp_v1_4;

    temp_s0 = D_80109E68;
    temp_s1 = D_800E0742;
    var_a0 = 0;
    if (D_80102EE0 == 0x24) {
        var_a0 = D_80102EDE != 0x1F;
    }
    D_800E0746 = var_a0;
    func_80008154(var_a0);
    if (temp_s1 == 0) {
        func_8000A310();
        func_80044BE4(D_800E0740);
    } else {
        func_8000A2B8();
        func_8000A2F4();
    }
    temp_v0 = func_80083E90(0x2E74, 0x33);
    D_800B2710 = temp_v0;
    memset(temp_v0, 0, 0x2E74);
    (*(s16 *)((char *)(D_800B2710) + 0x10)) = (s16) temp_s0;
    temp_v0_2 = func_80083E90(0x8000, 0x33);
    (*(void **)((char *)(D_800B2710) + 4)) = temp_v0_2;
    (*(void **)((char *)(D_800B2710) + 0)) = temp_v0_2;
    func_8000B9B8((*(void **)((char *)(D_800B2710) + 4)), *(s32 *)(D_800B2640 + (temp_s0 * 4)) + D_54D910, 0x8000);
    var_a2 = 0;
    var_a0_2 = 0;
    do {
        temp_v0_3 = D_800B2710 + var_a0_2;
        (*(s8 *)((char *)(temp_v0_3) + 0x9A)) = 0;
        (*(s16 *)((char *)(temp_v0_3) + 0x80)) = 1;
        (*(s16 *)((char *)(temp_v0_3) + 0x82)) = 1;
        (*(s16 *)((char *)(temp_v0_3) + 0x84)) = 1;
        (*(s16 *)((char *)(temp_v0_3) + 0x86)) = 1;
        (*(s16 *)((char *)(temp_v0_3) + 0x88)) = 1;
        (*(s16 *)((char *)(temp_v0_3) + 0x8A)) = 1;
        (*(f32 *)((char *)(temp_v0_3) + 0x6C)) = 1.0f;
        (*(f32 *)((char *)(temp_v0_3) + 0x70)) = 1.0f;
        (*(s16 *)((char *)(temp_v0_3) + 0x8C)) = 1;
        (*(s16 *)((char *)(temp_v0_3) + 0x8E)) = 1;
        (*(f32 *)((char *)(temp_v0_3) + 0x74)) = 255.0f;
        (*(f32 *)((char *)(temp_v0_3) + 0x78)) = 255.0f;
        (*(s16 *)((char *)(temp_v0_3) + 0x90)) = -1;
        temp_v1 = D_800B2710 + var_a0_2;
        (*(u8 *)((char *)(temp_v1) + 0x99)) = 0xFF;
        (*(f32 *)((char *)(temp_v1) + 0x38)) = 999.0f;
        temp_v0_4 = D_800B2710 + var_a0_2;
        (*(u8 *)((char *)(temp_v0_4) + 0x98)) = 0xFF;
        var_a2 += 1;
        temp_v1_2 = D_800B2710 + var_a0_2;
        (*(s32 *)((char *)(temp_v0_4) + 0x7C)) = -1;
        var_a0_2 += 0xD4;
        (*(s16 *)((char *)(temp_v1_2) + 0x96)) = 0;
        (*(s16 *)((char *)(temp_v1_2) + 0xE0)) = 0;
    } while (0x38 > var_a2);
    D_800E0748 = 0;
    D_800E074C = 0;
    func_8000CD8C(var_a0_2, 1, var_a2, -1);
    D_800CA338 = 1;
    if (temp_s1 == 0) {
        func_80044D84(D_800E0740);
        func_80044D28(D_80100B60);
        func_80044FF0();
        func_80042CFC(((__repair_record_D_80109688*)D_80109688)->field_8, D_800E0740);
        func_8004505C();
    } else {
        func_80044D28(D_80100B60);
        func_8000CF14(0);
    }
    func_80048794(2, D_800CA31C);
    func_8003C710(D_80109690);
    func_8004844C(D_80109690, 0x43200000, 0x42F00000, 0x43A00000, 180.0f, 0, 0);
    (*(s32 *)((char *)(D_80109690) + 0x100)) |= 0x10;
    temp_v0_5 = D_8010A4C1 | 4;
    temp_v1_3 = D_8010A4C2 | 4;
    D_8010A4C1 = temp_v0_5;
    D_8010A4C2 = temp_v1_3;
    D_8010A4C1 = temp_v0_5 & 0xFE;
    D_8010A4C2 = temp_v1_3 & 0xFE;
    (*(s32 *)((char *)(D_800B2710) + 0x2B30)) = 0;
    (*(s32 *)((char *)(D_800B2710) + 0x2B3C)) = 0;
    func_8000CC38(0x34, &D_8010A4C1, D_800B2710);
    D_800B2714 = 1;
    D_800B2715 = 0;
    D_800E0744 = 0;
    D_800E0745 = 0;
    D_800E0758 = 0;
    (*(s16 *)((char *)(D_800B2710) + 0x12)) = 1;
    func_80001D80(1);
    temp_v1_4 = D_800B2718;
    if (temp_v1_4 != NULL) {
        temp_v0_6 = (*(s32 *)((char *)(temp_v1_4) + 0x60));
        D_800B2718 = NULL;
        (*(s32 *)((char *)(temp_v1_4) + 0x60)) = (s32) (temp_v0_6 | 1);
    }
    func_800101D8();
    ((__repair_record_D_80109688*)D_80109688)->field_100 |= 0x40;
    ((__repair_record_D_80109688*)D_80109688)->field_142 = 7;
    ((__repair_record_D_80109688*)D_80109688)->field_100 |= 0x100;
    return 1;
}
