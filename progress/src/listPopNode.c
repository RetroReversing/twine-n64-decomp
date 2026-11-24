typedef struct ListNode ListNode;
struct ListNode {
    u8 pad0[0x10];
    ListNode *next;
    ListNode *prev;
    void *owner;
};

/* Unlinks and returns the first node after head (0 if empty), clearing its links. */
ListNode *listPopNode(ListNode *head) {
    ListNode *first = head->next;
    if (first != 0) {
        ListNode *second = first->next;
        if ((head->next = second) != 0) {
            second->prev = head;
        }
        first->next = 0;
        first->prev = 0;
        first->owner = 0;
    }
    return first;
}
