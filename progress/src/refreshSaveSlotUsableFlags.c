typedef struct { u8 a; u8 pad[5]; } Entry;
typedef struct { u16 a; u16 pad; } Item;
extern u16 gSaveStatus; extern Item D_800E0768[]; extern Entry D_800E077C[]; extern s16 gSaveSlot; extern s16 gSaveSlotFlags[]; extern u8 gSavePresentMask;
/* Sets a flag for each of the 4 save slots that is present, not blocked, and has a type-5 entry. */ s32 refreshSaveSlotUsableFlags(void) {
 s16 *flag; s16 *flags=gSaveSlotFlags; s16 next; int presentMask=gSavePresentMask; int i;
 gSaveSlot=0;
 do {
 i=gSaveSlot; flag=(s16 *)((i * 2) + (u32)flags); *flag=0;
 if (!D_800E077C[i].a && (presentMask >> i) && (D_800E0768[i].a&0x1f07)==5) *flag=1;
 next=gSaveSlot+1; gSaveSlot=next;
 } while(next<4);
 return gSaveStatus;
}
