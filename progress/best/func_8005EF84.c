static __inline__ s16 __repair_inline(s16 a) { return a; }
/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

s32 func_8000A894();
s32 func_80031700();
f32 func_80045D2C();
s32 func_8005E350();
s32 func_8005EF30();
s32 func_80063C7C();
s32 func_80073AF8();
s32 func_80084338();
s32 *func_80087100();
s32 func_8011B0FC();
s32 func_8011B460();
s32 sprintf();
extern char D_800C469C[];
extern char D_800C46A1[];
extern char D_800C7C14[];
extern char D_800C7C16[];
extern u8 gSceneType;
extern s32 gBorderSkipFlag;
extern s32 D_8010302C;
extern char gAimAxisTable[];

typedef struct { unsigned char pad[108]; void * value; } __repair_field_6C;
typedef struct { unsigned char pad_0[38]; unsigned short field_26; unsigned short field_28; unsigned short field_2A; } __repair_record_temp_s3;
s32 func_8005EF84(void *arg0, void *arg1) {
    u8 sp30[0x80];
    u8 spB0[0x98];
    union { s32 * pointer; s32 value; } __repair_phase_storage;
    s32 *var_v0_3;
    s32 var_a0_2;
    s32 var_a1;
    f32 temp_fv1;
    f32 temp_fv1_2;
    f32 temp_fv1_3;
    s16 temp_v0_2;
    s16 temp_v0_4;
s16 __repair_result_temp_v0_4;
    
    s32 temp_v0_3;
    s32 var_a0;
    s32 var_a0_3;
    s32 var_s0;
    
    
    s32 var_v0;
s32 __repair_phase_var_v0;
    s32 var_v1;
    s8 temp_v0_5;
    u16 temp_a1;
    u16 temp_v0;
    u16 temp_v1;
    u16 temp_v1_2;
    u16 temp_v1_4;
    u16 temp_v1_9;
    u8 temp_s0;
    u8 temp_s2;
    u8 temp_v1_7;
    void *temp_a0;
    
    void *temp_a1_2;
    void *temp_s0_2;
    void *temp_s1;
    void *temp_s3;
    void *temp_s5;
    void *temp_v1_3;
    void *temp_v1_5;
    void *temp_v1_6;
    void *temp_v1_8;

    temp_s3 = (((__repair_field_6C *)arg1)->value);
    temp_v1 = (((__repair_record_temp_s3*)temp_s3)->field_26);
    temp_s1 = (((__repair_field_6C *)arg0)->value);
    switch (temp_v1) {                              /* switch 1; irregular */
    case 2:                                         /* switch 1 */
        temp_a1 = (((__repair_record_temp_s3*)temp_s3)->field_28);
        var_v0 = 0;


        if ((*(s16 *)((char *)((temp_s1 + (temp_a1 * 2))) + 0x1BC)) < *(s16 *)(D_800C7C16 + (temp_a1 * 4))) {
            var_v0 = 0;
            if ((func_8005EF30(arg0) << 0x18) != 0) {
                if (gBorderSkipFlag != 0) {
                    __repair_phase_storage.pointer = func_80087100(arg0, (((__repair_record_temp_s3*)temp_s3)->field_28) | 0x9000);
                    var_a0 = 0xA2;
                
                sprintf(sp30, "%s %s", __repair_phase_storage.pointer, func_80087100(var_a0));} else {
                    __repair_phase_storage.pointer = func_80087100((((__repair_record_temp_s3*)temp_s3)->field_28) | 0x9000);
                    var_a0 = 0x16A;
                
                sprintf(sp30, "%s %s", __repair_phase_storage.pointer, func_80087100(var_a0));}
                D_8010302C += 1;
                func_80073AF8(0, *(s32 *)(gAimAxisTable + ((*(s8 *)((char *)(temp_s1) + 0x182)) * 4)), sp30, -1, -1, 1, 0, 0, 0, 0, 0);
                temp_v1_2 = (((__repair_record_temp_s3*)temp_s3)->field_28);
                (*(u16 *)((char *)(temp_v1_3) + 0x1BC)) += *(s16 *)(D_800C7C14 + (temp_v1_2 * 4));
                temp_v1_3 = temp_s1 + (temp_v1_2 * 2);
                temp_v0 = (((__repair_record_temp_s3*)temp_s3)->field_28);
                temp_a0 = temp_s1 + (temp_v0 * 2);
                temp_v0_2 = *(s16 *)(D_800C7C16 + (temp_v0 * 4));
                if (temp_v0_2 < (*(s16 *)((char *)(temp_a0) + 0x1BC))) {
                    (*(s16 *)((char *)(temp_a0) + 0x1BC)) = temp_v0_2;
                }
                if ((*(u16 *)((char *)(arg0) + 0x78)) == 3) {
                    func_80084338(0xD8, arg0 + 0x24);
                } else {
                    func_8000A894(0xD8);
                }
            default:                                /* switch 1 */
block_66:
                func_80031700((((__repair_record_temp_s3*)temp_s3)->field_2A));
                var_v0 = 1;
            }
        }
        return var_v0;
    case 0:                                         /* switch 1 */
        temp_v1_4 = (((__repair_record_temp_s3*)temp_s3)->field_28);
        temp_v0_3 = temp_v1_4 * 0xE8;
        temp_s5 = temp_v0_3 + D_800C469C;
        temp_s2 = (*(u8 *)((char *)(temp_s5) + 0x80));
        __repair_phase_storage.value = 0;
        if ((u8) (*(u8 *)((char *)((temp_s1 + (temp_v1_4 * 8))) + 0x1FC)) < (u8) *(D_800C46A1 + temp_v0_3)) {
            D_8010302C += 1;
            func_80073AF8(0, *(s32 *)(gAimAxisTable + ((*(s8 *)((char *)(temp_s1) + 0x182)) * 4)), func_80087100((((__repair_record_temp_s3*)temp_s3)->field_28) | 0x6000, D_800C469C), -1, -1, 1, 0, 0, 0, 0, 0);
            temp_v1_5 = temp_s1 + ((((__repair_record_temp_s3*)temp_s3)->field_28) * 8);
            (*(u8 *)((char *)(temp_v1_5) + 0x1FC)) += 1;
            __repair_phase_storage.value = 1;
            if ((*(u16 *)((char *)(arg0) + 0x78)) == 3) {
                var_a0_2 = 0xD9;
                goto block_26;
            }
            var_a0_2 = 0xD9;
            goto block_27;
            goto block_28;
        }
        __repair_phase_var_v0 = 1;
        if ((*(s16 *)((char *)((temp_s1 + (temp_s2 * 2))) + 0x1BC)) < *(s16 *)(D_800C7C16 + (temp_s2 * 4))) {
            if (gBorderSkipFlag != 0) {
                var_v0_3 = func_80087100(temp_s2 | 0x9000, D_800C469C);
                var_a0_3 = 0x16A;
            
            sprintf(spB0, "%s %s", var_v0_3, func_80087100(var_a0_3));} else {
                var_v0_3 = func_80087100(temp_s2 | 0x9000, D_800C469C);
                var_a0_3 = 0xA2;
            
            sprintf(spB0, "%s %s", var_v0_3, func_80087100(var_a0_3));}
            D_8010302C += 1;
            func_80073AF8(0, *(s32 *)(gAimAxisTable + ((*(s8 *)((char *)(temp_s1) + 0x182)) * 4)), spB0, -1, -1, 1, 0, 0, 0, 0, 0);
            var_a0_2 = 0xD8;
            if ((*(u16 *)((char *)(arg0) + 0x78)) == 3) {
block_26:
                func_80084338(var_a0_2, arg0 + 0x24);
            } else {
block_27:
                func_8000A894();
            }
block_28:
            temp_fv1 = func_80045D2C();
            if (__repair_phase_storage.value != 0) {
                temp_s0 = (*(u8 *)((char *)(temp_s5) + 0x82));
                (*(u8 *)((char *)((temp_s1 + ((s32) (func_80063C7C((s16) (((__repair_record_temp_s3*)temp_s3)->field_28)) << 0x10) >> 0xD))) + 0x1FF)) = temp_s0;
            } else {
                temp_fv1_2 = (temp_fv1 * (f32) (*(u8 *)((char *)(temp_s5) + 0x82))) + 1.0f;
                var_s0 = (u32) temp_fv1_2;
var_v1 = temp_s2 * 2;

                temp_v1_6 = temp_s1 + var_v1;
                (*(u16 *)((char *)(temp_v1_6) + 0x1BC)) += var_s0;
            }
            temp_a1_2 = temp_s1 + (temp_s2 * 2);
            __repair_result_temp_v0_4 = __repair_inline(*(s16 *)(D_800C7C16 + (temp_s2 * 4)));
            if (__repair_result_temp_v0_4 < (*(s16 *)((char *)(temp_a1_2) + 0x1BC))) {
                (*(s16 *)((char *)(temp_a1_2) + 0x1BC)) = __repair_result_temp_v0_4;
                return 0;
            }
            temp_v0_5 = (*(s8 *)((char *)(temp_s5) + 4));
            if (temp_v0_5 != 0) {
                temp_s0_2 = (((((__repair_record_temp_s3*)temp_s3)->field_28) + temp_v0_5) * 0xE8) + D_800C469C;
                temp_v1_7 = (*(u8 *)((char *)(temp_s0_2) + 0x80));
                if (temp_v1_7 != (*(u8 *)((char *)(temp_s5) + 0x80))) {
                    temp_fv1_3 = ((func_80045D2C(0x3F000000) + 0.5f) * (f32) (*(u8 *)((char *)(temp_s0_2) + 0x82))) + 1.0f;
                    var_s0 = (u32) temp_fv1_3;
                    if (__repair_phase_storage.value != 0) {
                        (*(s8 *)((char *)((temp_s1 + ((s32) (func_80063C7C((s16) ((((__repair_record_temp_s3*)temp_s3)->field_28) + (s8) (u8) (*(s8 *)((char *)(temp_s5) + 4)))) << 0x10) >> 0xD))) + 0x1FF)) = (s8) var_s0;
                    } else {
                        temp_v1_8 = temp_s1 + (temp_v1_7 * 2);
                        (*(u16 *)((char *)(temp_v1_8) + 0x1BC)) += var_s0;
                    }
                    temp_a0 = temp_s1 + (temp_v1_7 * 2);
                    temp_v0_4 = *(s16 *)(D_800C7C16 + (temp_v1_7 * 4));
                    if (temp_v0_4 < (*(s16 *)((char *)(temp_a0) + 0x1BC))) {
                        (*(s16 *)((char *)(temp_a0) + 0x1BC)) = temp_v0_4;
                    }
                }
            }
            goto block_66;
        }
        /* Duplicate return node #67. Try simplifying control flow for better match */
        return __repair_phase_var_v0;
    case 1:                                         /* switch 1 */
        func_8005E350(arg0, (((__repair_record_temp_s3*)temp_s3)->field_28), 1);
        if ((gBorderSkipFlag != 0) && (gSceneType == 8)) {
            temp_v1_9 = (((__repair_record_temp_s3*)temp_s3)->field_28);
            switch (temp_v1_9) {                    /* switch 2; irregular */
            case 23:                                /* switch 2 */
                var_a1 = 1;
                func_8011B460(temp_s1, var_a1);
                if ((*(u8 *)((char *)((*(void **)((char *)(temp_s1) + 0xB4))) + 0x10)) == 7) {
                    func_8011B0FC(temp_s1);
                }
                break;
            case 24:                                /* switch 2 */
                var_a1 = 2;
                func_8011B460(temp_s1, var_a1);
                if ((*(u8 *)((char *)((*(void **)((char *)(temp_s1) + 0xB4))) + 0x10)) == 7) {
                    func_8011B0FC(temp_s1);
                }
                break;
            case 25:                                /* switch 2 */
                var_a1 = 4;
                func_8011B460(temp_s1, var_a1);
                if ((*(u8 *)((char *)((*(void **)((char *)(temp_s1) + 0xB4))) + 0x10)) == 7) {
                    func_8011B0FC(temp_s1);
                }
                break;
            }
        }
        (*(s32 *)((char *)(arg1) + 0x60)) |= 1;
        goto block_66;
    }
}
