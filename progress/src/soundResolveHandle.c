typedef struct VoiceEntry VoiceEntry;
struct VoiceEntry {
    VoiceEntry *next;
    u32 unknown;
    u32 key;
    s32 value;
};
extern VoiceEntry *gVoiceListHead;

/* Looks up a handle key in the sorted voice list and returns its value, or -1 if absent. */
s32 soundResolveHandle(u32 key) {
    VoiceEntry *entry;
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
            result = ((VoiceEntry *)result)->value;
        } else {
            result = -1;
        }
        return result;
    }
    return -1;
}
