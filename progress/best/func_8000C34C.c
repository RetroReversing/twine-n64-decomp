/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

s32 func_8000BB50(void *, f32, f32, f32, f32);
s32 func_80043FA0();
void *func_80044818();
f32 func_80046140(f32, f32, s32);
f32 func_8008292C(f32);
f32 func_80082968(f32);
f32 approximateAtan2(f32, f32);
s32 func_800A37C0();
extern f32 D_800AE4D8;
extern char D_800B1B68[];
extern char D_800B1D48[];
extern u32 D_800B1D84;
extern char D_800B25C0[];
extern u8 D_800C2B40;
extern char D_800C392A[];
extern s32 D_801032A0;
extern u32 D_80107EA0;
extern s32 D_8010A924;
extern s32 *D_8010A928;
extern s32 D_8010D538;
extern f32 D_80112F90;
extern f32 D_80112F98;
extern f32 D_80112FA0;
extern f32 D_80112FA8;
extern f32 D_80112FB0;
extern f32 D_80112FB8;
extern void *D_80117728;

extern void *D_80117728;
extern f32 D_80112F90, D_80112F98, D_80112FA0, D_80112FA8, D_80112FB0, D_80112FB8;
extern u8 D_800C2B40;

typedef struct { int value; } __repair_field_0;
void func_8000C34C(void *arg0, void *arg1) {
    char sp18[0xC];
    char *var_s2;
    char *var_a0_2;
    char sp24[0x244];
    int var_a0;
    
    f32 temp_fs0;
    f32 temp_fs0_2;
    f32 temp_fs1;
    f32 temp_fv0;
    s8 temp_a0;
    f32 temp_fv1_2;
    f32 var_fs1;
    f32 var_fs2;
    f32 var_ft1;
    s32 *temp_a0_2;
    union { s32 * pointer; s32 value; } __repair_phase_storage;
    s32 *temp_v1_3;
    s32 *temp_v1_4;
    s32 *temp_v1_8;
    s32 var_a1_2;
    void *temp_v1_6;
    
    long var_s4;
    f32 temp_fv1;
    s32 temp_s6;
    unsigned long temp_v0;
    void *temp_s0;
    void *temp_s0_2;
    void *temp_v1;
    void *temp_v1_5;
    s32 var_s1;
s32 __repair_phase_var_s1;
    void *temp_v1_7;

    temp_v1 = (*(void **)((char *)(arg0) + 0x68));
    if (*(s16 *)(D_800C392A + ((*(u8 *)((char *)(temp_v1) + 0xB2)) * 8)) == 0) {
        temp_s6 = (*(s8 *)((char *)(temp_v1) + 0xB3));
        var_a0 = 0xF;
        if (!(((u32) (*(u32 *)((char *)((*(void **)((char *)(arg0) + 0x20))) + 0x58)) >> 2) & 0x200)) {
            var_a0 = 0xE;
            if (D_8010A924 != 0xE) {
                __repair_phase_storage.pointer = D_8010A928;
                D_8010A924 = 0xE;
                D_8010A928 = __repair_phase_storage.pointer + 8;
                ((__repair_field_0 *)__repair_phase_storage.pointer)->value = 0xDE000000;
                (*(s32 **)((char *)(__repair_phase_storage.pointer) + 4)) = D_800B1D48;
            }
            var_fs2 = (*(f32 *)((char *)((*(void **)((char *)(arg0) + 0x68))) + 8));
        } else {
            if (D_8010A924 != 0xF) {
                temp_v1_3 = D_8010A928;
                D_8010A924 = 0xF;
                D_8010A928 = (s8 *) temp_v1_3 + 8;
                ((__repair_field_0 *)temp_v1_3)->value = 0xDE000000;
                (*(s32 **)((char *)(temp_v1_3) + 4)) = D_800B1B68;
            }
            var_fs2 = (*(f32 *)((char *)((*(void **)((char *)(arg0) + 0x68))) + 8)) + 0.01f;
        }
        __repair_phase_storage.value = 0xFCFF0000;
        if (D_801032A0 != 7) {
            __repair_phase_storage.value = 0xFCFF97FF;
            temp_v1_4 = D_8010A928;
            var_a0 = 0xFFFDFE38;
            D_801032A0 = 7;
            D_8010A928 = temp_v1_4 + 8;
            ((__repair_field_0 *)temp_v1_4)->value = 0xFCFF97FF;
            (*(s32 *)((char *)(temp_v1_4) + 4)) = 0xFFFDFE38;
        }
        if (arg1 != NULL) {
            temp_fv0 = approximateAtan2((*(f32 *)((char *)(arg0) + 0x24)) - (*(f32 *)((char *)(arg1) + 4)), (*(f32 *)((char *)(arg0) + 0x2C)) - (*(f32 *)((char *)(arg1) + 0xC)));
            var_fs1 = func_8008292C(temp_fv0);
            var_ft1 = func_80082968(temp_fv0);
        } else {
            var_fs1 = 1.0f;
            var_ft1 = 0.0f;
        }
        var_s1 = 0;
        if (temp_s6 > 0) {
            var_a0_2 = sp18;
            var_a1_2 = 0;
            do {
                (*(f32 *)((char *)(var_a0_2) + 0)) = (f32) *(f32 *)(var_a1_2 + (*(s32 *)((char *)((*(void **)((char *)(arg0) + 0x68))) + 0)));
                (*(f32 *)((char *)(var_a0_2) + 4)) = var_fs2;
                (*(f32 *)((char *)(var_a0_2) + 8)) = (f32) (*(f32 *)((char *)((var_a1_2 + (*(s32 *)((char *)((*(void **)((char *)(arg0) + 0x68))) + 0)))) + 8));
                temp_v1_5 = (*(void **)((char *)(arg0) + 0x68));
                (*(f32 *)((char *)(var_a0_2) + 0)) += (var_fs1 * (((*(f32 *)((char *)((var_a1_2 + ((__repair_field_0 *)temp_v1_5)->value)) + 4)) - D_800AE4D8) - (*(f32 *)((char *)(temp_v1_5) + 8))));
                temp_v1_6 = (*(void **)((char *)(arg0) + 0x68));
                temp_fv1 = (*(f32 *)((char *)(var_a0_2) + 8)) + (var_ft1 * (((*(f32 *)((char *)((var_a1_2 + ((__repair_field_0 *)temp_v1_6)->value)) + 4)) - D_800AE4D8) - (*(f32 *)((char *)(temp_v1_6) + 8))));
                var_s1++;
                var_a1_2 += 0xC;
                (*(f32 *)((char *)(var_a0_2) + 8)) = temp_fv1;
                var_a0_2 += 0xC;
            } while (var_s1 < temp_s6);
        }
        __repair_phase_var_s1 = 1;
        if (1 < temp_s6) {
            var_s2 = sp24;
            var_s4 = 8;
            do {
                if (*(D_800B25C0 + var_s4) != -1) {
                    temp_s0 = var_s4 + D_800B25C0;
                    temp_a0 = (*(s8 *)((char *)(temp_s0) + 1));
                    temp_v1_7 = sp18 + (temp_a0 * 0xC);
                    temp_fs1 = (*(f32 *)((char *)(temp_v1_7) + 0)) - (*(f32 *)((char *)(var_s2) + 0));
                    temp_fs0 = (*(f32 *)((char *)(temp_v1_7) + 8)) - (*(f32 *)((char *)(var_s2) + 8));
                    temp_s0_2 = func_80044818((*(s32 *)((char *)(temp_s0) + 4)), 0x2A);
                    temp_fv1_2 = approximateAtan2(temp_fs1, temp_fs0);
                    temp_fs0_2 = func_80046140(temp_fs1, temp_fs0, temp_a0);
                    if (((u32) D_80107EA0 < (u32) D_800B1D84) && ((temp_v0 = D_80107EA0 + 1, D_80107EA0 = temp_v0, D_8010D538 = (*(s32 *)((char *)(D_80117728) + 0x74C)) + (temp_v0 << 6), func_8000BB50(&D_80112F90, (*(f32 *)((char *)(var_s2) + 0)) * 64.0f, (*(f32 *)((char *)(var_s2) + 4)) * 64.0f, (*(f32 *)((char *)(var_s2) + 8)) * 64.0f, temp_fv1_2), D_80112F90 *= temp_fs0_2, D_80112FA0 *= temp_fs0_2, D_80112FB0 *= temp_fs0_2, D_80112F98 *= temp_fs0_2, D_80112FA8 *= temp_fs0_2, D_80112FB8 *= temp_fs0_2, func_800A37C0(&D_80112F90, D_8010D538), temp_a0_2 = D_8010A928, D_8010A928 = (unsigned)temp_a0_2 + 8, ((__repair_field_0 *)temp_a0_2)->value = 0xDA380003, (*(s32 *)((char *)(temp_a0_2) + 4)) = (s32) (D_8010D538 - (unsigned)0x80000000), (*(s32 *)((char *)(temp_a0_2) + 8)) = 0xFA000000, (*(s32 *)((char *)(temp_a0_2) + 0xC)) = (s32) ((((*(u8 *)((char *)(arg0) + 0x82)) * 2) / 3) & 0xFF), D_8010A928 = (s8 *) temp_a0_2 + 0x10, (((__repair_field_0 *)temp_s0_2)->value != 0)) || (func_80043FA0(temp_s0_2, 0xDA380003), (((__repair_field_0 *)temp_s0_2)->value != 0)))) {
                        if (!((*(u8 *)((char *)(temp_s0_2) + 0x46)) & 0x80)) {
                            (*(u8 *)((char *)(temp_s0_2) + 0x46)) = (u8) D_800C2B40;
                        }
                        temp_v1_8 = D_8010A928;
                        ((__repair_field_0 *)temp_v1_8)->value = 0xDE000000;
                        D_8010A928 = temp_v1_8 + 8;
                        (*(s32 *)((char *)(temp_v1_8) + 4)) = (s32) ((__repair_field_0 *)temp_s0_2)->value;
                    }
                }
                var_s2 += 0xC;
                __repair_phase_var_s1 += 1;
                var_s4 += 8;
            } while (__repair_phase_var_s1 < temp_s6);
        }
    }
}
