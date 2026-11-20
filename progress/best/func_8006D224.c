typedef struct { u8 pad[0x7f]; u8 red, green, blue; } ColorFields;
void func_80017E14(ColorFields *object, s16 dr, s16 dg, s16 db) {
    s16 b, g, r;
    u8 red = object->red;
    u8 green = object->green;
    u8 blue = object->blue;
    dr = red + dr;
    dr &= (s32)~dr >> 31;
    r = dr;
    dg = green + dg;
    dg &= (s32)~dg >> 31;
    g = dg;
    db = blue + db;
    db &= (s32)~db >> 31;
    b = db;
    if (dr > 255) r = 255;
    if (dg > 255) g = 255;
    if (db > 255) b = 255;
    object->red = r;
    object->green = g;
    object->blue = b;
}


extern u8 D_800C471C[];
extern s8 D_800C46A0[];
extern u8 D_800C469E[];
s16 func_80063C7C(s32 arg0) {
    s32 index = (s16)arg0;
    s32 scaled = (index * 8 - index) * 4 + index;
    s32 offset = scaled * 8;
    s32 present = D_800C46A0[offset];
    s32 next = *(u16 *)(D_800C469E + offset);
    if (present != 0) {
        s32 nextIndex = (s16)next;
        s32 nextScaled = (nextIndex * 8 - nextIndex) * 4 + nextIndex;
        s32 nextOffset = nextScaled * 8;
        if (D_800C471C[offset] == D_800C471C[nextOffset]) arg0 = next;
    }
    return (s16)arg0;
}
typedef struct { u8 pad[16]; u32 color, halfColor; } Colors6D;
typedef struct { u8 pad[0x414]; Colors6D *colors; } Inner6D;
typedef struct { u8 pad[0x6c]; Inner6D *inner; u32 unk70; f32 intensity; } Outer6D;
void func_8006D224(Outer6D *obj) {
    Colors6D *entry = obj->inner->colors;
    if (entry != 0) {
        Colors6D *colors = entry;
        f32 intensity = 2.55f * obj->intensity;
        u32 value = (u32)intensity;
        u32 red, blue, alpha;
        if (value >= 256U) value = 255U;
        alpha = 0xFF000000U;
        red = (value >> 1) << 16;
        blue = (255U - value) | 64U;
        value = red | alpha;
        alpha = 0x7F800000U;
        red >>= 1;
        value |= blue;
        blue >>= 1;
        colors->color = value;
        colors->halfColor = (blue | alpha) | red;
    }
}
