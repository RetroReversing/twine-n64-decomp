typedef struct { unsigned char bytes[134]; } AudioRecord;
extern AudioRecord D_800EE420[][16];
extern AudioRecord D_800F2720[];
s32 func_800968A4();
s32 func_8009692C();
void func_80095EC4(s32 arg0, s32 arg1) {
    s32 bank;
    s32 slot;
    unsigned char *p;
    unsigned char *end;
    bank = arg1 & 255;
    if (bank != 255) {
        unsigned char *base = (unsigned char *) D_800EE420;
        unsigned char *row = bank * 2144 + base;
        s32 index = arg0 & 255;
        s32 offset = index * 134;
        offset += (s32) row;
        p = (unsigned char *) offset;
        end = p + 134;
        do { *p++ = 0; } while (p < end);
    } else {
        s32 index = arg0 & 255;
        unsigned char *base = (unsigned char *) D_800F2720;
        p = index * 134 + base;
        end = p + 134;
        do { *p++ = 0; } while (p < end);
    }
    bank = arg1 & 255;
    if (bank != 255) {
        unsigned char *base = (unsigned char *) D_800EE420;
        unsigned char *row = bank * 2144 + base;
        s32 index = arg0 & 255;
        s32 offset = index * 134;
        offset = offset + (s32) row;
        ((unsigned char *) offset)[7] = 127;
    } else {
        D_800F2720[arg0 & 255].bytes[7] = 127;
    }
    bank = arg1 & 255;
    if (bank != 255) {
        unsigned char *base = (unsigned char *) D_800EE420;
        unsigned char *row = bank * 2144 + base;
        s32 index = arg0 & 255;
        s32 offset = index * 134;
        offset = offset + (s32) row;
        ((unsigned char *) offset)[10] = 64;
    } else {
        D_800F2720[arg0 & 255].bytes[10] = 64;
    }
    bank = arg1 & 255;
    if (bank != 255) {
        unsigned char *base = (unsigned char *) D_800EE420;
        unsigned char *row = bank * 2144 + base;
        s32 index = arg0 & 255;
        s32 offset = index * 134;
        offset = offset + (s32) row;
        ((unsigned char *) offset)[128] = 64;
    } else {
        D_800F2720[arg0 & 255].bytes[128] = 64;
    }
    bank = arg1 & 255;
    if (bank != 255) {
        unsigned char *base = (unsigned char *) D_800EE420;
        unsigned char *row = bank * 2144 + base;
        s32 index = arg0 & 255;
        s32 offset = index * 134;
        offset = offset + (s32) row;
        ((unsigned char *) offset)[129] = 0;
    } else {
        D_800F2720[arg0 & 255].bytes[129] = 0;
    }
    bank = arg1 & 255;
    if (bank != 255) {
        unsigned char *base = (unsigned char *) D_800EE420;
        unsigned char *row = bank * 2144 + base;
        s32 index = arg0 & 255;
        s32 offset = index * 134;
        offset = offset + (s32) row;
        ((unsigned char *) offset)[64] = 0;
    } else {
        D_800F2720[arg0 & 255].bytes[64] = 0;
    }
    bank = arg1 & 255;
    if (bank != 255) {
        unsigned char *base = (unsigned char *) D_800EE420;
        unsigned char *row = bank * 2144 + base;
        s32 index = arg0 & 255;
        s32 offset = index * 134;
        offset = offset + (s32) row;
        ((unsigned char *) offset)[65] = 0;
    } else {
        D_800F2720[arg0 & 255].bytes[65] = 0;
    }
    bank = arg1 & 255;
    if (bank != 255) {
        unsigned char *base = (unsigned char *) D_800EE420;
        unsigned char *row = bank * 2144 + base;
        s32 index = arg0 & 255;
        s32 offset = index * 134;
        offset = offset + (s32) row;
        ((unsigned char *) offset)[91] = 0;
    } else {
        D_800F2720[arg0 & 255].bytes[91] = 0;
    }
    bank = arg1 & 255;
    if (bank != 255) {
        unsigned char *base = (unsigned char *) D_800EE420;
        unsigned char *row = bank * 2144 + base;
        s32 index = arg0 & 255;
        s32 offset = index * 134;
        offset = offset + (s32) row;
        ((unsigned char *) offset)[131] = 0;
    } else {
        D_800F2720[arg0 & 255].bytes[131] = 0;
    }
    bank = arg1 & 255;
    if (bank != 255) {
        unsigned char *base = (unsigned char *) D_800EE420;
        unsigned char *row = bank * 2144 + base;
        s32 index = arg0 & 255;
        s32 offset = index * 134;
        offset = offset + (s32) row;
        ((unsigned char *) offset)[132] = 64;
    } else {
        D_800F2720[arg0 & 255].bytes[132] = 64;
    }
    bank = arg1 & 255;
    if (bank != 255) {
        unsigned char *base = (unsigned char *) D_800EE420;
        unsigned char *row = bank * 2144 + base;
        s32 index = arg0 & 255;
        s32 offset = index * 134;
        offset = offset + (s32) row;
        ((unsigned char *) offset)[133] = 0;
    } else {
        D_800F2720[arg0 & 255].bytes[133] = 0;
    }
    {
        s32 finalSlot = arg0 & 255;
        s32 finalBank = arg1 & 255;
        func_800968A4(finalSlot, finalBank, 255);
        func_8009692C(finalSlot, finalBank, 0);
    }
}
