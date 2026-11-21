typedef struct { u32 x, y, z; } Vec;
f32 approxDistance(void *, void *);
/* For each actor in the linked list that shares this actor's parent and lies within radius, flags it and writes the impact values into its hit state. */
void applyNearbyActorImpact(void *actor, f32 radius, f32 impulse) {
    void *other;
    u32 impactFlag, impactMask, unitOne;
    other = **(void ***)((char *)actor + 0x20);
    if (other != 0) {
    impactFlag = 0x40000000; impactMask = 0xFFFF0FFF; unitOne = 1;
    do {
        if (*(void **)((char *)other + 0x20) == *(void **)((char *)actor + 0x20) && approxDistance((char *)actor + 0x24, (char *)other + 0x24) < radius) {
            if ((u32)(*(u16 *)((char *)other + 0x78) - 2) < 2) {
                char *hitState = *(char **)((char *)other + 0x6C);
                *(u32 *)((char *)other + 0x60) |= impactFlag;
                *(u32 *)(hitState + 0x18C) = (*(u32 *)(hitState + 0x18C) & impactMask) | 0x7000;
                { u32 a = *(u32 *)((char *)actor + 0x24), b = *(u32 *)((char *)actor + 0x28), c = *(u32 *)((char *)actor + 0x2c); *(u32 *)(hitState + 0x1a0) = a; *(u32 *)(hitState + 0x1a4) = b; *(u32 *)(hitState + 0x1a8) = c; }
                do { *(f32 *)(hitState + 0x1B0) = impulse; } while (0);
                *(u32 *)(hitState + 0x1B4) = 0;
            }
            if (*(u16 *)((char *)other + 0x78) == 1 && *(s16 *)((char *)other + 0x7A) != 0x27) {
                char *hitState = *(char **)((char *)other + 0x6C);
                u32 a, b, c;
                *(u32 *)((char *)other + 0x60) |= impactFlag;
                *(u32 *)(hitState + 0x88) = (*(u32 *)(hitState + 0x88) & 0xFFE1FFFF) | 0xE0000;
                a = *(u32 *)((char *)actor + 0x24); b = *(u32 *)((char *)actor + 0x28); c = *(u32 *)((char *)actor + 0x2C);
                *(u32 *)(hitState + 0x50) = a; *(u32 *)(hitState + 0x54) = b; *(u32 *)(hitState + 0x58) = c;
                do { *(f32 *)(hitState + 0x60) = impulse; } while (0);
                *(u32 *)(hitState + 0x64) = 0;
            }
        }
        other = *(void **)other;
    } while (other != 0);
    }
}
