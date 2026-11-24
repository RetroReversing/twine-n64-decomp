s32 spawnTextNode(void *);
extern s16 gTextPopupValue;
extern s32 gTextPopupNode;

/* Spawns the text popup node once, storing the low byte of value in the node's source data. */ void showTextPopup(s32 value) {
    s16 *valuePtr;
    if (gTextPopupNode == 0) {
        valuePtr = &gTextPopupValue;
        *valuePtr = value & 0xFF;
        gTextPopupNode = spawnTextNode((char *)valuePtr - 0x20);
    }
}
