/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

extern unsigned char D_8010A4C3;
s32 func_8004844C();
s32 func_80048794();
s32 func_800820B0();
extern s32 D_80000300;
extern s32 D_800CA31C;
extern f64 D_800D48B0;
extern f64 D_800D48B8;
extern f64 D_800D48C8;
extern f64 D_800D48D0;
extern f64 D_800D48E0;
extern s32 D_801002B4;
extern s32 D_801002C0;
extern s32 D_80102ED8;
extern char D_80109688[];
extern void *D_80109698;
extern void *D_8010969C;
extern u8 D_8010A4C2;
extern u8 D_8010A4FD;

typedef struct { void * value; } __repair_field_0;
void func_8007560C(void) {
    unsigned var_a0;
    f32 temp_fs0_2;
    f32 temp_fs0_3;
    f32 temp_fs0_4;
    f32 temp_fs0_5;
    f32 temp_fs1;
    f32 temp_fs2;
    f32 temp_fs2_2;
    f32 temp_fs2_3;
    f32 temp_fs3;
    f32 temp_fs3_2;
    f32 temp_fs4;
    f32 var_a1;
    register f32 var_a2;
    f32 var_a3;
    f64 temp_fs0;
    f64 var_fv0;
    f64 var_fv1;
    f64 var_fv1_2;
    f64 var_fv1_3;
    f64 var_fv1_4;
    long temp_v1;
    s32 var_s0;
    int var_v1;
    void **var_s1;
    void *temp_s4;
    void *temp_v1_2;
    void *var_a0_2;

    if (D_80000300 != 0) {

    }
    if (D_80109698 == (s32)NULL) {
        func_80048794(4, D_800CA31C);
    }
    var_fv1 = (f64) 0;
    if (0 < 0) {
        var_fv1 += D_800D48B0;
    }
    func_8004844C(D_80109698, 160.0f, 120.0f, 320.0f, (f32) var_fv1, (f32) (f64) 0);
    D_8010A4C3 = (u8) (D_8010A4C3 & 0xEF);
    (*(u8 *)((char *)(&D_8010A4C3) + -2)) &= 0xEF;
    (*(s32 *)((char *)(D_80109698) + 0x100)) |= 0x100;
    if (D_8010969C == NULL) {
        func_80048794(5, D_800CA31C);
    }
    var_fv1_2 = (f64) 0;
    if (0 > 0) {
        var_fv1_2 += D_800D48B8;
    }
    func_8004844C(D_8010969C, 160.0f, 120.0f, 320.0f, (f32) var_fv1_2, (f32) (f64) 0);
    D_8010A4C3 = (u8) (D_8010A4C3 & 0xDF);
    (*(u8 *)((char *)(&D_8010A4C3) + -2)) &= 0xDF;
    D_8010A4C2 |= 0x20;
    (*(s32 *)((char *)(D_8010969C) + (int)0x100)) |= 0x100;
    if (!D_80102ED8) {
        if (((__repair_field_0 *)D_80109688)->value == NULL) {
            func_80048794(0, D_800CA31C);
        }
        if (0 > 0) {

        }
        var_fv1_3 = (f64) 0;
        if (0 < 0) {
            var_fv1_3 += D_800D48C8;
        }
        func_8004844C(((__repair_field_0 *)D_80109688)->value, 160.0f, 120.0f, 320.0f, (f32) var_fv1_3);
        var_a0 = 1;
        goto block_75;
    }
    var_s0 = 0;
    if (D_801002B4 > 0) {
        temp_fs0 = D_800D48D0;
        temp_s4 = &D_8010A4C3 - 1;
        var_s1 = &D_80109698 - 0x10;
        do {
            if (*var_s1 == NULL) {
                func_80048794(var_s0, D_800CA31C);
                if (0 > 0) {

                }
                var_fv0 = (f64) 0;
                if (0 < 0) {
                    var_fv0 += temp_fs0;
                }
                func_8004844C(*var_s1, 160.0f, 120.0f, 160.0f + 160.0f, (f32) var_fv0);
                if (D_801002C0 <= var_s0) {
                    var_v1 = 1 << var_s0;
                    if ((D_801002C0 == 3) & (var_s0 == 3)) {
                        D_8010A4C3 = (u8) (D_8010A4C3 | var_v1);
                    } else {
                        D_8010A4C3 = (u8) (D_8010A4C3 & ~(1 << var_s0));
                        var_v1 = 1 << var_s0;
                    }
                    temp_v1 = ~var_v1;
                    (*(u8 *)((char *)(temp_s4) + 0)) &= temp_v1;
                    (*(u8 *)((char *)(temp_s4) + -1)) &= temp_v1;
                    temp_v1_2 = *var_s1;
                    (*(s32 *)((char *)(temp_v1_2) + 0x100)) |= 0x100;
                } else {
                    D_8010A4C3 = (u8) (D_8010A4C3 | (1 << var_s0));
                }
            }
            var_s1 += 4;
            ++var_s0;
        } while (var_s0 < D_801002B4);
    }
    switch (D_801002C0) {                           /* irregular */
    case 1:
        if (((__repair_field_0 *)D_80109688)->value == (u32)NULL) {
            func_80048794(0, D_800CA31C);
        }
        if (0 < 0) {

        }
        var_fv1_4 = (f64) 0;
        if (0 < 0) {
            var_fv1_4 += (s32)D_800D48E0;
        }
        func_8004844C(((__repair_field_0 *)D_80109688)->value, 160.0f, 120.0f, 160.0f + 160.0f, (f32) var_fv1_4);
        break;
    case 4:
        if (((__repair_field_0 *)D_80109688)->value == NULL) {
            func_80048794(0, D_800CA31C);
        }
        if ((*(void **)((char *)(D_80109688) + 4)) == NULL) {
            func_80048794(1, D_800CA31C);
        }
        if ((*(void **)((char *)(D_80109688) + 8)) == NULL) {
            func_80048794(2, D_800CA31C);
        }
        if ((*(void **)((char *)(D_80109688) + 0xC)) == NULL) {
            func_80048794(3, D_800CA31C);
        }
        temp_fs2_3 = 160.0f * 0.5f;
        temp_fs4 = 120.0f * 0.5f;
        temp_fs1 = 120.0f * 0.5f;
        func_8004844C(((__repair_field_0 *)D_80109688)->value, temp_fs2_3, temp_fs4, 160.0f, 120.0f, 1.0f, 1.0f);
        temp_fs3_2 = temp_fs2_3 + 160.0f;
        func_8004844C((*(void **)((char *)(D_80109688) + 4)), temp_fs3_2, temp_fs1, 160.0f, 120.0f, 1.0f, 1.0f);
        func_8004844C((*(void **)((char *)(D_80109688) + 8)), temp_fs2_3, 120.0f + temp_fs4, 160.0f, 120.0f, 1.0f, 1.0f);
        var_a0_2 = (*(void **)((char *)(D_80109688) + 0xC));
        var_a1 = temp_fs3_2;
        var_a2 = 120.0f + temp_fs1;
        var_a3 = 160.0f;
        goto block_74;
    case 3:
        if (((__repair_field_0 *)D_80109688)->value == NULL) {
            func_80048794(0, D_800CA31C);
        }
        if ((*(void **)((char *)(D_80109688) + 4)) == NULL) {
            func_80048794(1, D_800CA31C);
        }
        if ((*(void **)((char *)(D_80109688) + 8)) == NULL) {
            func_80048794(2, D_800CA31C);
        }
        if ((*(void **)((char *)(D_80109688) + 0xC)) == NULL) {
            func_80048794(3, D_800CA31C);
        }
        temp_fs2_2 = 160.0f * 0.5f;
        temp_fs0_4 = 120.0f * 0.5f;
        func_8004844C(((__repair_field_0 *)D_80109688)->value, temp_fs2_2, temp_fs0_4, 160.0f, 120.0f, 1.0f, 1.0f);
        temp_fs3 = temp_fs2_2 + 160.0f;
        func_8004844C((*(void **)((char *)(D_80109688) + 4)), temp_fs3, temp_fs0_4, 160.0f, 120.0f, 1.0f, 1.0f);
        temp_fs0_5 = 120.0f + temp_fs0_4;
        func_8004844C((*(void **)((char *)(D_80109688) + 8)), temp_fs2_2, temp_fs0_5, 160.0f, 120.0f, 1.0f, 1.0f);
        var_a0_2 = (*(void **)((char *)(D_80109688) + 0xC));
        var_a1 = temp_fs3;
        var_a2 = temp_fs0_5;
        var_a3 = 160.0f;
        goto block_74;
    case 2:
        if (((__repair_field_0 *)D_80109688)->value == NULL) {
            func_80048794(0, D_800CA31C);
        }
        if ((*(void **)((char *)(D_80109688) + 4)) == NULL) {
            func_80048794(1, D_800CA31C);
        }
        if (D_8010A4FD == 1) {
            register temp_fs0_2 = 160.0f * 0.5f;
            func_8004844C(((__repair_field_0 *)D_80109688)->value, temp_fs0_2, 120.0f, 160.0f, 2.0f * 120.0f, 1.0f, 1.0f);
            var_a0_2 = (*(void **)((char *)(D_80109688) + 4));
            var_a2 = 120.0f;
            var_a1 = 160.0f + temp_fs0_2;
            var_a3 = 160.0f;
        } else {
            temp_fs0_3 = 120.0f * 0.5f;
            temp_fs2 = 160.0f + 160.0f;
            func_8004844C(((__repair_field_0 *)D_80109688)->value, 160.0f, temp_fs0_3, temp_fs2, 120.0f, 1.0f, 1.0f);
            var_a0_2 = (*(void **)((char *)(D_80109688) + 4));
            var_a1 = 160.0f;
            var_a3 = temp_fs2;
            var_a2 = 120.0f + temp_fs0_3;
        }
block_74:
        func_8004844C(var_a0_2, var_a1, var_a2, var_a3);
        var_a0 = 0;
block_75:
        func_800820B0(var_a0);
        break;
    }
    (*(s32 *)((char *)(((__repair_field_0 *)D_80109688)->value) + 0x100)) |= 0x40;
    (*(s8 *)((char *)(((__repair_field_0 *)D_80109688)->value) + 0x142)) = 4;
}
