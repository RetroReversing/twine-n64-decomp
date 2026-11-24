extern u8 sDataBankInitialised, sDataBankFlags[];
extern char sDataBankSlots[];
static __inline__ s32 lookup_8845C(s32 key) {
    u32 i = 0;
    s32 offset = 0;
    do {
        if (sDataBankFlags[offset] && *(s32 *)(sDataBankSlots + offset) == key) return i;
        offset += 0x1228;
    } while (++i < 2);
    return -1;
}
s32 isSlotActiveById(s32 key) {
    s32 found;
    if (sDataBankInitialised) {
        found = lookup_8845C(key);
        if (found != -1) return sDataBankFlags[found * 0x1228] != 0;
    }
    return 0;
}

extern void formatTextEntry(void *, s32, ...);
extern void updateActiveMenuState(void);
extern char *lookupDataEntry(s32);
extern s16 D_80109B9C;
extern void *gSaveMenuState;
extern u8 D_8010A4FF;
extern char sStringFormat[];
void updateSaveMenuText(void) {
    s32 id;
    u8 flag;
    char *text;
    char *buffer;
    updateActiveMenuState();
    if (*((u8 *)gSaveMenuState + 0x2D)) {
        flag = D_8010A4FF;
        D_80109B9C = !flag;
        id = 0x1B3;
        if (flag) id = 0x1D;
        text = lookupDataEntry(id);
        buffer = *(char **)((u8 *)gSaveMenuState + 0x18);
        formatTextEntry(buffer + 0x28, (s32)sStringFormat, text);
    }
}

typedef struct {
    s32 f00, f04, f08, f0c, f10, f14, f18, f1c, f20;
    f32 f24, f28, f2c, f30, f34, f38;
    s32 f3c;
    u8 pad40[0x18];
    unsigned flags58_hi : 16;
    unsigned mode58 : 14;
    unsigned flags58_lo : 2;
    unsigned mode5c_hi : 9;
    unsigned mode5c_mid : 6;
    unsigned flags5c_lo : 17;
} InitRecord3C;
/* Zeroes the record's fields and float vectors, storing the given value in the field at 0x10. */ void initObjectMotionRecord(InitRecord3C *record, s32 param) {
    record->f00 = 0;
    record->f04 = 0;
    record->f08 = 0;
    record->f0c = 0;
    record->f20 = 0;
    record->f10 = param;
    record->f14 = 0;
    record->f1c = 0;
    record->f3c = 0;
    record->f24 = record->f28 = record->f2c = 0.0f;
    record->f30 = record->f34 = record->f38 = 0.0f;
    record->mode58 = 0;
    record->mode5c_hi = 0;
    record->mode5c_mid = 0;
}

typedef struct { s8 *start; s16 length; } LineSpan308;
void getTextLineSpan(LineSpan308 *out, s8 *text, u16 limit) {
    u16 n = 0;
    s8 *end = text;
    s32 ch;
    if (text != 0) {
        do {
            ch = *text;
            if (!ch || n == limit) break;
            if (ch == '\n') n++;
            text++;
        } while (text != 0);
        end = text;
        if (text != 0) {
            do {
                ch = *end;
                if (!ch) break;
                if ((ch == '\n') | (ch == 0)) goto done;
                end++;
            } while (end != 0);
        }
    }
done:
    out->start = text;
    out->length = end - text;
}
