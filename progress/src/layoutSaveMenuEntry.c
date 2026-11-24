/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

s32 getTextLength();
s32 setMenuMarkersPalette();
s32 setTextPopupLowByte();
s32 setTextPopupStyle();
s32 setTextPopupFields();
extern s32 D_800BD64C;
extern s32 D_800BD650;
extern s32 D_800BD65C;
extern s32 sMenuMarkerColor;
extern s32 sSaveMenuColorHighlight;
extern u8 sSaveSlotTable[];
extern s32 gMenuSoundParams;
extern void *gSaveMenuState;

/* Positions and colors a save-menu entry's label and value widgets, highlighting them when selected. */ void layoutSaveMenuEntry(void *entry, s32 isEnabled, s32 isSelected) {
    s32 flags;
    void *labelWidget;
    void *labelBase;
    void *widgets;
    void *label;
    void *valueWidget;
    void *widget;

    widgets = (*(void **)((char *)(entry) + 0));
    label = (*(void **)((char *)(widgets) + 0));
    if (label != NULL) {
        (*(u16 *)((char *)(label) + 0x20)) = (u16) (*(u16 *)((char *)(entry) + 4));
        (*(u16 *)((char *)((*(void **)((char *)(widgets) + 0))) + 0x22)) = (u16) (*(u16 *)((char *)(entry) + 6));
        labelWidget = (*(void **)((char *)(widgets) + 0));
        (*(s32 *)((char *)((*(void **)((char *)(widgets) + 0))) + 0x10)) = (isSelected & 0xFF) ? (s32) ((sMenuMarkerColor & ~0xFF) | (*(u8 *)((char *)(gSaveMenuState) + 0x30))) : (s32) (gMenuSoundParams);
        labelBase = *(void **)widgets;
        {
            s32 bits = *(s32 *)((char *)labelBase + 0x28) & ~0xFC;
            flags = ((u8)isEnabled == 0 ? 7 : 0) | 3;
            *(s32 *)((char *)labelBase + 0x28) = bits | (flags << 2);
        }
        setTextPopupStyle(3);
        setTextPopupLowByte((*(u8 *)((char *)(gSaveMenuState) + 0x30)));
        if (isSelected & 0xFF) {
            setTextPopupFields(((*(u16 *)((char *)(entry) + 4)) - 2) & 0xFFFF, ((*(u8 *)((char *)(entry) + 7)) - 4) & 0xFF, (getTextLength((*(void **)((char *)(widgets) + 0))) * 0xC) & 0xFC);
            widget = (*(void **)((char *)(widgets) + 0));
            (*(s32 *)((char *)(widget) + 0x10)) = (s32) ((sSaveMenuColorHighlight & ~0xFF) | (*(u8 *)((char *)(gSaveMenuState) + 0x30)));
        } else {
            widget = (*(void **)((char *)(widgets) + 0));
            (*(s32 *)((char *)(widget) + 0x10)) = (s32) ((D_800BD64C & ~0xFF) | (*(u8 *)((char *)(gSaveMenuState) + 0x30)));
        }
        valueWidget = (*(void **)((char *)(widgets) + 4));
        if (valueWidget != NULL) {
            (*(s16 *)((char *)(valueWidget) + 0x20)) = (s16) ((*(u16 *)((char *)(entry) + 4)) + 0x7E);
            (*(u16 *)((char *)((*(void **)((char *)(widgets) + 4))) + 0x22)) = (u16) (*(u16 *)((char *)(entry) + 6));
            if (isSelected & 0xFF) {
                widget = (*(void **)((char *)(widgets) + 4));
                (*(s32 *)((char *)(widget) + 0x10)) = ((sSaveMenuColorHighlight & ~0xFF) | (*(u8 *)((char *)(gSaveMenuState) + 0x30)));
            } else {
                widget = (*(void **)((char *)(widgets) + 4));
                if (*(sSaveSlotTable + ((*(u8 *)((char *)(entry) + 8)) * 0x18)) == 0)
                    (*(s32 *)((char *)(widget) + 0x10)) = ((D_800BD65C & ~0xFF) | (*(u8 *)((char *)(gSaveMenuState) + 0x30)));
                else
                    (*(s32 *)((char *)(widget) + 0x10)) = ((D_800BD650 & ~0xFF) | (*(u8 *)((char *)(gSaveMenuState) + 0x30)));
            }
            widget = (*(void **)((char *)(widgets) + 4));
            (*(s32 *)((char *)(widget) + 0x28)) = (s32) (((*(s32 *)((char *)(widget) + 0x28)) & ~0xFC) | ((*(s32 *)((char *)((*(void **)((char *)(widgets) + 0))) + 0x28)) & 0xFC));
        }
        setMenuMarkersPalette(3);
    }
}
