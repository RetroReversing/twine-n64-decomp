void func_800455CC(void *a, void *b, void *c, void *d);
void func_80045824(f32 *a, f32 *b);
f32 func_80045E34(void *a, void *b);
extern u8 D_801096A0;
extern u8 D_80109A60[];

void *func_8000BF90(u8 *arg0, u8 *arg1, u8 *arg2, u8 *arg3) {
    void *best[2];
    f32 bestd[2];
    f32 sp20[3];
    f32 sp30[3];
    u8 *p;
    u8 *list;
    u8 *node;
    u8 *t;
    f32 *pos;
    f32 *tf;
    f32 f;
    f32 dot;
    s32 iv;
    u32 idx;
    u32 r, g, b, v;
    u32 mn;
    s32 k;

    pos = (f32 *)(arg0 + 0x24);
    p = *(u8 **)(arg0 + 0x20);
    if (p != NULL) {
        for (k = 0; k < 2; k++) {
            best[k] = NULL;
            bestd[k] = 65536.0f;
        }
        list = *(u8 **)(*(u8 **)(p + 0x20) + 0x58);
        do {
            node = *(u8 **)(*(u8 **)(p + 0x20) + 0x50);
            while (node != NULL) {
                if (node[0x2B] == 0 || D_80109A60[node[0x2B]] != 0) {
                    func_800455CC(sp20, node + 4, node + 0x10, pos);
                    f = func_80045E34(pos, sp20);
                    for (idx = 0; idx < 2; idx++) {
                        if (f > 0.0f && f < bestd[idx]) {
                            break;
                        }
                    }
                    if (idx < 2) {
                        if (idx == 0) {
                            best[1] = best[0];
                            bestd[1] = bestd[0];
                        }
                        best[idx] = node;
                        bestd[idx] = f;
                    }
                }
                node = *(u8 **)node;
            }
            if (list != NULL) {
                p = *(u8 **)(list + 8);
                list = *(u8 **)list;
            } else {
                p = NULL;
            }
        } while (p != NULL);

        r = 0;
        g = 0;
        b = 0;
        for (idx = 0; idx < 2; idx++) {
            t = best[idx];
            if (t != NULL) {
                tf = (f32 *)t;
                sp30[0] = pos[0] - tf[1];
                sp30[1] = pos[1] - tf[2];
                sp30[2] = pos[2] - tf[3];
                func_80045824(sp30, sp30);
                dot = sp30[0] * tf[7] + sp30[1] * tf[8] + sp30[2] * tf[9];
                if (dot > 0.0f) {
                    if (dot >= 2147483648.0f) {
                        iv = (s32)(dot - 2147483648.0f) | 0x80000000;
                    } else {
                        iv = (s32)dot;
                    }
                    v = (u32)iv & 0xFFFF;
                    r += (v * t[0x28]) >> 8;
                    g += (v * t[0x29]) >> 8;
                    b += (v * t[0x2A]) >> 8;
                    if ((r & 0xFFFF) >= 0x100) {
                        r = 0xFF;
                    }
                    if ((g & 0xFFFF) >= 0x100) {
                        g = 0xFF;
                    }
                    if ((b & 0xFFFF) >= 0x100) {
                        b = 0xFF;
                    }
                }
            }
        }
        mn = D_801096A0 & 0xFFFF;
        if ((r & 0xFFFF) < mn) {
            r = D_801096A0;
        }
        if ((g & 0xFFFF) < mn) {
            g = D_801096A0;
        }
        if ((b & 0xFFFF) < mn) {
            b = D_801096A0;
        }
        if ((r & 0xFFFF) >= 0x100) {
            r = 0xFF;
        }
        if ((g & 0xFFFF) >= 0x100) {
            g = 0xFF;
        }
        if ((b & 0xFFFF) >= 0x100) {
            b = 0xFF;
        }
        *arg1 = r;
        *arg2 = g;
        *arg3 = b;
        return best[0];
    }
    return NULL;
}
