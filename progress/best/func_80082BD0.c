typedef struct { u8 active; u8 pad[7]; f64 time; u32 now; u32 prev; u8 rest[0x50]; } E8B1C0;
extern E8B1C0 *D_800E41DC;
extern u16 D_800E41E4;
void func_8008B1C0(void) {
    s32 i = 0;
    E8B1C0 *p;
    if (i < D_800E41E4) {
        p = D_800E41DC;
        do {
            E8B1C0 *current = p;
            if (p->active) {
                f64 time = p->time;
                p->prev = p->now;
                current->now = (u32)time;
            }
            ++i;
            ++p;
        } while (i < D_800E41E4);
    }
}

extern f32 D_80102E6C, D_80102E70, D_80102E74, D_80102E78;
extern f32 D_80102E80, D_80102E84, D_80102E88, D_80102E8C, D_80102EA4;
f32 *func_80082BD0(void) {
    register f32 *out = (f32 *)((u32)&D_80102E74 & ~3U);
    f32 x0 = D_80102E80 * out[-3];
    f32 x1 = D_80102E84 * D_80102E6C;
    f32 x2 = D_80102E88 * D_80102E70;
    f32 y0 = D_80102E8C * out[-3];
    f32 y1 = out[7] * D_80102E6C;
    f32 y2 = out[8] * D_80102E70;
    f32 z0 = out[9] * out[-3];
    f32 z1 = out[10] * D_80102E6C;
    f32 z2 = out[11] * D_80102E70;
    f32 x = x0 + x1 + x2 + D_80102EA4;
    f32 y = y0 + y1 + y2 + out[13];
    f32 z = z0 + z1 + z2 + out[14];
    *out = x;
    D_80102E78 = y;
    out[2] = z;
    return out;
}
