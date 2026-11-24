s32 memset();
extern u8 sCharMap[];

/* Encodes a space-padded name string into character-map indices, trimming trailing spaces; unknown characters become 0. */ void saveDataEncodeName(s8 *encoded, s8 *text, s32 maxLen) {
    s32 length = maxLen;
    s32 count;
    s8 *dst;
    s8 *src;
    s32 end;
    u32 charIndex;

    memset(encoded, 0, (u8)length);
    while ((u8)length != 0 && text[(u8)length - 1] == ' ') {
        length--;
    }
    count = (u8)length;
    dst = encoded;
    if (count != 0) {
        src = text;
        end = count + (s32)dst;
        do {
            for (charIndex = 0; charIndex < 0x42; charIndex++) {
                if (sCharMap[charIndex] == *src) break;
            }
            charIndex &= -(charIndex < 0x42);
            *dst = charIndex;
            dst++;
            src++;
        } while ((s32)dst < end);
    }
}
