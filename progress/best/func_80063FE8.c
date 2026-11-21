/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

s32 actorInitTrackMarker();
f32 approxDistance();
s16 randomIntBelow();
extern u8 D_80100BE0[];
extern s32 gSaveTotalSlots;
extern u8 gSceneType;
extern u32 gTrackMarkerCount;
extern s32 gTrackMarkerIndex;
extern s32 gTrackMarkerPosTable;
extern s32 sBonusObjectTable;

void func_80063FE8(void *arg0) {
    f32 temp_fv0;
    f32 var_fs0;
    f32 var_fs1;
    s16 temp_s1;
    s16 temp_v0;
    s16 temp_v0_2;
    s16 var_s0;
    s16 var_s0_2;
    u16 var_s1;
    s16 var_s4;
    s32 temp_v1;
    void *temp_s3;

    var_fs1 = -1.0f;
    temp_s3 = (*(void **)((char *)(arg0) + 0x6C));
    temp_v1 = (u32) (gSceneType - 2) < 2U;
    var_s4 = 0;
    if (temp_v1 == 0) {
        for (;;) {
            var_s0 = 0;
            temp_s1 = randomIntBelow(gTrackMarkerCount);
            if (gSaveTotalSlots > 0) {
loop_3:
                if ((var_s0 == (*(s8 *)((char *)(temp_s3) + 0x182))) || !(approxDistance(((temp_s1 & 0xFFFF) * 0xC) + &gTrackMarkerPosTable, (&sBonusObjectTable)[var_s0] + 0x24) < 3.0f)) {
                    var_s0 = temp_v0;
                    var_s0 = var_s0 + 1;
                    if (var_s0 < gSaveTotalSlots) {
                        goto loop_3;
                    }
                } else {
                    continue;
                }
            }
            break;
        }
        var_s4 = temp_s1;
    } else {
        var_s1 = 0;
        if (gTrackMarkerCount != 0) {
            do {
                if ((temp_v1 == 0) || (*(D_80100BE0 + (var_s1 & 0xFFFF)) == (*(u8 *)((char *)((*(void **)((char *)(temp_s3) + 0xB4))) + 0x12)))) {
                    var_fs0 = 4194304.0f;
                    var_s0_2 = 0;
                    if (gSaveTotalSlots > 0) {
                        do {
                            if (var_s0_2 != (*(s8 *)((char *)(temp_s3) + 0x182))) {
                                temp_fv0 = approxDistance(((var_s1 & 0xFFFF) * 0xC) + &gTrackMarkerPosTable, (&sBonusObjectTable)[var_s0_2] + 0x24);
                                if (temp_fv0 < var_fs0) {
                                    var_fs0 = temp_fv0;
                                }
                            }
                            temp_v0_2 = var_s0_2 + 1;
                            var_s0_2 = temp_v0_2;
                        } while (temp_v0_2 < gSaveTotalSlots);
                    }
                    if (var_fs1 < var_fs0) {
                        var_fs1 = var_fs0;
                        var_s4 = var_s1;
                    }
                }
                var_s1 += 1;
            } while ((u32) (var_s1 & 0xFFFF) < (u32) gTrackMarkerCount);
        }
    }
    gTrackMarkerIndex = (s32) var_s4;
    actorInitTrackMarker(arg0);
}
