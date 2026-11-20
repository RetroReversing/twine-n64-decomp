static __inline__ int __repair_inline(s32 a, s32 b) { return a < b; }
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

s32 func_80022DBC();
void *func_80087100();
s32 sprintf(char *, const char *, ...);
extern char D_800D2AB4[], D_800D2ABC[];
extern s16 D_800E1068[];
extern s16 D_800E107E;
extern s16 D_800E1080;
extern char D_801001A4[];
extern u8 D_801002A0;
extern u8 D_801002A1;
extern u8 D_801002AC;
extern s32 D_801002B4;
extern void *D_80102CD0;

void *func_80023BD4(void) {
    s32 var_a0;
    s32 temp_a0;
    s16 temp_v0_3;
    s32 var_s1;
    s32 temp_v0_2;
    
    s32 var_s0;
    s32 var_s0_2;
    s32 var_s0_3;
    s32 var_s1_2;
    s32 var_s1_3;
    s32 var_s3;
    void **var_s2;
    void *temp_s0;
    void *temp_s5;
    union { void * pointer; s32 value; } __repair_phase_storage;
    void *var_a2;
    void *var_v0;

    if (D_801002AC == 0) {
        return func_80087100(3);
    }
    var_s1 = -0x270F;
    temp_s5 = func_80087100(0x4000);
    if (D_801002A1 != 0) {
        if (D_800E107E > D_800E1080) {
            var_a0 = 0x6E;
            goto block_6;
        }
        if (D_800E107E < D_800E1080) {
var_a0 = 0x6F;
block_6:
            temp_s0 = func_80087100(var_a0);
            var_v0 = func_80087100(0xEE);
            var_a2 = temp_s0;
            {
        sprintf(temp_s5, D_800D2AB4, var_a2);return temp_s5;}
        }
        goto block_7;
    }
    var_s3 = 0;
    if (D_801002A0 == 8) {
        var_s1_2 = 0;
        var_s0 = 0;
        if (D_801002B4 > 0) {
            var_s2 = &D_80102CD0;
            do {
                __repair_phase_storage.pointer = *var_s2;
                if ((__repair_phase_storage.pointer != NULL) && (M2C_FIELD(M2C_FIELD(__repair_phase_storage.pointer, void **, 0xB4), u8 *, 0x11) != 0)) {
                    var_s1_2 += 1;
                } else {
                    var_s3 = func_80022DBC(var_s0 & 0xFFFF) & 0xFFFF;
                }
                var_s0 += 1;
                var_s2 += 1;
            } while (var_s0 < D_801002B4);
        }
        var_s1 = -0x63;
        if (var_s1_2 == (D_801002B4 - 1)) {
            var_s1_3 = 0;
        } else {
            var_s3 = 0;
            goto block_19;
        }
    } else {
block_19:
        temp_v0_2 = D_801002B4;
        var_s0_2 = 0;
        if (__repair_inline(0, temp_v0_2)) {
            do {
                __repair_phase_storage.value = func_80022DBC(var_s0_2 & 0xFFFF) & 0xFFFF;
                temp_a0 = D_800E1068[__repair_phase_storage.value];
                if (var_s1 < temp_a0) {
var_s3 = __repair_phase_storage.value; var_s1 = temp_a0;
                }
                var_s0_2 += 1;
            } while (var_s0_2 < D_801002B4);
        }
        var_s1_3 = -1;
        var_s0_3 = 0;
        if (__repair_inline(0, temp_v0_2)) {
            do {
                temp_v0_3 = D_800E1068[func_80022DBC(var_s0_3 & 0xFFFF) & 0xFFFF];
                var_s0_3 += 1;
                var_s1_3 += temp_v0_3 == *((var_s3 * 2) + D_800E1068);
            } while (var_s0_3 < D_801002B4);
        }
    }
    if (var_s1_3 <= 0) {
        var_v0 = func_80087100(0xEE);
        var_a2 = (var_s3 * 0x18) + D_801001A4;
block_30:
        sprintf(temp_s5, D_800D2AB4, var_a2, var_v0);
        return temp_s5;
    }
block_7:
    sprintf(temp_s5, D_800D2ABC, func_80087100(0xEF));
    return temp_s5;
}
