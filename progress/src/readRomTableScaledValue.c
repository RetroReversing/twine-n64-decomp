void romDmaRead(s32, s32, u32);
extern char D_1D69634[];
extern f64 D_800D2160;

/* Looks up entryIndex in a ROM offset table (24-bit offsets), reads the u16 stored there and returns it scaled by 1/75. */ f32 readRomTableScaledValue(s32 entryIndex)
{
    s32 dmaBuf[3];
    s32 entryOffset;
    s32 rawValue;
    f64 asDouble;

    romDmaRead((s32)dmaBuf, (s32)(D_1D69634 + entryIndex * 4), 4);
    entryOffset = dmaBuf[0];
    entryOffset &= 0xFFFFFF;
    romDmaRead((s32)dmaBuf, (s32)(D_1D69634 + entryOffset), 2);
    rawValue = *(u16 *)dmaBuf;
    asDouble = (f64)rawValue;
    if (rawValue < 0)
        asDouble += D_800D2160;
    return (f32)asDouble * 0.013333334f;
}
