/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

s32 func_8000A310();
s32 func_8000A5D0();
void *func_80015F74(void *);
void *func_800162BC();
void *spawnEffectObject();
s32 objectListInsert();
s32 func_8002B000();
s32 func_8002E9D0();
s32 objectSetAnimFrame();
s32 func_80064318();
s32 memset();
extern u16 D_800BFC92;
extern s16 D_800BFCBC;
extern s16 D_800BFCE0;
extern s16 D_800BFD04;
extern char D_800BFD08[];
extern s16 D_800BFD70;
extern s32 D_800BFD74;
extern s16 D_800BFD94;
extern s16 D_800BFDB8;
extern s16 D_800BFDDC;
extern char D_800E1584[];
extern char D_800E1590[];
extern u8 gPendingMenuCommand;
extern char gTrackMarkerTable[];

typedef struct { void * field_0; unsigned char pad_4[36]; int field_28; void * field_2C; void * field_30; void * field_34; void * field_38; void * field_3C; short field_40; short field_42; short field_44; } __repair_record_temp_s1;
void *spawnTrackHudObject(s32 arg0) {
    s16 *__base_D_800BFD04;
    
    s16 *__base_D_800BFCBC;
    char *__base_D_800BFD08;
    s32 __repair_store_0;
    s32 __repair_store_1;
    s32 __repair_store_2;
    s32 __repair_store_3;
    char *var_a1;
    char *var_a2;
    char *var_a3;
    s32 temp_a0;
    s32 temp_a0_2;
    s32 temp_s0;
    int temp_v1;
    s32 temp_v1_2;
    void *temp_a1;
    
    void *temp_a1_3;
    void *temp_s1;
    void *temp_t0;
    void *temp_v0;
    void *temp_v0_2;
    
    void *temp_v0_4;
    void *var_a2_2;

    temp_v0 = spawnEffectObject(0x48, 0, 0);
    if (temp_v0 == NULL) {
        return NULL;
    }
    (*(s16 *)((char *)(temp_v0) + 0x78)) = 0x39;
    (*(s16 *)((char *)(temp_v0) + 0x7A)) = (s16) ((gPendingMenuCommand != 0) * 4);
    func_8000A310();
    func_8000A5D0(0xC);
    do { func_80064318(temp_v0, arg0 & 0xFFFF); } while (0);
    temp_s1 = (*(void **)((char *)(temp_v0) + 0x6C));
    (((__repair_record_temp_s1*)temp_s1)->field_0) = NULL;
    (((__repair_record_temp_s1*)temp_s1)->field_30) = NULL;
    (((__repair_record_temp_s1*)temp_s1)->field_28) = 0;
    (((__repair_record_temp_s1*)temp_s1)->field_2C) = NULL;
    (((__repair_record_temp_s1*)temp_s1)->field_44) = arg0;
    (((__repair_record_temp_s1*)temp_s1)->field_34) = NULL;
    (((__repair_record_temp_s1*)temp_s1)->field_40) = 0;
    (((__repair_record_temp_s1*)temp_s1)->field_42) = 0;
    (((__repair_record_temp_s1*)temp_s1)->field_38) = NULL;
    (((__repair_record_temp_s1*)temp_s1)->field_3C) = NULL;
    {
        s16 *mode = &D_800BFDDC;
        *mode = arg0;
        (((__repair_record_temp_s1*)temp_s1)->field_3C) = func_80015F74((char *)mode - 0x20);
    }
    var_a3 = &D_800BFD74;
    D_800BFD70 = arg0;
    __base_D_800BFD08 = D_800BFD08;
    var_a2 = (void *) ((((D_800BFC92 & 1) * 0x24)) + (s32) __base_D_800BFD08);
    {
        typedef struct { u32 words[9]; } MenuDescriptor;
        *(MenuDescriptor *)var_a3 = *(MenuDescriptor *)var_a2;
    }
    {
        s16 *descriptorMode = &D_800BFD94;
        *descriptorMode = arg0;
    D_800BFDB8 = arg0;
    D_800BFC92 += 1;
        var_a1 = (char *)descriptorMode - 0x20;
        if (gPendingMenuCommand != 0) {
            var_a1 = (char *)descriptorMode + 4;
        }
    }
    (((__repair_record_temp_s1*)temp_s1)->field_2C) = func_80015F74(var_a1);
    {
        s16 *mode = &D_800BFD04;
        *mode = arg0;
        temp_v0_2 = func_80015F74((char *)mode - 0x20);
    }
    (((__repair_record_temp_s1*)temp_s1)->field_34) = temp_v0_2;
    temp_a0 = (*(s32 *)((char *)(temp_v0_2) + 8));
    if (temp_a0 != 0) {
        memset(temp_a0, 0, (*(u16 *)((char *)(temp_v0_2) + 0x24)) * (*(u8 *)((char *)(temp_v0_2) + 0x28)));
    }
    {
        u16 __repair_i;
        for (__repair_i = 0; __repair_i < 9; __repair_i++) {
            temp_v0_2 = func_800162BC(arg0 & 0xFFFF);
            temp_a0_2 = __repair_i;
            var_a2_2 = (void *) (((temp_a0_2 * 4)) + (s32) temp_s1);
            (*(void **)((char *)(var_a2_2) + 4)) = temp_v0_2;
            if (temp_v0_2 != NULL) {
            (*(void **)((char *)(temp_v0_2) + 0x18)) = (void *) ((temp_a0_2 * 0xC) + D_800E1590);
            (*(s16 *)((char *)((*(void **)((char *)(var_a2_2) + 4))) + 0x1C)) = 0xB;
            temp_a1 = (*(void **)((char *)(var_a2_2) + 4));
            (*(s32 *)((char *)(temp_a1) + 0x28)) = (s32) (((*(s32 *)((char *)(temp_a1) + 0x28)) & ~0xFC) | 0x14);
            temp_a1 = (*(void **)((char *)(var_a2_2) + 4));
            temp_v1 = 0x100 - (temp_a0_2 * temp_a0_2 * 2);
            if (temp_v1 >= 0) {
            if (temp_v1 < 0x100) {
            (*(s32 *)((char *)(temp_a1) + 0x10)) = (s32) ((temp_v1 << 8) | 0x800000);
            } else {
            (*(s32 *)((char *)(temp_a1) + 0x10)) = 0x80FF00;
            }
            } else {
            (*(s32 *)((char *)(temp_a1) + 0x10)) = 0x800000;
            }
            var_a2_2 = (void *) __repair_i;
            temp_v1_2 = (s32) var_a2_2 * 4;
            temp_a1_3 = (void *) ((temp_v1_2) + (s32) temp_s1);
            (*(s16 *)((char *)((*(void **)((char *)(temp_a1_3) + 4))) + 0x1E)) = 0x40;
            (*(s16 *)((char *)((*(void **)((char *)(temp_a1_3) + 4))) + 0x20)) = 0xF0;
            (*(s16 *)((char *)((*(void **)((char *)(temp_a1_3) + 4))) + 0x22)) = (s16) (((s32) ((s32)var_a2_2 * 5) * 2) + 0x28);
            }
            func_8002E9D0((__repair_i * 0xC) + D_800E1590, 0xB, (s32) var_a2_2);
        }
    }
    __base_D_800BFCBC = &D_800BFCBC;
    (*__base_D_800BFCBC) = (s32)arg0;
    (((__repair_record_temp_s1*)temp_s1)->field_0) = func_80015F74((char *)__base_D_800BFCBC - 0x20);
    temp_v0_4 = spawnEffectObject(0, 0, 0);
    (((__repair_record_temp_s1*)temp_s1)->field_30) = temp_v0_4;
    if (temp_v0_4 != NULL) {
        (*(s16 *)((char *)(temp_v0_4) + 0x78)) = 0x1F;
        (*(s16 *)((char *)((((__repair_record_temp_s1*)temp_s1)->field_30)) + 0x7A)) = 0;
        (*(f32 *)((char *)((((__repair_record_temp_s1*)temp_s1)->field_30)) + 0x24)) = 4.1f;
        (*(f32 *)((char *)((((__repair_record_temp_s1*)temp_s1)->field_30)) + 0x28)) = -3.5f;
        (*(f32 *)((char *)((((__repair_record_temp_s1*)temp_s1)->field_30)) + 0x2C)) = -9.0f;
        (*(f32 *)((char *)((((__repair_record_temp_s1*)temp_s1)->field_30)) + 0x44)) = -284.44446f;
        (*(s8 *)((char *)((((__repair_record_temp_s1*)temp_s1)->field_30)) + 0x7F)) = 0;
        (*(s8 *)((char *)((((__repair_record_temp_s1*)temp_s1)->field_30)) + 0x80)) = 0;
        (*(s8 *)((char *)((((__repair_record_temp_s1*)temp_s1)->field_30)) + 0x81)) = 0;
        (*(f32 *)((char *)((((__repair_record_temp_s1*)temp_s1)->field_30)) + 0x54)) = 0.95f;
        objectSetAnimFrame((((__repair_record_temp_s1*)temp_s1)->field_30), 2, 0x24);
        temp_s0 = arg0 & 0xFFFF;
        func_80064318((((__repair_record_temp_s1*)temp_s1)->field_30), temp_s0);
        objectListInsert((((__repair_record_temp_s1*)temp_s1)->field_30), (*(s32 *)((char *)(*(s32 *)(gTrackMarkerTable + (temp_s0 * 4))) + 0xF4)));
        {
            s16 *mode = &D_800BFCE0;
            *mode = arg0;
            (((__repair_record_temp_s1*)temp_s1)->field_38) = func_80015F74((char *)mode - 0x20);
        }
        func_8002B000(D_800E1584, 0x1E);
    }
    return temp_v0;
}

