typedef struct AudioBufferNode { struct AudioBufferNode *next, *prev; s32 a, b, c; u8 *buf; } AudioBufferNode;
extern u8 *sPoolBufferBase; extern AudioBufferNode *sPoolNodes, *sPoolNodeHead; extern s32 D_800E425C, D_800E4260; extern void *(*gDataBankAlloc)(s32, s32); void flushDCacheRange(void *, s32);
/* Allocates the sample buffer and one list node per buffer slot, then links the nodes into a list. */
void audioInitBufferPool(u16 nodeCount) {
 s32 i; void *(**allocFn)(s32, s32) = &gDataBankAlloc; s32 bufSize = nodeCount * 0x600;
 sPoolBufferBase = (*allocFn)(bufSize, 0); flushDCacheRange(sPoolBufferBase, bufSize);
 sPoolNodes = (*allocFn)(nodeCount * sizeof(AudioBufferNode), 0); D_800E425C = 0; D_800E4260 = 0; sPoolNodeHead = sPoolNodes;
 sPoolNodes[0].prev = 0; sPoolNodes[0].buf = sPoolBufferBase;
 for (i = 1; i < nodeCount; i++) { sPoolNodes[i - 1].next = &sPoolNodes[i]; sPoolNodes[i].prev = &sPoolNodes[i - 1]; sPoolNodes[i].buf = sPoolBufferBase + i * 0x600; }
 sPoolNodes[i - 1].next = 0;
}
