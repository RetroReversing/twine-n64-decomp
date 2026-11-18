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

M2C_UNK func_8000A18C(M2C_UNK);                     /* extern */
M2C_UNK func_8000A22C(M2C_UNK);                     /* extern */
M2C_UNK func_8000A6F4();                            /* extern */
s32 func_8000B384(s32, M2C_UNK);                    /* extern */
s32 func_8000B534();                                /* extern */
M2C_UNK func_8000B900(s32, s32, s32);               /* extern */
M2C_UNK func_80088AC0(M2C_UNK *, M2C_UNK);          /* extern */
M2C_UNK func_80088C50(M2C_UNK);                     /* extern */
M2C_UNK func_80092A68(s32, u16, M2C_UNK *, s32, s32); /* extern */
s32 func_80095820(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32, s32); /* extern */
M2C_UNK func_8009CE34(M2C_UNK, M2C_UNK);            /* extern */
M2C_UNK func_8009CF18(M2C_UNK, M2C_UNK, M2C_UNK);   /* extern */
M2C_UNK func_8009D030(M2C_UNK *);                   /* extern */
extern M2C_UNK D_14CD630;
extern M2C_UNK D_14D0ED0;
extern M2C_UNK D_14DDC00;
extern M2C_UNK D_14E2500;
extern M2C_UNK D_1D69630;
extern s32 D_800B2480;
extern M2C_UNK D_800B2488;
extern M2C_UNK D_800B256C;
extern M2C_UNK D_800DD7D0;
extern s32 D_800E06B0;
extern s32 D_800E06FC;
extern s32 D_800E0700;
extern s32 D_800E0704;
extern s32 D_800E0708;
extern M2C_UNK *D_800E070C;
extern s16 D_80108400;

s32 func_80009F04(void) {
    s32 temp_s0;
    s32 temp_s2;
    s32 temp_s2_2;
    s32 temp_s2_3;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v0_3;
    s32 var_s0;
    s32 var_v0;
    u16 temp_a1;

    var_v0 = 0;
    if (func_80095820(0x5622, 0x14, 0xA, 0xA, 0xFA, -(D_80108400 != 0) & 0x140000) == 0) {
        temp_s2 = &D_14D0ED0 - &D_14CD630;
        temp_v0 = func_8000B384(temp_s2, 0);
        D_800E06FC = temp_v0;
        func_8000B900(temp_v0, (s32) &D_14CD630 & 0x0FFFFFFF, temp_s2);
        temp_s2_2 = &D_14DDC00 - &D_14D0ED0;
        temp_v0_2 = func_8000B384(temp_s2_2, 0);
        D_800E0700 = temp_v0_2;
        func_8000B900(temp_v0_2, (s32) &D_14D0ED0 & 0x0FFFFFFF, temp_s2_2);
        temp_s2_3 = &D_14E2500 - &D_14DDC00;
        temp_v0_3 = func_8000B384(temp_s2_3, 0);
        D_800E0704 = temp_v0_3;
        func_8000B900(temp_v0_3, (s32) &D_14DDC00 & 0x0FFFFFFF, temp_s2_3);
        func_80092A68(D_800E06FC, 0U, &D_14E2500, D_800E0704, D_800E0700);
        var_s0 = 0;
        if (D_800B2480 != 0) {
            __repair_rows: {
                temp_a1 = *(&D_800B2488 + var_s0);
                var_s0 += 0xC;
                func_80092A68(D_800E06FC, temp_a1, &D_14E2500, D_800E0704, D_800E0700);
            }
if (*(&D_800B2480 + var_s0) != 0) goto __repair_rows;
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
        func_80088AC0(&D_1D69630, 0);
        func_8009D030(&D_800B256C);
        D_800E0708 = -1;
        D_800E070C = &D_800DD7D0;
        func_8000A6F4();
        D_800E06B0 = -1;
        temp_s0 = func_8000B534();
        func_8000A18C(0xA);
        func_8000A22C(0xA);
        var_v0 = temp_s0;
    }
    return var_v0;
}
