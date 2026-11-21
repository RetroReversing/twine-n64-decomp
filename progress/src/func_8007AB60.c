s32 func_80002BD0();
s32 randomIntBelow();
s32 func_80077960();
s32 func_80077ED8();
extern char sEnemyDefTable[];
extern u16 D_800C9BD0[];
extern u16 D_800C9BE0[];
extern u16 D_800C9BE4[];
extern u16 D_800C9BF0[];
extern u16 D_800C9BF4[];

s32 func_8007AB60(void *arg0) {
    u16 *tbl;
    s32 n;
    u8 *a1;
    u8 *a2;
    s32 sel;

    a2 = *(u8 **)((u8 *)arg0 + 0x6C);
    a1 = (u8 *)sEnemyDefTable + *(s8 *)(*(u8 **)((u8 *)arg0 + 0x68) + 0xE) * 0xE8;
    switch (*(s16 *)((u8 *)arg0 + 0x7C)) {
    case 0:
    case 3:
        if (*(s32 *)(a2 + 0x88) & 0x40000000) {
            switch (a1[0x6E]) {
            case 0:
                func_80002BD0(arg0, D_800C9BE0[randomIntBelow(1)]);
                func_80077960(arg0, 0x81);
                return 1;
            case 1:
                func_80002BD0(arg0, D_800C9BF0[randomIntBelow(1)]);
                func_80077960(arg0, 0x81);
                return 1;
            case 2:
                func_80002BD0(arg0, D_800C9BF4[randomIntBelow(5)]);
                func_80077960(arg0, 0x81);
                return 1;
            default:
                func_80002BD0(arg0, 0x129);
                func_80077960(arg0, 4);
                return 1;
            }
        }
        func_80077ED8(arg0);
        return 1;
    case 1:
        if (*(s32 *)((u8 *)arg0 + 0x58) & 4) {
            switch (a1[0x6E]) {
            case 0:
                func_80002BD0(arg0, D_800C9BE0[randomIntBelow(1)]);
                func_80077960(arg0, 4);
                return 1;
            case 1:
                return 0;
            case 2:
                sel = a2[0x81];
                if (sel == 0 || (u8)sel != 1) {
                    tbl = D_800C9BD0;
                    n = 8;
                } else {
                    tbl = D_800C9BE4;
                    n = 5;
                }
                func_80002BD0(arg0, tbl[randomIntBelow(n)]);
                func_80077960(arg0, 4);
                return 1;
            default:
                return 0;
            }
        }
        return 0;
    case 2:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    default:
        return 0;
    }
}
