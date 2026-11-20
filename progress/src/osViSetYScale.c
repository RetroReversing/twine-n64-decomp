/* identical to osViSetYScale in V-RALLY-PAL (local match library) (matched), with its names changed by decompdecomp */
s32 func_8009F640();
void func_8009F6B0(s32);
extern void *vi_active_ctx;

/* Sets the VI controller's Y scale and turns on the scale enable bit, with interrupts off. */
void osViSetYScale(f32 yScale)
{
    s32 savedInt;

    savedInt = func_8009F640();
    *(f32 *)((s8 *)vi_active_ctx + 0x24) = yScale;
    *(u16 *)((s8 *)vi_active_ctx + 0) = (u16)(*(u16 *)((s8 *)vi_active_ctx + 0) | 4);
    func_8009F6B0(savedInt);
}
