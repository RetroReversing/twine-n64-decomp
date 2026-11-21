typedef struct { u8 active; u8 pad[7]; f64 time; u32 now; u32 prev; u8 rest[0x50]; } E8B1C0;
extern E8B1C0 *D_800E41DC;
extern u16 D_800E41E4;
void func_8008B1C0(void) {
    s32 i;
    E8B1C0 *p;
    for (i = 0; i < D_800E41E4; i++) {
        if (D_800E41DC[i].active != 0) {
            p = &D_800E41DC[i];
            p->prev = p->now;
            p->now = p->time;
        }
    }
}
