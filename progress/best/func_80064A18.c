/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

s32 func_800015AC();
s32 func_80001D80();
s32 func_8000237C();
s32 func_80002BD0();
s32 func_80002D30();
void *func_80015F74();
void *func_800162BC();
void *func_800164F8();
s32 func_80022DBC();
s32 func_8002B9CC();
s32 actorLinkToSurface();
s32 func_800448A4();
s32 func_80063C7C();
s32 func_800643EC();
void *func_80064444();
s32 func_800644CC();
void *func_8006452C();
s32 func_80064630();
s32 func_800649E4();
s32 func_800671E0();
s32 func_80067AE8();
s32 setActionSlot();
s32 func_8007080C();
s32 func_80077C00();
s8 func_80081828();
s32 func_8011ACAC();
s32 func_8011B278();
extern u8 D_800BF688[];
extern u8 D_800C471C[];
extern char D_800C471E[];
extern s32 D_800C7C98;
extern s32 D_800C7C9C;
extern s16 D_800C7D74;
extern s16 D_800C7D98;
extern s32 *gProbeObjectList;
extern s8 D_800E19F4;
extern char gSaveSlotInfo[];
extern u8 D_801001A0[];
extern char D_801001A3[];
extern s32 gSaveSlotCount;
extern char D_80102CD0[];
extern s32 gBorderSkipFlag;
extern u8 D_80102EE8;
extern s8 D_80103EB0;
extern s32 D_80108F78;
extern char gTrackMarkerTable[];
extern char D_8010A500[];
extern u8 D_80112F6D;

void *func_80064A18(s32 arg0, void *arg1, void *arg2, void *arg3) {
    f32 temp_fv0;
    f32 temp_fv0_2;
    s32 var_fv1;
    s16 *temp_s0_2;
    u32 var_fv0;
    f32 temp_fv0_3;
    void *sp14;
    union { s16 * pointer; s32 value; } __repair_phase_storage;
    s32 temp_a1;
    s16 temp_a1_2;
    s16 temp_v0;
    s16 temp_v0_2;
    s16 temp_v1_10;
    s16 temp_v1_11;
    s16 var_s2;
    s32 var_v1;
    s32 var_v1_2;
    s32 temp_s0;
    
    
    s32 temp_s0_5;
    s32 temp_s0_6;
    s32 temp_s1;
    register s32 temp_v1_19;
    s32 var_a1;
    
    s32 var_s5;
    s32 var_v0_2;
    s32 var_v0_3;
    register s32 var_v0_4;
    s32 var_v0_5;
    s32 var_v1_4;
    s8 var_v1_3;
    u16 temp_a0;
    u16 temp_s1_3;
    u16 temp_s2;
    u32 var_s0;
    u8 temp_v1_18;
    u8 var_a3;
    void **temp_a0_2;
    void **temp_v1_17;
    void *temp_a1_3;
    void *temp_s3;
    void *temp_s4;
    void *temp_v0_10;
    void *temp_v0_3;
    void *temp_v0_4;
    void *temp_v0_5;
    void *temp_v0_6;
    void *temp_v0_7;
    void *temp_v0_8;
    void *temp_v0_9;
    void *temp_v1;
    void *temp_v1_12;
    void *temp_v1_13;
    void *temp_v1_14;
    void *temp_v1_15;
    void *temp_v1_16;
    void *temp_v1_20;
    void *temp_v1_2;
    void *temp_v1_3;
    void *temp_v1_4;
    void *temp_v1_5;
    void *temp_v1_6;
    void *temp_v1_7;
    void *temp_v1_8;
    void *temp_v1_9;
    void *var_v0;
    volatile s64 stack_pad;

    sp14 = arg2;
    if ((gBorderSkipFlag != 0) || (var_v0 = NULL, ((*(u16 *)((char *)(arg3) + 0x40)) == D_80102EE8))) {
        temp_s4 = func_800164F8(0x5AC, arg1, 0);
        temp_s0 = (s32) (arg0 << 0x10) >> 0xE;
        D_800E19F4 = 0;
        *(s32 *)(D_8010A500 + temp_s0) = temp_s4; if (temp_s4 != NULL) {
            temp_s3 = (*(void **)((char *)(temp_s4) + 0x6C));
            func_80077C00(temp_s4);
            temp_s1 = arg0 & 0xFF;
            (*(s32 *)((char *)(temp_s3) + 0x1B0)) = 0;
            (*(u8 *)((char *)(temp_s3) + 0x182)) = arg0;
            (*(s8 *)((char *)(temp_s3) + 0x183)) = func_80081828(temp_s1);
            *(s32 *)(D_80102CD0 + temp_s0) = temp_s3;
            (*(s32 *)((char *)(temp_s3) + 0x104)) = 0;
            (*(s32 *)((char *)(temp_s3) + 0x108)) = 0;
            (*(s32 *)((char *)(temp_s3) + 0x10C)) = 0;
            (*(s32 *)((char *)(temp_s3) + 0x110)) = 0;
            (*(s32 *)((char *)(temp_s3) + 0x114)) = 0;
            (*(s32 *)((char *)(temp_s3) + 0x118)) = 0;
            (*(s32 *)((char *)(temp_s3) + 0xC0)) = 0;
            D_80103EB0 = 1;
            (*(s8 *)((char *)(temp_s3) + 0x198)) = 0;
            (*(s8 *)((char *)(temp_s3) + 0x197)) = 0;
            (*(s32 *)((char *)(temp_s3) + 0x1C)) = 0;
            (*(s32 *)((char *)(temp_s3) + 0x20)) = 0;
            (*(s32 *)((char *)(temp_s3) + 0x24)) = 0;
            (*(s32 *)((char *)(temp_s3) + 0x28)) = 0;
            (*(f32 *)((char *)(temp_s3) + 0x9C)) = 3.1415927f;
            if (gBorderSkipFlag) {
                func_8011B278(temp_s3, temp_s1);
            } else {
                (*(s32 *)((char *)(temp_s3) + 0xB4)) = 0;
            }
            (*(s32 *)((char *)(temp_s3) + 0xCC)) = 0;
            (*(s32 *)((char *)(temp_s3) + 4)) = 0;
            (*(s32 *)((char *)(temp_s3) + 0xA8)) = func_800671E0(temp_s4, (s16) arg0);
            (*(s32 *)((char *)(temp_s3) + 0x6C)) = 0;
            (*(s32 *)((char *)(temp_s3) + 0x70)) = 0;
            (*(s32 *)((char *)(temp_s3) + 0x74)) = 0;
            (*(s32 *)((char *)(temp_s3) + 0x78)) = 0;
            (*(s32 *)((char *)(temp_s3) + 0xC)) = -1;
            (*(s32 *)((char *)(temp_s3) + 8)) = -1;
            (*(s16 *)((char *)(temp_s3) + 0x176)) = 0;
            (*(s16 *)((char *)(temp_s3) + 0x178)) = 0;
            (*(s16 *)((char *)(temp_s3) + 0x17A)) = 0;
            (*(s8 *)((char *)(temp_s3) + 0x19A)) = 0;
            (*(void **)((char *)(temp_s3) + 0xAC)) = func_80064444(temp_s4, (s16) arg0);
            (*(void **)((char *)(temp_s3) + 0xB0)) = func_8006452C(temp_s4, (s16) arg0);
            (*(void **)((char *)((*(void **)((char *)(temp_s3) + 0xAC))) + 0x18)) = temp_s4;
            (*(void **)((char *)((*(void **)((char *)(temp_s3) + 0xB0))) + 0x18)) = temp_s4;
            (*(s32 *)((char *)(temp_s3) + 0xC4)) = func_800644CC(temp_s4);
            (*(s32 *)((char *)(temp_s3) + 0xBC)) = 0;
            (*(s16 *)((char *)(temp_s4) + 0x78)) = 2;
            (*(s32 *)((char *)(temp_s4) + 0x3C)) = 0;
            (*(s32 *)((char *)(temp_s4) + 0x44)) = 0;
            (*(f32 *)((char *)(temp_s4) + 0x40)) = (f32) (*(f32 *)((char *)(sp14) + 4));
            var_v1 = 0;
            actorLinkToSurface(*gProbeObjectList, temp_s4, 0);
            (*(s8 *)((char *)(temp_s3) + 0x184)) = 0;
            (*(s8 *)((char *)(temp_s3) + 0x185)) = 0;
            (*(s32 *)((char *)(temp_s3) + 0x410)) = 0;
            (*(s32 *)((char *)(temp_s3) + 0x414)) = 0;
            var_v0_2 = 0 << 0x10;
            do {
                (*(s32 *)((char *)(((var_v0_2 >> 0xE) + temp_s3)) + 0x3D4)) = 0;
                temp_v0 = var_v1 + 1;
                var_v1 = temp_v0;
                var_v0_2 = var_v1 << 0x10;
            } while (4 > temp_v0);
            var_v1_2 = 0;
            var_v0_3 = 0 << 0x10;
            do {
                (*(s32 *)((char *)(((var_v0_3 >> 0xE) + temp_s3)) + 0x3E4)) = 0;
                temp_v0_2 = var_v1_2 + 1;
                var_v1_2 = temp_v0_2;
                var_v0_3 = var_v1_2 << 0x10;
            } while (temp_v0_2 < 6);
            (*(s32 *)((char *)(temp_s3) + 0x3FC)) = 0;
            (*(s32 *)((char *)(temp_s3) + 0x400)) = 0;
            (*(s16 *)((char *)(temp_s3) + 0x520)) = 0x706;
            D_800C7D74 = (s16) (s8) (*(u8 *)((char *)(temp_s3) + 0x182));
            __repair_phase_storage.pointer = &D_800C7D74 - 0x20;
            D_800C7D98 = (s16) (s8) (*(u8 *)((char *)(temp_s3) + 0x182));
            temp_s0_2 = D_800C7D74 + 4;
            (*(void **)((char *)(temp_s3) + 0x404)) = func_80015F74(__repair_phase_storage.pointer);
            (*(void **)((char *)(temp_s3) + 0x408)) = func_80015F74(temp_s0_2);
            (*(void **)((char *)(temp_s3) + 0x478)) = func_80015F74(__repair_phase_storage.pointer);
            (*(void **)((char *)(temp_s3) + 0x47C)) = func_80015F74(__repair_phase_storage.pointer);
            if (gBorderSkipFlag != 0) {
                temp_v1 = (*(void **)((char *)(temp_s3) + 0x478));
                (*(void **)((char *)(temp_s3) + 0x480)) = func_80015F74(temp_s0_2);
                (*(u16 *)((char *)(temp_v1) + 0x26)) = (u16) ((u16) (*(u16 *)((char *)(temp_v1) + 0x26)) >> 1);
                temp_v1_2 = (*(void **)((char *)(temp_s3) + 0x478));
                (*(u8 *)((char *)(temp_v1_2) + 0x29)) = (u8) ((u8) (*(u8 *)((char *)(temp_v1_2) + 0x29)) >> 1);
                (*(s16 *)((char *)((*(void **)((char *)(temp_s3) + 0x480))) + 0x26)) = 0x1A;
                temp_v1_3 = (*(void **)((char *)(temp_s3) + 0x47C));
                (*(u16 *)((char *)(temp_v1_3) + 0x26)) = (u16) ((u16) (*(u16 *)((char *)(temp_v1_3) + 0x26)) >> 1);
                temp_v1_4 = (*(void **)((char *)(temp_s3) + 0x47C));
                (*(u8 *)((char *)(temp_v1_4) + 0x29)) = (u8) ((u8) (*(u8 *)((char *)(temp_v1_4) + 0x29)) >> 1);
                temp_v1_5 = (*(void **)((char *)(temp_s3) + 0x404));
                (*(u16 *)((char *)(temp_v1_5) + 0x26)) = (u16) ((u16) (*(u16 *)((char *)(temp_v1_5) + 0x26)) >> 1);
                temp_v1_6 = (*(void **)((char *)(temp_s3) + 0x404));
                (*(u8 *)((char *)(temp_v1_6) + 0x29)) = (u8) ((u8) (*(u8 *)((char *)(temp_v1_6) + 0x29)) >> 1);
                temp_v1_7 = (*(void **)((char *)(temp_s3) + 0x408));
                (*(u16 *)((char *)(temp_v1_7) + 0x26)) = (u16) ((u16) (*(u16 *)((char *)(temp_v1_7) + 0x26)) >> 1);
                temp_v1_8 = (*(void **)((char *)(temp_s3) + 0x408));
                (*(u8 *)((char *)(temp_v1_8) + 0x29)) = (u8) ((u8) (*(u8 *)((char *)(temp_v1_8) + 0x29)) >> 1);
                var_fv1 = 0x18;
                (*(s16 *)((char *)((*(void **)((char *)(temp_s3) + 0x480))) + 0x20)) = 0x18;
                var_s5 = 3;
                var_s2 = 0x12;
                (*(s16 *)((char *)((*(void **)((char *)(temp_s3) + 0x480))) + 0x22)) = 0x12;
            } else {
                temp_v0_3 = func_800162BC((s8) (*(u8 *)((char *)(temp_s3) + 0x182)));
                func_800448A4(temp_v0_3, 0x2B, 0x1B);
                (*(s16 *)((char *)(temp_v0_3) + 0x20)) = 0x14;
                (*(s16 *)((char *)(temp_v0_3) + 0x22)) = 0x13;
                (*(s32 *)((char *)(temp_v0_3) + 0x10)) = 0xFF0000C8;
                (*(u16 *)((char *)(temp_v0_3) + 0x1E)) |= 2;
                (*(s32 *)((char *)(temp_v0_3) + 0x28)) = (s32) (((*(s32 *)((char *)(temp_v0_3) + 0x28)) & ~0xFC) | 0x10);
                (*(void **)((char *)(temp_s3) + 0x484)) = temp_v0_3;
                temp_v0_4 = func_800162BC((s8) (*(u8 *)((char *)(temp_s3) + 0x182)));
                func_800448A4(temp_v0_4, 0x2C, 0x1B);
                (*(s16 *)((char *)(temp_v0_4) + 0x20)) = 0x55;
                (*(s32 *)((char *)(temp_v0_4) + 0x10)) = 0xFFC8;
                (*(s16 *)((char *)(temp_v0_4) + 0x22)) = 0x13;
                (*(s32 *)((char *)(temp_v0_4) + 0x28)) = (s32) (((*(s32 *)((char *)(temp_v0_4) + 0x28)) & ~0xFC) | 0x1C);
                (*(u16 *)((char *)(temp_v0_4) + 0x1E)) |= 2;
                (*(void **)((char *)(temp_s3) + 0x488)) = temp_v0_4;
                temp_v0_5 = func_800162BC((s8) (*(u8 *)((char *)(temp_s3) + 0x182)));
                (*(void **)((char *)(temp_s3) + 0x480)) = temp_v0_5;
                func_800448A4(temp_v0_5, 0xC, 0x2A);
                temp_v1_9 = (*(void **)((char *)(temp_s3) + 0x480));
                (*(u16 *)((char *)(temp_v1_9) + 0x1E)) |= 2;
                var_fv1 = 0x24;
                (*(s16 *)((char *)((*(void **)((char *)(temp_s3) + 0x480))) + 0x20)) = 0x16;
                var_s2 = 0x15;
                var_s5 = 6;
                (*(s16 *)((char *)((*(void **)((char *)(temp_s3) + 0x480))) + 0x22)) = 0x13;
            }
            temp_v1_10 = var_fv1 + 1;
            (*(s16 *)((char *)((*(void **)((char *)(temp_s3) + 0x478))) + 0x20)) = temp_v1_10;
            temp_a1 = var_s2 + 1;
            (*(s16 *)((char *)((*(void **)((char *)(temp_s3) + 0x478))) + 0x22)) = temp_a1;
            (*(s16 *)((char *)((*(void **)((char *)(temp_s3) + 0x47C))) + 0x20)) = temp_v1_10;
            (*(s16 *)((char *)((*(void **)((char *)(temp_s3) + 0x47C))) + 0x22)) = (s16) (var_s5 + temp_a1);
            temp_v1_11 = 0x114 - var_fv1;
            (*(s16 *)((char *)((*(void **)((char *)(temp_s3) + 0x404))) + 0x20)) = (s16) (temp_v1_11 + 1);
            (*(s16 *)((char *)((*(void **)((char *)(temp_s3) + 0x404))) + 0x22)) = temp_a1;
            (*(s16 *)((char *)((*(void **)((char *)(temp_s3) + 0x408))) + 0x20)) = temp_v1_11;
            (*(s16 *)((char *)((*(void **)((char *)(temp_s3) + 0x408))) + 0x22)) = var_s2;
            temp_v0_6 = func_800162BC((s8) (*(u8 *)((char *)(temp_s3) + 0x182)), temp_a1);
            (*(void **)((char *)(temp_s3) + 0x40C)) = temp_v0_6;
            func_800448A4(temp_v0_6, 0x30, 0x1B);
            temp_v1_12 = (*(void **)((char *)(temp_s3) + 0x40C));
            (*(u16 *)((char *)(temp_v1_12) + 0x1E)) |= 2;
            (*(s16 *)((char *)((*(void **)((char *)(temp_s3) + 0x40C))) + 0x20)) = 0xE0;
            (*(s16 *)((char *)((*(void **)((char *)(temp_s3) + 0x40C))) + 0x22)) = 0x11;
            temp_v1_13 = (*(void **)((char *)(temp_s3) + 0x40C));
            (*(s32 *)((char *)(temp_v1_13) + 0x28)) = (s32) (((*(s32 *)((char *)(temp_v1_13) + 0x28)) & ~0xFC) | 0x1C);
            (*(s32 *)((char *)((*(void **)((char *)(temp_s3) + 0x40C))) + 0x10)) = 0xFFFF00;
            temp_v1_14 = (*(void **)((char *)(temp_s3) + 0x478));
            (*(s32 *)((char *)(temp_v1_14) + 0x28)) = (s32) (((*(s32 *)((char *)(temp_v1_14) + 0x28)) & ~0xFC) | 0x10);
            temp_v1_15 = (*(void **)((char *)(temp_s3) + 0x480));
            (*(s32 *)((char *)(temp_v1_15) + 0x28)) = (s32) (((*(s32 *)((char *)(temp_v1_15) + 0x28)) & ~0xFC) | 0x10);
            temp_v1_16 = (*(void **)((char *)(temp_s3) + 0x47C));
            (*(s32 *)((char *)(temp_v1_16) + 0x28)) = (s32) (((*(s32 *)((char *)(temp_v1_16) + 0x28)) & ~0xFC) | 0x10);
            (*(s32 *)((char *)((*(void **)((char *)(temp_s3) + 0x478))) + 0x10)) = 0xAA00FF;
            (*(s32 *)((char *)((*(void **)((char *)(temp_s3) + 0x480))) + 0x10)) = 0xC8;
            (*(s32 *)((char *)((*(void **)((char *)(temp_s3) + 0x47C))) + 0x10)) = 0xAAFF;
            (*(s32 *)((char *)((*(void **)((char *)(temp_s3) + 0x404))) + 0x10)) = 0xAAAA00;
            (*(s32 *)((char *)((*(void **)((char *)(temp_s3) + 0x408))) + 0x10)) = 0;
            func_8007080C(temp_s3);
            func_800649E4(temp_s4);
            temp_v1_17 = ((s32) (arg0 << 0x10) >> 0xE) + gTrackMarkerTable;
            (*(f32 *)((char *)(*temp_v1_17) + 0x4C)) = 1.0f;
            temp_v0_7 = *temp_v1_17;
            temp_fv0 = (*(f32 *)((char *)(arg1) + 0));
            (*(f32 *)((char *)(temp_v0_7) + 0x10)) = temp_fv0;
            (*(f32 *)((char *)(temp_v0_7) + 0x28)) = temp_fv0;
            temp_v0_8 = *temp_v1_17;
            temp_fv0_2 = (*(f32 *)((char *)(arg1) + 4));
            (*(f32 *)((char *)(temp_v0_8) + 0x14)) = temp_fv0_2;
            (*(f32 *)((char *)(temp_v0_8) + 0x2C)) = temp_fv0_2;
            temp_v0_9 = *temp_v1_17;
            temp_fv0_3 = (*(f32 *)((char *)(arg1) + 8));
            (*(f32 *)((char *)(temp_v0_9) + 0x18)) = temp_fv0_3;
            (*(f32 *)((char *)(temp_v0_9) + 0x30)) = temp_fv0_3;
            (*(f32 *)((char *)(*temp_v1_17) + 0x38)) = (f32) (*(f32 *)((char *)(sp14) + 4));
            (*(s32 *)((char *)(*temp_v1_17) + 0xF4)) = 0;
            (*(void **)((char *)(*temp_v1_17) + 0x138)) = temp_s4;
            (*(s32 *)((char *)(*temp_v1_17) + 0x130)) = 0;
            func_80001D80(0);
            var_fv1 = arg0 & 0xFFFF;
            if (gBorderSkipFlag) {
                __repair_phase_storage.value = func_8002B9CC(*(s32 *)(gSaveSlotInfo + ((func_80022DBC(var_fv1) & 0xFFFF) * 0x18)));
                var_a3 = *(D_801001A3 + ((func_80022DBC(var_fv1) & 0xFFFF) * 0x18));
                var_a1 = __repair_phase_storage.value;
            } else {
                switch (D_80108F78) {               /* switch 1 */
                default:                            /* switch 1 */
                    var_a1 = 0x11;
                    break;
                case 25:                            /* switch 1 */
                    var_a1 = 0x10;
                    break;
                case 1:                             /* switch 1 */
                case 38:                            /* switch 1 */
                    var_a1 = 0xC;
                    break;
                case 11:                            /* switch 1 */
                    var_a1 = 0xE;
                    break;
                case 18:                            /* switch 1 */
                case 28:                            /* switch 1 */
                case 29:                            /* switch 1 */
                case 33:                            /* switch 1 */
                    var_a1 = 0xB;
                    break;
                }
                var_a3 = 0;
            }
            func_8000237C(temp_s4, var_a1, 1, var_a3);
            func_80002BD0(temp_s4, 0x159);
            (*(s8 *)((char *)(temp_s3) + 0x18F)) = 0;
            func_80064630(temp_s4);
            func_800015AC(temp_s4, 0);
            func_800643EC(temp_s4);
            temp_a1_2 = (*(s16 *)((char *)((*(void **)((char *)(temp_s4) + 0x68))) + 0xA2));
            if (temp_a1_2 != 0) {
                func_80002D30(temp_s4, temp_a1_2);
            }
            func_80067AE8(temp_s4);
            temp_v0_10 = (*(void **)((char *)(temp_s4) + 0x68));
            temp_v1_18 = (*(u8 *)((char *)(temp_v0_10) + 0xE));
            (*(u8 *)((char *)(temp_v0_10) + 0xF)) = temp_v1_18;
            (*(u8 *)((char *)(temp_v0_10) + 0x10)) = temp_v1_18;
            if (gBorderSkipFlag == 0) {
                temp_a0 = (*(u16 *)((char *)(arg3) + 0x2C));
                temp_s1_3 = (*(u16 *)((char *)(arg3) + 0x30));
                temp_s0 = (u16)((*(u16 *)((char *)(arg3) + 0x32)));
                temp_s0_5 = temp_a0 * 0xE8;
                (*(s8 *)((char *)((temp_s3 + (temp_a0 * 8))) + 0x1FC)) = 1;
                (*(u16 *)((char *)((temp_s3 + (*(D_800C471C + temp_s0_5) * 2))) + 0x1BC)) = (u16) (*(u16 *)((char *)(arg3) + 0x2E));
                (*(u8 *)((char *)((temp_s3 + ((s32) (func_80063C7C((s16) temp_a0) << 0x10) >> 0xD))) + 0x1FF)) = (u8) *(D_800C471E + temp_s0_5);
                temp_s0_6 = temp_s1_3 * 0xE8;
                (*(s8 *)((char *)((temp_s3 + (temp_s1_3 * 8))) + 0x1FC)) = 1;
                (*(u16 *)((char *)((temp_s3 + (*(D_800C471C + temp_s0_6) * 2))) + 0x1BC)) = temp_s0;
                (*(u8 *)((char *)((temp_s3 + ((s32) (func_80063C7C((s16) temp_s1_3) << 0x10) >> 0xD))) + 0x1FF)) = (u8) *(D_800C471E + temp_s0_6);
                if (((D_80108F78 == 0x26) | (D_80108F78 == 1)) != 0) {
                    (*(s8 *)((char *)(temp_s3) + 0x21E)) = 1;
                }
                if (D_80108F78 != 0x19) {
                    (*(s8 *)((char *)(temp_s3) + 0x304)) = 1;
                    (*(s8 *)((char *)(temp_s3) + 0x30C)) = 1;
                    (*(s8 *)((char *)(temp_s3) + 0x314)) = 1;
                    (*(s8 *)((char *)(temp_s3) + 0x31C)) = 1;
                    (*(s8 *)((char *)(temp_s3) + 0x307)) = 0x64;
                    (*(s8 *)((char *)(temp_s3) + 0x317)) = 0x64;
                    var_v1_3 = 0xC;
                    if (D_80108F78 != 2) {
                        var_v1_3 = -(D_80108F78 == 0x26) & 0xC;
                    }
                    (*(s8 *)((char *)(temp_s3) + 0x30F)) = var_v1_3;
                }
                setActionSlot(temp_s3, (*(u8 *)((char *)(arg3) + 0x35)), 1, 1);
                setActionSlot(temp_s3, (*(u8 *)((char *)(arg3) + 0x37)), 1, 1);
                setActionSlot(temp_s3, (*(u8 *)((char *)(arg3) + 0x39)), 1, 1);
                setActionSlot(temp_s3, (*(u8 *)((char *)(arg3) + 0x3B)), 1, 1);
                setActionSlot(temp_s3, (*(u8 *)((char *)(arg3) + 0x3F)), 1, 1);
                if (D_80112F6D != 0) {
                    var_s0 = 0;
                    do {
                        setActionSlot(temp_s3, var_s0 & 0xFF, 1, 0);
                        var_s0 += 1;
                    } while (var_s0 < 0x1EU);
                }
            }
            var_v0_4 = arg0 << 0x10;
            temp_v1_19 = var_v0_4 >> 0x10;
            switch (temp_v1_19) {                   /* switch 2; irregular */
            case 0:                                 /* switch 2 */
                var_v1_4 = 0x7D000;
                var_v0_5 = 0x2000;
                (*(s32 *)((char *)(temp_s4) + 0x5C)) = var_v0_5;
                (*(s32 *)((char *)(temp_s3) + 0)) = var_v1_4;
                break;
            case 1:                                 /* switch 2 */
                var_v1_4 = 0x7B000;
                var_v0_5 = 0x4000;
                (*(s32 *)((char *)(temp_s4) + 0x5C)) = var_v0_5;
                (*(s32 *)((char *)(temp_s3) + 0)) = var_v1_4;
                break;
            case 2:                                 /* switch 2 */
                var_v1_4 = 0x77000;
                var_v0_5 = 0x8000;
                (*(s32 *)((char *)(temp_s4) + 0x5C)) = var_v0_5;
                (*(s32 *)((char *)(temp_s3) + 0)) = var_v1_4;
                break;
            case 3:                                 /* switch 2 */
                var_v1_4 = 0x6F000;
                var_v0_5 = 0x10000;
                (*(s32 *)((char *)(temp_s4) + 0x5C)) = var_v0_5;
                (*(s32 *)((char *)(temp_s3) + 0)) = var_v1_4;
                break;
            }
            (*(s32 *)((char *)(temp_s4) + 0x58)) |= 0x2400;
            temp_a0_2 = ((s16) arg0 * 4) + gTrackMarkerTable;
            (*(s32 *)((char *)(temp_s4) + 0x5C)) |= 0x600;
            temp_a1_3 = *temp_a0_2;
            (*(s32 *)((char *)(temp_a1_3) + 0x100)) &= ~7;
            temp_v1_20 = *temp_a0_2;
            (*(s32 *)((char *)(temp_v1_20) + 0x100)) |= 1;
            (*(u8 *)((char *)(temp_s4) + 0x7F)) = 0xFF;
            (*(u8 *)((char *)(temp_s4) + 0x80)) = 0xFF;
            (*(u8 *)((char *)(temp_s4) + 0x81)) = 0xFF;
            (*(u8 *)((char *)(temp_s4) + 0x82)) = 0xFF;
            (*(s8 *)((char *)(temp_s4) + 0x7E)) = 1;
            (*(s32 *)((char *)(temp_s3) + 0x60)) = 0;
            (*(s32 *)((char *)(temp_s3) + 0x64)) = 0;
            if (gBorderSkipFlag != 0) {
                if ((s16) arg0 < gSaveSlotCount) {
                    (*(f32 *)((char *)(temp_s4) + 0x74)) = (f32) *(D_801001A0 + ((func_80022DBC(arg0 & 0xFFFF, temp_a1_3, (s16) arg0) & 0xFFFF) * 0x18));
                } else {
                    (*(f32 *)((char *)(temp_s4) + 0x74)) = (f32) (*(D_800BF688 + (*(s32 *)(gSaveSlotInfo + ((func_80022DBC(arg0 & 0xFFFF, temp_a1_3, (s16) arg0) & 0xFFFF) * 0x18)) * 0xC)) * 5);
                }
            } else {
                (*(f32 *)((char *)(temp_s4) + 0x74)) = 100.0f;
            }
            (*(s8 *)((char *)(temp_s3) + 0x199)) = 0;
            (*(u8 *)((char *)(temp_s3) + 0x18D)) = 0x80;
            (*(s8 *)((char *)(temp_s3) + 0x18C)) = 0;
            (*(f32 *)((char *)(temp_s3) + 0x68)) = (f32) (*(f32 *)((char *)(temp_s4) + 0x74));
            if (gBorderSkipFlag != 0) {
                func_8011ACAC(temp_s4, temp_s3, arg0 & 0xFF);
            }
            (*(s8 *)((char *)(temp_s3) + 0x17E)) = 3;
            (*(f32 *)((char *)((*(void **)((char *)(temp_s4) + 0x68))) + 8)) = (f32) ((*(f32 *)((char *)(temp_s4) + 0x28)) - 2.0f);
        }
        if (gBorderSkipFlag != 0) {
            var_fv0 = 0x41200000;
            var_fv1 = 0x41800000;
            goto block_65;
        }
        if (D_80102EE8 != 1) {
            if ((2 > D_80102EE8) || (var_v0 = temp_s4, (D_80102EE8 != 2))) {
                var_fv1 = 0x41900000;
                var_fv0 = 0x41400000;
                goto block_65;
            }
            D_800C7C98 = 0;
            D_800C7C9C = 0;
            /* Duplicate return node #67. Try simplifying control flow for better match */
            return var_v0;
        }
        var_fv0 = 0x41000000;
        var_fv1 = 0x41600000;
block_65:
        D_800C7C98 = var_fv0;
        D_800C7C9C = var_fv1;
        return temp_s4;
    }
    return var_v0;
}
