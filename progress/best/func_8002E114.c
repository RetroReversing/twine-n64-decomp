/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

s32 func_8002E8F0(s32 *, s32 *, s32, s32); /* extern */
s32 func_8002E93C(s32 *, u8, s32, s32); /* extern */
s32 func_8002E9C0(s32 *);                   /* extern */
extern s32 D_800E1114;
extern s32 D_800E1310;
extern s32 D_80100198;
extern s32 D_8010019C;
extern s32 D_801001A0;
extern s32 D_801001A1;
extern s32 D_801001A2;
extern s32 D_801001A4;
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
extern s32 D_80112F70;
extern s32 D_80112F7B;
extern s32 D_80112F7F;
extern s32 D_80112F82;
extern s32 D_80115088;
extern s32 D_80115089;
extern s32 D_8011508A;
extern s32 D_8011508B;
extern s32 D_8011508C;
extern s32 D_8011508D;
extern s32 D_8011508E;
extern s32 D_8011508F;
extern s32 D_80115090;
extern s32 D_80115091;
extern s32 D_80117410;
extern s32 D_80117416;
extern s32 D_80117428;
extern s32 D_8011742E;
extern s32 D_801176C8;
extern s32 D_80117730;

void func_8002E114(void) {
    register s32 temp_s1;
    s32 temp_s0_4;
    s32 temp_s0;
    u32 temp_s0_2;
    u8 temp_a1_7;
    s32 var_s1_3;
    unsigned int temp_a1_2;
    unsigned var_s1;
    register unsigned var_s1_2;
    unsigned var_s3;
    unsigned temp_a1_3;
    s8 temp_a1;
    unsigned int var_s2;
    unsigned int var_s2_2;
    u8 temp_a1_8;
    register int var_s4;
    s32 var_s1_5;
    register u8 temp_a1_4;
    register u8 temp_a1_5;
    register u8 temp_a1_6;
    register s32 temp_s0_3;
    long var_s1_4;

    func_8002E8F0(&D_800E1310, &D_800E1114, 0, 0x1FB);
    var_s4 = 0;
    do {
        var_s1_3 = var_s4 & 0xFFFF;
        temp_s0 = var_s1_3 * 0xA0;
        var_s3 = 0;
        func_8002E93C(&D_800E1310, *((s32 *)((s8 *)&D_80115088 + temp_s0)), 1, 1);
        func_8002E93C(&D_800E1310, *((s32 *)((s8 *)&D_80115089 + temp_s0)), 1, 1);
        func_8002E93C(&D_800E1310, *((s32 *)((s8 *)&D_8011508B + temp_s0)), 1, 1);
        func_8002E93C(&D_800E1310, *((s32 *)((s8 *)&D_8011508A + temp_s0)), 1, 1);
        func_8002E93C(&D_800E1310, *((s32 *)((s8 *)&D_8011508C + temp_s0)), 1, 1);
        func_8002E93C(&D_800E1310, *((s32 *)((s8 *)&D_80115090 + temp_s0)), 1, 1);
        func_8002E93C(&D_800E1310, *((s32 *)((s8 *)&D_8011508D + temp_s0)), 1, 1);
        func_8002E93C(&D_800E1310, *((s32 *)((s8 *)&D_80115091 + temp_s0)), 1, 4);
        func_8002E93C(&D_800E1310, *((s32 *)((s8 *)&D_8011508F + temp_s0)), 1, 1);
        func_8002E93C(&D_800E1310, *((s32 *)((s8 *)&D_8011508E + temp_s0)), 1, 1);
        temp_s0_2 = var_s1_3 * 0x18;
        func_8002E93C(&D_800E1310, *((s32 *)((s8 *)&D_80100198 + temp_s0_2)), 1, 4);
        func_8002E93C(&D_800E1310, (u8) *((s32 *)((s8 *)&D_8010019C + temp_s0_2)), 4, 0x10);
        func_8002E93C(&D_800E1310, *((s32 *)((s8 *)&D_801001A0 + temp_s0_2)), 1, 8);
        func_8002E93C(&D_800E1310, *((s32 *)((s8 *)&D_801001A1 + temp_s0_2)), 1, 1);
        func_8002E93C(&D_800E1310, *((s32 *)((s8 *)&D_801001A2 + temp_s0_2)), 1, 4);
loop_2:
        temp_a1 = *(temp_s0_2 + &D_801001A4 + (var_s3 & 0xFFFF));
        func_8002E93C(&D_800E1310, (u8) temp_a1, 1, 8);
        var_s3++;
        if ((u32) (var_s3 & 0xFFFF) < 9U) {
            goto loop_2;
        }
        var_s4++;
    } while ((u32) (var_s4 & 0xFFFF) < 0xBU);
    var_s2 = 0;
    func_8002E93C(&D_800E1310, D_801002A0, 1, 4);
    func_8002E93C(&D_800E1310, D_801002A1, 1, 1);
    func_8002E93C(&D_800E1310, D_801002A2, 1, 4);
    func_8002E93C(&D_800E1310, D_801002A4, 1, 8);
    func_8002E93C(&D_800E1310, D_801002D4, 1, 4);
    func_8002E93C(&D_800E1310, (u8) D_80117730, 4, 0x20);
    func_8002E93C(&D_800E1310, D_801002D5, 1, 1);
    func_8002E93C(&D_800E1310, (u8) D_801002C4, 4, 0x20);
    func_8002E93C(&D_800E1310, (u8) D_80102EE4, 4, 0x20);
    func_8002E93C(&D_800E1310, D_80102EE0, 1, 8);
    func_8002E93C(&D_800E1310, D_80102EE8, 1, 4);
    func_8002E93C(&D_800E1310, D_8010A4C0, 1, 2);
    func_8002E93C(&D_800E1310, D_8010A4FD, 1, 1);
    func_8002E93C(&D_800E1310, D_8010A4FC, 1, 6);
    func_8002E93C(&D_800E1310, D_8010A4FE, 1, 1);
    func_8002E93C(&D_800E1310, D_8010A4FF, 1, 2);
    func_8002E93C(&D_800E1310, (u8) D_801002EC, 4, 1);
    func_8002E93C(&D_800E1310, D_801002F0, 1, 4);
    func_8002E93C(&D_800E1310, D_801002F2, 1, 2);
    func_8002E93C(&D_800E1310, D_801002F1, 1, 4);
    func_8002E93C(&D_800E1310, D_801002F3, 1, 1);
    do {
        temp_s0_3 = (var_s2 & 0xFFFF) * 8;
        temp_a1_2 = *((s32 *)((s8 *)&D_80117410 + temp_s0_3));
        func_8002E93C(&D_800E1310, (u8) temp_a1_2, 4, 0xD);
        var_s2++;
        func_8002E93C(&D_800E1310, (u8) *((s32 *)((s8 *)&D_80117416 + temp_s0_3)), 1, 6);
    } while ((u32) (var_s2 & 0xFFFF) < 3U);
    var_s1 = 0;
    do {
        var_s2_2 = 0;
do {
        temp_s0_4 = ((var_s2_2 & 0xFFFF) * 8) + ((var_s1 & 0xFFFF) * 0x18);
        temp_a1_3 = *((s32 *)((s8 *)&D_80117428 + temp_s0_4));
        func_8002E93C(&D_800E1310, (u8) temp_a1_3, 4, 4);
        var_s2_2 += 1;
        func_8002E93C(&D_800E1310, (u8) *((s32 *)((s8 *)&D_8011742E + temp_s0_4)), 1, 6);
        } while ((u32) (var_s2_2 & 0xFFFF) < 3U);
        var_s1_2 = var_s1 & 0xFFFF;
    temp_a1_4 = *((s32 *)((s8 *)&D_801176C8 + (var_s1_2)));
        func_8002E93C(&D_800E1310, temp_a1_4, 1, 2);
        var_s1++;
    } while ((u32) (var_s1 & 0xFFFF) < 0xEU);
    var_s1_2 = 0;
    __repair_rows: {
        temp_a1_5 = *((s32 *)((s8 *)&D_80112F70 + (var_s1_2 & 0xFFFF)));
        func_8002E93C(&D_800E1310, temp_a1_5, 1, 1);
        var_s1_2 += 1;
    }
if ((u32) (var_s1_2 & 0xFFFF) < 0xBU) goto __repair_rows;
    var_s1_3 = 0;
    do {
        temp_a1_6 = *((s32 *)((s8 *)&D_80112F7B + (var_s1_3 & 0xFFFF)));
        func_8002E93C(&D_800E1310, temp_a1_6, 1, 1);
        var_s1_3 += 1;
    } while ((u32) (var_s1_3 & 0xFFFF) < 4U);
    var_s1_4 = 0;
    do {
        temp_a1_7 = *((s32 *)((s8 *)&D_80112F7F + (var_s1_4 & 0xFFFF)));
        func_8002E93C(&D_800E1310, temp_a1_7, 1, 1);
        var_s1_4 += 1;
    } while ((u32) (var_s1_4 & 0xFFFF) < 3U);
    var_s1_5 = 0;
    do {
        temp_a1_8 = *((s32 *)((s8 *)&D_80112F82 + (var_s1_5 & 0xFFFF)));
        func_8002E93C(&D_800E1310, temp_a1_8, 1, 1);
        var_s1_5 += 1;
    } while ((u32) (var_s1_5 & 0xFFFF) < 3U);
    func_8002E9C0(&D_800E1310);
}
