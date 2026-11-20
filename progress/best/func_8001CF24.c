/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

s32 func_80018318();
s32 func_80019B34();
s32 func_80022B60();
s32 func_80022E5C();
s32 func_80022E88();
s32 func_80022EB8();
s32 func_80087100();
s32 strlen();
extern s32 D_800BD64C;
extern s32 D_800BD654;
extern s32 D_800BD65C;
extern s32 D_800BD664;
extern u8 D_801001A1[];
extern u8 D_801002A0;
extern s32 D_80102EBC;
extern void *D_80109BB0;

void func_8001CF24(void *arg0, u8 arg1, s8 arg2) {
int __repair_literal;
 /* baseline */
    unsigned var_v0_2;
    s32 palette;
    void *temp_a1;
    void *temp_s0;
    void *temp_s1;
    void *temp_v1;
    void *var_a1;

    temp_s1 = (*(void **)((char *)(arg0) + 0));
    temp_v1 = (*(void **)((char *)(temp_s1) + 0));
    if (temp_v1 != NULL) {
        (*(u16 *)((char *)(temp_v1) + 0x20)) = (u16) (*(u16 *)((char *)(arg0) + 4));
        temp_a1 = (*(void **)((char *)(temp_s1) + 0));
        (*(u16 *)((char *)((*(void **)((char *)(temp_s1) + 0))) + 0x22)) = (u16) (*(u16 *)((char *)(arg0) + 6));
        palette = arg1 & 0xFF;
        palette = -(palette == 0);
        palette &= 7;
        palette |= 3;
        (*(s32 *)((char *)(temp_a1) + 0x28)) = (s32) (((*(s32 *)((char *)(temp_a1) + 0x28)) & ~0xFC) | (palette * 4));
        func_80022E88(3);
        func_80022E5C((*(u8 *)((char *)(D_80109BB0) + 0x30)));
        if (arg2 & 0xFF) {
            do { func_80022EB8(((*(u16 *)((char *)(arg0) + 4)) - 2) & 0xFFFF, ((*(u8 *)((char *)(arg0) + 7)) - 4) & 0xFF, (func_80018318((*(void **)((char *)(temp_s1) + 0))) * 0xC) & 0xFC); } while (0);
            var_a1 = (*(void **)((char *)(temp_s1) + 0));
            (*(s32 *)((char *)(var_a1) + 0x10)) = (s32) ((D_800BD664 & ~0xFF) | (*(u8 *)((char *)(D_80109BB0) + 0x30)));
        } else {
            var_a1 = (*(void **)((char *)(temp_s1) + 0));
            (*(s32 *)((char *)(var_a1) + 0x10)) = (s32) ((D_800BD64C & ~0xFF) | (*(u8 *)((char *)(D_80109BB0) + 0x30)));
        }
        if ((*(void **)((char *)(temp_s1) + 4)) != NULL) {
            (*(s32 *)((char *)((*(void **)((char *)(temp_s1) + 4))) + 0x18)) = func_80087100(func_80019B34((*(u8 *)((char *)(arg0) + 8)), var_a1) & 0xFFFF);
            temp_s0 = (*(void **)((char *)(temp_s1) + 4));
            (*(s16 *)((char *)(temp_s0) + 0x1C)) = strlen((*(s32 *)((char *)(temp_s0) + 0x18)));
            (*(s16 *)((char *)((*(void **)((char *)(temp_s1) + 4))) + 0x20)) = (s16) ((*(u16 *)((char *)(arg0) + 4)) + 0x7E);
            (*(u16 *)((char *)((*(void **)((char *)(temp_s1) + 4))) + 0x22)) = (u16) (*(u16 *)((char *)(arg0) + 6));
            var_v0_2 = arg2 & 0xFF;
__repair_literal = 2;

            if (((s32) D_801002A0 >= __repair_literal) && ((var_v0_2 = arg2 & 0xFF, (((s32) D_801002A0 < 4) != 0)) || (var_v0_2 = arg2 & 0xFF, (D_801002A0 == 6)))) {
                if (var_v0_2 != 0) {
                    (*(s32 *)((char *)((*(void **)((char *)(temp_s1) + 4))) + 0x10)) = (s32) ((D_800BD664 & ~0xFF) | (*(u8 *)((char *)(D_80109BB0) + 0x30)));
                } else if (*(D_801001A1 + ((*(u8 *)((char *)(arg0) + 8)) * 0x18)) == 0) {
                    (*(s32 *)((char *)((*(void **)((char *)(temp_s1) + 4))) + 0x10)) = (s32) ((D_800BD65C & ~0xFF) | (*(u8 *)((char *)(D_80109BB0) + 0x30)));
                } else {
                    (*(s32 *)((char *)((*(void **)((char *)(temp_s1) + 4))) + 0x10)) = (s32) ((D_800BD654 & ~0xFF) | (*(u8 *)((char *)(D_80109BB0) + 0x30)));
                }
            } else if (var_v0_2 != 0) {
                (*(s32 *)((char *)((*(void **)((char *)(temp_s1) + 4))) + 0x10)) = (s32) ((D_800BD664 & ~0xFF) | (*(u8 *)((char *)(D_80109BB0) + 0x30)));
            } else {
                (*(s32 *)((char *)((*(void **)((char *)(temp_s1) + 4))) + 0x10)) = (s32) ((D_80102EBC & ~0xFF) | (*(u8 *)((char *)(D_80109BB0) + 0x30)));
            }
            var_a1 = (*(void **)((char *)(temp_s1) + 4));
            (*(s32 *)((char *)(var_a1) + 0x28)) = (s32) (((*(s32 *)((char *)(var_a1) + 0x28)) & ~0xFC) | ((*(s32 *)((char *)((*(void **)((char *)(temp_s1) + 0))) + 0x28)) & 0xFC));
        }
        func_80022B60(3, var_a1);
    }
}
