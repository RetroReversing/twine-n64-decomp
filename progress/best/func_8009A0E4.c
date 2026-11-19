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

s32 func_800968A4();
s32 func_80099CA8();
extern char D_801007D9[];
extern char D_80100C7C[];

s32 func_8009A0E4(void *arg0, u32 *arg1) {
    char *__base_D_801007D9;
    s32 temp_v0;
    s32 temp_v1;
    
    u16 var_v1;
    
    u32 temp_a0;
    u8 temp_a1;
    u8 temp_v0_2;
    s32 var_v0_2;
    u8 var_v1_3;

    temp_a0 = *arg1;
    if ((temp_a0 >> 0x18) == 0) {
        var_v1 = M2C_FIELD(arg0, u16 *, 0x50);
    } else {
        var_v1 = M2C_FIELD(arg0, u16 *, 0x4E);
    }
    M2C_FIELD(arg0, u16 *, 0x50) = (u16) (var_v1 + ((s32) (temp_a0 << 0x10) >> 0x18));
    temp_v0 = (s16) M2C_FIELD(arg0, u16 *, 0x50);
    if (temp_v0 >= 0) {
        if ((u32) temp_v0 >= 0x80U) {
            var_v1 = 0x7F;
            goto block_9;
        }
        M2C_FIELD(arg0, u16 *, 0x50) = (u16) temp_v0;
    } else {
        var_v1 = 0;
block_9:
        M2C_FIELD(arg0, u16 *, 0x50) = var_v1;
    }
    temp_v1 = M2C_FIELD(arg0, s32 *, 0x60);
    M2C_FIELD(arg0, s8 *, 0xC0) = (s8) (u16) *arg1;
    if (temp_v1 != -1) {
        temp_a1 = M2C_FIELD(arg0, u8 *, 0x4A);
        temp_v0 = 0;
        if (temp_a1 != 0xFF) {
            temp_v0_2 = M2C_FIELD(arg0, u8 *, 0x4B);
            if (temp_v0_2 == 0xFF) {
                var_v1_3 = temp_v1 & 0xFF;
                var_v0_2 = *(D_80100C7C + var_v1_3);
            } else {
                __base_D_801007D9 = D_801007D9;
                var_v1_3 = *((temp_v0_2 * 0x10) + __base_D_801007D9 + temp_a1);
                var_v0_2 = temp_v1 & 0xFF;
            }
            temp_v0 = 0;
            if (var_v1_3 == var_v0_2) {
                temp_v0 = 1;
            }
        }
    } else {
        temp_v0 = 0;
    }
    if (temp_v0 & 0xFF) {
        func_800968A4(M2C_FIELD(arg0, u8 *, 0x4A), M2C_FIELD(arg0, u8 *, 0x4B), M2C_FIELD(arg0, u8 *, 0x51));
    }
    *arg1 = 4;
    return func_80099CA8(arg0, arg1) & 0xFF;
}
