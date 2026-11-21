typedef union {
    u32 word;
    u8 bytes[4];
    struct { unsigned :16; unsigned x:4; unsigned y:4; unsigned :8; } bits;
} PackedWord15F74;

typedef union {
    u32 word;
    u16 halves[2];
    u8 bytes[4];
    struct { unsigned :24; unsigned x:4; unsigned y:4; } bits;
} PackedOptions15F74;

typedef struct {
    s32 position[2];
    PackedOptions15F74 style;
    u16 width;
    u8 height;
    u8 padF;
    PackedOptions15F74 options;
    u16 stringId;
    u16 pad16;
    const char *text;
    s32 length;
    s16 index;
} TextArgs15F74;

typedef struct {
    u8 pad0[0x10];
    s32 position[2];
    const char *text;
    u16 length;
    u16 style;
    u16 width;
    u16 height;
    u16 defaultSize;
    u16 size;
    PackedWord15F74 flags;
} TextNode15F74;

TextNode15F74 *func_80015F0C(void);
void func_800165E0(TextNode15F74 *, s32);
void initObjectFromBankEntry(TextNode15F74 *, const char *, s32);
const char *lookupDataEntry(u16);
unsigned int strlen(const char *);
extern s32 gTrackMarkers[];

TextNode15F74 *spawnTextNode(TextArgs15F74 *args)
{
    TextNode15F74 *node = func_80015F0C();
    u32 flags;
    u32 spacing;
    u32 lines;
    s16 index;
    s32 length;

    if (node == 0) {
        return 0;
    }
    if (args == 0) {
        return node;
    }

    node->position[0] = args->position[0];
    node->position[1] = args->position[1];
    node->flags.word = (node->flags.word & ~0xFC) | ((args->style.word >> 29) << 2);
    node->style = args->style.halves[1];
    if (args->stringId != 0) {
        const char *text = lookupDataEntry(args->stringId);
        node->text = text;
        node->length = strlen(text);
    } else {
        length = args->length;
        if (length >= 0) {
            initObjectFromBankEntry(node, args->text, length);
        } else {
            node->text = lookupDataEntry(3);
            node->length = 0;
        }
    }

    node->width = args->width;
    node->height = args->height;
    if (args->options.halves[0] != 0) {
        node->size = args->options.halves[0];
    } else {
        node->size = node->defaultSize;
    }
    if (args->options.bytes[2] != 0) {
        node->flags.bytes[1] = args->options.bytes[2];
    } else {
        node->flags.bytes[1] = node->flags.bytes[0];
    }

    node->flags.bits.x = args->options.bits.x ? args->options.bits.x : 1;
    node->flags.bits.y = args->options.bits.y ? args->options.bits.y : 1;
    index = args->index;
    if (index >= 0) {
        func_800165E0(node, gTrackMarkers[index]);
    }
    return node;
}
