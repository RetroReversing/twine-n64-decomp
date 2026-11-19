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

s32 func_800160FC();
s32 func_800162BC();
s32 func_80018318();
s32 func_80022A30();
s32 func_80022AD8();
s32 func_80026004();
s32 func_800262A8();
s32 func_8002A644();
s32 func_8002A7CC();
s32 func_8002A9A8();
s32 func_8002AC04();
s32 func_8002ACB4();
void *func_80087100();
s32 sprintf();
extern s16 D_800B60E2;
extern s32 *D_800B60E4;
extern s16 D_800B60E8;
extern u8 D_800BD68E;
extern u8 D_800BD68F;
extern char D_800BDBD0[];
extern char D_800CE92C[];
extern char D_800CE984[];
extern char D_800E0C70[];
extern char D_800E0C98[];
extern char D_800E0E40[];
extern char D_800E0ED4[];
extern u8 D_80102EE8;
extern s32 func_8001EA6C;
extern s32 func_8001EAF0;

void func_80020F84(void) {
    s32 *var_s5;
    s32 *temp_s1;
    s32 temp_s2;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 var_s3;
    u32 var_s4;
    void *temp_v0_3;

    D_800B60E2 = 3;
    D_800B60E4 = D_800E0C70;
    func_8002A644(D_800E0C70, D_800E0C98, 0x1A4, 0xB, 0x2D, 0xB4, 0x4C, 0xB, 0, &func_8001EA6C, &func_8001EAF0);
    D_800B60E8 = 0;
    temp_v0 = func_800262A8(D_800BDBD0, 0x4000);
    if (temp_v0 != 0) {
        do { func_80022A30(D_800BD68E, 0x2D, 0x46, 0xDC, 0x7F); } while (0);
        var_s5 = NULL;
        func_80026004(temp_v0, "%s", func_80087100(*(u16 *)(D_800E0ED4 + (D_800BD68F * 2)) | 0x7000));
        var_s4 = 0;
        switch (D_80102EE8) {                       /* irregular */
        case 1:
        case 2:
            var_s5 = D_800CE984;
            var_s4 = 6;
            break;
        case 0:
            var_s5 = D_800CE92C;
            var_s4 = 5;
            break;
        }
        var_s3 = 0;
        if (var_s4 != 0) {
            do {
                temp_s2 = var_s3 & 0xFFFF;
                temp_v0_2 = func_800162BC(D_800BD68E);
                temp_s1 = (temp_s2 * 4) + D_800E0E40;
                *temp_s1 = temp_v0_2;
                if (temp_v0_2 != 0) {
                    temp_v0_3 = func_80087100((var_s3 + 0x4002) & 0xFFFF);
                    M2C_FIELD(temp_v0_3, s8 *, 0) = 3;
                    M2C_FIELD(temp_v0_3, s8 *, 1) = 0x6E;
                    sprintf(temp_v0_3 + 2, "%s", func_80087100(M2C_FIELD(((temp_s2 * 8) + var_s5), u16 *, 6)));
                    func_800160FC(*temp_s1, temp_v0_3, 0x40);
                    func_8002A7CC(D_800B60E4, *temp_s1, var_s3 & 0xFF, func_80018318(*temp_s1) & 0xFF);
                }
                var_s3 += 1;
            } while ((u32) (var_s3 & 0xFFFF) < var_s4);
        }
        func_80022AD8(D_800BD68E);
        func_8002A9A8(D_800B60E4, 0);
        func_8002AC04(D_800B60E4, 1);
        func_8002ACB4(D_800B60E4);
    }
}
