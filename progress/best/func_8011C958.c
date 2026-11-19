/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

s32 func_80015F74(s32 *);                       /* extern */
void *func_800162BC(s32);                           /* extern */
s32 func_800448A4(void *, s32, s32);    /* extern */
extern s32 D_800BD644;
typedef struct { u16 f0; u8 pad[22]; } Slot_801001A2;
extern Slot_801001A2 D_801001A2[];
extern s32 D_801002C0;
extern u8 D_8011EDC0[];
extern s32 D_8011F338;
extern s32 D_8011F3C4;
extern s32 D_8011F3C8;
extern s32 D_8011F3CC;

void func_8011C958(void) {
int __repair_literal;

    s32 var_a0;
    s32 var_s1;
    s32 var_s3;
    s32 var_v0;
    
    u8 temp_v1;
    union { void * pointer; s32 value; } __repair_phase_storage;

    D_8011F3C4 = func_80015F74(D_8011EDC0);
    D_8011F3C8 = func_80015F74(D_8011EDC0 + 0x24);
    D_8011F3CC = func_80015F74(D_8011EDC0 + 0x48);
    var_s3 = 0;
    if (D_801002C0 > 0) {
        var_a0 = 0 & 0xFFFF;
        do {
            var_v0 = (unsigned char)var_a0;
    temp_v1 = D_801001A2[var_v0].f0;
            if (temp_v1 != 0) {
                var_s1 = 0;
__repair_literal = 4;

                if ((s32) temp_v1 >= __repair_literal) {
                    var_v0 = var_s3 & 0xFFFF;
                    if (temp_v1 == 5) {
                        var_s1 = 0;
                        goto block_6;
                    }
                    goto block_12;
                }
block_6:
loop_7:
                __repair_phase_storage.pointer = func_800162BC(var_a0);
                if (__repair_phase_storage.pointer != NULL) {
                    func_800448A4(__repair_phase_storage.pointer, 0x13, 0xF4);
                    (*(s32 *)((char *)(__repair_phase_storage.pointer) + 0x10)) = (s32) D_800BD644;
                    *((var_a0 * 4) + (((var_s1 & 0xFFFF) * 0x10) + &D_8011F338)) = __repair_phase_storage.pointer;
                }
                ++var_s1;
                if ((u32) (var_s1 & 0xFFFF) < 3U) {
                    goto loop_7;
                }
            } else {
                register var_s1 = 0;
                var_v0 = var_s3 & 0xFFFF;
block_12:
                __repair_phase_storage.value = 0 & 0xFFFF;
                __repair_rows: { {
                    *((var_v0 * 4) + ((__repair_phase_storage.value * 0x10) + &D_8011F338)) = 0;
                    ++var_s1;
                    var_a0 = var_s1 & 0xFFFF;
    __repair_phase_storage.value = var_a0;
                }
}
if ((u32) ((var_a0 = (short)var_s1) & 0xFFFF) < 3U) goto __repair_rows;
            }
            var_s3 += 1;
            var_a0 = var_s3 & 0xFFFF;
        } while ((var_s3 & 0xFFFF) < D_801002C0);
    }
}
