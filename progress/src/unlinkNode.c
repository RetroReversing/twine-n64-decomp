typedef struct Node { struct Node *prev, *next; } Node;
extern void linkNodeAfter(Node *, void *);
/* Unlinks node from the singly-walked list starting at head, then calls the follow-up handler on it. */ void unlinkNode(Node *node, Node *head, void *extra) {
    Node *cur = head->next, *prev = cur;
    while (cur) {
        if (cur == node) {
            if (prev != node) {
                prev->next = node->next;
                if (node->next) node->next->prev = prev;
            } else {
                head->next = node->next;
                if (node->next) node->next->prev = head;
            }
            break;
        }
        prev = cur;
        cur = cur->next;
    }
    linkNodeAfter(node, extra);
}
