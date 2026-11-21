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

s32 requestSound();
s32 func_8005B5A8();
s32 func_8007092C();
extern s32 D_800C4470;
extern s32 D_800C4474;
extern void *gPlayerActor;
extern s32 gBonusObjectTable;

void func_8005C6F8(void) {
    char *var_s0;
    char *var_s1;
    u32 var_s2;
    s32 var_s3;
    s32 var_v0;
    u32 temp_a0;

    var_s3 = 0;
    if (gPlayerActor != NULL) {
        var_v0 = var_s3;
        if (M2C_FIELD(gPlayerActor, void **, 0x70) != NULL) {
            for (var_s2 = 0; var_s2 < 1U; var_s2++) {
                temp_a0 = M2C_FIELD(M2C_FIELD(gPlayerActor, void **, 0x70), u32 *, 0x30);
                if ((((temp_a0 >> 4) & 0xFFFF) == ((s32 *)&D_800C4470)[var_s2]) && ((temp_a0 >> 0x14) == ((s32 *)&D_800C4474)[var_s2]) && (M2C_FIELD(gPlayerActor, u16 *, 0x78) == 0x12) && (M2C_FIELD(gPlayerActor, s16 *, 0x7C) == 0)) {
                    M2C_FIELD(gPlayerActor, s16 *, 0x7C) = 1;
                    M2C_FIELD(gPlayerActor, s32 *, 0x60) |= 0x08000000;
                    requestSound(0x1D2, gPlayerActor);
                    var_s3 = 1;
                    func_8007092C(gBonusObjectTable, 1);
                }
            }
            goto block_9;
        }
    } else {
block_9:
        var_v0 = var_s3;
    }
    if (var_v0 == 0) {
        func_8005B5A8();
    }
}
