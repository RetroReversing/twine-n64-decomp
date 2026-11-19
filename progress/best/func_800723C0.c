typedef union { s32 w[9]; f32 f[9]; } Vec9;
void *func_80016410(s32, s32, s32, void *);
void func_80016990(void *, s32);
void func_800328B8(void *, void *);
void func_800336FC(void *, void *, void *, void *, s32, f32, s32, s32, s32, s32, s32);
s32 func_8004493C(s32);
s32 func_80044968(s32);
void func_80045278(void *);
void func_80045314(void *, void *, void *);
void func_80045474(void *, void *, void *, void *);
f32 func_80045D8C(f32, f32);
f32 func_80045F44(void *, void *);
void func_80072390(void *, f32, void *);
void *func_80083E90();
void func_80084048(void *, s32);
extern s32 D_800C7E60;
extern f32 D_800E1A38;
extern f32 D_800E1A3C;
extern f32 D_800E1A40;
extern f32 D_800E1A5C;
extern f32 D_800E1A60;
extern s32 D_800E1A64;
extern s32 D_800E1A68;

void *func_800723C0(s32 *arg0, s32 *arg1, s32 *arg2, void *arg3, s32 arg4) {
    f32 *__base_D_800E1A38;
    f32 sp30[3];
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
    
    f32 var_fs0;
    f32 temp_fv0;
    f32 temp_fv0_2;
    f32 temp_ft0;
    int temp_s0_2;

    s = arg0; d = sp58.w;
    __repair_rows: {
        d[0] = s[0]; d[1] = s[1]; d[2] = s[2]; d[3] = s[3];
        s += 4; d += 4;
    }
if (s != arg0 + 8) goto __repair_rows;
    d[0] = s[0];
    s = arg1; d = sp80.w;
    do {
        d[0] = s[0]; d[1] = s[1]; d[2] = s[2]; d[3] = s[3];
        s += 4; d += 4;
    } while (s != arg1 + 8);
    d[0] = s[0];
    s = arg2; d = spA8.w;
    do {
        d[0] = s[0]; d[1] = s[1]; d[2] = s[2]; d[3] = s[3];
        s += 4; d += 4;
    } while (s != arg2 + 8);
    d[0] = s[0];
    D_800E1A68 += 1;
    temp_v0 = func_80016410(0x24, 0, 0, d);
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
        *(f32 *) ((u8 *) temp_s0 + 0) = temp_ft0 * (sp30[0] - (*__base_D_800E1A38));
        *(f32 *) ((u8 *) temp_s0 + 4) = temp_ft0 * (sp30[1] - D_800E1A3C);
        *(f32 *) ((u8 *) temp_s0 + 8) = temp_ft0 * (sp30[2] - D_800E1A40);
        *(f32 *) ((u8 *) temp_s0 + 0) = *(f32 *) ((u8 *) temp_s0 + 0) + func_80045D8C((int)D_800E1A5C, D_800E1A60);
        *(f32 *) ((u8 *) temp_s0 + 4) = *(f32 *) ((u8 *) temp_s0 + 4) + func_80045D8C(D_800E1A5C, D_800E1A60);
        *(f32 *) ((u8 *) temp_s0 + 8) = *(f32 *) ((u8 *) temp_s0 + 8) + func_80045D8C(D_800E1A5C, D_800E1A60);
        *(s32 *) ((u8 *) temp_s0 + 0xC) = (s32) (var_fs0 * 8.0f);
        if (*(s32 *) ((u8 *) temp_s0 + 0xC) >= 0x10) {
            *(s32 *) ((u8 *) temp_s0 + 0xC) = 0xF;
        }
        func_80045314(sp58.w, sp30, sp58.w);
        func_80045314(sp80.w, sp30, sp80.w);
        func_80045314(spA8.w, sp30, spA8.w);
        temp_v0_2 = func_80083E90(0x4C, 0x16);
        *(void **) ((u8 *) temp_v0 + 0x70) = temp_v0_2;
        if (temp_v0_2 != NULL) {
            s32 *src = (s32 *) arg3;
            s32 *dst = (s32 *) temp_v0_2;
            do {
                dst[0] = src[0]; dst[1] = src[1]; dst[2] = src[2]; dst[3] = src[3];
                src += 4; dst += 4;
            } while (src != (s32 *) arg3 + 16);
            dst[0] = src[0]; dst[1] = src[1]; dst[2] = src[2];
            *(s16 *) ((u8 *) temp_v0_2 + 0x42) = 3;
            *(s32 *) ((u8 *) temp_v0_2 + 0x34) = 0;
            *(s16 *) ((u8 *) temp_v0_2 + 0x40) = 1;
            temp_v0_3 = func_80083E90(0x3C, 0x2D, dst, src);
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
            func_80084048(temp_v0_3, 0x2D);
            return temp_v0;
        }
block_71:
        *(s32 *) ((u8 *) temp_v0 + 0x60) = *(s32 *) ((u8 *) temp_v0 + 0x60) | 1;
        return NULL;
    }
    return temp_v0;
}
