/* identical to osCreateMesgQueue in PENNY RACERS (local match library) (matched), with its names changed by decompdecomp */
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

extern M2C_UNK gEmptyThreadQueue;

/* Initialises an OS message queue: empty wait queues, no pending messages, given buffer and capacity. */ void osCreateMesgQueue(void *mq, s32 msgBuf, s32 msgCount) {
    M2C_FIELD(mq, M2C_UNK **, 0) = &gEmptyThreadQueue;
    M2C_FIELD(mq, M2C_UNK **, 4) = &gEmptyThreadQueue;
    M2C_FIELD(mq, s32 *, 8) = 0;
    M2C_FIELD(mq, s32 *, 0xC) = 0;
    M2C_FIELD(mq, s32 *, 0x10) = msgCount;
    M2C_FIELD(mq, s32 *, 0x14) = msgBuf;
}
