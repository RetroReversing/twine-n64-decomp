void func_800957A8(unsigned int *);
extern s32 D_80107ED4[],D_80107ED8[],D_80107EDC[],D_80107EE0[],D_80107EE4[];
extern u8 D_80107EE8[],D_80107EE9[];
void func_8008EB80(s32 arg0,s32 arg1,s32 arg2,s8 arg3,s32 arg4) {
 s32 sp10,s1,s0,i,index,status,delta; s1=arg1; if(!(s1&0xffff))s1=arg1+1; s0=s1&0xffff; sp10=s0; do { func_800957A8((u32 *)&sp10); } while (0);
 index=arg2&255;
 if(index==255 || index==252 || (index>=250 && index<=254)) {
   if(index==255) status=0;
   else if(index==252) status=2;
   else status=index-253;
   for(i=0;i<32;i++) {
     if(index==255 ? D_80107EE8[i*40]<2 : index==252 ? (u32)(D_80107EE8[i*40]-2)<2 : D_80107EE8[i*40]==status) {
       D_80107ED8[i*10]=(arg0&255)<<16;
       D_80107EE0[i*10]=sp10;
       delta=D_80107ED8[i*10]-D_80107ED4[i*10];
       D_80107EDC[i*10]=delta/(s1&0xffff);
       D_80107EE4[i*10]=-1;
     }
   }
 } else {
   index*=40;
   D_80107ED8[index/4]=(arg0&255)<<16;
   D_80107EDC[index/4]=delta/s0;
   delta=D_80107ED8[index/4]-D_80107ED4[index/4];
   D_80107EE9[index]=arg3;
   D_80107EE4[index/4]=arg4;
   D_80107EE0[index/4]=sp10;
 }
}
