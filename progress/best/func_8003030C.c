/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

s32 func_80015F74();
void *func_80016410();
s32 func_80064318();
extern u8 D_800BFDE8;
extern s16 D_800BFE00;
extern s8 D_800BFE0C;
extern s16 D_800BFE24;
extern char D_800BFE28[];
extern char D_800BFE48[];
extern char D_800BFEB8[];
extern char D_800BFED8[];
extern s32 D_80102ED8;

void *func_8003030C(s16 arg0) {
    s32 var_s1_2;
    unsigned temp_v0_3;
    s32 var_s0;
    s32 var_s0_2;
    s32 var_s1;
    void *temp_s0_2;
    void *temp_s0;
    register s32 temp_v0_2;
    void *temp_s2;
    void *temp_v0;

    temp_v0 = func_80016410(0x28, 0, 0);
    if (temp_v0 == NULL) {
        return NULL;
    }
    (*(s16 *)((char *)(temp_v0) + 0x78)) = 0x37;
    (*(s16 *)((char *)(temp_v0) + 0x7A)) = 0;
    func_80064318(temp_v0, arg0 & 0xFFFF);
    temp_s2 = (*(void **)((char *)(temp_v0) + 0x6C));
    var_s1 = 0;
    (*(s32 *)((char *)(temp_s2) + 4)) = 0;
    (*(s32 *)((char *)(temp_s2) + 8)) = 0;
    (*(s32 *)((char *)(temp_s2) + (short)0xC)) = 0;
    var_s0 = 0 & 0xFFFF;
    do {
        temp_v0_2 = var_s0 * 0x24;
        temp_s0 = (char *)(((int)var_s0 * 4)); temp_s0 += (s32)(temp_s2);
        (*(s32 *)((char *)(temp_s0) + 0x10)) = 0;
        *(u16 *)(D_800BFE48 + temp_v0_2) = arg0;
        (*(s32 *)((char *)(temp_s0) + 0x10)) = func_80015F74(temp_v0_2 + D_800BFE28);
        var_s0 = var_s1 & 0xFFFF;
        ++var_s1;
    } while ((u32) (var_s1 & 0xFFFF) < 4U);
    var_s1_2 = 0;
    var_s0_2 = 0 & 0xFFFF;
    do {
        temp_v0_2 = var_s0_2 * 0x24;
        temp_s0_2 = (char *)((var_s0_2 * 4)); temp_s0_2 += (s32)(temp_s2);
        (*(s32 *)((char *)(temp_s0_2) + 0x20)) = 0;
        *(u16 *)(D_800BFED8 + temp_v0_2) = arg0;
        (*(s32 *)((char *)(temp_s0_2) + 0x20)) = func_80015F74(temp_v0_2 + D_800BFEB8);/*__repair_loop_weight*/do {
        var_s1_2 += 1;} while (0);
        var_s0_2 = var_s1_2 & 0xFFFF;
    } while ((u32) (var_s1_2 & 0xFFFF) < 2U);
    D_800BFE24 = arg0;
    D_800BFE0C = (D_800BFE0C & 0x1FFFFFFF) | (((-(D_80102ED8 == 0) & 5) | 4) << 0x1D);
    (*(s32 *)((char *)(temp_s2) + 0xC)) = func_80015F74(&D_800BFE0C - 8, &D_800BFE0C);
    D_800BFE00 = arg0;
    D_800BFDE8 = (D_800BFDE8 & 0x1FFFFFFF) | (((-(D_80102ED8 == 0) & 5) | 4) << 0x1D);
    (*(s32 *)((char *)(temp_s2) + 4)) = func_80015F74(&D_800BFDE8 - 8, &D_800BFDE8);
    return temp_v0;
}
