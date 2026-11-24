/* Copies count raw characters into the output buffer and returns the advanced write pointer. */ char *printfWriteChars(char *out, const void *chars, unsigned int count) {
    memcpy(out, chars, count);
    return out + count;
}
