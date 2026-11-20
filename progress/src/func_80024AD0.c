void func_80024D78(void);
void func_80026424(s32, s32);
s32 func_8002AF30(void *);
void func_8002CB5C(u8);
u16 func_8002CC14();
extern s16 D_800BFC32;
extern s32 D_80102F2C;
extern u8 *D_80109BB0;
extern u8 D_8010A950;

s32 func_80024AD0(u16 arg0, u8 arg1) {
    switch (arg0) {
    case 0:
        if (func_8002CC14()) {
            D_80109BB0[0x2C] = 0;
            func_80026424(D_80102F2C, 0x18);
            return 3;
        }
        D_800BFC32 = 0x10D;
        func_80026424(D_80102F2C, 0x18);
        return 0x4003;
    case 0x4000:
        if ((u8)func_8002AF30(&D_8010A950) == 1) {
            return 0x2003;
        }
        return 0x8003;
    case 0x2000:
        func_8002CB5C(arg1);
        func_80026424(D_80102F2C, 0x18);
        return 0x8003;
    case 0x8000:
        func_80024D78();
        D_80109BB0[0x2C] = 0;
        return 3;
    default:
        return 3;
    }
}
