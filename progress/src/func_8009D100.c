typedef struct { s32 a, b, c; } T9D100;
s32 func_800CEEE0(s32, s32);
s32 osSendMesg(void *, s32, s32);
extern volatile u8 dmaQueueCount;
extern T9D100 dmaQueueRomAddr[];
extern u8 D_800FDBE4;
extern char dmaMesgQueue[];
extern T9D100 *sSlotLog;
extern u16 sSlotLogCount;
extern s32 D_80109BA0;
extern s32 D_80109BF8;

void func_8009D100(void) {
    u8 i;
    T9D100 *o;

    if (D_800FDBE4 != 0) {
        osSendMesg(dmaMesgQueue, 0, 0);
    }
    if (dmaQueueCount != 0) {
        for (i = 0; i < dmaQueueCount; i++) {
            D_80109BF8 += 0xC;
            D_80109BA0 = func_800CEEE0(D_80109BA0, D_80109BF8);
            o = (T9D100 *)(sSlotLogCount * (s32)sizeof(*o) + (u32)sSlotLog);
            o->b = dmaQueueRomAddr[i].b;
            o->a = dmaQueueRomAddr[i].c;
            o->c = dmaQueueRomAddr[i].a;
            sSlotLogCount++;
        }
        dmaQueueCount = 0;
        D_800FDBE4 = 1;
    } else {
        D_800FDBE4 = 0;
    }
}
