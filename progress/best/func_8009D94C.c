extern u8 *D_800E41DC;
#define FIELD(p, T, off) (*(T *)((p) + (off)))
void func_8008C5DC(s32 index) {
    u8 *base = D_800E41DC;
    u8 *slot = base + index * 104;
    if (slot[0]) {
        u8 pending = slot[1];
        FIELD(slot, u16, 0x28) = 20;
        if (pending) {
            slot[1] = 0;
        } else {
            f32 value = FIELD(slot, f32, 0x4c);
            u16 timer = FIELD(slot, u16, 0x28);
            slot[0x5c] = 3;
            FIELD(slot, s32, 0x54) = 0;
            FIELD(slot, s32, 0x50) = 0;
            FIELD(slot, f32, 0x58) = value;
            FIELD(slot, u16, 0x48) = timer;
        }
    }
}

u32 func_8009D94C(u8 *state, u32 step) {
    u32 ret;
    s32 remaining;
    u32 progress;
    u32 delta;

    if ((s8)state[0x11dd] != 3) {
        ret = 0;
    } else {
        remaining = FIELD(state, s32, 0x11a8);
        if (remaining > 0) {
            remaining = (u32)remaining - step;
            FIELD(state, s32, 0x11a8) = remaining;
            if (remaining <= 0) {
                state[0x11dd] = 4;
                FIELD(state, s32, 0x11a8) = 0;
            }
        }
        progress = FIELD(state, u32, 0x11d4);
        delta = FIELD(state, u32, 0x11d8) - progress;
        delta = step < delta ? step : delta;
        FIELD(state, u32, 0x11d4) = progress + delta;
        ret = delta;
    }
    return delta;
}

void func_800A97A0(f32 *out, u32 *in) {
    u32 *end = in + 8;
    do {
        u32 a = in[0];
        u32 b = in[8];
        s32 x = (a & 0xFFFF0000u) | (b >> 16);
        s32 y = (a << 16) | (b & 0xFFFFu);
        f32 first = (f32)x * 0.0000152587890625f;
        f32 second = (f32)y * 0.0000152587890625f;
        out[0] = first;
        out[1] = second;
        in++;
        out += 2;
    } while (in != end);
}

typedef struct ListNode ListNode;
struct ListNode {
    ListNode *next;
};

ListNode *func_800A798C(ListNode **head) {
    ListNode *node = *head;
    *head = node->next;
    return node;
}
