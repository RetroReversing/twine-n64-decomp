s32 func_8008C1B0(u8);
s32 func_80095638(void);
s32 func_800957A8(u32 *);
s32 func_800957B8(u32 *, void *);
s32 func_80099CA8(void *arg0, void *arg1) {
    u32 sp10;
    u32 s1;
    u32 a0;
    sp10 = *(u16 *)((s8 *)arg1 + 4);
    if (sp10 != 0) {
        if ((*(u32 *)arg1 >> 8) & 1) {
            if (*(s32 *)((s8 *)arg0 + 0x24) & 8) return 0;
            *(s32 *)((s8 *)arg0 + 0x24) |= 4;
        } else {
            *(s32 *)((s8 *)arg0 + 0x24) &= ~4;
        }
        if (*(u8 *)arg1 & 1) {
            if (!(*(s32 *)((s8 *)arg0 + 0x24) & 0x20) && !(func_8008C1B0(*(u8 *)((s8 *)arg0 + 0x63)) & 0xFF)) return 0;
            *(s32 *)((s8 *)arg0 + 0x24) |= 0x100000;
        } else {
            *(s32 *)((s8 *)arg0 + 0x24) &= 0xFFEFFFFF;
        }
        if (*(u16 *)arg1 & 1) sp10 = (func_80095638() & 0xFFFF) % sp10;
        if (sp10 != 0xFFFF) {
            s1 = *(u32 *)((s8 *)arg1 + 4) >> 8;
            if (s1 & 0xFF) func_800957A8(&sp10);
            else func_800957B8(&sp10, arg0);
            if (s1 & 0xFF) {
                *(u32 *)((s8 *)arg0 + 0x9C) = *(u32 *)((s8 *)arg0 + 0xA4) + sp10;
            } else {
                a0 = *(u32 *)((s8 *)arg0 + 0xA0) + sp10;
                *(u32 *)((s8 *)arg0 + 0x9C) = a0;
                if (*(u32 *)((s8 *)arg0 + 0xA4) >= a0) {
                    *(u32 *)((s8 *)arg0 + 0xA0) = a0;
                    *(u32 *)((s8 *)arg0 + 0x9C) = 0;
                }
            }
        } else {
            *(u32 *)((s8 *)arg0 + 0x9C) = -1;
        }
        return *(u32 *)((s8 *)arg0 + 0x9C) != 0;
    }
    return 0;
}
