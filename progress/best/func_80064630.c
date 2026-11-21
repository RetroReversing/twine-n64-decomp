extern u8 D_80112F6C;
extern u8 D_800C7C16[];
extern u8 D_800C46A1[];
extern u8 D_800C471E[];
extern u16 D_800C469C;
extern s32 func_800645A4(s32);

void func_80064630(void *arg0) {
    u8 *obj = (u8 *)arg0;
    u8 *record = *(u8 **)(obj + 0x6C);
    u8 *flag = &D_80112F6C;
    u32 i;
    s32 off;

    for (i = 0, off = 0; i < 32; i++, off += 4) {
        u16 value = 0;
        if (*flag != 0) {
            value = *(u16 *)(D_800C7C16 + off);
        }
        *(u16 *)(record + 0x1BC + i * 2) = value;
    }

    {
        s32 idx = 0;
        s32 dataOff = 0;
        s32 recOff = 0;
        u8 *entry = record;
        for (;;) {
            if (*flag != 0) {
                entry[0x1FC] = D_800C46A1[dataOff];
                entry[0x1FF] = D_800C471E[dataOff];
            } else {
                entry[0x1FC] = 0;
                entry[0x1FF] = 0;
            }
            if ((*(u16 *)((u8 *)&D_800C469C + dataOff) & 0x8000) == 0) {
                *(u8 *)(record + recOff + 0x1FC) = 0;
            }
            {
                u8 *p = record + recOff;
                recOff += 8;
                entry += 8;
                idx++;
                p[0x1FD] = 0;
                p[0x1FE] = 0;
                *(f32 *)(p + 0x200) = (f32)(func_800645A4(idx - 1) & 0xFF);
            }
            if (idx >= 0x3B) break;
            dataOff += 0xE8;
        }
    }
    record[0x1FC] = 1;
    record[0x32C] = 0;
    record[0x324] = 0;
    if (*flag == 0) record[0x1FC] = 1;
}
