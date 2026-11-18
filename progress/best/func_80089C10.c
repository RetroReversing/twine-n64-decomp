/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

s32 func_800A0170(void *, s32);                 /* extern */
extern void *D_800E4240;
extern void *D_800E4244;
extern s32 D_800E4248;
extern s32 D_800E424C;
extern void *D_800E4250;
extern void *(*D_8010017C)(s32, s32);

void func_80089C10(s32 arg0) {
void *__repair_cached_pointer = D_800E4240;

int __repair_literal;

    unsigned temp_s1;
    void *temp_v0_2;
    s32 var_a1;
    register void *temp_v0;
    int var_a0;
    
    void *var_v1;

    var_a0 = arg0 << 8;
    D_800E4240 = D_8010017C(arg0 * 0x14, 0);
    temp_v0 = D_8010017C(var_a0, 0);
    D_800E4244 = temp_v0;
    func_800A0170(temp_v0, var_a0);
    var_a0 = 1;
    D_800E424C = 0;
    D_800E4250 = D_800E4240;
    (*(void **)((char *)(__repair_cached_pointer) + 8)) = (void *) D_800E4244;
    (*(s32 *)((char *)(D_800E4240) + 4)) = 0;
__repair_literal = 1;

    if (__repair_literal < arg0) {
        temp_v0 = D_800E4244 + 0x100;
        var_a1 = 0;
        var_v1 = D_800E4240 + 0x14;
        __repair_rows: {
            (*(void **)((char *)(var_v1) + 8)) = temp_v0;
            temp_v0_2 = D_800E4240 + var_a1;
            temp_v0 += 0x100;
            (*(void **)((char *)(var_v1) + -0x14)) = var_v1;
            (*(void **)((char *)(var_v1) + 4)) = temp_v0_2;
            var_v1 += 0x14;
            var_a1 += 0x14;
            ++var_a0;
        }
if (var_a0 < arg0) goto __repair_rows;
    }
    D_800E4248 = 0;
    (*(s32 *)((char *)(((var_a0 * 0x14) + D_800E4240)) + -0x14)) = 0;
}
