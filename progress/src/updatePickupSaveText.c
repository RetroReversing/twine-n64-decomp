extern const char sFmtEntryName[];
s32 formatTextEntry();
s32 updateActiveMenuState();
s32 lookupDataEntry();
extern char sSaveSlotInfo[];
extern u8 gPickupSavedByte;
extern void *gSaveMenuState;

/* Refreshes the save-menu text line for the last picked-up item: when the menu is active, formats the message for the item's save state (0..5) and writes the state byte back. */
void updatePickupSaveText(void) {
    s32 msgId;
    s32 textPos;
    u32 saveState;
    s32 slotByte;

    updateActiveMenuState();
    if ((*(u8 *)((char *)(gSaveMenuState) + 0x2D)) != 0) {
        textPos = (*(s32 *)((char *)(gSaveMenuState) + 0x18)) + 0x28;
        slotByte = (u8) *(sSaveSlotInfo + (gPickupSavedByte * 0x18));
        saveState = slotByte & 0xFFFF;
        switch (saveState) {
        case 0:
            msgId = 0xA;
block_9:
            formatTextEntry(textPos, sFmtEntryName, lookupDataEntry(msgId));
            break;
        case 1:
            msgId = 9;
            goto block_9;
        case 2:
            msgId = 0x6B;
            goto block_9;
        case 3:
            msgId = 0x6C;
            {
            formatTextEntry(textPos, sFmtEntryName, lookupDataEntry(msgId));break;}
        case 4:
            msgId = 0x296;
            {
            formatTextEntry(textPos, sFmtEntryName, lookupDataEntry(msgId));break;}
        case 5:
            msgId = 0x297;
            {
            formatTextEntry(textPos, sFmtEntryName, lookupDataEntry(msgId));break;}
        }
        *(sSaveSlotInfo + (gPickupSavedByte * 0x18)) = slotByte;
    }
}
