char *func_80087100(s32);
void *memset(void *, s32, s32);
s32 sprintf(char *, const char *, ...);
extern u8 D_800B2750[];

void func_800103B0(u8 *dst, s8 *src, u8 len) {
    s32 i;

    memset(dst, 0, len);
    for (i = 0; i < len; i++) {
        if (len == 4 && src[i] == 0) {
            break;
        }
        if ((u8)src[i] >= 0x42) {
            sprintf(dst, func_80087100(0x3003));
            return;
        }
    }
    for (i = 0; i < len; i++) {
        if (src[i] == 0) {
            dst[i] = ' ';
        } else if ((u32)src[i] < 0x42) {
            dst[i] = D_800B2750[(u16)src[i]];
        }
    }
}
