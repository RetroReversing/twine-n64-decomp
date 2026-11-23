typedef struct Stream {
    u8 pad0[0x190];
    s32 (*read)(u8 *, void *, s32, void *);
    u8 *src;
    u8 *ring;
    u32 size;
    u32 buf[0x400];
    u16 cnt;
    u16 w2;
    u32 remain;
    u32 x11A8;
    u8 queue[0x1C];
    u32 x11C8;
    u32 x11CC;
    u32 pos;
    u32 x11D4;
    u32 x11D8;
    s8 pending;
    s8 mode;
    s8 budget;
} Stream;
s32 osRecvMesg(void *, s32, s32);
s32 func_8009DF60(void *, void *);
s32 bzero(void *, s32);
void func_8009D5D4(Stream *p) {
    s32 budget;
    u32 s1, s2, v1;
    s32 len;
    budget = p->budget;
    if (p->pending != 0 && osRecvMesg(p->queue, 0, 0) >= 0) {
        if (p->pos == 0) {
            p->cnt = (p->buf[1] >> 16) & 0xFFFF;
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
        if (p->pos - p->x11CC < 0xC01) {
            if (p->pos == 0) {
                len = 0x400;
            } else {
                if (p->remain > 0x100) len = 0x400;
                else len = p->remain * 4;
            }
            if (len > 0) {
                p->pending = 1;
                p->read(p->src + p->pos, (u8 *)p + 0x1A0 + ((p->pos & 0xFFF) >> 3) * 8, len, p->queue);
            }
        }
    }
    while (p->x11D8 - p->x11D4 < p->size - 0xA0 && (p->mode == 1 || p->cnt > 0) &&
           ((p->pos != 0 && p->remain == 0) || p->pos - p->x11CC >= 0x25) && budget > 0) {
        func_8009DF60(p, p->ring + ((p->x11D8 % p->size) >> 2) * 8);
        p->x11CC = (p->x11C8 >> 3) & ~3;
        p->x11D8 += 0xA0;
        p->cnt--;
        if (p->cnt == 0) p->x11A8 = p->size;
        budget--;
    }
    if ((p->mode == 3 || p->mode == 4) && p->cnt <= 0) {
        while (p->x11D8 - p->x11D4 < p->size - 0xA0 && budget > 0) {
            bzero(p->ring + ((p->x11D8 % p->size) >> 2) * 8, 0x140);
            p->x11D8 += 0xA0;
            budget--;
        }
    }
    if (p->mode == 1 && p->x11D8 - p->x11D4 >= p->size - 0x140) p->mode = 2;
}
