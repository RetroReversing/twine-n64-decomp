/* Parses the EDL header at edlData and returns its first header word, or 0 on error. */
s32 getEdlFirstWord(s32 edlData) {
    union {
        unsigned char bytes[32];
        struct { s32 value; } base;
        struct { unsigned char pad[4]; s32 value; } header;
        struct { unsigned char pad[8]; s32 value; } firstWord;
        struct { unsigned char pad[20]; s32 value; } reserved;
        struct { unsigned char pad[28]; s32 value; } error;
    } reader;
    s32 result;

    reader.header.value = edlData;
    reader.reserved.value = 1;
    parse_edl_header(&reader.base.value);

    if (reader.error.value != 0) { result = 0; } else {
        result = reader.firstWord.value;
    }
    return result;
}
