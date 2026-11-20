typedef struct { s32 x, y, z; } V3i;
f32 func_80045E34(void *, void *);

/* Walks the object lists in a chain of list heads, and for objects in the given type set within max_dist of pos, updates their flag word and copies pos into their sub-record. */
void func_800175C0(void **list_heads, s32 clear_mask, s32 set_mask, V3i *pos, f32 max_dist, s32 flag) {
    void **first = list_heads;
    void *obj;
    void *node;
    void *sub;
    s32 v;

    if (list_heads == NULL) {
        return;
    }
    node = *(void **)((char *)*(void **)((char *)list_heads + 0x20) + 0x58);
    do {
        for (obj = *list_heads; obj != NULL; obj = *(void **)obj) {
            switch (*(u16 *)((char *)obj + 0x78)) {
            case 1:
            case 2:
            case 3:
            case 0xB:
            case 0x24:
            case 0x3B:
            case 0x4C:
                if (max_dist == 0.0f || func_80045E34(pos, (char *)obj + 0x24) < max_dist) {
                    u16 type = *(u16 *)((char *)obj + 0x78);
                    if ((type == 1 || type == 0x4C) && !(*(s32 *)((char *)obj + 0x60) & clear_mask)) {
                        s32 flags = *(s32 *)((char *)obj + 0x60) | set_mask;
                        s32 r;
                        sub = *(void **)((char *)obj + 0x6C);
                        *(s32 *)((char *)obj + 0x60) = flags;
                        if (list_heads == first) {
                            r = flags | 0x1000;
                        } else {
                            r = flags | 0x2000;
                        }
                        *(s32 *)((char *)obj + 0x60) = r;
                        *(V3i *)((char *)sub + 0x50) = *pos;
                    } else if ((u32)(*(u16 *)((char *)obj + 0x78) - 2) < 2U) {
                        v = *(s32 *)((char *)obj + 0x60);
                        if (!(v & clear_mask)) {
                            void *q = *(void **)((char *)obj + 0x6C);
                            *(s32 *)((char *)obj + 0x60) = v | set_mask;
                            *(V3i *)((char *)q + 0x1A0) = *pos;
                        }
                    } else if ((s8)flag == 0) {
                        *(s32 *)((char *)obj + 0x60) |= set_mask;
                    }
                }
                break;
            }
        }
        list_heads = NULL;
        if (node != NULL) {
            list_heads = *(void ***)((char *)node + 8);
            node = *(void **)node;
        }
    } while (list_heads != NULL);
}
