#ifndef M2C_DEFINES
#define M2C_DEFINES
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32;
#define M2C_FIELD(expr,type_ptr,offset) (*(type_ptr)((s8 *)(expr)+(offset)))
#define M2C_BITWISE(type,expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define M2C_CARRY 0
#define M2C_OVERFLOW(a) (0)
#endif
void *func_8005D3D0(s32,u8);
M2C_UNK func_800617D8(s32,M2C_UNK,M2C_UNK,M2C_UNK,f32,f32,s32,s32,s32,s32,s32);
M2C_UNK func_80084338(s32,s32);
extern void *D_80102FD8; extern void *D_80108788; extern s32 D_80108F78; extern u8 D_80109A60[]; extern void *D_8010A500;
typedef struct { s32 w[3]; } __repair_words3;
void func_8005BF84(void *arg0,M2C_UNK unused,M2C_UNK arg2) {
 s32 temp_v1_3; s8 var_s0; u16 temp_v0,temp_v0_2,temp_v1; void *temp_t0,*temp_v1_2;
 func_800617D8(M2C_FIELD(arg0,s32 *,0x20),arg2,0,0,1.0f,1.0f,0xA,0x1B,0x22,0xFFFF0080,0x78748010);
 if(D_80108788!=NULL) {
  temp_v1=M2C_FIELD(D_80108788,u16 *,0x78); var_s0=temp_v1==0x60; if(temp_v1==0x5f)var_s0=1; if(temp_v1==0x5e)var_s0=1;
  if(temp_v1==0x12) if(M2C_FIELD(M2C_FIELD(D_80108788,void **,0x6c),s32 *,0x2c)&2) { temp_v0=M2C_FIELD(D_80108788,u16 *,0x7c)+1; M2C_FIELD(D_80108788,u16 *,0x7c)=temp_v0; if((s16)temp_v0==5) { M2C_FIELD(D_80108788,u16 *,0x7c)=6; M2C_FIELD(D_80108788,s32 *,0x60)|=2; func_80084338(0x117,(s32)arg2); } }
  if(var_s0) { if(D_80108F78==0x1d) { temp_v0_2=M2C_FIELD(M2C_FIELD(D_80108788,void **,0x6c),u16 *,0x34); if(temp_v0_2!=0) *(D_80109A60+temp_v0_2)=0; } M2C_FIELD(D_80108788,u16 *,0x78)=0x5a; func_8005D3D0(arg2,0xF); }
 }
 if((D_80102FD8!=NULL)&&(M2C_FIELD(D_80102FD8,u16 *,0x78)==1)&&(M2C_FIELD(D_80102FD8,s16 *,0x7a)!=0x2d)) {
  temp_t0=M2C_FIELD(D_80102FD8,void **,0x6c); temp_v1_2=M2C_FIELD(arg0,void **,0x6c);
  M2C_FIELD(temp_t0,__repair_words3 *,0x50)=*(__repair_words3 *)((s8 *)D_8010A500+0x24);
  M2C_FIELD(temp_t0,f32 *,0x60)+=M2C_FIELD(M2C_FIELD(temp_v1_2,void **,0x2c),f32 *,0xc);
  M2C_FIELD(temp_t0,s32 *,0x64)=M2C_FIELD(M2C_FIELD(temp_v1_2,void **,0x2c),u8 *,1);
  M2C_FIELD(temp_t0,s32 *,0x68)=M2C_FIELD(temp_v1_2,s32 *,0x24);
  if(M2C_FIELD(temp_t0,f32 *,0x60)<0.0f) M2C_FIELD(temp_t0,f32 *,0x60)=0.0f;
  temp_v1_3=((u32)M2C_FIELD(temp_t0,u32 *,0x88)>>0x15)&0xf;
  if(temp_v1_3<4) if(temp_v1_3>=2) M2C_FIELD(temp_t0,f32 *,0x60)+=4.0f;
  M2C_FIELD(D_80102FD8,s32 *,0x60)|=2;
 }
}
