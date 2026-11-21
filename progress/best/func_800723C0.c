typedef union { s32 w[9]; f32 f[9]; } Vec9;
void *spawnEffectObject(s32, s32, s32);
void objectListInsert(void *, s32);
void func_800328B8(void *, void *);
void func_800336FC(void *, void *, void *, void *, s32, f32, s32, s32, s32, s32, s32);
s32 func_8004493C(s32);
s32 func_80044968(s32);
void func_80045278(void *);
void func_80045314(void *, void *, void *);
void func_80045474(void *, void *, void *, void *);
f32 randomFloatMinusOffset(f32, f32);
f32 func_80045F44(void *, void *);
void func_80072390(void *, f32, void *);
void *func_80083E90(s32, s32);
void func_80084048(void *, s32);
extern s32 D_800C7E60;
extern f32 D_800E1A38;
extern f32 D_800E1A3C;
extern f32 D_800E1A40;
extern f32 D_800E1A5C;
extern f32 D_800E1A60;
extern s32 D_800E1A64;
extern s32 D_800E1A68;

typedef struct { float field_0; float field_4; float field_8; int field_C; unsigned char pad_10[8]; void * field_18; void * field_1C; } __repair_record_temp_s0;
void *func_800723C0(s32 *arg0, s32 *arg1, s32 *arg2, void *arg3, s32 arg4) {
    f32 *__base_D_800E1A38;
    f32 sp30[9];
    Vec9 sp58;
    Vec9 sp80;
    Vec9 spA8;
    s32 *s;
    s32 *d;
    void *temp_v0;
    void *temp_v0_2;
    void *temp_v0_3;
    void *temp_v0_4;
    void *temp_v0_5;
    void *temp_s0;
    void *temp_s3;
    void *material;
    void *lastFree;
    
    f32 var_fs0;
    f32 temp_fv0;
    f32 temp_fv0_2;
    f32 temp_ft0;
    long temp_s0_2;

    sp58 = *(Vec9 *)arg0;
    sp80 = *(Vec9 *)arg1;
    spA8 = *(Vec9 *)arg2;
    D_800E1A68 += 1;
    temp_v0 = spawnEffectObject(0x24, 0, 0);
    if (temp_v0 != NULL) {
        temp_v0_2 = *(void **) ((u8 *) temp_v0 + 0x6C); temp_s0=(void *)temp_v0_2;
        *(s16 *) ((u8 *) temp_v0 + 0x78) = 0x1C;
        func_80045474(arg0, arg1, arg2, sp30);
        __base_D_800E1A38 = &D_800E1A38;
        var_fs0 = func_80045F44(arg0, __base_D_800E1A38);
        temp_fv0 = func_80045F44(arg1, __base_D_800E1A38);
        if (temp_fv0 < var_fs0) {
            var_fs0 = temp_fv0;
        }
        temp_fv0_2 = func_80045F44(arg2, __base_D_800E1A38);
        if (temp_fv0_2 < var_fs0) {
            var_fs0 = temp_fv0_2;
        }
        if (var_fs0 == 0.0f) {
            var_fs0 = 0.1f;
        }
        temp_ft0 = 1.0f / var_fs0;
        ((__repair_record_temp_s0*)temp_s0)->field_0 = temp_ft0 * (sp30[0] - (*__base_D_800E1A38));
        ((__repair_record_temp_s0*)temp_s0)->field_4 = temp_ft0 * (sp30[1] - D_800E1A3C);
        ((__repair_record_temp_s0*)temp_s0)->field_8 = temp_ft0 * (sp30[2] - D_800E1A40);
        ((__repair_record_temp_s0*)temp_s0)->field_0 = ((__repair_record_temp_s0*)temp_s0)->field_0 + randomFloatMinusOffset(D_800E1A5C, D_800E1A60);
        ((__repair_record_temp_s0*)temp_s0)->field_4 = ((__repair_record_temp_s0*)temp_s0)->field_4 + randomFloatMinusOffset(D_800E1A5C, D_800E1A60);
        ((__repair_record_temp_s0*)temp_s0)->field_8 = ((__repair_record_temp_s0*)temp_s0)->field_8 + randomFloatMinusOffset(D_800E1A5C, D_800E1A60);
        ((__repair_record_temp_s0*)temp_s0)->field_C = (s32) (var_fs0 * 8.0f);
        if (((__repair_record_temp_s0*)temp_s0)->field_C >= 0x10) {
            ((__repair_record_temp_s0*)temp_s0)->field_C = 0xF;
        }
        func_80045314(sp58.w, sp30, sp58.w);
        func_80045314(sp80.w, sp30, sp80.w);
        func_80045314(spA8.w, sp30, spA8.w);
        material = func_80083E90(0x4C, 0x16);
        *(void **) ((u8 *) temp_v0 + 0x70) = material;
        if (material != NULL) {
            typedef struct { s32 w[19]; } Block76;
            s32 *src = (s32 *)arg3 + 16;
            s32 *dst = (s32 *)material + 16;
            *(Block76 *)material = *(Block76 *)arg3;
            *(s16 *) ((u8 *) material + 0x42) = 3;
            *(s32 *) ((u8 *) material + 0x34) = 0;
            *(s16 *) ((u8 *) material + 0x40) = 1;
            temp_v0_3 = func_80083E90(0x3C, 0x2D);
            temp_v0_2 = (u8 *) temp_v0_3 + 0xC;
            temp_s3 = (u8 *) temp_v0_3 + 0x30;
            if (temp_v0_3 == NULL) {
                func_80084048(*(void **) ((u8 *) temp_v0 + 0x70), 0x16);
                goto block_71;
            }
            func_80072390(sp58.w, 8.0f, temp_v0_2);
            func_80072390(sp80.w, 8.0f, (u8 *) temp_v0_3 + 0x18);
            func_80072390(spA8.w, 8.0f, (u8 *) temp_v0_3 + 0x24);
            *(s16 *) ((u8 *) temp_v0_3 + 0) = (s16) (s32) sp58.f[3];
            *(s16 *) ((u8 *) temp_v0_3 + 2) = (s16) (s32) sp58.f[4];
            ((u8 *)temp_s3)[0] = (u32)sp58.f[5];
            ((u8 *)temp_s3)[1] = (u32)sp58.f[6];
            ((u8 *)temp_s3)[2] = (u32)sp58.f[7];
            ((u8 *)temp_s3)[3] = (s32)sp58.f[8] | 0x40;
            ((s16 *)temp_v0_3)[2] = (s32)sp80.f[3];
            ((s16 *)temp_v0_3)[3] = (s32)sp80.f[4];
            ((u8 *)temp_s3)[4] = (u32)sp80.f[5];
            ((u8 *)temp_s3)[5] = (u32)sp80.f[6];
            ((u8 *)temp_s3)[6] = (u32)sp80.f[7];
            ((u8 *)temp_s3)[7] = (s32)sp80.f[8] | 0x40;
            ((s16 *)temp_v0_3)[4] = (s32)spA8.f[3];
            ((s16 *)temp_v0_3)[5] = (s32)spA8.f[4];
            ((u8 *)temp_s3)[8] = (u32)spA8.f[5];
            ((u8 *)temp_s3)[9] = (u32)spA8.f[6];
            ((u8 *)temp_s3)[10] = (u32)spA8.f[7];
            ((u8 *)temp_s3)[11] = (s32)spA8.f[8] | 0x40;
            temp_v0_4 = func_80083E90(0x30, 0x2D);
            ((__repair_record_temp_s0*)temp_s0)->field_18 = temp_v0_4;
            if (temp_v0_4 == NULL) {
                func_80084048(*(void **)((u8 *)temp_v0 + 0x70), 0x2D);
                lastFree = temp_v0_3;
                goto free_last;
            }
            temp_v0_5 = func_80083E90(0x100, 0x2D);
            ((__repair_record_temp_s0*)temp_s0)->field_1C = temp_v0_5;
            if (temp_v0_5 == NULL) {
                func_80084048(*(void **)((u8 *)temp_v0 + 0x70), 0x2D);
                func_80084048(temp_v0_3, 0x2D);
                lastFree = ((__repair_record_temp_s0*)temp_s0)->field_18;
free_last:
                func_80084048(lastFree, 0x2D);
                goto block_71;
            }
            func_800328B8(((__repair_record_temp_s0*)temp_s0)->field_18, temp_v0_5);
            *(void **)material = ((__repair_record_temp_s0*)temp_s0)->field_1C;
            temp_s0_2 = func_80044968(D_800E1A64);
            func_800336FC(&D_800C7E60, (u8 *)temp_v0_3 + 0xC, temp_s3, temp_v0_3, 3, 1.0f, temp_s0_2, func_8004493C(D_800E1A64), 1, 0, 0);
            func_80084048(temp_v0_3, 0x2D);
            *(s32 *)((u8 *)temp_v0 + 0x24) = ((s32 *)sp30)[0];
            *(s32 *)((u8 *)temp_v0 + 0x28) = ((s32 *)sp30)[1];
            *(s32 *)((u8 *)temp_v0 + 0x2C) = ((s32 *)sp30)[2];
            *(s32 *)((u8 *)temp_v0 + 0x30) = *(s32 *)((u8 *)temp_v0 + 0x24);
            *(s32 *)((u8 *)temp_v0 + 0x34) = *(s32 *)((u8 *)temp_v0 + 0x28);
            *(s32 *)((u8 *)temp_v0 + 0x38) = *(s32 *)((u8 *)temp_v0 + 0x2C);
            func_80045278((u8 *)temp_v0 + 0x48);
            func_80045278((u8 *)temp_v0 + 0x3C);
            *(u8 *)((u8 *)temp_v0 + 0x7E) = 3;
            *(u8 *)((u8 *)temp_v0 + 0x82) = 255;
            *(s16 *)((u8 *)temp_v0 + 0x7A) = 0;
            *(f32 *)((u8 *)temp_v0 + 0x54) = 0.125f;
            *(f32 *)((u8 *)temp_v0 + 0x64) = 5.0f;
            objectListInsert(temp_v0, arg4);
            return temp_v0;
        }
block_71:
        *(s32 *) ((u8 *) temp_v0 + 0x60) = *(s32 *) ((u8 *) temp_v0 + 0x60) | 1;
        return NULL;
    }
    return temp_v0;
}

