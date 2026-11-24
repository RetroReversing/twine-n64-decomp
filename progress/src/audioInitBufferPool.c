typedef struct AudioBufferNode { struct AudioBufferNode *next, *prev; s32 a, b, c; u8 *buf; } AudioBufferNode;
extern u8 *sPoolBufferBase; extern AudioBufferNode *sPoolNodes, *gCacheFreeList; extern s32 gCacheLruTail, gCacheLruHead; extern void *(*gDataBankHandler)(s32, s32); void flushDCacheRange(void *, s32);
/* Allocates the sample buffer and one list node per buffer slot, then links the nodes into a list. */
void audioInitBufferPool(u16 nodeCount) {
 s32 i; void *(**allocFn)(s32, s32) = &gDataBankHandler; s32 bufSize = nodeCount * 0x600;
 sPoolBufferBase = (*allocFn)(bufSize, 0); flushDCacheRange(sPoolBufferBase, bufSize);
 sPoolNodes = (*allocFn)(nodeCount * sizeof(AudioBufferNode), 0); gCacheLruTail = 0; gCacheLruHead = 0; gCacheFreeList = sPoolNodes;
 sPoolNodes[0].prev = 0; sPoolNodes[0].buf = sPoolBufferBase;
 for (i = 1; i < nodeCount; i++) { sPoolNodes[i - 1].next = &sPoolNodes[i]; sPoolNodes[i].prev = &sPoolNodes[i - 1]; sPoolNodes[i].buf = sPoolBufferBase + i * 0x600; }
 sPoolNodes[i - 1].next = 0;
}
