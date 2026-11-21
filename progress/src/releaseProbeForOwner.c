s16 timerGetTotalSeconds(void *timer);
s32 setActorStatusBits(void *actor);
extern u8 sProbeOwners[];
extern s32 sProbeTimes[2];
extern void *sProbeActors[2];
extern void *sProbeStates[2];
extern u8 sProbeTimer[];

/* If owner is waiting in one of the two probe slots, records the probe time,
   clears the slot, flags the actor and sets the state's mode bits. */
void releaseProbeForOwner(s32 owner) {
    s32 *slot;
    s32 slotOffset;
    void *state;

    {
        u16 i;
        for (i = 0; i < 2; i++) {
            slotOffset = i * 4;
            slot = (s32 *)(sProbeOwners + slotOffset);
            if (owner == *slot) {
            ((u32 *) &sProbeTimes)[i] = (s32) timerGetTotalSeconds(sProbeTimer);
            *slot = 0;
            setActorStatusBits(sProbeActors[i]);
            state = sProbeStates[i];
            *(s32 *)((u8 *)state + 0x28) = (s32) ((*(s32 *)((u8 *)state + 0x28) & ~0xFC) | 0x1C);
            }
        }
    }
}
