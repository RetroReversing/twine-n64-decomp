void *func_800262A8(void *, s32);
void *func_8002638C(void *, s32);
s32 func_80018BE0(s32);
void func_80018C5C(void *, void *);
void func_80025D84(void *, void *, void *, void *, s32, s32);
void func_80025E9C(void *, void *, void *, void *, s32, s32);
void func_80026004(void *, char *, s32);
s16 func_8002B278(void *);
s32 func_8002B248(void *);
void func_8003099C(u8, u8);
s32 func_80087100(s32);

extern u8 D_800BD690;
extern u8 D_800BD9A0[];
extern u8 D_801002A0;
extern u8 D_801002A1;
extern u8 D_801002A4;
extern s32 D_801002A8;
extern s32 D_801002B8;
extern s32 D_801002C4;
extern u8 D_801002D4;
extern u8 D_801002D5;
extern s32 D_801002F4;
extern u8 D_80102EE8;
extern u16 *D_80102FD4;
extern u8 D_8010A4FD;
extern u32 D_80117730;
extern char D_800D2858[];
extern char D_800D2864[];

void func_8001BE64(void) {
    void *temp_s3;
    void *temp_fp;
    long var_v0_2;
    void *temp_s2;
    void *temp_s5;
    void *temp_s7;
    s32 *__base_D_801002A8;
    register void *temp_s4;
    void *var_s1;
    u16 *var_v1;
    s32 var_v0;
    void *temp_s6;
    int temp_s0_v;
    int var_v0_3;
    register unsigned long var_v0_4;
    int var_a0;
    s32 *temp_s0;
    u32 temp_v1;

    D_800BD690 = 1;
    temp_fp = func_800262A8(D_800BD9A0, 0x5B);
    temp_s6 = func_800262A8(D_800BD9A0, 0x5C);
    temp_s2 = func_8002638C(D_800BD9A0, 0xE7);
    temp_s5 = func_8002638C(D_800BD9A0, 0x66);
    var_s1 = func_8002638C(D_800BD9A0, 0xB1);
    if (var_s1 == (int)NULL) {
        var_s1 = func_8002638C(D_800BD9A0, 0x1AD);
    }
    temp_s4 = func_8002638C(D_800BD9A0, 0x16C);
    temp_s3 = func_8002638C(D_800BD9A0, 0x61);
    temp_s7 = func_800262A8(D_800BD9A0, 0xC);
    D_801002F4 = func_80018BE0(D_801002C4);
    if (((temp_fp != (s32)NULL) & (temp_s6 != NULL)) && ((temp_s4 != NULL) & (temp_s5 != NULL)) && ((var_s1 != NULL) & (temp_s3 != NULL)) && ((temp_s2 != NULL) & (temp_s7 != NULL))) {
        switch (D_801002A0) {
        case 5:
        case 6:
            var_v0 = 0x19;
            var_v1 = (u16 *)0x8011AC60;
            if (D_80102FD4 != var_v1) {
                D_80117730 = 0;
            }
            break;
        default:
            var_v0 = 0xB;
            var_v1 = (u16 *)0x8011AC1C;
            if (D_80102FD4 != var_v1) {
                D_80117730 = 0;
            }
            break;
        case 7:
            var_v1 = (u16 *)0x8011AC94;
            if (D_80102FD4 != var_v1) {
                D_80117730 = 9;
            }
            var_v0 = 0xF;
            break;
        case 2:
        case 3:
        case 4:
            var_v0 = 0x14;
            var_v1 = (u16 *)0x8011AC34;
            if (D_80102FD4 != var_v1) {
                D_80117730 = 0;
            }
            break;
        }
        D_80102FD4 = var_v1;
        *(u32 *)((u8 *)var_s1 - 0x14) = var_v0;
        var_v0_2 = 0xB1;
        if (D_801002A0 == 7) {
            var_v0_2 = 0x1AD;
        }
        temp_v1 = *(u32 *)((u8 *)var_s1 - 0x14);
        *(s16 *)((u8 *)var_s1 - 0x28) = var_v0_2;
        if (temp_v1 < D_80117730) {
            D_80117730 = temp_v1;
        }
        __base_D_801002A8 = &D_801002A8;
        (*__base_D_801002A8) = D_80102FD4[D_80117730];
        func_80018C5C(temp_fp, temp_s6);
        temp_s0 = (s8 *) __base_D_801002A8 + 0x1C;
        func_8003099C(D_801002A4, D_80102EE8);
        if ((func_8002B278(temp_s0) << 0x10) != 0) {
            var_v0_3 = func_8002B248(temp_s0);
        
        func_80026004(temp_s3, D_800D2864, var_v0_3);} else {
            var_v0_3 = func_80087100(0x5F);
        
        func_80026004(temp_s3, D_800D2864, var_v0_3);}
        if ((*__base_D_801002A8) != 0) {
            func_80026004(var_s1, D_800D2858, (*__base_D_801002A8));
        } else {
            var_v0_4 = func_80087100(0x5F);
            func_80026004(var_s1, D_800D2864, var_v0_4);
        }
        var_a0 = 0x67;
        if ((int)D_8010A4FD != 0) {
            var_a0 = 0x68;
        }
        func_80026004(temp_s5, D_800D2864, func_80087100(var_a0));
        var_a0 = 0xA;
        if (D_801002D5 != 0) {
            var_a0 = 9;
        }
        func_80026004(temp_s4, D_800D2864, func_80087100(var_a0));
        if (D_801002D4 == 1) {
            var_v0_4 = func_80087100(0x2E2);
        } else if (!D_801002D4) {
            var_v0_4 = func_80087100(0xA);
        } else if (D_801002D4 != 2) {
            var_v0_4 = func_80087100(0x2E4);
        } else {
            var_v0_4 = func_80087100(0x2E3);
        }
        func_80026004(temp_s2, D_800D2864, var_v0_4);
        if (D_801002A1 != 0) {
            func_80025D84((u8 *)temp_s4 - 0x28, temp_s4, (u8 *)temp_s2 - 0x28, (u8 *)temp_s3 - 0x28, 0x16C, 1);
        } else {
            func_80025E9C((u8 *)temp_s4 - 0x28, temp_s4, (u8 *)temp_s2 - 0x28, (u8 *)temp_s3 - 0x28, 1, 0xD);
        }
        if (D_801002B8 == 2) {
            func_80025D84((u8 *)temp_s5 - 0x28, temp_s5, temp_s6, (u8 *)temp_s2 - 0x28, 0x66, 1);
        } else {
            func_80025E9C((u8 *)temp_s5 - 0x28, temp_s5, temp_s6, (u8 *)temp_s2 - 0x28, 1, 0xD);
        }
        if (D_801002A0 == 8) {
            func_80025E9C((u8 *)var_s1 - 0x28, var_s1, (u8 *)temp_s3 - 0x28, temp_s7, 1, 0xD);
            return;
        }
        if (D_801002A0 == 7) {
            var_v0_2 = 0x1AD;
        
        do { func_80025D84((u8 *)var_s1 - 0x28, var_s1, (u8 *)temp_s3 - 0x28, temp_s7, var_v0_2, 1); } while (0);} else {
            var_v0_2 = 0xB1;
        
        func_80025D84((u8 *)var_s1 - 0x28, var_s1, (u8 *)temp_s3 - 0x28, temp_s7, var_v0_2, 1);}
    }
}
