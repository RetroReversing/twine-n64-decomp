extern u8 D_54D910[];
extern s32 D_800C0780[], D_800C0784[], D_800C0788[], D_800C078C[];
extern f32 D_800E19E0, D_800E19E4, D_800E19E8;
extern u8 D_80107ECC, D_80109A35;
extern s32 gExpansionPakPresent;
extern s32 func_80083E24(void), func_80083E90(s32,s32);
extern void func_80083E44(s32), func_80084048(s32,s32);
extern void func_800134C0(void), func_800134C8(void), func_80041F68(void *);
extern void func_8000B9B8(u8 *,s32,u32);
extern s32 func_8001499C(void *);
extern s32 func_80014A0C(s32,s32);
extern void func_800411C0(s32,s32,s32);
extern void *memset(void *,int,u32);
extern void *memcpy(void *,void *,u32);
typedef struct { s32 a; u16 b; u8 pad[0x1E]; } Header426;
typedef struct { u16 index; u16 slot; u8 pad4[0x20]; s32 file; u8 pad2C[0x18]; } Record426;
void func_800426B8(s32 arg0, s32 arg1, s8 arg2) {
    f32 __repair_fzero = 0.0f;

 unsigned long off=arg1<<4, id, n, i, j, maxA=0,maxB=0,maxC=0,maxD=0,maxE=0;
 u8 *obj,*records,*p,*q,*buf1,*buf2,*buf3,*buf4,*buf5,*buf6,*buf7,*buf8;
 u8 header[0x20]; s32 *slot; s32 bytes;
 if (D_800C0784[arg1]) return;
 id=func_80083E24();
 obj=(u8*)func_80083E90(0x30,0x17);
 func_800134C0();
 n=D_800C078C[arg1];
 records=(u8*)func_80083E90(n*0x4C,0xA);
 D_800C0788[arg1]=(s32)records;
 memset(records,0,n*0x4C);
 func_8000B9B8(obj,D_800C0780[arg1]+(s32)D_54D910,0x30);
 D_800C0784[arg1]=(s32)obj;
 n=*(s32 *)(obj+4);
 p=(u8*)func_80083E90(n*0x44,0x2D);
 func_8000B9B8(p,*(s32*)obj+(s32)D_54D910,n*0x44);
 D_800E19E8= __repair_fzero; D_800E19E4= __repair_fzero; D_800E19E0= __repair_fzero;
 func_80041F68(obj);
 q=p;
 for(i=0;i<n;i++,q+=0x44) {
  func_8000B9B8(header,*(s32*)(q+0x24)+(s32)D_54D910,0x20);
  if(maxA<*(u16*)(header+4)) maxA=*(u16*)(header+4);
  if(maxB<*(u16*)(header+0xC)) maxB=*(u16*)(header+0xC);
  if(maxC<*(u16*)(header+0x14)) maxC=*(u16*)(header+0x14);
  if(maxD<*(u16*)(header+0x1C)) maxD=*(u16*)(header+0x1C);
  if(maxE<*(u16*)(q+2)) maxE=*(u16*)(q+2);
 }
 buf1=(u8*)func_80083E90(maxD,0x2D);
 buf2=(u8*)func_80083E90(maxD*3,0x2D);
 bytes=maxA*12; buf3=(u8*)func_80083E90(bytes,0x2D);
 buf4=(u8*)func_80083E90(bytes,0x2D);
 bytes=maxB*4; buf5=(u8*)func_80083E90(bytes,0x2D);
 buf6=(u8*)func_80083E90(bytes,0x2D);
 bytes=maxC*4; buf7=(u8*)func_80083E90(bytes,0x2D);
 buf8=(u8*)func_80083E90(bytes,0x2D);
 for(i=0;i<n;i++,p+=0x44,records+=0x4C) {
  Header426 *h;
  s32 rid,ix,base;
  u16 ix0;
  rid=*(s16 *)(p+0x24+4);
  slot=(s32 *)(D_800C0788+rid*4);
  ix0=*(u16*)p;
  base=(s32)*slot + ix0*76;
  *(s32 *)(base+4)=*(s32*)p;
  if(gExpansionPakPresent && !D_80107ECC) *(u8 *)(base+0x46)=0x80;
  else *(u8 *)(base+0x46)=0;
  if(!*(u8 *)(base+0x46)) D_80109A35=1;
  func_8000B9B8(header,*(s32*)(p+0x24)+(s32)D_54D910,0x20);
  *(s32*)records=(s32)header;
  if(!*(u8 *)(records+0x45)) {
   func_8000B9B8(buf1,*(s32*)header+(s32)D_54D910,*(u16*)(header+4)*12);
   func_8000B9B8(buf2,*(s32*)(header+8)+(s32)D_54D910,*(u16*)(header+0xC)*4);
   func_8000B9B8(buf3,*(s32*)(header+0x10)+(s32)D_54D910,*(u16*)(header+0x14)*12);
   func_8000B9B8(buf4,*(s32*)(p+0x28)+(s32)D_54D910,*(u16*)(p+0x2C)*12);
   if(func_8001499C(buf4)) func_80014A0C((s32)buf5,(s32)buf4);
   else memcpy(buf5,buf4,*(u16*)(header+0x14)*12);
   if(func_8001499C(buf1)) func_80014A0C((s32)buf2,(s32)buf1);
   else memcpy(buf2,buf1,*(u16*)(header+0x1C));
   if(func_8001499C(buf2)) func_80014A0C((s32)buf6,(s32)buf2);
   else memcpy(buf6,buf2,*(u16*)(header+0xC)*4);
   if(func_8001499C(buf3)) func_80014A0C((s32)buf7,(s32)buf3);
   else memcpy(buf7,buf3,*(u16*)(header+0x14)*4);
   *(s32*)(header+0x18)=(s32)buf2; *(s32*)header=(s32)buf5;
   *(s32*)(header+8)=(s32)buf6; *(s32*)(header+0x10)=(s32)buf7;
  } else {
   *(s32*)header=0; *(s32*)(header+8)=0; *(s32*)(header+0x10)=0;
  }
  func_800411C0(arg0,(s32)p,arg2);
 }
 func_80084048((s32)buf1,0x2D); func_80084048((s32)buf2,0x2D);
 func_80084048((s32)buf3,0x2D); func_80084048((s32)buf4,0x2D);
 func_80084048((s32)buf5,0x2D); func_80084048((s32)buf6,0x2D);
 func_80084048((s32)buf7,0x2D); func_80084048((s32)buf8,0x2D);
 func_800134C8(); func_80084048((s32)p,0x2D); func_80083E44(id);
}
