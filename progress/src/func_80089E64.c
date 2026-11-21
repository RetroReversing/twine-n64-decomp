typedef struct N { struct N *next,*prev; s32 a,b,c; u8 *buf; } N;
extern u8 *D_800E4254; extern N *D_800E4258,*D_800E4264; extern s32 D_800E425C,D_800E4260; extern void *(*gDataBankAlloc)(s32,s32); void func_800A0170(void *, s32);
void func_80089E64(u16 count) {
 s32 i; void *(**alloc)(s32,s32)=&gDataBankAlloc; s32 size=count*0x600;
 D_800E4254=(*alloc)(size,0); func_800A0170(D_800E4254,size);
 D_800E4258=(*alloc)(count*sizeof(N),0); D_800E425C=0; D_800E4260=0; D_800E4264=D_800E4258;
 D_800E4258[0].prev=0; D_800E4258[0].buf=D_800E4254;
 for(i=1;i<count;i++) { D_800E4258[i-1].next=&D_800E4258[i]; D_800E4258[i].prev=&D_800E4258[i-1]; D_800E4258[i].buf=D_800E4254+i*0x600; }
 D_800E4258[i-1].next=0;
}
