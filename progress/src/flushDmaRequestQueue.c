typedef struct { s32 a, b, c; } T9D100;
s32 func_800CEEE0(s32, s32);
s32 osSendMesg(void *, s32, s32);
extern volatile u8 dmaQueueCount;
extern T9D100 dmaQueueRomAddr[];
extern u8 sDmaQueueBusy;
extern char dmaMesgQueue[];
extern T9D100 *sSlotLog;
extern u16 sSlotLogCount;
extern s32 D_80109BA0;
extern s32 D_80109BF8;

/* Moves queued DMA requests into the slot log, advancing the log cursor, and marks the queue busy until the next flush. */ void flushDmaRequestQueue(void) {
    u8 reqIdx;
    T9D100 *logEntry;

    if (sDmaQueueBusy != 0) {
        osSendMesg(dmaMesgQueue, 0, 0);
    }
    if (dmaQueueCount != 0) {
        for (reqIdx = 0; reqIdx < dmaQueueCount; reqIdx++) {
            D_80109BF8 += 0xC;
            D_80109BA0 = func_800CEEE0(D_80109BA0, D_80109BF8);
            logEntry = (T9D100 *)(sSlotLogCount * (s32)sizeof(*logEntry) + (u32)sSlotLog);
            logEntry->b = dmaQueueRomAddr[reqIdx].b;
            logEntry->a = dmaQueueRomAddr[reqIdx].c;
            logEntry->c = dmaQueueRomAddr[reqIdx].a;
            sSlotLogCount++;
        }
        dmaQueueCount = 0;
        sDmaQueueBusy = 1;
    } else {
        sDmaQueueBusy = 0;
    }
}
