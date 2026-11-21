#define FLD(p,t,o) (*(t *)((u8 *)(p)+(o)))
extern s16 D_800C3CF4[]; extern s16 D_800C3928[]; extern s16 D_800C392A[]; extern s16 *D_800C3CF8[]; extern u8 *D_800C3CFC[]; extern f32 D_800AE4D8; extern s16 *D_800AE4DC[]; extern s16 D_800AE53C[]; extern u8 D_800CA338; extern s32 gBootState;
void *func_80083E90(void*, s32); void *memset(void*,s32,s32); f32 func_80082908(f32); void func_800060B0(void*,s32,s32); void func_80084180(s32*,s32*,s32); void *func_8002BC4C(void); s16 *func_80001928(s32); s32 func_8003FA78(s32); s32 func_80002098(void *a); s32 func_8004478C(s32,s32); s32 randomIntBelow(s32);
s32 func_8000237C(void *a,s32 index,s32 mode,s32 opt) {
 u32 result=0, n, bytes, aligned, stride, size12, size4, i, j, val, id;
 s32 tmp, valid; void *base; void *obj; void *state; s16 *list;  f32 f;
 if(!a) goto done;
 bytes=D_800C3928[n*4];
 n=D_800C3CF4[index*3];
 obj=FLD(a,void*,0x68);
 state=(u8*)obj+0x14;
 if(obj == 0) {
  if(mode==1) bytes=(bytes+bytes*4+5)*4;
  else if(mode==2) bytes=(bytes*3+bytes+2)*4;
  else if(mode!=3) bytes=((s32)bytes+5)*4;
  else bytes=(bytes*3+bytes+2+bytes*4)*4;
  size4=n*4; size12=n*12;
  aligned=(bytes+7)&~7;
  base=func_80083E90(a,aligned+0xB8+aligned+bytes+size4+size12+size12);
  if(!base) goto done;
  FLD(a,void*,0x68)=base;
  memset(base,0,0xB8);
  obj=FLD(a,void*,0x68);
  tmp=(s32)((u8 *)base+0xB8); FLD(obj,void*,0x54)=(void*)tmp;
  tmp+=aligned; FLD(obj,void*,0x58)=(void*)tmp;
  tmp+=aligned; FLD(obj,void*,0x5C)=(void*)tmp;
  tmp+=bytes; FLD(obj,s32,0x14)=mode; FLD(obj,s16,0xA6)=bytes;
  FLD(obj,void*,0x6C)=(void*)tmp;
  FLD(base,void*,0)=(void*)(tmp+size4);
  FLD(base,void*,4)=(void*)((s32)base+0x14+size12);
 }
 FLD(state,s8,0x9F)=n;
 for(i=0;i<n;i++){
  f=FLD(a,f32,0x24+i*4);
  FLD(FLD(obj,void*,0),f32,i*4)=f;
  FLD(FLD(obj,void*,4),f32,i*4)=f;
 }
 f=func_80082908(3.0f);
 FLD(a,f32,0x64)=f;
 FLD(state,s32,0xC)=0;
 FLD(state,s16,0x8E)=-1; FLD(state,s16,0x8C)=0;
 FLD(state,s16,0x82)=-1; FLD(state,s16,0x84)=-1; FLD(state,s16,0x86)=-1;
 FLD(state,u8,0xA0)=0;
 FLD(state,s32,0x1C)=0; FLD(state,s32,0x4C)=0; FLD(state,s32,0x54)=0; FLD(state,s32,0x20)=0;
 FLD(state,f32,4)=1.0f; FLD(state,f32,8)=0.125f;
 f=FLD(state,f32,0xC);
 FLD(state,f32,0x14)=f; FLD(state,f32,0x10)=f; FLD(state,f32,0x18)=f;
 FLD(state,f32,0x6C)=1.0f; FLD(state,f32,0x70)=1.0f; FLD(state,f32,0x74)=1.0f;
 for(i=0;i<4;i++) FLD(state,s16,0x94+i*2)=0;
 val=(s16)FLD(a,f32,0x40); FLD(state,s16,0x78)=val; FLD(state,s16,0x7A)=0;
 FLD(state,u32,0)= (FLD(state,u32,0)&3)|0x8010;
 if(D_800C392A[index*4]) {
  for(i=0;i<(FLD(state,s16,0x92)>>2);i++) FLD((void*)FLD(state,void*,0x40),s32,i*4)=0;
 } else func_800060B0(a,0x71,0);
 func_80084180((s32*)FLD(state,void*,0x44),(s32*)FLD(state,void*,0x40),FLD(state,s16,0x92));
 func_80084180((s32*)FLD(state,void*,0x48),(s32*)FLD(state,void*,0x40),FLD(state,s16,0x92));
 f=FLD((void*)FLD(state,void*,0x44),f32,0xC);
 FLD(state,f32,0x24)=f; FLD(state,s32,0x28)=0; FLD(state,s32,0x2C)=0; FLD(state,s32,0x30)=0;
 FLD(state,u8,0x9D)=((u8*)&index)[0]; FLD(state,u8,0x9E)=((u8*)&bytes)[0];
 obj=func_8002BC4C();
 if(FLD(obj,u16,6)&0x40) FLD(state,u32,0)|=0x200000;
 list=func_80001928(index);
 id=*(D_800C3CF8[index*3]);
 valid=func_8003FA78(id); if(valid) {
  for(i=0,j=0;list[j]>=0;j++,i++) {
   val=D_800C3CFC[index*3][j];
   if(func_80002098(a),tmp!=-1) FLD(state,u32,0x58+i*4)=func_8004478C(bytes,0);
   else FLD(state,u32,0x58+i*4)=0;
  }
 } else { for(i=0,j=0;list[j]>=0;j++,i++) FLD(state,u32,0x58+i*4)=0; }
 if(opt && id>=0x2B && id<0x89) {
  for(i=0;i<16;i++) {
   if(!D_800AE4DC[i]) {result=1; goto done;}
   if(*D_800AE4DC[i]!=id) continue;
   list=&D_800AE53C[i*3];
   j=1;
   while(list[0]==14){list+=3;j += 1;}
   if(opt<0) j=randomIntBelow(j+1);
   if(j == 0) {result=1;goto done;}
   val=func_8004478C(list[-2],id); FLD(state,s32,0x38)=val;
   for(;list[0]>=0;list+=3) if(list[-2]==val) FLD(state,s32,0x58+list[0]*4)=func_8004478C(list[0],id);
  }
 } else if(valid == 0) {
  for(i=0,j=0;list[j]>=0;j++,i++) FLD(state,s32,0x58+i*4)=0;
 }
 result=1;
done: gBootState=0; return result;
}
