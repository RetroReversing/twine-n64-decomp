void pickRandomTableEntry(s32, s32, void *, void *);
u32 randomIntBelow(s32);
void spawnSparkleLine(s32, s32, void *, void *);
/* Randomly spawns sparkle effects at the actor's position when flagged, then clears its event flags. */ void updateActorSparkles(char *actor) {
 struct Vec { s32 x,y,z; } v; char *info;
 if ((*(s32 *)(actor+0x58)&4 || *(s32 *)(actor+0x60)&0x3000) && !randomIntBelow(*(s16 *)(actor+0x7c))) {
 info=*(char **)(actor+0x6c);
 v = *(struct Vec *)(actor+0x24);
 pickRandomTableEntry(*(s32 *)info, *(u8 *)(info+5), &v, 0);
 spawnSparkleLine(*(s32 *)(actor+0x20),1,&v,&v);
 }
 *(s32 *)(actor+0x60)=0;
}
