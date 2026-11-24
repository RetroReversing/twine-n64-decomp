/* identical to releaseTextPopupNode in V-RALLY-PAL (local match library) (matched), with its names changed by decompdecomp */
void freeMenuItemRecord(s32 block);
extern s32 gTextPopupNode;

/* Releases the cached heap block and clears the saved handle. */
/* Frees the current text popup node and clears the global pointer. */ void releaseTextPopupNode(void) {
    freeMenuItemRecord(gTextPopupNode);
    gTextPopupNode = 0;
}
