extern u8 sAltPrimTintR;
extern u8 sPrimTintB;
extern u8 sPrimTintG;
extern u8 sPrimTintR;
extern u8 sAltPrimTintG;
extern u8 sAltPrimTintB;
extern void *sDisplayListCursor;

/* Emits a G_SETPRIMCOLOR display-list command with the object's average vertex colour, scaled by the active prim tint. */
void emitPrimColor(void *obj, void *state) {
    s32 flags;
    s32 r, g, b;
    u16 lum;
    void *dl;

    flags = *(s32 *)((char *)state + 0x100);
    if (flags & 2) {
u8 *colors;

        colors = *(u8 **)((char *)obj + 0x20);
        lum = (colors[0x64] + colors[0x65] + colors[0x66]) / 3;
        r = (lum * sPrimTintR) >> 8;
        g = (lum * sPrimTintG) >> 8;
        b = (lum * sPrimTintB) >> 8;
    } else if (flags & 4) {
u8 *colors;

        colors = *(u8 **)((char *)obj + 0x20);
        lum = (colors[0x64] + colors[0x65] + colors[0x66]) / 3;
        r = (lum * sAltPrimTintR) >> 8;
        g = (lum * sAltPrimTintG) >> 8;
        b = (lum * sAltPrimTintB) >> 8;
    } else {
u8 *colors;

        colors = *(u8 **)((char *)obj + 0x20);
        r = colors[0x64];
        g = colors[0x65];
        b = colors[0x66];
    }
    dl = sDisplayListCursor;
    sDisplayListCursor = (u8 *)dl + 8;
    ((s32 *)dl)[0] = 0xFA000000;
    ((s32 *)dl)[1] = (r << 24) | ((g & 0xFF) << 16) | ((b & 0xFF) << 8) | 0x80;
}
