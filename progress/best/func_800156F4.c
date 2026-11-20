typedef s32 M2C_UNK;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
extern u16 D_800B35B0;
extern void *D_80102D68;
extern M2C_UNK D_80103F10;
extern void *D_80107E9C;
extern u32 D_80109E1C;
void func_800156F4(void) {
u8 __repair_frame[8]; M2C_UNK *var_a3; f32 temp_fv1,temp_fv1_2,temp_fv1_3,temp_fv1_4; s16 temp_v0; u32 var_t0; void **var_t1; void *temp_a2,*temp_v0_2,*temp_v0_3,*temp_v0_4,*temp_v1,*var_a0,*var_a1;
temp_v0=D_800B35B0+1; D_800B35B0=temp_v0; var_t0=0;
if(D_80109E1C!=0) { var_a3=&D_80103F10; var_t1=&D_80102D68;
do { temp_a2=*var_t1; temp_v1=M2C_FIELD(temp_a2,void **,0x20);
if(!(M2C_FIELD(temp_v1,u16 *,0x60)!=(temp_v0&0xFFFF))) {
temp_fv1=M2C_FIELD(var_a3,f32 *,0); if(temp_fv1<M2C_FIELD(temp_v1,f32 *,0)) M2C_FIELD(temp_v1,f32 *,0)=temp_fv1;
temp_v0_2=M2C_FIELD(temp_a2,void **,0x20); temp_fv1_2=M2C_FIELD(var_a3,f32 *,8); if(temp_fv1_2<M2C_FIELD(temp_v0_2,f32 *,8)) M2C_FIELD(temp_v0_2,f32 *,8)=temp_fv1_2;
temp_v0_3=M2C_FIELD(temp_a2,void **,0x20); temp_fv1_3=M2C_FIELD(var_a3,f32 *,4); if(M2C_FIELD(temp_v0_3,f32 *,4)<temp_fv1_3) M2C_FIELD(temp_v0_3,f32 *,4)=temp_fv1_3;
temp_v0_4=M2C_FIELD(temp_a2,void **,0x20); temp_fv1_4=M2C_FIELD(var_a3,f32 *,0xC); if(M2C_FIELD(temp_v0_4,f32 *,0xC)<temp_fv1_4) M2C_FIELD(temp_v0_4,f32 *,0xC)=temp_fv1_4;
block_24: var_a3+=4;
} else { M2C_FIELD(temp_v1,u16 *,0x60)=temp_v0;
M2C_FIELD(M2C_FIELD(temp_a2,void **,0x20),f32 *,0)=(f32)M2C_FIELD(var_a3,f32 *,0);
M2C_FIELD(M2C_FIELD(temp_a2,void **,0x20),f32 *,8)=(f32)M2C_FIELD(var_a3,f32 *,8);
M2C_FIELD(M2C_FIELD(temp_a2,void **,0x20),f32 *,4)=(f32)M2C_FIELD(var_a3,f32 *,4);
M2C_FIELD(M2C_FIELD(temp_a2,void **,0x20),f32 *,0xC)=(f32)M2C_FIELD(var_a3,f32 *,0xC);
var_a0=D_80107E9C; var_a1=NULL;
if(var_a0==NULL) { M2C_FIELD(temp_a2,void **,0x1C)=NULL; D_80107E9C=temp_a2; var_a3+=4; } else {
loop_17: if(!(M2C_FIELD(M2C_FIELD(temp_a2,void **,0x20),f32 *,0x54)<M2C_FIELD(M2C_FIELD(var_a0,void **,0x20),f32 *,0x54))) {
var_a1=var_a0; var_a0=M2C_FIELD(var_a1,void **,0x1C);
if(var_a0==NULL) { M2C_FIELD(var_a1,void **,0x1C)=temp_a2; M2C_FIELD(temp_a2,void **,0x1C)=NULL; goto block_24; } goto loop_17; }
M2C_FIELD(temp_a2,void **,0x1C)=var_a0;
if(var_a1!=NULL) { M2C_FIELD(var_a1,void **,0x1C)=temp_a2; goto block_24; }
D_80107E9C=temp_a2; var_a3+=4;
}
}/*__repair_loop_weight*/do {
var_t0+=1;} while (0); var_t1+=4;
} while(var_t0<(u32)D_80109E1C);
}
}
