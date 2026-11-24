/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

void dmaRomToRamUnaligned(u8 *, s32, u32);
u16 func_800870F4(void);
extern char D_148B400[];
extern s32 gCurrentTextId;
extern char sTextBankTables[];

/* Looks up textId in the text bank table for the current language, DMAs the string from ROM into dst and NUL-terminates it. */ void loadTextString(s8 *dst, s32 textId) {
    unsigned temp_v1;
    long bankOffset;
    char *entry;
    unsigned int bankIndex;
    u16 *table;
    register s8 *var_v0_3;
    s32 length;

    s32 id = textId;
    gCurrentTextId = id;
    temp_v1 = func_800870F4() & 0xFFFF;
    if (temp_v1 == 2) goto one;
    if (temp_v1 == 5) goto two;
    bankIndex = 0;
    goto scale;
one:
    bankIndex = 1;
    goto scale;
found:
    length = *(u16 *)(entry + 2);
    dmaRomToRamUnaligned(dst, (*(s32 *)(entry + 4)) + D_148B400, length);
    goto done;
two:
    bankIndex = 2;
scale:
    bankOffset = (s32)bankIndex * 4;
scan:
    table = *(s32 *)(sTextBankTables + bankOffset);
    length = 0;
    if (*table != 0xFFFF) {
        unsigned sentinel = 0xFFFF;
        entry = (char *)table;
        do {
            var_v0_3 = dst;
            if (*(u16 *)entry == textId) goto found;
            entry += 8;
        } while (*(u16 *)entry != sentinel);
    }
done:
    *(dst + length) = 0;
}
