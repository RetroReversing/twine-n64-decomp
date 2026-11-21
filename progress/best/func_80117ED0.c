extern u8 gSaveSlotInfo[];
extern u8 D_800BF688[];
extern u8 D_8011EE68[];
extern u8 D_8011EE70[];
f32 func_800461D4(void *, f32 *);
s32 func_80022DBC(s32);
s32 func_80002BD0(void *, s32);
f32 approximateAtan2(f32, f32);
f32 sinAngle(f32);
f32 cosAngle(f32);
f32 absFloat(f32);
void func_8007AABC(void *, s32, f32);

f32 func_80117ED0(u8 *arg0, f32 *arg1, f32 *arg2) {
    u8 *s1;
    f32 speed, fs0, fs1, fs2, t, dx, dz, initial_dist;
    s32 s2, sel, k, yaw;
    u16 x, t16;
    s1 = *(u8 **)(arg0 + 0x6C);
    initial_dist = func_800461D4(arg0 + 0x24, arg1);
    if (initial_dist < arg2[0]) {
        arg2[0] = initial_dist;
    }
    x = func_80022DBC((u16)(s8)s1[0x182]) & 0xFFFF;
    k = *(u32 *)(gSaveSlotInfo + x * 24);
    t16 = *(u16 *)(D_800BF688 + k * 12);
    sel = (t16 >> 2) & 7;
    switch (sel) {
    case 1:
    default: speed = 0.074f; s2 = 0x15F; break;
    case 2: speed = 0.149f; s2 = 0x165; break;
    case 3: speed = 0.16000001f; s2 = 0x171; break;
    case 4: speed = 0.2f; s2 = 0x171; break;
    case 5: speed = 0.23f; s2 = 0x171; break;
    }
    *(f32 *)(s1 + 0x80) = speed;
    fs2 = *(volatile f32 *)(s1 + 0x80);
    t = arg2[0] - fs2;
    arg2[0] = t;
    if (t < fs2 || *(s16 *)(arg0 + 0x7A) == 7) {
        arg2[0] = 0.0f;
        func_80002BD0(arg0, 0x14D);
        dx = arg1[0] - *(f32 *)(arg0 + 0x24);
        dz = arg1[2] - *(f32 *)(arg0 + 0x2C);
        if ((dx == 0.0f) & (dz == 0.0f)) {
            yaw = (s32)*(f32 *)(arg0 + 0x40);
        } else {
            yaw = (s32)(approximateAtan2(dx, dz) * 651.8986f);
        }
        func_8007AABC(arg0, yaw, (f32)0.2);
        return 0.0f;
    }
    dz = arg1[2] - *(f32 *)(arg0 + 0x2C);
    dx = arg1[0] - *(f32 *)(arg0 + 0x24);
    if ((dx == 0.0f) & (dz == 0.0f)) {
        yaw = (s32)*(f32 *)(arg0 + 0x40);
    } else {
        yaw = (s32)(approximateAtan2(dx, dz) * 651.8986f);
    }
    func_8007AABC(arg0, yaw, 0.2f);
    if (arg2[0] != 0.0f) {
        f32 speedNow = *(f32 *)(s1 + 0x80);
        *(f32 *)(s1 + 0x80) = speedNow + (fs2 - speedNow) * 0.1f;
    }
    fs0 = *(f32 *)(s1 + 0x80);
    fs1 = *(f32 *)(arg0 + 0x40);
    if (*(s16 *)(arg0 + 0x7A) == 9) {
        fs0 = (f32)((f64)fs0 * *(f64 *)D_8011EE68);
        fs1 = fs1 + 1024.0f;
        func_80002BD0(arg0, 0x1A2);
    } else if (*(s16 *)(arg0 + 0x7A) == 10) {
        fs0 = (f32)((f64)fs0 * *(f64 *)D_8011EE70);
        fs1 = fs1 - 1024.0f;
        func_80002BD0(arg0, 0x1A8);
    } else {
        func_80002BD0(arg0, s2);
    }
    *(f32 *)(arg0 + 0x24) += fs0 * sinAngle(fs1);
    *(f32 *)(arg0 + 0x2C) += fs0 * cosAngle(fs1);
    *(f32 *)(*(u8 **)(arg0 + 0x68) + 0x34) = fs0;
    return absFloat(fs2);
}
