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

s32 func_80034560();
s32 func_80034928();
s32 func_80039068();
extern char D_800B1CD0[];
extern s32 D_801032A0;
extern void *D_80109CB8;
extern s32 D_8010A4D8;
extern s32 D_8010A924;
extern s32 D_80112E40;
extern void *D_80115328;
extern void *D_80117728;

typedef struct { int value; } __repair_field_0;
void func_80037C84(s32 arg0) {
    void *temp_a2;
    void *temp_v1;
    void *temp_v1_2;

    func_80034560(arg0);
    if (D_80112E40 != 2) {
        D_80112E40 = 2;
        func_80039068(arg0);
    }
    if (D_8010A924 != 6) {
        temp_v1 = D_80115328;
        D_8010A924 = 6;
        D_80115328 = temp_v1 + 8;
        ((__repair_field_0 *)temp_v1)->value = 0xDE000000;
        M2C_FIELD(temp_v1, s32 **, 4) = D_800B1CD0;
    }
    if (D_801032A0 != 2) {
        temp_v1_2 = D_80115328;
        D_801032A0 = 2;
        D_80115328 = temp_v1_2 + 8;
        ((__repair_field_0 *)temp_v1_2)->value = 0xFC419883;
        M2C_FIELD(temp_v1_2, s32 *, 4) = 0xFF32FF7F;
    }
    func_80034928(arg0, 2);
    ((__repair_field_0 *)D_80109CB8)->value = 0xDF000000;
    ((__repair_field_0 *)D_80109CB8 + 1)->value = 0;
    ((__repair_field_0 *)D_80115328)->value = 0xDE000000;
    M2C_FIELD(D_80115328, s32 *, 4) = (s32) M2C_FIELD(D_80117728, s32 *, 0x1A60);
    D_80109CB8 += 8;
    temp_a2 = D_80115328 + 8;
    D_80115328 = temp_a2;
    func_80034928(arg0, D_8010A4D8, temp_a2);
}
