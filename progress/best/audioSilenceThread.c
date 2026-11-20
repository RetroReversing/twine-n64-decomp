extern void bzero(void *, s32);
extern s32 func_800A00D0(s32, s32);
extern void func_800A0220(s32, s32);
extern s32 osRecvMesg(void *, u8 **, s32);
extern u8 gWorkerMsgQueue[24];
extern s32 D_800E4170[24];
extern volatile u8 D_800E41D0;
extern u32 D_800E41D4;
extern u8 D_800E41D8;
extern volatile u16 D_800E41DA;
extern s32 (*D_8010017C)(s32, s32);
extern u8 D_8010086C;

void audioSilenceThread(void) {
    u8 *message;
    s32 *prev;
    s32 *next;
    s32 i;
    s32 count;
    u32 buffers;
    u8 done;

    buffers = (-(D_8010086C != 0) & 0x18) | 0x10;
    D_800E41DA = buffers;
    if (D_800E41D4 < 0x5623U) {
        D_800E41DA = buffers >> 1;
    }
    D_800E4170[0] = D_8010017C(D_800E41DA * 0x300, 0x80);
    i = 1;
    count = *(u16 *)&D_800E41DA;
    prev = D_800E4170;
    if (i < count) {
        s32 limit = count;
        next = prev + 1;
        do {
            s32 addr = *prev++;
            i++;
            *next++ = addr + 0x300;
        } while (i < limit);
    }
    bzero((void *)D_800E4170[0], D_800E41DA * 0x300);
    done = 0;
    func_800A0220(D_800E4170[0], D_800E41DA * 0x300);
    D_800E41D0 = 0;
    func_800A00D0(D_800E4170[0], 0x300);
    do {
        osRecvMesg(gWorkerMsgQueue, &message, 1);
        if (!D_800E41D8) {
            switch (*message) {
            case 1:
                D_800E41D0 = (D_800E41D0 + 1) % (s32)D_800E41DA;
                func_800A00D0(D_800E4170[D_800E41D0], 0x300);
                break;
            case 255:
                done = 1;
                break;
            }
        }
    } while (!done);
}
