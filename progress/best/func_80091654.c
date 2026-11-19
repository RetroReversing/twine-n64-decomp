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

s32 func_8008EB80();
extern char D_800E5AC4[];
extern char D_800E5FEC[];
extern char D_800E6A85[];
extern char D_800E6A88[];
extern char D_800E6AA4[];
extern char D_800E6AB2[];
extern char D_800E6AB4[];

void func_80091654(s8 arg0, s32 arg1, s32 arg2, s32 arg3) {
    
    s32 temp_a3;
    s32 temp_s0;
    s32 var_a2;
    s32 var_v0;
    s32 var_v1;
    s8 var_v1_2;
    u32 var_s0;
    char *var_s0_2;
    u8 temp_a2;
    union { void * pointer; s32 value; } __repair_phase_storage;
    

    var_s0_2 = D_800E5AC4;

    var_s0 = 0;
    var_v1 = 0;
loop_1:
    if ((*(D_800E6A85 + var_v1) != 0) || (*(s32 *)(var_s0_2 + var_v1) != (arg2 & 0x7FFFFFFF))) {
        var_s0 += 1;
        var_v1 += 0xFF8;
        if (var_s0 >= 8U) {
            var_a2 = -1;
        } else {
            goto loop_1;
        }
    } else {
        var_a2 = var_s0 | (arg2 & 0x80000000);
    }
    if (var_a2 != -1) {
        if (var_a2 >= 0) {
            temp_s0 = var_a2 * 0xFF8;
            func_8008EB80(arg0 & 0xFF, arg1 & 0xFFFF, *(D_800E6A88 + temp_s0), arg3 & 0xFF, arg2);
            var_s0_2 = temp_s0 + D_800E5FEC;
            __repair_phase_storage.pointer = var_s0_2 + 0x40;
loop_8:
            temp_a2 = *(u8 *)var_s0_2;
            if (temp_a2 != *(D_800E6A88 + temp_s0)) {
                func_8008EB80(arg0 & 0xFF, arg1 & 0xFFFF, temp_a2, 0, 0);
            }
            var_s0_2 += 1;
            if ((u32) var_s0_2 < (u32) __repair_phase_storage.pointer) {
                goto loop_8;
            }
        } else {
            __repair_phase_storage.value = var_a2 & 0x7FFFFFFF;
            temp_a3 = arg3 & 0xF;
            switch (temp_a3) {                      /* irregular */
            case 0:
                *(D_800E6AA4 + (__repair_phase_storage.value * 0xFF8)) = arg0;
                return;
            case 1:
                *(s32 *)(D_800E6AB4 + (__repair_phase_storage.value * 0xFF8)) = 0;
                return;
            case 2:
                var_v0 = __repair_phase_storage.value * 0xFF8;
                *(D_800E6AA4 + var_v0) = arg0;
                var_v1_2 = *(D_800E6AB2 + var_v0) | 8;
                *(D_800E6AB2 + var_v0) = var_v1_2;
                break;
            case 3:
                var_v0 = __repair_phase_storage.value * 0xFF8;
                *(D_800E6AA4 + var_v0) = arg0;
                var_v1_2 = *(D_800E6AB2 + var_v0) | 0x80;
                *(D_800E6AB2 + var_v0) = var_v1_2;
                break;
            }
        }
    }
}
