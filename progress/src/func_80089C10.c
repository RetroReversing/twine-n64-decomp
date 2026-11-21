typedef struct N89C10 { struct N89C10 *next; struct N89C10 *prev; u8 *buf; s32 a, b; } N89C10;
extern N89C10 *D_800E4240;
extern u8 *D_800E4244;
extern s32 D_800E4248;
extern s32 D_800E424C;
extern N89C10 *D_800E4250;
extern void *(*gDataBankAlloc)(s32, s32);
void func_800A0170(void *, s32);

void func_80089C10(s32 arg0) {
    s32 i;
    void *(**alloc)(s32, s32) = &gDataBankAlloc;
    s32 size;

    D_800E4240 = (*alloc)(arg0 * sizeof(N89C10), 0);
    size = arg0 << 8;
    D_800E4244 = (*alloc)(size, 0);
    func_800A0170(D_800E4244, size);
    D_800E424C = 0;
    D_800E4250 = D_800E4240;
    D_800E4240[0].buf = D_800E4244;
    D_800E4240[0].prev = NULL;
    for (i = 1; i < arg0; i++) {
        D_800E4240[i].prev = &D_800E4240[i - 1];
        D_800E4240[i].buf = D_800E4244 + i * 0x100;
        D_800E4240[i - 1].next = &D_800E4240[i];
    }
    D_800E4248 = 0;
    D_800E4240[i - 1].next = NULL;
}
