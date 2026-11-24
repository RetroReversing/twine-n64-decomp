s32 decompressByMethod(s32 *);

/* Decompresses src into dst via decompressByMethod; returns 1 if the status word of the request block is zero. */
s32 decompressData(s32 src, s32 dst) {
    union {
        unsigned char bytes[32];
        struct { s32 value; } view_sp10;
        struct { unsigned char pad[4]; s32 value; } view_sp14;
        struct { unsigned char pad[20]; s32 value; } view_sp24;
        struct { unsigned char pad[28]; s32 value; } view_sp2C;
    } request;

    request.view_sp10.value = src;
    request.view_sp24.value = 1;
    request.view_sp14.value = dst;
    decompressByMethod(&request.view_sp10.value);
    return request.view_sp2C.value == 0;
}
