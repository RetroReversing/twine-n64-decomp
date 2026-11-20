typedef struct { s32 a[6]; } Arr6;
extern Arr6 D_800D2EA0;

s32 func_80034EAC(s32 i) {
    Arr6 t = D_800D2EA0;
    return t.a[i];
}

typedef struct Blk { struct Blk *prev; struct Blk *next; s32 size; } Blk;
extern Blk *D_800E1AAC;

void coalesce_adjacent_free_blocks(void) {
    Blk *b, *n;
    s32 merged;
    do {
        merged = 0;
        for (b = D_800E1AAC; b != 0; b = b->next) {
            n = (Blk *)((u8 *)b + b->size);
            if (n == b->next) {
                b->size += n->size;
                b->next = n->next;
                if (n->next != 0) n->next->prev = b;
                merged = 1;
            }
        }
    } while (merged);
}
