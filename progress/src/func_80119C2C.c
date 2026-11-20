/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

extern int D_8011F108;
extern int D_8011F10C;
extern int D_8011F110;
void *func_80016410();
s32 actorLinkToSurface();
s32 func_80044670();
extern s32 *gProbeObjectList;
extern u8 gSceneType;

typedef struct { int field_0; int field_4; int field_8; } __repair_record_arg0;
typedef struct { unsigned char pad_0[84]; float field_54; unsigned char pad_58[4]; int field_5C; unsigned char pad_60[24]; short field_78; short field_7A; unsigned char pad_7C[2]; signed char field_7E; signed char field_7F; signed char field_80; signed char field_81; unsigned char field_82; } __repair_record_temp_v0;
typedef struct { s32 w[3]; } __repair_record_copy_3;
void *func_80119C2C(void *arg0, s32 arg1, s32 arg2) {
    void *temp_v0;

    if ((u32) (gSceneType - 4) >= 2U) {
        return NULL;
    }
    temp_v0 = func_80016410(0, arg0, arg1);
    *(__repair_record_copy_3 *) &D_8011F108 = *(__repair_record_copy_3 *) arg0;
    if ((s32)temp_v0 != NULL) {
        func_80044670(temp_v0, 0, 0xF4);
        ((__repair_record_temp_v0*)temp_v0)->field_54 = (f32) (arg2 & 0xFFFF);
        ((__repair_record_temp_v0*)temp_v0)->field_78 = 0x29;
        ((__repair_record_temp_v0*)temp_v0)->field_7F = 0;
        ((__repair_record_temp_v0*)temp_v0)->field_7E = 3;
        ((__repair_record_temp_v0*)temp_v0)->field_82 = 0x80;
        ((__repair_record_temp_v0*)temp_v0)->field_80 = 0;
        ((__repair_record_temp_v0*)temp_v0)->field_81 = 0;
        ((__repair_record_temp_v0*)temp_v0)->field_7A = 0;
        ((__repair_record_temp_v0*)temp_v0)->field_5C &= ~0x200;
        actorLinkToSurface(*gProbeObjectList, temp_v0, 1);
    }
    return temp_v0;
}
