typedef struct {
    s32 value;
    u16 field4;
    u16 field6;
} LookupResult;

extern u16 D_800F38D4[];
extern LookupResult *D_800F38DC;
extern volatile s32 D_800F8158;
extern s32 D_800F815C;
extern s32 func_800986EC(void *, void *);
extern LookupResult *func_800956E0(void *, void *, s32, s32, s32 (*)(void *, void *));

s32 func_8009852C(u16 key, u16 *out) {
    s32 count;
    u16 *record;
    LookupResult *result;
    s32 value;

    count = D_800F8158;
    record = D_800F38D4;
    *(volatile u16 *)record = key;
    result = func_800956E0(record - 2, &D_800F815C, count, 12, func_800986EC);
    D_800F38DC = result;
    if (result == NULL) {
        value = 0;
    } else {
        *out = result->field6;
        value = D_800F38DC->value;
    }
    return value;
}
