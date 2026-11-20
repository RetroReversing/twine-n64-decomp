typedef struct { u8 a; u8 pad[5]; } Entry;
typedef struct { u16 a; u16 pad; } Item;
extern u16 D_800BFC32; extern Item D_800E0768[]; extern Entry D_800E077C[]; extern s16 D_800E093A; extern s16 D_80103022[]; extern u8 D_80108F75;
u16 func_80012BCC(void) {
 s16 *p; s16 v;
 D_800E093A=0;
 do {
 p=&D_80103022[D_800E093A]; *p=0;
 if (!D_800E077C[D_800E093A].a && (D_80108F75 >> D_800E093A) && (D_800E0768[D_800E093A].a&0x1f07)==5) *p=1;
 v=D_800E093A+1; D_800E093A=v;
 } while(v<4);
 return D_800BFC32;
}
