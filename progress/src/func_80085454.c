extern u32 D_800CF550;
s32 func_80095638(void) { u32 temp_lo = D_800CF550 * 0xA8351D63; D_800CF550=temp_lo; return (temp_lo >> 6) & 0xFFFF; }
s32 updateActorTrackingState(void *, s32);
void func_800861F8(void *arg0) { updateActorTrackingState(arg0, *(s32 *)((char *)arg0+0x6C)); *(s32 *)((char *)arg0+0x60) &= 1; }
s32 func_80045CF8(s32);
s32 func_8000A8B4(u32,s32,s32);
extern u16 D_800CE774[];
void func_80085454(void) { func_8000A8B4(D_800CE774[func_80045CF8(4)],0,0xFF); }
s32 func_8008C0D4(void); s32 func_8008C688(void); s32 func_8008C11C(void); extern u8 gWorkerActive;
void func_8009D058(void) { if(gWorkerActive) { func_8008C0D4(); func_8008C688(); func_8008C11C(); } }
