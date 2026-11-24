typedef struct Node8009450C {
    struct Node8009450C *next;
    struct Node8009450C *prev;
    s32 unk8;
    char pad[0x34 - 0xC];
    s32 unk34;
} Node8009450C;
extern Node8009450C *gActiveEmitterList;
extern u8 gWorkerThreadActive;
void workerLockAcquire(void);
void workerLockRelease(void);
void func_8008EA58(s32);

void unlinkActiveEmitters(void) {
    Node8009450C *n = gActiveEmitterList;
    Node8009450C *next;
    while (n != NULL) {
        next = n->next;
        if (gWorkerThreadActive != 0) {
            workerLockAcquire();
            if (n->next != NULL) {
                n->next->prev = n->prev;
            }
            if (n->prev != NULL) {
                n->prev->next = n->next;
            } else {
                gActiveEmitterList = n->next;
            }
            n->unk8 = *(u16 *)((u8 *)n + 0xA);
            if (n->unk34 != -1) {
                func_8008EA58(n->unk34);
            }
            workerLockRelease();
        }
        n = next;
    }
}
