extern unsigned char D_801002A2, D_80112F82, D_80112F83, D_80112F84;
extern unsigned char *D_80109BB0;
extern int D_800BDA68;
extern const char D_800D2864[];
extern void func_80029068(void);
extern int func_8002638C(int, int);
extern int func_80027CE0(int);
extern int func_80087100(int);
extern void func_80026004(void *, int, ...);

void func_8001D204(void) {
    char *item;
    char *second;
    unsigned char *index;
    int name;
    const char *format;

    if (D_80109BB0[0x2F] == 0)
        func_80029068();
    if (D_80109BB0[0x2D] == 0)
        goto clear;
    item = (char *)func_8002638C((int)&D_800BDA68, 0x92);
    if (item == 0)
        return;
    second = item + 0x28;
    index = &D_801002A2;
    switch (*index) {
    case 7:
        if (D_80112F82 == 0) {
            D_80109BB0[0x2F] = 1;
            if ((unsigned char)func_80027CE0(0x21))
                ++*index;
            else
                --*index;
            func_8001D204();
        }
        break;
    case 8:
        if (D_80112F83 == 0) {
            D_80109BB0[0x2F] = 1;
            if ((unsigned char)func_80027CE0(0x21))
                ++*index;
            else
                --*index;
            func_8001D204();
        }
        break;
    case 9:
        if (D_80112F84 == 0) {
            D_80109BB0[0x2F] = 1;
            if ((unsigned char)func_80027CE0(0x21))
                *index = 0;
            else
                --*index;
            func_8001D204();
        }
        break;
    }
    index = &D_801002A2;
    name = func_80087100(*index + 0x16D);
    format = D_800D2864;
    func_80026004(item, (int)format, name);
    func_80026004(second, (int)format, func_80087100(*index + 0x177));
clear:
    D_80109BB0[0x2F] = 0;
}
