f32 approxDistance();
s8 func_8005EF84();
extern const f64 D_800D4190;
extern u8 sTrackDoneFlags[];
extern void *gBonusSceneHandle;

s8 func_8005E4C8(void *arg0) {
    u32 i;
    void **p;
    void *e;
    void *temp_s1;
    u16 temp_v0;

    temp_s1 = *(void **)((s8 *)arg0 + 0x6C);
    temp_v0 = *(u16 *)((s8 *)temp_s1 + 0x24);
    if ((temp_v0 != 0) && (*(sTrackDoneFlags + temp_v0) == 0)) {
        return 0;
    }
    for (i = 0; i < 4; i++) {
        p = (void **) &gBonusSceneHandle + i;
        e = *p;
        if (e == NULL) {
            continue;
        }
        if (*(u16 *)((s8 *)e + 0x78) == 0x4D) {
            continue;
        }
        if (*(u16 *)((s8 *)e + 0x78) == 0x61) {
            continue;
        }
        if (*(s32 *)((s8 *)e + 0x78) == 0x20000) {
            continue;
        }
        if (*(s32 *)((s8 *)e + 0x20) != *(s32 *)((s8 *)arg0 + 0x20)) {
            continue;
        }
        if (approxDistance((u8 *) e + 0x24, (u8 *) arg0 + 0x24) < D_800D4190) {
            if (*(u16 *)((s8 *)temp_s1 + 0x30) == 0) {
                return func_8005EF84(*p, arg0);
            }
            continue;
        }
        if (*(u16 *)((s8 *)temp_s1 + 0x30) != 0) {
            *(u16 *)((s8 *)temp_s1 + 0x30) -= 1;
        }
    }
    return 0;
}
