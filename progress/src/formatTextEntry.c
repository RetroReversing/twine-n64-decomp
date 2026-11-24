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

s32 _Printf();
s32 lookupDataEntry();
s16 strlen();
extern s32 printfWriteChars;

/* printf-formats into the entry's text buffer, NUL-terminates it, and updates the linked text box's cached length. */ void formatTextEntry(void *textEntry, s32 format, ...) {
    char *args;
    s32 length;
    void *textBox;

    if (textEntry != NULL) {
        args = (char *) __builtin_next_arg(format);
        length = _Printf(&printfWriteChars, lookupDataEntry(M2C_FIELD(textEntry, u16 *, 0), format), format, args);
        if (length >= 0) {
            *(s8 *)(lookupDataEntry(M2C_FIELD(textEntry, u16 *, 0)) + length) = 0;
        }
        textBox = M2C_FIELD(textEntry, void **, 8);
        if (textBox != NULL) {
            M2C_FIELD(textBox, s16 *, 0x1C) = strlen(M2C_FIELD(textBox, s32 *, 0x18));
        }
    }
}
