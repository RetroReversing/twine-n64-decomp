/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

s32 func_80018318();
s32 func_80022B60();
s32 func_80022E5C();
s32 func_80022E88();
s32 func_80022EB8();
extern s32 D_800BD64C;
extern s32 D_800BD650;
extern s32 D_800BD65C;
extern s32 D_800BD660;
extern s32 D_800BD664;
extern u8 D_801001A1[];
extern s32 D_80102EBC;
extern void *D_80109BB0;

void func_8001CCF4(void *arg0, s32 arg1, s32 arg2) {
    s32 flags;
    void *temp_a1;
    void *temp_s0;
    void *temp_v1;
    void *temp_v1_2;
    void *var_a1;

    temp_s0 = (*(void **)((char *)(arg0) + 0));
    temp_v1 = (*(void **)((char *)(temp_s0) + 0));
    if (temp_v1 != NULL) {
        (*(u16 *)((char *)(temp_v1) + 0x20)) = (u16) (*(u16 *)((char *)(arg0) + 4));
        (*(u16 *)((char *)((*(void **)((char *)(temp_s0) + 0))) + 0x22)) = (u16) (*(u16 *)((char *)(arg0) + 6));
        temp_a1 = (*(void **)((char *)(temp_s0) + 0));
        (*(s32 *)((char *)((*(void **)((char *)(temp_s0) + 0))) + 0x10)) = (arg2 & 0xFF) ? (s32) ((D_800BD660 & ~0xFF) | (*(u8 *)((char *)(D_80109BB0) + 0x30))) : (s32) (D_80102EBC);
        temp_a1 = *(void * volatile *)temp_s0;
        flags = (u8)arg1 == 0;
        flags = -flags;
        flags &= 7;
        flags |= 3;
        (*(s32 *)((char *)(temp_a1) + 0x28)) = (s32) (((*(s32 *)((char *)(temp_a1) + 0x28)) & ~0xFC) | (flags << 2));
        func_80022E88(3, temp_a1);
        func_80022E5C((*(u8 *)((char *)(D_80109BB0) + 0x30)));
        if (arg2 & 0xFF) {
            func_80022EB8(((*(u16 *)((char *)(arg0) + 4)) - 2) & 0xFFFF, ((*(u8 *)((char *)(arg0) + 7)) - 4) & 0xFF, (func_80018318((*(void **)((char *)(temp_s0) + 0))) * 0xC) & 0xFC);
            var_a1 = (*(void **)((char *)(temp_s0) + 0));
            (*(s32 *)((char *)(var_a1) + 0x10)) = (s32) ((D_800BD664 & ~0xFF) | (*(u8 *)((char *)(D_80109BB0) + 0x30)));
        } else {
            var_a1 = (*(void **)((char *)(temp_s0) + 0));
            (*(s32 *)((char *)(var_a1) + 0x10)) = (s32) ((D_800BD64C & ~0xFF) | (*(u8 *)((char *)(D_80109BB0) + 0x30)));
        }
        temp_v1_2 = (*(void **)((char *)(temp_s0) + 4));
        if (temp_v1_2 != NULL) {
            (*(s16 *)((char *)(temp_v1_2) + 0x20)) = (s16) ((*(u16 *)((char *)(arg0) + 4)) + 0x7E);
            (*(u16 *)((char *)((*(void **)((char *)(temp_s0) + 4))) + 0x22)) = (u16) (*(u16 *)((char *)(arg0) + 6));
            if (arg2 & 0xFF) {
                var_a1 = (*(void **)((char *)(temp_s0) + 4));
                (*(s32 *)((char *)(var_a1) + 0x10)) = ((D_800BD664 & ~0xFF) | (*(u8 *)((char *)(D_80109BB0) + 0x30)));
            } else {
                var_a1 = (*(void **)((char *)(temp_s0) + 4));
                if (*(D_801001A1 + ((*(u8 *)((char *)(arg0) + 8)) * 0x18)) == 0)
                    (*(s32 *)((char *)(var_a1) + 0x10)) = ((D_800BD65C & ~0xFF) | (*(u8 *)((char *)(D_80109BB0) + 0x30)));
                else
                    (*(s32 *)((char *)(var_a1) + 0x10)) = ((D_800BD650 & ~0xFF) | (*(u8 *)((char *)(D_80109BB0) + 0x30)));
            }
            var_a1 = (*(void **)((char *)(temp_s0) + 4));
            (*(s32 *)((char *)(var_a1) + 0x28)) = (s32) (((*(s32 *)((char *)(var_a1) + 0x28)) & ~0xFC) | ((*(s32 *)((char *)((*(void **)((char *)(temp_s0) + 0))) + 0x28)) & 0xFC));
        }
        func_80022B60(3, var_a1);
    }
}
