typedef struct {
    u32 *display;
    u32 base;
    u8 frame;
    u8 frameCount;
    u8 tick;
    u8 delay;
    u16 stride;
} AnimationEntry;
extern u32 D_80107ED0;
extern AnimationEntry *D_80109EA0[];

void func_8003278C(void) {
    volatile u32 framePad;
    u32 i = 0;
    AnimationEntry **entries;
    if (D_80107ED0 != 0) {
        entries = D_80109EA0;
        do {
            AnimationEntry *entry = *entries;
            u8 tick = entry->tick;
            u8 delay = entry->delay;
            entry->tick = ++tick;
            if (delay < tick) {
                u8 frame = entry->frame;
                u8 frameCount = entry->frameCount;
                entry->tick = 0;
                entry->frame = ++frame;
                if (frame == frameCount)
                    entry->frame = 0;
                *entry->display = entry->base + entry->frame * entry->stride;
            }
            i++;
            entries++;
        } while (i < D_80107ED0);
    }
}

typedef struct { u8 pad[0x7f]; u8 red, green, blue; } ColorFields;
void func_80017E14(ColorFields *object, s16 dr, s16 dg, s16 db) {
    s16 b, g, r;
    r = object->red;
    g = object->green;
    b = object->blue;
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

typedef struct LinkA798C { struct LinkA798C *next; } LinkA798C;
LinkA798C *func_800A798C(LinkA798C **head) {
    LinkA798C *first = *head;
    *head = first->next;
    return first;
}

extern f32 sqrtf(f32);
f32 func_80082908(f32 x) {
    f32 result = 0.0f;
    if (!(x <= 0.0f)) result = sqrtf(x);
    return result;
}
