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

M2C_UNK func_8002E8F0(M2C_UNK *, M2C_UNK *, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_8002E93C(M2C_UNK *, u8, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_8002E9C0(M2C_UNK *);                   /* extern */
extern M2C_UNK D_800E1114;
extern M2C_UNK D_800E1310;
extern M2C_UNK D_80100198;
extern M2C_UNK D_8010019C;
extern M2C_UNK D_801001A0;
extern M2C_UNK D_801001A1;
extern M2C_UNK D_801001A2;
extern M2C_UNK D_801001A4;
extern u8 D_801002A0;
extern u8 D_801002A1;
extern u8 D_801002A2;
extern u8 D_801002A4;
extern s32 D_801002C4;
extern u8 D_801002D4;
extern u8 D_801002D5;
extern s32 D_801002EC;
extern u8 D_801002F0;
extern u8 D_801002F1;
extern u8 D_801002F2;
extern u8 D_801002F3;
extern u8 D_80102EE0;
extern s32 D_80102EE4;
extern u8 D_80102EE8;
extern u8 D_8010A4C0;
extern u8 D_8010A4FC;
extern u8 D_8010A4FD;
extern u8 D_8010A4FE;
extern u8 D_8010A4FF;
extern M2C_UNK D_80112F70;
extern M2C_UNK D_80112F7B;
extern M2C_UNK D_80112F7F;
extern M2C_UNK D_80112F82;
extern M2C_UNK D_80115088;
extern M2C_UNK D_80115089;
extern M2C_UNK D_8011508A;
extern M2C_UNK D_8011508B;
extern M2C_UNK D_8011508C;
extern M2C_UNK D_8011508D;
extern M2C_UNK D_8011508E;
extern M2C_UNK D_8011508F;
extern M2C_UNK D_80115090;
extern M2C_UNK D_80115091;
extern M2C_UNK D_80117410;
extern M2C_UNK D_80117416;
extern M2C_UNK D_80117428;
extern M2C_UNK D_8011742E;
extern M2C_UNK D_801176C8;
extern s32 D_80117730;

void func_8002E114(void) {
    s32 temp_a1_2;
    s32 temp_a1_3;
    s32 temp_s0;
    s32 temp_s0_2;
    s32 temp_s0_3;
    s32 temp_s0_4;
    s32 temp_s1;
    s32 var_s1;
    s32 var_s1_2;
    s32 var_s1_3;
    s32 var_s1_4;
    s32 var_s1_5;
    s32 var_s2;
    s32 var_s2_2;
    s32 var_s3;
    s32 var_s4;
    s8 temp_a1;
    u8 temp_a1_4;
    u8 temp_a1_5;
    u8 temp_a1_6;
    u8 temp_a1_7;
    u8 temp_a1_8;

    func_8002E8F0(&D_800E1310, &D_800E1114, 0, 0x1FB);
    var_s4 = 0;
    do {
        temp_s1 = var_s4 & 0xFFFF;
        temp_s0 = temp_s1 * 0xA0;
        var_s3 = 0;
        func_8002E93C(&D_800E1310, *(&D_80115088 + temp_s0), 1, 1);
        func_8002E93C(&D_800E1310, *(&D_80115089 + temp_s0), 1, 1);
        func_8002E93C(&D_800E1310, *(&D_8011508A + temp_s0), 1, 1);
        func_8002E93C(&D_800E1310, *(&D_8011508B + temp_s0), 1, 1);
        func_8002E93C(&D_800E1310, *(&D_8011508C + temp_s0), 1, 1);
        func_8002E93C(&D_800E1310, *(&D_8011508D + temp_s0), 1, 1);
        func_8002E93C(&D_800E1310, *(&D_80115090 + temp_s0), 1, 1);
        func_8002E93C(&D_800E1310, *(&D_80115091 + temp_s0), 1, 4);
        func_8002E93C(&D_800E1310, *(&D_8011508E + temp_s0), 1, 1);
        func_8002E93C(&D_800E1310, *(&D_8011508F + temp_s0), 1, 1);
        temp_s0_2 = temp_s1 * 0x18;
        func_8002E93C(&D_800E1310, *(&D_80100198 + temp_s0_2), 1, 4);
        func_8002E93C(&D_800E1310, (u8) *(&D_8010019C + temp_s0_2), 4, 0x10);
        func_8002E93C(&D_800E1310, *(&D_801001A0 + temp_s0_2), 1, 8);
        func_8002E93C(&D_800E1310, *(&D_801001A1 + temp_s0_2), 1, 1);
        func_8002E93C(&D_800E1310, *(&D_801001A2 + temp_s0_2), 1, 4);
loop_2:
        temp_a1 = *(temp_s0_2 + &D_801001A4 + (var_s3 & 0xFFFF));
        var_s3 += 1;
        func_8002E93C(&D_800E1310, (u8) temp_a1, 1, 8);
        if ((u32) (var_s3 & 0xFFFF) < 9U) {
            goto loop_2;
        }
        var_s4 += 1;
    } while ((u32) (var_s4 & 0xFFFF) < 0xBU);
    var_s2 = 0;
    func_8002E93C(&D_800E1310, D_801002A0, 1, 4);
    func_8002E93C(&D_800E1310, D_801002A1, 1, 1);
    func_8002E93C(&D_800E1310, D_801002A2, 1, 4);
    func_8002E93C(&D_800E1310, D_801002A4, 1, 8);
    func_8002E93C(&D_800E1310, D_801002D4, 1, 4);
    func_8002E93C(&D_800E1310, D_801002D5, 1, 1);
    func_8002E93C(&D_800E1310, (u8) D_80117730, 4, 0x20);
    func_8002E93C(&D_800E1310, (u8) D_801002C4, 4, 0x20);
    func_8002E93C(&D_800E1310, D_80102EE0, 1, 8);
    func_8002E93C(&D_800E1310, (u8) D_80102EE4, 4, 0x20);
    func_8002E93C(&D_800E1310, D_80102EE8, 1, 4);
    func_8002E93C(&D_800E1310, D_8010A4C0, 1, 2);
    func_8002E93C(&D_800E1310, D_8010A4FC, 1, 6);
    func_8002E93C(&D_800E1310, D_8010A4FD, 1, 1);
    func_8002E93C(&D_800E1310, D_8010A4FE, 1, 1);
    func_8002E93C(&D_800E1310, D_8010A4FF, 1, 2);
    func_8002E93C(&D_800E1310, (u8) D_801002EC, 4, 1);
    func_8002E93C(&D_800E1310, D_801002F0, 1, 4);
    func_8002E93C(&D_800E1310, D_801002F1, 1, 4);
    func_8002E93C(&D_800E1310, D_801002F2, 1, 2);
    func_8002E93C(&D_800E1310, D_801002F3, 1, 1);
    do {
        temp_s0_3 = (var_s2 & 0xFFFF) * 8;
        temp_a1_2 = *(&D_80117410 + temp_s0_3);
        var_s2 += 1;
        func_8002E93C(&D_800E1310, (u8) temp_a1_2, 4, 0xD);
        func_8002E93C(&D_800E1310, (u8) *(&D_80117416 + temp_s0_3), 1, 6);
    } while ((u32) (var_s2 & 0xFFFF) < 3U);
    var_s1 = 0;
    do {
        var_s2_2 = 0;
loop_8:
        temp_s0_4 = ((var_s2_2 & 0xFFFF) * 8) + ((var_s1 & 0xFFFF) * 0x18);
        temp_a1_3 = *(&D_80117428 + temp_s0_4);
        var_s2_2 += 1;
        func_8002E93C(&D_800E1310, (u8) temp_a1_3, 4, 4);
        func_8002E93C(&D_800E1310, (u8) *(&D_8011742E + temp_s0_4), 1, 6);
        if ((u32) (var_s2_2 & 0xFFFF) < 3U) {
            goto loop_8;
        }
        temp_a1_4 = *(&D_801176C8 + (var_s1 & 0xFFFF));
        var_s1 += 1;
        func_8002E93C(&D_800E1310, temp_a1_4, 1, 2);
    } while ((u32) (var_s1 & 0xFFFF) < 0xEU);
    var_s1_2 = 0;
    __repair_rows: {
        temp_a1_5 = *(&D_80112F70 + (var_s1_2 & 0xFFFF));
        var_s1_2 += 1;
        func_8002E93C(&D_800E1310, temp_a1_5, 1, 1);
    }
if ((u32) (var_s1_2 & 0xFFFF) < 0xBU) goto __repair_rows;
    var_s1_3 = 0;
    do {
        temp_a1_6 = *(&D_80112F7B + (var_s1_3 & 0xFFFF));
        var_s1_3 += 1;
        func_8002E93C(&D_800E1310, temp_a1_6, 1, 1);
    } while ((u32) (var_s1_3 & 0xFFFF) < 4U);
    var_s1_4 = 0;
    do {
        temp_a1_7 = *(&D_80112F7F + (var_s1_4 & 0xFFFF));
        var_s1_4 += 1;
        func_8002E93C(&D_800E1310, temp_a1_7, 1, 1);
    } while ((u32) (var_s1_4 & 0xFFFF) < 3U);
    var_s1_5 = 0;
    do {
        temp_a1_8 = *(&D_80112F82 + (var_s1_5 & 0xFFFF));
        var_s1_5 += 1;
        func_8002E93C(&D_800E1310, temp_a1_8, 1, 1);
    } while ((u32) (var_s1_5 & 0xFFFF) < 3U);
    func_8002E9C0(&D_800E1310);
}
