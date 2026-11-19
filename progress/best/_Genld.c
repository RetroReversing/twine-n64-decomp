typedef struct {
    s32 f00;
    s32 f04;
    u8 *buf;
    s32 f0C;
    s32 f10;
    s32 pos;
    s32 f18;
    s32 f1C;
    s32 f20;
    s32 width;
    s32 f28;
    s32 f2C;
    s32 flags;
} Gen;

u8 *memcpy(u8 *dst, u8 *src, s32 n);
extern u8 D_800D6E70[];

void _Genld(Gen *g, s8 arg1, u8 *arg2, s16 arg3, s32 arg4) {
    u8 *s2;
    s8 s3;
    s16 s5;
    s16 s5_2;
    s16 s5_3;
    s16 s4_2;
    s32 s4;
    s32 v;
    s32 t;
    u8 *p;
    u8 *p2;
    s32 tmp;
    s32 a2;

    s2 = arg2;
    s3 = arg1;
    s5 = arg3;
    s4 = arg4;
    if ((arg3 << 0x10) <= 0) {
        s5 = 1;
        s2 = D_800D6E70;
    }
    if (arg1 != 0x66) {
        if (arg1 == 0x67 || arg1 == 0x47) {
            if ((s16) arg4 >= -4) {
                if ((s16) arg4 < g->width) {
                    goto block_6;
                }
            }
            if (arg1 == 0x67 || arg1 == 0x47) {
                if (s5 < g->width) {
                    g->width = s5;
                }
                g->width = g->width - 1;
                if (g->width < 0) {
                    g->width = 0;
                }
                s3 = (arg1 == 0x67) ? 0x65 : 0x45;
            }
        }
        goto block_38;
    } else {
block_6:
        s4_2 = arg4 + 1;
        if (arg1 != 0x66) {
            if (!(g->flags & 8) && (s5 < g->width)) {
                g->width = s5;
            }
            t = g->width - s4_2;
            g->width = t;
            if (t < 0) {
                g->width = 0;
            }
        }
        if (s4_2 <= 0) {
            g->buf[g->pos++] = 0x30;
            if ((g->width > 0) || ((v = s4_2 << 0x10), (g->flags & 8) != 0)) {
                g->buf[g->pos++] = 0x2E;
            }
            if (g->width < -s4_2) {
                s4_2 = (s16) -g->width;
            }
            g->f18 = -s4_2;
            g->width = g->width + s4_2;
            if (g->width < s5) {
                s5 = (s16) g->width;
            }
            g->f1C = s5;
            memcpy(g->buf + g->pos, s2, s5);
            g->f20 = g->width - s5;
        } else if (s5 < s4_2) {
            memcpy(g->buf + g->pos, s2, s5);
            g->f18 = s4_2 - s5;
            g->pos = g->pos + s5;
            if ((g->width > 0) || (g->flags & 8)) {
                g->buf[g->pos] = 0x2E;
                g->f1C = g->f1C + 1;
            }
            g->f20 = g->width;
        } else {
            memcpy(g->buf + g->pos, s2, s4_2);
            s5_3 = s5 - s4_2;
            a2 = g->pos + s4_2;
            g->pos = a2;
            if ((g->width > 0) || (g->flags & 8)) {
                g->pos = a2 + 1;
                g->buf[a2] = 0x2E;
            }
            if (g->width < s5_3) {
                s5_3 = (s16) g->width;
            }
            memcpy(g->buf + g->pos, s2 + s4_2, s5_3);
            g->pos = g->pos + s5_3;
            g->f18 = g->width - s5_3;
        }
    }
    goto done;

block_38:
    g->buf[g->pos++] = *s2;
    if ((g->width > 0) || (g->flags & 8)) {
        g->buf[g->pos++] = 0x2E;
    }
    t = g->width;
    tmp = s5 - 1;
    if (t > 0) {
        s5_2 = tmp;
        if (t < tmp) {
            s5_2 = (s16) t;
        }
        memcpy(g->buf + g->pos, s2 + 1, s5_2);
        g->pos = g->pos + s5_2;
        g->f18 = g->width - s5_2;
    }
    p = g->buf + g->pos;
    *p = s3;
    p2 = p + 1;
    if (!(s4 & 0x8000)) {
        p[1] = 0x2B;
        p2 = p2 + 1;
    } else {
        p[1] = 0x2D;
        p2 = p2 + 1;
        s4 = -s4;
    }
    if ((s16) s4 >= 0x64) {
        if ((s16) s4 >= 0x3E8) {
            *p2++ = (s4 / 1000) + 0x30;
            s4 = s4 % 0x3E8;
        }
        *p2++ = (s4 / 100) + 0x30;
        s4 = s4 % 0x64;
    }
    p2[0] = (s4 / 10) + 0x30;
    p2[1] = (s4 % 10) + 0x30;
    g->f1C = (p2 + 2) - p;

done:
    if ((g->flags & 0x14) == 0x10) {
        t = g->f28;
        tmp = g->f0C + g->pos + g->f18 + g->f1C + g->f20;
        if (tmp < t) {
            g->f10 = t - tmp;
        }
    }
}
