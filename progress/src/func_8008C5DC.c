extern u8 *D_800E41DC;
#define FIELD(p, T, off) (*(T *)((u8 *)(p) + (off)))
void func_8008C5DC(s32 index) {
    u8 *base;
    void *slot;
    base = D_800E41DC;
    slot = (void *)((u32)(index * 0x68) + (u32)base);
    if (FIELD(slot, u8, 0) != 0) {
        FIELD(slot, u16, 0x28) = 0x14U;
        if (FIELD(slot, u8, 1) != 0) {
            FIELD(slot, u8, 1) = 0U;
            return;
        }
        FIELD(slot, s8, 0x5C) = 3;
        FIELD(slot, s32, 0x54) = 0;
        FIELD(slot, s32, 0x50) = 0;
        FIELD(slot, f32, 0x58) = (f32) FIELD(slot, f32, 0x4C);
        FIELD(slot, u16, 0x48) = (u16) FIELD(slot, u16, 0x28);
    }
}
