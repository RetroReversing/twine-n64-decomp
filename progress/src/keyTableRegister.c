typedef struct { u16 key; s16 state; u8 pad[0x18]; } N97814;
typedef struct { N97814 *list; s32 arg; u16 count; } Slot97814;
extern s32 sKeyTableCount;
extern Slot97814 sKeyTableSlots[];
void workerLockAcquire(void);
void workerLockRelease(void);
extern u8 D_800F38F4[];
extern u8 D_800F38F8[];

s32 keyTableRegister(N97814 *arg0, s32 arg1) {
    s32 i;
    u16 n;
    u16 j;
    N97814 *p;

    for (i = 0; i < sKeyTableCount; i++) {
        if (sKeyTableSlots[i].list == arg0) {
            break;
        }
    }
    if (i != sKeyTableCount) {
        return 1;
    }
    if (i < 8) {
    n = 0;
    for (p = arg0; p->key != 0xFFFF; p++) {
        n++;
    }
    workerLockAcquire();
    p = arg0;
    i = sKeyTableCount;
    *(N97814 **)((u8 *)sKeyTableSlots + i * 12) = p;
    *(u16 *)(D_800F38F8 + i * 12) = n;
    *(s32 *)(D_800F38F4 + i * 12) = arg1;
    i = n;
    for (j = 0; j < (u32)i; j++, p++) {
        p->state = 0;
    }
    sKeyTableCount++;
    workerLockRelease();
    return 1;
    }
    return 0;
}

