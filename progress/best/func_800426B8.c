extern u8 D_54D910[];
extern s32 D_800C0780[];
extern s32 D_800C0784[];
extern s32 D_800C0788[];
extern s32 D_800C078C[];
extern f32 D_800E19E0, D_800E19E4, D_800E19E8;
extern u8 D_80107ECC;
extern s16 D_80108400;
extern s8 D_80109A35;
extern s32 func_80083E24(void);
extern s32 func_80083E90(s32, s32);
extern void func_80083E44(s32);
extern void func_80084048(s32, s32);
extern void func_800134C0(void);
extern void func_800134C8(void);
extern void func_80041F68(void *);
extern void func_800411C0(s32, void *, s8, u8);
extern s32 func_8001499C(void *);
extern void func_80014A0C(void *, void *);
extern void func_8000B9B8(u8 *, s32, u32);
extern void *memset(void *, int, u32);
extern void *memcpy(void *, const void *, u32);

void func_800426B8(s32 arg0, s32 arg1, u8 arg2) {
    s32 off = arg1 * 16;
    s32 *obj;
    s32 *records;
    s32 count;
    s32 i;
    s32 maxA = 0, maxB = 0, maxC = 0, maxD = 0;
    s32 maxE = 0;
    s32 allocId;
    s32 header;
    s32 a, b, c, d, e, f, g, h;
    u8 scratch[0x20];
    s32 *record;
    s32 *data;
    if (D_800C0784[arg1] != 0) return;
    allocId = func_80083E24();
    obj = (s32 *)func_80083E90(0x30, 0x17);
    func_800134C0();
    count = D_800C078C[arg1];
    records = (s32 *)func_80083E90(count * 0x4C, 0xA);
    D_800C0788[arg1] = (s32)records;
    memset(records, 0, count * 0x4C);
    func_8000B9B8((u8 *)obj, (s32)(D_54D910 + D_800C0780[arg1]), 0x30);
    D_800C0784[arg1] = (s32)obj;
    count = obj[1];
    data = (s32 *)func_80083E90(count * 0x44, 0x2D);
    func_8000B9B8((u8 *)data, (s32)(D_54D910 + obj[0]), obj[1] * 0x44);
    D_800E19E8 = 0.0f; D_800E19E4 = 0.0f; D_800E19E0 = 0.0f;
    func_80041F68(obj);
    record = data;
    for (i = 0; i < count; i++, record = (s32 *)((u8 *)record + 0x44)) {
        func_8000B9B8(scratch, (s32)(D_54D910 + record[9]), 0x20);
        if (maxA < *(u16 *)(scratch + 4)) maxA = *(u16 *)(scratch + 4);
        if (maxB < *(u16 *)(scratch + 12)) maxB = *(u16 *)(scratch + 12);
        if (maxC < *(u16 *)(scratch + 20)) maxC = *(u16 *)(scratch + 20);
        if (maxD < *(u16 *)(scratch + 28)) maxD = *(u16 *)(scratch + 28);
        if (maxE < *(u16 *)((u8 *)record + 2)) maxE = *(u16 *)((u8 *)record + 2);
    }
    a = func_80083E90(maxD, 0x2D);
    b = func_80083E90(maxD * 3, 0x2D);
    c = func_80083E90(maxA * 12, 0x2D);
    d = func_80083E90(maxA * 12, 0x2D);
    e = func_80083E90(maxB * 4, 0x2D);
    f = func_80083E90(maxC * 4, 0x2D);
    g = func_80083E90(*(u16 *)(scratch + 0x16) * 4, 0x2D);
    h = func_80083E90(*(u16 *)(scratch + 0x16) * 4, 0x2D);
    record = data;
    for (i = 0; i < count; i++, record = (s32 *)((u8 *)record + 0x44)) {
        s32 *slot = records + (*(s16 *)(D_54D910 + record[1]) * 0x10); /* placeholder */
        (void)slot;
    }
    func_80084048(a, 0x2D); func_80084048(b, 0x2D);
    func_80084048(c, 0x2D); func_80084048(d, 0x2D);
    func_80084048(e, 0x2D); func_80084048(f, 0x2D);
    func_80084048(g, 0x2D); func_80084048(h, 0x2D);
    func_800134C8();
    func_80084048((s32)data, 0x2D);
    func_80083E44(allocId);
}
