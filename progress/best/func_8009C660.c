extern s32 soundResolveHandle(s32);
extern s32 voiceStoreParam(s32,s32,u8,s32);
extern void workerLockAcquire(void),workerLockRelease(void);
extern s32 D_8010D748,D_8010D784,gVoiceChannelTable;
extern u8 D_8010D76F,D_8010D779,gWorkerActive;
s32 func_8009C660(s32 arg0,s32 arg1) {
 s32 index,offset,handle,ret=-1;
 u32 high;
 u8 channel;
 if(gWorkerActive) {
  workerLockAcquire();
  handle=soundResolveHandle(arg0);
  if(handle!=-1) {
   high=(u32)(arg1&0xffff)>>7;
   again: {
    index=handle&255;
    offset=index*0x1a0;
    if(*(s32*)((u8*)&D_8010D784+offset)!=handle) goto done;
    if(*(s32*)((u8*)&D_8010D748+offset)&2) {
     voiceStoreParam(1,index,*(&D_8010D779+offset),high&255);
     channel=*(&D_8010D779+offset);
    } else {
     voiceStoreParam(1,index,*(&D_8010D76F+offset),high&255);
     channel=*(&D_8010D76F+offset);
    }
    voiceStoreParam(0x21,index,channel,arg1&127);
    handle=*(s32*)((u8*)&gVoiceChannelTable+offset);
    ret=0;
   if(handle!=-1) goto again;
   }
   done:;
  }
  workerLockRelease();
 }
 return ret;
}
