void func_80085A08(void);
void func_80085A88(void);
void func_80085B08(void);
void func_80085B88(void);
void func_80085C08(void);
void func_80085C88(void);
void func_80085D88(void);

void func_80085D90(s32 arg0, s32 arg1) {
    switch (arg1) {
    default:
    case 1:
    case 9:
        func_80085A08();
        break;
    case 2:
        func_80085A88();
        break;
    case 3:
        func_80085B08();
        break;
    case 4:
    case 8:
        func_80085B88();
        break;
    case 5:
        func_80085C08();
        break;
    case 6:
        func_80085C88();
        break;
    case 7:
        func_80085D88();
        break;
    }
}
