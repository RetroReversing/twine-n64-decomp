extern void *gFramebuffers[];
extern s16 gExpansionPakPresent;
extern u16 gFramebufferCount;
extern void *memset(void *, int, unsigned int);

void func_800081C4(s32 fill) {
    s32 bytes = 0x25800;
    u32 i;

    if (gExpansionPakPresent != 0)
        bytes = 0x4B000;
    for (i = 0; i < gFramebufferCount; i++)
        memset(gFramebuffers[i], fill & 0xFF, bytes);
}
