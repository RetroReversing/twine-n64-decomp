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
extern s32 D_800C4440;
extern s32 D_800C4444;
extern void *gPlayerActor;

s32 func_8005BC7C(void) {
    u32 i;
    u32 temp_a1;
    s32 var_a2;
    s32 var_v0;

    var_a2 = 0;
    if (gPlayerActor != NULL && M2C_FIELD(gPlayerActor, void **, 0x70) != NULL) {
        for (i = 0; i < 1U; i++) {
            temp_a1 = M2C_FIELD(M2C_FIELD(gPlayerActor, void **, 0x70), u32 *, 0x30);
            if ((((temp_a1 >> 4) & 0xFFFF) == ((s32 *)&D_800C4440)[i]) && ((temp_a1 >> 0x14) == ((s32 *)&D_800C4444)[i]) && (M2C_FIELD(gPlayerActor, u16 *, 0x78) == 0x12) && (M2C_FIELD(gPlayerActor, s16 *, 0x7C) == 0)) {
                requestSound(0x12D, temp_a1, var_a2);
                var_a2 = 1;
                M2C_FIELD(gPlayerActor, s32 *, 0x60) |= 0x08000000;
            }
        }
    }
    var_v0 = var_a2;
    if (var_v0 == 0) {
        var_v0 = func_8005B5A8();
    }
    return var_v0;
}
