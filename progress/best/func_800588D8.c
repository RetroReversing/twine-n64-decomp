extern void *spawnEffectObject(s32, s32, s32);
void *func_800588D8(void *arg0) {
    void *obj = spawnEffectObject(4, 0, 0);
    if (obj) {
        void **slot = *(void ***)((u8 *)obj + 0x6C);
        *(s16 *)((u8 *)obj + 0x78) = 0x23;
        *slot = arg0;
        {
            u32 *flags = (u32 *)((u8 *)arg0 + 0x58);
            u32 old = *flags;
            u32 updated = ~0x1c0U;
            updated &= old;
            *flags = updated;
        }
    }
    return obj;
}
