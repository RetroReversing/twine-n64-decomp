typedef struct { u8 pad0[0x2e]; u8 group; u8 pad2f[0x34]; u8 slot; } Entry;
typedef struct { u8 previous; u8 next; u16 used; } SlotLinks;
typedef struct { u16 index; u16 pad; } IndexLink;
extern SlotLinks D_80102CE0[]; extern u8 D_8010957D[]; extern u16 D_80109B1C; extern IndexLink D_8010A51A[], D_8010A51C[]; extern void voiceReleaseHandles(void *);
void func_80098B14(register Entry *entry, s32 group) {
 u32 slot=entry->slot; union { SlotLinks * pointer; u32 value; } __repair_phase_storage = {&D_80102CE0[slot] }; u32 current,key,orderedGroup,groupPosition; u16 previous,head;  u8 next;
 if(__repair_phase_storage.pointer->used==1){ if(entry->group==(u8)group) return; voiceReleaseHandles(entry); }
 __repair_phase_storage.pointer->used=1; __repair_phase_storage.pointer->previous=0xFF; next=D_8010957D[(u8)group]; current=(u8)group; __repair_phase_storage.pointer->next=next;
 if(next!=0xFF) D_80102CE0[D_8010957D[(u8)group]].previous=slot;
 else {
   head=D_80109B1C; __repair_phase_storage.value=(u8)group;
   if(head!=0xFFFF){ groupPosition=(u8)group; orderedGroup=(u16)__repair_phase_storage.value;
     if(orderedGroup>=(u16)head){ current=head;
for (;;) {
    key=(u16)current; if(orderedGroup>=key){ previous=current; current=D_8010A51A[key].index; if(current!=0xFFFF) continue; }
    break;
}
       D_8010A51A[previous].index=__repair_phase_storage.value; groupPosition=(u8)group; D_8010A51C[groupPosition].index=previous; D_8010A51A[groupPosition].index=current;
       if((u16)current!=0xFFFF) D_8010A51C[(u16)current].index=__repair_phase_storage.value;
     } else { D_8010A51A[groupPosition].index=head; D_8010A51C[groupPosition].index=0xFFFF; D_8010A51C[head].index=__repair_phase_storage.value; D_80109B1C=__repair_phase_storage.value; }
   } else { D_8010A51A[current].index=0xFFFF; D_8010A51C[current].index=0xFFFF; D_80109B1C=(u8)group; }
 }
 D_8010957D[(u8)group]=slot; entry->group=(u8)group;
}
