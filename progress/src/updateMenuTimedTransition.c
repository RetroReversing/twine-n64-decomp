/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2 -fno-schedule-insns, tried by autopilot */
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

s32 menuNudgeItemValues();
s32 isMenuButtonPressed();
s32 func_80027D60();
extern u8 D_800BD694[];
extern void *sActiveMenu;

void updateMenuTimedTransition(void) {
    s16 temp_v0;

    menuNudgeItemValues(M2C_FIELD(sActiveMenu, s16 *, 0x7C));
    if ((*(D_800BD694 + (M2C_FIELD(sActiveMenu, s16 *, 0x7A) * 0x1C)) != 0) && ((isMenuButtonPressed(0x2A) & 0xFF) || (isMenuButtonPressed(0x23) & 0xFF))) {
        M2C_FIELD(sActiveMenu, s16 *, 0x7C) = 0;
    }
    temp_v0 = M2C_FIELD(sActiveMenu, s16 *, 0x7C);
    if (temp_v0 > 0) {
        M2C_FIELD(sActiveMenu, s16 *, 0x7C) = (s16) (temp_v0 - 1);
        return;
    }
    func_80027D60((u16) M2C_FIELD(sActiveMenu, s16 *, 0x7A));
}
