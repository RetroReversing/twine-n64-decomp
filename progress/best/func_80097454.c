typedef struct { s32 data; u16 id; u16 pad; u16 ref; u16 pad2; } Entry;
extern s32 D_800F8158; extern Entry D_800F815C[];
void func_8008C0D4(void); void func_8008C11C(void);
s32 func_80097454(u16 arg0) {
 s32 i,j;
 func_8008C0D4();
 { s32 offset=0; extern char D_800F8160[]; for(i=0;i<D_800F8158;i++, offset+=12) if(*(u16 *)(D_800F8160+offset)==arg0) break; }
 if(i!=D_800F8158) {
  if(--D_800F815C[i].ref==0) {
   for(j=i+1;j<D_800F8158;j++) D_800F815C[j-1]=D_800F815C[j];
   D_800F8158--; func_8008C11C(); return 1;
  }
 }
 func_8008C11C(); return 0;
}
