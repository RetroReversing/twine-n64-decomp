void romDmaRead(s32, s32, u32);
extern char D_1D69634[];
extern f64 D_800D2160;

f32 func_8000A4F4(s32 index)
{
    s32 buffer[3];
    s32 offset;
    s32 value;
    f64 converted;

    romDmaRead((s32)buffer, (s32)(D_1D69634 + index * 4), 4);
    offset = buffer[0];
    offset &= 0xFFFFFF;
    romDmaRead((s32)buffer, (s32)(D_1D69634 + offset), 2);
    value = *(u16 *)buffer;
    converted = (f64)value;
    if (value < 0)
        converted += D_800D2160;
    return (f32)converted * 0.013333334f;
}
