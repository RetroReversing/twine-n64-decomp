typedef union {
    u32 word;
    u8 bytes[4];
    struct { unsigned :16; unsigned x:4; unsigned y:4; unsigned :8; } bits;
} State;
typedef struct {
    u8 pad[16];
    u32 x,y;
    char *text;
    u16 len, style, size, mode, defaultWidth, width;
    State state;
} Text;
typedef struct {
    u32 x,y;
    union {u32 word; u16 halves[2];} style;
    u16 size;
    u8 mode, pad;
    union {u32 word; u16 halves[2]; u8 bytes[4];
        struct {unsigned :24; unsigned x:4; unsigned y:4;} bits;
    } settings;
    u16 id;
    s32 index,bank;
} Template;
extern char *lookupDataEntry(s32);
extern void initObjectFromBankEntry(Text *, s32, s32);
extern unsigned int strlen(const char *);
/* Fills a Text object from a Template: position, style, string (by id, or by index/bank, or empty), size, mode, width and colour state. */
void initTextFromTemplate(Text *dst, Template *src) {
    if (dst != NULL) if (src != NULL) {
        dst->x = src->x;
        dst->y = src->y;
        dst->state.word = (dst->state.word & ~0xfc) | ((src->style.word >> 29) << 2);
        dst->style = src->style.halves[1];
        if (src->id) {
            dst->len = strlen(dst->text = lookupDataEntry(src->id));
        } else if (src->bank >= 0) {
            initObjectFromBankEntry(dst, src->index, src->bank);
        } else {
            dst->text = lookupDataEntry(3);
            dst->len = 0;
        }
        dst->size = src->size;
        dst->mode = src->mode;
        if (src->settings.halves[0])
            dst->width = src->settings.halves[0];
        else
            dst->width = dst->defaultWidth;
        if (src->settings.bytes[2])
            dst->state.bytes[1] = src->settings.bytes[2];
        else
            dst->state.bytes[1] = dst->state.bytes[0];
        dst->state.bits.x = src->settings.bits.x ? src->settings.bits.x : 1;
        dst->state.bits.y = src->settings.bits.y ? src->settings.bits.y : 1;
    }
}
