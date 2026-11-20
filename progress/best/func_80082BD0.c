s32 func_8000A8B4(u16, f32, s32);
s32 func_8000AABC(s32, s32, s32, s32);
u32 func_80045CF8(s32);
f32 func_80084270(s32, s16 *);
extern u16 D_800CE5D0[], D_800CE5D8[];
extern s32 D_80109688[];

void func_800843CC(s32 object, u8 variant) {
    s16 index;
    f32 factor = func_80084270(object, &index);
    u16 item;
    s32 result;
    if (variant) {
        item = D_800CE5D0[func_80045CF8(4)];
    } else {
        item = D_800CE5D8[func_80045CF8(4)];
    }
    result = func_8000A8B4(item, factor, 255);
    func_8000AABC(result, D_80109688[(u16)index], object, 0);
}

extern f32 D_80102E6C, D_80102E70, D_80102E74, D_80102E78;
extern f32 D_80102E80, D_80102E84, D_80102E88, D_80102E8C, D_80102EA4;

f32 *func_80082BD0(void) {
    f32 *out = &D_80102E74;
    f32 x0 = D_80102E80 * out[-3];
    f32 x1 = D_80102E84 * D_80102E6C;
    f32 x2 = D_80102E88 * D_80102E70;
    f32 y0 = D_80102E8C * out[-3];
    f32 y1 = out[7] * D_80102E6C;
    f32 y2 = out[8] * D_80102E70;
    f32 z0 = out[9] * out[-3];
    f32 z1 = out[10] * D_80102E6C;
    f32 z2 = out[11] * D_80102E70;
    f32 x = x0 + x1 + x2 + D_80102EA4;
    f32 y = y0 + y1 + y2 + out[13];
    f32 z = z0 + z1 + z2 + out[14];
    *out = x;
    D_80102E78 = y;
    out[2] = z;
    return out;
}

typedef struct ListNode ListNode;
struct ListNode {
    u8 pad0[0x10];
    ListNode *next;
    ListNode *prev;
    void *owner;
};

void func_800168A4(ListNode *head) {
    ListNode *node = head->next;
    if (node != 0) {
        ListNode *next = node->next;
        if ((head->next = next) != 0) {
            next->prev = head;
        }
        node->next = 0;
        node->prev = 0;
        node->owner = 0;
    }
}

u64 osGetTime(void);
extern u64 D_80102CC8, D_80109DD8, D_80115320;

void func_800070A4(void) {
    D_80109DD8 = 0;
    D_80115320 = osGetTime();
    D_80102CC8 = 0;
}
