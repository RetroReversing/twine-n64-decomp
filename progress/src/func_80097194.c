/* identical to func_80097704 (matched), with its names changed by decompdecomp */
typedef struct { s32 data; u16 id; u16 ref; } E97704;
extern s32 D_800F7954;
extern E97704 D_800F7958[];
void func_8008C0D4(void);
void func_8008C11C(void);

s32 func_80097194(u16 arg0) {
    s32 i, j;

    func_8008C0D4();
    for (i = 0; i < D_800F7954; i++) {
        if (D_800F7958[i].id == arg0) {
            break;
        }
    }
    if (i != D_800F7954) {
        if (--D_800F7958[i].ref == 0) {
            for (j = i + 1; j < D_800F7954; j++) {
                D_800F7958[j - 1] = D_800F7958[j];
            }
            D_800F7954--;
            func_8008C11C();
            return 1;
        }
    }
    func_8008C11C();
    return 0;
}
