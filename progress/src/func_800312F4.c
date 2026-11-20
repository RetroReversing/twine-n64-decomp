extern int func_8003090C(short);
extern char *D_800BFF04;
int func_800312F4(short a, unsigned short b) {
    short index;
    unsigned short flags;
    int type;
    if (b == 1) index = func_8003090C(a);
    else index = a - 1;
    if (index < 0) return 3;
    flags = *(unsigned short *)(D_800BFF04 + index * 8 + 2);
    if (flags & 0x200) return 3;
    type = flags & 15;
    if (type == 0) return 0;
    if (type == 2) return 2;
    return 1;
}
