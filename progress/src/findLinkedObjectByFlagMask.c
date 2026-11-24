extern s32 gSaveTotalSlots;
extern s32 *sBonusObjectTable[];

/* Returns the first linked object (field 0x6C of a table entry) whose flag bits 0x1E000 equal those of flagMask, or NULL. */ s32 *findLinkedObjectByFlagMask(s32 flagMask) {
    u16 i;
    s32 *object;
    s32 *linked;

    flagMask &= 0x1E000;
    for (i = 0; i < gSaveTotalSlots; i++) {
        object = sBonusObjectTable[i];
        if (object != NULL) {
            linked = ((s32 **)object)[0x6C / 4];
            if (linked != NULL && flagMask == (*linked & 0x1E000)) {
                return linked;
            }
        }
    }
    return NULL;
}
