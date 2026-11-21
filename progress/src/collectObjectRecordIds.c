s32 func_8000C860();
extern s32 **gObjectRecords;
extern struct CommandRef {
    s16 *id;
    char padding[8];
} D_800C3CF8[];
extern struct CommandDef {
    s16 id;
    char padding[230];
} D_800C4708[];
extern s16 D_800E0740;
extern s16 sObjectIdList[];

/* Walks the object record command stream and collects the object ids it references into sObjectIdList, -1 terminated. */
void collectObjectRecordIds(void) {
    u32 *cmdCursor;
    s16 *out;
    s32 idCount = 0;
    s32 running = 1;

    out = sObjectIdList;
    D_800E0740 = -1;
    cmdCursor = *gObjectRecords;

    do {
        s32 objId = -1;
        s32 cmdWord = *cmdCursor;
        s32 skipWords = 0;
        s32 cmdArgs = cmdWord >> 8;
        s32 cmdOpcode = cmdWord & 0x3f;
        cmdCursor++;
        switch (cmdOpcode) {
        case 35: running = 0; break;
        case 36: break;
        case 0:
            objId = **(u16 **)cmdCursor;
            D_800E0740 = objId;
        case 9: case 10: case 14: case 22: case 23: case 28:
            skipWords = 1; break;
        case 26: skipWords = 2; break;
        case 1: case 2: case 4: case 5: case 6: case 8:
        case 15: case 16: case 20: case 21: case 25:
            skipWords = 3; break;
        case 17: skipWords = 6; break;
        case 33:
            if ((cmdArgs & 255) == 0x69) {
                objId = D_800C4708[func_8000C860((cmdArgs >> 8) & 255)].id;
            }
            break;
        case 18: case 19:
            objId = **(u16 **)cmdCursor;
            skipWords = 7;
            break;
        case 11: case 12: case 13:
            objId = ((u8 *)cmdCursor)[3];
            objId = *D_800C3CF8[objId].id;
            skipWords = 7;
            break;
        case 3: case 7: case 24: skipWords = 12; break;
        }
        if (objId >= 0) {
            sObjectIdList[idCount] = objId;
            idCount++;
        }
        cmdCursor += skipWords;
    } while (running);
    sObjectIdList[idCount] = -1;
}
