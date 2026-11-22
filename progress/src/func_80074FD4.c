typedef union { u32 word; u8 bytes[4]; } TextColor;
typedef struct { u8 pad[16]; TextColor color; u32 other; char *volatile string; s16 length; } Text;
typedef struct { u32 pad; Text *text; } Widget;
typedef struct { u8 pad[0x6c]; Widget *widget; u8 rest[0xa]; s16 phase; } Panel;
extern char *lookupDataEntry(s32);
extern u32 strlen(const char *);

void func_80074FD4(Panel *arg0) {
    u32 carrier = (u32)arg0;
    Text *text = ((Panel *)carrier)->widget->text;
    s32 intensity = text->color.bytes[3];
    s16 next = intensity;
    s32 adjusted;
    s32 id;
    char *first;
    switch (((Panel *)carrier)->phase) {
    case 0:
        adjusted = intensity + 8;
        next = adjusted;
        if (adjusted >= 256) {
            ((Panel *)carrier)->phase = 1;
            next = 255;
        }
        break;
    case 1:
        adjusted = intensity - 8;
        next = adjusted;
        if (adjusted < 0) {
            ((Panel *)carrier)->phase = 0;
            first = lookupDataEntry(0xf8);
            next = 0;
            id = 0xf8;
            if (text->string == first)
                id = 0x2ab;
            text->string = lookupDataEntry(id);
            text->length = strlen(text->string);
        }
        break;
    }
    {
        u32 shade = (s32)next;
        u32 high, low, __repair_or_part; do { do { do { high = shade << 16; } while (0); } while (0); } while (0); do { do { do { low = shade << 8; } while (0); } while (0); } while (0); do { __repair_or_part = low | 0xff000000; do { high |= __repair_or_part; } while (0); text->color.word = high | shade; } while (0);
    }
}
