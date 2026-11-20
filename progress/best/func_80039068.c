extern s32 osPiStartDma(u8 *, s32, s32, s32, s32, s32, s32);
extern u8 D_800DD7B8[], D_80102CA0[];
extern u16 D_8010018A, D_8010018C;
typedef struct { s32 length, device, destination; } DmaEntry;
extern DmaEntry *D_80100190;

s32 func_8000B5E0(void) {
    u16 *cursor = &D_8010018C;
    u16 index = *cursor;
    s32 next = index + 1;
    DmaEntry *entry;
    s32 destination, length;
    s32 result;

    if (index >= D_8010018A) {
        result = 0;
    } else {
        *cursor = next;
        entry = D_80100190 + (u16)next;
        destination = entry[-1].destination;
        length = D_80100190[*cursor - 1].length;
        osPiStartDma(D_800DD7B8, 0, 0, entry[-1].device, destination, length, (s32)D_80102CA0);
        result = 1;
    }
    return result;
}

extern void func_8001A4F4(void);
extern void func_80026004(void *, const char *, ...);
extern void *func_8002638C(void *, s32);
extern const char *func_80087100(s32);
extern s8 D_800BD690;
extern u8 D_800BDA68[];
extern u8 D_801002A2;
extern u8 *D_80109BB0;
extern const char D_800D2864[];

void func_8001A434(void) {
    u8 *base;
    const char *format;
    const char *text;
    u8 *object = func_8002638C(D_800BDA68, 0x92);

    D_800BD690 = 1;
    if (object != NULL) {
        D_80109BB0[0x2F] = 1;
        D_80109BB0[0x2D] = 1;
        func_8001A4F4();
        base = &D_801002A2;
        D_80109BB0[0x2F] = 0;
        text = func_80087100(*base + 0x16D);
        format = D_800D2864;
        func_80026004(object, format, text);
        text = func_80087100(*base + 0x177);
        func_80026004(object + 0x28, format, text);
    }
}

extern u32 *volatile D_80115328;
extern u8 *D_80117728;
extern s32 D_800E1710;

void func_80039068(void) {
    u32 matrixLoad = 0xDA380007U;
    u32 matrixMultiply = 0xDA380005U;
    u32 *out = D_80115328;
    s32 index = D_800E1710;
    u8 *state = D_80117728;
    u32 segmentOffset = 0x80000040U;
    u32 physicalBias = 0x80000000U;
    u32 matrix, parameter;
    u16 count;

    out[0] = matrixLoad;
    out[1] = (u32)(state + (index << 6)) - physicalBias;
    out[2] = matrixMultiply;
    matrix = *(u32 *)(state + 0x74C);
    out[4] = 0xDC080008U;
    out[5] = (u32)(state + ((index << 4) + 0x300));
    out[6] = 0xDB0E0000U;
    parameter = matrix + segmentOffset;
    out[3] = parameter;
    count = *(u16 *)(state + index * 2 + 0x360);
    D_80115328 = out + 2;
    D_80115328 = out + 4;
    D_80115328 = out + 6;
    D_80115328 = out + 8;
    out[7] = count;
}

extern u32 D_800C2EB0;
extern s32 D_800C2EB4;

void func_80045CC4(void) {
    u32 sum = D_800C2EB0 + D_800C2EB4;
    u32 carry = sum >> 31;
    D_800C2EB0 = sum;
    D_800C2EB4 += sum + carry;
}
