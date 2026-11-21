typedef struct Node { struct Node *prev, *next; } Node;
extern void func_800165E0(Node *, void *);
void unlinkNode(Node *a, Node *head, void *arg) {
    Node *p = head->next, *prev = p;
    while (p) {
        if (p == a) {
            if (prev != a) {
                prev->next = a->next;
                if (a->next) a->next->prev = prev;
            } else {
                head->next = a->next;
                if (a->next) a->next->prev = head;
            }
            break;
        }
        prev = p;
        p = p->next;
    }
    func_800165E0(a, arg);
}
