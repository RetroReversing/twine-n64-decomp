/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O1, tried by autopilot */
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

extern char gTrackMarkerDone[];

void func_8005E304(void *arg0) {
    u8 * __repair_hoisted;

    s32 temp_v1;
    u8 temp_v1_2;

    temp_v1 = M2C_FIELD(arg0, s32 *, 0x60);
    __repair_hoisted = M2C_FIELD(arg0, u8 **, 0x6C);
    if (temp_v1 & 0x400000) {
        M2C_FIELD(arg0, s32 *, 0x60) = (s32) (temp_v1 & 0xFFBFFFFF);
        temp_v1_2 = *__repair_hoisted;
        if (temp_v1_2 != 0) {
            *(gTrackMarkerDone + temp_v1_2) = 1;
        }
    }
}
