/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

s32 func_8000B9B8();
s16 strlen();
extern char D_148B400[];
extern u16 *D_800C994C;
extern s32 D_800C9958;

void func_8007539C(void) {
    register s32 sp10;
    int sp410;
    char *var_s3;
    register s32 var_s1;
    u16 **var_s2;
    u16 *temp_v1;
    char *var_s0;
    u32 var_s4;

    var_s4 = 0;
    var_s2 = &D_800C994C;
    var_s3 = &D_800C9958;
    sp410 = 0;
    do {
        temp_v1 = *var_s2;
        if (*temp_v1 != (short)0xFFFF) {
            var_s0 = temp_v1;
            var_s1 = *(s32 *)var_s3;
            __repair_rows: {
                do{{ func_8000B9B8(&sp410, var_s1 + D_148B400, 4); }{ func_8000B9B8(&sp10, sp410 + D_148B400, 0x400); }}while(0);
                (*(s16 *)((char *)(var_s0) + 2)) = strlen(&sp10);
                (*(s32 *)((char *)(var_s0) + 4)) = sp410;
                var_s0 += 8;
                var_s1 += 4;
            }
if (*(u16 *)var_s0 != 0xFFFF) goto __repair_rows;
        }
        var_s2 += 4;
        var_s3 += 4;
        var_s4 += 1;
    } while (var_s4 < 3U);
}
