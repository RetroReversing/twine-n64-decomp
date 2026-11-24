typedef s32 M2C_UNK;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
void *findEntryById(s32, M2C_UNK);
M2C_UNK setSaveMenuPage(M2C_UNK, s32, u16);
extern u8 D_800B60EA;
extern M2C_UNK gMenuEventHandlers;
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
/* Calls the handler registered for eventType on the menu object at objectIndex, then runs the active save-menu entry's callback when the menu is in its selectable state. */ u8 dispatchMenuEvent(s32 objectIndex, s32 eventType) {
 M2C_UNK (*temp_v0)(s32); s32 menuObject; s32 temp_s0; u8 result; void *foundEntry;
 menuObject = *(s32 *)((u8 *)&D_8010A500 + ((objectIndex & 0xFFFF) * 4));
 if (menuObject == 0) return 0;
 objectIndex = (u8)eventType;
 temp_v0 = *(M2C_UNK (**)(s32))((u8 *)&gMenuEventHandlers + (objectIndex * 0x10));
 if (temp_v0 != NULL) temp_v0(menuObject);
 result = (u8)eventType;
 if (M2C_FIELD(gMenuState, u8 *, 0x2C) == 0) {
  result = eventType & 0xFF;
  if (D_800B60EA == 1) {
   if (objectIndex == 0x13) { setSaveMenuPage(0xA, D_80102EBC, M2C_FIELD(sActiveMenu, u16 *, 0x7A)); return result; }
   result = eventType & 0xFF;
   if (M2C_FIELD(gMenuState, void **, 0x18) != NULL) {
    SaveMenuMatch *menu;
    foundEntry = findEntryById(gMenuState->id, 0xE);
    menu = gMenuState;
    menu->flag = 1U;
    menu->entry = foundEntry;
    M2C_FIELD(*(void * volatile *)&gMenuState->entry, M2C_UNK (**)(void), 4)();
    result = eventType & 0xFF;
   }
   return result;
  }
 }
 return result;
}
