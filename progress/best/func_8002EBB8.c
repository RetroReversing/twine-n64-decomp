/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

s32 func_8000A310();
s32 func_8000A5D0();
void *func_80015F74();
void *func_800162BC();
void *func_80016410();
s32 func_80016990();
s32 func_8002B000();
s32 func_8002E9D0();
s32 func_80044670();
s32 func_80064318();
s32 memset();
extern u16 D_800BFC92;
extern s16 D_800BFCBC;
extern s16 D_800BFCE0;
extern s16 D_800BFD04;
extern char D_800BFD08[];
extern s16 D_800BFD70;
extern s32 D_800BFD74;
extern s16 D_800BFD94;
extern s16 D_800BFDB8;
extern s16 D_800BFDDC;
extern char D_800E1584[];
extern char D_800E1590[];
extern u8 D_80102EDE;
extern char D_80109688[];

void *func_8002EBB8(s32 arg0) {
    s32 __repair_store_0;
    s32 __repair_store_1;
    s32 __repair_store_2;
    s32 __repair_store_3;
    s16 *var_a1;
    char *var_a2;
    char *var_a3;
    s32 temp_a0;
    s32 temp_a0_2;
    s32 temp_s0;
    int temp_v1;
    s32 temp_v1_2;
    void *temp_a1;
    
    void *temp_a1_3;
    void *temp_s1;
    void *temp_t0;
    void *temp_v0;
    void *temp_v0_2;
    
    void *temp_v0_4;
    void *var_a2_2;

    temp_v0 = func_80016410(0x48, 0, 0);
    if (temp_v0 == NULL) {
        return NULL;
    }
    (*(s16 *)((char *)(temp_v0) + 0x78)) = 0x39;
    (*(s16 *)((char *)(temp_v0) + 0x7A)) = (s16) ((D_80102EDE != 0) * 4);
    func_8000A310();
    func_8000A5D0(0xC);
    func_80064318(temp_v0, arg0 & 0xFFFF);
    temp_s1 = (*(void **)((char *)(temp_v0) + 0x6C));
    (*(void **)((char *)(temp_s1) + 0)) = NULL;
    (*(void **)((char *)(temp_s1) + 0x30)) = NULL;
    (*(s32 *)((char *)(temp_s1) + 0x28)) = 0;
    (*(void **)((char *)(temp_s1) + 0x2C)) = NULL;
    (*(s16 *)((char *)(temp_s1) + 0x44)) = arg0;
    (*(void **)((char *)(temp_s1) + 0x34)) = NULL;
    (*(s16 *)((char *)(temp_s1) + 0x40)) = 0;
    (*(s16 *)((char *)(temp_s1) + 0x42)) = 0;
    (*(void **)((char *)(temp_s1) + 0x38)) = NULL;
    (*(void **)((char *)(temp_s1) + 0x3C)) = NULL;
    *((s16 *)((char *)&D_800BFDDC - 0x20)) = arg0;
    (*(void **)((char *)(temp_s1) + 0x3C)) = func_80015F74((s16 *)((char *)&D_800BFDDC - 0x20));
    var_a3 = &D_800BFD74;
    D_800BFD70 = arg0;
    var_a2 = ((D_800BFC92 & 1) * 0x24) + D_800BFD08;
    temp_t0 = var_a2 + 0x20;
    do {
        __repair_store_0 = (*(s32 *)((char *)(var_a2) + 0));
        __repair_store_1 = (s32) (*(s32 *)((char *)(var_a2) + 4));
        __repair_store_2 = (s32) (*(s32 *)((char *)(var_a2) + 8));
        __repair_store_3 = (s32) (*(s32 *)((char *)(var_a2) + 0xC));
        (*(s32 *)((char *)(var_a3) + 0)) = __repair_store_0;
        (*(s32 *)((char *)(var_a3) + 4)) = __repair_store_1;
        (*(s32 *)((char *)(var_a3) + 8)) = __repair_store_2;
        (*(s32 *)((char *)(var_a3) + 0xC)) = __repair_store_3;
        var_a2 += 0x10;
        var_a3 += 0x10;
    } while (var_a2 != temp_t0);
    *(s32 *)var_a3 = *(s32 *)var_a2;
    D_800BFD94 = arg0;
    D_800BFDB8 = arg0;
    D_800BFC92 += 1;
    var_a1 = &D_800BFD94 - 0x20;
    if (D_80102EDE != 0) {
        var_a1 = D_800BFD94 + 4;
    }
    (*(void **)((char *)(temp_s1) + 0x2C)) = func_80015F74(var_a1, var_a1, var_a2, var_a3);
    *((s16 *)((char *)&D_800BFD04 - 0x20)) = arg0;
    temp_v0_2 = func_80015F74((s16 *)((char *)&D_800BFD04 - 0x20));
    (*(void **)((char *)(temp_s1) + 0x34)) = temp_v0_2;
    temp_a0 = (*(s32 *)((char *)(temp_v0_2) + 8));
    if (temp_a0 != 0) {
        memset(temp_a0, 0, (*(u16 *)((char *)(temp_v0_2) + 0x24)) * (*(u8 *)((char *)(temp_v0_2) + 0x28)));
    }
    {
        u16 __repair_i;
        for (__repair_i = 0; __repair_i < 9; __repair_i++) {
            temp_v0_2 = func_800162BC(arg0 & 0xFFFF);
            temp_a0_2 = __repair_i;
            var_a2_2 = (temp_a0_2 * 4) + temp_s1;
            (*(void **)((char *)(var_a2_2) + 4)) = temp_v0_2;
            if (temp_v0_2 != NULL) {
            (*(void **)((char *)(temp_v0_2) + 0x18)) = (void *) ((temp_a0_2 * 0xC) + D_800E1590);
            (*(s16 *)((char *)((*(void **)((char *)(var_a2_2) + 4))) + 0x1C)) = 0xB;
            temp_a1 = (*(void **)((char *)(var_a2_2) + 4));
            (*(s32 *)((char *)(temp_a1) + 0x28)) = (s32) (((*(s32 *)((char *)(temp_a1) + 0x28)) & ~0xFC) | 0x14);
            temp_a1 = (*(void **)((char *)(var_a2_2) + 4));
            temp_v1 = 0x100 - (temp_a0_2 * temp_a0_2 * 2);
            if (temp_v1 >= 0) {
            if (temp_v1 < 0x100) {
            (*(s32 *)((char *)(temp_a1) + 0x10)) = (s32) ((temp_v1 << 8) | 0x800000);
            } else {
            (*(s32 *)((char *)(temp_a1) + 0x10)) = 0x80FF00;
            }
            } else {
            (*(s32 *)((char *)(temp_a1) + 0x10)) = 0x800000;
            }
            var_a2_2 = (void *) __repair_i;
            temp_v1_2 = (s32) var_a2_2 * 4;
            temp_a1_3 = temp_v1_2 + temp_s1;
            (*(s16 *)((char *)((*(void **)((char *)(temp_a1_3) + 4))) + 0x1E)) = 0x40;
            (*(s16 *)((char *)((*(void **)((char *)(temp_a1_3) + 4))) + 0x20)) = 0xF0;
            (*(s16 *)((char *)((*(void **)((char *)(temp_a1_3) + 4))) + 0x22)) = (s16) (((s32) (temp_v1_2 + var_a2_2) * 2) + 0x28);
            }
            func_8002E9D0((__repair_i * 0xC) + D_800E1590, 0xB, (s32) var_a2_2);
        }
    }
    D_800BFCBC = (s32)arg0;
    (*(void **)((char *)(temp_s1) + 0)) = func_80015F74((s16 *)((char *)&D_800BFCBC - 0x20));
    temp_v0_4 = func_80016410(0, 0, 0);
    (*(void **)((char *)(temp_s1) + 0x30)) = temp_v0_4;
    if (temp_v0_4 != NULL) {
        (*(s16 *)((char *)(temp_v0_4) + 0x78)) = 0x1F;
        (*(s16 *)((char *)((*(void **)((char *)(temp_s1) + 0x30))) + 0x7A)) = 0;
        (*(f32 *)((char *)((*(void **)((char *)(temp_s1) + 0x30))) + 0x24)) = 4.1f;
        (*(f32 *)((char *)((*(void **)((char *)(temp_s1) + 0x30))) + 0x28)) = -3.5f;
        (*(f32 *)((char *)((*(void **)((char *)(temp_s1) + 0x30))) + 0x2C)) = -9.0f;
        (*(f32 *)((char *)((*(void **)((char *)(temp_s1) + 0x30))) + 0x44)) = -284.44446f;
        (*(s8 *)((char *)((*(void **)((char *)(temp_s1) + 0x30))) + 0x7F)) = 0;
        (*(s8 *)((char *)((*(void **)((char *)(temp_s1) + 0x30))) + 0x80)) = 0;
        (*(s8 *)((char *)((*(void **)((char *)(temp_s1) + 0x30))) + 0x81)) = 0;
        (*(f32 *)((char *)((*(void **)((char *)(temp_s1) + 0x30))) + 0x54)) = 0.95f;
        func_80044670((*(void **)((char *)(temp_s1) + 0x30)), 2, 0x24);
        temp_s0 = arg0 & 0xFFFF;
        func_80064318((*(void **)((char *)(temp_s1) + 0x30)), temp_s0);
        func_80016990((*(void **)((char *)(temp_s1) + 0x30)), (*(s32 *)((char *)(*(s32 *)(D_80109688 + (temp_s0 * 4))) + 0xF4)));
        *((s16 *)((char *)&D_800BFCE0 - 0x20)) = arg0;
        (*(void **)((char *)(temp_s1) + 0x38)) = func_80015F74((s16 *)((char *)&D_800BFCE0 - 0x20));
        func_8002B000(D_800E1584, 0x1E);
    }
    return temp_v0;
}
