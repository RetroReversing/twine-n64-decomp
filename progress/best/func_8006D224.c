typedef struct { u8 pad[16]; u32 color, halfColor; } Colors6D;
typedef struct { u8 pad[0x414]; Colors6D *colors; } Inner6D;
typedef struct { u8 pad[0x6c]; Inner6D *inner; u32 unk70; f32 intensity; } Outer6D;
void func_8006D224(Outer6D *obj) {
    Colors6D *colors = obj->inner->colors;
    if (colors != 0) {
        f32 intensity = obj->intensity * 2.55f;
        u32 color = 0xFF000000U, halfColor = 0x7F800000U;
        u32 red, blue;
        u32 value = (u32)intensity;
        if (value < 256U) goto pack;
        value = 255;
    pack:
        red = (value >> 1) << 16;
        blue = (255 - value) | 64;
        color |= red;
        halfColor |= red >> 1;
        color |= blue;
        halfColor |= blue >> 1;
        colors->color = color;
        colors->halfColor = halfColor;
    }
}
