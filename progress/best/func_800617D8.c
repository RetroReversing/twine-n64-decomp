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

void *func_80016410();
s32 func_80016990();
s32 func_8003E6EC();
s32 func_80044670();
s32 func_80045278();
extern s32 *D_800CA31C;

typedef struct { unsigned char pad_0[84]; float field_54; unsigned char pad_58[20]; void * field_6C; unsigned char pad_70[8]; short field_78; unsigned char pad_7A[5]; signed char field_7F; signed char field_80; signed char field_81; signed char field_82; } __repair_record_temp_v0;
void *func_800617D8(s32 arg0, s32 arg1, s32 arg2, void *arg3, f32 arg4, f32 arg5, s32 arg6, s32 arg7, s32 arg8, u32 arg9, u32 arg10) {
    s32 __repair_store_0;
    s32 __repair_store_1;
    s32 __repair_store_2;
    void *temp_s1;
    void *temp_v0;

    if (arg0 == 0) {
        return NULL;
    }
    temp_v0 = func_80016410(0x2C);
    if (temp_v0 != NULL) {
        temp_s1 = ((__repair_record_temp_v0*)temp_v0)->field_6C;
        if (arg3 == NULL) {
            func_80045278(temp_s1);
        } else {
            __repair_store_0 = (s32) M2C_FIELD(arg3, s32 *, 0);
            __repair_store_1 = (s32) M2C_FIELD(arg3, s32 *, 4);
            __repair_store_2 = (s32) M2C_FIELD(arg3, s32 *, 8);
            M2C_FIELD(temp_s1, s32 *, 0) = __repair_store_0;
            M2C_FIELD(temp_s1, s32 *, 4) = __repair_store_1;
            M2C_FIELD(temp_s1, s32 *, 8) = __repair_store_2;
        }
        ((__repair_record_temp_v0*)temp_v0)->field_78 = (s16) arg8;
        ((__repair_record_temp_v0*)temp_v0)->field_54 = arg4;
        M2C_FIELD(temp_s1, f32 *, 0x14) = arg5;
        ((__repair_record_temp_v0*)temp_v0)->field_7F = (s8) (arg9 >> 0x18);
        ((__repair_record_temp_v0*)temp_v0)->field_80 = (s8) (arg9 >> 0x10);
        ((__repair_record_temp_v0*)temp_v0)->field_81 = (s8) (arg9 >> 8);
        ((__repair_record_temp_v0*)temp_v0)->field_82 = (s8) arg9;
        M2C_FIELD(temp_s1, s8 *, 0x23) = (s8) ((arg10 >> 0x18) + 0x80);
        M2C_FIELD(temp_s1, s8 *, 0x24) = (s8) ((arg10 >> 0x10) + 0x80);
        M2C_FIELD(temp_s1, s8 *, 0x25) = (s8) ((arg10 >> 8) + 0x80);
        M2C_FIELD(temp_s1, s8 *, 0x26) = (s8) arg10;
        func_80044670(temp_v0, arg6, arg7);
        if (arg0 != 0) {
            func_80016990(temp_v0, arg0);
            return temp_v0;
        }
        do { func_8003E6EC(*D_800CA31C, temp_v0, 1); } while (0);
        goto block_9;
    }
block_9:
    return temp_v0;
}
