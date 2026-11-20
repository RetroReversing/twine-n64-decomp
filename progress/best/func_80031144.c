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
s8 *func_80087100(u16);
s32 strlen(s8 *);
extern TextPageSet *D_800BFF08;
extern TextLine30818 D_800E1600;

TextLine30818 *func_80031144(s32 kind, s32 line)
{
    TextLine30818 *out = &D_800E1600;
    u16 *page;
    s32 lineIndex;

    out->text = func_80087100(3);
    D_800E1600.length = 0;
    if (D_800BFF08 != NULL) {
        lineIndex = line - 1;
        switch ((u16)kind) {
        case 0:
            D_800E1600.text = func_80087100(func_8003137C((s16)line, 1));
            D_800E1600.length = strlen(D_800E1600.text);
            break;
        case 1:
            page = D_800BFF08->pages[0];
            if (page != NULL) {
                text_get_line_span(out, func_80087100(*page), (u16)lineIndex);
            }
            break;
        case 2:
            page = D_800BFF08->pages[1];
            if (page != NULL) {
                text_get_line_span(out, func_80087100(*page), (u16)lineIndex);
            }
            break;
        case 3:
            page = D_800BFF08->pages[2];
            if (page != NULL) {
                text_get_line_span(out, func_80087100(*page), (u16)lineIndex);
            }
            break;
        }
    }
    return &D_800E1600;
}
