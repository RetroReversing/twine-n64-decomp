/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

s32 func_8000B9B8();
s16 strlen();
extern char D_148B400[];
extern u16 *D_800C994C;
extern s32 D_800C9958;

typedef struct { unsigned char pad_0[2]; short field_2; int field_4; } __repair_record_var_s0;
void func_8007539C(void) {
    char sp10[0x400];
    s32 sp410;
    char *var_s3;
    s32 var_s1;
    register u16 **var_s2;
    unsigned long var_s4;
    char *var_s0;
    register u16 *temp_v1;

    var_s4 = 0;
    var_s2 = &D_800C994C;
    var_s3 = &D_800C9958;
    sp410 = 0;
    do {
        temp_v1 = *var_s2;
        if (*temp_v1 != 0xFFFF) {
            var_s0 = temp_v1;/*__repair_loop_weight*/do {do {
            var_s1 = *(s32 *)var_s3;} while (0);} while (0);
            do {
                func_8000B9B8(&sp410, var_s1 + D_148B400, 4);
                func_8000B9B8(sp10, sp410 + D_148B400, 0x400);
                ((__repair_record_var_s0*)var_s0)->field_2 = strlen((unsigned)sp10);
                var_s0 += 8;
                ((__repair_record_var_s0*)var_s0)->field_4 = sp410;
                var_s1 += 4;
            } while (*(u16 *)var_s0 != 0xFFFF);
        }
        var_s3 += 4;
        var_s4 += 1;
        var_s2 += 4;
    } while (var_s4 < 3U);
}
