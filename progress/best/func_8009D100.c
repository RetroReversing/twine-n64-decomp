/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

s32 func_800CEEE0(s32, s32);                        /* extern */
s32 osSendMesg(s32 *, s32, s32);    /* extern */
extern u8 D_800FDBB0;
extern s32 D_800FDBB4;
extern s32 D_800FDBB8;
extern s32 D_800FDBBC;
extern u8 D_800FDBE4;
extern s32 D_800FDBE8;
extern s32 D_80103EB4;
extern u16 D_80108F70;
extern s32 D_80109BA0;
extern s32 D_80109BF8;

typedef struct { int field_0; int field_4; int field_8; } __repair_record_temp_a1_2;
void func_8009D100(void) {
    unsigned short temp_a0;
    s32 temp_a1;
    s32 temp_v0;
    s32 var_s0;
    void *temp_a1_2;

    if (D_800FDBE4 != 0) {
        osSendMesg(&D_800FDBE8, 0, 0);
    }
    if (D_800FDBB0) {
        var_s0 = 0;
        if (D_800FDBB0) {
            __repair_rows: {
                temp_a1 = D_80109BF8 + 0xC;
                D_80109BF8 = temp_a1;
                temp_v0 = func_800CEEE0(D_80109BA0, temp_a1);
                temp_a1_2 = (D_80108F70 * 0xC) + D_80103EB4;
                temp_a0 = (var_s0 & 0xFF) * 0xC;
                ((__repair_record_temp_a1_2*)temp_a1_2)->field_4 = (s32) *(&D_800FDBB8 + (unsigned short)temp_a0);
                var_s0 += 1;
                D_80109BA0 = temp_v0;
                ((__repair_record_temp_a1_2*)temp_a1_2)->field_0 = (s32) *(&D_800FDBBC + temp_a0);
                ((__repair_record_temp_a1_2*)temp_a1_2)->field_8 = (s32) *(&D_800FDBB4 + temp_a0);
                D_80108F70 += 1;
            }
if ((u32) (var_s0 & 0xFF) < (u8) D_800FDBB0) goto __repair_rows;
        }
        D_800FDBB0 = 0;
        D_800FDBE4 = 1;
        return;
    }
    D_800FDBE4 = 0;
}
