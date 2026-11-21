typedef struct {
    u8 weight;
    u8 variant;
    u16 id;
} SelectionEntry;

s32 func_80002BD0(void *, s32);
u32 randomIntBelow(s32);
s32 func_8007ADD0(void *, s32);

s32 func_8007AEA4(void *actor, SelectionEntry *entries, s32 count) {
    u8 *details = *(u8 **)((u8 *)actor + 0x6C);
    volatile s32 pad;
    volatile s32 weight = entries[count - 1].weight;
    volatile s32 spare;
    u32 attempt = 0;
    u32 index, threshold, limit;
    u8 *entry;
    u16 id;

retry:
    index = 0;
    threshold = randomIntBelow(weight);
    limit = count - 1;
    if (!limit) {
        ++attempt;
        goto check_attempt;
    }
    entry = (u8 *)entries;
scan:
    if (entry[4] < threshold) {
        index++;
        goto advance;
    }
    id = *(u16 *)(entry + 2);
    if (id == 0)
        return 0;
    if (((u32)func_8007ADD0(actor, id) << 24) == 0) {
        index++;
        goto advance;
    }
    details[0x7F] = entry[1];
    func_80002BD0(actor, *(u16 *)(entry + 2));
    return 1;
advance:
    entry += 4;
    if (index < limit)
        goto scan;
    ++attempt;
check_attempt:
    if (attempt < 3)
        goto retry;
    return 0;
}
