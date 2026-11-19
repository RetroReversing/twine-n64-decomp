/* Partial candidate from function #30064772288 in project #7; rechecked locally. */
extern char D_80112DC8[];
extern char D_800CFE78[];

typedef struct Ring {
    long unk4;
    s32 *unk0;
    unsigned int unk8;
    s32 unkC;
    s32 unk10;
    s32 *unk14;
} Ring;

s32 func_800A798C();
void func_800A7944();

void func_800A774C(s32 arg0) {
    u8 *base = D_80112DC8;
    Ring *r = *(Ring **)(base + arg0);
    s32 idx;
    u32 ret;
    s32 cnt;

    if (r != NULL) {
        cnt = r->unk8;
        if (cnt < r->unk10) {
            idx = (r->unkC + cnt) % r->unk10;
            r->unk14[idx] = *(s32 *)(base + arg0 + 4);
            r->unk8 = cnt + 1;
            if (*r->unk0 != 0) {
                ret = func_800A798C(arg0, r);
                func_800A7944(D_800CFE78);
            }
        }
    }
}
