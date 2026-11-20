typedef struct { unsigned char bytes[134]; } AudioRecord;
extern AudioRecord D_800EE420[][16];
extern AudioRecord D_800F2720[];
s32 func_800968A4();
s32 func_8009692C();
/* Resets one audio slot's 134-byte record in the given bank (255 = fallback table), sets its default fields, and updates the slot lookup maps. */
void audio_slot_reset(s32 slot, s32 bankId) {
    s32 bank;
    s32 slotIdx;
    unsigned char *cursor;
    unsigned char *cursorEnd;
    bank = bankId & 255;
    if (bank != 255) {
        unsigned char *tableBase = (unsigned char *) D_800EE420;
        unsigned char *bankBase = bank * 2144 + tableBase;
        s32 index = slot & 255;
        s32 offset = index * 134;
        offset += (s32) bankBase;
        cursor = (unsigned char *) offset;
        cursorEnd = cursor + 134;
        do { *cursor++ = 0; } while (cursor < cursorEnd);
    } else {
        s32 index = slot & 255;
        unsigned char *tableBase = (unsigned char *) D_800F2720;
        cursor = index * 134 + tableBase;
        cursorEnd = cursor + 134;
        do { *cursor++ = 0; } while (cursor < cursorEnd);
    }
    bank = bankId & 255;
    if (bank != 255) {
        unsigned char *tableBase = (unsigned char *) D_800EE420;
        unsigned char *bankBase = bank * 2144 + tableBase;
        s32 index = slot & 255;
        s32 offset = index * 134;
        offset = offset + (s32) bankBase;
        ((unsigned char *) offset)[7] = 127;
    } else {
        D_800F2720[slot & 255].bytes[7] = 127;
    }
    bank = bankId & 255;
    if (bank != 255) {
        unsigned char *tableBase = (unsigned char *) D_800EE420;
        unsigned char *bankBase = bank * 2144 + tableBase;
        s32 index = slot & 255;
        s32 offset = index * 134;
        offset = offset + (s32) bankBase;
        ((unsigned char *) offset)[10] = 64;
    } else {
        D_800F2720[slot & 255].bytes[10] = 64;
    }
    bank = bankId & 255;
    if (bank != 255) {
        unsigned char *tableBase = (unsigned char *) D_800EE420;
        unsigned char *bankBase = bank * 2144 + tableBase;
        s32 index = slot & 255;
        s32 offset = index * 134;
        offset = offset + (s32) bankBase;
        ((unsigned char *) offset)[128] = 64;
    } else {
        D_800F2720[slot & 255].bytes[128] = 64;
    }
    bank = bankId & 255;
    if (bank != 255) {
        unsigned char *tableBase = (unsigned char *) D_800EE420;
        unsigned char *bankBase = bank * 2144 + tableBase;
        s32 index = slot & 255;
        s32 offset = index * 134;
        offset = offset + (s32) bankBase;
        ((unsigned char *) offset)[129] = 0;
    } else {
        D_800F2720[slot & 255].bytes[129] = 0;
    }
    bank = bankId & 255;
    if (bank != 255) {
        unsigned char *tableBase = (unsigned char *) D_800EE420;
        unsigned char *bankBase = bank * 2144 + tableBase;
        s32 index = slot & 255;
        s32 offset = index * 134;
        offset = offset + (s32) bankBase;
        ((unsigned char *) offset)[64] = 0;
    } else {
        D_800F2720[slot & 255].bytes[64] = 0;
    }
    bank = bankId & 255;
    if (bank != 255) {
        unsigned char *tableBase = (unsigned char *) D_800EE420;
        unsigned char *bankBase = bank * 2144 + tableBase;
        s32 index = slot & 255;
        s32 offset = index * 134;
        offset = offset + (s32) bankBase;
        ((unsigned char *) offset)[65] = 0;
    } else {
        D_800F2720[slot & 255].bytes[65] = 0;
    }
    bank = bankId & 255;
    if (bank != 255) {
        unsigned char *tableBase = (unsigned char *) D_800EE420;
        unsigned char *bankBase = bank * 2144 + tableBase;
        s32 index = slot & 255;
        s32 offset = index * 134;
        offset = offset + (s32) bankBase;
        ((unsigned char *) offset)[91] = 0;
    } else {
        D_800F2720[slot & 255].bytes[91] = 0;
    }
    bank = bankId & 255;
    if (bank != 255) {
        unsigned char *tableBase = (unsigned char *) D_800EE420;
        unsigned char *bankBase = bank * 2144 + tableBase;
        s32 index = slot & 255;
        s32 offset = index * 134;
        offset = offset + (s32) bankBase;
        ((unsigned char *) offset)[131] = 0;
    } else {
        D_800F2720[slot & 255].bytes[131] = 0;
    }
    bank = bankId & 255;
    if (bank != 255) {
        unsigned char *tableBase = (unsigned char *) D_800EE420;
        unsigned char *bankBase = bank * 2144 + tableBase;
        s32 index = slot & 255;
        s32 offset = index * 134;
        offset = offset + (s32) bankBase;
        ((unsigned char *) offset)[132] = 64;
    } else {
        D_800F2720[slot & 255].bytes[132] = 64;
    }
    bank = bankId & 255;
    if (bank != 255) {
        unsigned char *tableBase = (unsigned char *) D_800EE420;
        unsigned char *bankBase = bank * 2144 + tableBase;
        s32 index = slot & 255;
        s32 offset = index * 134;
        offset = offset + (s32) bankBase;
        ((unsigned char *) offset)[133] = 0;
    } else {
        D_800F2720[slot & 255].bytes[133] = 0;
    }
    {
        s32 slotArg = slot & 255;
        s32 bankArg = bankId & 255;
        func_800968A4(slotArg, bankArg, 255);
        func_8009692C(slotArg, bankArg, 0);
    }
}
