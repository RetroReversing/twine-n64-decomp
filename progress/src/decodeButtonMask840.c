s32 decodeButtonMask840(u32 buttons) {
    u32 masked = buttons & 0x840;
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
