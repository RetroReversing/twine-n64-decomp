typedef struct Bank {u8 pad0[0x11A0]; u16 f11A0; u8 pad1[0x3B]; s8 f11DD; u8 pad2[0x22]; volatile u8 flags; u8 c1, c2, c3, c4; u8 pad3[3]; u32 d4; s32 ret; s32 p10; s32 p14; u8 cmd, d9; u8 pad4[2]; s32 dc; f32 e0; u8 pad5[4];} Bank;
extern u8 sDataBankInitialised; extern Bank sDataBanks[2];
extern u8 sDataBankMesgQueue[]; extern s32 sDataBankMode; extern void (*gDataBankFree)(s32); extern s32 func_80088EE4;
extern s32 startAudioVoice(u8,s32,s32,s32,u8,u8,u8,u8,s32,s32);
void func_8008863C(void) {
 s32 i; Bank *o;
 if (sDataBankInitialised) {
  osRecvMesg(sDataBankMesgQueue, 0, 1);
  for (i = 0; i < 2; i++) {
   if (sDataBanks[i].flags != 0) {
    o = &sDataBanks[i];
    func_8009D5D4(o);
    switch (sDataBanks[i].flags) {
    case 1:
     if (sDataBanks[i].f11DD == 2) {
      sDataBanks[i].dc = 0;
      sDataBanks[i].flags = 2;
      sDataBanks[i].e0 = ((f32)sDataBanks[i].f11A0 * 160.0f) / (f32)sDataBanks[i].d4;
      func_8009D9B8(o);
      o->ret = startAudioVoice(sDataBanks[i].c4, sDataBanks[i].p10, sDataBanks[i].p14, sDataBanks[i].d4, sDataBanks[i].c1, sDataBanks[i].c2, sDataBanks[i].c3, sDataBanks[i].d9, (s32)&func_80088EE4, i);
      if (o->ret == -1) {
       func_8009D9D8(o);
       goto freeit;
      }
     }
     break;
    case 2:
     if (sDataBanks[i].f11DD == 4) { sDataBanks[i].flags = 3; sDataBanks[i].cmd = 4; }
     break;
    case 3:
     if (sDataBanks[i].cmd == 0) {
freeit:
      if (!(sDataBankMode & 1)) gDataBankFree(sDataBanks[i].p10);
      sDataBanks[i].flags = 0;
     } else {
      if (sDataBanks[i].cmd == 2) { func_80093758(sDataBanks[i].ret); sDataBanks[i].ret = -1; }
      o->cmd = sDataBanks[i].cmd - 1;
     }
     break;
    }
   }
  }
  osSendMesg(sDataBankMesgQueue, 0, 0);
 }
}
