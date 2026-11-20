typedef struct Node8009450C {
    struct Node8009450C *next;
    struct Node8009450C *prev;
    s32 unk8;
    char pad[0x34 - 0xC];
    s32 unk34;
} Node8009450C;
extern Node8009450C *gSlotListHead;
extern u8 D_800CF540;
void func_8008C0D4(void);
void func_8008C11C(void);
void func_8008EA58(s32);

void func_8009450C(void) {
    Node8009450C *n = gSlotListHead;
    Node8009450C *next;
    while (n != NULL) {
        next = n->next;
        if (D_800CF540 != 0) {
            func_8008C0D4();
            if (n->next != NULL) {
                n->next->prev = n->prev;
            }
            if (n->prev != NULL) {
                n->prev->next = n->next;
            } else {
                gSlotListHead = n->next;
            }
            n->unk8 = *(u16 *)((u8 *)n + 0xA);
            if (n->unk34 != -1) {
                func_8008EA58(n->unk34);
            }
            func_8008C11C();
        }
        n = next;
    }
}
