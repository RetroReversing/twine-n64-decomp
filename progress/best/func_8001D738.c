/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */
#ifndef M2C_DEFINES
#define M2C_DEFINES
typedef s32 M2C_UNK;
typedef s8 M2C_UNK8;
typedef s16 M2C_UNK16;
typedef s32 M2C_UNK32;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define M2C_CARRY 0
#define M2C_OVERFLOW(a) (0)
#endif

s32 func_800160FC();
s32 func_800162BC();
s32 func_80022A30();
s32 func_80022AD8();
s32 func_80022E18();
s32 func_80025D84();
s32 func_80025E9C();
s32 formatTextEntry();
s32 func_8002638C();
s32 func_800274BC();
s32 func_8002A644();
s32 func_8002A7CC();
s32 func_8002A9A8();
s32 func_8002AC04();
u8 func_8002D13C();
s32 lookupDataEntry();
s32 sprintf();
extern char D_800D285C[];
extern char D_800D2864[];
extern u8 D_800B7CF0;
extern u8 gMenuParamC;
extern s8 D_800BD690;
extern char D_800BD914[];
typedef struct { u8 f0; u8 pad[23]; } Slot_80100198;
extern Slot_80100198 D_80100198[];
extern u8 D_801002AD;
extern char D_80100408[];
extern u8 D_801007C1;
extern u8 D_80102EB0;
extern u8 D_80102EB8;
extern char D_80102F48[];
extern u8 D_80104310;
extern u8 D_80108960;
extern void *gMenuState;
extern u8 D_80109E20;
extern u8 D_8010A394;
extern char D_8010A488[];
extern u8 D_8010D2B1;
extern u8 D_8010D454;
extern char D_80115088[];
extern char D_80115089[];
extern char D_8011508A[];
extern char D_8011508C[];
extern char D_8011508D[];
extern char D_8011508E[];
extern char D_8011508F[];
extern char D_80115090[];
extern char D_80115091[];
extern s32 func_8001AC88;
extern s32 func_80022C04;

void func_8001D738(void) {
    s32 temp_a0;
    s32 temp_s0;
    s32 temp_s2;
    s32 temp_s2_2;
    s32 temp_s3;
    s32 temp_s4;
    s32 temp_s5;
    s32 temp_s6;
    s32 temp_s7;
    s32 temp_v0_8;
    s32 temp_v1;
    s32 var_a0;
    s32 var_a0_2;
    s32 var_a0_3;
    s32 var_a0_4;
    s32 var_a0_5;
    s32 var_a0_6;
    s32 var_a0_7;
    s32 var_a0_8;
    s32 var_a0_9;
    s32 var_a2;
    s32 var_a3;
    s32 var_s1;
    s32 var_s1_2;
    u32 temp_s0_2;
    u8 temp_v0;
    u8 temp_v0_2;
    u8 temp_v0_3;
    u8 temp_v0_4;
    u8 temp_v0_5;
    u8 temp_v0_6;
    u8 temp_v0_7;
    s8 temp_v1_2;
    s8 temp_v1_3;

    D_800BD690 = 1;
    temp_s6 = func_8002638C(D_800BD914, 0x78);
    temp_s2 = func_8002638C(D_800BD914, 0x79);
    var_s1 = func_8002638C(D_800BD914, 0x7A);
    if (var_s1 == 0) {
        var_s1 = func_8002638C(D_800BD914, 0x13);
    }
    temp_s3 = func_8002638C(D_800BD914, 0x7B);
    temp_s7 = func_8002638C(D_800BD914, 0x7D);
    temp_s4 = func_8002638C(D_800BD914, 0x7C);
    temp_s0 = func_8002638C(D_800BD914, 0x162);
    temp_s5 = func_8002638C(D_800BD914, 0x7F);
    if (((temp_s6 != 0) & (temp_s2 != 0)) && ((var_s1 != 0) & (temp_s3 != 0)) && ((temp_s7 != 0) & (temp_s4 != 0)) && ((temp_s5 != 0) & (temp_s0 != 0))) {
        D_800B7CF0 = D_801002AD;
        temp_v1 = D_801002AD & 0xFF;
        D_80100198[temp_v1].f0 = *(D_80115091 + (temp_v1 * 0xA0));
        temp_v0 = *(D_80115088 + (D_800B7CF0 * 0xA0));
        D_80109E20 = temp_v0;
        var_a0 = 0x10;
        if (temp_v0 != 0) {
            var_a0 = 0xF;
        }
        do { formatTextEntry(temp_s6, D_800D2864, lookupDataEntry(var_a0)); } while (0);
        temp_v0_2 = *(D_80115089 + (D_800B7CF0 * 0xA0));
        D_8010D454 = temp_v0_2;
        var_a0_2 = 0xA;
        if (temp_v0_2 != 0) {
            var_a0_2 = 9;
        }
        formatTextEntry(temp_s2, D_800D2864, lookupDataEntry(var_a0_2));
        D_8010D2B1 = *(D_8011508A + (D_800B7CF0 * 0xA0));
        temp_v1_2 = D_80100198[D_800B7CF0].f0;
        temp_a0 = var_s1 - 0x28;
        if (((s32) temp_v1_2 < 2) && ((s32) temp_v1_2 >= 0)) {
            func_80025E9C(temp_a0, var_s1, temp_s2 - 0x28, temp_s3 - 0x28, 1, 0xD);
        } else {
            func_80025D84(temp_a0, var_s1, temp_s2 - 0x28, temp_s3 - 0x28, 0x7A, 1);
            var_a0_3 = 0x11;
            if (D_8010D2B1 != 0) {
                var_a0_3 = 0x12;
            }
            formatTextEntry(var_s1, D_800D2864, lookupDataEntry(var_a0_3));
        }
        temp_v0_3 = *(D_80115090 + (D_800B7CF0 * 0xA0));
        D_80102EB0 = temp_v0_3;
        var_a0_4 = 0xA;
        if (temp_v0_3 != 0) {
            var_a0_4 = 9;
        }
        formatTextEntry(temp_s3, D_800D2864, lookupDataEntry(var_a0_4));
        temp_v0_4 = *(D_8011508D + (D_800B7CF0 * 0xA0));
        D_801007C1 = temp_v0_4;
        var_a0_5 = 0xA;
        if (temp_v0_4 != 0) {
            var_a0_5 = 9;
        }
        do { formatTextEntry(temp_s7, D_800D2864, lookupDataEntry(var_a0_5)); } while (0);
        temp_v0_5 = *(D_8011508C + (D_800B7CF0 * 0xA0));
        D_8010A394 = temp_v0_5;
        var_a0_6 = 0xA;
        if (temp_v0_5 != 0) {
            var_a0_6 = 9;
        }
        formatTextEntry(temp_s4, D_800D2864, lookupDataEntry(var_a0_6));
        D_80108960 = *(D_8011508F + (D_800B7CF0 * 0xA0));
        temp_v1_3 = D_80100198[D_800B7CF0].f0;
        if ((s32) temp_v1_3 >= 0) {
            var_a0_7 = temp_s0 - 0x28;
            if ((s32) temp_v1_3 >= 2) {
                if ((s32) temp_v1_3 < 6) {
                    if ((s32) temp_v1_3 >= 4) {
                        var_a0_7 = temp_s0 - 0x28;
                        goto block_27;
                    }
                    goto block_31;
                }
                goto block_30;
            }
block_27:
            func_80025E9C(var_a0_7, temp_s0, temp_s4 - 0x28, temp_s5 - 0x28, 1, 0xD);
            if (M2C_FIELD(gMenuState, u8 *, 8) == 0xD) {
                func_800274BC(0x100, 2);
            }
        } else {
            var_a0_7 = temp_s0 - 0x28;
block_30:
block_31:
            func_80025D84(var_a0_7, temp_s0, temp_s4 - 0x28, temp_s5 - 0x28, 0x162, 1);
            var_a0_8 = 0xA;
            if (D_80108960 != 0) {
                var_a0_8 = 9;
            }
            formatTextEntry(temp_s0, D_800D2864, lookupDataEntry(var_a0_8));
        }
        temp_v0_6 = *(D_8011508E + (D_800B7CF0 * 0xA0));
        D_80104310 = temp_v0_6;
        var_a0_9 = 0xA;
        if (temp_v0_6 != 0) {
            var_a0_9 = 9;
        }
        var_s1_2 = 0;
        formatTextEntry(temp_s5, D_800D2864, lookupDataEntry(var_a0_9));
        func_8002A644(D_8010A488, D_80100408, 0x1A4, 0xB, 0x25, 0xB4, 0x34, 0xE, 1, &func_80022C04, &func_8001AC88);
        func_80022A30(gMenuParamC, 0x23, 0x2C, 0x33, 0x9A);
        temp_v0_7 = func_8002D13C(0xA3);
        D_80102EB8 = temp_v0_7;
        if (temp_v0_7 & 0xFF) {
            do {
                temp_s0_2 = var_s1_2 & 0xFFFF;
                temp_v0_8 = func_800162BC(gMenuParamC);
                *(s32 *)((temp_s0_2 * 4) + D_80102F48) = temp_v0_8;
                if (temp_v0_8 != 0) {
                    temp_s5 = lookupDataEntry((var_s1_2 + 0x400D) & 0xFFFF);
                    if (temp_s0_2 < 4U) {
                        var_a2 = lookupDataEntry(0xAD);
                        var_a3 = temp_s0_2 + 1;
                    
                    sprintf(temp_s5, D_800D285C, var_a2, var_a3);} else {
                        var_a2 = lookupDataEntry(0x158);
                        var_a3 = temp_s0_2 - 3;
                    
                    sprintf(temp_s5, D_800D285C, var_a2, var_a3);}
                    func_800160FC(*(s32 *)(((var_s1_2 & 0xFFFF) * 4) + D_80102F48), temp_s5, 0x40);
                }
                func_8002A7CC(D_8010A488, *(s32 *)(((var_s1_2 & 0xFFFF) * 4) + D_80102F48), var_s1_2 & 0xFF, 1);
                var_s1_2 += 1;
            } while ((u32) (var_s1_2 & 0xFFFF) < (u8) D_80102EB8);
        }
        func_80022E18(gMenuParamC);
        func_80022AD8(gMenuParamC);
        func_8002A9A8(D_8010A488, D_801002AD);
        func_8002AC04(D_8010A488, 1);
    }
}
