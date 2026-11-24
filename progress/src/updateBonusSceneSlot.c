typedef struct { char pad[0x68]; void *a; void *b; } Obj;
extern Obj *sBonusObjectTable[];
extern s16 sBonusSlotValueA[], sBonusSlotValueB[];
extern u8 getSlotByteOrZero(void *, s32);
/* Refreshes the cached value pair for a bonus scene slot from its object and linked target. */ void updateBonusSceneSlot(u16 slot) {
 Obj *object = sBonusObjectTable[slot];
 void *target;
 if (object != 0) {
  target = object->b;
  if (target != 0) {
   sBonusSlotValueA[slot] = (s8)*((u8 *)object->a + 0xe);
   sBonusSlotValueB[slot] = getSlotByteOrZero(target, *((u8 *)target + 0x175));
  }
 }
}
