void *spawnEffectObject(s32, s32, s32); s32 objectListInsert(void *, s32); s32 effectSetAnimFrame(void *, s32, s32); s32 randomIntBelow(s32); f32 randomFloatScaled(f32); f32 randomFloatMinusOffset(f32, f32); extern f64 D_800D4148;
/* Spawns count effect objects at random offsets within radius, each with random velocity and animation */ void spawnRandomEffectBurst(void *arg0, s32 arg1, f32 arg2, u32 arg3, s32 arg4, s32 arg5) {
 f32 halfRadius; f64 temp_fs1, var_fv0, var_fv0_2; register f64 var_fv0_3; unsigned int temp_v0_2; unsigned temp_v0_3; u32 temp_v0_4; register void *temp_v0; register void *temp_s1; u32 i;
 i=0; halfRadius=arg2*0.5f;
 temp_fs1=D_800D4148;for(;i<arg3;i++){temp_v0=spawnEffectObject(0x20,arg1,0);if(temp_v0!=NULL){temp_s1=*(void **)((char *)temp_v0+0x6C);*(u16 *)((char *)temp_v0+0x78)=0x66;*(u16 *)((char *)temp_s1+0x1C)=0x3C;*(u16 *)((char *)temp_v0+0x7A)=0;*(f32 *)((char *)temp_v0+0x54)=(f32)(randomFloatScaled(0.25f)+0.25f);*(f32 *)((char *)temp_s1+4)=randomFloatMinusOffset(arg2,halfRadius);*(f32 *)((char *)temp_s1+8)=randomFloatMinusOffset(arg2,halfRadius);*(f32 *)((char *)temp_s1+0xC)=randomFloatMinusOffset(arg2,halfRadius);
 temp_v0_2=randomIntBelow(0x100)-0x80;var_fv0=(f64)temp_v0_2;if(temp_v0_2<0)var_fv0+=temp_fs1;*(f32 *)((char *)temp_s1+0x10)=(f32)var_fv0;
 temp_v0_3=randomIntBelow(0x100)-0x80;var_fv0_2=(f64)temp_v0_3;if(temp_v0_3<0)var_fv0_2+=temp_fs1;*(f32 *)((char *)temp_s1+0x14)=(f32)var_fv0_2;
 temp_v0_4=randomIntBelow(0x100)-0x80;var_fv0_3=(f64)temp_v0_4;if(temp_v0_4<0)var_fv0_3+=temp_fs1;*(f32 *)((char *)temp_s1+0x18)=(f32)var_fv0_3;
 *(u8 *)((char *)temp_v0+0x7F)=0;*(u8 *)((char *)temp_v0+0x81)=0xFF;*(u8 *)((char *)temp_v0+0x80)=0;*(s32 *)((char *)temp_v0+0x58)|=0x10000;effectSetAnimFrame(temp_v0,arg4,arg5);objectListInsert(temp_v0,*(s32 *)((char *)arg0+0x20));}}
}
