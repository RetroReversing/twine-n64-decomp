typedef struct Obj {u8 pad[0x120C]; s32 ret; u8 pad2[8]; u8 cmd;} Obj;
extern u8 sDataBankInitialised; extern f64 D_800D66D0; extern u8 sDataBanks[]; extern u8 D_800E2CC0[], D_800E2CC1[], D_800E2CC2[], D_800E2CC3[], D_800E2CC4[], D_800E2CC8[], D_800E2CCC[], D_800E2CD0[], D_800E2CD4[], D_800E2CD8[], D_800E2CD9[], D_800E2CDC[], D_800E2CE0[], D_800E2C60[], D_800E2C9D[];
extern u8 sDataBankMesgQueue[]; extern s32 sDataBankMode; extern void (*gDataBankFree)(s32); extern s32 func_80088EE4;
extern s32 startAudioVoice(u8,s32,s32,s32,u8,u8,u8,u8,s32,s32);
#define F(T,s,o) (*(T*)((u8*)(s)+(o)))
void func_8008863C(void) {
 s32 i, off; Obj *o;
 if (sDataBankInitialised) {
  osRecvMesg(sDataBankMesgQueue, 0, 1);
  for (i = 0, off = 0; i < 2; i++, off += 0x1228) {
   if (D_800E2CC0[off] != 0) {
    o = (Obj*)(sDataBanks + off);
    func_8009D5D4(o);
    switch (D_800E2CC0[off]) {
    case 1:
     if (F(s8,D_800E2C9D,off) == 2) {
      u32 t = F(u32,D_800E2CC8,off);
      F(s32,D_800E2CDC,off) = 0;
      D_800E2CC0[off] = 2;
      F(f32,D_800E2CE0,off) = ((f32)F(u16,D_800E2C60,off) * 160.0f) / (f32)t;
      func_8009D9B8(o);
      o->ret = startAudioVoice(D_800E2CC4[off], F(s32,D_800E2CD0,off), F(s32,D_800E2CD4,off), F(s32,D_800E2CC8,off), D_800E2CC1[off], D_800E2CC2[off], D_800E2CC3[off], D_800E2CD9[off], (s32)&func_80088EE4, i);
      if (o->ret == -1) {
       func_8009D9D8(o);
       goto freeit;
      }
     }
     break;
    case 2:
     if (F(s8,D_800E2C9D,off) == 4) { D_800E2CC0[off] = 3; D_800E2CD8[off] = 4; }
     break;
    case 3:
     if (D_800E2CD8[off] == 0) {
freeit:
      if (!(sDataBankMode & 1)) gDataBankFree(F(s32,D_800E2CD0,off));
      D_800E2CC0[off] = 0;
     } else {
      if (D_800E2CD8[off] == 2) { func_80093758(F(s32,D_800E2CCC,off)); F(s32,D_800E2CCC,off) = -1; }
      o->cmd = D_800E2CD8[off] - 1;
     }
     break;
    }
   }
  }
  osSendMesg(sDataBankMesgQueue, 0, 0);
 }
}
