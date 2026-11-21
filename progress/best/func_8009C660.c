extern void workerLockAcquire(void), workerLockRelease(void);
extern s32 soundResolveHandle(s32);
extern void voiceStoreParam(u8,u8,u8,u8);
extern u8 gWorkerActive;
extern s32 gVoiceChannelTable,D_8010D748,D_8010D784;
extern u8 D_8010D76F,D_8010D779;
s32 func_8009C660(s32 handle, s32 paramValue) {
 register s32 voiceIndex;
 s32 voiceOffset,voiceHandle,result,low,value,high;
 result=-1;
 voiceHandle=handle;
 value=paramValue;
 if(gWorkerActive != 0) {
  workerLockAcquire();
  voiceHandle=soundResolveHandle(voiceHandle);
  if(voiceHandle == result) goto unlock;
  high=(u16)value >> 7;
  low=value & 0x7f;
again:
  voiceIndex=voiceHandle & 0xff;
  voiceOffset=(s32)voiceIndex * 0x1a0;
  if(*(s32 *)((s8 *)&D_8010D784+voiceOffset) != voiceHandle) goto unlock;
  if(*(s32 *)((s8 *)&D_8010D748+voiceOffset)&2) {
   do { voiceStoreParam(1,voiceIndex,*(&D_8010D779+voiceOffset),high); } while (0);
   voiceStoreParam(33,voiceIndex,*(&D_8010D779+voiceOffset),low);
  } else {
   voiceStoreParam(1,voiceIndex,*(&D_8010D76F+voiceOffset),high);
   voiceStoreParam(33,voiceIndex,*(&D_8010D76F+voiceIndex*0x1a0),low);
  }
  result=0;
  voiceHandle=*(s32 *)((s8 *)&gVoiceChannelTable+voiceIndex*0x1a0);
  if(voiceHandle != -1) goto again;
unlock:
  workerLockRelease();
 }
 return result;
}
