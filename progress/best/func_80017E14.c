typedef struct {
    u8 pad[0x7F];
    u8 red, green, blue;
} ColorFields;
void func_80017E14(ColorFields *object, s16 dr, s16 dg, s16 db) {
    s16 r = object->red;
    s16 g = object->green;
    s16 b = object->blue;
    dr += r;
    dr &= (s32)~dr >> 31;
    r = dr;
    dg += g;
    dg &= (s32)~dg >> 31;
    g = dg;
    db += b;
    db &= (s32)~db >> 31;
    b = db;
    if (dr > 255) r = 255;
    if (dg > 255) g = 255;
    if (db > 255) b = 255;
    object->red = r;
    object->green = g;
    object->blue = b;
}
