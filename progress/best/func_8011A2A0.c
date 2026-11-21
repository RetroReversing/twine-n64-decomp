typedef struct { u8 pad[12]; u16 total, remaining; u8 unused, flag, player; } BonusData;
typedef struct { u8 pad[0xB4]; BonusData *data; } BonusState;
typedef struct { u8 pad[0x6C]; BonusState *state; } BonusObject;
extern BonusObject *sBonusObjectTable[];
extern u8 gSceneType, D_801002AC;
extern s32 gSaveTotalSlots, D_801002A8, D_8011F3A8;
extern s16 D_8011F15C[];
extern u8 sProbeTimers[][8];
extern s32 timerGetTotalSeconds(void *);
extern void func_8011A7C8(void);

#define ACCUMULATE() do { \
    i = 0; \
    while ((s32)(u16)i < gSaveTotalSlots) { \
        BonusObject *object = sBonusObjectTable[(u16)i]; \
        if (object != 0) { \
            BonusData *data = object->state->data; \
            totals[data->player] += data->total - data->remaining; \
        } \
        i++; \
    } \
} while (0)
#define CHECK_TOTALS() do { \
    s32 *thresholdPtr = &D_801002A8; \
    s32 threshold = *thresholdPtr; \
    i = 0; \
    if (threshold == 0) goto finish; \
    do { \
        if (totals[(u16)i] >= threshold) { \
            D_8011F3A8 = 90; \
            *((u8 *)thresholdPtr + 4) = 1; \
        } \
        i++; \
    } while ((u16)i < 2); \
    goto finish; \
} while (0)
#define COUNT_FLAGS(value) do { \
    s32 slots = gSaveTotalSlots; \
    s32 *countPtr = (s32 *)((u8 *)&gSaveTotalSlots + 4); \
    i = 0; \
    while ((s32)(u16)i < slots) { \
        BonusObject *object = sBonusObjectTable[(u16)i]; \
        if (object != 0 && (object->state->data->flag != 0) == (value)) { \
            count++; \
            saved += (s32)(u16)i < *countPtr; \
        } \
        i++; \
    } \
    if (saved >= *countPtr) { \
        func_8011A7C8(); \
        if (saved >= *countPtr) goto set_flag; \
    } \
    if (count < gSaveTotalSlots - 1) goto finish; \
    goto set_flag; \
} while (0)

s32 func_8011A2A0(void) {
    s16 totals[2];
    s32 maximum = 0;
    s32 count = 0;
    s32 saved = 0;
    s32 i = 0;
    do {
        totals[(u16)i] = 0;
        i++;
    } while ((u16)i < 2);
    switch (gSceneType) {
    case 6:
        if (D_801002A8 == 0) D_801002AC = 0;
        i = 0;
        do {
            u16 index = (u16)i;
            totals[index] = (s16)timerGetTotalSeconds(sProbeTimers[index]) / 10;
            i++;
        } while ((u16)i < 2);
        ACCUMULATE();
        CHECK_TOTALS();
    case 7:
        COUNT_FLAGS(0);
    case 1:
    case 2:
    case 3:
    case 5:
        ACCUMULATE();
        CHECK_TOTALS();
    case 8:
        COUNT_FLAGS(1);
    default:
        i = 0;
        while ((s32)(u16)i < gSaveTotalSlots) {
            BonusObject *object = sBonusObjectTable[(u16)i];
            if (object != 0) {
                BonusData *data = object->state->data;
                s32 difference = data->total - data->remaining;
                if (maximum < difference) maximum = difference;
            }
            i++;
        }
        if (D_801002A8 == 0 || maximum < D_801002A8) goto finish;
    }
set_flag:
    D_8011F3A8 = 90;
    D_801002AC = 1;
finish:
    i = 0;
    do {
        D_8011F15C[(u16)i] = totals[(u16)i];
        i++;
    } while ((u16)i < 2);
    return D_801002AC;
}
