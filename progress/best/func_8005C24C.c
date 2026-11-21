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

s32 requestSound();
s32 func_8005B5A8();
s32 func_80073AF8();
s32 lookupDataEntry();
extern s32 D_800C4450;
extern char D_800C4458[];
extern char D_800C4462[];
extern char D_800C446A[];
extern void *D_80108788;
extern s32 D_80109688;

void func_8005C24C(void) {
    char *var_s2;
    s32 temp_s0;
    s32 var_a2;
    
    u32 temp_a0;
    u32 var_s1;

    var_a2 = 0;
    if (D_80108788 != NULL) {
        temp_s0 = 0;
        if (M2C_FIELD(D_80108788, void **, 0x70) != NULL) {
            var_s1 = 0;
            var_s2 = &D_800C4450;
            do {
                temp_a0 = M2C_FIELD(M2C_FIELD(D_80108788, void **, 0x70), u32 *, 0x30);
                temp_s0 = var_s1 * 4;
                if ((((temp_a0 >> 4) & 0xFFFF) == *(s32 *)var_s2) && ((temp_a0 >> 0x14) == *(s32 *)(D_800C4458 + temp_s0)) && (M2C_FIELD(D_80108788, u16 *, 0x78) == 0x12)) {
                    if (M2C_FIELD(D_80108788, s16 *, 0x7C) == 0) {
                        M2C_FIELD(D_80108788, s16 *, 0x7C) = 1;
                        requestSound(0x110);
                        var_s2 += 4;
                        func_80073AF8(0, D_80109688, lookupDataEntry(*(u16 *)(D_800C4462 + temp_s0)), -1, -1, 1, 0, 0, 3, 0, 0);
                        var_a2 = 1;
                        M2C_FIELD(D_80108788, s32 *, 0x60) |= 0x08000000;
                    } else {
                        func_80073AF8(0, D_80109688, lookupDataEntry(*(u16 *)(D_800C446A + temp_s0), D_80108788, var_a2), -1, -1, 1, 0, 0, 3, 0, 0);
                        var_a2 = 1;
                        goto block_9;
                    }
                } else {
block_9:
                    var_s2 += 4;
                }/*__repair_loop_weight*/__repair_rows: {do {do {
                var_s1 += 1;} while (0);} while (0);}
if (0) goto __repair_rows;
            } while (var_s1 < 2U);
            goto block_11;
        }
    } else {
block_11:
        temp_s0 = var_a2;
    }
    if (temp_s0 == 0) {
        func_8005B5A8();
    }
}
