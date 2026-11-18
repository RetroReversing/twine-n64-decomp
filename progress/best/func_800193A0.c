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

s32 func_800261A4();
void *func_800262A8();
s8 func_800263B8();
s32 func_8003099C();
s32 func_80030C58();
extern u8 D_800BD9CC;
extern u8 D_80102EE0;
extern u8 D_80102EE8;
extern void *D_80109BB0;
extern u8 D_80112F6E;
extern char D_801176C7[];

void func_800193A0(void) {
    u8 temp_v1;
    void *temp_s0;
    void *temp_s1;
    void *temp_s2;

    func_8003099C(D_80102EE0, D_80102EE8);
    temp_s0 = func_800262A8(M2C_FIELD(D_80109BB0, s32 *, 0x10), 0x72);
    D_800BD9CC = D_80102EE8;
    if (temp_s0 != NULL) {
        M2C_FIELD(temp_s0, u16 *, 0xC) &= 0xFFF0;
        M2C_FIELD(temp_s0, u16 *, 0x34) &= 0xFFF0;
        M2C_FIELD(temp_s0, u16 *, 0x5C) &= 0xFFF0;
        M2C_FIELD(temp_s0, s8 *, 0x27) = func_800263B8(M2C_FIELD(D_80109BB0, s32 *, 0x10), 0x73);
        M2C_FIELD(temp_s0, s8 *, 0x4F) = func_800263B8(M2C_FIELD(D_80109BB0, s32 *, 0x10), 0x74);
        M2C_FIELD(temp_s0, s8 *, 0x77) = func_800263B8(M2C_FIELD(D_80109BB0, s32 *, 0x10), 0x72);
        M2C_FIELD(temp_s0, s8 *, 0x26) = func_800263B8(M2C_FIELD(D_80109BB0, s32 *, 0x10), 0x74);
        M2C_FIELD(temp_s0, s8 *, 0x4E) = func_800263B8(M2C_FIELD(D_80109BB0, s32 *, 0x10), 0x72);
        M2C_FIELD(temp_s0, s8 *, 0x76) = func_800263B8(M2C_FIELD(D_80109BB0, s32 *, 0x10), 0x73);
        temp_s1 = temp_s0 + 0x28;
        temp_s2 = temp_s0 + 0x50;
        if ((func_80030C58() != 2) && (D_80112F6E == 0)) {
            temp_v1 = *(D_801176C7 + (func_800261A4(func_80030C58()) & 0xFFFF));
            switch (temp_v1) {                      /* irregular */
            case 0:
                M2C_FIELD(temp_s0, s8 *, 0x27) = func_800263B8(M2C_FIELD(D_80109BB0, s32 *, 0x10), 0x72);
                M2C_FIELD(temp_s0, s8 *, 0x26) = func_800263B8(M2C_FIELD(D_80109BB0, s32 *, 0x10), 0x72);
                M2C_FIELD(temp_s0, u16 *, 0x34) |= 0xD;
                M2C_FIELD(temp_s0, u16 *, 0x5C) |= 0xD;
                break;
            case 1:
                M2C_FIELD(temp_s0, s8 *, 0x27) = func_800263B8(M2C_FIELD(D_80109BB0, s32 *, 0x10), 0x73);
                M2C_FIELD(temp_s0, s8 *, 0x4F) = func_800263B8(M2C_FIELD(D_80109BB0, s32 *, 0x10), 0x72);
                M2C_FIELD(temp_s0, s8 *, 0x26) = func_800263B8(M2C_FIELD(D_80109BB0, s32 *, 0x10), 0x73);
                M2C_FIELD(temp_s0, s8 *, 0x4E) = func_800263B8(M2C_FIELD(D_80109BB0, s32 *, 0x10), 0x72);
                M2C_FIELD(temp_s0, u16 *, 0x5C) |= 0xD;
                break;
            default:
                M2C_FIELD(temp_s0, s8 *, 0x27) = func_800263B8(M2C_FIELD(D_80109BB0, s32 *, 0x10), 0x73);
                M2C_FIELD(temp_s1, s8 *, 0x27) = func_800263B8(M2C_FIELD(D_80109BB0, s32 *, 0x10), 0x74);
                M2C_FIELD(temp_s2, s8 *, 0x27) = func_800263B8(M2C_FIELD(D_80109BB0, s32 *, 0x10), 0x72);
                M2C_FIELD(temp_s0, s8 *, 0x26) = func_800263B8(M2C_FIELD(D_80109BB0, s32 *, 0x10), 0x74);
                M2C_FIELD(temp_s1, s8 *, 0x26) = func_800263B8(M2C_FIELD(D_80109BB0, s32 *, 0x10), 0x72);
                M2C_FIELD(temp_s2, s8 *, 0x26) = func_800263B8(M2C_FIELD(D_80109BB0, s32 *, 0x10), 0x73);
                break;
            }
            D_800BD9CC = *(D_801176C7 + (func_800261A4(func_80030C58()) & 0xFFFF));
        }
    }
}
