extern s16 *D_800AE724[];
extern s16 D_800C2B28;
extern s16 D_800C2B32;
extern s8 D_800D1E58[];

s32 func_80001F40(s16 id, s8 code, s32 *out) {
    s32 found = 0;
        s32 i = 0;
    s32 j = 0;

    while (D_800AE724[i] != 0) {
        s16 value = *D_800AE724[i];
        if (id == value) found = 1;
        while (D_800D1E58[j] >= 0) {
            if (id == value && code == D_800D1E58[j]) {
                if (id == D_800C2B32) {
                    if (code == 2) *out = 0;
                    if (code == 0x1E) *out = 1;
                }
                if (id != D_800C2B28) return 1;
                if (code == 2) *out = 0;
                if (code != 0x16) return 1;
                *out = 1;
                goto accepted;
            }
            j++;
        }
        j++;
        i++;
    }
    if (!found) {
        if (code < 0x25) {
            if (code == 2) *out = 0;
            if (code == 0x14) {
                *out = 1;
                goto accepted;
            }
            return 1;
        }
        goto rejected;
    }
    return 0;
accepted:
    return 1;
rejected:
    return 0;
}

