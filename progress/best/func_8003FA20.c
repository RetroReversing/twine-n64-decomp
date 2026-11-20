extern f32 D_80102E6C, D_80102E70, D_80102E74, D_80102E78;
extern f32 D_80102E80, D_80102E84, D_80102E88, D_80102E8C, D_80102EA4;

f32 *func_80082BD0(void) {
    volatile f32 *out = &D_80102E74;
    f32 x0 = D_80102E80 * out[-3];
    f32 x1 = D_80102E84 * D_80102E6C;
    f32 x2 = D_80102E88 * D_80102E70;
    f32 y0 = D_80102E8C * out[-3];
    f32 y1 = out[7] * D_80102E6C;
    f32 y2 = out[8] * D_80102E70;
    f32 x = x0 + x1;
    f32 y = y0 + y1;
    f32 z = out[9] * out[-3];
    x += x2;
    y += y2;
    z += out[10] * D_80102E6C;
    x += D_80102EA4;
    y += out[13];
    z += out[11] * D_80102E70;
    z += out[14];
    *out = x;
    D_80102E78 = y;
    out[2] = z;
    return (f32 *)out;
}



s32 func_80018030(u32 buttons) {
    u32 input = buttons & 0x840;
    s32 result;
    if (input == 0x40)
        goto first;
    result = 1;
    if (input <= 0x40)
        goto done;
    if (input == 0x800)
        goto second;
    if (input == 0x840)
        goto third;
    result = 1;
    goto done;
first:
    result = 0;
    goto done;
second:
    result = 2;
    goto done;
third:
    result = 3;
done:
    return result;
}

u64 osGetTime(void);
extern volatile u64 D_80102CC8;
extern volatile u64 D_80109DD8;
extern volatile u64 D_80115320;

void func_800070A4(void) {
    u64 t;
    D_80109DD8 = 0;
    t = osGetTime();
    D_80115320 = t;
    D_80102CC8 = 0;
}

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

s32 func_80032884();
extern char D_800C0784[];
extern char D_800C0788[];
extern s32 D_80100914;

void func_8003FA20(void) {
    u32 var_v1;

    u32 end = 0x1FC0;
    var_v1 = 0;
    D_80100914 = 0x1FC;
    do {
        *(s32 *)(D_800C0784 + var_v1) = 0;
        *(s32 *)(D_800C0788 + var_v1) = 0;
        var_v1 += 0x10;
    } while (var_v1 < end);
    func_80032884();
}
