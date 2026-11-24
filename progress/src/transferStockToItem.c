typedef struct { u8 pad[0x80]; u8 slot; u8 p81; u8 max; u8 cap; u8 pad84[0x64]; } P648FC;
typedef struct { u8 pad[7]; s8 c; } I648FC;
typedef struct { u8 pad[0x1BC]; s16 stock[30]; I648FC items[1]; } S648FC;
typedef struct { u8 pad[0xE]; s8 idx; } Q648FC;
typedef struct { u8 pad[0x68]; Q648FC *q; S648FC *s; } O648FC;
extern P648FC sEnemyDefTable[];
s16 resolveEnemyDefLink(s32);

/* Moves ammo from the stock pool into the item's count, limited by max, per-transfer cap and available stock.
   Returns 1 if a transfer is possible; only applies it when checkOnly is 0. */
s32 transferStockToItem(O648FC *owner, s8 checkOnly) {
    s8 defIndex = owner->q->idx;
    S648FC *inventory = owner->s;
    P648FC *def = &sEnemyDefTable[defIndex];
    u8 slot = def->slot;
    s16 itemIndex = resolveEnemyDefLink(defIndex);
    s16 *stockPtr = (s16 *)((u8 *)inventory + slot * 2) + 0xDE;
    s16 stockCount = *stockPtr;
    s32 amount;

    if (stockCount > 0) {
        amount = def->max - inventory->items[itemIndex].c;
        if (def->cap < amount) {
            amount = def->cap;
        }
        if (stockCount < amount) {
            amount = stockCount;
        }
        if (amount != 0) {
            if (checkOnly == 0) {
                *stockPtr = stockCount - amount;
                inventory->items[itemIndex].c += amount;
            }
            return 1;
        }
    }
    return 0;
}
