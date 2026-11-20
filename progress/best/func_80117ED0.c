extern u8 D_8010019C[];
extern u8 D_800BF688[];
extern u8 D_8011EE68[];
extern u8 D_8011EE70[];
f32 func_800461D4(void *, f32 *);
u16 func_80022DBC(u8 *);
void func_80002BD0(void *, s32);
f32 func_80082A70(f32, f32);
f32 func_800829A0(f32);
f32 func_800829C8(f32);
void func_800828D0(f32);
void func_8007AABC(void *, s32, f32);

void func_80117ED0(u8 *arg0, f32 *arg1, f32 *arg2) {
    register f32 __repair_fzero = 0.0f;

    u8 *s1;
    f32 fv, fs0, fs1, fs2, t, dx, dz;
    s32 s2, sel, k;
    u16 x, t16;
    s1 = *(u8 **)(arg0 + 0x6C);
    fv = func_800461D4(arg0 + 0x24, arg1);
    if (fv < arg2[0]) {
        arg2[0] = fv;
    }
    x = func_80022DBC(arg0) & 0xFFFF;
    k = *(u32 *)(D_8010019C + x * 24);
    t16 = *(u16 *)(D_800BF688 + k * 12);
    sel = (t16 >> 2) & 7;
    switch (sel) {
    case 1:
    default: *(f32 *)(s1 + 0x80) = 0.074f; s2 = 0x15F; break;
    case 2: *(f32 *)(s1 + 0x80) = 0.149f; s2 = 0x165; break;
    case 3: *(f32 *)(s1 + 0x80) = 0.16000001f; s2 = 0x171; break;
    case 4: *(f32 *)(s1 + 0x80) = 0.2f; s2 = 0x171; break;
    case 5: *(f32 *)(s1 + 0x80) = 0.23f; s2 = 0x171; break;
    }
    fs2 = *(f32 *)(s1 + 0x80);
    t = arg2[0] - fs2;
    arg2[0] = t;
    if (t < fs2 || *(s16 *)(arg0 + 0x7A) == 7) {
        arg2[0] = __repair_fzero;
        func_80002BD0(arg0, 0x14D);
        dx = arg1[0] - *(f32 *)(arg0 + 0x24);
        dz = arg1[2] - *(f32 *)(arg0 + 0x2C);
        if (dx == 0.0f && dz == 0.0f) {
            fv = *(f32 *)(arg0 + 0x40);
        } else {
            fv = func_80082A70(dx, dz) * 651.8986f;
        }
        func_8007AABC(arg0, (s32)fv, 0.2f);
        return;
    }
    dz = arg1[2] - *(f32 *)(arg0 + 0x2C);
    dx = arg1[0] - *(f32 *)(arg0 + 0x24);
    if (dx == 0.0f && dz == 0.0f) {
        fv = *(f32 *)(arg0 + 0x40);
    
    func_8007AABC(arg0, fv, 0.2f);} else {
        fv = func_80082A70(dx, dz) * 651.8986f;
    
    func_8007AABC(arg0, fv, 0.2f);}
    if (arg2[0] != 0.0f) {
        fv = *(f32 *)(s1 + 0x80);
        t = fs2 - fv;
        *(f32 *)(s1 + 0x80) = fv + t * 0.1f;
    }
    fs0 = *(f32 *)(s1 + 0x80);
    fs1 = *(f32 *)(arg0 + 0x40);
    if (*(s16 *)(arg0 + 0x7A) == 9) {
        fs0 = (f32)(*(f64 *)D_8011EE68 * (f64)fs0);
        fs1 = fs1 + 1024.0f;
        s2 = 0x1A2;
    } else if (*(s16 *)(arg0 + 0x7A) == 10) {
        fs0 = (f32)(*(f64 *)D_8011EE70 * (f64)fs0);
        fs1 = fs1 - 1024.0f;
        s2 = 0x1A8;
    }
    func_80002BD0(arg0, s2);
    fv = fs0 * func_800829A0(fs1);
    *(f32 *)(arg0 + 0x24) = *(f32 *)(arg0 + 0x24) + fv;
    fv = fs0 * func_800829C8(fs1);
    *(f32 *)(arg0 + 0x2C) = *(f32 *)(arg0 + 0x2C) + fv;
    *(f32 *)(*(u8 **)(arg0 + 0x68) + 0x34) = fs0;
    func_800828D0(fs2);
}
