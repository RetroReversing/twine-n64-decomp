typedef struct { s32 data; u16 id; u16 pad; u16 ref; u16 pad2; } Entry;
typedef struct { u16 id; u16 a; u16 b; u16 c; u16 d; u16 e; } Entry2;
extern s32 D_800F8158; extern Entry D_800F815C[]; extern Entry2 D_800F8160[];
void func_8008C0D4(void); void func_8008C11C(void);
s32 func_80097454(u16 arg0) {
 s32 i,j;
 func_8008C0D4();
 for(i=0;i<D_800F8158;i++) if(D_800F8160[i].id==arg0) break;
 if(i!=D_800F8158) {
  if(--D_800F815C[i].ref==0) {
   for(j=i+1;j<D_800F8158;j++) D_800F815C[j-1]=D_800F815C[j];
   D_800F8158--; func_8008C11C(); return 1;
  }
 }
 func_8008C11C(); return 0;
}
