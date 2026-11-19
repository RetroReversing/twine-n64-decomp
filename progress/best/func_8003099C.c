static __inline__ u8 __repair_inline(u8 a) { return a; }
/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

s32 func_80030680();
void *func_80087100();
extern s16 D_800BFF02;
extern s32 D_800BFF04;
extern void *D_800BFF08;
extern u16 D_800BFF0C;
extern s32 D_800BFF10;
extern char D_800C02C0[];
extern char D_800C02D4[];
extern u16 D_800C02D8;
extern char D_800C02DA[];
extern char D_800C02DC[];
extern u16 D_800E1608;
extern u16 D_800E160A;
extern s8 D_80100768;

typedef struct { short field_0; unsigned short field_2; unsigned short field_4; } __repair_record_temp_a1_2;
void func_8003099C(s8 arg0, s32 arg1) {
int __repair_constant = 6;

    s16 var_s2_2;
    int temp_a0;
    int temp_a1;
    s32 temp_s1;
    s32 var_s0;
    s32 var_s0_2;
    u16 temp_v0;
    s32 var_v0;
    u32 temp_v1_2;
    s32 var_s2;
    u16 temp_v1_3;
    u16 temp_a0_2;
    void *temp_a1_2;
    u8 temp_v1;
    
    void *temp_v0_2;
    void *temp_v0_3;

    D_800BFF02 = 0;
    D_80100768 = arg0;
    D_800BFF10 = __repair_constant;
    var_s2 = 0;
    if (D_800C02D8) {
        var_v0 = 0 & 0xFFFF;
        for (;;) {
            temp_a1 = var_v0 << 5;
                ++var_s2;
                if (*(u16 *)(D_800C02DA + temp_a1) == (arg0 & 0xFF)) {
                    temp_a0 = *(s32 *)(D_800C02D4 + temp_a1);
                    D_800BFF08 = temp_a1 + D_800C02C0;
                    D_800BFF04 = temp_a0;
                    temp_v1 = __repair_inline(*(D_800C02DC + temp_a1));
                    D_800BFF0C = *(u16 *)(D_800C02D8 + temp_a1);
                    D_800E160A = (arg1 & 0xFF) << 0xC;
                    temp_v1_2 = (u16) temp_v1;
            D_800E1608 = temp_v1_2;
                    temp_v1_2 = temp_v1 & 0xFFFF;
                    var_s0 = 0;
                    if (temp_v1_2) {
loop_5:
                        if (temp_a0 != 0) {
                            temp_a1_2 = ((var_s0 & 0xFFFF) * 8) + temp_a0;
                            temp_v0 = ((__repair_record_temp_a1_2*)temp_a1_2)->field_2;
                            temp_s1 = (u16)(temp_v0 & 0xFDF0);
                            ((__repair_record_temp_a1_2*)temp_a1_2)->field_2 = temp_s1;
                            if (temp_v0 & 0x400) {
                                ((__repair_record_temp_a1_2*)temp_a1_2)->field_2 = (u16) (temp_s1 | 0x200);
                            }/*__repair_loop_weight*/do {do {do {
                            var_s0 += 1;} while (0);} while (0);} while (0);
                            if ((u32) (var_s0 & 0xFFFF) < temp_v1_2) {
                                goto loop_5;
                            }
                        }
                    }
                    var_s0_2 = 0;
                    var_s2_2 = 0;
                    if (D_800E1608 != 0) {
loop_10:
                        temp_s1 = (var_s0_2 & 0xFFFF) * 8;
                        temp_a1_2 = temp_s1 + D_800BFF04;
                        ((__repair_record_temp_a1_2*)temp_a1_2)->field_0 = -1;
                        if (D_800BFF04) {
                            temp_v1_3 = ((__repair_record_temp_a1_2*)temp_a1_2)->field_2;
                            if (!(temp_v1_3 & 0x200) && ((u16) D_800E160A >= (u32) (temp_v1_3 & 0xF000))) {
                                ((__repair_record_temp_a1_2*)temp_a1_2)->field_0 = var_s2_2;
                                temp_v0_2 = func_80087100(((__repair_record_temp_a1_2*)temp_a1_2)->field_4, temp_a1_2);
                                if (temp_v0_2 != NULL) {
                                    (*(s8 *)((char *)(temp_v0_2) + 0)) = __repair_constant;
                                    (*(s8 *)((char *)(temp_v0_2) + 1)) = -1;
                                    (*(s8 *)((char *)(temp_v0_2) + 2)) = (s8) ((*(u8 *)((char *)((temp_s1 + D_800BFF04)) + 1)) + 0x41);
                                }
                                temp_v0_3 = func_80087100((*(u16 *)((char *)((temp_s1 + D_800BFF04)) + 6)));
                                var_s2_2 += 1;
                                if (temp_v0_3 != NULL) {
                                    (*(s8 *)((char *)(temp_v0_3) + 0)) = __repair_constant;
                                    (*(s8 *)((char *)(temp_v0_3) + 1)) = -1;
                                    (*(s8 *)((char *)(temp_v0_3) + 2)) = (s8) ((*(u8 *)((char *)((temp_s1 + D_800BFF04)) + 1)) + 0x41);
                                }
                            }
                            var_s0_2 += 1;
                            if ((u32) (var_s0_2 & 0xFFFF) < (u16) D_800E1608) {
                                goto loop_10;
                            }
                        }
                    }
                    func_80030680();
                    return;
                }
                var_v0 = var_s2 & 0xFFFF;
                if (*(s32 *)(D_800C02D8 + ((var_s2 & 0xFFFF) << 5)) == 0) {
                    goto block_20;
                }
                continue;
            break;
        }
    }
block_20:
    D_800BFF04 = 0;
    D_80100768 = 0;
    D_800E1608 = 0;
    D_800E160A = 0;
    D_800BFF0C = 3;
}
