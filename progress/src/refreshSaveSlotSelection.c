#ifndef M2C_DEFINES
#define M2C_DEFINES
typedef s32 M2C_UNK;
#define M2C_FIELD(expr,type_ptr,offset) (*(type_ptr)((s8 *)(expr)+(offset)))
#endif
typedef struct { s16 f0; u8 pad[230]; } Slot_800C469E;
s32 getSaveSlotIndex(s32);
s32 func_80063D38(void *,u32);
void func_8007089C(void *,s32,s32);
extern u8 D_800BF68A[];
extern Slot_800C469E D_800C469E[];
extern s32 gSaveSlotInfo;
extern u8 *D_8011ECC0[];
/* Scans the slot cursor list for a selectable save slot and moves the selection to it when it changed. */ void refreshSaveSlotSelection(void *arg0) {
 int __repair_literal;
 u8 slotId; u8 *cursor; void *state; register u8 *cursorEnd; register s32 foundSlot;
 state=M2C_FIELD(arg0,void**,0x6C);
 cursor=D_8011ECC0[*(D_800BF68A+(*((s32*)((s8*)&gSaveSlotInfo+(((getSaveSlotIndex(((s32)(s8)M2C_FIELD(state,volatile u8*,0x182)) & 0xFFFF) & 0xFFFF))*0x18)))*0xC))];
 foundSlot=-1U; cursorEnd=cursor+0x3B;
 for(;;){ slotId=*cursor; __repair_literal=8;
 if((*(u8*)((char*)(state+(D_800C469E[slotId].f0*__repair_literal))+(unsigned short)0x1FC)!=0)&&((func_80063D38(state,slotId)<<0x18)!=0)) foundSlot=slotId;
 else {cursor+=1;if(cursor<cursorEnd)continue;} break;}
 if(((u32)foundSlot!=-1U)&&((*(s8*)((char*)M2C_FIELD(arg0,void**,0x68)+0xE))!=(short)foundSlot))func_8007089C(arg0,0,foundSlot&0xFFFF);
}
