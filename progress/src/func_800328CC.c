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

typedef struct { short field_0; short field_2; short field_4; unsigned char pad_6[2]; int field_8; int field_C; } __repair_record_arg0;
void func_800328CC(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, f32 arg7) {
char *__repair_addr;

    void *temp_a1;

    temp_a1 = arg1 + (arg4 * 0xC);
    ((__repair_record_arg0*)arg0)->field_0 = (s16) (s32) (M2C_FIELD(temp_a1, f32 *, 0) * arg7 * 64.0f);
    ((__repair_record_arg0*)arg0)->field_2 = (s16) (s32) (M2C_FIELD(temp_a1, f32 *, 4) * arg7 * 64.0f);
    ((__repair_record_arg0*)arg0)->field_4 = (s16) (s32) (M2C_FIELD(temp_a1, f32 *, 8) * arg7 * 64.0f);
    ((__repair_record_arg0*)arg0)->field_8 = (s32) *(s32 *)((arg5 * 4) + arg3);
__repair_addr = (char *)(arg2 + (arg6 * 4));

    ((__repair_record_arg0*)arg0)->field_C = (s32) *(s32 *)(__repair_addr);
}
