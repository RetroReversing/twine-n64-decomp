s32 func_8000A18C(); s32 func_8000A22C(); s32 func_8000A6F4(); s32 func_8000B384(); s32 func_8000B534(); s32 func_8000B900(); s32 func_80088AC0(); s32 func_80088C50(); s32 func_80092A68(); s32 func_80095820(); s32 func_8009CE34(); s32 func_8009CF18(); s32 func_8009D030();
extern char D_14CD630[],D_14D0ED0[],D_14DDC00[],D_14E2500[],D_1D69630[],D_800B2488[],D_800B256C[],D_800DD7D0[];
extern s32 D_800B2480,D_800E06B0,D_800E06FC,D_800E0700,D_800E0704,D_800E0708; extern s32 *D_800E070C; extern s16 gExpansionPakPresent;
s32 func_80009F04(void) {
    s32 ret;
    s32 s2;
s32 __repair_phase_s2;
    s32 v0;
    s32 i;
    u16 t;
    s32 mask = (gExpansionPakPresent != 0);
    mask = -mask & 0x140000;
    if (func_80095820(0x5622, 0x14, 0xA, 0xA, 0xFA, mask) != 0) {
        return 0;
    }
    __repair_phase_s2 = D_14D0ED0 - D_14CD630;
    v0 = func_8000B384(__repair_phase_s2, 0);
    D_800E06FC = v0;
    func_8000B900(v0, (s32)D_14CD630 & 0x0FFFFFFF, __repair_phase_s2);
    s2 = D_14DDC00 - D_14D0ED0;
    v0 = func_8000B384(s2, 0);
    D_800E0700 = v0;
    func_8000B900(v0, (s32)D_14D0ED0 & 0x0FFFFFFF, s2);
    s2 = D_14E2500 - D_14DDC00;
    v0 = func_8000B384(s2, 0);
    D_800E0704 = v0;
    func_8000B900(v0, (s32)D_14DDC00 & 0x0FFFFFFF, s2);
    func_80092A68(D_800E06FC, 0, D_14E2500, D_800E0704, D_800E0700);
    i = 0;
    if (D_800B2480 != 0) {
        do {
            t = *(u16 *)(D_800B2488 + i);
            i += 0xC;
            func_80092A68(D_800E06FC, t, D_14E2500, D_800E0704, D_800E0700);
        } while (*(s32 *)(D_800B2480 + i) != 0);
    }
    func_8009CE34(0xE7, 0);
    func_8009CE34(0xE8, 0);
    func_8009CE34(0xE9, 0);
    func_8009CE34(0xEA, 0);
    func_8009CE34(0xEB, 0);
    func_8009CE34(0xEC, 0);
    func_8009CE34(0xED, 0);
    func_8009CE34(0xEE, 0);
    func_8009CF18(0x7F, 0, 0);
    func_8009CE34(0x1B8, 1);
    func_80088C50(1);
    func_80088AC0(D_1D69630, 0);
    func_8009D030(D_800B256C);
    D_800E0708 = -1;
    D_800E070C = (s32 *)D_800DD7D0;
    func_8000A6F4();
    D_800E06B0 = -1;
    ret = func_8000B534();
    func_8000A18C(0xA);
    func_8000A22C(0xA);
    return ret;
}
