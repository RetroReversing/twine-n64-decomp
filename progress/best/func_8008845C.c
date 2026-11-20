extern u8 D_800CEEC0, D_800E2CC0[];
extern char D_800E2CE4[];
s32 func_8008845C(s32 key) {
    if (D_800CEEC0) {
        u32 i = 0;
        s32 offset = 0;
        s32 found;
        do {
            if (D_800E2CC0[offset] && *(s32 *)(D_800E2CE4 + offset) == key) {
                found = i;
                goto test;
            }
            offset += 0x1228;
        } while (++i < 2);
        found = -1;
test:
        if (found != -1) return D_800E2CC0[found * 0x1228] != 0;
    }
    return 0;
}

extern s32 func_80018364(s32, u16);
extern s32 *func_80018510(u32);
s32 func_800184AC(s32 arg0, s32 arg1, u32 arg2) {
    s32 scale = func_80018364(arg0, arg1);
    s32 *record = func_80018510(arg2);
    s32 reduced = scale - 1;
    s32 clamped = 0x7D00;
    s32 value;
    if ((u32)reduced <= 0x7D00U) clamped = reduced;
    value = *((u8 *)record[2] + 0x148);
    return clamped * (value + 3) + value;
}

extern s32 D_800E06B8[];
extern s32 D_800E06F8;
void func_8000A724(s32 value) {
    u32 index;
    s32 *base;
    s32 remaining;
    if (value != -1) {
        index = D_800E06F8;
        remaining = 15;
        base = D_800E06B8;
        do {
            if (base[index] == -1) break;
            index = (index + 1) & 15;
        } while (remaining--);
        base[index] = value;
        D_800E06F8 = (index + 1) & 15;
    }
}

typedef struct { u8 pad[0x18]; char *buffer; u8 pad1c[0x11]; u8 active; } MenuText;
extern MenuText *D_80109BB0;
extern u8 D_8010A4FD;
extern char D_800D2AA0[];
extern void func_80029068(void);
extern char *func_80087100(s32);
extern void func_80026004(void *, s32, ...);
void func_800223E4(void) {
    s32 id;
    char *text;
    func_80029068();
    if (D_80109BB0->active) {
        id = 0x67;
        if (D_8010A4FD) id = 0x68;
        text = func_80087100(id);
        func_80026004(D_80109BB0->buffer + 0x28, (s32)D_800D2AA0, text);
    }
}
