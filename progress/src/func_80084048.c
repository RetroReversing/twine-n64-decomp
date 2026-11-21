typedef struct Node { struct Node *a; struct Node *b; s32 size; } Node;
extern struct { s32 value; s32 pad[2]; } D_800CE354[];
extern s8 D_800E1A90;
extern s32 D_800E1A9C;
extern s32 D_800E1AA0;
extern Node *D_800E1AAC;
extern Node *D_800E1AB0;
void coalesce_adjacent_free_blocks();

void func_80084048(void *arg0, s32 arg1) {
    Node *n;
    Node *prev;
    Node *next;
    Node *cur;
    Node *nxt;
    Node *p;

    if (D_800E1A90 != 0) {
        if (arg0 != NULL) {
            n = (Node *)((char *)arg0 - 12);
            D_800CE354[arg1].value -= n->size;
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
                D_800E1AB0 = ((volatile Node *)n)->b;
            }
            n->a = NULL;
            n->b = NULL;
            cur = D_800E1AAC;
            if (cur != NULL) {
                do {
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
                    if ((u8)((cur < n) & (n < nxt)) == 0) {
                        cur = nxt;
                    } else {
                        cur->b = n;
                        n->a = cur;
                        nxt->a = n;
                        n->b = nxt;
                        break;
                    }
                } while (cur != NULL);
            }
            coalesce_adjacent_free_blocks(cur);
        }
    }
}
