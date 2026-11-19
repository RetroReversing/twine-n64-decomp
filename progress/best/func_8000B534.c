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

extern u16 *D_80109A50;

s32 func_8000B534(void) {
    u16 *p;
    s32 n;
    s32 sum;
    u8 *q;
    u16 flags;

    p = D_80109A50;
    sum = 0;
    if (!(*p & 8)) {
        do {
            n = *(s32 *) ((u8 *) p + 4);
            flags = *p;
            q = (u8 *) p + n;
            p = (u16 *) (q + 0x10);
            if (flags & 2) {/*__repair_loop_weight*/do {
                sum += n;} while (0);
            }
        } while (!(*(u16 *) (q + 0x10) & 8));
    }
    return sum;
}
