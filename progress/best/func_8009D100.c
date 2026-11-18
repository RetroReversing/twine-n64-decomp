/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */
#ifndef M2C_DEFINES
#define M2C_DEFINES
typedef s32 M2C_UNK;
typedef s8 M2C_UNK8;
typedef s16 M2C_UNK16;
typedef s32 M2C_UNK32;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define M2C_CARRY 0
#define M2C_OVERFLOW(a) (0)
#endif

s32 func_800CEEE0(s32, s32);                        /* extern */
M2C_UNK osSendMesg(M2C_UNK *, M2C_UNK, M2C_UNK);    /* extern */
extern u8 D_800FDBB0;
extern M2C_UNK D_800FDBB4;
extern M2C_UNK D_800FDBB8;
extern M2C_UNK D_800FDBBC;
extern u8 D_800FDBE4;
extern M2C_UNK D_800FDBE8;
extern s32 D_80103EB4;
extern u16 D_80108F70;
extern s32 D_80109BA0;
extern s32 D_80109BF8;

void func_8009D100(void) {
    s32 temp_a0;
    s32 temp_a1;
    s32 temp_v0;
    s32 var_s0;
    void *temp_a1_2;

    if (D_800FDBE4 != 0) {
        osSendMesg(&D_800FDBE8, 0, 0);
    }
    if (D_800FDBB0 != 0) {
        var_s0 = 0;
        if (D_800FDBB0 != 0) {
            __repair_rows: {
                temp_a1 = D_80109BF8 + 0xC;
                D_80109BF8 = temp_a1;
                temp_v0 = func_800CEEE0(D_80109BA0, temp_a1);
                temp_a0 = (var_s0 & 0xFF) * 0xC;
                temp_a1_2 = (D_80108F70 * 0xC) + D_80103EB4;
                M2C_FIELD(temp_a1_2, s32 *, 4) = (s32) *(&D_800FDBB8 + temp_a0);
                var_s0 += 1;
                D_80109BA0 = temp_v0;
                M2C_FIELD(temp_a1_2, s32 *, 0) = (s32) *(&D_800FDBBC + temp_a0);
                D_80108F70 += 1;
                M2C_FIELD(temp_a1_2, s32 *, 8) = (s32) *(&D_800FDBB4 + temp_a0);
            }
if ((u32) (var_s0 & 0xFF) < (u8) D_800FDBB0) goto __repair_rows;
        }
        D_800FDBB0 = 0;
        D_800FDBE4 = 1;
        return;
    }
    D_800FDBE4 = 0;
}
