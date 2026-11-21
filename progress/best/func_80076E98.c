/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

s32 clearProbeState(void *, s32);           /* extern */
s32 func_80002BD0(void *, u16);                 /* extern */
s32 func_80002C74(void *, u16, u16);            /* extern */
s32 func_80002CAC(void *, u16, u16);            /* extern */
s32 func_80077960(void *, s32);             /* extern */
s32 func_8007947C(void *);                      /* extern */
s32 randomIntBelow(s32);                        /* extern */
extern s32 D_800C9970;
extern s32 D_800C9972;
extern s32 D_800C99AC;
extern s32 D_800C99AE;
extern s32 D_800C99E8;
extern s32 D_800C9A08;
extern s32 D_800C9A0A;
extern s32 D_800C9A1C;
extern s32 D_800C9A1E;

typedef struct { s32 w[3]; } __repair_words3;
void func_80076E98(void *arg0) {
    volatile s32 scratch[8];
    s32 var_a1;
    s16 temp_v1;
    s16 temp_v1_2;
    s32 temp_v0;
    void *temp_s1;
    s32 temp_v0_3;
    s32 temp_v0_4;
    s32 temp_v1_3;
    unsigned var_s2;
    s32 var_v0;
    u16 var_a1_2;
    u16 var_a2;
    s32 temp_v0_2;

    temp_v1 = (*(s16 *)((char *)(arg0) + 0x7A));
    temp_s1 = (*(void **)((char *)(arg0) + 0x6C));
    if ((temp_v1 != 0x2D) && ((*(u8 *)((char *)(temp_s1) + 0x7E)) == 0)) {
        (*(u8 *)((char *)(temp_s1) + 0x7E)) = (u8) temp_v1;
    }
    if ((*(s32 *)((char *)(temp_s1) + 0x64)) == 0x22) {
        (*(s16 *)((char *)(arg0) + 0x7C)) = 0xC;
        (*(s8 *)((char *)(temp_s1) + 0x7F)) = 0xC;
        (*(s32 *)((char *)(arg0) + 0x74)) = 0;
        clearProbeState(arg0, 0x205);
        var_a1 = 0x71;
        goto block_23;
    }
    temp_v1_2 = (*(s16 *)((char *)(arg0) + 0x7C));
    var_s2 = 0;
    switch (temp_v1_2) {
    case 2:
    case 5:
        (*(s16 *)((char *)(arg0) + 0x7C)) = 5;
        (*(s8 *)((char *)(temp_s1) + 0x7F)) = 5;
        temp_v0 = ((u32) (*(u32 *)((char *)(temp_s1) + 0x88)) >> 0xF) & 0x3C;
        var_a1_2 = *(u16 *)((u8 *)&D_800C9970 + temp_v0);
        var_a2 = *(u16 *)((u8 *)&D_800C9972 + temp_v0);
        var_s2 = 1;
block_19:
        func_80002CAC(arg0, var_a1_2, var_a2);
    case 11:
    default:
        var_v0 = var_s2;
        break;
    case 6:
    case 10:
        (*(s16 *)((char *)(arg0) + 0x7C)) = 6;
        (*(s8 *)((char *)(temp_s1) + 0x7F)) = 6;
        temp_v0_2 = ((u32) (*(u32 *)((char *)(temp_s1) + 0x88)) >> 0xF) & 0x3C;
        func_80002C74(arg0, *(u16 *)((u8 *)&D_800C99AC + temp_v0_2), *(u16 *)((u8 *)&D_800C99AE + temp_v0_2));
        var_v0 = 1;
        break;
    case 1:
        (*(s16 *)((char *)(arg0) + 0x7C)) = 4;
        (*(s8 *)((char *)(temp_s1) + 0x7F)) = 4;
        var_s2 = 1;
        func_80002BD0(arg0, *(u16 *)((u8 *)&D_800C99E8 + ((*(u16 *)((char *)(temp_s1) + 0x88)) & 0x1E)));
        var_v0 = var_s2;
        break;
    case 0:
    case 3:
    case 4:
    case 7:
        (*(s16 *)((char *)(arg0) + 0x7C)) = 4;
        (*(s8 *)((char *)(temp_s1) + 0x7F)) = 4;
        temp_v1_3 = ((u32) (*(u32 *)((char *)(temp_s1) + 0x88)) >> 0x11) & 0xF;
        var_s2 = 1;
        if (temp_v1_3 == 7) {
block_17:
            temp_v0_4 = (randomIntBelow(5) & 0xFFFF) * 4;
            var_a1_2 = *(u16 *)((u8 *)&D_800C9A08 + temp_v0_4);
            var_a2 = *(u16 *)((u8 *)&D_800C9A0A + temp_v0_4);
        } else {
            if (temp_v1_3 >= 8) {
                if (temp_v1_3 == 0xE) {
                    goto block_17;
                }
                goto block_18;
            }
            if (temp_v1_3 != 0) {
block_18:
                temp_v0_3 = ((u32) (*(u32 *)((char *)(temp_s1) + 0x88)) >> 0xF) & 0x3C;
                var_a1_2 = *(u16 *)((u8 *)&D_800C9A1C + temp_v0_3);
                var_a2 = *(u16 *)((u8 *)&D_800C9A1E + temp_v0_3);
            } else {
                goto block_17;
            }
        }
        goto block_19;
    }
    if (var_v0 != 0) {
        (*(__repair_words3 *)((char *)(temp_s1) + 0x18)) = *(__repair_words3 *) ((s8 *) temp_s1 + 0x50);
        func_8007947C(arg0);
        var_a1 = 0x2D;
block_23:
        func_80077960(arg0, var_a1);
    }
}
