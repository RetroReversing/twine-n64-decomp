typedef struct {
    u8 flags;
    u8 pad01;
    u16 extent;
    u8 pad04;
    u8 count;
    u8 pad06[2];
    s32 value;
} Entry448;
typedef struct {
    u8 pad00[4];
    s32 value;
} Payload448;
typedef struct {
    u8 pad00[16];
    Payload448 *payloads;
    u8 pad14[4];
    Entry448 *entries;
} Bank448;
typedef struct {
    Bank448 *bank;
    u8 pad04[12];
} Slot448;
typedef struct {
    u8 pad00[8];
    s32 value;
    s32 payload;
    u8 pad10[20];
    u16 extent;
    u16 otherExtent;
    union {
        u8 counts[4];
        u32 word;
        struct {
            unsigned int : 30;
            unsigned int flags : 2;
        } bits;
    } state;
} Object448;
extern Slot448 D_800C0784[];
void initObjectFromBankEntry(Object448 *object, s32 index, s32 bankIndex) {
    Bank448 *bank;
    Entry448 *entry;
    Payload448 *payload;
    u8 count;
    u32 word;
    u16 extent;

    if (bankIndex < 0) return;
    bank = D_800C0784[bankIndex].bank;
    if (bank == NULL) return;
    payload = bank->payloads;
    entry = bank->entries;
    entry += index;
    object->value = entry->value;
    extent = entry->extent + 1;
    object->extent = extent;
    object->otherExtent = extent;
    count = entry->count;
    payload += index;
    count++;
    object->state.counts[0] = count;
    object->state.counts[1] = count;
    word = object->state.word;
    {
        u32 flags = entry->flags;
        object->state.word = (word & ~3U) | (flags & 3U);
    }
    object->payload = payload->value;
}
