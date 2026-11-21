extern s32 func_8000A8B4(u16,f32,s32); extern u32 randomIntBelow(s32); extern f32 func_80084270(s32,s16 *); extern u16 D_800CE700[];
void func_80084E10(s32 arg0) { s16 sp10; f32 f=func_80084270(arg0,&sp10); func_8000A8B4(D_800CE700[randomIntBelow(2)],f,255); }
