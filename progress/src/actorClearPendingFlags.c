typedef struct { u8 pad[0x60]; f32 f60; u8 pad64[4]; s32 x68; u8 pad6c[0x1C]; u32 hi:11; u32 fld:4; u32 lo:17; } O81470;
typedef struct { u8 pad[0x60]; u32 flags; u8 pad64[8]; O81470 *o; u8 pad70[0xC]; s16 kind; } A81470;
/* Clears the pending flags (0x04000080) on an actor; unless it is kind 0xC, sets flag 0x40000000 and primes its object with 500.0f and state 0xE. */ void actorClearPendingFlags(A81470 *actor) {
    u32 pendingMask = 0x04000080;
    u32 flags = actor->flags;
    O81470 *o = actor->o;

    if (flags & pendingMask) {
        flags &= ~0x04000080;
        actor->flags = flags;
        if (actor->kind != 0xC) {
            actor->flags = flags | 0x40000000;
            o->x68 |= 0x1000;
            o->f60 = 500.0f;
            o->fld = 0xE;
        }
    }
}
