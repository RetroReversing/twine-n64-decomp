extern u32 gRandomSeed;
s32 randomU16Next(void) { u32 temp_lo = gRandomSeed * 0xA8351D63; gRandomSeed=temp_lo; return (temp_lo >> 6) & 0xFFFF; }
s32 updateActorTrackingState(void *, s32);
void updateActorTrackingAndClearFlags(void *arg0) { updateActorTrackingState(arg0, *(s32 *)((char *)arg0+0x6C)); *(s32 *)((char *)arg0+0x60) &= 1; }
s32 randomIntBelow(s32);
s32 playDistanceSound(u32,s32,s32);
extern u16 gRandomSoundIds[];
void playRandomDistanceSound(void) { playDistanceSound(gRandomSoundIds[randomIntBelow(4)],0,0xFF); }
s32 workerLockAcquire(void); s32 freeAudioStreamInfo(void); s32 workerLockRelease(void); extern u8 gWorkerThreadActive;
/* If the sound worker is active, frees the audio stream info under the worker lock. */ void releaseWorkerAudioStreamInfo(void) { if(gWorkerThreadActive) { workerLockAcquire(); freeAudioStreamInfo(); workerLockRelease(); } }
