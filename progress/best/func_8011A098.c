/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

void *func_80016410(s32, s32, s32);      /* extern */
s32 func_8002B000(s32 *, s32);          /* extern */
s32 func_8003E6EC(s32, void *, s32);        /* extern */
s32 func_80044670(void *, s32, s32);    /* extern */
s32 func_80119E60(s32, s32, void *);        /* extern */
extern s32 *D_800CA31C;
extern u8 D_801002A0;
extern s32 D_8011F118;
extern s32 D_8011F11C;
extern s32 D_8011F120;
extern u8 D_8011F140[];
extern s32 D_8011F150[];

typedef struct { unsigned char pad[92]; int value; } __repair_field_5C;
typedef struct { unsigned char pad_0[84]; float field_54; unsigned char pad_58[20]; void * field_6C; unsigned char pad_70[8]; short field_78; short field_7A; short field_7C; } __repair_record_temp_v0;
void *func_8011A098(void *arg0, s32 arg1, s32 arg2) {
    int temp_s3;
    void *temp_v0_2;
    unsigned int temp_s0;
    register s32 temp_v0_3;
    unsigned int temp_v1;
    register void *temp_v0;

    if (D_801002A0 == 6) {
        func_8002B000(D_8011F140, 0x1E);
        func_8002B000(D_8011F140 + 8, 0x1E);
        temp_s3 = arg2 - 1;
        temp_v0 = func_80016410(0, arg0, arg1);
        if (temp_v0 != NULL) {
            temp_v1 = temp_s3 & 0xFFFF;
            D_8011F150[temp_v1] = temp_v0;
            switch (temp_v1) {
                case 0:
                    func_80044670(temp_v0, 3, 0xF4);
                    break;
                case 1:
                    func_80044670(temp_v0, 4, 0xF4);
                    break;
                default:
                    func_80044670(temp_v0, 5, 0xF4);
                    break;
            }
            ((__repair_record_temp_v0*)temp_v0)->field_7A = temp_s3;
            ((__repair_record_temp_v0*)temp_v0)->field_7C = 2;
            ((__repair_record_temp_v0*)temp_v0)->field_78 = 0x41;
            ((__repair_record_temp_v0*)temp_v0)->field_54 = 1.0f;
            ((__repair_field_5C *)temp_v0)->value = (s32) (((__repair_field_5C *)temp_v0)->value & ~0x200);
            func_8003E6EC(*D_800CA31C, temp_v0, 1);
            temp_v0_2 = func_80016410(0, arg0, arg1);
            if (temp_v0_2 != NULL) {
                func_80044670(temp_v0_2, 2, 0xF4);
                (*(s16 *)((char *)(temp_v0_2) + 0x7A)) = temp_s3;
                temp_s0 = temp_s3 & 0xFFFF;
                (*(s16 *)((char *)(temp_v0_2) + 0x7C)) = 2;
                ((__repair_field_5C *)temp_v0_2)->value = (s32) (((__repair_field_5C *)temp_v0_2)->value & ~0x200);
                func_80119E60(temp_s0, 2, temp_v0);
                temp_v0_3 = temp_s0 * 0x3;
                ((__repair_record_temp_v0*)temp_v0)->field_6C = temp_v0_2;
                *(&D_8011F120 + temp_v0_3) = (*(s32 *)((char *)(arg0) + 8));
                *(&D_8011F11C + temp_v0_3) = (*(s32 *)((char *)(arg0) + 4));
                *(&D_8011F118 + temp_v0_3) = (*(s32 *)((char *)(arg0) + 0));
                (*(s16 *)((char *)(temp_v0_2) + 0x78)) = 0x1F;
                (*(f32 *)((char *)(temp_v0_2) + 0x54)) = 1.0f;
                func_8003E6EC(*D_800CA31C, temp_v0_2, 1);
            }
            return temp_v0;
        }
    }
    return NULL;
}
