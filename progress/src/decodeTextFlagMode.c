/* Maps flag bits 0x40/0x800 to a mode: 0x40 only -> 0, 0x800 only -> 2, both -> 3, neither -> 1. */ s32 decodeTextFlagMode(u32 flags) {
    u32 masked = flags & 0x840;
    if (masked == 0x40) goto left;
    if (masked < 0x41) goto plain;
    if (masked == 0x800) goto high;
    if (masked == 0x840) goto both;
plain:
    return 1;
left:
    return 0;
high:
    return 2;
both:
    return 3;
}
