/* identical to osViBlack in V-RALLY-PAL (local match library) (matched), with its names changed by decompdecomp */
s32 func_8009F640(s32 a0);
void func_8009F6B0(s32 a0);
extern u16 *vi_active_ctx;

/* Turns the VI blank bit (0x20 in the VI control word at vi_active_ctx) on when
 * active is non-zero, off otherwise. Interrupts are disabled around the update. */
void osViBlack(s32 active)
{
    s32 saved_int;
    u16 *ctrl;

    saved_int = func_8009F640(active);
    if (active & 0xFF) {
        ctrl = vi_active_ctx;
        *ctrl = *ctrl | 0x20;
    } else {
        ctrl = vi_active_ctx;
        *ctrl = *ctrl & 0xFFDF;
    }
    func_8009F6B0(saved_int);
}
