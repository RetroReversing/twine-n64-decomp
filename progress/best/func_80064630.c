/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O1, tried by autopilot */

s32 func_800645A4();
extern char D_800C469C[];
extern char D_800C46A1[];
extern char D_800C471E[];
extern char D_800C7C16[];
extern u8 D_80112F6C;

void func_80064630(void *arg0) {
    s32 var_a0;
    s32 var_s3;
    s32 var_s4;
    u32 temp_a0;
    u32 var_s2;
    u32 var_s2_2;
    void *temp_s0;
    void *temp_s5;
    void *var_s1;
    

    temp_s5 = (*(void **)((char *)(arg0) + 0x6C));
    var_a0 = 0;
    var_s2 = 0;
    var_s1 = temp_s5;
    __repair_rows: {
        if (D_80112F6C != 0) {
            (*(u16 *)((char *)(var_s1) + 0x1BC)) = (u16) *(u16 *)(D_800C7C16 + var_a0);
        } else {
            (*(u16 *)((char *)(var_s1) + 0x1BC)) = 0U;
        }
        var_s1 += 2;
        var_s2 += 1;
        var_a0 += 4;
    }
if (var_s2 < 0x20U) goto __repair_rows;
    var_s2_2 = 0;
    var_s3 = 0;
    var_s4 = 0;
    var_s1 = temp_s5;
    do { {
        if (D_80112F6C != 0) {
            (*(u8 *)((char *)(var_s1) + 0x1FC)) = (u8) *(D_800C46A1 + var_s3);
            (*(u8 *)((char *)(var_s1) + 0x1FF)) = (u8) *(D_800C471E + var_s3);
        } else {
            (*(u8 *)((char *)(var_s1) + 0x1FC)) = 0U;
            (*(u8 *)((char *)(var_s1) + 0x1FF)) = 0U;
        }
        var_s3 += 0xE8;
        if (!(*(u16 *)(D_800C469C + var_s3) & 0x8000)) {
            (*(s8 *)((char *)((temp_s5 + var_s4)) + 0x1FC)) = 0;
        }
        temp_s0 = temp_s5 + var_s4;
        var_s4 += 8;
        var_s1 += 8;
        temp_a0 = var_s2_2;/*(int)__repair_loop_weight*/do {do {do {
        ++var_s2_2;} while (0);} while (0);} while (0);
        (*(s8 *)((char *)(temp_s0) + 0x1FD)) = 0;
        (*(s8 *)((char *)(temp_s0) + 0x1FE)) = 0;
        (*(f32 *)((char *)(temp_s0) + 0x200)) = (f32) (func_800645A4(temp_a0) & 0xFF);
    }
} while (var_s2_2 < 0x3BU);
    (*(s8 *)((char *)(temp_s5) + 0x1FC)) = 1;
    (*(s8 *)((char *)(temp_s5) + 0x32C)) = 0;
    (*(s8 *)((char *)(temp_s5) + 0x324)) = 0;
    if (D_80112F6C) {
        (*(s8 *)((char *)(temp_s5) + 0x1FC)) = 1;
    }
}
