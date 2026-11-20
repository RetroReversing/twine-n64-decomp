typedef struct Node { char pad[16]; struct Node *next, *prev; } Node;
void func_80016948(Node *a, Node *b) {
 Node *p;
 if (a) {
  p=a;
  while ((a=p->next)) p=a;
  p->next=b; b->prev=p; b->next=0;
 }
}
