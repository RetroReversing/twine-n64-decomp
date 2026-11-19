/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

s32 func_8000A894();
void *func_800262A8();
void *func_80026314();
s32 func_80027CE0();
s32 func_8002AAD4();
s32 func_8002AAF4();
s32 func_8002AB14();
s32 func_8002AB34();
s32 func_8002AB54();
s32 func_8002AB6C();
extern char D_80000001[];
extern s32 D_800BD644;
extern s32 D_800BD64C;
extern s32 D_800BD660;
extern f64 D_800D2CD0;
extern f64 D_800D2CD8;
extern void *D_80109BB0;

typedef struct { unsigned char pad[16]; int value; } __repair_field_10;
s32 func_80029C08(void *arg0, s32 arg1, s32 arg2) {
    unsigned int var_a0;
    f64 var_ft0;
    s32 var_a0_3;
    f32 temp_fv1;
    f32 temp_fv1_2;
    s32 var_a0_2;
    f64 var_ft0_2;
    s32 *var_a0_4;
    register s32 temp_s0;
s32 __repair_phase_temp_s0;
    s32 temp_s0_2;
    
    unsigned int temp_s0_4;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v1_3;
    s32 var_a1;
    s32 var_s0;
    s32 var_s1;
    s32 var_v0_2;
    s32 var_v0_3;
    s32 var_v1;
    u8 temp_s6;
    u8 temp_v1;
    u8 var_s1_2;
    register u8 var_v0_4;
    void *temp_a0;
    void *temp_a1;
    void *temp_a1_2;
    void *temp_s3;
    void *temp_s3_2;
    void *temp_v1_2;
    void *var_s3;
    void *var_s4;
    void *var_v0;

    if (arg0 != (s32)NULL) {
        temp_s6 = (*(u8 *)((char *)(arg0) + 0x18));
        if (!(arg2 & 0xFF)) {
            var_s4 = func_800262A8(((__repair_field_10 *)D_80109BB0)->value, 0xAC);
            var_s3 = func_800262A8(((__repair_field_10 *)D_80109BB0)->value, 0xAB);
            var_v0 = func_800262A8(((__repair_field_10 *)D_80109BB0)->value, 4);
            var_a1 = arg1 & 0xFF;
        } else {
            var_s4 = func_80026314(((__repair_field_10 *)D_80109BB0)->value, 0xAC, 2);
            var_s3 = func_80026314(((__repair_field_10 *)D_80109BB0)->value, 0xAB, 2);
            var_v0 = func_80026314(((__repair_field_10 *)D_80109BB0)->value, 4, 2);
            var_a1 = arg1 & 0xFF;
        }
        switch (var_a1) {                           /* irregular */
        case 0:
            var_s1 = func_80027CE0(0x25, var_a1) & 0xFF;
            var_a0 = 0x26;
            var_s0 = func_80027CE0(var_a0) & 0xFF;
            break;
        case 1:
            var_s1 = func_80027CE0(0x1E, var_a1) & 0xFF;
            var_a0 = 0x1F;
            var_s0 = func_80027CE0(var_a0) & 0xFF;
            break;
        default:
            temp_s0 = func_80027CE0(0x25, var_a1);
            var_s1 = (temp_s0 | func_80027CE0(0x1E)) & 0xFF;
            __repair_phase_temp_s0 = func_80027CE0(0x26);
            var_s0 = (__repair_phase_temp_s0 | func_80027CE0(0x1F)) & 0xFF;
            break;
        }
        if (!((var_s3 != NULL) & (var_s4 != NULL))) {
            goto block_12;
        }
        if (((u32)var_s1 != 0) && ((*(u8 *)((char *)(D_80109BB0) + 0x29)) != 0)) {
            var_a0_2 = 0xEB;
            if (func_8002AB54(arg0) & 0xFF) {
                var_a0_2 = 0xEC;
            }
            func_8000A894(var_a0_2);
            temp_a1 = (*(void **)((char *)(var_s3) + 8));
            ((__repair_field_10 *)temp_a1)->value = (s32) ((D_800BD644 & ~0xFF) | (*(u8 *)((char *)(D_80109BB0) + 0x30)));
            if ((*(u8 *)((char *)(arg0) + 0x1E)) == 0) {
                func_8002AAF4(arg0, temp_a1);
            } else {
                func_8002AB34(arg0, temp_a1);
            }
        } else if ((var_s0 != 0) && ((*(u8 *)((char *)(D_80109BB0) + 0x29)) != 0)) {
            var_a0_3 = 0xEB;
            if (func_8002AB6C(arg0) & 0xFF) {
                var_a0_3 = 0xEC;
            }
            func_8000A894(var_a0_3);
            temp_a1_2 = (*(void **)((char *)(var_s4) + 8));
            ((__repair_field_10 *)temp_a1_2)->value = (s32) ((D_800BD644 & ~0xFF) | (*(u8 *)((char *)(D_80109BB0) + 0x30)));
            if ((*(u8 *)((char *)(arg0) + 0x1E)) == 0) {
                func_8002AAD4(arg0, temp_a1_2);
            } else {
                func_8002AB14(arg0, temp_a1_2);
            }
        } else {
            if ((*(s32 *)((char *)(var_s4) + 0x20)) != 0x390024) {
                var_a0_4 = &D_800BD660;
            } else {
                var_a0_4 = &D_800BD64C;
            }
            (*(s32 *)((char *)((*(void **)((char *)(var_s3) + 8))) + 0x10)) = (s32) ((*var_a0_4 & ~0xFF) | (*(u8 *)((char *)(D_80109BB0) + 0x30)));
            (*(s32 *)((char *)((*(void **)((char *)(var_s4) + 8))) + 0x10)) = (s32) ((*var_a0_4 & ~0xFF) | (*(u8 *)((char *)(D_80109BB0) + 0x30)));
            temp_v1 = (*(u8 *)((char *)(D_80109BB0) + 0x30));
            var_s1_2 = 0xFF;
            if (temp_v1 < 0xFFU) {
                var_s1_2 = temp_v1;
            }
            temp_s3 = (*(void **)((char *)(var_s3) + 8));
            temp_s0 = ((__repair_field_10 *)temp_s3)->value & ~0xFF;
            var_v0_2 = temp_v1 | temp_s0;
            if (!(func_8002AB54(arg0, -0x100, D_80109BB0, (*(void **)((char *)(var_s3) + 8))) & 0xFF)) {
                var_v0_2 = temp_s0 | (*(u8 *)((char *)((*(void **)((char *)(D_80109BB0) + 0x1C))) + 0x13));
            }
            temp_s3_2 = (*(void **)((char *)(var_s4) + 8));
            temp_s0_4 = ((__repair_field_10 *)temp_s3_2)->value & ~0xFF;
            ((__repair_field_10 *)temp_s3)->value = var_v0_2;
            var_v0_3 = var_s1_2 | temp_s0_4;
            if (!(func_8002AB6C(arg0) & 0xFF)) {
                var_v0_3 = temp_s0_4 | (*(u8 *)((char *)((*(void **)((char *)(D_80109BB0) + 0x1C))) + 0x13));
            }
            ((__repair_field_10 *)temp_s3_2)->value = var_v0_3;
        }
        if (var_v0 != NULL) {
            temp_v1_2 = (*(void **)((char *)(var_v0) + 8));
            if (temp_v1_2 != NULL) {
                temp_v0 = (*(s32 *)((char *)(var_v0) + 0x14));
                var_ft0 = (f64) temp_v0;
                if (0 > temp_v0) {
                    var_ft0 += D_800D2CD0;
                }
                temp_fv1 = (*(f32 *)((char *)(arg0) + 0xC)) * (f32) var_ft0;
                if (temp_fv1 >= 2.1474836e9f) {
                    var_v0_4 = (s32) (temp_fv1 - 2.1474836e9f) | 0x80000001;
                } else {
                    var_v0_4 = (s32) temp_fv1 + 1;
                }
                (*(u8 *)((char *)(temp_v1_2) + 0x29)) = var_v0_4;
                temp_a0 = (*(void **)((char *)(var_v0) + 8));
                temp_v1_3 = (*(s32 *)((char *)(var_v0) + 0x14));
                if ((u32) temp_v1_3 < (u8) (*(u8 *)((char *)(temp_a0) + 0x29))) {
                    (*(u8 *)((char *)(temp_a0) + 0x29)) = (u8) temp_v1_3;
                }
                temp_v0_2 = (*(s32 *)((char *)(var_v0) + 0x14));
                var_ft0_2 = (f64) temp_v0_2; if (temp_v0_2 < 0) {
                    var_ft0_2 += D_800D2CD8;
                }
                temp_fv1_2 = (*(f32 *)((char *)(arg0) + 0x10)) * (f32) var_ft0_2;
                var_v1 = (u32) temp_fv1_2;
                (*(s16 *)((char *)((*(void **)((char *)(var_v0) + 8))) + 0x22)) = (s16) (var_v1 + (*(u16 *)((char *)(var_v0) + 0x1A)));
            }
        }
        return temp_s6 != (*(u8 *)((char *)(arg0) + 0x18));
    }
block_12:
    return 0;
}
