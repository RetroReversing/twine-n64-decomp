#define F(p, T, off) (*(T *)((u8 *)(p) + (off)))
typedef struct { s32 w[3]; } W3;
void func_800015AC(void *, s32);
s32 func_80002BD0(void *, s32);
void func_80076C80(void *);
void func_80077960(void *, s32);
void func_800779C4(void *);
s32 func_80077E00(void *arg0);

void func_80076CE4(void *arg0) {
    u8 *st = F(arg0, u8 *, 0x6C);
    s32 s = F(st, u8, 0x7F);
    s8 r;
    s32 a1;
    void *obj;

    switch (s) {
    default: r = 0; break;
case 0: r = 0; break;

    case 5:
        r = 2;
        break;
    case 6:
        r = 0xA;
        break;
    }
    switch (F(st, u8, 0x7F)) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 10:
        F(arg0, s16, 0x7C) = F(st, u8, 0x7F);
        return;
    case 4:
        func_800779C4(arg0);
        if (F(F(arg0, u8 *, 0x68), s8, 0xE) == 0 && (F(st, s32, 0x88) & 0x01E00000) == 0x200000) {
            s32 result = r;
            F(st, u8, 0x7F) = result;
            F(arg0, s16, 0x7C) = result;
            func_80002BD0(arg0, 0x1FE);
            func_80077960(arg0, 0x3A);
            return;
        }
    case 5:
    case 6:
        func_800779C4(arg0);
        switch (F(st, u8, 0x82)) {
        default:
        case 0:
            if (F(st, u8, 0x7F) == 5) {
                F(st, u8, 0x7F) = 2;
                F(arg0, s16, 0x7C) = 2;
            } else if (F(st, u8, 0x7F) == 6) {
                F(st, u8, 0x7F) = 0xA;
                F(arg0, s16, 0x7C) = 0xA;
            } else {
                F(st, u8, 0x7F) = 0;
                F(arg0, s16, 0x7C) = 0;
            }
            func_80076C80(arg0);
            return;
        case 12:
            obj = F(st, void *, 0x40);
            F(st, s32, 0x88) |= 0x40000000;
            F(st, W3, 0x18) = F(obj, W3, 0x24);
            func_800015AC(arg0, 4);
            F(st, u8, 0x82) = 0;
            if ((s8)func_80077E00(arg0)) {
                func_80002BD0(arg0, 0x14D);
                a1 = 0xB;
            call:
                func_80077960(arg0, a1);
            }
            break;
        }
        break;
    case 11:
    case 12:
        break;
    }
}
