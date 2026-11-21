void *spawnEffectObject();
void objectListInsert();
extern u8 gTimedEffectScaleTable;
extern u8 gTimedEffectRateTable;
typedef struct { s32 w[3]; } __repair_words3;

/* Spawns effect object 0x48 with a 300-frame timer and a kind-indexed scale, and inserts it into the owner's object list. */ void spawnTimedEffect(void *owner, s32 kind, void *srcPos, s32 effectType) {
    void *spark;
    void *effect;
    effect = spawnEffectObject(0x48, kind, 0);
    if (effect != NULL) {
        spark = *(void **)((s8 *)effect + 0x6C);
        *(s32 *)((s8 *)spark + 0x18) = 0;
        *(s32 *)((s8 *)spark + 0x1C) = (((*(s32 *)((s8 *)spark + 0x1C) & 0xFFF0000F) | 0x190) & 0x19F) | 0x0FB00000;
        *(s16 *)((s8 *)effect + 0x78) = effectType;
        *(s16 *)((s8 *)effect + 0x7A) = 0;
        if (srcPos != NULL) *(__repair_words3 *)((s8 *)spark) = *(__repair_words3 *)((s8 *)srcPos);
        *(s32 *)((s8 *)spark + 0xC) = 0x12C;
        *(s16 *)((s8 *)spark + 0x40) = 0x42;
        *(u8 *)((s8 *)spark + 0x45) = 0xFF;
        *(s8 *)((s8 *)spark + 0x44) = 0;
        *(s8 *)((s8 *)spark + 0x42) = 0;
        *(s8 *)((s8 *)spark + 0x43) = 0;
        *(s8 *)((s8 *)spark + 0x46) = 1;
        *(f32 *)((s8 *)spark + 0x38) = (f32) gTimedEffectScaleTable;
        kind = gTimedEffectRateTable;
        *(s32 *)((s8 *)spark + 0x2C) = -1;
        *(f32 *)((s8 *)spark + 0x30) = 1000.0f;
        *(f32 *)((s8 *)spark + 0x34) = 1000.0f;
        *(f32 *)((s8 *)spark + 0x3C) = (f32) kind;
        objectListInsert(effect, *(void **)((s8 *)owner + 0x20));
    }
}
