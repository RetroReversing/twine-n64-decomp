/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

s32 func_80087F60();
s32 func_800936A8();
s32 func_8009D510();
s32 func_800A0170();
s32 osCreateMesgQueue();
s32 osRecvMesg();
s32 osSendMesg();
extern u8 D_800CEEC0;
extern char D_800E1AC0[];
extern u8 D_800E2CC0[];
extern s32 D_800E3F18;
extern s32 D_800E3F1C;
extern u32 D_800E3F20;
extern char D_800E3F24[];
extern s32 D_800E3F2C;
extern char D_800E3F30[];
extern s32 (*D_8010017C)(s32, s32);
extern u8 D_8010086C;
extern s32 func_80088F6C;

s32 func_80088040(u32 arg0, s32 arg1, s8 arg2, s8 arg3, u8 arg4, u8 arg5, u8 arg6) {
    s32 temp_a0;
    long temp_v0_2;
    s32 var_s2;
    unsigned var_v1_2;
    register void *temp_s1;
    unsigned var_s0;
    register unsigned int var_v1;
    u32 temp_v0;

    var_s0 = arg1;
    if (D_800CEEC0) {
        var_s2 = 0;
        if (arg0 < D_800E3F20) {
            var_v1 = 0;
loop_3:
            if (*(D_800E2CC0 + var_v1) != 0) {
                var_s2 += 1;
                var_v1 += 0x1228;
                if (2 <= var_s2) {

                } else {
                    goto loop_3;
                }
            }
            if (var_s2 != 2) {
                temp_s1 = (var_s2 * 0x1228) + D_800E1AC0;
                osCreateMesgQueue(temp_s1 + 0x11E0, temp_s1 + 0x11F8, 2);
                var_v1_2 = var_s0 * 8;
                if (!var_s0) {
                    var_s0 = 0x3E80;
                    if (*(s32 *)((arg0 * 4) + D_800E3F1C) == 0) {
                        var_s0 = 0x1F40;
                    }
                    var_v1_2 = var_s0 * 8;
                }
                (*(s8 *)((char *)((int)temp_s1) + 0x1204)) = arg2;
                (*(u8 *)((char *)(temp_s1) + 0x1202)) = (unsigned)arg4;
                (*(s8 *)((char *)(temp_s1) + 0x1201)) = arg3;
                (*(u8 *)((char *)(temp_s1) + 0x1203)) = arg5;
                (*(u8 *)((char *)(temp_s1) + 0x1219)) = arg6;
                (*(s32 *)((char *)(temp_s1) + 0x1208)) = var_s0;
                temp_a0 = (((var_v1_2 / 30) + 0x9F) / 160) * 0xA0;
                (*(s32 *)((char *)(temp_s1) + 0x1214)) = temp_a0;
                if (D_800E3F2C & 1) {
                    (*(s32 *)((char *)(temp_s1) + 0x1210)) = (s32) *(s32 *)(D_800E3F24 + (var_s2 * 4));
                } else {
                    temp_v0 = func_800936A8(temp_a0);
                    temp_v0_2 = D_8010017C(temp_v0, 0);
                    (*(s32 *)((char *)(temp_s1) + 0x1210)) = temp_v0_2;
                    func_800A0170(temp_v0_2, temp_v0);
                }
                if ((*(s32 *)((char *)(temp_s1) + 0x1210)) != 0) {
                    osRecvMesg(D_800E3F30, 0, 1);
                    func_8009D510(temp_s1, (*(s32 *)((arg0 * 4) + D_800E3F1C) & 0xFFFFFF) + D_800E3F18, (*(s32 *)((char *)(temp_s1) + 0x1210)), (*(s32 *)((char *)(temp_s1) + 0x1214)), &func_80088F6C);
                    if (D_8010086C != 0) {
                        (*(u8 *)((char *)(temp_s1) + 0x11DE)) = (u8) ((*(u8 *)((char *)(temp_s1) + (int)0x11DE)) * 2);
                    }
                    (*(s32 *)((char *)(temp_s1) + 0x120C)) = -1;
                    (*(s8 *)((char *)(temp_s1) + 0x1200)) = 1;
                    osSendMesg(D_800E3F30, 0);
                    return func_80087F60(var_s2);
                }
                goto block_18;
            }
            goto block_18;
        }
    }
block_18:
    return -1;
}
