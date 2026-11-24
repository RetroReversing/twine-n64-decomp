extern u8 gCharClassTable[];

/* Returns the length of the leading run of whitespace plus the following word (including one trailing whitespace char), converting newlines in the leading whitespace to spaces. */ s32 textScanWordSpan(s8 *text) {
    s32 idx = 0;
    s32 length = 0;
    s8 ch;

    if (text[0] == 0) {
        return 0;
    }
    if (gCharClassTable[(u8)text[0]] & 1) {
        do {
            if (text[idx] == '\n') {
                text[idx] = ' ';
            }
            length++;
            idx++;
        } while (gCharClassTable[(u8)text[idx]] & 1);
    }
    if (text[idx] != 0 && !(gCharClassTable[(u8)text[idx++]] & 1)) {
        text = (s8 *)((u32)idx - (0U - (u32)text));
    loop:
        ch = *text;
        length++;
        if (ch != 0) {
            text++;
            if (!(gCharClassTable[(u8)ch] & 1)) {
                goto loop;
            }
        }
    }
    return length;
}
