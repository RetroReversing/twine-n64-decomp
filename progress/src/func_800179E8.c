#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
s32 func_8001792C(); extern u16 gSurfaceQueryStamp;
void func_800179E8(s32 arg0,void *arg1,s32 arg2,s32 arg3){
 void *sp10[0x80];  u32 sp224;
 u32 temp_s7,var_s3,var_s6,first; void *temp_a0,*temp_s1,*temp_t0,*temp_t0_2,*var_s0;
 sp224=0; gSurfaceQueryStamp++; var_s6=0;
 if(arg1){
 if(arg3==0)arg2&=0xFFFCFFFF;
 func_8001792C(arg1,2,arg2|0x1000,arg0); M2C_FIELD(M2C_FIELD(arg1,void **,0x20),u16 *,0x60)=gSurfaceQueryStamp;
 if(arg3==1)arg2&=0xFFFCFFFF;
 var_s0=M2C_FIELD(M2C_FIELD(arg1,void **,0x20),void **,0x58);
 if(var_s0){do{temp_s1=M2C_FIELD(var_s0,void **,8);temp_t0=M2C_FIELD(temp_s1,void **,0x20);
 if(M2C_FIELD(temp_t0,u16 *,0x60)!=gSurfaceQueryStamp){M2C_FIELD(temp_t0,u16 *,0x60)=gSurfaceQueryStamp;func_8001792C(temp_s1,2,arg2|0x2000,arg0);sp10[var_s6]=temp_s1;var_s6++;}
 var_s0=M2C_FIELD(var_s0,void **,0);
 }while(var_s0);}
 if(arg3==2)arg2&=0xFFFCFFFF;
 first=sp224; temp_s7=var_s6; sp224=temp_s7; var_s3=first;
 for(;var_s3<temp_s7;var_s3++){var_s0=M2C_FIELD(M2C_FIELD(sp10[var_s3],void **,0x20),void **,0x58);
 if(var_s0){do{temp_s1=M2C_FIELD(var_s0,void **,8);temp_t0_2=M2C_FIELD(temp_s1,void **,0x20);
 if(M2C_FIELD(temp_t0_2,u16 *,0x60)!=gSurfaceQueryStamp){M2C_FIELD(temp_t0_2,u16 *,0x60)=gSurfaceQueryStamp;func_8001792C(temp_s1,2,arg2|0x4000,arg0);sp10[var_s6]=temp_s1;var_s6++;}
 var_s0=M2C_FIELD(var_s0,void **,0);
 }while(var_s0);}
 }
 if(arg3==3)arg2&=0xFFFCFFFF;
 var_s3=sp224; temp_s7=var_s6;
 if(var_s3<temp_s7){do{var_s0=M2C_FIELD(M2C_FIELD(sp10[var_s3],void **,0x20),void **,0x58);
 if(var_s0){do{temp_s1=M2C_FIELD(var_s0,void **,8);temp_a0=M2C_FIELD(temp_s1,void **,0x20);
 if(M2C_FIELD(temp_a0,u16 *,0x60)!=gSurfaceQueryStamp){M2C_FIELD(temp_a0,u16 *,0x60)=gSurfaceQueryStamp;func_8001792C(temp_s1,2,arg2|0x8000,arg0);}
 var_s0=M2C_FIELD(var_s0,void **,0);
 }while(var_s0);}
 var_s3++;
 }while(var_s3<temp_s7);}
 }
}
