/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

s32 func_8000237C();
s32 func_80002BD0();
s32 func_80002D30();
s32 func_80002EF0();
s32 func_80026004();
s32 func_800262A8();
s32 func_80029C08();
void *func_8002A980();
s32 func_8002ACB4();
s32 func_8002B8AC();
s32 func_8002B9CC();
s32 func_8002B9FC();
s32 func_800316C8();
s32 func_80044D28();
s32 func_80087100();
extern void *volatile D_800B5B14;
extern u16 D_800BD680;
extern s16 D_800BD682;
extern char D_800C3CF8[];
extern s8 D_80107ECC;
extern void *D_80109BB0;
extern char D_8010A488[];

extern char D_800D2864[];
void func_8001BA84(void) {
    void *o;
    s32 temp_v0_2;
    void *volatile *__base_D_800B5B14;
    long temp_s0;
    void *temp_v0;
    u16 temp_v1;
    u16 *__base_D_800BD680;

    func_8002ACB4(D_8010A488);
    __base_D_800B5B14 = &D_800B5B14;
    o = *__base_D_800B5B14;
    if (o != NULL) {
        func_80002EF0(o);
        (*(f32 *)((char *)(D_800B5B14) + 0x24)) = 0.85f;
        (*(f32 *)((char *)(D_800B5B14) + 0x28)) = 0.25f;
        (*(f32 *)((char *)(D_800B5B14) + 0x2C)) = -3.0f;
        (*(f32 *)((char *)(D_800B5B14) + 0x54)) = 1.05f;
        func_80002D30((*__base_D_800B5B14), 0x14D);
        if (func_80029C08(D_8010A488, 2, 0) & 0xFFFF) {
            temp_v0 = func_8002A980(D_8010A488);
            if (temp_v0 != NULL) {
                temp_s0 = func_800262A8((*(s32 *)((char *)(D_80109BB0) + 0x10)), 0x4000);
                temp_v0_2 = func_800316C8();
                if (temp_v0_2 != 0) {
                    if (temp_s0) {
                        func_80026004(temp_s0, D_800D2864, func_80087100(*(u16 *)(((*(u8 *)((char *)(temp_v0) + 8)) * 4) + temp_v0_2)));
                    }
                    func_8002B8AC();
                    temp_v1 = *(u16 *)*(s32 *)(D_800C3CF8 + (func_8002B9CC(func_8002B9FC((*(u8 *)((char *)((((*(u8 *)((char *)(temp_v0) + 8)) * 4) + (int)temp_v0_2)) + 2)))) * 0xC));
                    D_800BD682 = -1;
                    D_80107ECC = 1;
                    __base_D_800BD680 = &D_800BD680;
                    (*__base_D_800BD680) = temp_v1;
                    func_80044D28(__base_D_800BD680);
                    D_80107ECC = 0;
                    func_8000237C((*__base_D_800B5B14), func_8002B9CC(func_8002B9FC((*(u8 *)((char *)((((*(u8 *)((char *)(temp_v0) + 8)) * 4) + temp_v0_2)) + 2)))), 0, 0);
                    func_80002BD0((*__base_D_800B5B14), 0x14D);
                    (*(f32 *)((char *)((*(void **)((char *)(D_800B5B14) + 0x68))) + 0x34)) = 0.05f;
                }
            }
        }
    }
}
