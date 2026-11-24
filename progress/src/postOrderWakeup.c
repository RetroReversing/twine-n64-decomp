/* identical to order_post_wakeup in V-RALLY-PAL (local match library) (matched), with its names changed by decompdecomp */
extern char gOsBssBase[];
void osSendMesg(char *a, int b, int c);
/* Posts a zero-valued blocking message to the order state's message queue. */
/* Posts a zero-valued blocking message to the order message queue in OS bss. */ void postOrderWakeup(void) { osSendMesg(gOsBssBase + 0x87A8, 0, 0); }
