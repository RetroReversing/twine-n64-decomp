/* identical to pakQueryStatus in V-RALLY-PAL (local match library) (matched), with its names changed by decompdecomp */
typedef struct { s16 unk0; u8 unk2,unk3; } S_func_8008FA20_arg1;
extern u8 D_80101390[],D_80106C1E[];
extern s32 __osSiRawStartDma(); extern s32 osRecvMesg(s32,void*,s32);
/* Sends a joybus status request over SI DMA, waits for the reply on msgQueue, decodes the device status and returns the reply error code (0 when the device answered). */
s32 __osEepStatus(s32 msgQueue,S_func_8008FA20_arg1 *status) {
u8 cmdBuf[8]; u8 *cursor; s32 i,errCode; u8 *replyBuf; s32 *tail;
for(i=15,tail=(s32*)(D_80101390+0x869c);i>=0;i--) *tail--=0;
tail=(s32*)(D_80101390+0x869c); *tail=1;
cursor=(u8*)tail-0x3c; for(i=3;i>=0;i--) *cursor++=0;
cmdBuf[0]=255;cmdBuf[1]=1;cmdBuf[2]=3;cmdBuf[3]=0;cmdBuf[4]=255;cmdBuf[5]=255;cmdBuf[6]=255;cmdBuf[7]=255;
__builtin_memcpy(cursor,cmdBuf,8); replyBuf=D_80101390+0x8660;cursor[8]=254;
__osSiRawStartDma(1,replyBuf); osRecvMesg(msgQueue,0,1); D_80106C1E[0x3272]=254;
errCode=__osSiRawStartDma(0,replyBuf);osRecvMesg(msgQueue,0,1);
if(errCode==0){cursor=replyBuf;for(i=3;i>=0;i--)*cursor++=0;__builtin_memcpy(cmdBuf,cursor,8);
status->unk3=(cmdBuf[2]&0xc0)>>4;status->unk0=cmdBuf[4]|(cmdBuf[5]<<8);status->unk2=cmdBuf[6];return status->unk3 ? status->unk3:0;}
return errCode;
}
