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

s32 func_8000A894();
s32 func_8002B150();
f32 func_80045E34();
s32 func_800643C8();
s32 func_80073AF8();
s32 func_80087100();
s32 sprintf();
extern u8 gSceneType;
extern s32 D_8010969C;
extern char D_8011F000[];
extern char D_8011F140[];
extern u8 D_8011F168[];
extern char D_8011F170[];
extern char D_8011F280[];
extern char D_8011F288[];
extern char D_8011F298[];
extern char D_8011F2B0[];

typedef struct { s32 w[3]; } __repair_words3;
void func_8011BF0C(void *arg0) {
    s32 var_a2;
    s32 temp_a0;
    s32 temp_a0_2;
    s32 temp_a1;
    s32 temp_a2_2;
    s32 temp_a3;
    s32 temp_s0;
    s32 temp_s0_2;
    s32 temp_s1;
    s32 temp_s1_2;
    s32 temp_s4;
    s32 temp_v0;
    s32 temp_v0_5;
    s32 temp_v1;
    void **temp_a0_3;
    void *temp_a0_4;
    void *temp_a2;
    void *temp_v0_2;
    void *temp_v0_3;
    void *temp_v0_4;
    void *temp_v1_2;
    void *temp_v1_3;

    if ((gSceneType != 3) || (*(D_8011F168 + M2C_FIELD(arg0, s16 *, 0x7A)) != 0)) {
        temp_s4 = M2C_FIELD(arg0, u8 *, 0x7B) ^ 1;
        temp_s0 = temp_s4 & 0xFF;
        temp_s1 = temp_s0 * 4;
        temp_a0 = *(s32 *)(D_8011F2B0 + temp_s1);
        if ((temp_a0 != 0) && (func_80045E34(temp_a0 + 0x24, arg0 + 0x24) < 2.0f)) {
            if (*(s32 *)(D_8011F280 + temp_s1) != 0) {
                temp_s1_2 = func_80087100((-(temp_s0 == 0) & 0x6F) | 0x6E);
                temp_v0 = func_80087100(0x28D);
                var_a2 = 0xC;
                if (temp_s0 == 0) {
                    var_a2 = 5;
                }
                sprintf(D_8011F170, D_8011F000, var_a2, temp_s1_2, temp_v0);
                func_80073AF8(0, D_8010969C, D_8011F170, -1, -1, 1, 0, 0, 6, 0, 0x3C);
                func_8000A894(0x21A);
            }
            temp_a0_2 = M2C_FIELD(arg0, s16 *, 0x7A) * 8;
            func_8002B150(temp_a0_2 + D_8011F140, (*(s32 *)(D_8011F140 + temp_a0_2) + 1) & 0xFF, 0);
            temp_v1 = temp_s4 & 0xFF;
            temp_s0_2 = temp_v1 * 4;
            temp_a0_3 = temp_s0_2 + D_8011F2B0;
            temp_a2 = *temp_a0_3;
            temp_v0_2 = (temp_v1 * 0xC) + D_8011F298;
            M2C_FIELD(temp_a2, __repair_words3 *, 0x24) = *(__repair_words3 *) ((s8 *) temp_v0_2 + 0x0);
            temp_v1_2 = *temp_a0_3;
            temp_s0 = M2C_FIELD(temp_v0_2, s32 *, 0);
            temp_a2_2 = M2C_FIELD(temp_v0_2, s32 *, 4);
            temp_a3 = M2C_FIELD(temp_v0_2, s32 *, 8);
            M2C_FIELD(temp_v1_2, s32 *, 0x30) = temp_s0;
            M2C_FIELD(temp_v1_2, s32 *, 0x34) = temp_a2_2;
            M2C_FIELD(temp_v1_2, s32 *, 0x38) = temp_a3;
            func_800643C8(*temp_a0_3);
            temp_v0_3 = *(s32 *)(D_8011F280 + temp_s0_2);
            if (temp_v0_3 != NULL) {
                temp_v0_4 = M2C_FIELD(temp_v0_3, void **, 0x6C);
                if (temp_v0_4 != NULL) {
                    temp_v1_3 = M2C_FIELD(temp_v0_4, void **, 0xB4);
                    M2C_FIELD(temp_v1_3, u16 *, 0xC) += 0xA;
                }
            }
            temp_v0_5 = temp_s4 * 4;
            temp_a0_4 = *(s32 *)(D_8011F288 + temp_v0_5);
            *(s32 *)(D_8011F280 + temp_v0_5) = 0;
            M2C_FIELD(temp_a0_4, s32 *, 0x28) = (s32) ((M2C_FIELD(temp_a0_4, s32 *, 0x28) & ~0xFC) | 0x1C);
            M2C_FIELD(arg0, s32 *, 0x3C) = 0;
            M2C_FIELD(arg0, s32 *, 0x40) = 0;
            M2C_FIELD(arg0, s32 *, 0x44) = 0;
        }
    }
}
