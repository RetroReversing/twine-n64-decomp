/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O1, tried by autopilot */

s32 func_800645A4(s32);
extern char D_800C469C[];
extern char D_800C46A1[];
extern char D_800C471E[];
extern char D_800C7C16[];
extern u8 D_80112F6C;

typedef struct { unsigned char pad_0[444]; unsigned short field_1BC; unsigned char pad_1BE[62]; unsigned char field_1FC; unsigned char pad_1FD[2]; unsigned char field_1FF; } __repair_record_var_s1;
void func_80064630(void *arg0) {
    s32 var_a0;
    s32 var_s3;
    s32 var_s4;
    u32 temp_a0;
    u32 var_s2;
    
    void *temp_s0;
    void *temp_s5;
    void *var_s1;
    

    temp_s5 = (*(void **)((char *)(arg0) + 0x6C));
    var_s2 = 0;
    var_a0 = 0;
    var_s1 = temp_s5;
    {
    u8 *flag = &D_80112F6C;
    do {
        if (*flag != 0) {
            ((__repair_record_var_s1*)var_s1)->field_1BC = (u16) *(u16 *)(D_800C7C16 + var_a0);
        } else {
            ((__repair_record_var_s1*)var_s1)->field_1BC = 0U;
        }
        var_s1 += 2;
        ++var_s2;
        var_a0 += 4;
    } while (var_s2 < 0x20U);
    }
    var_s2 = 0;
    var_s3 = 0;
    var_s4 = 0;
    var_s1 = temp_s5;
    do { {
        if (D_80112F6C != 0) {
            ((__repair_record_var_s1*)var_s1)->field_1FC = (u8) *(D_800C46A1 + var_s3);
            ((__repair_record_var_s1*)var_s1)->field_1FF = (u8) *(D_800C471E + var_s3);
        } else {
            ((__repair_record_var_s1*)var_s1)->field_1FC = 0U;
            ((__repair_record_var_s1*)var_s1)->field_1FF = 0U;
        }
        var_s3 += 0xE8;
        if (!(*(u16 *)(D_800C469C + var_s3) & 0x8000)) {
            (*(s8 *)((char *)((temp_s5 + var_s4)) + 0x1FC)) = 0;
        }
        temp_s0 = temp_s5 + var_s4;
        var_s4 += 8;
        var_s1 += 8;
        temp_a0 = var_s2;
        ++var_s2;
        (*(s8 *)((char *)(temp_s0) + 0x1FD)) = 0;
        (*(s8 *)((char *)(temp_s0) + 0x1FE)) = 0;
        (*(f32 *)((char *)(temp_s0) + 0x200)) = (f32) (func_800645A4(temp_a0) & 0xFF);
    }
} while (var_s2 < 0x3BU);
    (*(s8 *)((char *)(temp_s5) + 0x1FC)) = 1;
    (*(s8 *)((char *)(temp_s5) + 0x32C)) = 0;
    (*(s8 *)((char *)(temp_s5) + 0x324)) = 0;
    if (D_80112F6C != 0) {
        (*(s8 *)((char *)(temp_s5) + 0x1FC)) = 1;
    }
}
