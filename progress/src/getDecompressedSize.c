s32 parse_edl_header(s32 *);

/* Parses an EDL header and returns the decompressed size, or 0 if parsing flagged an error. */
s32 getDecompressedSize(s32 compressedData) {
    union {
        unsigned char bytes[32];
        struct { s32 value; } view_sp10;
        struct { unsigned char pad[4]; s32 value; } view_sp14;
        struct { unsigned char pad[12]; s32 value; } view_sp1C;
        struct { unsigned char pad[20]; s32 value; } view_sp24;
        struct { unsigned char pad[28]; s32 value; } view_sp2C;
    } header;
    s32 size;

    header.view_sp14.value = compressedData;
    header.view_sp24.value = 1;
    parse_edl_header(&header.view_sp10.value);
    
    if (header.view_sp2C.value != 0) { size=0; } else {
        size = header.view_sp1C.value;
    }
    return size;
}
