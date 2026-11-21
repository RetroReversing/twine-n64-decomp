typedef struct { u8 pad[0x80]; u8 slot; u8 p81; u8 max; u8 cap; u8 pad84[0x64]; } P648FC;
typedef struct { u8 pad[7]; s8 c; } I648FC;
typedef struct { u8 pad[0x1BC]; s16 stock[30]; I648FC items[1]; } S648FC;
typedef struct { u8 pad[0xE]; s8 idx; } Q648FC;
typedef struct { u8 pad[0x68]; Q648FC *q; S648FC *s; } O648FC;
extern P648FC sEnemyDefTable[];
s16 func_80063C7C(s32);

s32 func_800648FC(O648FC *arg0, s8 arg1) {
    s8 idx = arg0->q->idx;
    S648FC *s = arg0->s;
    P648FC *p = &sEnemyDefTable[idx];
    u8 slot = p->slot;
    s16 k = func_80063C7C(idx);
    s16 *st = (s16 *)((u8 *)s + slot * 2) + 0xDE;
    s16 have = *st;
    s32 n;

    if (have > 0) {
        n = p->max - s->items[k].c;
        if (p->cap < n) {
            n = p->cap;
        }
        if (have < n) {
            n = have;
        }
        if (n != 0) {
            if (arg1 == 0) {
                *st = have - n;
                s->items[k].c += n;
            }
            return 1;
        }
    }
    return 0;
}
