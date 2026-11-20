s32 func_80015D40(s32);
void *func_80016410(s32,s32,s32);
s32 func_8003E6EC(s32,void *,s32);
void func_80044670(void *,s32,s32);
extern s32 *D_800CA31C;
extern f64 D_800D4170;
extern s8 D_80109A60[19];
extern s8 D_80109B1E;
typedef struct { s32 w[3]; } __repair_words3;
typedef struct { f32 v[3]; } __repair_vec3;
typedef struct { unsigned char pad0[36]; s32 x,y,z; unsigned char pad30[12]; f32 a,b,c; unsigned char pad48[20]; s32 flags; unsigned char pad60[12]; void *sub; unsigned char pad70[8]; s16 t,u,v; } R;
void *func_8005DC2C(s32 arg0,s32 arg1,void *arg2,void *arg3) {
    s8 *__base_D_80109B1E;
 s16 var_v0; s32 temp_v1,var_a1; u16 var_a2,temp_v0_2; void *temp_s0,*temp_v0;
 temp_v0=func_80016410(0x50,arg0,arg1);
 if(temp_v0!=NULL) {
  temp_s0=((R*)temp_v0)->sub;
  (*(s32*)((char*)temp_s0+0x4C)) &= ~0x40;
  temp_v1=*(u8*)((char*)(*(void**)((char*)arg2+0x24))+0x1E);
  switch(temp_v1) {
  default: var_v0=0x11; if(temp_v1==0x2D) ((R*)temp_v0)->t=var_v0; break;
  case 0x90: (*__base_D_80109B1E)=1; ((R*)temp_v0)->t=0x60; break;
  case 0x8E: (*(__base_D_80109B1E = &D_80109B1E))=1; ((R*)temp_v0)->t=0x5F; break;
  case 0x2F: ((R*)temp_v0)->t=0x12; break;
  }
  *(u16*)((char*)temp_s0+0x34)=*(u16*)((char*)arg2+0x2C);
  *(u16*)((char*)temp_s0+0x40)=*(u16*)((char*)arg2+0x2E);
  *(s32*)((char*)temp_s0+0x2C)=func_80015D40(*(u16*)((char*)arg2+0x34));
  *(u16*)((char*)temp_s0+0x36)=*(u16*)((char*)arg2+0x36);
  *(u16*)((char*)temp_s0+0x38)=*(u16*)((char*)arg2+0x38);
  *(u16*)((char*)temp_s0+0x3A)=*(u16*)((char*)arg2+0x30);
  *(u16*)((char*)temp_s0+0x3C)=*(u16*)arg2;
  *(u16*)((char*)temp_s0+0x3E)=**(u16**)((char*)arg2+0x28);
  *(s16*)((char*)temp_s0+0x42)=0;
  if(*(u16*)((char*)temp_s0+0x3A)==1) { var_a2=*(u16*)((char*)temp_s0+0x3E); var_a1=*(u16*)((char*)temp_s0+0x3C); var_a1+=*(u16*)(D_80109A60+*(u16*)((char*)temp_s0+0x34)); func_80044670(temp_v0,var_a1,(s16)var_a2); }
  else { var_a1=*(u16*)arg2; var_a2=(u16)(s16)**(u16**)((char*)arg2+0x28); func_80044670(temp_v0,var_a1,(s16)var_a2); }
  if(*(u16*)((char*)arg2+0x40)==0) *(s32*)((char*)temp_s0+0x4C)|=0x80; else *(s32*)((char*)temp_s0+0x4C)&=~0x80;
  D_80109A60[*(u16*)((char*)temp_s0+0x34)]=(s8)*(u16*)((char*)arg2+0x32);
  *(void**)((char*)temp_s0+4)=arg3;
  temp_v0_2=*(u16*)((char*)arg2+4); *(u16*)((char*)temp_s0+0x44)=temp_v0_2; if(!temp_v0_2) *(u16*)((char*)temp_s0+0x44)=0x3C;
  *(s8*)((char*)temp_s0+0x4B)=0;
  *(s32*)((char*)temp_s0+0x4C)=(s8)(*(u8*)((char*)arg2+3)-1);
  *(f32*)((char*)temp_s0+8)=1.0f;
  if(arg3!=NULL) { ((R*)temp_v0)->x=*(s32*)arg3; ((R*)temp_v0)->z=*(s32*)((char*)arg3+8); ((R*)temp_v0)->y=*(s32*)((char*)arg3+4); ((R*)temp_v0)->a=(f32)((f64)*(f32*)((char*)arg3+0xC)*D_800D4170); ((R*)temp_v0)->b=(f32)((f64)*(f32*)((char*)arg3+0x10)*D_800D4170); ((R*)temp_v0)->c=(f32)((f64)*(f32*)((char*)arg3+0x14)*D_800D4170); }
  *(__repair_words3*)((char*)temp_v0+0x30)=*(__repair_words3*)((char*)temp_v0+0x24);
  *(__repair_vec3*)((char*)temp_v0+0x48)=*(__repair_vec3*)((char*)temp_v0+0x3C);
  ((R*)temp_v0)->u=0; ((R*)temp_v0)->v=0; ((R*)temp_v0)->flags|=0x600;
  func_8003E6EC(*D_800CA31C,temp_v0,1);
 }
 return temp_v0;
}
