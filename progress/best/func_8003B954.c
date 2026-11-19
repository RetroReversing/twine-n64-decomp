static __inline__ int __repair_inline(s32 a, s32 b) { return a > b; }
/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

s32 func_80018030();
u32 func_80018080();
u32 func_800180D4();
void *func_80018510();
s32 func_80018578();
s32 func_8003FA78();
extern char D_800BD640[];
extern u8 D_800C0738;
extern void *D_800C0A24;
extern s32 D_800E1760;
extern u32 D_800E1764;
extern u16 D_800E1766;
extern s32 D_800E1768;
extern void *D_80109BB0;
extern s32 D_8010A4E8;
extern s32 *D_80115328;

typedef struct { unsigned char pad[24]; int value; } __repair_field_18;
typedef struct { int value; } __repair_field_0;
void func_8003B954(s32 arg0, s32 arg1, void *arg2) {
    s32 *temp_a0_3;
    
    s32 *temp_a1_2;
    s32 *temp_v0;
    s32 *temp_v0_6;
    s32 *temp_v1;
    s32 *var_a2_2;
    s32 temp_a0;
    s32 temp_a0_2;
    s32 temp_a0_8;
    s32 temp_a0_9;
    s32 temp_a1_3;
    s32 temp_a1_5;
    s32 temp_a2;
    s32 temp_a3;
    s32 temp_s0;
    s32 temp_t2_3;
    s32 temp_t3;
    s32 temp_t4;
    s32 temp_v0_2;
    s32 temp_v0_4;
    s32 temp_v1_2;
    s32 var_a0_2;
    s32 var_a1;
    s32 var_a1_2;
    s32 var_a2;
    s32 var_s7;
    s32 var_v0_2;
    s32 var_v1;
    s32 var_v1_2;
    s8 temp_a0_7;
    s8 var_v1_3;
    u16 temp_a0_5;
    u16 temp_a0_6;
    register u16 temp_a1;
    register u16 temp_t0;
    u16 var_s1;
    u16 var_s5;
    u32 temp_t2;
    u32 temp_t2_2;
    u32 var_a0;
    u32 var_s0;
    u32 var_v0;
    u8 *temp_v1_3;
    u8 temp_s3_2;
    void *temp_a1_4;
    void *temp_s3;
    void *temp_s4;
    void *temp_v0_3;
    void *temp_v0_5;
    void *temp_v1_4;
    void *temp_v1_5;
    void *temp_v1_6;

    var_s7 = 0;
    if ((func_8003FA78(0x2A) << 0x18) != 0) {
        D_800E1764 = 0;
        D_800E1768 = 0;
        var_s1 = (*(u16 *)((char *)(arg2) + 0x20));
        temp_s4 = func_80018510(func_80018030((*(u16 *)((char *)(arg2) + 0x1E))) & 0xFFFF);
        temp_s3 = D_800C0A24;
        var_s5 = (*(u16 *)((char *)(arg2) + 0x22));
        temp_s0 = (*(s32 *)((char *)((((*(s32 *)((char *)(temp_s4) + 4)) * 0xC) + ((__repair_field_18 *)temp_s3)->value)) + 8));
        if ((*(u16 *)((char *)(arg2) + 0x1E)) & 0x201) {
            var_v0 = func_80018080(arg2);
            if ((*(u16 *)((char *)(arg2) + 0x1E)) & 1) {
                var_v0 = var_v0 >> 1;
            }
            var_s1 -= var_v0;
        }
        temp_v1 = D_80115328;
        ((__repair_field_0 *)temp_v1)->value = 0xFD900000;
        (*(s32 *)((char *)(temp_v1) + 8)) = 0xF5900000;
        (*(s32 *)((char *)(temp_v1) + 0x10)) = 0xE6000000;
        (*(s32 *)((char *)(temp_v1) + 4)) = temp_s0;
        (*(s32 *)((char *)(temp_v1) + 0xC)) = 0x070C0300;
        (*(s32 *)((char *)(temp_v1) + 0x14)) = 0;
        ((__repair_field_18 *)temp_v1)->value = 0xF3000000;
        temp_a1 = (*(u16 *)((char *)((((*(s32 *)((char *)(temp_s4) + 4)) * 0xC) + ((__repair_field_18 *)temp_s3)->value)) + 2));
        D_80115328 = temp_v1 + 8;
        D_80115328 = temp_v1 + 0x10;
        temp_v0 = temp_v1 + 0x18;
        D_80115328 = temp_v0;
        D_80115328 = temp_v1 + 0x20;
        temp_a0 = temp_a1 + 1;
        var_v1 = temp_a0;
        if (__repair_inline(0, temp_a0)) {
            var_v1 = temp_a1 + 0x10;
        }
        temp_v0_2 = var_v1 >> 4;
        var_a2 = 0x800;
        if (temp_v0_2 > 0) {{ s32 __repair_value; temp_a0_8 = temp_v0_2 + 0x7FF; var_a2 = temp_a0_8; }
        }
        temp_v0_3 = ((*(s32 *)((char *)(temp_s4) + 4)) * 0xC) + ((__repair_field_18 *)temp_s3)->value;
        temp_t0 = (*(u16 *)((char *)(temp_v0_3) + 2));
        temp_a0_2 = temp_t0 + 1;
        var_v1_2 = ((s32) ((temp_a0_2 * ((*(u16 *)((char *)(temp_v0_3) + 4)) + 1)) + 3) >> 2) - 1;
        if (var_v1_2 >= 0x800) {
            var_v1_2 = 0x7FF;
        }
        var_a1 = temp_a0_2;
        if (__repair_inline(0, temp_a0_2)) {
            var_a1 = temp_t0 + 0x10;
        }
        temp_v0_4 = var_a1 >> 4;
        if (temp_v0_4 <= 0) {
            var_v0_2 = var_a2 & 0xFFF;
        } else {
            var_v0_2 = (var_a2 / temp_v0_4) & 0xFFF;
        }
        temp_a0_3 = D_80115328;
        ((__repair_field_0 *)temp_a0_3)->value = 0xE7000000;
        (*(s32 *)((char *)(temp_v0) + 4)) = (s32) (((var_v1_2 & 0xFFF) << 0xC) | 0x07000000 | var_v0_2);
        (*(s32 *)((char *)(temp_a0_3) + 4)) = 0;
        (*(s32 *)((char *)(temp_a0_3) + 0x10)) = 0xF2000000;
        (*(s32 *)((char *)(temp_a0_3) + 0xC)) = 0xC0300;
        (*(s32 *)((char *)(temp_a0_3) + 8)) = (s32) (((((s32) (((s32) ((*(u16 *)((char *)((((*(s32 *)((char *)(temp_s4) + 4)) * 0xC) + ((__repair_field_18 *)temp_s3)->value)) + 2)) + 1) >> 1) + 7) >> 3) & 0x1FF) << 9) | 0xF5800000);
        temp_v0_5 = ((*(s32 *)((char *)(temp_s4) + 4)) * 0xC) + ((__repair_field_18 *)temp_s3)->value;
        ((__repair_field_18 *)temp_a0_3)->value = 0xFC30B261;
        (*(s32 *)((char *)(temp_a0_3) + 0x1C)) = 0x5566FF7F;
        (*(s32 *)((char *)(temp_a0_3) + 0x20)) = 0xE3001001;
        (*(s32 *)((char *)(temp_a0_3) + 0x24)) = 0;
        (*(s32 *)((char *)(temp_a0_3) + 0x14)) = (s32) (((((*(u16 *)((char *)(temp_v0_5) + 2)) * 4) & 0xFFF) << 0xC) | (((*(u16 *)((char *)(temp_v0_5) + 4)) * 4) & 0xFFF));
        D_80115328 = temp_a0_3 + 8;
        D_80115328 = temp_a0_3 + 0x10;
        D_80115328 = temp_a0_3 + 0x18;
        D_80115328 = temp_a0_3 + 0x20;
        D_80115328 = temp_a0_3 + 0x28;
        var_s0 = 0;
        if ((*(u16 *)((char *)(arg2) + 0x1C)) != 0) {
            do {
                temp_s3_2 = *(u8 *)(((__repair_field_18 *)arg2)->value + var_s0);
                switch (temp_s3_2) {
                case 9:
                    var_s1 = ((var_s1 >> 4) + 1) * 0x10;
                    break;
                case 1:
                    ++var_s0;
                    var_s1 = *(u16 *)(((__repair_field_18 *)arg2)->value + var_s0) * 2;
                    break;
                case 2:
                    var_s0 += 1;
                    var_v1_3 = *(s8 *)(((__repair_field_18 *)arg2)->value + var_s0);
                    var_s1 += var_v1_3;
block_48:
                    D_800E1760 += var_v1_3;
                    break;
                case 4:
                    D_800E1768 = 0x12;
                    /* fallthrough */
                case 3:
                    ++var_s0;
                    D_800E1760 = 0;
                    D_800E1764 = *(u32 *)(((__repair_field_18 *)arg2)->value + var_s0) * 2;
                    break;
                case 6:
                    var_s0 += 1;
                    break;
                case 5:
                    var_s0 += 1;
                    if (D_800C0738 == 0) {
                        temp_a0_3 = D_80115328;
                        temp_t2 = *((*(s32 *)(((__repair_field_18 *)arg2)->value + var_s0) * 4) + D_800BD640);
                        D_80115328 = temp_a0_3 + 8;
                        ((__repair_field_0 *)temp_a0_3)->value = 0xFA000000;
                        (*(s32 *)((char *)(temp_a0_3) + 4)) = (s32) (((temp_t2 >> 0x18) << 0x18) | (temp_t2 & 0xFF0000) | (temp_t2 & 0xFF00) | (temp_t2 & 0xFF));
                    }
                    break;
                case 7:
                    var_s0 += 1;
                    if (D_800C0738 == 0) {
                        temp_a1_2 = D_80115328;
                        D_80115328 = temp_a1_2 + 8;
                        temp_t2_2 = (*(((*(s32 *)(((__repair_field_18 *)arg2)->value + var_s0) & 0xF) * 4) + D_800BD640) & ~0xFF) | (*(u8 *)((char *)(D_80109BB0) + 0x30));
                        ((__repair_field_0 *)temp_a1_2)->value = 0xFA000000;
                        (*(s32 *)((char *)(temp_a1_2) + 4)) = (s32) (((temp_t2_2 >> 0x18) << 0x18) | (temp_t2_2 & 0xFF0000) | (temp_t2_2 & 0xFF00) | (temp_t2_2 & 0xFF));
                    }
                    break;
                case 10:
                    var_s1 = (*(u16 *)((char *)(arg2) + 0x20));
                    temp_a0_5 = (*(u16 *)((char *)(arg2) + 0x1E));
                    D_800E1760 = 0;
                    var_s5 = var_s5 + 3 + (*(u8 *)((char *)((*(void **)((char *)(temp_s4) + 8))) + 0x148));
                    if (temp_a0_5 & 1) {
                        var_s1 -= func_800180D4(((__repair_field_18 *)arg2)->value + (var_s0 + 1), (((*(u16 *)((char *)((u32)arg2) + 0x1C)) - 1) - var_s0) & 0xFFFF, (*(u16 *)((char *)(arg2) + 0x1E)), func_80018030(temp_a0_5) & 0xFFFF, (s32) D_800E1766) >> 1;
                    }
                    break;
                case 32:
                    var_v1_3 = (s8) (*(u8 *)((char *)(temp_s4) + 0x10));
                    var_s1 += var_v1_3;
                    goto block_48;
                default:
                    if ((D_800E1764 != 0) && ((u32) (D_800E1760 + (func_80018578(temp_s4, ((__repair_field_18 *)arg2)->value + var_s0) & 0xFFFF)) >= (u32) D_800E1764)) {
                        temp_a0_6 = (*(u16 *)((char *)(arg2) + 0x1E));
                        D_800E1760 = 0;
                        var_s5 = var_s5 + 3 + (*(u8 *)((char *)((*(void **)((char *)(temp_s4) + 8))) + 0x148));
                        if (temp_a0_6 & 1) {
                            var_s1 = (*(u16 *)((char *)(arg2) + 0x20)) - (func_800180D4(((__repair_field_18 *)arg2)->value + var_s0, ((*(u16 *)((char *)(arg2) + 0x1C)) - var_s0) & 0xFFFF, (*(u16 *)((char *)(arg2) + 0x1E)), func_80018030(temp_a0_6) & 0xFFFF, D_800E1766) >> 1);
                        } else {
                            var_s1 = (*(u16 *)((char *)(arg2) + 0x20)) + D_800E1768;
                        }
                    }
                    temp_v1_2 = (*(s32 *)((char *)(temp_s4) + 0xC));
                    temp_a1_3 = temp_s3_2 & 0xFF;
                    temp_t2_3 = temp_a1_3 - 0x21;
                    if (temp_v1_2) {
                        temp_a2 = var_s7 * 8;
                        var_a0 = 0;
                        if ((*(u8 *)((char *)((temp_a2 + temp_v1_2)) + 4)) != 0) {
loop_42:
                            temp_a1_4 = temp_a2 + temp_v1_2;
                            temp_v1_3 = (var_a0 * 2) + ((__repair_field_0 *)temp_a1_4)->value;
                            var_a0 += 1;
                            if ((*(u8 *)((char *)(temp_v1_3) + 0)) != temp_a1_3) {
                                if (var_a0 < (u8) (*(u8 *)((char *)(temp_a1_4) + 4))) {
                                    goto loop_42;
                                }
                            } else {
                                var_s1 -= (*(s8 *)((char *)(temp_v1_3) + 1));
                            }
                        }
                    }
                    temp_a3 = temp_t2_3 * 5;
                    temp_v1_4 = temp_a3 + (*(void **)((char *)(temp_s4) + 8));
                    temp_t3 = (*(u8 *)((char *)(temp_v1_4) + 0)) << 5;
                    temp_t4 = (*(u8 *)((char *)(temp_v1_4) + 1)) << 5;
                    temp_a0_7 = (*(s8 *)((char *)(temp_v1_4) + 4));
                    if (D_8010A4E8 != 0) {
                        var_a2_2 = D_80115328;
                        temp_a0_8 = arg1 + ((var_s5 - temp_a0_7) * 2);
                        temp_v1_5 = temp_a3 + (*(void **)((char *)(temp_s4) + 8));
                        D_80115328 = var_a2_2 + 8;
                        D_80115328 = var_a2_2 + 0x10;
                        (*(s32 *)((char *)(var_a2_2) + 8)) = 0xE1000000;
                        (*(s32 *)((char *)(var_a2_2) + 0xC)) = (s32) ((temp_t3 << 0x10) | temp_t4);
                        D_80115328 = var_a2_2 + 0x18;
                        (*(s32 *)((char *)(var_a2_2) + 0x10)) = 0xF1000000;
                        (*(s32 *)((char *)(var_a2_2) + 4)) = (s32) (((((arg0 + var_s1) * 4) & 0xFFF) << 0xC) | ((temp_a0_8 * 4) & 0xFFF));
                        (*(s32 *)((char *)(var_a2_2) + 0x14)) = 0x04000200;
                        var_a1_2 = (((arg0 + (var_s1 + (*(u8 *)((char *)(temp_v1_5) + 2)))) * 4) & 0xFFF) << 0xC;
                        var_a0_2 = temp_a0_8 + ((*(u8 *)((char *)(temp_v1_5) + 3)) * 2);
                    } else {
                        var_a2_2 = D_80115328;
                        var_a0_2 = arg0 + var_s1;
                        temp_a0_9 = arg1 + (var_s5 - temp_a0_7);
                        temp_v1_6 = temp_a3 + (*(void **)((char *)(temp_s4) + 8));
                        D_80115328 = var_a2_2 + 8;
                        D_80115328 = var_a2_2 + 0x10;
                        (*(s32 *)((char *)(var_a2_2) + 8)) = 0xE1000000;
                        (*(s32 *)((char *)(var_a2_2) + 0xC)) = (s32) ((temp_t3 << 0x10) | temp_t4);
                        D_80115328 = var_a2_2 + 0x18;
                        (*(s32 *)((char *)(var_a2_2) + 0x10)) = 0xF1000000;
                        (*(s32 *)((char *)(var_a2_2) + 4)) = (s32) ((((var_a0_2 * 4) & 0xFFF) << 0xC) | ((temp_a0_9 * 4) & 0xFFF));
                        var_a1_2 = (((var_a0_2 + (*(u8 *)((char *)(temp_v1_6) + 2))) * 4) & 0xFFF) << 0xC;
                        (*(s32 *)((char *)(var_a2_2) + 0x14)) = 0x04000400;
                        var_a0_2 = temp_a0_9 + (*(u8 *)((char *)(temp_v1_6) + 3));
                    }
                    *var_a2_2 = var_a1_2 | (((var_a0_2 * 4) & 0xFFF) | 0xE4000000);
                    var_s7 = temp_t2_3;
                    var_v1_3 = (*(u8 *)((char *)(((temp_t2_3 * 5) + (*(void **)((char *)(temp_s4) + 8)))) + 2)) + (*(s8 *)((char *)(temp_s4) + 0x11));
                    var_s1 += var_v1_3;
                    goto block_48;
                }
                var_s0 += 1;
            } while (var_s0 < (u16) (*(u16 *)((char *)(arg2) + 0x1C)));
        }
        temp_v0_6 = D_80115328;
        D_80115328 = temp_v0_6 + 8;
        ((__repair_field_0 *)temp_v0_6)->value = 0xE8000000;
        (*(s32 *)((char *)(temp_v0_6) + 4)) = 0;
    }
}
