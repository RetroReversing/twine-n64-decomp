typedef struct { u8 pad0[0x2e]; u8 group; u8 pad2f[0x34]; u8 slot; } Entry;
typedef struct { u8 previous; u8 next; u16 used; } SlotLinks;
typedef struct { u16 index; u16 pad; } IndexLink;
extern SlotLinks D_80102CE0[];
extern u8 D_8010957D[];
extern u16 D_80109B1C;
extern IndexLink D_8010A51A[], D_8010A51C[];
extern void func_80098A18(void);
void func_80098B14(register Entry *entry, u8 group) {
    u32 slot = entry->slot;
    SlotLinks *links = &D_80102CE0[slot];
    u32 current; u32 key; u32 orderedGroup; u16 previous; u16 head;
    u16 newGroup;  u32 groupPosition; u8 next;
    if (links->used == 1) {
        if (entry->group == group) return;
        func_80098A18();
    }
    links->used = 1;
    links->previous = 0xFF;
    current = group;
    next = D_8010957D[current];
    links->next = next;
    if (next != 0xFF) {
        D_80102CE0[D_8010957D[current]].previous = slot;
    } else {
        head = D_80109B1C;
        newGroup = group;
        if (head != 0xFFFF) {
            groupPosition = current;
            orderedGroup = (u16)newGroup;
            if (orderedGroup >= (u16)head) {
                current = head;
again:
                key = (u16)current;
                if (orderedGroup >= key) {
                    previous = current;
                    current = D_8010A51A[key].index;
                    if (current != 0xFFFF) goto again;
                }
                D_8010A51A[previous].index = newGroup;
                groupPosition = group;
                D_8010A51C[groupPosition].index = previous;
                D_8010A51A[groupPosition].index = current;
                if ((u16)current != 0xFFFF) D_8010A51C[(u16)current].index = newGroup;
            } else {
                D_8010A51A[groupPosition].index = head;
                D_8010A51C[groupPosition].index = 0xFFFF;
                D_8010A51C[head].index = newGroup;
                D_80109B1C = newGroup;
            }
        } else {
            D_8010A51A[current].index = 0xFFFF;
            D_8010A51C[current].index = 0xFFFF;
            D_80109B1C = group;
        }
    }
    D_8010957D[group] = slot;
    entry->group = group;
}
