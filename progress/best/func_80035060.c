/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

s32 func_80034EFC();
s32 osVirtualToPhysical();
extern s32 D_801002C0;
extern char D_80100304[];
extern u8 D_80100777;
extern u8 D_80100778;
extern u8 D_80100779;
extern u8 D_801007CF;
extern u8 D_801007D0;
extern u8 D_801007D1;
extern s32 D_80102ED8;
extern s32 D_80109A54;
extern s16 D_8010A4B0;
extern u8 D_8010A4C1;
extern s32 D_8010A4E8;
extern s32 D_8010A4EC;
extern s16 D_8010D6F8;
extern void *D_80115328;

typedef struct { unsigned char pad[16]; int value; } __repair_field_10;
void func_80035060(void *arg0) {
    s16 temp_v1;
    f32 temp_fv0;
    f32 temp_fv1;
    
    s32 temp_fp;
    s32 temp_s0_2;
    s32 temp_s3;
    s32 temp_s5;
    unsigned int temp_s6;
    unsigned long temp_s7;
    s32 temp_v1_2;
    long var_a0;
    s32 var_a0_2;
    s32 var_v0;
    s32 var_v1;
    s32 var_v1_2;
    long var_v1_3;
    void *temp_a1_2;
    void *temp_s0;
    union { void * pointer; s32 value; } __repair_phase_storage;
    void *temp_s1_2;
    void *temp_v0;
    void *temp_v0_2;
    void *temp_v0_3;

    if ((*(s32 *)((char *)(arg0) + 0x100)) & 0x40) {
        func_80034EFC();
        return;
    }
    temp_fv1 = (*(f32 *)((char *)(arg0) + 0x60));
    temp_fv0 = (*(f32 *)((char *)(arg0) + 0x64));
    __repair_phase_storage.pointer = D_80115328;
    D_80115328 = __repair_phase_storage.pointer + 8;
    (*(s32 *)((char *)(__repair_phase_storage.pointer) + 0)) = 0xE7000000;
    D_80115328 = __repair_phase_storage.pointer + 0x10;
    (*(s32 *)((char *)(__repair_phase_storage.pointer) + 4)) = 0;
    (*(s32 *)((char *)(__repair_phase_storage.pointer) + 8)) = 0xFE000000;
    temp_s7 = (s32) (temp_fv1 + (*(f32 *)((char *)(arg0) + 0x50)));
    temp_fp = (s32) (temp_fv0 + (*(f32 *)((char *)(arg0) + 0x58)));
    temp_s5 = (s32) ((temp_fv1 + (*(f32 *)((char *)(arg0) + 0x54))) - 1.0f);
    temp_s6 = (s32) ((temp_fv0 + (*(f32 *)((char *)(arg0) + 0x5C))) - 1.0f);
    temp_s0 = D_80115328;
    (*(s32 *)((char *)(__repair_phase_storage.pointer) + 0xC)) = osVirtualToPhysical(D_80109A54);
    D_80115328 = temp_s0 + 8;
    (*(s32 *)((char *)(temp_s0) + 4)) = 0x300000;
    D_80115328 = temp_s0 + 0x10;
    D_80115328 = temp_s0 + 0x18;
    (*(s32 *)((char *)(temp_s0) + 0)) = 0xE3000A01;
    (*(s32 *)((char *)(temp_s0) + 8)) = 0xE200001C;
    (*(s32 *)((char *)(temp_s0) + 0xC)) = 0x0F0A4000;
    ((__repair_field_10 *)temp_s0)->value = (s32) (((D_8010D6F8 - 1) & 0xFFF) | 0xFF100000);
    temp_s1_2 = D_80115328;
    (*(s32 *)((char *)(temp_s0) + 0x14)) = osVirtualToPhysical(D_80109A54, 0x0F0A4000);
    (*(s32 *)((char *)(temp_s1_2) + 4)) = 0xFFFCFFFC;
    temp_s3 = ((temp_s5 & 0x3FF) << 0xE) | (((temp_s6 & 0x3FF) * 4) | 0xF6000000);
    temp_s0_2 = ((temp_s7 & 0x3FF) << 0xE) | ((temp_fp & 0x3FF) * 4);
    (*(s32 *)((char *)(temp_s1_2) + 0)) = 0xF7000000;
    (*(s32 *)((char *)(temp_s1_2) + 8)) = temp_s3;
    (*(s32 *)((char *)(temp_s1_2) + 0xC)) = temp_s0_2;
    D_80115328 = temp_s1_2 + 8;
    D_80115328 = temp_s1_2 + 0x10;
    var_a0 = 2;
    if (D_8010A4EC != 0) {
        var_a0 = (-(D_8010A4E8 == 0) & 3) | 2;
    }
    ((__repair_field_10 *)temp_s1_2)->value = (s32) ((var_a0 << 0x13) | (((D_8010D6F8 - 1) & 0xFFF) | 0xFF000000));
    D_80115328 = temp_s1_2 + 0x18;
    (*(s32 *)((char *)(temp_s1_2) + 0x14)) = osVirtualToPhysical(*(s32 *)(D_80100304 + (D_8010A4B0 * 4)), 0xFF000000);
    if (D_80102ED8 != 0) {
        temp_v1 = (*(s16 *)((char *)(arg0) + 0x140));
        if ((temp_v1 == 3) && (D_801002C0 == temp_v1)) {
            temp_v0 = D_80115328;
            D_80115328 = temp_v0 + 8;
            (*(s32 *)((char *)(temp_v0) + 0)) = 0xF7000000;
            (*(s32 *)((char *)(temp_v0) + 4)) = 0;
            D_80115328 = temp_v0 + 0x10;
            (*(s32 *)((char *)(temp_v0) + 8)) = temp_s3;
            (*(s32 *)((char *)(temp_v0) + 0xC)) = temp_s0_2;
            return;
        }
    }
    __repair_phase_storage.value = (*(s32 *)((char *)(arg0) + 0x100));
    var_v1 = 0;
    if (!(__repair_phase_storage.value & 0x20)) {
        var_a0_2 = 0;
        if (D_8010A4EC != 0) {
            if (__repair_phase_storage.value & 2) {
                var_a0_2 = (D_801007CF + D_801007D0 + D_801007D1) << 0x10;
            } else {
                if (__repair_phase_storage.value & 1) {
                    var_a0_2 = (D_801007CF << 0x18) + (D_801007D0 << 0x10) + (D_801007D1 << 8);
                } else if (__repair_phase_storage.value & 4) {
                    var_a0_2 = 0x4000;
                }
                if ((*(s32 *)((char *)(arg0) + 0x100)) & 8) {
                    var_a0_2 = (D_80100777 << 0x18) + (D_80100778 << 0x10) + (D_80100779 << 8);
                }
            }
        } else {
            if (__repair_phase_storage.value & 2) {
                var_v1_2 = (((D_801007CF + D_801007D0 + D_801007D1) / 3) * 8) & 0x7C0;
                goto block_26;
            }
            var_v0 = __repair_phase_storage.value & 4;
            if (__repair_phase_storage.value & 1) {
                var_v1 = (((u8) D_801007D1 >> 2) & 0x3E) | (((D_801007CF << 8) & 0xF800) | ((D_801007D0 * 8) & 0x7C0));
                var_v0 = __repair_phase_storage.value & 4;
            }
            if (var_v0 != 0) {
                var_v1 = 0x10;
            }
            var_v1_3 = var_v1 | 1;
            if (__repair_phase_storage.value & 8) {
                var_v1_2 = (((u8) D_80100779 >> 2) & 0x3E) | (((D_80100777 << 8) & 0xF800) | ((D_80100778 * 8) & 0x7C0));
block_26:
                var_v1_3 = var_v1_2 | 1;
            }
            temp_v1_2 = var_v1_3 & 0xFFFF;
            var_a0_2 = (temp_v1_2 << 0x10) | temp_v1_2;
        }
        if (D_8010A4C1 != 0) {
            temp_v0_2 = D_80115328;
            D_80115328 = temp_v0_2 + 8;
            (*(s32 *)((char *)(temp_v0_2) + 4)) = (s32) (var_a0_2 & -(((*(s32 *)((char *)(arg0) + 0x100)) & 0x40) == 0));
            (*(s32 *)((char *)(temp_v0_2) + 0)) = 0xF7000000;
        } else {
            temp_v0_3 = D_80115328;
            D_80115328 = temp_v0_3 + 8;
            (*(s32 *)((char *)(temp_v0_3) + 0)) = 0xF7000000;
            (*(s32 *)((char *)(temp_v0_3) + 4)) = 0;
        }
        temp_a1_2 = D_80115328;
        D_80115328 = temp_a1_2 + 8;
        (*(s32 *)((char *)(temp_a1_2) + 0)) = (s32) (((temp_s5 & 0x3FF) << 0xE) | (((temp_s6 & 0x3FF) * 4) | 0xF6000000));
        (*(s32 *)((char *)(temp_a1_2) + 4)) = (s32) (((temp_s7 & 0x3FF) << 0xE) | ((temp_fp & 0x3FF) * 4));
    }
}
