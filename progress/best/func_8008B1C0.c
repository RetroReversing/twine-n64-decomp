typedef struct { u8 active; u8 pad[7]; f64 time; u32 now; u32 prev; u8 rest[0x50]; } E8B1C0;
extern E8B1C0 *D_800E41DC;
extern u16 D_800E41E4;
void func_8008B1C0(void) {
    s32 i;
    E8B1C0 *e;
    E8B1C0 *p;
    i = 0;
    e = D_800E41DC;
    if (i < D_800E41E4) {
        do {
            p = e;
            if (p->active != 0) {
                p->prev = p->now;
                p->now = p->time;
            }
            i++;
            e++;
        } while (i < D_800E41E4);
    }
}
