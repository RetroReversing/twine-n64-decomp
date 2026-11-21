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

M2C_UNK actorLinkToSurface(s32, void *, M2C_UNK);   /* extern */
M2C_UNK effectSetAnimFrame(void *, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_8002B000(M2C_UNK *, M2C_UNK);          /* extern */
M2C_UNK setBonusItemState(s32, M2C_UNK, void *);    /* extern */
void *spawnEffectObject(M2C_UNK, void *, M2C_UNK);  /* extern */
extern M2C_UNK D_8011F118;
extern M2C_UNK D_8011F11C;
extern M2C_UNK D_8011F120;
extern s32 D_8011F150[];
extern s32 *gProbeObjectList;
extern u8 gSceneType;
extern M2C_UNK sProbeTimers;

typedef struct { unsigned char pad_0[84]; float field_54; unsigned char pad_58[4]; int field_5C; unsigned char pad_60[12]; void * field_6C; unsigned char pad_70[8]; short field_78; short field_7A; short field_7C; } __repair_record_temp_v0;
typedef struct { unsigned char pad_0[84]; float field_54; unsigned char pad_58[4]; int field_5C; unsigned char pad_60[24]; short field_78; short field_7A; short field_7C; } __repair_record_temp_v0_2;
void *func_8011A098(void *arg0, M2C_UNK arg1, s32 arg2) {
    u16 temp_s3;
    s32 temp_s0;
    s32 temp_v0_3;
    s32 temp_v1;
    void *temp_v0;
    void *temp_v0_2;

    if (gSceneType == 6) {
        func_8002B000(&sProbeTimers, 0x1E);
        func_8002B000(&sProbeTimers + 2, 0x1E);
        temp_v0 = spawnEffectObject(0, arg0, arg1);
        temp_s3 = arg2 - 1;
        if (temp_v0 != NULL) {
            temp_v1 = temp_s3 & 0xFFFF;
            D_8011F150[temp_v1] = temp_v0;
            if (temp_v1 != 0) {
                if (temp_v1 != 1) {
                    effectSetAnimFrame(temp_v0, 5, 0xF4);
                } else {
                    effectSetAnimFrame(temp_v0, 4, 0xF4);
                }
            } else {
                effectSetAnimFrame(temp_v0, 3, 0xF4);
            }
            ((__repair_record_temp_v0*)temp_v0)->field_78 = 0x41;
            ((__repair_record_temp_v0*)temp_v0)->field_7A = temp_s3;
            ((__repair_record_temp_v0*)temp_v0)->field_7C = 2;
            ((__repair_record_temp_v0*)temp_v0)->field_54 = 1.0f;
            ((__repair_record_temp_v0*)temp_v0)->field_5C = (s32) (((__repair_record_temp_v0*)temp_v0)->field_5C & ~0x200);
            actorLinkToSurface(*gProbeObjectList, temp_v0, 1);
            temp_v0_2 = spawnEffectObject(0, arg0, arg1);
            if (temp_v0_2 != NULL) {
                effectSetAnimFrame(temp_v0_2, 2, 0xF4);
                temp_s0 = temp_s3 & 0xFFFF;
                ((__repair_record_temp_v0_2*)temp_v0_2)->field_7A = temp_s3;
                ((__repair_record_temp_v0_2*)temp_v0_2)->field_7C = 2;
                ((__repair_record_temp_v0_2*)temp_v0_2)->field_5C = (s32) (M2C_FIELD(temp_v0_2, const s32 *, 0x5C) & ~0x200);
                setBonusItemState(temp_s0, 2, temp_v0);
                temp_v0_3 = temp_s0 * 3;
                *(&D_8011F118 + temp_v0_3) = M2C_FIELD(arg0, const s32 *, 0);
                *(&D_8011F11C + temp_v0_3) = M2C_FIELD(arg0, const s32 *, 4);
                *(&D_8011F120 + temp_v0_3) = M2C_FIELD(arg0, const s32 *, 8);
                ((__repair_record_temp_v0*)temp_v0)->field_6C = temp_v0_2;
                ((__repair_record_temp_v0_2*)temp_v0_2)->field_78 = 0x1F;
                ((__repair_record_temp_v0_2*)temp_v0_2)->field_54 = 1.0f;
                { s32 probe = *gProbeObjectList; actorLinkToSurface(probe, temp_v0_2, 1); }
            }
            return temp_v0;
        }
    }
    return NULL;
}
