/* identical to printfWriteChars (matched), with its names changed by decompdecomp */
/* Copies n bytes from src to dst and returns the pointer just past the written bytes. */ char *sprintfWriteChars(char *dst, const void *src, unsigned int n) {
    memcpy(dst, src, n);
    return dst + n;
}
