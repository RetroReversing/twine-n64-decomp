typedef struct N9 { struct N9 *next; struct N9 *prev; s32 pad[4]; } N9;
typedef struct S9 { u8 a; u8 b; u8 pad[0xFF6]; } S9;
extern N9 D_800E42C0[];
extern N9 *gFreeSndNodeList;
extern S9 D_800E6A84[];
extern s32 D_800EDA90;

void func_800926E8(void) {
    u32 i;
    s32 j;
    N9 *prev;
    N9 *cur;

    for (i = 0; i < 8; i++) {
        D_800E6A84[i].a = 0;
        D_800E6A84[i].b = 1;
    }
    prev = NULL;
    gFreeSndNodeList = D_800E42C0;
    j = 0;
    cur = D_800E42C0;
    for (; j < 0x100; j++) {
        D_800E42C0[j].prev = prev;
        if (prev != NULL) {
            prev->next = cur;
        }
        prev = cur;
        cur++;
    }
    prev->next = NULL;
    D_800EDA90 = 0;
}
