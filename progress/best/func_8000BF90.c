void func_800455CC(void *a, void *b, void *c, void *d);
void normalizeVector3(f32 *a, f32 *b);
f32 approxDistance(void *a, void *b);
extern u8 D_801096A0;
extern u8 gTrackDoneFlags[];

void *func_8000BF90(u8 *arg0, u8 *arg1, u8 *arg2, u8 *arg3) {
    void *best[2];
    f32 bestd[2];
    f32 sp20[3];
    f32 sp30[3];
    union { u8 * pointer; u32 value; } __repair_phase_storage;
    u8 *list;
    f32 dot;
    u8 *t;
    u8 *selected;
    f32 *pos;
    f32 *tf;
    f32 f;
    s32 idx;
    u32 iv;
    register u8 *node;
    u32 r, g, b, v;
    register unsigned int k;
    pos = (f32 *)(arg0 + 0x24);
    __repair_phase_storage.pointer = *(u8 **)(arg0 + 0x20);
    if (__repair_phase_storage.pointer != NULL) {
        list = *(u8 **)(*(u8 **)(__repair_phase_storage.pointer + 0x20) + 0x58);
        for (idx = 0; (u32)idx < 2; idx++) {
            best[idx] = NULL;
            bestd[idx] = 65536.0f;
        }
        while (__repair_phase_storage.pointer != NULL) {
            node = *(u8 **)(*(u8 **)(__repair_phase_storage.pointer + 0x20) + 0x50);
            while (node != NULL) {
                if (node[0x2B] == 0 || gTrackDoneFlags[node[0x2B]] != 0) {
                    func_800455CC(sp20, node + 4, node + 0x10, ((f32 *)(arg0 + 0x24)));
                    f = approxDistance(((f32 *)(arg0 + 0x24)), sp20);
                    idx = 0;
                    do {
                        if (f > 0.0f && f < bestd[idx]) {
                            for (iv = 1; iv > idx; iv--) {
                                bestd[iv] = bestd[iv - 1];
                                best[iv] = best[iv - 1];
                            }
                            best[idx] = node;
                            bestd[idx] = f;
                            break;
                        }
                    } while ((u32)++idx < 2U);
                }
                node = *(u8 **)node;
            }
            if (list != NULL) {
                __repair_phase_storage.pointer = *(u8 **)(list + 8);
                list = *(u8 **)list;
            } else {
                __repair_phase_storage.pointer = NULL;
            }
        }
        b = 0; g = 0; r = 0;
        idx = 0;
        do {
            selected = best[idx];
            if (!selected) goto next_color;
            {
                t = selected;
                tf = (f32 *)t;
                sp30[0] = ((f32 *)(arg0 + 0x24))[0] - tf[1];
                sp30[1] = ((f32 *)(arg0 + 0x24))[1] - tf[2];
                sp30[2] = ((f32 *)(arg0 + 0x24))[2] - tf[3];
                normalizeVector3(sp30, sp30);
                dot = sp30[0] * tf[7] + sp30[1] * tf[8] + sp30[2] * tf[9];
                if (dot > 0.0f) {
                    v = (u32)dot & 0xFFFF;
                    r += (v * t[0x28]) >> 8;
                    g += (v * t[0x29]) >> 8;
                    b += (v * t[0x2A]) >> 8;
                    if ((r & 0xFFFF) >= 0x100) r = 0xFF;
                    if ((g & 0xFFFF) >= 0x100) g = 0xFF;
                    if ((b & 0xFFFF) >= 0x100) b = 0xFF;
                }
            }
next_color:
            ++idx;
        } while ((u32)idx < 2);
        __repair_phase_storage.value = D_801096A0 & 0xFFFF;
        if ((r & 0xFFFF) < __repair_phase_storage.value) r = (int)D_801096A0;
        if ((g & 0xFFFF) < __repair_phase_storage.value) g = D_801096A0;
        if ((b & 0xFFFF) < __repair_phase_storage.value) b = D_801096A0;
        if ((r & 0xFFFF) >= 0x100) r = 0xFF;
        if ((g & 0xFFFF) >= 0x100) g = 0xFF;
        if ((b & 0xFFFF) >= 0x100) b = 0xFF;
        *arg1 = r; *arg2 = g; *arg3 = b;
        if (best[0] != NULL) return best[0];
    }
    return NULL;
}

