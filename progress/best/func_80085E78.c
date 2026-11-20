s32 func_8000A270(s32);
s32 func_8000A8B4(u16, f32, u8);
s32 func_8000A9CC(u16, s32, u8);
s32 func_8000AABC(s32, s32, void *, f32);
s32 func_8000AD5C(s32, s32);
s32 func_800175C0(s32, s32, s32, void *, f32, s32);
f32 func_80084270(void *, u16 *);
extern s32 D_80109688;
extern s32 D_80109A60;
void func_80085E78(void *arg0, void *arg1) {
u16 sp18; f32 temp_fv0,temp_fv1,temp_fv1_2,temp_fv1_3,var_fs0,var_fv0,var_fv1;
s32 temp_v0,temp_v0_3,temp_v0_4; u8 temp_v0_2,temp_v1; register s32 temp_v1_2; void *temp_a0,*temp_s0;
if (arg1 && (*(u16 *)((char*)arg1+0x14))) {
temp_a0=(char*)arg0+0x24;
if (*(u16*)((char*)arg0+0x78)==0xF) {
var_fv1=func_80084270(temp_a0,&sp18)-*(f32*)((char*)arg1+0xC);
if ((*(s32*)((char*)(*(s32*)((char*)&D_80109688+sp18*4))+0x100))&8) { if (*(u8*)((char*)arg1+0x1A)!=1) {} else goto block_7; }
else if (*(u8*)((char*)arg1+0x1A)==0) { block_7: var_fv1=65536.0f; }
temp_v1=*(u8*)((char*)arg1+0x18);
switch(temp_v1) {
case 0: if (var_fv1<*(f32*)((char*)arg1+0xC)) { temp_s0=(char*)arg0+0x24; temp_v0=func_8000A8B4(*(u16*)((char*)arg1+0x14),0,*(u8*)((char*)arg1+0x19)); temp_a0=(void*)temp_v0; *(s32*)arg1=(s32)temp_a0; func_8000AABC((s32)temp_a0,*(s32*)((char*)&D_80109688+sp18*4),temp_s0,0.0f); func_800175C0(*(s32*)((char*)arg0+0x20),2,0x20000,temp_s0,0.0f,1); *(u8*)((char*)arg1+0x18)=1; return;} break;
case 1: if (*(f32*)((char*)arg1+0x10)<var_fv1) { *(s32*)arg1=-1; *(u8*)((char*)arg1+0x18)=0; return;} break;
}
} else {
temp_v0_2=*(u8*)((char*)arg1+0x16);
if(temp_v0_2 && *((u8*)((char*)&D_80109A60+temp_v0_2))==*(u8*)((char*)arg1+0x17)) {func_8000A270(*(s32*)arg1); *(s32*)arg1=-1; return;}
var_fs0=func_80084270(temp_a0,&sp18); temp_fv1=*(f32*)((char*)arg1+0xC);
if ((*(s32*)((char*)(*(s32*)((char*)&D_80109688+sp18*4))+0x100))&8) {if(*(u8*)((char*)arg1+0x1A)==1)var_fs0=65536.0f;}
else if(*(u8*)((char*)arg1+0x1A)==0)var_fs0=65536.0f;
var_fv0=var_fs0-temp_fv1; if(var_fv0<0.0f)var_fv0=0.0f;
temp_fv1_2=*(f32*)((char*)arg1+0x10)-temp_fv1; if(temp_fv1_2<var_fv0)var_fv0=temp_fv1_2;
temp_fv0=var_fv0/temp_fv1_2; temp_fv1_3=127.0f-(temp_fv0*temp_fv0*127.0f);
temp_v1_2=*(u8*)((char*)arg1+0x18); *(f32*)((char*)arg1+4)=temp_fv1_3;
switch(temp_v1_2) {
case 0: if(temp_fv1_3>0.0f) {temp_v0_3=func_8000A9CC(*(u16*)((char*)arg1+0x14),(s32)temp_fv1_3,*(u8*)((char*)arg1+0x19)); *(s32*)arg1=temp_v0_3; func_8000AABC(temp_v0_3,*(s32*)((char*)&D_80109688+sp18*4),(char*)arg0+0x24,*(f32*)((char*)arg1+8)-var_fs0); *(f32*)((char*)arg1+8)=var_fs0; if(*(s32*)arg1!=-1)*(u8*)((char*)arg1+0x18)=1; if(*(u16*)((char*)arg0+0x78)==0x57){*(s32*)((char*)arg0+0x60)=*(s32*)((char*)arg0+0x60)|1;return;}} break;
case 1: temp_v0_4=func_8000AD5C(*(s32*)arg1,temp_fv1_3); *(s32*)arg1=(u32)temp_v0_4; if(temp_v0_4==-1){*(u8*)((char*)arg1+0x18)=0;return;} func_8000AABC(temp_v0_4,*(s32*)((char*)&D_80109688+sp18*4),(char*)arg0+0x24,*(f32*)((char*)arg1+8)-var_fs0); *(f32*)((char*)arg1+8)=var_fs0; break;
}
}
}
}
