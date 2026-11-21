char *lookupDataEntry(s32);
void *memset(void *, s32, s32);
s32 sprintf(char *, const char *, ...);
extern u8 sCharMap[];

/* Decodes a fixed-length packed text field into outText; invalid codes print an error string instead. */ void decodeTextField(u8 *outText, s8 *packedText, u8 length) {
    s32 index;

    memset(outText, 0, length);
    for (index = 0; index < length; index++) {
        if (length == 4 && packedText[index] == 0) {
            break;
        }
        if ((u8)packedText[index] >= 0x42) {
            sprintf(outText, lookupDataEntry(0x3003));
            return;
        }
    }
    for (index = 0; index < length; index++) {
        if (packedText[index] == 0) {
            outText[index] = ' ';
        } else if ((u32)packedText[index] < 0x42) {
            outText[index] = sCharMap[(u16)packedText[index]];
        }
    }
}
