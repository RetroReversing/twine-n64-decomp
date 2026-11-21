typedef struct Node {
    struct Node *prev;
    struct Node *next;
    u32 addr;
    s32 tag;
    s32 len;
    u32 data;
} Node;

typedef struct Out {
    s32 a;
    s32 b;
    s16 c;
    s16 d;
} Out;

typedef struct Ent {
    s32 a;
    s32 b;
    s32 c;
} Ent;

s32 func_800CEEE0();
extern Node *D_800E425C;
extern Node *D_800E4260;
extern Node *D_800E4264;
extern Ent *D_80103EB4;
extern u16 sSlotLogCount;
extern s32 D_80109BA0;
extern s32 D_80109BF8;

void func_80089F7C(Out *arg0, u32 arg1, s32 arg2, s32 arg3) {
    s32 sp10[6];
    u32 sp2C;
    u32 sp34;
    s32 sp38;
    Node *s0;
    Node *s7;
    union { Node * pointer; u32 value; } __repair_phase_storage;
    s32 *p;
    
    u32 a0;
    u32 a1;
    u32 a2;
    s32 s1;
    s32 s3;
    s32 s2;
    u32 s4;
    s32 t0;
    s32 v0;
    u32 s1_2;
    

    s4 = arg1;
    s0 = D_800E4260;
    s3 = 0;
    s2 = arg2;
    sp2C = s4 + s2;
    sp34 = s4 - 0x600;
    if (s0 != NULL) {
        t0 = 0x600;
        do {
            s7 = s0->next;
            if (s0->tag == arg3 && (a0 = s0->addr, a0 < sp2C) && sp34 < a0) {
                a1 = s0->len;
                if (a1 != t0) {
                    if (a0 + a1 < s4 + s2) {
Ent *e;

                        if (s4 + s2 >= a0 + 0x600) {
                            s1 = t0 - a1;
                        } else {
                            s1 = ((s4 + s2 - (a0 + a1)) + 0xFF) & ~0xFF;
                        }
                        sp38 = t0;
                        D_80109BF8 += 0xC;
                        D_80109BA0 = func_800CEEE0(D_80109BA0, D_80109BF8);
                        e = &D_80103EB4[(*(u16 *)&sSlotLogCount)];
                        e->b = s0->addr + s0->len;
                        e->a = s1;
                        e->c = s0->data + s0->len;
                        sSlotLogCount++;
                        s0->len += s1;
                    }
                }
                if (s0 != D_800E4260) {
                    if (s0->prev != NULL) s0->prev->next = s0->next;
                    if (s0->next != NULL) s0->next->prev = s0->prev;
                    else D_800E425C = s0->prev;
                    D_800E4260->prev = s0;
                    s0->next = D_800E4260;
                    D_800E4260 = s0;
                    s0->prev = NULL;
                }
                a1 = s0->addr;
                if (s4 < a1) {
                    p = &sp10[(u16)s3];
                    p[0] = s0->data;
                    p[4] = s0->addr;
                    s3++;
                    s2 -= (s2 - (a1 - s4));
                    p[2] = s2;
                    s0 = s7;
                    continue;
                }
                if (a1 + s0->len < s4 + s2) {
                    s1_2 = (u16)s3;
    p = &sp10[s1_2];
                    p[0] = s0->data + (s4 - a1);
                    p[4] = s4;
                    p[2] = s0->addr + s0->len - s4;
                    s3++;
                    s2 -= (s0->addr + s0->len - s4);
                    s4 = s0->addr + s0->len;
                    s0 = s7;
                    continue;
                }
                p = &sp10[(u16)s3];
                p[2] = s2;
                s2 = 0;
                s3++;
                p[4] = s4;
                p[0] = s0->data + (s4 - a1);
            }
            s0 = s7;
        } while (s0 != NULL);
    }
    if (s2 != 0) {
        s1_2 = (s4 - arg3) % 1536;
        do {
            __repair_phase_storage.pointer = D_800E4264;
            if (D_800E4264 != NULL) {
                D_800E4264 = __repair_phase_storage.pointer->prev;
                if (D_800E4264 != NULL) {
                    D_800E4264->next = NULL;
                }
                if (D_800E4260 == NULL) {
                    __repair_phase_storage.pointer->prev = D_800E425C;
                    if (D_800E425C != NULL) {
                        D_800E425C->next = __repair_phase_storage.pointer;
                    }
                    D_800E425C = __repair_phase_storage.pointer;
                } else {
                    __repair_phase_storage.pointer->prev = NULL;
                    __repair_phase_storage.pointer->next = D_800E4260;
                    D_800E4260->prev = __repair_phase_storage.pointer;
                }
                D_800E4260 = __repair_phase_storage.pointer;
                s0 = __repair_phase_storage.pointer;
            } else {
                D_800E425C->prev->next = NULL;
                s0 = D_800E425C;
                D_800E4260 = s0;
                s0->next = D_800E4260;
                D_800E4260->prev = s0;
                s0->prev = NULL;
                D_800E425C = D_800E425C->prev;
            }
            __repair_phase_storage.value = s2 + s1_2;
            s0->addr = s4 - s1_2;
            s0->tag = arg3;
            if (__repair_phase_storage.value >= 0x601U) {
Ent *e;

                s0->len = 0x600;
                D_80109BF8 += 0xC;
                v0 = func_800CEEE0(D_80109BA0, D_80109BF8);
                __repair_phase_storage.value = (u16)s3;
    p = &sp10[__repair_phase_storage.value];
                s3++;
                D_80109BA0 = v0;
                e = &D_80103EB4[sSlotLogCount];
                e->b = s0->addr;
                e->a = 0x600;
                e->c = s0->data;
                s2 = s2 - 0x600 + s1_2;
                sSlotLogCount += 1;
                p[0] = s0->data + s1_2;
                s4 -= s1_2 - 0x600;
                p[4] = 0x600 - s1_2;
                p[2] = s0->addr + s1_2;
            } else {
Ent *e;

                s0->len = (__repair_phase_storage.value + 0xFF) & ~0xFF;
                D_80109BF8 += 0xC;
                v0 = func_800CEEE0(D_80109BA0, D_80109BF8);
                e = &D_80103EB4[sSlotLogCount];
                e->b = s0->addr;
                e->a = s0->len;
                e->c = s0->data;
                p = &sp10[(u16)s3];
                p[0] = s0->data + s1_2;
                D_80109BA0 = v0;
                sSlotLogCount += 1;/*__repair_loop_weight*/do {
                s3++;} while (0);
                p[2] = s2;
                s2 = 0;
                p[4] = s0->addr + s1_2;
            }
            s1_2 = 0;
        } while (s2 != 0);
    }
    if ((s3 & 0xFFFF) == 1) {
        arg0->a = sp10[0];
        arg0->d = 0;
        arg0->c = (s16)sp10[2];
        return;
    }
    if ((u32)sp10[4] < (u32)sp10[5]) {
        arg0->a = sp10[0];
        arg0->b = sp10[1];
        arg0->c = (s16)sp10[2];
        arg0->d = (s16)sp10[3];
        return;
    }
    arg0->a = sp10[1];
    arg0->b = sp10[0];
    arg0->c = (s16)sp10[3];
    arg0->d = (s16)sp10[2];
}
