typedef struct Worker {
    struct Worker *next;
    u8 pad4[4];
    u32 flags;
    f32 pos[3];
    f32 vel[3];
    u8 pad24[0x48 - 0x24];
    u8 data48[0x78 - 0x48];
    f32 limitHi;
    f32 limitLo;
    f32 w80;
    f32 w84;
} Worker;

typedef struct Source {
    u8 pad0[8];
    u32 flags;
    f32 pos[3];
    f32 vel[3];
    f32 radius;
    f32 f28;
    f32 f2C;
    f32 f30;
} Source;

extern Worker *gWorkerListHead;
extern void func_80095280(void *, void *, f32 *);
extern f32 func_8009532C(f32 *);
extern f32 sqrtf(f32);

void func_800937D0(Source *a, f32 *o1, f32 *o2, f32 *o3, f32 *o4, f32 *o5) {
    f32 d[3];
    f32 v[3];
    f32 out[3];
    f32 acc[3];
    Worker *w;
    u32 n;
    f32 len, l2, t, k, s;
    f32 zero;

    s = 0.016666668f;
    *o1 = 0.0f;
    *o2 = 1.0f;
    w = gWorkerListHead;
    n = 0;
    zero = 0.0f;
    acc[2] = zero;
    acc[1] = zero;
    acc[0] = zero;
    if (w != NULL) {
        do {
            d[0] = a->pos[0] - w->pos[0];
            d[1] = a->pos[1] - w->pos[1];
            d[2] = a->pos[2] - w->pos[2];
            len = sqrtf(d[0] * d[0] + d[1] * d[1] + d[2] * d[2]);
            if (len <= a->radius) {
                t = len / a->radius;
                k = a->f30;
                *o1 += w->w84 * (a->f2C + (a->f28 - a->f2C) * (1.0f - ((1.0f - k) * t + k * t * t)));
                if (!(a->flags & 0x80000)) {
                    if ((a->flags & 8) || (w->flags & 1)) {
                        v[0] = w->vel[0] - a->vel[0];
                        v[1] = w->vel[1] - a->vel[1];
                        v[2] = w->vel[2] - a->vel[2];
                        l2 = sqrtf(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);
                        if (l2 > 0.0f) {
                            d[0] = (a->pos[0] + a->vel[0] * s) - (w->pos[0] + w->vel[0] * s);
                            d[1] = (a->pos[1] + a->vel[1] * s) - (w->pos[1] + w->vel[1] * s);
                            d[2] = (a->pos[2] + a->vel[2] * s) - (w->pos[2] + w->vel[2] * s);
                            if (sqrtf(d[0] * d[0] + d[1] * d[1] + d[2] * d[2]) < len) {
                                k = w->w80;
                                t = k - l2;
                            } else {
                                k = w->w80;
                                t = k + l2;
                            }
                            *o2 = k / t;
                        }
                    }
                    if (len != 0.0f) {
                        func_80095280(w->data48, a->pos, out);
                        if (out[2] >= 0.0f) {
                            acc[2] += (out[2] < w->limitHi) ? out[2] / w->limitHi : 1.0;
                        } else {
                            acc[2] += (-w->limitLo < out[2]) ? out[2] / w->limitLo : -1.0;
                        }
                        if (out[0] != 0.0 || out[1] != 0.0 || out[2] != 0.0f) {
                            func_8009532C(out);
                        }
                        acc[0] += out[0];
                        acc[1] += out[1];
                    }
                }
            }
            w = w->next;
            n++;
        } while (w != NULL);
    }
    if (n != 0) {
        *o3 = acc[0] / (f32)n;
        *o4 = acc[1] / (f32)n;
        *o5 = acc[2] / (f32)n;
    }
}
