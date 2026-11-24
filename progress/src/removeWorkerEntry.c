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

s32 workerLockAcquire();
s32 workerLockRelease();
extern char D_800FD55C[];
extern s32 sWorkerEntryCount;
extern char sWorkerEntryIds[];

typedef struct { s32 w[2]; } __repair_words2;
/* Removes the entry with the given id from the 8-byte-entry worker table, shifting later entries down. Returns 1 if found, else 0. */ s32 removeWorkerEntry(s32 entryId) {
    volatile u64 unused;
    s32 nextOffset;
    s32 count;
    s32 id;
    s32 next;
    s32 index;
    s32 var_v0;
    s32 byteOffset;
    void *src;
    void *dst;

    count = sWorkerEntryCount;
    id = entryId;
    index = 0;
    if (count > 0) {
        id &= 0xFFFF;
        byteOffset = 0;
        for (;;) {
            if (*(u16 *)(sWorkerEntryIds + byteOffset) != id) {
                index += 1;
                byteOffset += 8;
                if (index < count) {
                    continue;
                }
            }
            break;
        }
    }
    if (index != sWorkerEntryCount) {
        workerLockAcquire();
        next = index + 1;
        nextOffset = next * 8;
        if (next < sWorkerEntryCount) {
            dst = nextOffset + D_800FD55C;
            src = nextOffset + (D_800FD55C + 8);
            do {
                M2C_FIELD(dst, __repair_words2 *, 0x0) = *(__repair_words2 *) ((s8 *) src + 0x0);
                dst += 8;
                next += 1;
                src += 8;
            } while (next < sWorkerEntryCount);
        }
        sWorkerEntryCount -= 1;
        workerLockRelease();
        return 1;
    }
    return 0;
}
