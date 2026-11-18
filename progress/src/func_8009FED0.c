/* identical to order_post_wakeup in V-RALLY-PAL (local match library) (matched), with its names changed by decompdecomp */
extern char D_80101290[];
void osSendMesg(char *a, int b, int c);
/* Posts a zero-valued blocking message to the order state's message queue. */
void func_8009FED0(void) { osSendMesg(D_80101290 + 0x87A8, 0, 0); }
