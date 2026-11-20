typedef struct { s32 data; u16 id; u16 ref; } E97704;
extern s32 D_800F3950;
extern E97704 D_800F3954[];
void func_8008C0D4(void);
void func_8008C11C(void);

s32 func_80097704(u16 arg0) {
    s32 i, j;

    func_8008C0D4();
    for (i = 0; i < D_800F3950; i++) {
        if (D_800F3954[i].id == arg0) {
            break;
        }
    }
    if (i != D_800F3950) {
        if (--D_800F3954[i].ref == 0) {
            for (j = i + 1; j < D_800F3950; j++) {
                D_800F3954[j - 1] = D_800F3954[j];
            }
            D_800F3950--;
            func_8008C11C();
            return 1;
        }
    }
    func_8008C11C();
    return 0;
}
