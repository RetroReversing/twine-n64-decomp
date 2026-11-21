void func_80043FA0(void);
void func_800723C0(f32 *, f32 *, f32 *, void **, s32);
void subdivideTriangle(f32, f32 *, f32 *, f32 *, void **, s32);
void func_80082FE4(s16 *, f32 *);
void rotateVec3ByMat3(f32 *, f32 *);

void func_8003941C(void **arg0, s32 arg1, f32 *arg2, f32 *arg3, s32 arg4) {
    f32 sp18[54];
    volatile u8 spF0[6];
    f32 spF8[12];
    s16 sp128[3];
    long var_s2;
    u8 sp147;
    unsigned long sp14C;
    register f32 *ent;
    s32 var_s1;
    register u8 *p;
    u32 *var_s6;
    u32 *var_s7;
    u32 pad[2];

    sp147 = 0;
    var_s1 = 0;
    if (*arg0 != NULL || (func_80043FA0(), *arg0 != NULL)) {
        var_s6 = *arg0;
        if (arg3 != NULL) {
            sp128[0] = (s16)arg3[0];
            sp128[1] = (s16)arg3[1];
            sp128[2] = (s16)arg3[2];
            func_80082FE4(sp128, spF8);
        }
        sp14C = (s8)arg4;
        var_s7 = var_s6 + 1;
        do {
            switch (var_s6[0] & 0xFF000000) {
            case 0x1000000:
                var_s1 = var_s7[0] - 0x80000000;
                break;
            case 0x6000000:
                spF0[3] = (u8)((var_s7[0] >> 17) & 0x7F);
                spF0[4] = (u8)((var_s7[0] & 0xFF00) >> 9);
                spF0[5] = (u8)(*((u8 *)var_s7 + 3) >> 1);
                ent = sp18 + 27;
                var_s2 = 3;
                do {
                    p = (u8 *)(var_s1 + spF0[var_s2] * 16);
                    ent[0] = (f32)*(s16 *)(p + 0) * 0.015625f;
                    ent[1] = (f32)*(s16 *)(p + 2) * 0.015625f;
                    ent[2] = (f32)*(s16 *)(p + 4) * 0.015625f;
                    ent[4] = (f32)*(s16 *)(p + 0xA);
                    ent[3] = (f32)*(s16 *)(p + 8);
                    ent[6] = (f32)p[0xD];
                    ent[5] = (f32)p[0xC];
                    ent[8] = (f32)p[0xF];
                    ent[7] = (f32)p[0xE];
                    if (arg3 != NULL) {
                        rotateVec3ByMat3(spF8, ent);
                    }
                    var_s2 += 1;
                    if (arg2 != NULL) {
                        ent[0] = ent[0] + arg2[0];
                        ent[1] = ent[1] + arg2[1];
                        ent[2] = ent[2] + arg2[2];
                    }
                    ent += 9;
                } while (var_s2 < 6U);
                if (sp14C) {
                    subdivideTriangle(0.0f, &sp18[27], &sp18[36], &sp18[45], arg0, arg1);
                } else {
                    func_800723C0(&sp18[27], &sp18[36], &sp18[45], arg0, arg1);
                }
                /* fallthrough */
            case 0x5:
                spF0[0] = (u8)((var_s6[0] >> 17) & 0x7F);
                spF0[1] = (u8)((var_s6[0] & 0xFF00) >> 9);
                spF0[2] = (u8)(*((u8 *)var_s6 + 3) >> 1);
                ent = sp18;
                var_s2 = 0;
                do {
                    p = (u8 *)(var_s1 + spF0[var_s2] * 16);
                    ent[0] = (f32)*(s16 *)(p + 0) * 0.015625f;
                    ent[1] = (f32)*(s16 *)(p + 2) * 0.015625f;
                    ent[2] = (f32)*(s16 *)(p + 4) * 0.015625f;
                    ent[3] = (f32)*(s16 *)(p + 8);
                    ent[4] = (f32)*(s16 *)(p + 0xA);
                    ent[5] = (f32)p[0xC];
                    ent[6] = (f32)p[0xD];
                    ent[7] = (f32)p[0xE];
                    ent[8] = (f32)p[0xF];
                    if (arg3 != (unsigned)NULL) {
                        rotateVec3ByMat3(spF8, ent);
                    }
                    var_s2 += 1;
                    if (arg2 != (unsigned)NULL) {
                        ent[0] = ent[0] + arg2[0];
                        ent[2] = ent[2] + arg2[2];
                        ent[1] = ent[1] + arg2[1];
                    }
                    ent += 9;
                } while (var_s2 < 3U);
                if (sp14C != 0) {
                    subdivideTriangle(0.0f, &sp18[0], &sp18[9], &sp18[18], arg0, arg1);
                } else {
                    func_800723C0(&sp18[0], &sp18[9], &sp18[18], arg0, arg1);
                }
                break;
            case 0xDF000000:
                sp147 = 1;
                break;
            }
            var_s6 += 2;
            var_s7 += 2;
        } while (!sp147);
    }
}
