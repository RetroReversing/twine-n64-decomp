typedef struct Node { struct Node *next, *prev; char pad[24]; struct Node *owner; } Node;
/* Links node into the list right after anchor and records anchor as its owner. */ void insertNodeAfter(Node *anchor, Node *node) {
 if (anchor->next) anchor->next->prev = node;
 node->next = anchor->next;
 node->prev = anchor;
 anchor->next = node;
 anchor->prev = 0;
 node->owner = anchor;
}
