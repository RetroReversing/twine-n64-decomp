/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */
#ifndef M2C_DEFINES
#define M2C_DEFINES
typedef s32 M2C_UNK;
typedef s8 M2C_UNK8;
typedef s16 M2C_UNK16;
typedef s32 M2C_UNK32;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define M2C_CARRY 0
#define M2C_OVERFLOW(a) (0)
#endif

s32 getTextLength();
s32 func_80019B34();
s32 setMenuMarkersPalette();
s32 setTextPopupLowByte();
s32 setTextPopupStyle();
s32 setTextPopupFields();
s32 func_80087100();
s16 strlen();
extern s32 D_800BD64C;
extern s32 D_800BD654;
extern s32 D_800BD65C;
extern s32 sSaveMenuColorHighlight;
extern u8 D_801001A1[];
extern u8 D_801002A0;
extern s32 D_80102EBC;
extern void *D_80109BB0;

/* Positions and colors a menu entry's icon and label widgets from the entry data, picking colors by highlight state and scene type. */ void setupMenuEntryDisplay(void *menuItem, s32 useIdlePalette, s32 isHighlighted) { /* baseline */
    s32 highlighted;
    s32 palette;
    void *iconWidget2;
    void *labelWidget;
    void *widgets;
    void *iconWidget;
    void *widget;

    widgets = M2C_FIELD(menuItem, void **, 0);
    iconWidget = M2C_FIELD(widgets, void **, 0);
    if (iconWidget != NULL) {
        M2C_FIELD(iconWidget, u16 *, 0x20) = (u16) M2C_FIELD(menuItem, u16 *, 4);
        M2C_FIELD(M2C_FIELD(widgets, void **, 0), u16 *, 0x22) = (u16) M2C_FIELD(menuItem, u16 *, 6);
        iconWidget2 = M2C_FIELD(widgets, void **, 0);
        M2C_FIELD(iconWidget2, s32 *, 0x28) = (s32) ((M2C_FIELD(iconWidget2, s32 *, 0x28) & ~0xFC) | ((palette = ((-(s32)((useIdlePalette & 0xFF) == 0) & 7) | 3)) * 4));
        setTextPopupStyle(3);
        setTextPopupLowByte(M2C_FIELD(D_80109BB0, u8 *, 0x30));
        if (isHighlighted & 0xFF) {
            setTextPopupFields((M2C_FIELD(menuItem, u16 *, 4) - 2) & 0xFFFF, (M2C_FIELD(menuItem, u8 *, 7) - 4) & 0xFF, (getTextLength(M2C_FIELD(widgets, void **, 0)) * 0xC) & 0xFC);
            widget = M2C_FIELD(widgets, void **, 0);
            M2C_FIELD(widget, s32 *, 0x10) = (s32) ((sSaveMenuColorHighlight & ~0xFF) | M2C_FIELD(D_80109BB0, u8 *, 0x30));
        } else {
            widget = M2C_FIELD(widgets, void **, 0);
            M2C_FIELD(widget, s32 *, 0x10) = (s32) ((D_800BD64C & ~0xFF) | M2C_FIELD(D_80109BB0, u8 *, 0x30));
        }
        if (M2C_FIELD(widgets, void **, 4) != NULL) {
            M2C_FIELD(M2C_FIELD(widgets, void **, 4), s32 *, 0x18) = func_80087100(func_80019B34(M2C_FIELD(menuItem, u8 *, 8)) & 0xFFFF);
            labelWidget = M2C_FIELD(widgets, void **, 4);
            M2C_FIELD(labelWidget, s16 *, 0x1C) = strlen(M2C_FIELD(labelWidget, s32 *, 0x18));
            M2C_FIELD(M2C_FIELD(widgets, void **, 4), s16 *, 0x20) = (s16) (M2C_FIELD(menuItem, u16 *, 4) + 0x7E);
            M2C_FIELD(M2C_FIELD(widgets, void **, 4), u16 *, 0x22) = (u16) M2C_FIELD(menuItem, u16 *, 6);
            if ((s16) D_801002A0 < 2) goto ordinary;
            if ((s16) D_801002A0 < 4) goto special;
            if ((s16) D_801002A0 != 6) goto ordinary;
            special: {
                highlighted = isHighlighted & 0xFF;
                if (highlighted != 0) {
                    M2C_FIELD(M2C_FIELD(widgets, void **, 4), s32 *, 0x10) = (s32) ((sSaveMenuColorHighlight & ~0xFF) | M2C_FIELD(D_80109BB0, u8 *, 0x30));
                } else {
                    s32 entry = D_801001A1[M2C_FIELD(menuItem, u8 *, 8) * 0x18];
                    widget = M2C_FIELD(widgets, void **, 4);
                    if (entry == 0) {
                        M2C_FIELD(widget, s32 *, 0x10) = (D_800BD65C & ~0xFF) | M2C_FIELD(D_80109BB0, u8 *, 0x30);
                    } else {
                        M2C_FIELD(widget, s32 *, 0x10) = (D_800BD654 & ~0xFF) | M2C_FIELD(D_80109BB0, u8 *, 0x30);
                    }
                }
                goto color_done;
            }
            ordinary:
            if (isHighlighted & 0xFF) {
                M2C_FIELD(M2C_FIELD(widgets, void **, 4), s32 *, 0x10) = (s32) ((sSaveMenuColorHighlight & ~0xFF) | M2C_FIELD(D_80109BB0, u8 *, 0x30));
            } else {
                M2C_FIELD(M2C_FIELD(widgets, void **, 4), s32 *, 0x10) = (s32) ((D_80102EBC & ~0xFF) | M2C_FIELD(D_80109BB0, u8 *, 0x30));
            }
            color_done:;
            widget = M2C_FIELD(widgets, void **, 4);
            M2C_FIELD(widget, s32 *, 0x28) = (s32) ((M2C_FIELD(widget, s32 *, 0x28) & ~0xFC) | (M2C_FIELD(M2C_FIELD(widgets, void **, 0), s32 *, 0x28) & 0xFC));
        }
        setMenuMarkersPalette(3);
    }
}
