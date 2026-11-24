typedef struct Stream {
    u8 pad0[0x190];
    s32 (*readAsync)(u8 *, void *, s32, void *);
    u8 *src;
    u8 *ring;
    u32 ringSize;
    u32 buf[0x400];
    u16 frameCount;
    u16 w2;
    u32 remain;
    u32 x11A8;
    u8 queue[0x1C];
    u32 x11C8;
    u32 consumedSrcPos;
    u32 pos;
    u32 ringReadPos;
    u32 ringWritePos;
    s8 pending;
    s8 mode;
    s8 budget;
} Stream;
s32 osRecvMesg(void *, s32, s32);
s32 readAudioFrame(void *, void *);
s32 bzero(void *, s32);
/* Per-tick audio stream pump: completes the pending ROM read, starts the next one,
 * decodes up to `budget` frames into the output ring, and pads with silence at the end. */
void updateAudioStream(Stream *p) {
    s32 budget;
    u32 s1, s2, v1;
    s32 len;
    budget = p->budget;
    if (p->pending != 0 && osRecvMesg(p->queue, 0, 0) >= 0) {
        if (p->pos == 0) {
            p->frameCount = (p->buf[1] >> 16) & 0xFFFF;
            p->w2 = p->buf[1] & 0xFFFF;
            p->remain = p->buf[2] & 0xFFFFFF;
            p->x11C8 = 0x60;
        }
        p->pos += 0x400;
        if (p->remain > 0x100) {
            p->remain -= 0x100;
        } else {
            p->remain = 0;
        }
        p->pending = 0;
    }
    if (p->pending == 0 && (p->mode == 1 || p->mode == 2 || p->mode == 3)) {
        if (p->pos - p->consumedSrcPos < 0xC01) {
            if (p->pos == 0) {
                len = 0x400;
            } else {
                if (p->remain > 0x100) len = 0x400;
                else len = p->remain * 4;
            }
            if (len > 0) {
                p->pending = 1;
                p->readAsync(p->src + p->pos, (u8 *)p + 0x1A0 + ((p->pos & 0xFFF) >> 3) * 8, len, p->queue);
            }
        }
    }
    while (p->ringWritePos - p->ringReadPos < p->ringSize - 0xA0 && (p->mode == 1 || p->frameCount > 0) &&
           ((p->pos != 0 && p->remain == 0) || p->pos - p->consumedSrcPos >= 0x25) && budget > 0) {
        readAudioFrame(p, p->ring + ((p->ringWritePos % p->ringSize) >> 2) * 8);
        p->consumedSrcPos = (p->x11C8 >> 3) & ~3;
        p->ringWritePos += 0xA0;
        p->frameCount--;
        if (p->frameCount == 0) p->x11A8 = p->ringSize;
        budget--;
    }
    if ((p->mode == 3 || p->mode == 4) && p->frameCount <= 0) {
        while (p->ringWritePos - p->ringReadPos < p->ringSize - 0xA0 && budget > 0) {
            bzero(p->ring + ((p->ringWritePos % p->ringSize) >> 2) * 8, 0x140);
            p->ringWritePos += 0xA0;
            budget--;
        }
    }
    if (p->mode == 1 && p->ringWritePos - p->ringReadPos >= p->ringSize - 0x140) p->mode = 2;
}
