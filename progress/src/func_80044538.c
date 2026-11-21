typedef struct { u32 f0; u8 pad[12]; } Slot_800C0784;
extern Slot_800C0784 D_800C0784[];
typedef struct { u32 f0; u8 pad[12]; } Slot_800C0788;
extern Slot_800C0788 D_800C0788[];
typedef struct { u32 f0; u8 pad[12]; } Slot_800C078C;
extern Slot_800C078C D_800C078C[];
s32 func_80084048();
void func_80044538(s32 arg0) {
    volatile u64 stack_pad;
    register u32 *base;
    s32 flag;
    u32 i;
    u8 *p;
    void *tmp;
    flag = 1;
    if (D_800C0784[arg0].f0 != 0) {
        tmp = (void *)D_800C0788[arg0].f0;
        i = 0;
        if (D_800C078C[arg0].f0 != 0) {
            do {
                p = (u8 *)tmp + i * 0x4C;
                if (*(s32 *)p != 0) {
                    if (p[0x46] >= 5) {
                        p[0x46] = 4;
                    }
                    flag = 0;
                }
                i++;
            } while (i < D_800C078C[arg0].f0);
        }
        if ((s16)flag != 0) {
            func_80084048(D_800C0788[arg0].f0, 0xA, flag);
            func_80084048(*(u32 *)(*(u32 *)(D_800C0784[arg0].f0 + 0x10) + 4), 0x1B);
            func_80084048(*(u32 *)(*(u32 *)(D_800C0784[arg0].f0 + 0x18) + 8), 0x1A);
            func_80084048(*(u32 *)(D_800C0784[arg0].f0 + 0x10), 0x18);
            func_80084048(*(u32 *)(D_800C0784[arg0].f0 + 0x18), 0x1A);
            D_800C0784[arg0].f0 = 0;
        }
    }
}
