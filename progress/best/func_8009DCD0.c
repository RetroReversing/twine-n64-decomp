/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

s32 func_8009DBE8();

s32 func_8009DCD0(s32 arg0, void *arg1, s32 arg2) {
int *__repair_home2 = &arg2;

int *__repair_home0 = &arg0;

    s32 sp48;
    u8 temp_t4;
    s16 spB8;
    unsigned long spC0;
    s32 spC8;
    s16 spD0;
    u8 temp_t9;
    s16 spD4;
    register s16 spD6;
    s16 spDE;
    register s16 spDA;
    s16 spDC;
    s16 spD8;
    s32 *var_a3;
    s32 *var_t1;
    s32 *var_t2;
    s32 *var_v1;
    char *var_t0;
    s32 spB0;
    s16 spD2;
    void *var_v0;

    var_v0 = arg1;
    spD0 = (((s32) (*(u8 *)((char *)(arg1) + 1)) >> 6) & 3) | (((*(u8 *)((char *)(arg1) + 0)) & 0xF) * 4);
    var_a3 = &spC8;
    spD2 = (*(u8 *)((char *)(arg1) + 1)) & 0x3F;
    var_t0 = &spB8;
    var_t1 = &spC0;
    spD4 = ((s32) (*(u8 *)((char *)(arg1) + 2)) >> 3) & 0x1F;
    var_t2 = &spB0;
    spD6 = (((s32) (*(u8 *)((char *)(arg1) + 3)) >> 6) & 3) | (((*(u8 *)((char *)(arg1) + 2)) & 7) * 4);
    var_v1 = &sp48;
    spD8 = ((s32) (*(u8 *)((char *)(arg1) + 3)) >> 2) & 0xF;
    spDA = (((s32) (*(u8 *)((char *)(arg1) + 4)) >> 6) & 3) | (((*(u8 *)((char *)(arg1) + 3)) & 3) * 4);
    spDC = ((s32) (*(u8 *)((char *)(arg1) + 4)) >> 3) & 7;
    spDE = (*(u8 *)((char *)(arg1) + 4)) & 7;
    __repair_rows: {
        var_v1 += 0x1A;
        var_a3 += 2;
        (*(s16 *)((char *)(var_a3) + -2)) = (s16) (((s32) (*(u8 *)((char *)(var_v0) + 5)) >> 1) & 0x7F);
        temp_t4 = (*(u8 *)((char *)(var_v0) + 6));
        temp_t9 = (*(u8 *)((char *)(var_v0) + 5));
        var_v0 += 7;
        *(s16 *)var_t0 = ((temp_t4 >> 7) & 1) | ((temp_t9 & 1) * 2);
        var_t0 += 2;
        var_t1 += 2;
        (*(s16 *)((char *)(var_t1) + -2)) = (s16) (((s32) (*(u8 *)((char *)(var_v0) + -1)) >> 5) & 3);
        var_t2 += 2;
        (*(s16 *)((char *)(var_t2) + -2)) = (s16) ((((s32) (*(u8 *)((char *)(var_v0) + 0)) >> 7) & 1) | (((*(u8 *)((char *)(var_v0) + -1)) & 0x1F) * 2));
        (*(s16 *)((char *)(var_v1) + -0x16)) = (s16) ((((s32) (*(u8 *)((char *)(var_v0) + 1)) >> 6) & 3) | (((*(u8 *)((char *)(var_v0) + 0)) & 1) * 4));
        (*(s16 *)((char *)(var_v1) + -0x18)) = (s16) (((s32) (*(u8 *)((char *)(var_v0) + 0)) >> 1) & 7);
        (*(s16 *)((char *)((unsigned short)var_v1) + -0x1A)) = (s16) (((s32) (*(u8 *)((char *)(var_v0) + 0)) >> 4) & 7);
        (*(s16 *)((char *)(var_v1) + -0x14)) = (s16) (((s32) (*(u8 *)((char *)(var_v0) + 1)) >> 3) & 7);
        (*(s16 *)((char *)(var_v1) + -0x12)) = (s16) ((*(u8 *)((char *)(var_v0) + 1)) & 7);
        (*(s16 *)((char *)(var_v1) + -0x10)) = (s16) (((s32) (*(u8 *)((char *)(var_v0) + 2)) >> 5) & 7);
        (*(s16 *)((char *)(var_v1) + -0xE)) = (s16) (((s32) (*(u8 *)((char *)(var_v0) + 2)) >> 2) & 7);
        (*(s16 *)((char *)(var_v1) + -0xC)) = (s16) ((((s32) (*(u8 *)((char *)(var_v0) + 3)) >> 7) & 1) | (((*(u8 *)((char *)(var_v0) + 2)) & 3) * 2));
        (*(s16 *)((char *)(var_v1) + -0xA)) = (s16) (((s32) (*(u8 *)((char *)(var_v0) + 3)) >> 4) & 7);
        (*(s16 *)((char *)(var_v1) + -8)) = (s16) (((s32) (*(u8 *)((char *)(var_v0) + 3)) >> 1) & 7);
        (*(s16 *)((char *)(var_v1) + -6)) = (s16) ((((s32) (*(u8 *)((char *)(var_v0) + 4)) >> 6) & 3) | (((*(u8 *)((char *)(var_v0) + 3)) & 1) * 4));
        (*(s16 *)((char *)(var_v1) + -4)) = (s16) (((s32) (*(u8 *)((char *)(var_v0) + 4)) >> 3) & 7);
        (*(s16 *)((char *)(var_v1) + -2)) = (s16) ((*(u8 *)((char *)(var_v0) + 4)) & 7);
    }
if (var_v1 != &spB0) goto __repair_rows;
    func_8009DBE8((*__repair_home0),  &spD0,  &spC8,  &spB8,  &spC0,  &spB0);
    return 0;
}
