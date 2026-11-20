static __inline__ u8 __repair_inline(u8 a) { return a; }
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

s32 func_800312F4();
f32 Vec3_DistanceSq();
s32 func_800707B4();
s32 func_80074C34();
extern s32 D_800C7EE4;
extern char D_800C7EE8[];
extern u8 D_800C7EE9[];
extern char D_800C7EEC[];
extern u8 D_800CEEB0;
extern void *D_8010A500;
extern u8 D_80115091[];
extern s32 func_801188B4;

typedef struct { unsigned char pad_0[96]; int field_60; unsigned char pad_64[24]; short field_7C; } __repair_record_arg0;
void func_8007514C(void *arg0) {
    char *__base_D_800C7EEC;
    s32 temp_a0;
    s32 temp_v1_2;
    s32 var_a0;
    s32 var_s0;
    s32 var_v0;
    u8 temp_v0;
    u8 temp_v1;
    void *temp_s2;
    f32 threshold;

    if ((D_800CEEB0 == 0) && (D_8010A500 != NULL)) {
        temp_v1 = __repair_inline(*(D_800C7EE8 + (((__repair_record_arg0*)arg0)->field_7C * 0xC)));
        threshold = 3.0f;
        temp_s2 = M2C_FIELD(D_8010A500, void **, 0x6C);
        var_s0 = 0;
        switch (temp_v1) {
case 0: case 3: goto block_12;
                          /* switch 1 */
        case 1:                                     /* switch 1 */
            if ((func_800707B4(temp_s2, 2, 1) << 0x18) != 0) {
                var_s0 = 1;
                if (M2C_FIELD(&func_801188B4, s8 *, 0x9F) != 0) {
                default:                            /* switch 1 */
block_12:
                    var_v0 = var_s0;
block_13:
                    if ((var_s0 != 0) || (Vec3_DistanceSq(arg0 + 0x24, D_8010A500 + 0x24) < threshold)) {
                        temp_v0 = *(D_80115091 + (M2C_FIELD(temp_s2, s8 *, 0x182) * 0xA0));
                        switch (temp_v0) {          /* switch 2 */
                        case 2: case 4: case 6:
                        default:                    /* switch 2 */
                            var_a0 = 0;
                            break;
                        case 1:                     /* switch 2 */
                        case 3:                     /* switch 2 */
                        case 5:                     /* switch 2 */
                        case 7:                     /* switch 2 */
                            var_a0 = 1;
                            break;
                        }
                        temp_v1_2 = ((__repair_record_arg0*)arg0)->field_7C * 0xC;
                        if (*(D_800C7EE9 + temp_v1_2) == 0) {
                            *(D_800C7EE9 + temp_v1_2) = 1;
                            __base_D_800C7EEC = D_800C7EEC;
                            if (*(s32 *)((temp_a0 = var_a0 * 4) + ((((__repair_record_arg0*)arg0)->field_7C * 0xC) + __base_D_800C7EEC)) >= 0) {
                                D_800C7EE4 = 1;
                            }
                            func_80074C34(0, *(s32 *)(temp_a0 + ((((__repair_record_arg0*)arg0)->field_7C * 0xC) + __base_D_800C7EEC)), 1);
                            D_800C7EE4 = 2;
                        }
                        ((__repair_record_arg0*)arg0)->field_60 |= 1;
                    }
                }
            }
            break;
        case 2:                                     /* switch 1 */
            var_v0 = 0;
            if (func_800312F4(2, 0) != 3) {
                goto block_13;
            }
            break;
        case 4:                                     /* switch 1 */
            var_s0 = 1;
            if (M2C_FIELD(temp_s2, u8 *, 0x23C) != 0) {
                goto block_12;
            }
            break;
        case 5:                                     /* switch 1 */
            var_s0 = 1;
            if (M2C_FIELD(M2C_FIELD(D_8010A500, void **, 0x68), s8 *, 0xE) == 0x29) {
                goto block_12;
            }
            break;
        }
    }
}
