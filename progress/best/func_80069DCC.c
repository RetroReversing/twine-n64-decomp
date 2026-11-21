
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
M2C_UNK func_80002BD0(void *, M2C_UNK);
M2C_UNK func_80002D30(void *, u16);
M2C_UNK func_80002D50(void *, M2C_UNK);
M2C_UNK func_80002EF0(void *);
M2C_UNK listUnlinkFree(s32);
M2C_UNK requestSound();
void *func_80015DAC(s8);
M2C_UNK func_800179E8(void *, void *, s32, s32);
M2C_UNK func_800452E0(void *, void *, f32 *);
f32 func_8004572C(f32 *);

M2C_UNK func_80047B14(void *, M2C_UNK, void *);
M2C_UNK func_80047FB4(s32, s32);
s32 func_8004BCC0(void *, void *, f32 *, M2C_UNK);
M2C_UNK func_800635BC(void *, M2C_UNK);
f32 func_80063758(f32, f32, s32);
M2C_UNK updateHudSprites(void *);
M2C_UNK func_80064318(s32, s8);
M2C_UNK func_80065684(void *);
M2C_UNK actorInitFromSpawn(void *, void *, void *);
M2C_UNK func_80065D90(void *);
M2C_UNK updateSwayMotion(void *);
M2C_UNK func_80067E94(void *);
M2C_UNK func_8006899C(void *, M2C_UNK);
M2C_UNK func_80069250(void *);
M2C_UNK func_800698D8(void *, f32, f32);
f32 func_80069998(f32);
f32 func_80069A14(f32);
s32 func_80069A90(void *);
M2C_UNK func_80069BC8(void *);
M2C_UNK func_8006D2E4(void *);
M2C_UNK func_8006E648(void *, void *, M2C_UNK, M2C_UNK *, M2C_UNK *, M2C_UNK *, M2C_UNK *, M2C_UNK *);
f32 probeTrackSteerAngle(void *, void *);
M2C_UNK setTrackMarkerActive(M2C_UNK, void *);
M2C_UNK func_8007092C(void *, M2C_UNK);
M2C_UNK func_80070F34(void *);
M2C_UNK actorUpdateGatedState(void *, M2C_UNK);
s32 func_800818AC(s32, M2C_UNK);
s32 func_8008194C(s32, M2C_UNK);
s32 func_800819EC(s32, M2C_UNK);
s32 func_80081AA4(s32, M2C_UNK);
f32 func_80081B44(s32, M2C_UNK, M2C_UNK);
M2C_UNK func_80081CC0(s32);
M2C_UNK func_80081D00(s32);
M2C_UNK func_80081D20(s32, M2C_UNK);
f32 absFloat(f32);
f32 func_8008292C(f32);
f32 func_80082968(f32);
f32 sinAngle(f32);
f32 cosAngle(f32);
M2C_UNK func_80119DB4(void *, void *);
M2C_UNK func_8011A234(void *, void *, f32, f32, s32, s32);
extern M2C_UNK D_800C4710;
extern M2C_UNK D_800C7C8E;
extern f32 D_800C7DBC;
extern f32 D_800C7DC4;
extern f64 D_800D45E0;
extern f64 D_800D45E8;
extern f32 D_800E19F0;
extern f32 D_800E19F8;
extern f32 D_800E1A04;
extern f32 D_800E1A08;
extern u8 D_800E1A0C;
extern f32 D_800E1A10;
extern s16 D_800E1A14;
extern u8 D_800E1A16;
extern s32 D_800E1A18;
extern f32 D_800E1A1C;
extern s8 D_800E1A20;
extern s32 D_800E1A24;
extern s32 D_800E1A28;
extern s32 D_800E1A2C;
extern u8 D_801002AE;
extern s32 gSaveSlotCount;
extern s32 gBorderSkipFlag;
extern s8 D_80103EB0;
extern s32 gGameMode;
extern M2C_UNK gTrackMarkerTable;
extern u8 gSceneFlagsB;
extern M2C_UNK D_8011508B;
typedef struct { f32 __repair_v[3]; } __repair_vec3;
void func_80069DCC(void *arg0) {
volatile s32 unused_stack[4];
f32 sp20;
f32 sp24;
f32 sp28;
M2C_UNK sp30;
M2C_UNK sp34;
M2C_UNK sp38;
M2C_UNK sp3C;
M2C_UNK sp40;
f32 sp48;
f32 sp4C;
f32 sp50;
f32 sp5C;
void *sp64;
f32 temp_fa0;
f32 temp_fa0_2;
f32 temp_fa0_3;
f32 temp_fa0_4;
f32 temp_fs0;
f32 temp_fs0_2;
f32 temp_fs0_3;
f32 temp_fs0_4;
f32 temp_fs0_5;
f32 temp_fs1;
f32 temp_fs1_2;
f32 temp_fs2;
f32 temp_fs2_2;
f32 temp_fs2_3;
f32 temp_fs3;
f32 temp_fs3_10;
f32 temp_fs3_11;
f32 temp_fs3_2;
f32 temp_fs3_3;
f32 temp_fs3_4;
f32 temp_fs3_5;
f32 temp_fs3_6;
f32 temp_fs3_7;
f32 temp_fs3_8;
f32 temp_fs3_9;
f32 temp_fs4;
f32 temp_fs5;
f32 temp_fs5_2;
f32 temp_ft0;
f32 temp_ft0_2;
f32 temp_ft0_3;
f32 temp_ft1;
f32 temp_ft1_2;
f32 temp_fv0;
f32 temp_fv0_10;
f32 temp_fv0_11;
f32 temp_fv0_12;
f32 temp_fv0_13;
f32 temp_fv0_14;
f32 temp_fv0_15;
f32 temp_fv0_16;
f32 temp_fv0_17;
f32 temp_fv0_18;
f32 temp_fv0_19;
f32 temp_fv0_20;
f32 temp_fv0_21;
f32 temp_fv0_22;
f32 temp_fv0_23;
f32 temp_fv0_24;
f32 temp_fv0_25;
f32 temp_fv0_26;
f32 temp_fv0_27;
f32 temp_fv0_28;
f32 temp_fv0_29;
f32 temp_fv0_2;
f32 temp_fv0_30;
f32 temp_fv0_31;
f32 temp_fv0_32;
f32 temp_fv0_3;
f32 temp_fv0_4;
f32 temp_fv0_5;
f32 temp_fv0_6;
f32 temp_fv0_7;
f32 temp_fv0_8;
f32 temp_fv0_9;
f32 temp_fv1;
f32 temp_fv1_10;
f32 temp_fv1_11;
f32 temp_fv1_12;
f32 temp_fv1_13;
f32 temp_fv1_2;
f32 temp_fv1_3;
f32 temp_fv1_4;
f32 temp_fv1_5;
f32 temp_fv1_6;
f32 temp_fv1_7;
f32 temp_fv1_8;
f32 temp_fv1_9;
f32 temp_s5;
f32 temp_s5_2;
f32 temp_s6;
f32 temp_s6_2;
f32 var_a2;
f32 var_fp;
f32 var_fs1;
f32 var_fs2;
f32 var_fs2_2;
f32 var_fs2_3;
f32 var_fs2_4;
f32 var_fs2_5;
f32 var_fs3;
f32 var_fs3_2;
f32 var_fs3_3;
f32 var_fs3_4;
f32 var_fs3_5;
f32 var_fs3_6;
f32 var_fs3_7;
f32 var_fs3_8;
f32 var_fv0;
f32 var_fv1;
f32 var_fv1_2;
f32 var_fv1_3;
f32 var_fv1_4;
f32 var_fv1_5;
f32 var_fv1_6;
f32 var_s5;
f32 var_s6;
s16 temp_v0;
s16 temp_v1;
s32 temp_v1_15;
s16 temp_v1_16;
s16 temp_v1_23;
s16 temp_v1_24;
s16 temp_v1_27;
s32 temp_a0;
s32 temp_a0_4;
s32 temp_v0_12;
s32 temp_v1_7;
s32 var_s0_3;
s32 var_s3;
s32 var_v0;
s32 var_v0_10;
s32 var_v0_11;
s32 var_v0_12;
s32 var_v0_13;
s32 var_v0_14;
s32 var_v0_15;
s32 var_v0_16;
s32 var_v0_17;
s32 var_v0_18;
s32 var_v0_19;
s32 var_v0_20;
s32 var_v0_21;
s32 var_v0_22;
s32 var_v0_23;
s32 var_v0_24;
s32 var_v0_2;
s32 var_v0_3;
s32 var_v0_4;
s32 var_v0_5;
s32 var_v0_6;
s32 var_v0_7;
s32 var_v0_8;
s32 var_v0_9;
s32 var_v1;
s32 var_v1_10;
s32 var_v1_11;
s32 var_v1_12;
s32 var_v1_13;
s32 var_v1_14;
s32 var_v1_15;
s32 var_v1_16;
s32 var_v1_17;
s32 var_v1_18;
s32 var_v1_19;
s32 var_v1_20;
s32 var_v1_21;
s32 var_v1_22;
s32 var_v1_23;
s32 var_v1_2;
s32 var_v1_3;
s32 var_v1_4;
s32 var_v1_5;
s32 var_v1_6;
s32 var_v1_7;
s32 var_v1_8;
s32 var_v1_9;
s32 temp_s4;
s32 temp_v0_3;
s8 temp_v0_6;
s8 temp_v0_7;
s8 temp_v1_21;
s8 temp_v1_22;
s8 temp_v1_25;
s8 temp_v1_26;
s8 temp_v1_31;
u16 temp_a0_7;
u16 temp_v0_11;
u16 temp_v1_17;
u16 temp_v1_28;
u16 temp_v1_2;
u16 temp_v1_30;
u16 temp_v1_3;
u8 temp_v0_2;
u8 temp_v0_5;
u8 temp_v1_20;
u8 temp_v1_35;
s32 var_s0;
void *temp_a0_10;
void *temp_a0_2;
void *temp_a0_3;
void *temp_a0_5;
void *temp_a0_6;
void *temp_a0_8;
void *temp_a0_9;
void *temp_a1;
void *temp_s1;
void *temp_v0_10;
void *temp_v0_4;
void *temp_v0_8;
void *temp_v0_9;
void *temp_v1_10;
void *temp_v1_11;
void *temp_v1_12;
void *temp_v1_13;
void *temp_v1_14;
void *temp_v1_18;
void *temp_v1_19;
void *temp_v1_29;
void *temp_v1_32;
void *temp_v1_33;
void *temp_v1_34;
void *temp_v1_36;
void *temp_v1_4;
void *temp_v1_5;
void *temp_v1_6;
void *temp_v1_8;
void *temp_v1_9;
void *var_s0_2;
void *var_v0_25;
temp_s1 = M2C_FIELD(arg0, void **, 0x6C);
sp64 = M2C_FIELD(arg0, void **, 0x20);
temp_s4 = M2C_FIELD(temp_s1, s8 *, 0x182);
if (D_80103EB0 == 0) {
temp_a0 = M2C_FIELD(temp_s1, s32 *, 8);
M2C_FIELD(temp_s1, s32 *, 0x1B0) = 0;
if (temp_a0 != -1) {
listUnlinkFree(temp_a0);
M2C_FIELD(temp_s1, s32 *, 8) = -1;
}
func_8006E648(M2C_FIELD(arg0, void **, 0x20), arg0, 0, &sp30, &sp34, &sp38, &sp3C, &sp40);
func_80002EF0(arg0);
func_80070F34(arg0);
temp_v1 = M2C_FIELD(arg0, s16 *, 0x7A);
if (temp_v1 < 4) {
if (temp_v1 < 2) {
M2C_FIELD(arg0, s32 *, 0x60) = 0;
return;
}
if (M2C_FIELD(temp_s1, u8 *, 0x5A8) != 3) {
M2C_FIELD(arg0, s32 *, 0x60) = 0;
return;
}
actorUpdateGatedState(arg0, 2);
goto block_11;
}
block_11:
M2C_FIELD(arg0, s32 *, 0x60) = 0;
return;
}
if (D_801002AE == 0) {
D_800E1A24 = 0x10;
D_800E1A28 = 0;
if (temp_s1 != NULL) {
if (M2C_FIELD(temp_s1, u8 *, 0x185) == 1) {
temp_v1_2 = M2C_FIELD(temp_s1, u16 *, 0x520);
if (temp_v1_2 < 2U) {
requestSound(0x58);
setTrackMarkerActive(0, temp_s1);
} else {
M2C_FIELD(temp_s1, u16 *, 0x520) = (u16) (temp_v1_2 - 1);
updateHudSprites(temp_s1);
}
} else {
temp_v1_3 = M2C_FIELD(temp_s1, u16 *, 0x520);
if (temp_v1_3 < 0x706U) {
M2C_FIELD(temp_s1, u16 *, 0x520) = (u16) (temp_v1_3 + 2);
}
}
if (D_800E1A14 != 0x546) {
temp_v1_4 = M2C_FIELD(temp_s1, void **, 0x404);
M2C_FIELD(temp_v1_4, s32 *, 0x28) = (s32) ((M2C_FIELD(temp_v1_4, s32 *, 0x28) & ~0xFC) | 0x10);
temp_v1_5 = M2C_FIELD(temp_s1, void **, 0x408);
M2C_FIELD(temp_v1_5, s32 *, 0x28) = (s32) ((M2C_FIELD(temp_v1_5, s32 *, 0x28) & ~0xFC) | 0x10);
temp_v1_6 = M2C_FIELD(temp_s1, void **, 0x40C);
M2C_FIELD(temp_v1_6, s32 *, 0x28) = (s32) ((M2C_FIELD(temp_v1_6, s32 *, 0x28) & ~0xFC) | 0x10);
temp_a0_2 = M2C_FIELD(temp_s1, void **, 0x404);
temp_v1_7 = M2C_FIELD(temp_a0_2, s32 *, 0x10);
if ((u32) (temp_v1_7 & 0xFF) < 0xF7U) {
M2C_FIELD(temp_a0_2, s32 *, 0x10) = (s32) (temp_v1_7 + 8);
temp_v1_8 = M2C_FIELD(temp_s1, void **, 0x408);
M2C_FIELD(temp_v1_8, s32 *, 0x10) = (s32) (M2C_FIELD(temp_v1_8, s32 *, 0x10) + 4);
temp_v1_9 = M2C_FIELD(temp_s1, void **, 0x40C);
M2C_FIELD(temp_v1_9, s32 *, 0x10) = (s32) (M2C_FIELD(temp_v1_9, s32 *, 0x10) + 8);
}
temp_fv1 = (f32) D_800E1A14 * 0.035555556f;
temp_a0_3 = M2C_FIELD(temp_s1, void **, 0x404);
if (temp_fv1 >= 2.1474836e9f) {
M2C_FIELD(temp_a0_3, s16 *, 0x26) = (s16) ((s32) (temp_fv1 - 2.1474836e9f) | 0x80000000);
} else {
M2C_FIELD(temp_a0_3, s16 *, 0x26) = (s16) (s32) temp_fv1;
}
} else {
temp_v1_10 = M2C_FIELD(temp_s1, void **, 0x404);
temp_a0_4 = M2C_FIELD(temp_v1_10, s32 *, 0x10);
if ((u32) (temp_a0_4 & 0xFF) < 8U) {
M2C_FIELD(temp_v1_10, s32 *, 0x28) = (s32) ((M2C_FIELD(temp_v1_10, s32 *, 0x28) & ~0xFC) | 0x1C);
temp_v1_11 = M2C_FIELD(temp_s1, void **, 0x408);
M2C_FIELD(temp_v1_11, s32 *, 0x28) = (s32) ((M2C_FIELD(temp_v1_11, s32 *, 0x28) & ~0xFC) | 0x1C);
temp_v1_12 = M2C_FIELD(temp_s1, void **, 0x40C);
M2C_FIELD(temp_v1_12, s32 *, 0x28) = (s32) ((M2C_FIELD(temp_v1_12, s32 *, 0x28) & ~0xFC) | 0x1C);
} else {
M2C_FIELD(temp_v1_10, s32 *, 0x10) = (s32) (temp_a0_4 - 8);
temp_v1_13 = M2C_FIELD(temp_s1, void **, 0x408);
M2C_FIELD(temp_v1_13, s32 *, 0x10) = (s32) (M2C_FIELD(temp_v1_13, s32 *, 0x10) - 4);
temp_v1_14 = M2C_FIELD(temp_s1, void **, 0x40C);
M2C_FIELD(temp_v1_14, s32 *, 0x10) = (s32) (M2C_FIELD(temp_v1_14, s32 *, 0x10) - 8);
}
}
}
temp_v1_15 = M2C_FIELD(arg0, s16 *, 0x7A);
D_800E1A18 = (s32) M2C_FIELD(M2C_FIELD(arg0, void **, 0x68), u16 *, 0xC);
if (temp_v1_15 != 1) {
if (temp_v1_15 >= 2) {
if (temp_v1_15 < 4) {
if (M2C_FIELD(temp_s1, u8 *, 0x5A8) == 3) {
actorUpdateGatedState(arg0, 2);
}
}
} else if (temp_v1_15 == 0) {
M2C_FIELD(temp_s1, f32 *, 0x20) = 0.0f;
temp_fs0 = M2C_FIELD(temp_s1, f32 *, 0x20);
M2C_FIELD(temp_s1, s32 *, 0x1C) = 0;
M2C_FIELD(temp_s1, s8 *, 0x19B) = 0;
M2C_FIELD(temp_s1, f32 *, 0x38) = temp_fs0;
M2C_FIELD(temp_s1, f32 *, 0x34) = temp_fs0;
M2C_FIELD(temp_s1, f32 *, 0x44) = 1.0f;
M2C_FIELD(temp_s1, f32 *, 0x40) = 1.0f;
M2C_FIELD(temp_s1, f32 *, 0x3C) = 1.0f;
func_80081CC0(temp_s4);
actorInitFromSpawn(arg0, arg0 + 0x24, arg0 + 0x3C);
M2C_FIELD(temp_s1, void **, 0xB8) = NULL;
if (gGameMode == 0x19) {
func_800635BC(arg0, 2);
func_80119DB4(arg0, temp_s1 + 0xB8);
D_800E1A20 = 0;
M2C_FIELD(M2C_FIELD(temp_s1, void **, 0xB8), f32 *, 0x4C) = temp_fs0;
func_80081D00(temp_s4);
}
switch (gGameMode) {
case 1:
case 16:
case 20:
case 25:
case 29:
case 33:
case 34:
case 40:
case 41:
func_8007092C(arg0, 0);
break;
}
if ((gBorderSkipFlag != 0) && (gSaveSlotCount < (M2C_FIELD(temp_s1, s8 *, 0x182) + 1))) {
M2C_FIELD(arg0, s16 *, 0x78) = 3;
M2C_FIELD(arg0, s16 *, 0x7A) = 0;
}
}
goto block_474;
}
sp5C = 0.0f;
D_800E1A1C = 0.0f;
var_s6 = 0.0f;
func_80065D90(arg0);
var_fp = 0.0f;
var_s5 = 0.0f;
if (D_800E1A16 != 0) {
temp_v0 = (u16) D_800E1A14 + 8;
D_800E1A14 = temp_v0;
if (temp_v0 >= 0x547) {
D_800E1A14 = 0x546;
}
}
temp_v0_2 = M2C_FIELD(temp_s1, u8 *, 0x186);
if (temp_v0_2 != 0) {
M2C_FIELD(temp_s1, u8 *, 0x186) = (u8) (temp_v0_2 - 1);
}
temp_v0_3 = M2C_FIELD(temp_s1, s8 *, 0x188);
if (temp_v0_3 != 0) {
M2C_FIELD(temp_s1, s8 *, 0x188) = (s8) (temp_v0_3 - 1);
}
temp_v1_16 = M2C_FIELD(arg0, s16 *, 0x7C);
switch (temp_v1_16) {
case 0:
if (func_80069A90(arg0) == 0) {
if (!((s32) M2C_FIELD(M2C_FIELD(arg0, void **, 0x68), u16 *, 0xC) & 0x410000)) {
var_fs3 = func_80081B44(temp_s4, 0, 1);
temp_fs5 = absFloat(var_fs3);
if (M2C_FIELD(M2C_FIELD(arg0, void **, 0x68), u16 *, 0xC) & 8) {
var_v1 = 1;
if (!(var_fs3 <= 0.0002f)) {
var_v1 = 0;
}
var_v0 = 1;
if (!(var_fs3 >= -0.0002f)) {
var_v0 = 0;
}
if (((var_v1 ^ 1) | (var_v0 ^ 1)) != 0) {
temp_fv0 = var_fs3 * var_fs3;
if (var_fs3 > 0.0f) {
var_fs3 = (temp_fv0 * 0.2f) + 0.01f;
} else {
var_fs3 = (temp_fv0 * -0.1f) - 0.01f;
}
}
var_fs2 = 0.2f;
} else {
var_v1_2 = 1;
if (!(var_fs3 <= 0.0002f)) {
var_v1_2 = 0;
}
var_v0_2 = 1;
if (!(var_fs3 >= -0.0002f)) {
var_v0_2 = 0;
}
if (((var_v1_2 ^ 1) | (var_v0_2 ^ 1)) != 0) {
temp_fv1_2 = var_fs3 * var_fs3;
if (var_fs3 > 0.0f) {
var_fs3 = temp_fv1_2 * 0.1f;
} else {
var_fs3 = temp_fv1_2 * -0.1f;
}
}
var_fs2 = 0.01f;
}
temp_v1_17 = M2C_FIELD(M2C_FIELD(arg0, void **, 0x68), u16 *, 0xC);
if (temp_v1_17 & 4) {
var_fs3 *= 0.5f;
}
if (temp_v1_17 & 0x200) {
var_fs3 *= M2C_FIELD(temp_s1, f32 *, 0x94);
}
temp_fv0_2 = M2C_FIELD(temp_s1, f32 *, 0x4C);
temp_fa0 = ((var_fs3 - temp_fv0_2) * var_fs2) + temp_fv0_2;
var_v0_3 = 1;
M2C_FIELD(temp_s1, f32 *, 0x4C) = temp_fa0;
if (!(var_fs3 <= 0.0002f)) {
var_v0_3 = 0;
}
var_v1_3 = 1;
if (!(var_fs3 >= -0.0002f)) {
var_v1_3 = 0;
}
if ((var_v0_3 & var_v1_3) && (absFloat(temp_fa0) < 0.01f)) {
M2C_FIELD(temp_s1, f32 *, 0x4C) = 0.0f;
}
temp_fv0_3 = M2C_FIELD(temp_s1, f32 *, 0x4C);
var_fv1 = -0.2f;
if ((temp_fv0_3 < -0.2f) || (var_fv1 = 0.2f, (temp_fv0_3 > 0.2f))) {
M2C_FIELD(temp_s1, f32 *, 0x4C) = var_fv1;
}
temp_fs3 = M2C_FIELD(temp_s1, f32 *, 0x4C);
var_v1_4 = 1;
if (!(temp_fs3 <= 0.0002f)) {
var_v1_4 = 0;
}
var_v0_4 = 1;
if (!(temp_fs3 >= -0.0002f)) {
var_v0_4 = 0;
}
if (((var_v1_4 ^ 1) | (var_v0_4 ^ 1)) == 0) {
D_800E1A28 |= 0x80000;
}
var_s5 = 0.0f + (temp_fs3 * sinAngle(M2C_FIELD(arg0, f32 *, 0x40)));
var_s6 = 0.0f + (temp_fs3 * cosAngle(M2C_FIELD(arg0, f32 *, 0x40)));
M2C_FIELD(M2C_FIELD(arg0, void **, 0x68), f32 *, 0x34) = temp_fs3;
temp_fs2 = absFloat(temp_fs3);
func_800452E0(temp_s1 + 0x128, arg0 + 0x24, &sp48);
(*(__repair_vec3 *) ((s8 *) (temp_s1) + 0x128)) = (*(__repair_vec3 *) ((s8 *) (arg0) + 0x24));
sp4C = 0.0f;
var_s0 = 1;
if (func_8004572C(&sp48) <= 0.001f) {
temp_fs0_2 = M2C_FIELD(temp_s1, f32 *, 0x58);
var_fs1 = 0.0f;
func_80065684(arg0);
M2C_FIELD(temp_s1, f32 *, 0x58) = temp_fs0_2;
} else {
var_fs1 = temp_fs2 * 5.0f;
var_v0_5 = 1;
if (!(var_fs1 <= 0.0002f)) {
var_v0_5 = 0;
}
var_v1_5 = 1;
if (!(var_fs1 >= -0.0002f)) {
var_v1_5 = 0;
}
var_s0 = 1;
if (!(var_v0_5 & var_v1_5)) {
var_v0_6 = 1;
if (!(temp_fs5 <= 0.0002f)) {
var_v0_6 = 0;
}
var_v1_6 = 1;
if (!(temp_fs5 >= -0.0002f)) {
var_v1_6 = 0;
}
var_s0 = 1;
if (!(var_v0_6 & var_v1_6)) {
var_s0 = 4;
var_v0_7 = 1;
if (!(temp_fs5 > 0.0f)) {
var_v0_7 = 0;
}
var_v1_7 = 1;
if (!(temp_fs5 < 1.0f)) {
var_v1_7 = 0;
}
if (var_v0_7 & var_v1_7) {
if (var_fs1 < 0.375f) {
var_s0 = 2;
} else if (var_fs1 < 0.75f) {
var_s0 = 3;
}
}
}
}
}
if (var_s0 != M2C_FIELD(temp_s1, u8 *, 0x195)) {
var_v0_8 = 1;
if (!(var_fs1 <= 0.0002f)) {
var_v0_8 = 0;
}
var_v1_8 = 1;
if (!(var_fs1 >= -0.0002f)) {
var_v1_8 = 0;
}
var_v0_9 = var_s0 * 2;
if ((var_v0_8 & var_v1_8) || (var_v0_9 = var_s0 * 2, (absFloat(var_fs1 - M2C_FIELD(temp_s1, f32 *, 0x8C)) > 0.03f))) {
M2C_FIELD(temp_s1, f32 *, 0x8C) = var_fs1;
M2C_FIELD(temp_s1, u8 *, 0x195) = var_s0;
func_80002D30(arg0, *(&D_800C7C8E + var_v0_9));
M2C_FIELD(M2C_FIELD(arg0, void **, 0x68), s32 *, 0x30) = 0;
}
}
func_800698D8(arg0, temp_fs5, probeTrackSteerAngle(sp64, arg0));
if (func_800818AC(temp_s4, 0xC) != 0) {
if ((M2C_FIELD(temp_s1, s8 *, 0x180) == 0) && !(M2C_FIELD(M2C_FIELD(arg0, void **, 0x68), u16 *, 0xC) & 0x20)) {
M2C_FIELD(temp_s1, u8 *, 0x187) = 0U;
M2C_FIELD(temp_s1, s8 *, 0x180) = 1;
M2C_FIELD(temp_s1, f32 *, 0xCC) = (f32) ((f64) M2C_FIELD(temp_s1, f32 *, 0xCC) + D_800D45E0);
temp_v1_18 = M2C_FIELD(arg0, void **, 0x68);
M2C_FIELD(temp_v1_18, u16 *, 0xC) = (u16) (M2C_FIELD(temp_v1_18, u16 *, 0xC) & 0xFFCB);
requestSound(0xFF, 4);
if (gBorderSkipFlag != 0) {
temp_fv0_4 = M2C_FIELD(temp_s1, f32 *, 0x4C);
if ((temp_fv0_4 <= 0.0002f) && (temp_fv0_4 >= -0.0002f)) {
temp_fv0_5 = M2C_FIELD(temp_s1, f32 *, 0x50);
if (temp_fv0_5 <= 0.0002f) {
if (temp_fv0_5 >= -0.0002f) {
func_80002D30(arg0, 0x1ADU);
}
}
}
}
}
}
temp_fv0_6 = func_80081B44(temp_s4, 4, 5);
var_fs3_2 = temp_fv0_6 * temp_fv0_6 * 82.8f;
if (temp_fv0_6 < 0.0f) {
var_fs3_2 = -var_fs3_2;
}
temp_fv0_7 = M2C_FIELD(temp_s1, f32 *, 0x48);
temp_fv1_3 = ((var_fs3_2 - temp_fv0_7) * 0.8f) + temp_fv0_7;
M2C_FIELD(temp_s1, f32 *, 0x48) = temp_fv1_3;
if (temp_fv1_3 < -82.8f) {
M2C_FIELD(temp_s1, f32 *, 0x48) = -82.8f;
} else if (temp_fv1_3 > 82.8f) {
M2C_FIELD(temp_s1, f32 *, 0x48) = 82.8f;
}
temp_v0_4 = M2C_FIELD(arg0, void **, 0x68);
D_800E1A1C -= M2C_FIELD(temp_s1, f32 *, 0x48);
if (M2C_FIELD(temp_v0_4, f32 *, 0x34) <= 0.0f) {
M2C_FIELD(M2C_FIELD(arg0, void **, 0x68), f32 *, 0x20) = absFloat(M2C_FIELD(temp_v0_4, f32 *, 0x20));
} else {
M2C_FIELD(M2C_FIELD(arg0, void **, 0x68), f32 *, 0x20) = (f32) -absFloat(M2C_FIELD(temp_v0_4, f32 *, 0x20));
}
if (M2C_FIELD(M2C_FIELD(arg0, void **, 0x68), u16 *, 0xC) & 8) {
if ((func_800819EC(temp_s4, 0xD) != 0) && (M2C_FIELD(temp_s1, s8 *, 0x180) == 0)) {
temp_v1_19 = M2C_FIELD(arg0, void **, 0x68);
M2C_FIELD(temp_v1_19, u16 *, 0xC) = (u16) (M2C_FIELD(temp_v1_19, u16 *, 0xC) | 0x40);
func_80002D30(arg0, 0x177U);
func_800635BC(arg0, 6);
}
}
}
var_fs2_2 = 0.01f;
temp_fs3_2 = func_80081B44(temp_s4, 2, 3) * 0.15f;
if (M2C_FIELD(M2C_FIELD(arg0, void **, 0x68), u16 *, 0xC) & 8) {
var_fs2_2 = 0.2f;
}
temp_fv0_8 = M2C_FIELD(temp_s1, f32 *, 0x50);
temp_fa0_2 = ((temp_fs3_2 - temp_fv0_8) * var_fs2_2) + temp_fv0_8;
var_v0_10 = 1;
M2C_FIELD(temp_s1, f32 *, 0x50) = temp_fa0_2;
if (!(temp_fs3_2 <= 0.0002f)) {
var_v0_10 = 0;
}
var_v1_9 = 1;
if (!(temp_fs3_2 >= -0.0002f)) {
var_v1_9 = 0;
}
if ((var_v0_10 & var_v1_9) && (absFloat(temp_fa0_2) < 0.01f)) {
M2C_FIELD(temp_s1, f32 *, 0x50) = 0.0f;
}
temp_fv0_9 = M2C_FIELD(temp_s1, f32 *, 0x50);
var_fv1_2 = -0.15f;
if ((temp_fv0_9 < -0.15f) || (var_fv1_2 = 0.15f, (temp_fv0_9 > 0.15f))) {
M2C_FIELD(temp_s1, f32 *, 0x50) = var_fv1_2;
}
temp_fs3_3 = M2C_FIELD(temp_s1, f32 *, 0x50);
var_s5 += temp_fs3_3 * sinAngle(M2C_FIELD(arg0, f32 *, 0x40) + 1024.0f);
temp_a0_5 = M2C_FIELD(arg0, void **, 0x68);
var_s6 += temp_fs3_3 * cosAngle(M2C_FIELD(arg0, f32 *, 0x40) + 1024.0f);
var_v0_11 = 1;
if (!(M2C_FIELD(temp_a0_5, u16 *, 0xC) & 0x40) && (M2C_FIELD(temp_s1, u8 *, 0x195) == 1)) {
if (!(temp_fs3_3 <= 0.0002f)) {
var_v0_11 = 0;
}
var_v1_10 = 1;
if (!(temp_fs3_3 >= -0.0002f)) {
var_v1_10 = 0;
}
if (var_v0_11 & var_v1_10) {
if ((M2C_FIELD(temp_a0_5, s16 *, 0xA2) != 0x1AD) || (M2C_FIELD(temp_a0_5, s32 *, 0x14) & 0x20)) {
func_80002BD0(arg0, 0x159);
}
} else if (temp_fs3_3 < 0.0f) {
func_80002BD0(arg0, 0x1A9);
M2C_FIELD(M2C_FIELD(arg0, void **, 0x68), f32 *, 0x34) = (f32) -temp_fs3_3;
} else if (temp_fs3_3 > 0.0f) {
func_80002BD0(arg0, 0x1A3);
M2C_FIELD(M2C_FIELD(arg0, void **, 0x68), f32 *, 0x34) = temp_fs3_3;
}
}
}
default:
block_430:
func_80069BC8(arg0);
if (!(M2C_FIELD(M2C_FIELD(arg0, void **, 0x68), u16 *, 0xC) & 8)) {
temp_v1_20 = M2C_FIELD(temp_s1, u8 *, 0x196);
if (temp_v1_20 < 8U) {
M2C_FIELD(temp_s1, u8 *, 0x196) = (u8) (temp_v1_20 + 1);
}
} else {
if ((u8) M2C_FIELD(temp_s1, u8 *, 0x196) >= 8U) {
D_800E1A28 |= 0x20000;
requestSound(0x100);
}
M2C_FIELD(temp_s1, u8 *, 0x196) = 0U;
}
temp_v1_21 = M2C_FIELD(temp_s1, s8 *, 0x180);
switch (temp_v1_21) {
case 1:
if (!(M2C_FIELD(M2C_FIELD(arg0, void **, 0x68), u16 *, 0xC) & 0x20) && (func_800818AC(temp_s4, 0xC) != 0)) {
temp_v0_5 = M2C_FIELD(temp_s1, u8 *, 0x187);
M2C_FIELD(temp_s1, u8 *, 0x187) = (u8) (temp_v0_5 + 1);
if ((s8) temp_v0_5 >= 5) {
goto block_444;
}
M2C_FIELD(temp_s1, f32 *, 0xCC) = (f32) ((f64) M2C_FIELD(temp_s1, f32 *, 0xCC) + D_800D45E8);
} else {
block_444:
M2C_FIELD(temp_s1, s8 *, 0x180) = 2;
}
break;
case 2:
if ((M2C_FIELD(M2C_FIELD(arg0, void **, 0x68), u16 *, 0xC) & 8) && (func_800818AC(temp_s4, 0xC) == 0) && !(M2C_FIELD(M2C_FIELD(arg0, void **, 0x68), u16 *, 0xC) & 1)) {
M2C_FIELD(temp_s1, s8 *, 0x180) = 0;
}
break;
}
if (*(&D_8011508B + (M2C_FIELD(temp_s1, s8 *, 0x182) * 0xA0)) == 0) {
temp_v1_22 = M2C_FIELD(temp_s1, s8 *, 0x17E);
if ((temp_v1_22 >= 0) && (temp_v1_22 >= 2) && (temp_v1_22 < 4)) {
temp_v0_6 = M2C_FIELD(temp_s1, s8 *, 0x19B);
if (temp_v0_6 != 0) {
M2C_FIELD(temp_s1, s8 *, 0x19B) = (s8) (temp_v0_6 - 1);
} else {
temp_ft1 = M2C_FIELD(temp_s1, f32 *, 0x34);
temp_ft0 = (M2C_FIELD(temp_s1, f32 *, 0x38) - temp_ft1) * 0.15f;
if ((M2C_FIELD(arg0, s16 *, 0x7C) != 0) || (M2C_FIELD(temp_s1, s8 *, 0x180) == 0)) {
temp_fv0_10 = temp_ft1 + temp_ft0;
var_fv1_3 = -1.0f;
M2C_FIELD(temp_s1, f32 *, 0x34) = temp_fv0_10;
if ((temp_fv0_10 < -1.0f) || (var_fv1_3 = 1.0f, (temp_fv0_10 > 1.0f))) {
M2C_FIELD(temp_s1, f32 *, 0x34) = var_fv1_3;
}
var_v0_12 = 1;
if (!(temp_ft0 <= 0.0002f)) {
var_v0_12 = 0;
}
var_v1_11 = 1;
if (!(temp_ft0 >= -0.0002f)) {
var_v1_11 = 0;
}
if ((var_v0_12 & var_v1_11) && (M2C_FIELD(temp_s1, s8 *, 0x17E) == 2)) {
M2C_FIELD(temp_s1, s8 *, 0x17E) = 3;
}
}
}
}
}
temp_v1_23 = M2C_FIELD(arg0, s16 *, 0x7C);
if ((temp_v1_23 == 0) || (temp_v1_23 == 6)) {
var_s5 -= M2C_FIELD(temp_s1, f32 *, 0x11C);
var_s6 -= M2C_FIELD(temp_s1, f32 *, 0x124);
}
temp_a0_6 = temp_s1 + 0x11C;
func_80047B14(temp_a0_6, 0x3F4CCCCD, temp_a0_6);
M2C_FIELD(arg0, f32 *, 0x24) = (f32) (M2C_FIELD(arg0, f32 *, 0x24) + var_s5);
M2C_FIELD(arg0, f32 *, 0x28) = (f32) (M2C_FIELD(arg0, f32 *, 0x28) + var_fp);
M2C_FIELD(arg0, f32 *, 0x40) = (f32) (M2C_FIELD(arg0, f32 *, 0x40) + D_800E1A1C);
M2C_FIELD(arg0, f32 *, 0x2C) = (f32) (M2C_FIELD(arg0, f32 *, 0x2C) + var_s6);
M2C_FIELD(arg0, f32 *, 0x3C) = (f32) (M2C_FIELD(arg0, f32 *, 0x3C) + sp5C);
M2C_FIELD(arg0, f32 *, 0x44) = (f32) (M2C_FIELD(arg0, f32 *, 0x44) + 0.0f);
block_474:
func_80002EF0(arg0);
func_8006D2E4(arg0);
temp_v1_24 = M2C_FIELD(arg0, s16 *, 0x7A);
if (temp_v1_24 < 4) {
if (temp_v1_24 < 2) {
if (temp_v1_24 != 1) {
} else {
goto block_479;
}
} else {
updateSwayMotion(arg0);
func_80070F34(arg0);
}
} else if (temp_v1_24 == 4) {
block_479:
temp_v1_25 = M2C_FIELD(temp_s1, s8 *, 0x307);
M2C_FIELD(temp_s1, u8 *, 0x197) = (u8) (M2C_FIELD(temp_s1, u8 *, 0x197) - 1);
if (temp_v1_25 < M2C_FIELD(temp_s1, s8 *, 0x317)) {
M2C_FIELD(temp_s1, s8 *, 0x317) = temp_v1_25;
}
temp_v0_7 = M2C_FIELD(temp_s1, s8 *, 0x317);
if (temp_v0_7 < M2C_FIELD(temp_s1, s8 *, 0x307)) {
M2C_FIELD(temp_s1, s8 *, 0x307) = temp_v0_7;
}
if ((s8) M2C_FIELD(temp_s1, u8 *, 0x197) < 0) {
temp_v1_26 = M2C_FIELD(temp_s1, s8 *, 0x307);
M2C_FIELD(temp_s1, u8 *, 0x197) = 0xFU;
if (temp_v1_26 < 0x64) {
M2C_FIELD(temp_s1, s8 *, 0x307) = (s8) (temp_v1_26 + 1);
}
M2C_FIELD(temp_s1, s8 *, 0x317) = (s8) (u8) M2C_FIELD(temp_s1, s8 *, 0x307);
}
func_80067E94(arg0);
updateSwayMotion(arg0);
func_80070F34(arg0);
temp_v1_27 = M2C_FIELD(arg0, s16 *, 0x7C);
switch (temp_v1_27) {
case 0:
case 1:
case 2:
case 3:
case 4:
case 6:
case 8:
case 9:
case 10:
func_8006899C(arg0, 0);
break;
}
func_800179E8(arg0 + 0x24, sp64, D_800E1A28, D_800E1A2C);
}
func_80047FB4(*(&gTrackMarkerTable + (temp_s4 * 4)), *(&D_800C4710 + ((s8) M2C_FIELD(M2C_FIELD(arg0, void **, 0x68), u8 *, 0xE) * 0xE8)));
func_80069250(arg0);
break;
case 6:
if (func_80069A90(arg0) == 0) {
if (!((s32) M2C_FIELD(M2C_FIELD(arg0, void **, 0x68), u16 *, 0xC) & 0x410000)) {
temp_fs3_4 = func_80081B44(temp_s4, 0, 1);
func_800698D8(arg0, temp_fs3_4, probeTrackSteerAngle(sp64, arg0));
temp_v1_28 = M2C_FIELD(M2C_FIELD(arg0, void **, 0x68), u16 *, 0xC);
if (!(temp_v1_28 & 1)) {
if ((temp_v1_28 & 8) && ((func_800819EC(temp_s4, 0xD) != 0) || (func_800819EC(temp_s4, 0xC) != 0))) {
if ((func_8004BCC0(sp64, arg0 + 0x24, &sp48, 0x40000000) << 0x18) == 0) {
sp48 = M2C_FIELD(arg0, f32 *, 0x24);
sp4C = M2C_FIELD(arg0, f32 *, 0x28);
sp50 = M2C_FIELD(arg0, f32 *, 0x2C);
sp4C += 2.0f;
}
if ((M2C_FIELD(arg0, f32 *, 0x28) + 1.46f) < sp4C) {
func_80002D50(arg0, 0x177);
func_800635BC(arg0, 0);
temp_v1_29 = M2C_FIELD(arg0, void **, 0x68);
M2C_FIELD(temp_v1_29, u16 *, 0xC) = (u16) (M2C_FIELD(temp_v1_29, u16 *, 0xC) | 0x40);
}
} else if (M2C_FIELD(arg0, s16 *, 0x7C) != 0) {
temp_fv0_11 = func_80081B44(temp_s4, 4, 5);
var_fs3_3 = temp_fv0_11 * temp_fv0_11;
if (temp_fv0_11 < 0.0f) {
var_fs3_3 = -var_fs3_3;
}
temp_fv0_12 = M2C_FIELD(temp_s1, f32 *, 0x48);
temp_fv1_4 = (((var_fs3_3 * 82.8f) - temp_fv0_12) * 0.8f) + temp_fv0_12;
M2C_FIELD(temp_s1, f32 *, 0x48) = temp_fv1_4;
if (temp_fv1_4 < -82.8f) {
M2C_FIELD(temp_s1, f32 *, 0x48) = -82.8f;
} else if (temp_fv1_4 > 82.8f) {
M2C_FIELD(temp_s1, f32 *, 0x48) = 82.8f;
}
D_800E1A1C -= M2C_FIELD(temp_s1, f32 *, 0x48);
var_fs3_4 = func_80081B44(temp_s4, 0, 1);
absFloat(var_fs3_4);
if (M2C_FIELD(M2C_FIELD(arg0, void **, 0x68), u16 *, 0xC) & 8) {
var_v1_12 = 1;
if (!(var_fs3_4 <= 0.0002f)) {
var_v1_12 = 0;
}
var_v0_13 = 1;
if (!(var_fs3_4 >= -0.0002f)) {
var_v0_13 = 0;
}
if (((var_v1_12 ^ 1) | (var_v0_13 ^ 1)) != 0) {
temp_fv0_13 = var_fs3_4 * var_fs3_4;
if (var_fs3_4 > 0.0f) {
var_fs3_4 = (temp_fv0_13 * 0.09f) + 0.01f;
} else {
var_fs3_4 = (temp_fv0_13 * -0.045f) - 0.01f;
}
}
var_fs2_3 = 0.2f;
} else {
var_fs2_3 = 0.01f;
}
temp_v1_30 = M2C_FIELD(M2C_FIELD(arg0, void **, 0x68), u16 *, 0xC);
if (temp_v1_30 & 4) {
var_fs3_4 *= 0.5f;
}
if (temp_v1_30 & 0x200) {
var_fs3_4 *= M2C_FIELD(temp_s1, f32 *, 0x94);
}
temp_fv0_14 = M2C_FIELD(temp_s1, f32 *, 0x4C);
temp_fa0_3 = ((var_fs3_4 - temp_fv0_14) * var_fs2_3) + temp_fv0_14;
var_v0_14 = 1;
M2C_FIELD(temp_s1, f32 *, 0x4C) = temp_fa0_3;
if (!(var_fs3_4 <= 0.0002f)) {
var_v0_14 = 0;
}
var_v1_13 = 1;
if (!(var_fs3_4 >= -0.0002f)) {
var_v1_13 = 0;
}
if ((var_v0_14 & var_v1_13) && (absFloat(temp_fa0_3) < 0.01f)) {
M2C_FIELD(temp_s1, f32 *, 0x4C) = 0.0f;
}
temp_fv0_15 = M2C_FIELD(temp_s1, f32 *, 0x4C);
var_fv1_4 = -0.09f;
if ((temp_fv0_15 < -0.09f) || (var_fv1_4 = 0.09f, (temp_fv0_15 > 0.09f))) {
M2C_FIELD(temp_s1, f32 *, 0x4C) = var_fv1_4;
}
temp_fs3_5 = M2C_FIELD(temp_s1, f32 *, 0x4C);
var_v0_15 = 1;
if (!(temp_fs3_5 <= 0.0002f)) {
var_v0_15 = 0;
}
var_v1_14 = 1;
if (!(temp_fs3_5 >= -0.0002f)) {
var_v1_14 = 0;
}
if (var_v0_15 & var_v1_14) {
temp_fs1 = M2C_FIELD(temp_s1, f32 *, 0x50);
var_v0_16 = 1;
if (!(temp_fs1 <= 0.0002f)) {
var_v0_16 = 0;
}
var_v1_15 = 1;
if (!(temp_fs1 >= -0.0002f)) {
var_v1_15 = 0;
}
if (var_v0_16 & var_v1_15) {
M2C_FIELD(M2C_FIELD(arg0, void **, 0x68), s32 *, 0x30) = 0;
func_80002BD0(arg0, 0x17D);
} else {
M2C_FIELD(M2C_FIELD(arg0, void **, 0x68), f32 *, 0x34) = temp_fs1;
if (temp_fs1 > 0.0f) {
func_80002BD0(arg0, 0x189);
} else {
func_80002BD0(arg0, 0x18F);
}
}
} else {
func_80002BD0(arg0, 0x183);
M2C_FIELD(M2C_FIELD(arg0, void **, 0x68), f32 *, 0x34) = temp_fs3_5;
var_s5 = 0.0f + (temp_fs3_5 * sinAngle(M2C_FIELD(arg0, f32 *, 0x40)));
var_s6 = 0.0f + (temp_fs3_5 * cosAngle(M2C_FIELD(arg0, f32 *, 0x40)));
}
}
}
}
var_fs2_4 = 0.01f;
temp_fs3_6 = func_80081B44(temp_s4, 2, 3) * 0.075f;
if (M2C_FIELD(M2C_FIELD(arg0, void **, 0x68), u16 *, 0xC) & 8) {
var_fs2_4 = 0.2f;
}
temp_fv0_16 = M2C_FIELD(temp_s1, f32 *, 0x50);
temp_fa0_4 = ((temp_fs3_6 - temp_fv0_16) * var_fs2_4) + temp_fv0_16;
var_v0_17 = 1;
M2C_FIELD(temp_s1, f32 *, 0x50) = temp_fa0_4;
if (!(temp_fs3_6 <= 0.0002f)) {
var_v0_17 = 0;
}
var_v1_16 = 1;
if (!(temp_fs3_6 >= -0.0002f)) {
var_v1_16 = 0;
}
if ((var_v0_17 & var_v1_16) && (absFloat(temp_fa0_4) < 0.01f)) {
M2C_FIELD(temp_s1, f32 *, 0x50) = 0.0f;
}
temp_fv0_17 = M2C_FIELD(temp_s1, f32 *, 0x50);
var_fv1_5 = -0.075f;
if ((temp_fv0_17 < -0.075f) || (var_fv1_5 = 0.075f, (temp_fv0_17 > 0.075f))) {
M2C_FIELD(temp_s1, f32 *, 0x50) = var_fv1_5;
}
temp_fs1_2 = M2C_FIELD(temp_s1, f32 *, 0x50);
var_s5 += temp_fs1_2 * sinAngle(M2C_FIELD(arg0, f32 *, 0x40) + 1024.0f);
var_s6 += temp_fs1_2 * cosAngle(M2C_FIELD(arg0, f32 *, 0x40) + 1024.0f);
}
goto block_430;
case 1:
M2C_FIELD(temp_s1, f32 *, 0xCC) = 0.0f;
temp_a0_7 = M2C_FIELD(M2C_FIELD(arg0, void **, 0x68), u16 *, 0xC);
if (!(temp_a0_7 & 1)) {
temp_v1_31 = M2C_FIELD(temp_s1, s8 *, 0x181);
switch (temp_v1_31) {
case 1:
if (!(temp_a0_7 & 0x40)) {
temp_fv0_18 = func_80081B44(temp_s4, 0, 1);
var_fs3_5 = temp_fv0_18 * 0.04f;
if (M2C_FIELD(M2C_FIELD(arg0, void **, 0x68), u16 *, 0xC) & 0x200) {
var_fs3_5 *= M2C_FIELD(temp_s1, f32 *, 0x94);
}
if (var_fs3_5 < -0.04f) {
var_fs3_5 = -0.04f;
} else if (var_fs3_5 > 0.04f) {
var_fs3_5 = 0.04f;
}
temp_fs0_3 = var_fs3_5 + M2C_FIELD(arg0, f32 *, 0x28);
if (func_800818AC(temp_s4, 0xC) != 0) {
M2C_FIELD(temp_s1, s8 *, 0x181) = 4;
requestSound(0xFF);
} else if (M2C_FIELD(temp_s1, f32 *, 0x14) < temp_fs0_3) {
if ((func_8004BCC0(sp64, arg0 + 0x24, &sp48, 0x40000000) << 0x18) == 0) {
sp48 = M2C_FIELD(arg0, f32 *, 0x24);
sp4C = M2C_FIELD(arg0, f32 *, 0x28);
sp50 = M2C_FIELD(arg0, f32 *, 0x2C);
sp4C += 2.0f;
}
if ((M2C_FIELD(arg0, f32 *, 0x28) + 1.46f) < sp4C) {
temp_fv0_19 = func_80063758(M2C_FIELD(arg0, f32 *, 0x40), M2C_FIELD(temp_s1, f32 *, 0x90), 0x43000000);
var_fs3_5 = temp_fv0_19;
if (temp_fv0_19 == 0.0f) {
M2C_FIELD(arg0, f32 *, 0x28) = (f32) M2C_FIELD(temp_s1, f32 *, 0x14);
func_80002BD0(arg0, 0x298);
temp_v1_32 = M2C_FIELD(arg0, void **, 0x68);
M2C_FIELD(temp_v1_32, u16 *, 0xC) = (u16) (M2C_FIELD(temp_v1_32, u16 *, 0xC) | 0x40);
M2C_FIELD(temp_s1, s8 *, 0x181) = 2;
M2C_FIELD(temp_s1, s8 *, 0x17E) = 2;
func_800698D8(arg0, temp_fv0_18, 0.0f);
M2C_FIELD(temp_s1, s8 *, 0x19B) = 8;
} else {
temp_fv0_20 = M2C_FIELD(arg0, f32 *, 0x40) + var_fs3_5;
var_fs3_5 = 0.0f;
M2C_FIELD(arg0, f32 *, 0x40) = temp_fv0_20;
}
} else {
var_fs3_5 = 0.0f;
}
} else {
temp_fv0_21 = M2C_FIELD(temp_s1, f32 *, 0x18);
if (temp_fs0_3 < temp_fv0_21) {
var_a2 = 0.0f;
M2C_FIELD(arg0, f32 *, 0x28) = temp_fv0_21;
M2C_FIELD(temp_s1, s8 *, 0x181) = 3;
M2C_FIELD(temp_s1, s8 *, 0x17E) = 2;
} else {
M2C_FIELD(arg0, f32 *, 0x28) = temp_fs0_3;
func_80002BD0(arg0, 0x295);
var_a2 = func_80069998(temp_fv0_18);
}
func_800698D8(arg0, temp_fv0_18, var_a2);
}
M2C_FIELD(M2C_FIELD(arg0, void **, 0x68), f32 *, 0x34) = var_fs3_5;
M2C_FIELD(temp_s1, f32 *, 0x4C) = (f32) (var_fs3_5 * 5.0f);
}
break;
case 2:
if (!(temp_a0_7 & 0x40)) {
M2C_FIELD(temp_s1, s8 *, 0x181) = 3;
}
break;
case 4:
M2C_FIELD(temp_s1, f32 *, 0x4C) = 0.2f;
var_s5 = sinAngle(M2C_FIELD(arg0, f32 *, 0x40)) * 0.2f;
var_s6 = cosAngle(M2C_FIELD(arg0, f32 *, 0x40)) * 0.2f;
block_286:
M2C_FIELD(temp_s1, f32 *, 0xCC) = 0.0f;
M2C_FIELD(temp_s1, u8 *, 0x186) = 0xAU;
if (func_80069A90(arg0) == 0) {
M2C_FIELD(M2C_FIELD(arg0, void **, 0x68), s32 *, 0x30) = 0;
func_80002BD0(arg0, 0x159);
func_800635BC(arg0, 0);
}
break;
case 3:
func_80065684(arg0);
goto block_286;
}
}
goto block_430;
case 2:
if (D_800E1A20 <= 0) {
D_800E19F0 = 0.495f;
if (M2C_FIELD(M2C_FIELD(temp_s1, void **, 0xB8), s16 *, 0x94) < 0xF) {
if (func_800819EC(temp_s4, 0x1B) != 0) {
var_fv0 = 0.88000005f;
goto block_294;
}
if (func_800819EC(temp_s4, 0x1C) != 0) {
var_fv0 = 0.275f;
block_294:
D_800E1A20 = 0x3C;
D_800E19F0 = var_fv0;
}
}
} else {
D_800E1A20 -= 1;
}
temp_v0_8 = M2C_FIELD(temp_s1, void **, 0xB8);
temp_ft0_2 = M2C_FIELD(temp_v0_8, f32 *, 0x4C);
M2C_FIELD(temp_v0_8, f32 *, 0x4C) = (f32) (((D_800E19F0 - temp_ft0_2) * 0.02f) + temp_ft0_2);
temp_v0_9 = M2C_FIELD(temp_s1, void **, 0xB8);
var_fv1_6 = 0.275f;
temp_fv0_22 = M2C_FIELD(temp_v0_9, f32 *, 0x4C);
if ((temp_fv0_22 < 0.275f) || (var_fv1_6 = 0.88000005f, (temp_fv0_22 > 0.88000005f))) {
M2C_FIELD(temp_v0_9, f32 *, 0x4C) = var_fv1_6;
}
temp_fv0_23 = M2C_FIELD(temp_s1, f32 *, 0x50);
temp_fv1_5 = (((func_80081B44(temp_s4, 2, 3) * 0.2f) - temp_fv0_23) * 0.3f) + temp_fv0_23;
M2C_FIELD(temp_s1, f32 *, 0x50) = temp_fv1_5;
if (temp_fv1_5 < -0.2f) {
M2C_FIELD(temp_s1, f32 *, 0x50) = -0.2f;
} else if (temp_fv1_5 > 0.2f) {
M2C_FIELD(temp_s1, f32 *, 0x50) = 0.2f;
}
func_8011A234(arg0, M2C_FIELD(temp_s1, void **, 0xB8), M2C_FIELD(M2C_FIELD(temp_s1, void **, 0xB8), f32 *, 0x4C), M2C_FIELD(temp_s1, f32 *, 0x50), 0, 1);
goto block_430;
case 3:
if (!(M2C_FIELD(M2C_FIELD(arg0, void **, 0x68), u16 *, 0xC) & 1)) {
if (func_80081AA4(temp_s4, 0xC) != 0) {
var_fs3_6 = 0.2f;
goto block_307;
}
if (D_800E1A0C != 0) {
if (D_800E1A0C != 1) {
M2C_FIELD(temp_s1, f32 *, 0xCC) = 0.0f;
} else {
temp_fv0_24 = func_80063758(M2C_FIELD(arg0, f32 *, 0x40), D_800E19F8 + 2048.0f, 0x42800000);
M2C_FIELD(arg0, f32 *, 0x40) = (f32) (M2C_FIELD(arg0, f32 *, 0x40) + temp_fv0_24);
if (temp_fv0_24 == 0.0f) {
goto block_362;
}
goto block_363;
}
} else {
var_fs3_7 = -func_80081B44(temp_s4, 4, 5);
var_v0_18 = 1;
if (!(var_fs3_7 <= 0.0002f)) {
var_v0_18 = 0;
}
var_v1_17 = 1;
if (!(var_fs3_7 >= -0.0002f)) {
var_v1_17 = 0;
}
if (var_v0_18 & var_v1_17) {
var_fs3_7 = func_80081B44(temp_s4, 2, 3);
}
temp_fs2_2 = func_80081B44(temp_s4, 0, 1);
var_v1_18 = 1;
if (!(var_fs3_7 <= 0.0002f)) {
var_v1_18 = 0;
}
var_v0_19 = 1;
if (!(var_fs3_7 >= -0.0002f)) {
var_v0_19 = 0;
}
if (((var_v1_18 ^ 1) | (var_v0_19 ^ 1)) == 0) {
var_v1_19 = 1;
if (!(temp_fs2_2 <= 0.0002f)) {
var_v1_19 = 0;
}
var_v0_20 = 1;
if (!(temp_fs2_2 >= -0.0002f)) {
var_v0_20 = 0;
}
if (((var_v1_19 ^ 1) | (var_v0_20 ^ 1)) != 0) {
goto block_327;
}
goto block_333;
}
block_327:
temp_fv0_25 = func_80063758(M2C_FIELD(arg0, f32 *, 0x40), D_800E19F8 + 2048.0f, 0x42800000);
var_v1_20 = 1;
if (!(temp_fv0_25 <= 0.0002f)) {
var_v1_20 = 0;
}
var_v0_21 = 1;
if (!(temp_fv0_25 >= -0.0002f)) {
var_v0_21 = 0;
}
if (((var_v1_20 ^ 1) | (var_v0_21 ^ 1)) != 0) {
D_800E1A0C = 1;
M2C_FIELD(temp_s1, f32 *, 0xCC) = 0.0f;
} else {
block_333:
temp_fv0_26 = M2C_FIELD(temp_s1, f32 *, 0x48);
temp_fv1_6 = (((var_fs3_7 * 32.0f) - temp_fv0_26) * 0.1f) + temp_fv0_26;
M2C_FIELD(temp_s1, f32 *, 0x48) = temp_fv1_6;
if (temp_fv1_6 < -32.0f) {
M2C_FIELD(temp_s1, f32 *, 0x48) = -32.0f;
} else if (temp_fv1_6 > 32.0f) {
M2C_FIELD(temp_s1, f32 *, 0x48) = 32.0f;
}
temp_fs3_7 = M2C_FIELD(temp_s1, f32 *, 0x48);
temp_fv1_7 = D_800E19F8 + temp_fs3_7;
D_800E19F8 = temp_fv1_7;
var_v1_21 = 1;
if (!(temp_fs3_7 <= 0.0002f)) {
var_v1_21 = 0;
}
var_v0_22 = 1;
if (!(temp_fs3_7 >= -0.0002f)) {
var_v0_22 = 0;
}
if (((var_v1_21 ^ 1) | (var_v0_22 ^ 1)) != 0) {
M2C_FIELD(arg0, f32 *, 0x40) = (f32) (temp_fv1_7 + 2048.0f);
}
M2C_FIELD(arg0, f32 *, 0x24) = (f32) (D_800E1A04 + M2C_FIELD(temp_s1, f32 *, 0xEC) + (sinAngle(D_800E19F8) * 0.22500001f));
M2C_FIELD(arg0, f32 *, 0x2C) = (f32) (D_800E1A08 + M2C_FIELD(temp_s1, f32 *, 0xF4) + (cosAngle(D_800E19F8) * 0.22500001f));
func_800698D8(arg0, temp_fs2_2, func_80069A14(temp_fs2_2));
temp_ft0_3 = M2C_FIELD(temp_s1, f32 *, 0x4C);
temp_fv0_27 = (((temp_fs2_2 * 0.12f) - temp_ft0_3) * 0.2f) + temp_ft0_3;
M2C_FIELD(temp_s1, f32 *, 0x4C) = temp_fv0_27;
if (temp_fv0_27 < -0.12f) {
M2C_FIELD(temp_s1, f32 *, 0x4C) = -0.12f;
} else if (temp_fv0_27 > 0.12f) {
M2C_FIELD(temp_s1, f32 *, 0x4C) = 0.12f;
}
var_fs2_5 = M2C_FIELD(temp_s1, f32 *, 0x4C);
if (var_fs2_5 < 0.0f) {
var_fs2_5 *= 1.5f;
}
temp_fv0_28 = M2C_FIELD(arg0, f32 *, 0x28);
var_v0_23 = 1;
if (!(var_fs2_5 > 0.0f)) {
var_v0_23 = 0;
}
var_v1_22 = 1;
if (!((M2C_FIELD(temp_s1, f32 *, 0xF0) - temp_fv0_28) <= 1.5f)) {
var_v1_22 = 0;
}
if (var_v0_23 & var_v1_22) {
var_fs2_5 = 0.0f;
goto block_360;
}
var_v0_24 = 1;
if (!(var_fs2_5 < 0.0f)) {
var_v0_24 = 0;
}
var_v1_23 = 1;
if (!((temp_fv0_28 - M2C_FIELD(temp_s1, f32 *, 0xFC)) <= 1.5f)) {
var_v1_23 = 0;
}
var_fs3_6 = 0.0f;
if (!(var_v0_24 & var_v1_23)) {
block_360:
M2C_FIELD(arg0, f32 *, 0x28) = (f32) (M2C_FIELD(arg0, f32 *, 0x28) + var_fs2_5);
goto block_363;
}
block_307:
M2C_FIELD(temp_s1, f32 *, 0x4C) = var_fs3_6;
var_s5 = var_fs3_6 * sinAngle(M2C_FIELD(arg0, f32 *, 0x40));
temp_fs3_8 = var_fs3_6 * cosAngle(M2C_FIELD(arg0, f32 *, 0x40));
M2C_FIELD(temp_s1, f32 *, 0xCC) = 0.0f;
M2C_FIELD(temp_s1, s8 *, 0x188) = 0x14;
func_800635BC(arg0, 0);
M2C_FIELD(temp_s1, f32 *, 0x38) = 0.0f;
var_s6 = temp_fs3_8;
M2C_FIELD(temp_s1, s8 *, 0x17E) = 2;
requestSound(0xFF);
M2C_FIELD(temp_s1, f32 *, 0xCC) = 0.0f;
}
}
} else {
block_362:
D_800E1A0C = 0;
block_363:
M2C_FIELD(temp_s1, f32 *, 0xCC) = 0.0f;
}
goto block_430;
case 7:
var_v0_25 = M2C_FIELD(temp_s1, void **, 0xBC);
var_s3 = 0;
loop_365:
if (var_v0_25 == NULL) {
var_s3 = 1;
var_s0_2 = func_80015DAC(temp_s4);
goto block_371;
}
var_s0_2 = M2C_FIELD(var_v0_25, void **, 0x10);
if (func_80081AA4(temp_s4, 0x12) != 0) {
M2C_FIELD(temp_s1, void **, 0xBC) = NULL;
M2C_FIELD(temp_s1, s8 *, 0x184) = 0;
func_800635BC(arg0, 0);
temp_v1_33 = M2C_FIELD(arg0, void **, 0x68);
M2C_FIELD(temp_v1_33, u8 *, 0x10) = (u8) M2C_FIELD(temp_v1_33, u8 *, 0xE);
M2C_FIELD(M2C_FIELD(arg0, void **, 0x68), s8 *, 0xF) = (s8) M2C_FIELD(temp_s1, u16 *, 0x134);
gSceneFlagsB |= 0x21;
func_80064318(M2C_FIELD(temp_s1, s32 *, 0xA8), M2C_FIELD(temp_s1, s8 *, 0x182));
temp_v0_10 = *(&gTrackMarkerTable + (M2C_FIELD(temp_s1, s8 *, 0x182) * 4));
(*(__repair_vec3 *) ((s8 *) (arg0) + 0x30)) = (*(__repair_vec3 *) ((s8 *) (arg0) + 0x24));
(*(__repair_vec3 *) ((s8 *) (temp_v0_10) + 0x10)) = (*(__repair_vec3 *) ((s8 *) (arg0) + 0x30));
(*(__repair_vec3 *) ((s8 *) (temp_v0_10) + 0x28)) = (*(__repair_vec3 *) ((s8 *) (temp_v0_10) + 0x10));
M2C_FIELD(*(&gTrackMarkerTable + (M2C_FIELD(temp_s1, s8 *, 0x182) * 4)), void **, 0xF4) = (void *) M2C_FIELD(arg0, void **, 0x20);
func_80081D20(temp_s4, 0x12);
return;
}
if (func_80081AA4(temp_s4, 0xE) != 0) {
var_s3 = 1;
}
block_371:
if (var_s3 != 0) {
var_v0_25 = NULL;
if (var_s0_2 != NULL) {
loop_373:
temp_v0_11 = M2C_FIELD(var_s0_2, u16 *, 0x78);
if (((temp_v0_11 == 0x1B) | (temp_v0_11 == 0x5D)) != 0) {
M2C_FIELD(temp_s1, void **, 0xBC) = var_s0_2;
} else {
var_s0_2 = M2C_FIELD(var_s0_2, void **, 0x10);
if (var_s0_2 != NULL) {
goto loop_373;
}
}
goto block_377;
}
goto block_379;
}
block_377:
if (var_s0_2 == NULL) {
var_v0_25 = NULL;
block_379:
M2C_FIELD(temp_s1, void **, 0xBC) = NULL;
goto loop_365;
}
M2C_FIELD(temp_s1, s8 *, 0x184) = 3;
goto block_430;
case 4:
temp_fs4 = M2C_FIELD(arg0, f32 *, 0x3C) - (M2C_FIELD(temp_s1, f32 *, 0x34) * 1024.0f);
temp_fs5_2 = func_80081B44(temp_s4, 0, 1);
if ((M2C_FIELD(M2C_FIELD(sp64, void **, 0x20), f32 *, 0x5C) + 0.3f) <= M2C_FIELD(arg0, f32 *, 0x28)) {
sp5C = 0.0f;
func_800635BC(arg0, 0);
M2C_FIELD(arg0, f32 *, 0x3C) = sp5C;
M2C_FIELD(temp_s1, s8 *, 0x17E) = 2;
} else if (!(M2C_FIELD(M2C_FIELD(arg0, void **, 0x68), u16 *, 0xC) & 1)) {
temp_s5 = 0.0f - D_800C7DBC;
temp_s6 = 0.0f - D_800C7DC4;
temp_fs0_4 = func_8008292C(D_800E1A10 * 3.0f);
temp_fs3_9 = temp_fs0_4 * (func_80082968(D_800E1A10) * 0.1f);
temp_fs0_5 = func_8008292C(D_800E1A10);
temp_fs2_3 = temp_fs0_5 * (func_80082968(D_800E1A10 * 3.0f) * 0.1f);
D_800C7DBC = temp_fs3_9;
D_800E1A10 += 0.01f;
D_800C7DC4 = temp_fs2_3;
temp_fv1_8 = M2C_FIELD(temp_s1, f32 *, 0x48);
temp_fv0_29 = (((func_80081B44(temp_s4, 4, 5) * 32.0f) - temp_fv1_8) * 0.1f) + temp_fv1_8;
M2C_FIELD(temp_s1, f32 *, 0x48) = temp_fv0_29;
if (temp_fv0_29 < -32.0f) {
M2C_FIELD(temp_s1, f32 *, 0x48) = -32.0f;
} else if (temp_fv0_29 > 32.0f) {
M2C_FIELD(temp_s1, f32 *, 0x48) = 32.0f;
}
var_fs3_8 = M2C_FIELD(temp_s1, f32 *, 0x48);
if (D_800E1A16 != 0) {
var_fs3_8 *= 2.0f;
}
var_s0_3 = 0;
D_800E1A1C -= var_fs3_8;
if ((func_800818AC(temp_s4, 0x16) != 0) || (func_800818AC(temp_s4, 0xC) != 0)) {
var_s0_3 = 1;
}
if ((func_800818AC(temp_s4, 0x17) != 0) || (func_800818AC(temp_s4, 0xD) != 0)) {
var_s0_3 = -1;
}
temp_fv1_9 = M2C_FIELD(temp_s1, f32 *, 0x5C);
temp_fv0_30 = ((((f32) var_s0_3 * 0.05f) - temp_fv1_9) * 0.05f) + temp_fv1_9;
M2C_FIELD(temp_s1, f32 *, 0x5C) = temp_fv0_30;
if (temp_fv0_30 < -0.05f) {
M2C_FIELD(temp_s1, f32 *, 0x5C) = -0.05f;
} else if (temp_fv0_30 > 0.05f) {
M2C_FIELD(temp_s1, f32 *, 0x5C) = 0.05f;
}
spherical_to_cartesian(&sp20, M2C_FIELD(temp_s1, f32 *, 0x5C), M2C_FIELD(arg0, f32 *, 0x40) * 0.0015339808f, (temp_fs4 * 0.0015339808f) - 1.5707964f);
temp_fv1_10 = M2C_FIELD(temp_s1, f32 *, 0x50);
temp_fv0_31 = (((func_80081B44(temp_s4, 2, 3) * 0.05f) - temp_fv1_10) * 0.05f) + temp_fv1_10;
M2C_FIELD(temp_s1, f32 *, 0x50) = temp_fv0_31;
if (temp_fv0_31 < -0.05f) {
M2C_FIELD(temp_s1, f32 *, 0x50) = -0.05f;
} else if (temp_fv0_31 > 0.05f) {
M2C_FIELD(temp_s1, f32 *, 0x50) = 0.05f;
}
temp_fs3_10 = M2C_FIELD(temp_s1, f32 *, 0x50);
temp_s5_2 = temp_s5 + temp_fs3_9 + sp20 + (temp_fs3_10 * sinAngle(M2C_FIELD(arg0, f32 *, 0x40) + 1024.0f));
temp_ft1_2 = M2C_FIELD(temp_s1, f32 *, 0x4C);
temp_fv1_11 = (((temp_fs5_2 * 0.15f) - temp_ft1_2) * 0.05f) + temp_ft1_2;
temp_s6_2 = temp_s6 + temp_fs2_3 + sp28 + (temp_fs3_10 * cosAngle(M2C_FIELD(arg0, f32 *, 0x40) + 1024.0f));
M2C_FIELD(temp_s1, f32 *, 0x4C) = temp_fv1_11;
if (temp_fv1_11 < -0.15f) {
M2C_FIELD(temp_s1, f32 *, 0x4C) = -0.15f;
} else if (temp_fv1_11 > 0.15f) {
M2C_FIELD(temp_s1, f32 *, 0x4C) = 0.15f;
}
spherical_to_cartesian(&sp20, M2C_FIELD(temp_s1, f32 *, 0x4C), M2C_FIELD(arg0, f32 *, 0x40) * 0.0015339808f, temp_fs4 * 0.0015339808f);
temp_v1_34 = M2C_FIELD(arg0, void **, 0x68);
M2C_FIELD(temp_v1_34, f32 *, 0x34) = 0.0f;
var_s5 = temp_s5_2 + sp20;
temp_fs3_11 = M2C_FIELD(M2C_FIELD(sp64, void **, 0x20), f32 *, 0x5C) - 0.3f;
var_fp = (0.0f - sp24) - sp24;
temp_fv1_12 = M2C_FIELD(arg0, f32 *, 0x28);
var_s6 = temp_s6_2 + sp28;
if (temp_fv1_12 < temp_fs3_11) {
if (temp_fs3_11 < (temp_fv1_12 + var_fp)) {
var_fp = temp_fs3_11 - temp_fv1_12;
}
} else {
temp_fv0_32 = M2C_FIELD(temp_v1_34, f32 *, 0x34);
if (temp_fv0_32 < var_fp) {
var_fp = temp_fv0_32;
}
}
}
goto block_430;
case 5:
temp_a0_8 = M2C_FIELD(temp_s1, void **, 0xBC);
temp_v1_35 = M2C_FIELD(temp_s1, u8 *, 0x18A);
temp_a1 = M2C_FIELD(temp_a0_8, void **, 0x6C);
switch (temp_v1_35) {
case 0:
temp_v0_12 = temp_s4 * 0xA0;
M2C_FIELD(temp_s1, u8 *, 0x18B) = (u8) *(&D_8011508B + temp_v0_12);
*(&D_8011508B + temp_v0_12) = 1;
M2C_FIELD(temp_s1, u8 *, 0x18A) = 1U;
M2C_FIELD(arg0, f32 *, 0x3C) = 0.0f;
M2C_FIELD(arg0, f32 *, 0x44) = 0.0f;
M2C_FIELD(arg0, f32 *, 0x40) = (f32) M2C_FIELD(temp_a1, f32 *, 0x10);
func_80002BD0(arg0, 0x20D);
M2C_FIELD(arg0, f32 *, 0x24) = (f32) (M2C_FIELD(M2C_FIELD(temp_s1, void **, 0xBC), f32 *, 0x24) - (sinAngle(M2C_FIELD(arg0, f32 *, 0x40)) * 1.5f));
temp_fv1_13 = M2C_FIELD(M2C_FIELD(temp_s1, void **, 0xBC), f32 *, 0x2C) - (cosAngle(M2C_FIELD(arg0, f32 *, 0x40)) * 1.5f);
D_800E1A1C = 0.0f;
sp5C = 0.0f;
M2C_FIELD(arg0, f32 *, 0x2C) = temp_fv1_13;
break;
case 1:
M2C_FIELD(arg0, f32 *, 0x24) = (f32) (M2C_FIELD(M2C_FIELD(temp_s1, void **, 0xBC), f32 *, 0x24) - (sinAngle(M2C_FIELD(temp_a0_8, f32 *, 0x40)) * 1.5f));
M2C_FIELD(arg0, f32 *, 0x2C) = (f32) (M2C_FIELD(M2C_FIELD(temp_s1, void **, 0xBC), f32 *, 0x2C) - (cosAngle(M2C_FIELD(M2C_FIELD(temp_s1, void **, 0xBC), f32 *, 0x40)) * 1.5f));
M2C_FIELD(arg0, f32 *, 0x40) = (f32) M2C_FIELD(M2C_FIELD(temp_s1, void **, 0xBC), f32 *, 0x40);
if (func_80081AA4(temp_s4, 0x12) != 0) {
*(&D_8011508B + (temp_s4 * 0xA0)) = M2C_FIELD(temp_s1, u8 *, 0x18B);
M2C_FIELD(temp_s1, u8 *, 0x18A) = 2U;
} else if (func_8008194C(temp_s4, 0xE) != 0) {
temp_a0_9 = M2C_FIELD(temp_s1, void **, 0xBC);
if (M2C_FIELD(temp_a0_9, s16 *, 0x7A) == 2) {
M2C_FIELD(temp_a0_9, s16 *, 0x7A) = 6;
}
} else {
temp_a0_10 = M2C_FIELD(temp_s1, void **, 0xBC);
if (M2C_FIELD(temp_a0_10, s16 *, 0x7A) == 7) {
M2C_FIELD(temp_a0_10, s16 *, 0x7A) = 8;
}
}
break;
case 2:
sp5C = 0.0f;
func_800635BC(arg0, 0);
M2C_FIELD(arg0, f32 *, 0x3C) = sp5C;
M2C_FIELD(M2C_FIELD(temp_s1, void **, 0xBC), s16 *, 0x7A) = 5;
temp_v1_36 = M2C_FIELD(arg0, void **, 0x68);
M2C_FIELD(temp_v1_36, u8 *, 0x10) = (u8) M2C_FIELD(temp_v1_36, u8 *, 0xE);
M2C_FIELD(M2C_FIELD(arg0, void **, 0x68), s8 *, 0xF) = (s8) M2C_FIELD(temp_s1, u16 *, 0x134);
break;
}
goto block_430;
}
}
}
