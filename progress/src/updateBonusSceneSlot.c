typedef struct { char pad[0x68]; void *a; void *b; } Obj;
extern Obj *sBonusObjectTable[];
extern s16 D_800E0ECC[], D_800E0ED4[];
extern u8 func_80070844(void *, s32);
void updateBonusSceneSlot(u16 i) {
 Obj *p = sBonusObjectTable[i];
 void *q;
 if (p != 0) {
  q = p->b;
  if (q != 0) {
   D_800E0ECC[i] = (s8)*((u8 *)p->a + 0xe);
   D_800E0ED4[i] = func_80070844(q, *((u8 *)q + 0x175));
  }
 }
}
