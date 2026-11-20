extern s8 D_800CEEC0; extern u8 D_800CEEC1, D_800E2CC0[]; extern s32 D_800E3F1C,D_800E3F24[],D_800E3F2C,D_8010D428; extern void (*D_80100180)(s32);
void func_800882D0(); void func_8008C0D4(); void func_8009D278(); void func_8008C11C();
void func_80088DE0(s32 arg0,s32 arg1) {
 s32 i,j,off; s32 *p;
 for(i=0;i<2;i++) {func_800882D0(i,arg1); arg1=2;}
 do { i=0; off=0; while (!D_800E2CC0[off]) {i++; off+=0x1228; if(i>=2) break;} } while(i!=2);
 D_800CEEC0=0; func_8008C0D4(); D_8010D428=0; func_8009D278(); func_8008C11C();
 if(D_800E3F1C && D_800CEEC1) D_80100180(D_800E3F1C);
 if(D_800E3F2C & 1) { p=D_800E3F24; for(j=0;j<2;j++) D_80100180(*p++); }
}
