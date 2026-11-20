/* adapted from similar verified C in func_800263B8 in TWINE (matched), with its names changed by decompdecomp */
typedef struct { u16 id; u8 pad[0x26]; } Ent263B8;
typedef struct { Ent263B8 *arr; u8 pad4; u8 count; } Tbl263B8;

s32 func_800262A8(Tbl263B8 *arg0, u16 arg1) {
    u16 i;

    if (arg0 == NULL) {
        return 0;
    }
    for (i = 0; i < arg0->count; i++) {
        if (arg0->arr[i].id == arg1) {
            return i;
        }
    }
    return 0;
}
