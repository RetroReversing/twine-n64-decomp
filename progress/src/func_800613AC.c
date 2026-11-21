void *spawnEffectObject();
void objectListInsert();
extern u8 D_800B2022;
extern u8 D_800B2272;
typedef struct { s32 w[3]; } __repair_words3;

void func_800613AC(void *arg0, s32 arg1, void *arg2, s32 arg3) {
    void *temp_a2;
    void *temp_v0;
    temp_v0 = spawnEffectObject(0x48, arg1, 0);
    if (temp_v0 != NULL) {
        temp_a2 = *(void **)((s8 *)temp_v0 + 0x6C);
        *(s32 *)((s8 *)temp_a2 + 0x18) = 0;
        *(s32 *)((s8 *)temp_a2 + 0x1C) = (((*(s32 *)((s8 *)temp_a2 + 0x1C) & 0xFFF0000F) | 0x190) & 0x19F) | 0x0FB00000;
        *(s16 *)((s8 *)temp_v0 + 0x78) = arg3;
        *(s16 *)((s8 *)temp_v0 + 0x7A) = 0;
        if (arg2 != NULL) *(__repair_words3 *)((s8 *)temp_a2) = *(__repair_words3 *)((s8 *)arg2);
        *(s32 *)((s8 *)temp_a2 + 0xC) = 0x12C;
        *(s16 *)((s8 *)temp_a2 + 0x40) = 0x42;
        *(u8 *)((s8 *)temp_a2 + 0x45) = 0xFF;
        *(s8 *)((s8 *)temp_a2 + 0x44) = 0;
        *(s8 *)((s8 *)temp_a2 + 0x42) = 0;
        *(s8 *)((s8 *)temp_a2 + 0x43) = 0;
        *(s8 *)((s8 *)temp_a2 + 0x46) = 1;
        *(f32 *)((s8 *)temp_a2 + 0x38) = (f32) D_800B2022;
        arg1 = D_800B2272;
        *(s32 *)((s8 *)temp_a2 + 0x2C) = -1;
        *(f32 *)((s8 *)temp_a2 + 0x30) = 1000.0f;
        *(f32 *)((s8 *)temp_a2 + 0x34) = 1000.0f;
        *(f32 *)((s8 *)temp_a2 + 0x3C) = (f32) arg1;
        objectListInsert(temp_v0, *(void **)((s8 *)arg0 + 0x20));
    }
}
