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

s32 remapAnimIdForVariant();
s32 getMeshRootMotionDelta();
extern char sCommandSlotTable[];
extern char sCommandScriptTable[];
extern char sCommandSecondaryTable[];

/* Walks a 16-bit command stream, dispatching each opcode until a terminating command clears keepRunning. */ void runCommandStream(s32 arg0, s32 arg1, s32 arg2) {
    char *cmdPtr;
    s32 cmdWord;
    s32 keepRunning;
    u32 cmdOpcode;

    cmdPtr = *(s32 *)(sCommandScriptTable + (remapAnimIdForVariant(arg0, arg1) * 4));
    keepRunning = 1;
    do {
        cmdWord = *(s16 *)cmdPtr;
        cmdOpcode = cmdWord & 0x1F;
        cmdPtr += 2;
        switch (cmdOpcode) {
        case 0:
        case 1:
        case 2:
        case 3:
            cmdPtr = *(char **)(((cmdWord & 0x1F) * 4) + sCommandSlotTable);
            *(s16 *)cmdPtr = (*(s16 *)cmdPtr & 0x1F) + ((u16)cmdWord & 0xFFE0);
            break;
        case 27:
            cmdPtr = *(char **)((remapAnimIdForVariant(arg0, *(s16 *)cmdPtr) * 4) + sCommandScriptTable);
            break;
        case 28:
            cmdPtr = *(char **)((*(s16 *)cmdPtr * 4) + sCommandSecondaryTable);
            break;
        case 21:
        case 22:
        case 23:
            getMeshRootMotionDelta((u32) (cmdWord & 0xFFFF) >> 5, arg2);
            keepRunning = 0;
            break;
        case 11:
            cmdPtr += 4;
            break;
        case 10:
        case 12:
        case 13:
        case 14:
        case 15:
        case 16:
        case 17:
        case 18:
        case 19:
        case 20:
        case 24:
        case 25:
        case 26:
        case 29:
            cmdPtr += 2;
            break;
        }
    } while (keepRunning != 0);
}
