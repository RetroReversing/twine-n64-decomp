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

f32 approxDistance(s32, void *);                    /* extern */
M2C_UNK func_8002B150(void *, s32, M2C_UNK);        /* extern */
M2C_UNK func_80073AF8(M2C_UNK, s32, M2C_UNK *, M2C_UNK, s32, s32, s32, s32, s32, s32, s32); /* extern */
s32 lookupDataEntry(s32);                           /* extern */
M2C_UNK requestSound(M2C_UNK);                      /* extern */
M2C_UNK setActorStatusBits(void *, s32, s32, s32);  /* extern */
M2C_UNK sprintf(M2C_UNK *, M2C_UNK *, M2C_UNK, s32, s32); /* extern */
extern s32 D_8010969C;
extern M2C_UNK D_8011F000;
extern M2C_UNK D_8011F170;
extern u8 gSceneType;
extern M2C_UNK sProbeActive;
extern M2C_UNK sProbeActors;
extern M2C_UNK sProbeOriginTable;
extern M2C_UNK sProbePositions;
extern M2C_UNK sProbeStates;
extern M2C_UNK sProbeTimers;

typedef struct { s32 w[3]; } __repair_words3;
void func_8011BF0C(void *arg0) {
    M2C_UNK var_a2;
    s32 temp_a0;
    s32 temp_a0_2;
    s32 temp_a1;
    s32 temp_a2_2;
    s32 temp_a3;
    s32 temp_s0;
    s32 temp_s0_2;
    s32 temp_s1_2;
    s32 temp_s4;
    s32 temp_v0;
    s32 temp_v1;
    void **temp_a0_3;
    void *temp_a0_4;
    void *temp_a2;
    void *temp_v0_2;
    void *temp_v0_3;
    void *temp_v0_4;
    void *temp_v1_2;
    void *temp_v1_3;
    M2C_UNK *__base_D_8011F170;

    __base_D_8011F170 = &D_8011F170;

    if ((gSceneType != 3) || (*(&sProbeActive + M2C_FIELD(arg0, s16 *, 0x7A)) != 0)) {
        temp_s4 = M2C_FIELD(arg0, u8 *, 0x7B) ^ 1;
        temp_v1 = temp_s4 & 0xFF;
    temp_s0 = temp_v1;
        temp_a0 = ((u32 *) &sProbeActors)[temp_s0];
        if ((temp_a0 != 0) && (approxDistance(temp_a0 + 0x24, arg0 + 0x24) < 2.0f)) {
            if (((u32 *) &sProbeOriginTable)[temp_s0] != 0) {
                temp_s1_2 = lookupDataEntry((-(temp_s0 == 0) & 0x6F) | 0x6E);
                temp_v0 = lookupDataEntry(0x28D);
                var_a2 = 0xC;
                if (temp_s0 == 0) {
                    var_a2 = 5;
                }
                sprintf(__base_D_8011F170, &D_8011F000, var_a2, temp_s1_2, temp_v0);
                /*__repair_pointer_balance*/if ((unsigned long)__base_D_8011F170 & 0x100) {
func_80073AF8(0, D_8010969C, __base_D_8011F170, -1, -1, 1, 0, 0, 6, 0, 0x3C);
} else {
func_80073AF8(0, D_8010969C, __base_D_8011F170, -1, -1, 1, 0, 0, 6, 0, 0x3C);
}
                requestSound(0x21A);
            }
            temp_a0_2 = M2C_FIELD(arg0, s16 *, 0x7A) * 8;
            func_8002B150(temp_a0_2 + &sProbeTimers, (*(&sProbeTimers + temp_a0_2) + 1) & 0xFF, 0);
            temp_v1 = temp_s4 & 0xFF;
            temp_s0_2 = temp_v1 * 4;
            temp_a0_3 = temp_s0_2 + &sProbeActors;
            temp_a2 = *temp_a0_3;
            temp_v0_2 = (void *)((temp_v1 * 0xC)); temp_v0_2 = (void *)((char *)temp_v0_2 + (s32)(&sProbePositions));
            M2C_FIELD(temp_a2, __repair_words3 *, 0x24) = *(__repair_words3 *) ((s8 *) temp_v0_2 + 0x0);
            temp_v1_2 = *temp_a0_3;
            temp_a1 = M2C_FIELD(temp_v0_2, s32 *, 0);
            temp_a2_2 = M2C_FIELD(temp_v0_2, s32 *, 4);
            temp_a3 = M2C_FIELD(temp_v0_2, s32 *, 8);
            M2C_FIELD(temp_v1_2, s32 *, 0x30) = temp_a1;
            M2C_FIELD(temp_v1_2, s32 *, 0x34) = temp_a2_2;
            M2C_FIELD(temp_v1_2, s32 *, 0x38) = temp_a3;
            setActorStatusBits(*temp_a0_3, temp_a1, temp_a2_2, temp_a3);
            temp_v0_3 = ((u32 *) &sProbeOriginTable)[temp_v1];
            if (temp_v0_3 != NULL) {
                temp_v0_4 = M2C_FIELD(temp_v0_3, void **, 0x6C);
                if (temp_v0_4 != NULL) {
                    temp_v1_3 = M2C_FIELD(temp_v0_4, void **, 0xB4);
                    M2C_FIELD(temp_v1_3, u16 *, 0xC) = (u16) (M2C_FIELD(temp_v1_3, u16 *, 0xC) + 0xA);
                }
            }
            temp_a0_4 = ((u32 *) &sProbeStates)[temp_s4];
            ((u32 *) &sProbeOriginTable)[temp_s4] = 0;
            M2C_FIELD(temp_a0_4, s32 *, 0x28) = (s32) ((M2C_FIELD(temp_a0_4, s32 *, 0x28) & ~0xFC) | 0x1C);
            M2C_FIELD(arg0, s32 *, 0x3C) = 0;
            M2C_FIELD(arg0, s32 *, 0x40) = 0;
            M2C_FIELD(arg0, s32 *, 0x44) = 0;
        }
    }
}
