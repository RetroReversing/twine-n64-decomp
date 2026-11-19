char *func_80025D50(char *dst, const void *src, unsigned int n) {
    memcpy(dst, src, n);
    return dst + n;
}
