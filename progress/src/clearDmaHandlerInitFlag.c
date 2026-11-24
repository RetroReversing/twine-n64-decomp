/* Clears the DMA handler initialised flag (called on data bank shutdown). */ extern s32 dmaHandlerInit; void clearDmaHandlerInitFlag(void) { dmaHandlerInit = 0; }
