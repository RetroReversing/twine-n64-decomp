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

typedef struct { f32 x, y, z; } Point3;

void *func_80016410();
s32 func_80016990();
s32 actorLinkToSurface();
s32 func_80044670();
s32 func_80045278();
extern s32 *gProbeObjectList;

void *func_800617D8(s32 arg0, s32 arg1, s32 arg2, Point3 *arg3, f32 arg4, f32 arg5, s32 arg6, s32 arg7, s32 arg8, u32 arg9, u32 arg10) {
    Point3 *temp_s1;
    void *temp_v0;

    if (arg0 == 0) {
        return NULL;
    }
    temp_v0 = func_80016410(0x2C, arg1, arg2);
    if (temp_v0 != NULL) {
        temp_s1 = M2C_FIELD(temp_v0, Point3 **, 0x6C);
        if (arg3 == NULL) {
            func_80045278(temp_s1);
        } else {
            *temp_s1 = *arg3;
        }
        M2C_FIELD(temp_v0, s16 *, 0x78) = (s16) arg8;
        M2C_FIELD(temp_v0, f32 *, 0x54) = arg4;
        M2C_FIELD(temp_s1, f32 *, 0x14) = arg5;
        M2C_FIELD(temp_v0, s8 *, 0x7F) = (s8) (arg9 >> 0x18);
        M2C_FIELD(temp_v0, s8 *, 0x80) = (s8) (arg9 >> 0x10);
        M2C_FIELD(temp_v0, s8 *, 0x81) = (s8) (arg9 >> 8);
        M2C_FIELD(temp_v0, s8 *, 0x82) = (s8) arg9;
        M2C_FIELD(temp_s1, s8 *, 0x23) = (s8) ((arg10 >> 0x18) + 0x80);
        M2C_FIELD(temp_s1, s8 *, 0x24) = (s8) ((arg10 >> 0x10) + 0x80);
        M2C_FIELD(temp_s1, s8 *, 0x25) = (s8) ((arg10 >> 8) + 0x80);
        M2C_FIELD(temp_s1, s8 *, 0x26) = (s8) arg10;
        func_80044670(temp_v0, arg6, arg7);
        if (arg0 != 0) {
            func_80016990(temp_v0, arg0);
            return temp_v0;
        }
        actorLinkToSurface(*gProbeObjectList, temp_v0, 1);
        goto block_9;
    }
block_9:
    return temp_v0;
}

