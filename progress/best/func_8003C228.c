/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

s32 emitScissorFromWindow();
s32 func_80034928();
s32 func_800399D0(void *arg0);
s32 func_8003A4C0();
s32 func_8003AF20();
s32 func_8003B954();
s32 SetScissorRect();
extern s8 D_800C0738;
extern s8 D_800E176C;
extern s32 D_8010A4D8;
extern s32 gHiResScreen;
extern void *sDisplayListCursor;

typedef struct { unsigned char pad[40]; int value; } __repair_field_28;
typedef struct { int value; } __repair_field_0;
typedef struct { unsigned char pad[8]; int value; } __repair_field_8;
typedef struct { unsigned char pad[20]; int value; } __repair_field_14;
typedef struct { unsigned char pad[16]; int value; } __repair_field_10;
void func_8003C228(void *arg0, s32 arg1, s32 arg2) {
    unsigned sp14;
    u8 sp1F;
    s32 temp_s7;
    f32 temp_fs1;
    s32 temp_s6;
    f32 temp_fs0;
    void *temp_v1_4;
    void *temp_v1_3;
    u16 var_a1;
    u32 temp_s1;
    u32 temp_s2;
    u32 var_a3;
    void *var_s0;
    s32 var_v0;
    u16 temp_v1;
    
    void *temp_v1_2;
    void *temp_a3_2;
    void *temp_a3;
    

    sp14 = arg2;
    var_s0 = (*(void **)((char *)(arg0) + 4));
    temp_fs1 = (*(f32 *)((char *)(arg0) + 0x50)) + (*(f32 *)((char *)(arg0) + 0x60));
    sp1F = 1;
    temp_fs0 = (*(f32 *)((char *)(arg0) + 0x58)) + (*(f32 *)((char *)(arg0) + 0x64));
    if (var_s0 != NULL) {
        temp_s7 = temp_fs1;
        temp_s6 = temp_fs0;
        do {
            if ((((u32) ((__repair_field_28 *)var_s0)->value >> 2) & 0x3F) == sp14) {
                temp_s1 = (((__repair_field_10 *)var_s0)->value);
                temp_v1 = (*(u16 *)((char *)(var_s0) + 0x1E));
                temp_s2 = (((__repair_field_14 *)var_s0)->value);
                if (temp_v1 & 0x1000) {
                    var_a1 = (*(u16 *)((char *)(var_s0) + 0x22));
                    var_a3 = *(u8 *)((char *)var_s0 + 0x28);
                    if (gHiResScreen) {
                        var_a1 *= 2;
                        var_a3 *= 2;
                    }
                    SetScissorRect((*(u16 *)((char *)(var_s0) + 0x20)), var_a1 & 0xFFFF, (*(u16 *)((char *)(var_s0) + 0x24)), var_a3);
                } else if (temp_v1 & 0x2000) {
                    emitScissorFromWindow(arg0);
                } else if ((u32) (temp_s1 & 0xFF) >= 5U) {
                    var_v0 = temp_s1 & 0xFF;
                    if (sp1F == 1) {
                        func_800399D0(arg0);
                        sp1F = 0;
                        func_80034928(arg0, D_8010A4D8);
                        var_v0 = temp_s1 & 0xFF;
                    }
                    if (var_v0) {
                        if ((*(u16 *)((char *)(var_s0) + 0x1E)) & 0x400) {
                            if (D_800E176C == 0) {
                                temp_v1_2 = sDisplayListCursor;
                                D_800E176C = 1;
                                sDisplayListCursor = temp_v1_2 + 8;
                                ((__repair_field_0 *)temp_v1_2)->value = 0xE3001201;
                                (*(s32 *)((char *)(temp_v1_2) + 4)) = 0x2000;
                            }
                        } else if (D_800E176C) {
void *temp_a0;

                            temp_a0 = sDisplayListCursor;
                            D_800E176C = 0;
                            sDisplayListCursor = temp_a0 + 8;
                            ((__repair_field_0 *)temp_a0)->value = 0xE3001201;
                            (*(s32 *)((char *)(temp_a0) + 4)) = 0;
                        }
                        if ((*(s32 *)((char *)(var_s0) + 0x18)) != 0) {
                            if ((*(u16 *)((char *)(var_s0) + 0x1E)) & 0x20) {
                                temp_v1_3 = sDisplayListCursor;
                                D_800C0738 = 1;
                                sDisplayListCursor = temp_v1_3 + 8;
                                ((__repair_field_0 *)temp_v1_3)->value = 0xFA000000;
                                (*(s32 *)((char *)(temp_v1_3) + 4)) = (s32) (temp_s1 & 0xFF);
                                sDisplayListCursor = temp_v1_3 + 0x10;
                                (((__repair_field_8 *)temp_v1_3)->value) = 0xFB000000;
                                (*(s32 *)((char *)(temp_v1_3) + 0xC)) = 0;
                                func_8003B954((s32) (temp_fs1 + 1.0f), (s32) (temp_fs0 + 1.0f), var_s0);
                            }
                            temp_a3 = sDisplayListCursor;
                            D_800C0738 = 0;
                            (*(s32 *)((char *)(temp_a3) + 4)) = (s32) (((temp_s1 >> 0x18) << 0x18) | (temp_s1 & 0xFF0000) | (temp_s1 & 0xFF00) | (temp_s1 & 0xFF));
                            sDisplayListCursor = temp_a3 + 8;
                            sDisplayListCursor = temp_a3 + 0x10;
                            ((__repair_field_0 *)temp_a3)->value = 0xFA000000;
                            (*(s32 *)((char *)(temp_a3) + 0xC)) = (s32) (((temp_s2 >> 0x18) << 0x18) | (temp_s2 & 0xFF0000) | (temp_s2 & 0xFF00));
                            (((__repair_field_8 *)temp_a3)->value) = 0xFB000000;
                            func_8003B954(temp_s7, temp_s6, var_s0, temp_a3);
                        } else {
void *temp_a0;

                            if ((*(u16 *)((char *)(var_s0) + 0x1E)) & 0x20) {
                                temp_a3_2 = sDisplayListCursor;
                                ((__repair_field_0 *)temp_a3_2)->value = 0xFA000000;
                                (*(s32 *)((char *)(temp_a3_2) + 4)) = (s32) (temp_s1 & 0xFF);
                                (((__repair_field_8 *)temp_a3_2)->value) = 0xFB000000;
                                (*(s32 *)((char *)(temp_a3_2) + 0xC)) = 0;
                                sDisplayListCursor = temp_a3_2 + 8;
                                sDisplayListCursor = temp_a3_2 + 0x10;
                                if ((((__repair_field_28 *)var_s0)->value & 3) == 1) {
                                    sDisplayListCursor = temp_a3_2 + 0x18;
                                    (((__repair_field_10 *)temp_a3_2)->value) = 0xFC119623;
                                    (((__repair_field_14 *)temp_a3_2)->value) = 0xFF2FFFFF;
                                    sDisplayListCursor = temp_a3_2 + 0x20;
                                    (*(s32 *)((char *)(temp_a3_2) + 0x18)) = 0xE3001001;
                                    (*(s32 *)((char *)(temp_a3_2) + 0x1C)) = 0x8000;
                                    func_8003AF20((s32) (temp_fs1 + 1.0f), (s32) (temp_fs0 + 1.0f), var_s0, temp_a3_2);
                                } else {
                                    func_8003A4C0((s32) (temp_fs1 + 1.0f), (s32) (temp_fs0 + 1.0f), var_s0, temp_a3_2);
                                }
                            }
                            (*(s32 *)((char *)(sDisplayListCursor) + 4)) = (s32) (((temp_s1 >> 0x18) << 0x18) | (temp_s1 & 0xFF0000) | (temp_s1 & 0xFF00) | (temp_s1 & 0xFF));
                            (((__repair_field_8 *)sDisplayListCursor)->value) = 0xFB000000;
                            ((__repair_field_0 *)sDisplayListCursor)->value = 0xFA000000;
                            (*(s32 *)((char *)(sDisplayListCursor) + 0xC)) = (s32) (((temp_s2 >> 0x18) << 0x18) | (temp_s2 & 0xFF0000) | (temp_s2 & 0xFF00));
                            temp_a0 = sDisplayListCursor + 0x10;
                            sDisplayListCursor += 8;
                            sDisplayListCursor = temp_a0;
                            if ((((__repair_field_28 *)var_s0)->value & 3) == 1) {
                                func_8003AF20(temp_s7, temp_s6, var_s0);
                            } else {
                                func_8003A4C0(temp_s7, temp_s6, var_s0);
                            }
                        }
                    }
                }
            }
            var_s0 = (*(void **)((char *)(var_s0) + 4));
        } while (var_s0 != NULL);
    }
    if (D_800E176C == 0) {
        temp_v1_4 = sDisplayListCursor;
        sDisplayListCursor = temp_v1_4 + 8;
        ((__repair_field_0 *)temp_v1_4)->value = 0xE3001201;
        (*(s32 *)((char *)(temp_v1_4) + 4)) = 0x2000;
    }
}
