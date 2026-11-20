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

s32 func_80011938();
s32 func_800269B4();
s32 func_80027D60();
extern void *sActiveMenu;
extern void *gMenuState;

void func_80027E00(void) {
    void *temp_a2;

    func_800269B4(gMenuState + 0x1C, 3, 0x2A);
    temp_a2 = M2C_FIELD(gMenuState, void **, 0x1C);
    M2C_FIELD(temp_a2, s32 *, 0x10) &= ~0xFF;
    func_80011938(0, 1, temp_a2);
    func_80011938(1, 1);
    func_80011938(2, 1);
    func_80011938(3, 1);
    func_80027D60(M2C_FIELD(sActiveMenu, u16 *, 0x7A));
}
