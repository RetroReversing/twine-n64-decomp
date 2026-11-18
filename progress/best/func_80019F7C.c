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

s32 func_80001E28();
s32 func_8000237C();
s32 func_80002BD0();
s32 func_80002D30();
s32 func_80019E28();
s32 func_80026004();
void *func_800262A8();
s32 func_80027C60();
s32 func_80027CE0();
s32 func_80029068();
s32 func_8002B8AC();
s32 func_8002B930();
s32 func_8002B9CC();
s32 func_8002BA6C();
s32 func_8002BC28();
s32 func_80044D28();
extern void *D_800B5B14;
extern u16 D_800BD680;
extern s16 D_800BD682;
extern char D_800BF688[];
extern char D_800C3CF8[];
extern char D_8010019C[];
extern char D_801001A3[];
extern u8 D_801002AD;
extern s32 D_801002B8;
extern s8 D_80107ECC;
extern void *D_80109BB0;

void func_80019F7C(void) {
    s32 var_a1;
    s32 temp_a0;
    s32 temp_v0;
    s32 var_s1;
    u16 temp_v1;
    u16 temp_v1_3;
    u8 temp_s0_2;
    u8 temp_v1_2;
    void *temp_s0;
    void *temp_s3;
    void *temp_s4;

    temp_s0 = M2C_FIELD(D_80109BB0, void **, 0x18);
    temp_s4 = func_800262A8(M2C_FIELD(D_80109BB0, s32 *, 0x10), 0x400C);
    func_80029068();
    var_s1 = *M2C_FIELD(temp_s0, s32 **, 0x10);
    temp_s3 = temp_s0 + 0x28;
    if ((M2C_FIELD(D_80109BB0, u8 *, 0x2D) != 0) && (M2C_FIELD(D_80109BB0, u8 *, 0x2E) == 0)) {
        *(D_801001A3 + (D_801002AD * 0x18)) = 0;
        if (func_80027CE0(0x20) & 0xFF) {
            var_s1 = func_8002B930(var_s1, -1);
        }
        if (func_80027CE0(0x21) & 0xFF) {
            var_s1 = func_8002B930(var_s1, 1);
        }
        *M2C_FIELD(temp_s0, s32 **, 0x10) = var_s1;
        if (D_800B5B14 != NULL) {
            func_8002B8AC();
            temp_v1 = *(u16 *)*(D_800C3CF8 + (func_8002B9CC(var_s1) * 0xC));
            D_800BD682 = -1;
            D_80107ECC = 1;
            D_800BD680 = temp_v1;
            func_80044D28(&D_800BD680);
            D_80107ECC = 0;
            func_8000237C(D_800B5B14, func_8002B9CC(var_s1), 0, *(D_801001A3 + (D_801002AD * 0x18)));
            func_80002BD0(D_800B5B14, 0x14D);
            M2C_FIELD(M2C_FIELD(D_800B5B14, void **, 0x68), f32 *, 0x34) = 0.05f;
            var_a1 = 0x327;
            if (!(func_8002BC28(*(D_8010019C + (D_801002AD * 0x18))) & 0xFF)) {
                var_a1 = 0x2A9;
            }
            func_80002D30(D_800B5B14, var_a1);
            goto block_11;
        }
    } else {
block_11:
        M2C_FIELD(D_80109BB0, u8 *, 0x2D) = 0U;
        if (func_80027C60(0x28) & 0xFF) {
            temp_a0 = D_801002AD * 0x18;
            temp_v1_2 = *(D_801001A3 + temp_a0);
            if (temp_v1_2 != 0) {
                M2C_FIELD((temp_a0 + (&D_801002AD - 0x115)), s8 *, 0xB) = (s8) (temp_v1_2 - 1);
                M2C_FIELD(D_80109BB0, u8 *, 0x2D) = 1U;
            }
        }
        if (func_80027C60(0x29) & 0xFF) {
            temp_s0_2 = *(D_801001A3 + (D_801002AD * 0x18));
            if ((s32) temp_s0_2 < func_80001E28(*(s32 *)*(D_800C3CF8 + (func_8002B9CC(var_s1) * 0xC)))) {
                temp_v0 = D_801002AD * 0x18;
                M2C_FIELD((temp_v0 + (&D_801002AD - 0x115)), s8 *, 0xB) = (s8) (*(D_801001A3 + temp_v0) + 1);
                M2C_FIELD(D_80109BB0, u8 *, 0x2D) = 1U;
            }
        }
        if ((M2C_FIELD(D_80109BB0, u8 *, 0x2D) != 0) && (M2C_FIELD(D_80109BB0, u8 *, 0x2E) == 0)) {
            if (D_800B5B14 != NULL) {
                func_8002B8AC();
                temp_v1_3 = *(u16 *)*(D_800C3CF8 + (func_8002B9CC(var_s1) * 0xC));
                D_800BD682 = -1;
                D_80107ECC = 1;
                D_800BD680 = temp_v1_3;
                func_80044D28(&D_800BD680);
                D_80107ECC = 0;
                func_8000237C(D_800B5B14, func_8002B9CC(var_s1), 0, *(D_801001A3 + (D_801002AD * 0x18)));
                func_80002BD0(D_800B5B14, 0x14D);
                M2C_FIELD(M2C_FIELD(D_800B5B14, void **, 0x68), f32 *, 0x34) = 0.05f;
                goto block_21;
            }
        } else {
block_21:
            if (temp_s3 != NULL) {
                func_80026004(temp_s3, "%s", func_8002BA6C(var_s1));
            }
            if (temp_s4 != NULL) {
                func_80019E28(temp_s4);
            }
            if (D_801002B8 < (s32) D_801002AD) {
                func_80026004(func_800262A8(M2C_FIELD(D_80109BB0, s32 *, 0x10), 0x4004), "%d", *(D_800BF688 + (*(D_8010019C + (D_801002AD * 0x18)) * 0xC)) * 5);
            }
        }
    }
}
