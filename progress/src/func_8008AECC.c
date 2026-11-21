typedef struct { u8 active; u8 p0[0x5F]; u8 slot; u8 flag; u8 p1[6]; } Rec;
extern Rec *D_800E41DC;
extern u16 D_800E41E4;
extern u16 D_800E4216;
extern s32 D_800E4218;
extern u16 *D_800E421C;
extern s32 D_800E422C;
extern void *D_800E4230;
extern s32 D_800E4234;
extern s32 D_8010D378;
extern s32 D_8010D42C;
void func_8008A52C(u8 *, s32, s32);

void func_8008AECC(s32 arg0, u16 arg1) {
    volatile u64 scratch;
    s32 temp_a1;
    s32 temp_a1_2;
    s32 lim;
    s32 tb;
    s32 idx;
    s32 var_s0;
    s32 var_s1;
    s32 var_s2;
    s32 var_v1;
    u16 temp_v1_2;
    u16 temp_v1_3;
    u8 *temp_a0;
    u8 *temp_a0_2;
    u8 *temp_v1;
    u8 *var_v0;

    var_s1 = 0;
    var_s0 = 0;
    var_s2 = 0;
    if (D_800E41E4 != 0) {
        do {
            if (D_800E41DC[var_s0 & 0xFFFF].flag != 0) {
                D_800E41DC[var_s0 & 0xFFFF].flag = 0;
                var_s2 |= 1 << D_800E41DC[var_s0 & 0xFFFF].slot;
            }
            if (D_800E41DC[var_s0 & 0xFFFF].active != 0) {
                func_8008A52C((u8 *)&D_800E41DC[var_s0 & 0xFFFF], arg1 & 0xFFFF, var_s1 & 0xFF);
                var_s1 += 1;
            }
            var_s0 += 1;
        } while ((u32) (var_s0 & 0xFFFF) < (u16) D_800E41E4);
    }
    temp_a0_2 = (u8 *)((*D_800E421C * 0xA10) + D_800E4218);
    temp_v1_2 = *(u16 *)temp_a0_2;
    if (temp_v1_2 == 0) {
        *(s16 *)(temp_a0_2 + 0x3C) = 0;
        var_v0 = (u8 *)((*D_800E421C * 0xA10) + D_800E4218);
    } else {
        var_v0 = temp_a0_2 + ((temp_v1_2 - 1) * 0x50);
    }
    *(s32 *)(var_v0 + 0x54) = arg0;
    *(s32 *)(((*D_800E421C * 0xA10) + D_800E4218) + 8) = D_800E422C;
    *(s32 *)(((*D_800E421C * 0xA10) + D_800E4218) + 4) = var_s2;
    *(void **)(((*D_800E421C * 0xA10) + D_800E4218) + 0xC) = D_800E4230;
    if (D_800E4230 != NULL) {
        *(s16 *)(((*D_800E421C * 0xA10) + D_800E4218) + 2) = D_800E4234 / 192;
        temp_a1_2 = D_800E4234 + 0xC0;
        lim = *(s32 *)((u8 *)D_800E4230 + 4);
        D_800E4234 = temp_a1_2;
        if (temp_a1_2 == lim) {
            D_800E4234 = 0;
        }
    }
    *D_800E421C += 1;
    temp_v1_3 = *D_800E421C;
    if (temp_v1_3 < (u16) D_800E4216) {
        D_8010D378 = (D_800E4218 + (temp_v1_3 * 0xA10) + 0x10) & ~0xF;
        D_8010D42C = D_800E4218 + (*D_800E421C * 0xA10) + 0x10;
        *(u16 *)((*D_800E421C * 0xA10) + D_800E4218) = 0;
    }
}
