typedef struct Node { struct Node *a; struct Node *b; s32 size; } Node;
extern s32 D_800CE354;
extern s8 D_800E1A90;
extern s32 D_800E1A9C;
extern s32 D_800E1AA0;
extern Node *D_800E1AAC;
extern Node *D_800E1AB0;
void func_80083DBC(Node *);

void func_80084048(void *arg0, s32 arg1) {
    Node *n;
    Node *prev;
    Node *next;
    Node *cur;
    Node *nxt;
    Node *p;

    if (D_800E1A90 != 0) {
        if (arg0 != NULL) {
            *(&D_800CE354 + arg1 * 3) -= n->size;
            n = (Node *)((char *)arg0 - 12);
            D_800E1A9C += n->size;
            D_800E1AA0 -= n->size;
            prev = n->b;
            next = n->a;
            if (prev != NULL) {
                prev->a = next;
            }
            if (next != NULL) {
                next->b = prev;
            }
            if (n == D_800E1AB0) {
                D_800E1AB0 = prev;
            }
            n->a = NULL;
            n->b = NULL;
            cur = D_800E1AAC;
            if (cur != NULL) {
                for (;;) {
                    nxt = cur->b;
                    if (nxt == NULL) {
                        if (cur < n) {
                            cur->b = n;
                            n->b = NULL;
                            n->a = cur;
                        } else {
                            p = cur->a;
                            if (p != NULL) {
                                p->b = n;
                            }
                            cur->a = n;
                            n->b = cur;
                            n->a = p;
                        }
                        break;
                    }
                    if (!((cur < n) & (n < nxt))) {
                        cur = nxt;
                        continue;
                    }
                    cur->b = n;
                    n->a = cur;
                    nxt->a = n;
                    n->b = nxt;
                    break;
                }
            }
            func_80083DBC(cur);
        }
    }
}
