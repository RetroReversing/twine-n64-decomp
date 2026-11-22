s32 func_8008C5DC();
s32 func_8009876C();
s32 func_80098A18();
extern u8 D_800CF540;
extern void *D_800FDB74;
extern u8 D_801002EA;
extern u8 D_8010A930;
extern u8 D_8010D720;
extern char D_8010D724[];
extern char D_8010D734[];
extern char D_8010D784[];
extern u8 D_80110DB0;
extern char D_80117388[];
extern char D_80117389[];

typedef struct Node { struct Node *next; s32 pad; u32 key; s32 head; } Node;
typedef struct { u8 a; u8 b; u16 c; } Rec;

s32 sndStopNode(u32 arg0) {
    s32 ret = -1;
    s32 temp_s1;
    s32 off;
    s32 nxt;
    s32 m;
    char *s0;
    Rec *r;
    Node *n;
    u32 k;
    Node *found;
    if (D_800CF540 != 0) {
        if (arg0 == -1U) {
            goto no_head;
        }
        {
            found = NULL;
            n = D_800FDB74;
            if (n != NULL) {
                for (;;) {
                    k = n->key;
                    if (k == arg0) {
                        found = n;
                    } else {
                        if (arg0 >= k) {
                            n = n->next;
                            if (n != NULL) {
                                continue;
                            }
                        }
                        found = NULL;
                    }
                    break;
                }
            }
        }
        if (found != NULL) {
            off = found->head;
        } else {
no_head:
            off = -1;
        }
        arg0 = off;
        while (arg0 != -1) {
            temp_s1 = arg0 & 0xFF;
            off = temp_s1 * 0x1A0;
            nxt = *(s32 *)(D_8010D734 + off);
            if (*(s32 *)(D_8010D784 + off) == arg0) {
                if (*(s32 *)(D_8010D724 + off) != 0) {
                    s0 = D_8010D724 + off;
                    func_8009876C(s0);
                    *(s32 *)(s0 + 0x28) = 0;
                    *(s32 *)(s0 + 0x24) &= ~3;
                    func_80098A18(s0);
                    m = *(u8 *)(s0 + 0x63);
                    *(s32 *)s0 = 0;
                    *(s8 *)(s0 + 0x2E) = 0;
                    r = (Rec *)(D_80117388 + m * 4);
                    if (r->c == 0) {
                        r->c = 1;
                        if (D_801002EA != 0xFF) {
                            r->b = 0xFF;
                            r->a = D_80110DB0;
                            D_80117389[D_80110DB0 << 2] = m;
                        } else {
                            r->b = 0xFF;
                            r->a = 0xFF;
                            D_801002EA = m;
                        }
                        D_80110DB0 = m;
                        if (*(u8 *)(s0 + 0x4C) != 0) {
                            D_8010A930 -= 1;
                        } else {
                            D_8010D720 -= 1;
                        }
                    }
                    *(s32 *)(s0 + 0x60) = -1;
                }
                func_8008C5DC(temp_s1);
                ret = 0;
            }
            arg0 = nxt;
        }
    }
    return ret;
}
