/* identical to osContGetQuery in V-RALLY-PAL (local match library) (matched), with its names changed by decompdecomp */
s32 func_800A06EC(s32 *, s32);

/* Hands queryBuf to the pad driver's init-data routine, which fills a local scratch word. */
void osContGetQuery(void *queryBuf) {
    s32 initData;

    func_800A06EC(&initData, (s32)queryBuf);
}
