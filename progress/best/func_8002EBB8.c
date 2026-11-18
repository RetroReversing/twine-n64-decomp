/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */
#ifndef M2C_DEFINES
#define M2C_DEFINES
typedef s32 M2C_UNK;
typedef s8 M2C_UNK8;
typedef s16 M2C_UNK16;
typedef s32 M2C_UNK32;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define M2C_CARRY 0
#define M2C_OVERFLOW(a) (0)
#endif

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

void *func_8002EBB8(s16 arg0) {
    s16 *var_a1;
    char *var_a2;
    char *var_a3;
    s32 temp_a0;
    s32 temp_a0_2;
    s32 temp_s0;
    s32 temp_v1;
    s32 temp_v1_2;
    s32 var_s0;
    void *temp_a1;
    void *temp_a1_2;
    void *temp_a1_3;
    void *temp_s1;
    void *temp_t0;
    void *temp_v0;
    void *temp_v0_2;
    void *temp_v0_3;
    void *temp_v0_4;
    void *var_a2_2;

    temp_v0 = func_80016410(0x48, 0, 0);
    if (temp_v0 == NULL) {
        return NULL;
    }
    M2C_FIELD(temp_v0, s16 *, 0x78) = 0x39;
    M2C_FIELD(temp_v0, s16 *, 0x7A) = (s16) ((D_80102EDE != 0) * 4);
    func_8000A310();
    func_8000A5D0(0xC);
    func_80064318(temp_v0, arg0 & 0xFFFF);
    temp_s1 = M2C_FIELD(temp_v0, void **, 0x6C);
    M2C_FIELD(temp_s1, void **, 0) = NULL;
    M2C_FIELD(temp_s1, void **, 0x30) = NULL;
    M2C_FIELD(temp_s1, s32 *, 0x28) = 0;
    M2C_FIELD(temp_s1, void **, 0x2C) = NULL;
    M2C_FIELD(temp_s1, s16 *, 0x44) = arg0;
    M2C_FIELD(temp_s1, void **, 0x34) = NULL;
    M2C_FIELD(temp_s1, s16 *, 0x40) = 0;
    M2C_FIELD(temp_s1, s16 *, 0x42) = 0;
    M2C_FIELD(temp_s1, void **, 0x38) = NULL;
    M2C_FIELD(temp_s1, void **, 0x3C) = NULL;
    D_800BFDDC = arg0;
    var_a3 = &D_800BFD74;
    M2C_FIELD(temp_s1, void **, 0x3C) = func_80015F74(&D_800BFDDC - 0x20);
    D_800BFD70 = arg0;
    var_a2 = ((D_800BFC92 & 1) * 0x24) + D_800BFD08;
    temp_t0 = var_a2 + 0x20;
    do {
        M2C_FIELD(var_a3, s32 *, 0) = M2C_FIELD(var_a2, s32 *, 0);
        M2C_FIELD(var_a3, s32 *, 4) = (s32) M2C_FIELD(var_a2, s32 *, 4);
        M2C_FIELD(var_a3, s32 *, 8) = (s32) M2C_FIELD(var_a2, s32 *, 8);
        M2C_FIELD(var_a3, s32 *, 0xC) = (s32) M2C_FIELD(var_a2, s32 *, 0xC);
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
    M2C_FIELD(temp_s1, void **, 0x2C) = func_80015F74(var_a1, var_a1, var_a2, var_a3);
    D_800BFD04 = arg0;
    temp_v0_2 = func_80015F74(&D_800BFD04 - 0x20);
    M2C_FIELD(temp_s1, void **, 0x34) = temp_v0_2;
    temp_a0 = M2C_FIELD(temp_v0_2, s32 *, 8);
    var_s0 = 0;
    if (temp_a0 != 0) {
        memset(temp_a0, 0, M2C_FIELD(temp_v0_2, u16 *, 0x24) * M2C_FIELD(temp_v0_2, u8 *, 0x28));
        var_s0 = 0;
    }
    do {
        temp_v0_3 = func_800162BC(arg0 & 0xFFFF);
        temp_a0_2 = var_s0 & 0xFFFF;
        var_a2_2 = (temp_a0_2 * 4) + temp_s1;
        M2C_FIELD(var_a2_2, void **, 4) = temp_v0_3;
        if (temp_v0_3 != NULL) {
            M2C_FIELD(temp_v0_3, void **, 0x18) = (void *) ((temp_a0_2 * 0xC) + D_800E1590);
            M2C_FIELD(M2C_FIELD(var_a2_2, void **, 4), s16 *, 0x1C) = 0xB;
            temp_a1 = M2C_FIELD(var_a2_2, void **, 4);
            M2C_FIELD(temp_a1, s32 *, 0x28) = (s32) ((M2C_FIELD(temp_a1, s32 *, 0x28) & ~0xFC) | 0x14);
            temp_a1_2 = M2C_FIELD(var_a2_2, void **, 4);
            temp_v1 = 0x100 - (temp_a0_2 * temp_a0_2 * 2);
            if (temp_v1 >= 0) {
                if (temp_v1 < 0x100) {
                    M2C_FIELD(temp_a1_2, s32 *, 0x10) = (s32) ((temp_v1 << 8) | 0x800000);
                } else {
                    M2C_FIELD(temp_a1_2, s32 *, 0x10) = 0x80FF00;
                }
            } else {
                M2C_FIELD(temp_a1_2, s32 *, 0x10) = 0x800000;
            }
            var_a2_2 = (void *) (var_s0 & 0xFFFF);
            temp_v1_2 = (s32) var_a2_2 * 4;
            temp_a1_3 = temp_v1_2 + temp_s1;
            M2C_FIELD(M2C_FIELD(temp_a1_3, void **, 4), s16 *, 0x1E) = 0x40;
            M2C_FIELD(M2C_FIELD(temp_a1_3, void **, 4), s16 *, 0x20) = 0xF0;
            M2C_FIELD(M2C_FIELD(temp_a1_3, void **, 4), s16 *, 0x22) = (s16) (((s32) (temp_v1_2 + var_a2_2) * 2) + 0x28);
        }
        func_8002E9D0(((var_s0 & 0xFFFF) * 0xC) + D_800E1590, 0xB, (s32) var_a2_2);
        var_s0 += 1;
    } while ((u32) (var_s0 & 0xFFFF) < 9U);
    D_800BFCBC = arg0;
    M2C_FIELD(temp_s1, void **, 0) = func_80015F74(&D_800BFCBC - 0x20);
    temp_v0_4 = func_80016410(0, 0, 0);
    M2C_FIELD(temp_s1, void **, 0x30) = temp_v0_4;
    if (temp_v0_4 != NULL) {
        M2C_FIELD(temp_v0_4, s16 *, 0x78) = 0x1F;
        M2C_FIELD(M2C_FIELD(temp_s1, void **, 0x30), s16 *, 0x7A) = 0;
        M2C_FIELD(M2C_FIELD(temp_s1, void **, 0x30), f32 *, 0x24) = 4.1f;
        M2C_FIELD(M2C_FIELD(temp_s1, void **, 0x30), f32 *, 0x28) = -3.5f;
        M2C_FIELD(M2C_FIELD(temp_s1, void **, 0x30), f32 *, 0x2C) = -9.0f;
        M2C_FIELD(M2C_FIELD(temp_s1, void **, 0x30), f32 *, 0x44) = -284.44446f;
        M2C_FIELD(M2C_FIELD(temp_s1, void **, 0x30), s8 *, 0x7F) = 0;
        M2C_FIELD(M2C_FIELD(temp_s1, void **, 0x30), s8 *, 0x80) = 0;
        M2C_FIELD(M2C_FIELD(temp_s1, void **, 0x30), s8 *, 0x81) = 0;
        M2C_FIELD(M2C_FIELD(temp_s1, void **, 0x30), f32 *, 0x54) = 0.95f;
        func_80044670(M2C_FIELD(temp_s1, void **, 0x30), 2, 0x24);
        temp_s0 = arg0 & 0xFFFF;
        func_80064318(M2C_FIELD(temp_s1, void **, 0x30), temp_s0);
        func_80016990(M2C_FIELD(temp_s1, void **, 0x30), M2C_FIELD(*(D_80109688 + (temp_s0 * 4)), s32 *, 0xF4));
        D_800BFCE0 = arg0;
        M2C_FIELD(temp_s1, void **, 0x38) = func_80015F74(&D_800BFCE0 - 0x20);
        func_8002B000(D_800E1584, 0x1E);
    }
    return temp_v0;
}
