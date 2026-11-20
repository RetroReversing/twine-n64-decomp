typedef struct { u16 key; s16 state; u8 pad[0x18]; } N97814;
typedef struct { N97814 *list; s32 arg; u16 count; } Slot97814;
extern s32 D_800F38EC;
extern Slot97814 D_800F38F0[];
void func_8008C0D4(void);
void func_8008C11C(N97814 *, u16);

s32 func_80097814(N97814 *arg0, s32 arg1) {
    s32 i;
    u16 n;
    u16 j;
    N97814 *p;

    for (i = 0; i < D_800F38EC; i++) {
        if (D_800F38F0[i].list == arg0) {
            break;
        }
    }
    if (i != D_800F38EC) {
        return 1;
    }
    if (i < 8) {
    n = 0;
    for (p = arg0; p->key != 0xFFFF; p++) {
        n++;
    }
    func_8008C0D4();
    p = arg0;
    D_800F38F0[D_800F38EC].list = p;
    D_800F38F0[D_800F38EC].count = n;
    D_800F38F0[D_800F38EC].arg = arg1;
    for (j = 0; j < n; j++, p++) {
        p->state = 0;
    }
    D_800F38EC++;
    func_8008C11C(p, j);
    return 1;
    }
    return 0;
}
