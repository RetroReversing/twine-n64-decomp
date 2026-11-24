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

s32 __osMotorAccess();
extern char gRumblePaks[];
extern char gRumbleFlags[];

/* Turns the rumble motor off (3 attempts) for the given controller and clears its rumble-active flag. */ void stopControllerRumble(u16 controllerIndex) {
    char *slotTable;
    s32 pfsOffset;
    s32 motorTry;
    u16 *flagsPtr;
    void *var_a0;

    motorTry = 0;
    pfsOffset = controllerIndex * 0x68;
    slotTable = gRumblePaks;
    do {
        __osMotorAccess((void *) ((pfsOffset) + (s32) slotTable), 0);
        motorTry += 1;
    } while (motorTry < 3);
    {
        s32 index = controllerIndex;
        char *base = gRumbleFlags;
        flagsPtr = (u16 *)(base + index * 2);
    }
    *flagsPtr &= 0xFFFE;
}
