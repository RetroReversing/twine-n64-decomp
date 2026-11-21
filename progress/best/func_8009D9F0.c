void func_8009F1D4(void *, s32, s32);

#define FX(v, off, k, add) ((s16)(((s32)(((u32)(((v) - (off)) << 10) * (k)) + (add)) >> 15) * 2))
#define FM(v, off, k, add) ((s16)(((s32)((u32)((u64)(u32)(((v) - (off)) << 10) * (k)) + (add)) >> 15) * 2))

void func_8009D9F0(u8 *arg0, s16 *arg1, s32 arg2, s32 arg3) {
    volatile s32 pad[2];
    s16 *out = (s16 *)(arg0 + *(s16 *)(arg0 + 0x188) * 16 + 0x168);

    out[0] = FM(arg1[0], 0x20, 0x3333, 0x4000);
    out[1] = FM(arg1[1], 0x20, 0x3333, 0x4000);
    out[2] = FM(arg1[2], 0x10, 0x3333, 0xFCCD1000);
    out[3] = FM(arg1[3], 0x10, 0x3333, 0x04003C00);
    out[4] = FM(arg1[4], 8, 0x4B17, 0xFFC91B1C);
    out[5] = FX(arg1[5], 8, 0x4444, 0x03BBF800);
    out[6] = FX(arg1[6], 4, 0x7ADE, 0x0147936C);
    out[7] = FX(arg1[7], 4, 0x740C, 0x040D6B40);
    func_8009F1D4(arg0, arg2, arg3);
    *(s16 *)(arg0 + 0x188) ^= 1;
}
