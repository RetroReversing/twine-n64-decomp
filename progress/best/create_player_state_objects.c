extern s32 func_80015F74(void *);
extern volatile u8 D_801001A2;
extern s32 D_801002C0;
extern s16 D_8011EE4C;
extern s32 D_8011F338[];
void create_player_state_objects(void) {
 u16 i;
 int state, special=5;
 s16 *base=&D_8011EE4C;
 for (i=0; i<D_801002C0; i++) {
  state=*(&D_801001A2+i*24);
  if (state != 0) {
   if (state < 4) goto create;
   if (state == special) {
create:
    *base=i;
    D_8011F338[i]=func_80015F74((u8 *)base-0x20);
    continue;
   }
  }
  D_8011F338[i]=0;
 }
}
