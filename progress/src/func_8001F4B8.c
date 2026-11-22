typedef s32 M2C_UNK;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
void *findEntryById(s32, M2C_UNK);
M2C_UNK func_800278AC(M2C_UNK, s32, u16);
extern u8 D_800B60EA;
extern M2C_UNK D_800C4480;
extern s32 D_80102EBC;
extern M2C_UNK D_8010A500;
typedef struct SaveMenuMatch {
    u8 pad0[0xC];
    s32 id;
    u8 pad10[8];
    void * entry;
    u8 pad1C[0x10];
    u8 flag;
} SaveMenuMatch;
extern SaveMenuMatch *gSaveMenuState;
#define gMenuState gSaveMenuState
extern void *sActiveMenu;
u8 func_8001F4B8(s32 arg0, s32 arg1) {
 M2C_UNK (*temp_v0)(s32); s32 temp_a0; s32 temp_s0; u8 var_v0; void *temp_v0_2;
 temp_a0 = *(s32 *)((u8 *)&D_8010A500 + ((arg0 & 0xFFFF) * 4));
 if (temp_a0 == 0) return 0;
 arg0 = (u8)arg1;
 temp_v0 = *(M2C_UNK (**)(s32))((u8 *)&D_800C4480 + (arg0 * 0x10));
 if (temp_v0 != NULL) temp_v0(temp_a0);
 var_v0 = (u8)arg1;
 if (M2C_FIELD(gMenuState, u8 *, 0x2C) == 0) {
  var_v0 = arg1 & 0xFF;
  if (D_800B60EA == 1) {
   if (arg0 == 0x13) { func_800278AC(0xA, D_80102EBC, M2C_FIELD(sActiveMenu, u16 *, 0x7A)); return var_v0; }
   var_v0 = arg1 & 0xFF;
   if (M2C_FIELD(gMenuState, void **, 0x18) != NULL) {
    SaveMenuMatch *menu;
    temp_v0_2 = findEntryById(gMenuState->id, 0xE);
    menu = gMenuState;
    menu->flag = 1U;
    menu->entry = temp_v0_2;
    M2C_FIELD(*(void * volatile *)&gMenuState->entry, M2C_UNK (**)(void), 4)();
    var_v0 = arg1 & 0xFF;
   }
   return var_v0;
  }
 }
 return var_v0;
}
