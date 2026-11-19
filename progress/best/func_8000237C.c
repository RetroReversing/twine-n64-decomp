#define FLD(p, t, o) (*(t *)((u8 *)(p) + (o)))

s16 *func_80001928(s32);
s32 func_80002098(s32 *, s32 *, s32, void *);
s32 func_800060B0(void *, s32, s32);
void *func_8002BC4C(s32);
s32 func_8003FA78(s16);
s32 func_8004478C(s32, s32);
s32 func_80045CF8(s32);
f32 func_80082908(s32, s32);
void *func_80083E90(void *, s32, s32);
s32 func_80084180(void *, s32, s16);
void *memset(void *, s32, s32, s32);
extern f32 D_800AE4D8;
extern s16 *D_800AE4DC[];
extern s16 D_800AE53C[];
extern s16 D_800C3928[];
extern s16 D_800C392A[];
extern s16 D_800C3CF4[];
extern s16 *D_800C3CF8[];
extern s16 *D_800C3CFC[];
extern u8 D_800CA338;
extern s32 D_80109D18;

s32 func_8000237C(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    int sp10;
    s32 sp14;
    unsigned int sp1C;
    unsigned int sp24;
    s32 sp2C;
    s32 temp_s1;
    register s32 temp_s2;
    s32 temp_s3;
    s32 temp_s5;
    s32 temp_s7;
    unsigned int var_s2;
    register s32 var_a1;
    s32 var_s0;
    s32 var_s1;
    s16 temp_s5_2;
    s16 *temp_s1_2;
    void *base;
    void *p;
    void *sub;
    
    f32 fv;

    sp1C = arg1;
    sp2C = 0;
    if (arg0 == NULL) {
        goto done;
    }
    sp24 = D_800C3CF4[arg1 * 6];
    sp24 = D_800C3928[sp24 * 4];
    sub = FLD(arg0, void *, 0x68);
    p = (u8 *)sub + 0x14;
    if (sub == NULL) {
        if (arg2 == 1) {
            var_s2 = (sp24 + sp24 * 4 + 5) * 4;
        } else if (arg2 == 2) {
            var_s2 = (sp24 * 3 + sp24 + 2) * 4;
        } else if (arg2 != 3) {
            var_s2 = (sp24 + 5) * 4;
        } else {
            var_s2 = (sp24 * 3 + sp24 + 2 + sp24 * 4) * 4;
        }
        temp_s3 = ((unsigned)var_s2 + 7) & ~7;
        base = func_80083E90(arg0, temp_s3 + 0xB8 + temp_s3 + var_s2 + (temp_s7 = sp24 * 4) + (temp_s5 = sp24 * 12) + temp_s5, 0x21);
        if (base == NULL) {
            goto done;
        }
        FLD(arg0, void *, 0x68) = base;
        memset(base, arg1, 0, 0xB8);
        sub = FLD(arg0, void *, 0x68);
        p = (u8 *)base + 0xB8;
        FLD(sub, void *, 0x54) = p;
        p = (u8 *)p + temp_s3;
        FLD(sub, void *, 0x58) = p;
        p = (u8 *)p + temp_s3;
        p = (u8 *)p + var_s2;
        FLD(sub, void *, 0x5C) = p;
        FLD(sub, s32, 0x14) = arg2;
        FLD(sub, s16, 0xA6) = var_s2;
        p = (u8 *)p + temp_s7;
        FLD(sub, void *, 0x6C) = p;
        FLD(base, void *, 0) = p;
        p = (u8 *)base + 0x14;
        FLD(base, void *, 4) = (u8 *)p + temp_s5;
    }
    FLD(p, s8, 0x9F) = sp24;
    sp2C = 1;
done:
    D_80109D18 = 0;
    return sp2C;
}
