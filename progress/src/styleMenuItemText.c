#define FIELD(p,T,o) (*(T *)((u8 *)(p) + (o)))
extern s32 getTextLength(void *);
extern void setMenuMarkersPalette(s32,s32);
extern void setTextPopupLowByte(s32);
extern void setTextPopupStyle(s32);
extern void setTextPopupFields(s32,s32,s32);
extern s32 sMenuMarkerColor, sSaveMenuColorHighlight, gMenuSoundParams;
extern u16 sBonusSlotValueA[], sBonusSlotValueB[], gMenuMode;
extern u8 gMenuSlot;
extern void *gSaveMenuState;
#define ALPHA FIELD(gSaveMenuState,u8,0x30)
/* Applies position, color and alpha to a menu item's text object, dimming it or highlighting it depending on selection state. */ void styleMenuItemText(void *menuItem, s32 dimmed, s32 highlighted)
{
    void *textObj = FIELD(menuItem,void *,0);
    s32 colorMask;
    s32 flags;
    s32 textWidth;
    s32 selectedValue;
    if (textObj) {
        flags = FIELD(textObj,s32,0x28);
        flags &= ~0xFC;
        FIELD(textObj,u16,0x20) = FIELD(menuItem,u16,4);
        textWidth = FIELD(menuItem,u16,6);
        { u32 enabled = (u8)dimmed == 0;
          u32 fill = 0u - enabled;
          flags |= fill & 0x1C; }
        FIELD(textObj,s16,0x1E) = 0x40;
        FIELD(textObj,s32,0x28) = flags;
        FIELD(textObj,u16,0x22) = textWidth;
        setMenuMarkersPalette(0,textWidth);
        colorMask = ~0xFF;
        FIELD(textObj,s32,0x10) = (gMenuSoundParams & colorMask) | ALPHA;
        setTextPopupStyle(0);
        setTextPopupLowByte(ALPHA);
        switch (gMenuMode) {
        case 0:
            if (highlighted & 0xFF) {
                textWidth = (getTextLength(textObj) * 12) & 0xFC;
                setTextPopupFields((FIELD(menuItem,u16,4)-2)&0xFFFF, (FIELD(menuItem,u8,7)-4)&0xFF, textWidth);
                FIELD(textObj,s32,0x10) = (sSaveMenuColorHighlight & colorMask) | ALPHA;
                break;
            }
            selectedValue = sBonusSlotValueA[gMenuSlot];
            goto check_selection;
        case 1:
            if (highlighted & 0xFF) {
                textWidth = (getTextLength(textObj) * 12) & 0xFC;
                setTextPopupFields((FIELD(menuItem,u16,4)-2)&0xFFFF, (FIELD(menuItem,u8,7)-4)&0xFF, textWidth);
                FIELD(textObj,s32,0x10) = (sSaveMenuColorHighlight & colorMask) | ALPHA;
                break;
            }
            selectedValue = sBonusSlotValueB[gMenuSlot];
check_selection:
            if (selectedValue == FIELD(menuItem,u8,8))
                FIELD(textObj,s32,0x10) = (sMenuMarkerColor & colorMask) | ALPHA;
            break;
        }
        FIELD(textObj,s32,0x10) = (FIELD(textObj,s32,0x10) & ~0xFF) | ALPHA;
    }
}
