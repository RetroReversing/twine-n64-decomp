extern void func_80027E00(void);
extern void func_80027E88(void);
extern void func_80027EB4(void);
extern void func_80027EF4(void);
extern void func_80027F44(void);
extern void func_80027FF4(void);
extern void func_80028158(void);
extern void func_800281E0(void);
extern void func_800282D0(void);
extern void func_800283B0(void);
extern void func_80028458(void);
extern void func_80028530(void);
extern void func_800285D4(void);
extern void func_80028770(void);
extern void func_800287DC(void);
extern void func_80028A7C(void);
extern void func_80028E6C(void);
extern void func_80028EC8(void);
extern void func_80028F90(void);
extern u8 D_800BD68E;
extern u8 D_800BD68F;
extern u8 D_800BD691;
extern void *sActiveMenu;
extern void *D_80109BB0;

void func_80027260(void *arg0) {
    s32 temp_a1;
    void *temp_v1;

    if (!(*(s32 *)((u8 *)arg0 + 0x60) & 1)) {
        temp_v1 = *(void **)((u8 *)arg0 + 0x6C);
        temp_a1 = *(s16 *)((u8 *)arg0 + 0x7A);
        D_800BD68F = *(u8 *)((u8 *)temp_v1 + 4);
        D_800BD691 = *(u8 *)((u8 *)temp_v1 + 5);
        D_800BD68E = *(u8 *)((u8 *)temp_v1 + 6);
        sActiveMenu = arg0;
        D_80109BB0 = temp_v1;
        switch (temp_a1) {
        case 0:
            func_80027E00();
            break;
        case 17:
            func_80027E88();
            break;
        case 12:
            func_80028530();
            break;
        case 16:
            func_80027EB4();
            break;
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
            func_80027F44();
            break;
        case 1:
            func_80027EF4();
            break;
        case 9:
            func_80027FF4();
            break;
        case 11:
            func_80028458();
            break;
        case 13:
            func_80028158();
            break;
        case 14:
            func_800282D0();
            break;
        case 15:
            func_800283B0();
            break;
        case 10:
            func_800281E0();
            break;
        case 20:
            func_800285D4();
            break;
        case 21:
            func_80028770();
            break;
        case 22:
            func_800287DC();
            break;
        case 23:
            func_80028A7C();
            break;
        case 24:
            func_80028E6C();
            break;
        case 19:
            func_80028EC8();
            break;
        case 18:
            func_80028F90();
            break;
        }
    }
}
