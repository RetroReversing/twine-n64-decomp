typedef struct VoiceHandle {
    u8 slot;            /* 0: voice slot, 0xFF when none */
    u8 chain;           /* 1: next handle in the owner chain, 0xFF when none */
    u16 state;          /* 2: 1 while the handle is in use */
} VoiceHandle;

typedef struct VoiceLink {
    u16 prev;           /* 0 */
    u16 next;           /* 2 */
} VoiceLink;

typedef struct VoiceUser {
    u8 pad0[0x2E];
    u8 owner;           /* 0x2E */
    u8 pad1[0x63 - 0x2F];
    u8 handleIndex;     /* 0x63 */
} VoiceUser;

extern VoiceHandle sVoiceHandles[];
extern u8 sVoiceOwnerChains[];
extern VoiceLink sVoiceLinks[];
extern u16 sVoiceLinkHead;

/* Releases a voice's handle: unlinks it from its owner chain and from the voice link list, then marks it unused. */
void voiceReleaseHandles(VoiceUser *voice) {
    s32 linkNext;
    u16 linkPrev;
    u8 chainNext;
    u8 slot;
    VoiceHandle *handle;
    VoiceLink *ownerLink;

    handle = &sVoiceHandles[voice->handleIndex];
    if (handle->state == 1) {
        slot = handle->slot;
        if (slot != 0xFF) {
            sVoiceHandles[slot].chain = handle->chain;
        } else {
            sVoiceOwnerChains[voice->owner] = handle->chain;
        }
        chainNext = handle->chain;
        if (chainNext != 0xFF) {
            sVoiceHandles[chainNext].slot = handle->slot;
            handle->state = 0U;
            return;
        }
        if (handle->slot == chainNext) {
            ownerLink = &sVoiceLinks[voice->owner];
            linkNext = ownerLink->next;
            if (linkNext != 0xFFFF) {
                sVoiceLinks[linkNext].prev = ownerLink->prev;
            } else {
                sVoiceLinkHead = ownerLink->prev;
            }
            linkPrev = ownerLink->prev;
            if (linkPrev != 0xFFFF) {
                sVoiceLinks[linkPrev].next = ownerLink->next;
            }
        }
        handle->state = 0U;
    }
}
