typedef struct { u8 a; u8 pad[5]; } Entry;
typedef struct { u16 a; u16 pad; } Item;
extern u16 gSaveStatus; extern Item D_800E0768[]; extern Entry D_800E077C[]; extern s16 gSaveSlot; extern s16 gSaveSlotFlags[]; extern u8 D_80108F75;
u16 func_80012BCC(void) {
 s16 *p; s16 *base=gSaveSlotFlags; s16 v; int mask=D_80108F75; int i;
 gSaveSlot=0;
 do {
 i=gSaveSlot; p=(s16 *)((i * 2) + (u32)base); *p=0;
 if (!D_800E077C[i].a && (mask >> i) && (D_800E0768[i].a&0x1f07)==5) *p=1;
 v=gSaveSlot+1; gSaveSlot=v;
 } while(v<4);
 return gSaveStatus;
}
