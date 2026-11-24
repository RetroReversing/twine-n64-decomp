typedef union { u32 word; u8 bytes[4]; } TextColor;
typedef struct { u8 pad[16]; TextColor color; u32 other; char *volatile string; s16 length; } Text;
typedef struct { u32 pad; Text *text; } Widget;
typedef struct { u8 pad[0x6c]; Widget *widget; u8 rest[0xa]; s16 phase; } Panel;
extern char *lookupDataEntry(s32);
extern u32 strlen(const char *);

/* Pulses the text alpha up and down by 8 per call; at each bottom it swaps the text between two data-entry strings. */
void pulseTextFade(Panel *panel) {
    u32 panelAddr = (u32)panel;
    Text *text = ((Panel *)panelAddr)->widget->text;
    s32 alpha = text->color.bytes[3];
    s16 newAlpha = alpha;
    s32 stepped;
    s32 entryId;
    char *firstString;
    switch (((Panel *)panelAddr)->phase) {
    case 0:
        stepped = alpha + 8;
        newAlpha = stepped;
        if (stepped >= 256) {
            ((Panel *)panelAddr)->phase = 1;
            newAlpha = 255;
        }
        break;
    case 1:
        stepped = alpha - 8;
        newAlpha = stepped;
        if (stepped < 0) {
            ((Panel *)panelAddr)->phase = 0;
            firstString = lookupDataEntry(0xf8);
            newAlpha = 0;
            entryId = 0xf8;
            if (text->string == firstString)
                entryId = 0x2ab;
            text->string = lookupDataEntry(entryId);
            text->length = strlen(text->string);
        }
        break;
    }
    {
        u32 shade = (s32)newAlpha;
        u32 high, low, __repair_or_part; do { do { do { high = shade << 16; } while (0); } while (0); } while (0); do { do { do { low = shade << 8; } while (0); } while (0); } while (0); do { __repair_or_part = low | 0xff000000; do { high |= __repair_or_part; } while (0); text->color.word = high | shade; } while (0);
    }
}
