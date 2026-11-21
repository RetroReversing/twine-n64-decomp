typedef struct Entry989 Entry989;
struct Entry989 {
    Entry989 *next;
    u32 unknown;
    u32 key;
    s32 value;
};
extern Entry989 *gVoiceListHead;

s32 soundResolveHandle(u32 key) {
    Entry989 *entry;
    u32 result;

    if (key != -1U) {
        entry = gVoiceListHead;
        result = 0;
        if (entry != 0) {
            for (;;) {
                result = entry->key;
                if (result == key) {
                    result = (u32)entry;
                } else {
                    result = key < result;
                    if (result != 0)
                        goto absent;
                    entry = entry->next;
                    if (entry != 0)
                        continue;
absent:
                    result = 0;
                }
                break;
            }
        }
        if (result != 0) {
            result = ((Entry989 *)result)->value;
        } else {
            result = -1;
        }
        return result;
    }
    return -1;
}
