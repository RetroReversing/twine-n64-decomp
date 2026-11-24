/* identical to ctype_toupper in V-RALLY-PAL (local match library) (matched), with its names changed by decompdecomp */
extern char gCharClassTable[];

s32 ctypeToUpper(s32 c) {
    s32 ch;

    ch = c;
    if (*(gCharClassTable + (ch & 0xFF)) & 4) {
        ch -= 0x20;
    }
    return ch;
}
