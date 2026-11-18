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

void *func_80083E90();
extern s32 D_80107ED0;
extern char D_80109EA0[];
extern s32 D_8010A510;

void func_800326BC(void *arg0) {
    s16 temp_lo;
    s32 temp_s1;
    s32 temp_s2;
    void *temp_v0;

    temp_s2 = M2C_FIELD(arg0, u16 *, 2) + 1;
    temp_s1 = M2C_FIELD(arg0, u16 *, 4) + 1;
    temp_v0 = func_80083E90(0x10, 0x20);
    *(D_80109EA0 + (D_80107ED0 * 4)) = temp_v0;
    temp_lo = temp_s2 * temp_s1;
    M2C_FIELD(temp_v0, s32 *, 0) = (s32) (D_8010A510 + 4);
    M2C_FIELD(temp_v0, s8 *, 8) = 0;
    M2C_FIELD(temp_v0, s8 *, 0xA) = 0;
    M2C_FIELD(temp_v0, s32 *, 4) = (s32) M2C_FIELD(arg0, s32 *, 8);
    M2C_FIELD(temp_v0, u8 *, 9) = (u8) M2C_FIELD(arg0, u8 *, 6);
    M2C_FIELD(temp_v0, u8 *, 0xB) = (u8) M2C_FIELD(arg0, u8 *, 7);
    M2C_FIELD(temp_v0, s16 *, 0xC) = temp_lo;
    if (!(M2C_FIELD(arg0, u8 *, 0) & 1)) {
        M2C_FIELD(temp_v0, s16 *, 0xC) = (s16) ((u32) (temp_lo & 0xFFFF) >> 1);
    }
    D_80107ED0 += 1;
}
