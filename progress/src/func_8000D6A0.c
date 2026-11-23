
f32 approxDistance(); s32 func_80082D24(); s32 buildRotationMatrixS16(); s32 MatMul3x3InPlace(); s32 func_800839F0(); extern char *gObjectRecords;
typedef struct { u32 x, y, z; } ObjectVectorWords;
void func_8000D6A0(s32 arg0){
ObjectVectorWords sp10; char *records = gObjectRecords;
f32 sp20[3]; s16 sp30[3]; f32 var_fv0;
s32 temp_a0_2, temp_s1, ph1, ph2;
u32 temp_a1, temp_v0_4;
void *temp_a0, *pobj, *temp_s3, *temp_v1, *temp_v0_3;
s32 off; char *recs;u32 tt,tw,ua,ub;
ph1 = (arg0*53)<<2;
temp_a0 = ph1 + records;
ph2 = *(u8*)((char*)temp_a0+0x98);
if (ph2 != 0xFF) {
  temp_s1 = (ph2*53)<<2;
  {
    typedef struct { char pad[0x68]; void *object; char pad2[0x2c]; u8 parent; } ObjectRecordFields;
    ObjectRecordFields *parentRecord=(ObjectRecordFields *)(records+temp_s1);
    ObjectRecordFields *childRecord=(ObjectRecordFields *)temp_a0;
    temp_s3=childRecord->object;
    pobj=parentRecord->object;
    if(parentRecord->parent==0xFF){
      parentRecord=0;
      sp30[0]=(s16)(s32)*(f32*)((char*)pobj+0x3C);
      sp30[1]=(s16)(s32)*(f32*)((char*)pobj+0x40);
      sp30[2]=(s16)(s32)*(f32*)((char*)pobj+0x44);
      buildRotationMatrixS16(sp30,(u32)temp_s1+(u32)records+0x9C);
    }
  }
  sp10 = *(ObjectVectorWords *)(gObjectRecords + ph1 + 0x14);
  {func_800839F0((u32)temp_s1+(u32)gObjectRecords+0x9C,&sp10,sp20);}
  sp20[0]+=*(f32*)((char*)pobj+0x24);
  sp20[1]+=*(f32*)((char*)pobj+0x28);
  sp20[2]+=*(f32*)((char*)pobj+0x2C);
  {typedef struct {u32 x,y,z;} V; *(V*)((char*)temp_s3+0x24)=*(V*)sp20;}
  tt=*(u32*)((char*)temp_s3+0x70);
  if(tt){
   tw=*(u32*)(tt+0x30);ua=tw>>4;ua&=0xFFFF;ub=tw>>20;
   if(((ub==0x11C)&(ua==0x1A))||((ub==0x98)&(ua==3))||((ub==0xB1)&(ua==2))){
    var_fv0=approxDistance(temp_s3+0x24,temp_s3+0x30);
    {f32 period = 2.7017698f;
     if(var_fv0>period)do{var_fv0-=period;}while(var_fv0>period);
     temp_v1=(void*)gObjectRecords;
     temp_v1=(void*)((char*)temp_v1+(s32)(arg0*0xD4));
     *(s16*)((char*)temp_v1+0x96)=(s16)(s32)((f32)*(s16*)((char*)temp_v1+0x96)+(var_fv0/period)*4096.0f);}
  }}
  sp30[0]=(s16)(s32)*(f32*)((char*)temp_s3+0x3C);
  sp30[1]=(s16)(s32)*(f32*)((char*)temp_s3+0x40);
  recs=gObjectRecords;
  off=arg0*0xD4;
  sp30[2]=(s16)(s32)(*(f32*)((char*)temp_s3+0x44)+(f32)*(s16*)((char*)(off+recs)+0x96));
  off=off+0x14;
  func_80082D24(sp30,recs+off+0x88);
  MatMul3x3InPlace((u32)ph2*0xD4+(u32)gObjectRecords+0x9C,gObjectRecords+off+0x88);
  *(s16*)((char*)temp_s3+0x7C)=arg0;
  *(s32*)((char*)temp_s3+0x58)|=0x40000;
}
}

