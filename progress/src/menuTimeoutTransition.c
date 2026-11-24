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

s32 func_80026424();
s32 func_8002778C();
s32 func_8002B150();
s16 timerGetTotalSeconds();
s32 setStateMachineState();
extern char sMenuTimer[];
extern s32 sActiveMenu;

void menuTimeoutTransition(s32 arg0, void *arg1) {

    if (timerGetTotalSeconds(sMenuTimer) >= 0x14) {
        if (M2C_FIELD(arg1, s16 *, 0x7A) == 5) {
            setStateMachineState(arg1, 0xB);
        } else {
            func_80026424(sActiveMenu, 0xD);
            func_8002778C();
            setStateMachineState(arg1, 7);
        }
        func_8002B150(sMenuTimer, 0, 0);
    }
}
