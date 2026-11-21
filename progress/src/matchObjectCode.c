extern s16 *D_800AE724[];
extern s16 D_800C2B28;
extern s16 D_800C2B32;
extern s8 D_800D1E58[];

/* Checks whether an object id and code pair is accepted by the code tables, writing an output value for special ids. */ s32 matchObjectCode(s16 objId, s8 objCode, s32 *outValue) {
    s32 idSeen = 0;
        s32 tableIdx = 0;
    s32 codeIdx = 0;

    while (D_800AE724[tableIdx] != 0) {
        s16 tableId = *D_800AE724[tableIdx];
        if (objId == tableId) idSeen = 1;
        while (D_800D1E58[codeIdx] >= 0) {
            if (objId == tableId && objCode == D_800D1E58[codeIdx]) {
                if (objId == D_800C2B32) {
                    if (objCode == 2) *outValue = 0;
                    if (objCode == 0x1E) *outValue = 1;
                }
                if (objId != D_800C2B28) return 1;
                if (objCode == 2) *outValue = 0;
                if (objCode != 0x16) return 1;
                *outValue = 1;
                goto accepted;
            }
            codeIdx++;
        }
        codeIdx++;
        tableIdx++;
    }
    if (!idSeen) {
        if (objCode < 0x25) {
            if (objCode == 2) *outValue = 0;
            if (objCode == 0x14) {
                *outValue = 1;
                goto accepted;
            }
            return 1;
        }
        goto rejected;
    }
    return 0;
accepted:
    return 1;
rejected:
    return 0;
}

