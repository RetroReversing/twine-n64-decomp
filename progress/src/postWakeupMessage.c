/* identical to order_post_wakeup in V-RALLY-PAL (local match library) (matched), with its names changed by decompdecomp */
extern char gOrderStateBase[];
void osSendMesg(char *a, int b, int c);
/* Posts a zero-valued blocking message to the order state's message queue. */
/* Posts a zero-valued blocking message to the wakeup message queue embedded in the order state. */ void postWakeupMessage(void) { osSendMesg(gOrderStateBase + 0x87A8, 0, 0); }
