extern void ***func_8002A920(void *, s8);
extern char *func_80087100(s32);
extern char *func_800AB950(char *, char *);
extern s16 D_800BFC30;
extern s32 D_80107EA8;
extern char D_800D2AC0[];
s32 func_80024EF0(s32 arg0) {
    u8 i = 0;
    s32 mode = arg0 & 0xfff;
    void ***p;
    void **q;
    char *name;
    do {
        p = func_8002A920(&D_80107EA8, i);
        if (p && (q = *p) && *(char **)((char *)*q + 0x18)) {
            switch (mode) {
            case 1:
                if (D_800BFC30 != -1) return (u8)D_800BFC30;
                return 0;
            case 2:
                name = func_80087100(0x3004);
                if (func_800AB950(*(char **)((char *)*q + 0x18), name)) return i;
                if (func_800AB950(*(char **)((char *)*q + 0x18), D_800D2AC0)) return i;
                break;
            case 3:
                name = func_80087100(0x3004);
                if (func_800AB950(*(char **)((char *)*q + 0x18), name)) {
                    i++;
                    goto check_next;
                }
                return i;
            }
        }
        i++;
check_next:
        ;
    } while (i < 16);
    return 0;
}
