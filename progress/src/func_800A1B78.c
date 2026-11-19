char *func_800A1B78(char *dst, const void *src, unsigned int n) {
    memcpy(dst, src, n);
    return dst + n;
}
