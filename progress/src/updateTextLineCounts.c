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

s8 *lookupDataEntry(u16);
extern u16 gMaxTextLineCount;
extern void *gTextRefTable;

/* For each of the three text refs in gTextRefTable (offsets 8, 0xC, 0x10), counts the newline (0xA) characters in the looked-up string, stores the count at +2 of the ref and raises gMaxTextLineCount when it is larger. */
void updateTextLineCounts(void) {
    s8 *cursor;
    s8 *cursor2;
    s8 *cursor3;
    s8 ch;
    s8 ch2;
    s8 ch3;
    u16 *ref;
    u16 *ref2;
    u16 *ref3;
    u16 lineCount;

    ref = M2C_FIELD(gTextRefTable, u16 **, 8);
    lineCount = 0;
    if (ref != NULL) {
        cursor = lookupDataEntry(*ref);
        lineCount = cursor != NULL;
        if (cursor != NULL) {
            for (;;) {
                ch = *cursor;
                if (ch != 0) {
                    if (ch == 0xA) {
                        lineCount += 1;
                    }
                    cursor += 1;
                    if (cursor != NULL) {
                        continue;
                    }
                }
                break;
            }
        }
        M2C_FIELD(M2C_FIELD(gTextRefTable, u16 **, 8), u16 *, 2) = lineCount;
    }
    if ((u16) gMaxTextLineCount < (u32) (lineCount & 0xFFFF)) {
        gMaxTextLineCount = lineCount;
    }
    ref2 = M2C_FIELD(gTextRefTable, u16 **, 0xC);
    if (ref2 != NULL) {
        cursor2 = lookupDataEntry(*ref2);
        lineCount = cursor2 != NULL;
        if (cursor2 != NULL) {
            for (;;) {
                ch2 = *cursor2;
                if (ch2 != 0) {
                    if (ch2 == 0xA) {
                        lineCount += 1;
                    }
                    cursor2 += 1;
                    if (cursor2 != NULL) {
                        continue;
                    }
                }
                break;
            }
        }
        M2C_FIELD(M2C_FIELD(gTextRefTable, u16 **, 0xC), u16 *, 2) = lineCount;
    }
    if ((u16) gMaxTextLineCount < (u32) (lineCount & 0xFFFF)) {
        gMaxTextLineCount = lineCount;
    }
    ref3 = M2C_FIELD(gTextRefTable, u16 **, 0x10);
    if (ref3 != NULL) {
        cursor3 = lookupDataEntry(*ref3);
        lineCount = cursor3 != NULL;
        if (cursor3 != NULL) {
            for (;;) {
                ch3 = *cursor3;
                if (ch3 != 0) {
                    if (ch3 == 0xA) {
                        lineCount += 1;
                    }
                    cursor3 += 1;
                    if (cursor3 != NULL) {
                        continue;
                    }
                }
                break;
            }
        }
        M2C_FIELD(M2C_FIELD(gTextRefTable, u16 **, 0x10), u16 *, 2) = lineCount;
    }
    if ((u16) gMaxTextLineCount < (u32) (lineCount & 0xFFFF)) {
        gMaxTextLineCount = lineCount;
    }
}
