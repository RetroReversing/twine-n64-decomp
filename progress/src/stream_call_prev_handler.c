/* identical to stream_call_prev_handler in V-RALLY-PAL (local match library) (matched), with its names changed by decompdecomp */
extern void (*D_80100180)(void);

/* Calls the stream handler that was installed before the current one. */
void stream_call_prev_handler(void) {
    D_80100180();
}
