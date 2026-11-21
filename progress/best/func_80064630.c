extern u8 D_80112F6C;
extern u8 D_800C7C16[];
extern u8 D_800C46A1[];
extern u8 D_800C471E[];
extern u16 sEnemyDefTable;
extern s32 func_800645A4(s32);

typedef struct Ent { u8 a, b, c, d; f32 f; } Ent;
typedef struct Rec { u8 pad[0x1BC]; u16 w[32]; Ent e[0x3B]; } Rec;

void func_80064630(void *arg0) {
    Rec *rec = *(Rec **)((u8 *)arg0 + 0x6C);
    u8 *record = (u8 *)rec;
    u32 i;
    s32 off;
    s32 dataOff;
    s32 recOff;

    for (i = 0, off = 0; i < 32; i++, off += 4) {
        if (D_80112F6C != 0) {
            rec->w[i] = *(u16 *)(D_800C7C16 + off);
        } else {
            rec->w[i] = 0;
        }
    }
    i = 0; dataOff = 0; recOff = 0;
    do {
        Ent *p;
        if (D_80112F6C != 0) {
            rec->e[i].a = D_800C46A1[dataOff];
            rec->e[i].d = D_800C471E[dataOff];
        } else {
            rec->e[i].a = 0;
            rec->e[i].d = 0;
        }
        if ((*(u16 *)((u8 *)&sEnemyDefTable + dataOff) & 0x8000) == 0) {
            record[recOff + 0x1FC] = 0;
        }
        p = (Ent *)(record + recOff + 0x1FC);
        dataOff += 0xE8;
        recOff += 8;
        i++;
        p->b = 0;
        p->c = 0;
        p->f = (f32)(func_800645A4(i - 1) & 0xFF);
    } while (i < 0x3B);
    record[0x1FC] = 1;
    record[0x32C] = 0;
    record[0x324] = 0;
    if (D_80112F6C != 0) record[0x1FC] = 1;
}
