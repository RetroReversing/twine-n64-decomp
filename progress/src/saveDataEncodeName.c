s32 memset();
extern u8 D_800B2750[];

void saveDataEncodeName(s8 *arg0, s8 *arg1, s32 arg2) {
    s32 len = arg2;
    s32 n;
    s8 *dst;
    s8 *src;
    s32 end;
    u32 i;

    memset(arg0, 0, (u8)len);
    while ((u8)len != 0 && arg1[(u8)len - 1] == ' ') {
        len--;
    }
    n = (u8)len;
    dst = arg0;
    if (n != 0) {
        src = arg1;
        end = n + (s32)dst;
        do {
            for (i = 0; i < 0x42; i++) {
                if (D_800B2750[i] == *src) break;
            }
            i &= -(i < 0x42);
            *dst = i;
            dst++;
            src++;
        } while ((s32)dst < end);
    }
}
