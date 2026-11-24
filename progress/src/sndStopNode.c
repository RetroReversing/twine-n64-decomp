s32 func_8008C5DC();
s32 func_8009876C();
s32 func_80098A18();
extern u8 D_800CF540;
extern void *D_800FDB74;
extern u8 D_801002EA;
extern u8 D_8010A930;
extern u8 D_8010D720;
extern char D_8010D724[];
extern char D_8010D734[];
extern char sSoundVoiceHandle[];
extern u8 D_80110DB0;
extern char sVoiceFreeList[];
extern char D_80117389[];

typedef struct Node { struct Node *next; s32 pad; u32 key; s32 head; } Node;
typedef struct { u8 a; u8 b; u16 c; } Rec;

/* Stops every voice in the chain for a sound handle: looks up the handle's head voice in the sorted list, then releases each voice whose handle matches, returning its channel to the free list. Returns 0 on success, -1 if the sound system is inactive. */ s32 sndStopNode(u32 handle) {
    s32 result = -1;
    s32 slotIndex;
    s32 slotOffset;
    s32 nextHandle;
    s32 channel;
    char *voice;
    Rec *channelRec;
    Node *node;
    u32 nodeKey;
    Node *foundNode;
    if (D_800CF540 != 0) {
        if (handle == -1U) {
            goto no_head;
        }
        {
            foundNode = NULL;
            node = D_800FDB74;
            if (node != NULL) {
                for (;;) {
                    nodeKey = node->key;
                    if (nodeKey == handle) {
                        foundNode = node;
                    } else {
                        if (handle >= nodeKey) {
                            node = node->next;
                            if (node != NULL) {
                                continue;
                            }
                        }
                        foundNode = NULL;
                    }
                    break;
                }
            }
        }
        if (foundNode != NULL) {
            slotOffset = foundNode->head;
        } else {
no_head:
            slotOffset = -1;
        }
        handle = slotOffset;
        while (handle != -1) {
            slotIndex = handle & 0xFF;
            slotOffset = slotIndex * 0x1A0;
            nextHandle = *(s32 *)(D_8010D734 + slotOffset);
            if (*(s32 *)(sSoundVoiceHandle + slotOffset) == handle) {
                if (*(s32 *)(D_8010D724 + slotOffset) != 0) {
                    voice = D_8010D724 + slotOffset;
                    func_8009876C(voice);
                    *(s32 *)(voice + 0x28) = 0;
                    *(s32 *)(voice + 0x24) &= ~3;
                    func_80098A18(voice);
                    channel = *(u8 *)(voice + 0x63);
                    *(s32 *)voice = 0;
                    *(s8 *)(voice + 0x2E) = 0;
                    channelRec = (Rec *)(sVoiceFreeList + channel * 4);
                    if (channelRec->c == 0) {
                        channelRec->c = 1;
                        if (D_801002EA != 0xFF) {
                            channelRec->b = 0xFF;
                            channelRec->a = D_80110DB0;
                            D_80117389[D_80110DB0 << 2] = channel;
                        } else {
                            channelRec->b = 0xFF;
                            channelRec->a = 0xFF;
                            D_801002EA = channel;
                        }
                        D_80110DB0 = channel;
                        if (*(u8 *)(voice + 0x4C) != 0) {
                            D_8010A930 -= 1;
                        } else {
                            D_8010D720 -= 1;
                        }
                    }
                    *(s32 *)(voice + 0x60) = -1;
                }
                func_8008C5DC(slotIndex);
                result = 0;
            }
            handle = nextHandle;
        }
    }
    return result;
}
