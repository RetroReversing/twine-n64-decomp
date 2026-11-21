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
extern s32 sBonusObjectTable;

void func_8005C6F8(void) {
    u32 i; s32 s3; s32 v0; u32 a0;
    s3 = 0;
    if (gPlayerActor != NULL && M2C_FIELD(gPlayerActor, void **, 0x70) != NULL) {
        for (i = 0; i < 1U; i++) {
            a0 = M2C_FIELD(M2C_FIELD(gPlayerActor, void **, 0x70), u32 *, 0x30);
            if ((((a0 >> 4) & 0xFFFF) == ((s32 *)&D_800C4470)[i]) && ((a0 >> 0x14) == ((s32 *)&D_800C4474)[i]) && (M2C_FIELD(gPlayerActor, u16 *, 0x78) == 0x12) && (M2C_FIELD(gPlayerActor, s16 *, 0x7C) == 0)) {
                M2C_FIELD(gPlayerActor, s16 *, 0x7C) = 1;
                M2C_FIELD(gPlayerActor, s32 *, 0x60) |= 0x08000000;
                requestSound(0x1D2, gPlayerActor);
                s3 = 1;
                func_8007092C(sBonusObjectTable, 1);
            }
        }
        v0 = s3;
    } else v0 = s3;
    if (v0 == 0) func_8005B5A8();
}
