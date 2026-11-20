void func_80001D80(s32 arg0);
void func_8000C8BC(s32 arg0);
void func_8000C97C(void);
void func_8000CF14(s32 arg0);
void func_8000DBBC(s32 arg0);
void func_80064780(s32 arg0);
void func_80084048(void *arg0, s32 arg1);
extern void *gObjectTable;
extern s8 D_800B2715;
extern s8 D_800E0742;
extern u8 D_800E0746;
extern void *gTrackMarkerTable;
extern void *D_80109690;
extern u8 D_8010A4C1;
extern u8 D_8010A4C2;
extern s32 D_8010A500;

void func_8000CA3C(void) {
    void **base;
    s32 temp_s1;
    s32 var_a0;
    s32 var_v0;
    register long var_v0_2;

    temp_s1 = *(s16 *)((char *)gObjectTable + 0x10);
    if (D_800E0742 != 0) {
        base = &D_80109690;
        func_80084048(*base, 0xE);
        *base = NULL;
        func_80084048(*(void **)((char *)gObjectTable + 4), 0x33);
        func_80084048(gObjectTable, 0x33);
        func_8000CF14(1);
    }
    {
        u8 *p = &D_8010A4C1;
        *p |= 1;
    }
    D_8010A4C2 |= 1;
    *(s32 *)((char *)gTrackMarkerTable + 0x100) &= ~0x100;
    func_80001D80(0);
    gObjectTable = NULL;
    if (temp_s1 == 0x26 && D_8010A500) {
        func_80064780(D_8010A500);
    }
    var_v0_2 = temp_s1 != 0x20;
    var_a0 = -var_v0_2 | 0x1C;
    if (temp_s1 == 0x1C) {
        var_a0 = 0x1D;
    }
    if (temp_s1 == 0xA) {
        var_a0 = 0xB;
    }
    if (temp_s1 == 0x11) {
        var_a0 = 0x13;
    }
    if (temp_s1 == 5) {
        var_a0 = 0x33;
    }
    if ((D_800E0746 != 0) && (!D_800B2715)) {
        func_8000C8BC(temp_s1);
        return;
    }
    if (var_a0 >= 0) {
        if (!D_800B2715) {
            func_8000C8BC(var_a0);
            return;
        }
        if (var_a0 != 0x13) {
            func_8000DBBC(8);
        }
        goto block_22;
    }
block_22:
    func_8000C97C();
}

