typedef struct Node { struct Node *next, *prev; char pad[24]; struct Node *owner; } Node;
void func_8003E6C4(Node *a, Node *b) {
 if (a->next) a->next->prev = b;
 b->next = a->next;
 b->prev = a;
 a->next = b;
 a->prev = 0;
 b->owner = a;
}
