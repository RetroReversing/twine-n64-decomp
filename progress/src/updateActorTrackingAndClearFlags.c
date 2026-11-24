extern u32 gRandomSeed;
s32 randomU16Next(void) { u32 temp_lo = gRandomSeed * 0xA8351D63; gRandomSeed=temp_lo; return (temp_lo >> 6) & 0xFFFF; }
s32 updateActorTrackingState(void *, s32);
/* Runs the actor's tracking update with its field at 0x6C, then keeps only bit 0 of its flags at 0x60. */ void updateActorTrackingAndClearFlags(void *actor) { updateActorTrackingState(actor, *(s32 *)((char *)actor+0x6C)); *(s32 *)((char *)actor+0x60) &= 1; }
s32 randomIntBelow(s32);
s32 playDistanceSound(u32,s32,s32);
extern u16 gRandomSoundIds[];
void playRandomDistanceSound(void) { playDistanceSound(gRandomSoundIds[randomIntBelow(4)],0,0xFF); }
s32 workerLockAcquire(void); s32 freeAudioStreamInfo(void); s32 workerLockRelease(void); extern u8 gWorkerThreadActive;
void releaseWorkerAudioStreamInfo(void) { if(gWorkerThreadActive) { workerLockAcquire(); freeAudioStreamInfo(); workerLockRelease(); } }
