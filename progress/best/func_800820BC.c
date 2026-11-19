static __inline__ s16 __repair_inline(s16 a) { return a; }
/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2 -fno-strength-reduce, tried by autopilot */

s32 func_80011938();
s32 func_80081758();
extern s16 D_800E1A80;
extern char D_8010D434[];
extern char D_8010D436[];
extern char D_80115108[];
extern char D_8011510C[];

void func_800820BC(void) {
    register s16 temp_v0;
    char *var_s3;
    s32 var_s0;
    s32 var_s1;
    s32 var_s2;

    var_s0 = 0;
    var_s3 = &D_800E1A80;
    var_s2 = 0;
    var_s1 = 0;
    __repair_rows: {
        func_80011938(var_s0 & 0xFFFF, 0);
        *(s32 *)(D_80115108 + var_s1) = (s32) *(s16 *)(D_8010D434 + var_s2);
        func_80081758(var_s0);
        temp_v0 = __repair_inline(*(s16 *)(D_8010D436 + (int)var_s2));/*__repair_loop_weight*/do {do {do {
        var_s0++;} while (0);} while (0);} while (0);
        var_s2 += 8;
        *(s32 *)(D_8011510C + var_s1) = temp_v0;
        *(s16 *)var_s3 = 0;
        var_s3 += 2;
        var_s1 += 0xA0;
    }
if (4 > var_s0) goto __repair_rows;
}
