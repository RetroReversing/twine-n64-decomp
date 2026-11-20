extern s16 D_800DC710, D_800DC712;
extern s32 D_800DC718[6];

void func_80001A80(s32 value) {
    s32 index = D_800DC712;
    s32 start = index;
    u32 base = (u32)D_800DC718;
    u32 ptr = base + index * sizeof(s32);
    do {
        if (*(s32 *)ptr == value) {
            goto done;
        }
        --index;
        ptr -= sizeof(s32);
        if (index < 0) {
            ptr = base + 5 * sizeof(s32);
            index = 5;
        }
    } while (index != start);

    index = D_800DC710;
    --index;
    if (index < 0) {
        index = 5;
    }
    D_800DC710 = index;
    D_800DC718[index] = value;
done:
    D_800DC712 = index;
}
