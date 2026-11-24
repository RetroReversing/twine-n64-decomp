typedef struct {
    u8 pad_0[0x1E];
    s16 field_1E;
    u8 pad_20[8];
    u32 hi : 16;
    u32 b : 4;
    u32 c : 4;
    u32 lo : 8;
} Obj15F0C;

Obj15F0C *unlinkNextNode(void *);
extern s32 gNodeObjectCount;
extern s32 D_8010D268;

/* Allocates an object from the node pool, clears its field, bumps the live count and sets its flag nibbles to 1. */ Obj15F0C *allocTextNodeObject(void) {
    Obj15F0C *node;

    node = unlinkNextNode(&D_8010D268);
    if (node != NULL) {
        node->field_1E = 0;
        gNodeObjectCount++;
        node->b = 1;
        node->c = 1;
    }
    return node;
}
