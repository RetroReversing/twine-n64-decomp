extern unsigned char D_801002A2, D_80112F82, D_80112F83, D_80112F84;
extern unsigned char *gMenuState;
extern int D_800BDA68;
extern const char D_800D2864[];
extern void updateActiveMenuState(void);
extern int func_8002638C(int, int);
extern int func_80027CE0(int);
extern int func_80087100(int);
extern void formatTextEntry(void *, int, ...);

void func_8001D204(void) {
  int __repair_call_argument;
    unsigned char *index;
    char *item;
    char *second;
    const char *format;
    int name;

    if (gMenuState[0x2F] == 0)
        updateActiveMenuState();
    if (gMenuState[0x2D] == 0)
        goto clear;
    item = (char *)func_8002638C((int)&D_800BDA68, 0x92);
    if (item == 0)
        return;
    index = &D_801002A2;
    second = item + 0x28;
    switch (*index) {
    case 7:
        if (D_80112F82 == 0) {
            gMenuState[0x2F] = 1;
            if ((unsigned char)func_80027CE0(0x21))
                ++*index;
            else
                --*index;
            func_8001D204();
        }
        break;
    case 8:
        if (D_80112F83 == 0) {
            gMenuState[0x2F] = 1;
            if ((unsigned char)func_80027CE0(0x21))
                ++*index;
            else
                --*index;
            func_8001D204();
        }
        break;
    case 9:
        if (D_80112F84 == 0) {
            gMenuState[0x2F] = 1;
            if ((unsigned char)func_80027CE0(0x21))
                *index = 0;
            else
                --*index;
            func_8001D204();
        }
        break;
    }
    index = &D_801002A2;
    __repair_call_argument = *index + 0x16D;
    do {
      name = func_80087100(__repair_call_argument);
    } while (0);
    format = D_800D2864;
    formatTextEntry(item, (int)format, name);
    formatTextEntry(second, (int)format, func_80087100(*index + 0x177));
clear:
    gMenuState[0x2F] = 0;
}
