/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */
#ifndef M2C_DEFINES
#define M2C_DEFINES
typedef s32 M2C_UNK;
typedef s8 M2C_UNK8;
typedef s16 M2C_UNK16;
typedef s32 M2C_UNK32;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define M2C_CARRY 0
#define M2C_OVERFLOW(a) (0)
#endif

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
extern void *D_800B5B14;
extern u16 D_800BD680;
extern s16 D_800BD682;
extern char D_800C3CF8[];
extern s8 D_80107ECC;
extern void *D_80109BB0;
extern char D_8010A488[];

void func_8001BA84(void) {
    s32 temp_s0;
    s32 temp_v0_2;
    u16 temp_v1;
    void *temp_v0;

    func_8002ACB4(D_8010A488);
    if (D_800B5B14 != NULL) {
        func_80002EF0(D_800B5B14);
        M2C_FIELD(D_800B5B14, f32 *, 0x24) = 0.85f;
        M2C_FIELD(D_800B5B14, f32 *, 0x28) = 0.25f;
        M2C_FIELD(D_800B5B14, f32 *, 0x2C) = -3.0f;
        M2C_FIELD(D_800B5B14, f32 *, 0x54) = 1.05f;
        func_80002D30(D_800B5B14, 0x14D);
        if (func_80029C08(D_8010A488, 2, 0) & 0xFFFF) {
            temp_v0 = func_8002A980(D_8010A488);
            if (temp_v0 != NULL) {
                temp_s0 = func_800262A8(M2C_FIELD(D_80109BB0, s32 *, 0x10), 0x4000);
                temp_v0_2 = func_800316C8();
                if (temp_v0_2 != 0) {
                    if (temp_s0 != 0) {
                        func_80026004(temp_s0, "%s", func_80087100(*(s32 *)((M2C_FIELD(temp_v0, u8 *, 8) * 4) + temp_v0_2)));
                    }
                    func_8002B8AC();
                    temp_v1 = *(u16 *)*(D_800C3CF8 + (func_8002B9CC(func_8002B9FC(M2C_FIELD(((M2C_FIELD(temp_v0, u8 *, 8) * 4) + temp_v0_2), u8 *, 2))) * 0xC));
                    D_800BD682 = -1;
                    D_80107ECC = 1;
                    D_800BD680 = temp_v1;
                    func_80044D28(&D_800BD680);
                    D_80107ECC = 0;
                    func_8000237C(D_800B5B14, func_8002B9CC(func_8002B9FC(M2C_FIELD(((M2C_FIELD(temp_v0, u8 *, 8) * 4) + temp_v0_2), u8 *, 2))), 0, 0);
                    func_80002BD0(D_800B5B14, 0x14D);
                    M2C_FIELD(M2C_FIELD(D_800B5B14, void **, 0x68), f32 *, 0x34) = 0.05f;
                }
            }
        }
    }
}
