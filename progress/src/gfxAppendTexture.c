/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */
#ifndef M2C_DEFINES
#define M2C_DEFINES
typedef s32 M2C_UNK;
typedef s8 M2C_UNK8;
typedef s16 M2C_UNK16;
typedef s32 M2C_UNK32;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define M2C_CARRY 0
#define M2C_OVERFLOW(a) (0)
#endif

extern void *gGfxPtr;

/* Appends RDP texture-load commands for a sprite entry to the display list gGfxPtr, or only counts their words when emit is 0. */ void gfxAppendTexture(void *entry, s32 *arg1, u32 kind, s32 unusedArg, s32 tableBase, u8 arg5, s32 *arg6) {
    s32 tileAddr;
    void *gfx0;
    void *gfx1;
    void *gfxTex;
    void *gfxTex2;

    tileAddr = M2C_FIELD(((M2C_FIELD(entry, u8 *, 1) * 8) + tableBase), s32 *, 4);
    switch (kind) {
    case 5:
    case 6:
    case 9:
    case 15:
    if (*arg1 != 1) {
        if (arg5 != 0) {
            gfx0 = gGfxPtr;
            gGfxPtr = gfx0 + 8;
            M2C_FIELD(gfx0, s32 *, 0) = 0xE3001001;
            M2C_FIELD(gfx0, s32 *, 4) = 0;
        } else {
            *arg6 += 1;
        }
        *arg1 = 1;
    }
        break;
    default:
        if (*arg1 != 2) {
            if (arg5 != 0) {
                gfx1 = gGfxPtr;
                gGfxPtr = gfx1 + 8;
                M2C_FIELD(gfx1, s32 *, 0) = 0xE3001001;
                M2C_FIELD(gfx1, s32 *, 4) = 0x8000;
            } else {
                *arg6 += 1;
            }
            *arg1 = 2;
        }
        if (*(u8 *)((M2C_FIELD(entry, u8 *, 1) * 8) + tableBase) == 0xFF) {
            if (arg5 != 0) {
                gfxTex = gGfxPtr;
                gGfxPtr = gfxTex + 8;
                M2C_FIELD(gfxTex, s32 *, 0) = 0xFD100000;
                M2C_FIELD(gfxTex, s32 *, 4) = (s32) (tileAddr & ~7);
                gGfxPtr = gfxTex + 0x10;
                M2C_FIELD(gfxTex, s32 *, 8) = 0xE6000000;
                gGfxPtr = gfxTex + 0x18;
                M2C_FIELD(gfxTex, s32 *, 0x10) = 0xF0000000;
                gGfxPtr = gfxTex + 0x20;
                M2C_FIELD(gfxTex, s32 *, 0xC) = 0;
                M2C_FIELD(gfxTex, s32 *, 0x14) = 0x063FC000;
                M2C_FIELD(gfxTex, s32 *, 0x18) = 0xE7000000;
                M2C_FIELD(gfxTex, s32 *, 0x1C) = 0;
            } else {
                *arg6 += 4;
            }
        }
        if (*(u8 *)((M2C_FIELD(entry, u8 *, 1) * 8) + tableBase) == 0xF) {
            if (arg5 != 0) {
                gfxTex2 = gGfxPtr;
                gGfxPtr = gfxTex2 + 8;
                M2C_FIELD(gfxTex2, s32 *, 0) = 0xFD100000;
                M2C_FIELD(gfxTex2, s32 *, 4) = (s32) (tileAddr & ~7);
                gGfxPtr = gfxTex2 + 0x10;
                M2C_FIELD(gfxTex2, s32 *, 8) = 0xE6000000;
                gGfxPtr = gfxTex2 + 0x18;
                M2C_FIELD(gfxTex2, s32 *, 0x10) = 0xF0000000;
                gGfxPtr = gfxTex2 + 0x20;
                M2C_FIELD(gfxTex2, s32 *, 0xC) = 0;
                M2C_FIELD(gfxTex2, s32 *, 0x14) = 0x0603C000;
                M2C_FIELD(gfxTex2, s32 *, 0x18) = 0xE7000000;
                M2C_FIELD(gfxTex2, s32 *, 0x1C) = 0;
                return;
            }
            *arg6 += 4;
        }
        break;
    }
}
