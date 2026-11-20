extern u16 gSaveSlotValid[], D_800E09A6[], D_800E0996[], D_800E097E[], D_800E098E[], D_800E099E[];
void func_8001074C(u16 i, s16 a, s16 b) {
 if (i < 4 && gSaveSlotValid[i] && !D_800E09A6[i]) {
  D_800E0996[i] = b;
  D_800E097E[i] = a;
  D_800E098E[i] = 0;
  D_800E099E[i] = 0;
 }
}
