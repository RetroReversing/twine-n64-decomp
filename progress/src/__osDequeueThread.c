/* identical to __osDequeueThread in V-RALLY-PAL (local match library) (matched), with its names changed by decompdecomp */
/* Remove thread from its queue. */
/* Removes a thread from a singly linked thread queue. */ void __osDequeueThread(void **queue, void *thread) { void *node = *queue; while (node) { if (node == thread) { *queue = *(void **)node; return; } queue = node; node = *(void **)node; } }
