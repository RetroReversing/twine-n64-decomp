/* Translates the input flag word stored at offset 0x3C into a different bit layout and returns it. */ s32 remapInputFlags(void *input) {
    s32 srcFlags;
    s32 srcFlagsCopy;
    s32 outFlags;

    srcFlags = *(s32 *)((s8 *)input + 0x3C);
    outFlags = (-((srcFlags & 1) == 0) & 0x600) | 0x200;
    if (srcFlags & 0x40000) {
        outFlags &= 0x400;
    }
    if (srcFlags & 0x100000) {
        outFlags |= 0x20000000;
    }
    if (srcFlags & 2) {
        outFlags |= 0x800;
    }
    if (srcFlags & 0x80) {
        outFlags |= 2;
    }
    if (srcFlags & 0x10) {
        outFlags |= 4;
    }
    if (srcFlags & 0x20) {
        outFlags |= 8;
    }
    if (srcFlags & 0x100) {
        outFlags |= 1;
    }
    if (srcFlags & 0x40) {
        outFlags |= 0x10;
    }
    if (srcFlags & 8) {
        outFlags |= 0x20;
    }
    srcFlagsCopy = (u16) srcFlags | (srcFlags & (s32)0xFFFF0000);
    if (srcFlagsCopy & 0x400) {
        outFlags |= 0x80;
    }
    if (srcFlagsCopy & 0x200) {
        outFlags |= 0x40;
    }
    if (srcFlagsCopy & 0x4000) {
        outFlags |= 0x100000;
    }
    if (srcFlagsCopy & 0x8000) {
        outFlags |= 0x200000;
    }
    if (srcFlags & 0x80000) {
        outFlags |= 0x800000;
    }
    return outFlags;
}
