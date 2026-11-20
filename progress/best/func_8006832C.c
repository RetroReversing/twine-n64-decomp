/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

s32 func_8000A270();
s32 func_800158A4();
f32 Vec3_DistanceSq();
s32 func_80045764();
s32 func_80046384(void *, f32, f32, f32);
s32 func_80055B5C();
s32 func_800589FC();
s32 func_80064370();
s32 func_800643EC();
s32 func_80067A7C();
s32 UpdateActorTargetEffect();
f32 sinAngle(f32);
f32 cosAngle(f32);
s32 rotateVec3ByMat3();
extern char D_800C46FC[];
extern f32 D_800C683C;
extern s16 D_800C6858;
extern u16 D_800C68BA;
extern s32 gBorderSkipFlag;
extern void *gPlayerActor;
extern char gTrackMarkerTable[];
extern char D_80109A98[];
extern char D_80109A9C[];
extern char D_80109AA0[];
extern s32 D_801176D8;

void func_8006832C(void *arg0, f32 *arg1) {
    char *__base_D_80109688;
    f32 sp28[3];
    f32 sp38[3];
    f32 sp48[3];
    f32 sp58[3];
    f32 sp68[3];
    char sp78[0x10];
    f32 sp88[9];
    f32 spB8;
    s32 spC0;
    s32 (*temp_a1_2)(void *, s32);
    f32 *var_s1;
    f32 temp_a0;
    f32 temp_a1;
    f32 temp_fa0;
    f32 temp_fs0;
    f32 temp_fs0_2;
    f32 temp_fs0_3;
    f32 temp_fs0_4;
    f32 temp_fs0_5;
    f32 temp_ft0;
    f32 temp_ft1;
    f32 temp_fv0;
    s32 temp_a0_2;
    s32 temp_v0_4;
    unsigned long temp_v0_5;
    s32 temp_v0_6;
    register s32 temp_s7;
    u32 var_s0;
    u32 var_s0_2;
    void **temp_s4;
    void *temp_s2;
    void *temp_v0;
    void *temp_v0_2;
    void *temp_v0_3;

    temp_s2 = (*(void **)((char *)(arg0) + 0x6C));
    temp_s7 = (*(s8 *)((char *)(temp_s2) + 0x182));
    __base_D_80109688 = gTrackMarkerTable;
    temp_s4 = (temp_s7 * 4) + __base_D_80109688;
    sp28[0] = (*(f32 *)((char *)(*temp_s4) + 0x34));
    sp28[2] = 0;
    sp28[1] = (*(f32 *)((char *)(*temp_s4) + 0x38));
    var_s1 = arg1;
    if ((*(u8 *)((char *)(temp_s2) + 0x184)) == 0) {
        temp_v0 = *temp_s4;
        temp_a0 = (*(f32 *)((char *)(temp_v0) + 0x14));
        temp_a1 = (*(f32 *)((char *)(temp_v0) + 0x18));
        sp48[1] = temp_a0;
        sp48[0] = (*(f32 *)((char *)(temp_v0) + 0x10));
        sp48[2] = temp_a1;
        temp_fa0 = sp28[1] * 651.8986f;
        sp38[1] = temp_fa0;
        sp38[0] = -(sp28[0] * 651.8986f);
        temp_v0_2 = *temp_s4;
        sp58[0] = -(((*(f32 *)((char *)(temp_v0_2) + 0x78)) * (*(f32 *)((char *)(temp_s2) + 0x24))) / (*(f32 *)((char *)(temp_v0_2) + 0x4C))) / (*(f32 *)((char *)(temp_v0_2) + 0x68));
        temp_v0_3 = *temp_s4;
        sp58[1] = (((*(f32 *)((char *)(temp_v0_3) + 0x7C)) * (*(f32 *)((char *)(temp_s2) + 0x28))) / (*(f32 *)((char *)(temp_v0_3) + 0x4C))) / (*(f32 *)((char *)(temp_v0_3) + 0x6C));
        sp58[2] = 1.0f;
        sp88[0] = cosAngle(temp_fa0);
        temp_fs0 = sinAngle(sp38[0]);
        sp88[1] = -temp_fs0 * sinAngle(temp_fa0);
        temp_fs0_2 = sinAngle(temp_fa0);
        temp_fs0_3 = temp_fs0_2 * cosAngle(sp38[0]);
        sp88[3] = 0;
        sp88[2] = temp_fs0_3;
        sp88[4] = cosAngle(sp38[0]);
        sp88[5] = sinAngle(sp38[0]);
        sp88[6] = -sinAngle(temp_fa0);
        temp_fs0_4 = cosAngle(temp_fa0);
        sp88[7] = -(temp_fs0_4 * sinAngle(sp38[0]));
        temp_fs0_5 = cosAngle(sp38[0]);
        sp88[8] = temp_fs0_5 * cosAngle(temp_fa0);
        rotateVec3ByMat3(sp88);
        func_80045764(sp58, sp58);
        temp_ft1 = sp58[0] * 256.0f;
        temp_ft0 = sp58[1] * 256.0f;
        temp_fv0 = sp58[2] * 256.0f;
        sp58[0] = temp_ft1;
        sp58[1] = temp_ft0;
        sp58[2] = temp_fv0;
        sp58[0] = temp_ft1 + sp48[0];
        sp58[1] = temp_ft0 + sp48[1];
        sp58[2] = temp_fv0 + sp48[2];
        if (*(s32 *)(D_800C46FC + ((*(s8 *)((char *)((*(void **)((char *)(arg0) + 0x68))) + 0xE)) * 0xE8)) & 8) {
            temp_v0_4 = temp_s7 * 0xC;
            *(s32 *)(D_80109A98 + temp_v0_4) = sp58[0];
            *(s32 *)(D_80109A9C + temp_v0_4) = sp58[1];
            *(s32 *)(D_80109AA0 + temp_v0_4) = sp58[2];
        }
        if ((func_800158A4(sp48, sp58, (*(s32 *)((char *)(*temp_s4) + 0xF4)), sp68, 0, 0, (*(s32 *)((char *)(temp_s2) + 0)), 0, 0) << 0x18) == 0) {
            if (((*(s16 *)((char *)((*(void **)((char *)(temp_s2) + 0xA8))) + 0x7A)) == 0) && ((*(s8 *)((char *)((*(void **)((char *)(arg0) + 0x68))) + 0xE)) == 0x21) && (gPlayerActor != NULL) && ((*(s16 *)((char *)(gPlayerActor) + 0x7A)) == 0x72)) {
                if (Vec3_DistanceSq(sp48, sp68) < D_800C683C) {
                    temp_a0_2 = (*(s32 *)((char *)(temp_s2) + 8));
                    if (temp_a0_2 != -1) {
                        func_8000A270(temp_a0_2);
                        (*(s32 *)((char *)(temp_s2) + 8)) = -1;
                    }
                    (*(s32 *)((char *)(temp_s2) + 0x10)) = (s32) D_800C6858;
                    var_s1 = &D_800C683C - 0x18;
                    func_80067A7C(temp_s2, (*(void **)((char *)(temp_s2) + 0xA8)), D_800C68BA);
                }
            }
            UpdateActorTargetEffect(arg0, sp68);
            sp68[0] -= sp48[0];
            sp68[1] -= sp48[1];
            sp68[2] -= sp48[2];
            func_80045764(sp78, sp68);
            func_80046384(&spB8, sp68[0], sp68[1], sp68[2]);
            spC0 = 0;
            spB8 = -spB8;
            func_800643EC(arg0);
            if (((*(s32 *)((char *)(var_s1) + 0x64)) & 0x201) == 1) {
                D_801176D8 += 1;
            }
            var_s0 = 0;
            if ((*(u8 *)((char *)(var_s1) + 0x14)) != 0) {
                do {
                    temp_v0_5 = func_80055B5C((s16) temp_s7, arg0, var_s1, sp48, &spB8, sp78, (*(s32 *)((char *)(temp_s2) + 0)));
                    if (temp_v0_5 != 0) {
                        func_80064370(temp_v0_5, temp_s7);
                    }
                    var_s0 += 1;
                } while (var_s0 < (u8) (*(u8 *)((char *)(var_s1) + 0x14)));
            }
        } else {
            sp68[0] = sp58[0] - sp48[0];
            sp68[1] = sp58[1] - sp48[1];
            sp68[2] = sp58[2] - sp48[2];
            func_80045764(sp78, sp68);
            func_80046384(sp38, sp68[0], sp68[1], sp68[2]);
            sp38[2] = 0;
            sp38[0] = -sp38[0];
            func_800643EC(arg0);
            if (((*(s32 *)((char *)(var_s1) + 0x64)) & 0x201) == 1) {
                D_801176D8 += 1;
            }
            var_s0_2 = 0;
            if ((*(u8 *)((char *)(var_s1) + 0x14)) != 0) {
                do {
                    temp_v0_6 = func_80055B5C((s16) temp_s7, arg0, var_s1, sp48, sp38, sp78, (*(s32 *)((char *)(temp_s2) + 0)));
                    if (temp_v0_6) {
                        func_80064370(temp_v0_6, temp_s7);
                    }
                    var_s0_2 += 1;
                } while (var_s0_2 < (u8) (*(u8 *)((char *)(var_s1) + 0x14)));
            }
            UpdateActorTargetEffect(arg0, sp58);
        }
        if (((*(u8 *)((char *)(var_s1) + 0x9E)) != 0xFF) && ((*(s32 *)((char *)(var_s1) + 0x60)) & 0x100) && (gBorderSkipFlag == 0)) {
            func_800589FC(arg0, (*(s32 *)((char *)((*(void **)((char *)((*(void **)((char *)(temp_s2) + 0xA8))) + 0x68))) + 4)) + ((*(u16 *)((char *)(var_s1) + 0x90)) * 0xC));
        }
        (*(f32 *)((char *)(temp_s2) + 0x70)) -= (*(f32 *)((char *)(var_s1) + 0x88));
        (*(f32 *)((char *)(temp_s2) + 0x74)) += (*(f32 *)((char *)(var_s1) + 0x8C));
        if ((*(u8 *)((char *)(var_s1) + 0x80)) == 0) {
            temp_a1_2 = (*(s32 (**)(void *, s32))((char *)(var_s1) + 0xD0));
            if (temp_a1_2 != NULL) {
                temp_a1_2(arg0, temp_a1_2);
            }
        }
    }
}
