extern void *spawnEffectObject(s32, s32, s32);
/* Spawns an effect object that references target, and clears bits 0x1C0 in target's flags. */ void *spawnTargetMarkerEffect(void *target) {
    void *effect = spawnEffectObject(4, 0, 0);
    if (effect) {
        void **targetSlot = *(void ***)((u8 *)effect + 0x6C);
        *(s16 *)((u8 *)effect + 0x78) = 0x23;
        *targetSlot = target;
        {
            u32 *targetFlags = (u32 *)((u8 *)target + 0x58);
            u32 oldFlags = *targetFlags;
            u32 newFlags = (oldFlags & ~0x1c0U) | ~0x1c0U;
            newFlags &= oldFlags;
            *targetFlags = newFlags;
        }
    }
    return effect;
}
