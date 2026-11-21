typedef union {
    u32 word;
    u8 bytes[4];
} PackedWord15F74;

typedef union {
    u32 word;
    u16 halves[2];
    u8 bytes[4];
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
void func_800448A4(TextNode15F74 *, const char *, s32);
const char *lookupDataEntry(u16);
unsigned int strlen(const char *);
extern s32 gTrackMarkerTable[];

TextNode15F74 *func_80015F74(TextArgs15F74 *args)
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
            func_800448A4(node, args->text, length);
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

    spacing = args->options.word;
    if ((spacing & 0xF0) == 0) {
        spacing = 16;
    }
    spacing = (spacing >> 4) & 0xF;
    flags = (node->flags.word & 0xFFFF0FFF) | ((spacing & 0xF) << 12);
    node->flags.word = flags;
    lines = 1;
    if ((args->options.word & 0xF) != 0) {
        lines = args->options.word & 0xF;
    }
    node->flags.word = (flags & ~0xF00) | (lines << 8);
    index = args->index;
    if (index >= 0) {
        func_800165E0(node, gTrackMarkerTable[index]);
    }
    return node;
}
