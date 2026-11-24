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

/* Unlinks a node from a doubly linked list (offset 0 = next, offset 4 = pointer to previous link) and clears its links. */ void unlinkListNode(void *node) {
    void **prevLink;
    void *next;

    prevLink = M2C_FIELD(node, void ***, 4);
    next = M2C_FIELD(node, void **, 0);
    M2C_FIELD(node, void ***, 4) = NULL;
    M2C_FIELD(node, void **, 0) = NULL;
    if (prevLink != NULL) {
        *prevLink = next;
    }
    if (next != NULL) {
        M2C_FIELD(next, void ***, 4) = prevLink;
    }
}
