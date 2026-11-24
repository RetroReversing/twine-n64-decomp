/* Finds the probe record for this object's list and kind, attaches it to the object and copies the origin position. */

s32 clearProbeState(void *, u16);
extern s32 sProbeRecords;
extern s32 sProbeRecordIds;
extern s32 sProbeRecordFlags;
extern void *gDefaultOrderObj;

typedef struct { s32 x, y, z; } PositionWords;

s32 attachProbeRecord(void *object, s32 probeKind, void *originPos) {
    s32 recordNextOffset;
    s32 recordOffset;

    u16 recordWord;
    u32 recordIndex;

    recordIndex = 0;
    recordNextOffset = 0;
    for (;;) {
        recordOffset = recordNextOffset;
        recordWord = *((u16 *)((s8 *)&sProbeRecords + recordOffset));
        if (((recordWord >> 9) != (*(s32 *)((char *)(gDefaultOrderObj) + 4))) || (((recordWord >> 1) & 0xFF) != probeKind)) {
            recordIndex += 1;
            recordNextOffset = recordOffset + 6;
            if (recordIndex >= 0x1BU) {
                return 0;
            }
            continue;
        }
        break;
    }
    if ((*(s32 *)((char *)(object) + 0x60)) & 0x20) {
        if (!(((u16) *((u16 *)((s8 *)&sProbeRecordFlags + recordOffset)) >> 0xD) & 1)) {
            return 0;
        }
        goto attach;
    }
    if (((u16) *((u16 *)((s8 *)&sProbeRecordFlags + recordNextOffset)) >> 0xD) & 1) {
        return 0;
    }
    {
        recordOffset = recordIndex * 2;
attach:
        clearProbeState(object, *((u16 *)((s8 *)&sProbeRecordIds + ((recordIndex * 2 + recordIndex) * 2))));
        *(PositionWords *)((u8 *)object + 0x3C) = *(PositionWords *)originPos;
        return 1;
    }
}
