extern u8 D_54D910[];
extern u8 D_800C0784[];
extern s8 D_80109A94;
#define FLD(p, t, o) (*(t *)((u8 *)(p) + (o)))

void func_8000B9B8(u8 *, s32, u32);
void func_800134C0(void);
void func_800134C8(void);
s32 func_8001499C(s32 *);
s32 func_800149D4(void *);
s32 func_80014A0C(s32 *, s32 *);
s32 func_800328B8(void *, s32 *);
s32 func_800336FC(s32 *, s32 *, s32 *, s32 *, s32, f32, s32, s32, s32, s32 *, s32 *);
s32 *func_80083E90(s32, s32);
s32 func_80084048(s32 *, s32);

void func_80043FA0(void *arg0) {
    u8 sp30[0x20], sp50[0x20];
    s32 sp70, sp74;
    s32 *sp7C, *sp84, *sp8C;
    f32 var_fs0;
    union { s32 * pointer; s32 value; } __repair_phase_storage;
    s32 *temp_s1, *temp_s2, *temp_s6, *temp_t0;
    s32 *temp_v0_3, *temp_v0_7, *temp_v0_9;
    s32 *var_fp, *var_s2, *var_s3, *var_s5, *var_s7;
    s32 temp_s6_2, temp_v0_2, temp_v0, temp_v0_4, temp_v0_5, temp_v0_6;
    u8 *temp_v0_8;
    var_s5 = NULL;
    if (arg0 != NULL) {
        var_s7 = NULL;
        sp7C = NULL;
        var_fs0 = 1.0f;
        if (FLD(arg0, u8, 0x48) & 0x10) var_fs0 = 64.0f;
        func_800134C0();
        func_8000B9B8(sp30, D_54D910 + FLD(arg0, s32, 4), 0x20);
        sp8C = FLD(arg0, s32 *, 0x34);
        if (sp8C != (u32)NULL) goto block_10;
        var_s5 = func_80083E90(FLD(sp30, u16, 4) * 0x18, 0x2D);
        if (var_s5 != NULL) {
            func_8000B9B8(sp50, D_54D910 + FLD(sp30, s32, 0), 0x20);
            temp_v0 = func_800149D4(sp50);
            if (temp_v0 == 0) {
                sp8C = var_s5;
                func_8000B9B8(var_s5, D_54D910 + FLD(sp30, s32, 0), FLD(sp30, u16, 4) * 0xC);
            } else {
                func_8000B9B8(var_s5, D_54D910 + FLD(sp30, s32, 0), temp_v0);
                sp8C = (s32 *)((u8 *)var_s5 + FLD(sp30, u16, 4) * 0xC);
                do { func_8001499C(var_s5); } while (0);
                func_80014A0C(sp8C, var_s5);
            }
block_10:
            temp_v0_2 = FLD(sp30, u16, 0x0C) * 4;
            temp_v0_3 = func_80083E90(FLD(sp30, u16, 0x0A) * 8 + temp_v0_2 + temp_v0_2 + FLD((int)sp30, u16, 0x0E), 0x2D);
            if (temp_v0_3 != NULL) {
                var_s7 = temp_v0_3;
                temp_t0 = &var_s7[FLD(sp30, u16, 0x0A)];
                temp_s1 = &temp_t0[FLD(sp30, u16, 0x0A)];
                temp_s2 = &temp_s1[FLD(sp30, u16, 0x0C)];
                temp_s6 = &temp_s2[FLD(sp30, u16, 0x0C)];
                sp84 = temp_t0;
                func_8000B9B8(sp50, D_54D910 + FLD(sp30, s32, 8), 0x20);
                temp_v0_4 = func_800149D4(sp50);
                if (temp_v0_4 == 0) { var_fp = temp_s1; func_8000B9B8(temp_s1, D_54D910 + FLD(sp30, s32, 8), FLD(sp30, u16, 0x0C) * 4); }
                else { var_fp = temp_s2; func_8000B9B8(temp_s1, D_54D910 + FLD(sp30, s32, 8), temp_v0_4); func_8001499C(temp_s1); func_80014A0C(var_fp, temp_s1); }
                func_8000B9B8(sp50, D_54D910 + FLD(sp30, s32, 0x0C), 0x20);
                temp_v0_5 = func_800149D4(sp50);
                if (temp_v0_5 == 0) { var_s3 = var_s7; func_8000B9B8(var_s7, D_54D910 + FLD(sp30, s32, 0x0C), FLD(sp30, u16, 0x0A) * 4); }
                else { var_s3 = sp84; func_8000B9B8(var_s7, D_54D910 + FLD(sp30, s32, 0x0C), temp_v0_5); func_8001499C(var_s7); func_80014A0C(var_s3, var_s7); }
                func_8000B9B8(sp50, D_54D910 + FLD(sp30, s32, 0x10), 0x20);
                temp_v0_6 = func_800149D4(sp50);
                if (temp_v0_6 == 0) { var_s2 = temp_s6; func_8000B9B8(temp_s6, D_54D910 + FLD(sp30, s32, 0x10), FLD(sp30, u16, 0x0E)); goto block_21; }
                func_8000B9B8(temp_s6, D_54D910 + FLD(sp30, s32, 0x10), temp_v0_6);
                temp_v0_7 = func_80083E90(func_8001499C(temp_s6), 0x2D);
                sp7C = temp_v0_7;
                if (temp_v0_7 != NULL) { func_80014A0C(sp7C, temp_s6); var_s2 = sp7C;
block_21:
                    temp_v0_8 = *(u8 **)(D_800C0784 + (FLD(arg0, u16, 0x30) & 0xFFF0));
                    sp70 = 0; sp74 = 0;
                    temp_s6_2 = FLD(temp_v0_8, s32, 0x10);
                    __repair_phase_storage.value = FLD(temp_v0_8, s32, 0x18);
                    func_800336FC(var_s2, sp8C, var_fp, var_s3, FLD(arg0, u8, 0x45), var_fs0, __repair_phase_storage.value, temp_s6_2, 0, &sp70, &sp74);
                    temp_v0_9 = func_80083E90(sp70 * 0x10 + sp74 * 8, 0x2E);
                    if (temp_v0_9 != NULL) {
                        func_800328B8((u8 *)temp_v0_9 + sp74 * 8, temp_v0_9);
                        FLD(arg0, s32 *, 0) = temp_v0_9;
                        func_800336FC(var_s2, sp8C, var_fp, var_s3, FLD(arg0, u8, 0x45), var_fs0, __repair_phase_storage.value, temp_s6_2, 1, NULL, NULL);
                        if (D_80109A94 != 0) FLD(arg0, u8, 0x46) |= 0x80;
                    }
                    goto block_24;
                }
            } else goto block_24;
        } else {
block_24:
            if (sp7C != NULL) func_80084048(sp7C, 0x2D);
        }
        if (FLD(arg0, s32 *, 0x34) == NULL) func_80084048(var_s5, 0x2D);
        if (var_s7 != NULL) func_80084048(var_s7, 0x2D);
        func_800134C8();
    }
}
