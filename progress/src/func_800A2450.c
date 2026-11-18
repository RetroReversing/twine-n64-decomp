/* identical to order_post_wakeup in V-RALLY-PAL (local match library) (matched), with its names changed by decompdecomp */
extern char D_8010EF68[];
void osSendMesg(char *a, int b, int c);
/* Posts a zero-valued blocking message to the order state's message queue. */
void func_800A2450(void) { osSendMesg(D_8010EF68 + 0x87A8, 0, 0); }
