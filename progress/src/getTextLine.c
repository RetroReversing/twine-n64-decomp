typedef struct {
    s8 *text;
    s16 length;
} TextLine30818;

typedef struct {
    u8 pad[8];
    u16 *pages[3];
} TextPageSet;

void text_get_line_span(TextLine30818 *out, s8 *start, u16 line);
u16 func_8003137C(s16, s32);
s8 *lookupDataEntry(u16);
s32 strlen(s8 *);
extern TextPageSet *gTextRefTable;
extern TextLine30818 sTextLineResult;

/* Returns a text line in sTextLineResult: kind 0 looks up a string by id, kinds 1-3 select a line span from one of the reference table's pages. */
TextLine30818 *getTextLine(u16 kind, s32 line)
{
    TextLine30818 *out = &sTextLineResult;
    u16 *page;
    u16 lineIndex;

    out->text = lookupDataEntry(3);
    sTextLineResult.length = 0;
    if (gTextRefTable != NULL) {
        lineIndex = line - 1;
        switch ((u16)kind) {
        case 0:
            sTextLineResult.text = lookupDataEntry(func_8003137C((s16)line, 1));
            sTextLineResult.length = strlen(sTextLineResult.text);
            break;
        case 1:
            page = gTextRefTable->pages[0];
            if (page != NULL) {
                text_get_line_span(out, lookupDataEntry(*page), lineIndex);
            }
            break;
        case 2:
            page = gTextRefTable->pages[1];
            if (page != NULL) {
                text_get_line_span(out, lookupDataEntry(*page), lineIndex);
            }
            break;
        case 3:
            page = gTextRefTable->pages[2];
            if (page != NULL) {
                text_get_line_span(out, lookupDataEntry(*page), lineIndex);
            }
            break;
        }
    }
    return &sTextLineResult;
}
