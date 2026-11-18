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

s32 func_800101D8();
s32 func_80016FCC();
s32 func_80017454();
s32 func_800734B8();
s32 func_8008188C();
u64 osGetTime();
extern s32 D_800B1D74;
extern u8 D_800CA338;
extern s32 D_80102CC8;
extern u32 D_80102CCC;
extern s32 D_80108F88;
extern u32 D_80108F8C;
extern s32 D_80109DD8;
extern u32 D_80109DDC;
extern s32 D_8010A398;
extern u32 D_8010A39C;
extern s32 D_8010A4E0;
extern u32 D_80115320;
extern u32 D_80115324;

void func_800072B8(void) {
    s32 temp_a0;
    s32 temp_a2;
    s32 temp_a2_2;
    s32 temp_t0;
    s32 var_a0_2;
    s32 var_a2;
    s32 var_a3_2;
    u32 temp_a1;
    u32 temp_a1_2;
    u32 temp_lo;
    u32 temp_v1;
    u32 temp_v1_2;
    u32 temp_v1_3;
    u32 var_a0;
    u32 var_a1;
    u32 var_a2_2;
    u32 var_a3;
    u32 var_s0;
    u64 temp_ret;
    u64 temp_ret_2;
    u64 temp_ret_3;
    u64 temp_ret_4;

    /* Flowgraph is not reducible, falling back to gotos-only mode. */
    temp_ret = osGetTime();
    temp_v1 = (u32) temp_ret;
    temp_a2 = temp_v1 < (u32) D_80115324;
    D_80109DD8 = (temp_ret - D_80115320) - temp_a2;
    D_80109DDC = temp_v1 - D_80115324;
    temp_ret_2 = osGetTime(D_80115320, D_80115324, temp_a2);
    D_80115320 = temp_ret_2;
    D_80115324 = (u32) temp_ret_2;
    temp_a1 = D_80102CCC + D_80109DDC;
    D_80102CC8 = D_80102CC8 + D_80109DD8 + (temp_a1 < (u32) D_80109DDC);
    D_80102CCC = temp_a1;
    if (D_8010A4E0 == 0) {
        goto block_2;
    }
    var_a0 = (u32) D_80108F8C >> 0x1D;
    var_a2 = (D_80108F88 * 8) | var_a0;
    var_a3 = D_80108F8C * 8;
    goto block_3;
block_2:
    var_a0 = (u32) D_80108F8C >> 0x1F;
    var_a2 = (D_80108F88 * 2) | var_a0;
    var_a3 = D_80108F8C * 2;
block_3:
    if (var_a2 < D_80102CC8) {
        goto block_6;
    }
    if (D_80102CC8 != var_a2) {
        goto block_7;
    }
    if (var_a3 >= (u32) D_80102CCC) {
        goto block_7;
    }
block_6:
    D_80102CC8 = var_a2;
    D_80102CCC = var_a3;
block_7:
    var_s0 = 0;
    temp_ret_3 = osGetTime(var_a0, (u32) D_80102CC8, var_a2, var_a3);
    var_a3_2 = D_80102CC8;
    D_8010A398 = temp_ret_3;
    D_8010A39C = (u32) temp_ret_3;
    var_a2_2 = (u32) D_80108F8C >> 0x1F;
    var_a0_2 = (D_80108F88 * 2) | var_a2_2;
    var_a1 = D_80108F8C * 2;
    if (var_a3_2 < var_a0_2) {
        goto block_17;
    }
    if (var_a0_2 == var_a3_2) {
        goto block_16;
    }
loop_9:
    temp_v1_2 = D_80108F8C * 2;
    temp_a2_2 = (u32) D_80102CCC < temp_v1_2;
    temp_a1_2 = D_80102CCC - temp_v1_2;
    temp_a0 = (D_80102CC8 - ((D_80108F88 * 2) | ((u32) D_80108F8C >> 0x1F))) - temp_a2_2;
    D_80102CC8 = temp_a0;
    D_80102CCC = temp_a1_2;
    func_8008188C(temp_a0, temp_a1_2, temp_a2_2, (u32) var_a3_2);
    if (D_800CA338 != 1) {
        goto block_11;
    }
    func_800101D8();
block_11:
    func_80016FCC(var_s0 != 0);
    var_s0 += 1;
    temp_ret_4 = osGetTime();
    temp_v1_3 = (u32) temp_ret_4;
    var_a1 = var_s0;
    temp_lo = var_a1 * D_80108F8C;
    var_a0_2 = temp_v1_3 < (u32) D_8010A39C;
    temp_t0 = (temp_ret_4 - D_8010A398) - var_a0_2;
    var_a2_2 = ((MULTU_HI(var_a1, D_80108F8C) + (var_a1 * D_80108F88) + (D_80108F8C * 0)) * 2) | (temp_lo >> 0x1F);
    var_a3_2 = temp_lo * 2;
    if ((s32) var_a2_2 < temp_t0) {
        goto block_17;
    }
    if (temp_t0 != var_a2_2) {
        goto block_14;
    }
    if ((u32) var_a3_2 < (u32) (temp_v1_3 - D_8010A39C)) {
        goto block_17;
    }
block_14:
    var_a2_2 = (u32) D_80108F8C >> 0x1F;
    var_a0_2 = (D_80108F88 * 2) | var_a2_2;
    var_a1 = D_80108F8C * 2;
    D_800B1D74 += 1;
    if (D_80102CC8 < var_a0_2) {
        goto block_17;
    }
    if (var_a0_2 != D_80102CC8) {
        goto loop_9;
    }
block_16:
    if ((u32) D_80102CCC >= var_a1) {
        goto loop_9;
    }
block_17:
    func_80017454(var_a0_2, var_a1, var_a2_2, (u32) var_a3_2);
    func_800734B8();
    return;
}
