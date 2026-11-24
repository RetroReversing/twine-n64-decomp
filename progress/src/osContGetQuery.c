/* identical to osContGetQuery in V-RALLY-PAL (local match library) (matched), with its names changed by decompdecomp */
s32 __osContGetInitData(s32 *, s32);

/* Hands queryBuf to the pad driver's init-data routine, which fills a local scratch word. */
void osContGetQuery(void *queryBuf) {
    s32 initData;

    __osContGetInitData(&initData, (s32)queryBuf);
}
