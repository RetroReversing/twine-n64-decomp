typedef struct { f32 x, y, z; } SVec3;
typedef struct SNode {
    s32 a;
    struct SNode *next;
    struct SNode *parent;
    f32 cost;
    SVec3 *pos;
    struct SNode *nbr[16];
    s32 pad[1];
} SNode;
extern SNode *sSearchEntries;
extern u32 sSearchEntryCount;
extern s32 D_8011F070;
extern SNode *D_8011F074;
extern s32 D_8011F0C8;
f32 func_800461D4(SVec3 *, SVec3 *);
void func_80117740(s32 *, SNode *);
void func_8011775C(SNode *);

void func_80117784(s32 arg0, s32 arg1, SVec3 *arg2, SVec3 *arg3) {
    volatile s64 reserve;
    u32 i;
    u32 count;
    SNode *cur;
    SNode *n;
    SNode *p;
    SVec3 *a;
    SVec3 *b;
    f32 best;
    s32 found = 0;
    SNode *e;

    count = sSearchEntryCount;
    i = 0;
    cur = NULL;
    if (count != 0) {
        do {
            e = &sSearchEntries[i];
            e->a = 0;
            e->next = 0;
            e->parent = 0;
            e->cost = -1.0f;
            e++;
            i++;
        } while (i < count);
    }
    if (arg0 == arg1) {
        arg2->x = sSearchEntries[arg0].pos->x;
        arg2->y = sSearchEntries[arg0].pos->y;
        arg2->z = sSearchEntries[arg0].pos->z;
        arg3->x = sSearchEntries[arg0].pos->x;
        arg3->y = sSearchEntries[arg0].pos->y;
        arg3->z = sSearchEntries[arg0].pos->z;
        return;
    }
    D_8011F0C8 = 1;
    D_8011F070 = 0;
    D_8011F074 = &sSearchEntries[arg0];
    D_8011F074->cost = 0;
    while (!found) {
        best = 999999.0f;
        cur = NULL;
        for (n = D_8011F074; n != NULL; n = n->next) {
            if (n->cost < best) {
                cur = n;
                best = n->cost;
            }
        }
        if (cur == NULL) {
            *arg2 = *sSearchEntries[arg0].pos;
            *arg3 = *sSearchEntries[arg0].pos;
            return;
        }
        i = 0;
        if (cur == &sSearchEntries[arg1]) {
            found = 1;
        } else {
            SNode **q = (SNode **)cur;
            do {
                SNode *nb = q[5];
                i++;
                if (nb != NULL && nb->cost == -1.0f) {
                    q[5]->cost = (s32)(cur->cost + func_800461D4(cur->pos, nb->pos));
                    q[5]->parent = cur;
                    func_80117740(&D_8011F070, q[5]);
                    D_8011F0C8 = D_8011F0C8 + 1;
                }
                q++;
            } while (i < 16);
            func_8011775C(cur);
            D_8011F0C8 -= 1;
        }
    }
    a = cur->pos;
    b = a;
    p = &sSearchEntries[arg0];
    if (cur != p) {
        do {
            cur = cur->parent;
            b = a;
            a = cur->pos;
        } while (cur != p);
    }
    arg2->x = a->x;
    arg2->y = a->y;
    arg2->z = a->z;
    arg3->x = b->x;
    arg3->y = b->y;
    arg3->z = b->z;
}
