typedef struct {
    s32 value;
    u16 field4;
    u16 field6;
} LookupResult;

extern u16 sSceneGroupSearchKey[];
extern LookupResult *sSceneGroupLookupResult;
extern volatile s32 sLoadedSceneGroupCount;
extern s32 D_800F815C;
extern s32 compareSceneGroupKey(void *, void *);
extern LookupResult *func_800956E0(void *, void *, s32, s32, s32 (*)(void *, void *));

/* Binary-searches the loaded scene groups for groupKey; returns the entry's value and stores its
 * second halfword in outField6, or returns 0 if not found. */
s32 findSceneGroupByKey(u16 groupKey, u16 *outField6) {
    s32 groupCount;
    u16 *record;
    LookupResult *result;
    s32 value;

    groupCount = sLoadedSceneGroupCount;
    sSceneGroupSearchKey[0] = groupKey;
    result = func_800956E0(sSceneGroupSearchKey - 2, &D_800F815C, groupCount, 12, compareSceneGroupKey);
    sSceneGroupLookupResult = result;
    if (result == NULL) {
        value = 0;
    } else {
        *outField6 = result->field6;
        value = sSceneGroupLookupResult->value;
    }
    return value;
}
