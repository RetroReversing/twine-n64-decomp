s32 func_8009D9D8();
s32 osRecvMesg();
s32 osSendMesg();
extern char sDataBanks[], D_800E2CC0[], D_800E2CD0[], D_800E2CD8[], D_800E3F30[];
extern s32 sDataBankMode;
extern s32 (*gDataBankFree)(s32);
/* Advances a data bank slot's state: state 1 releases it via gDataBankFree, state 2 waits on the queue, finishes loading and signals completion. */ void processDataBankSlot(s32 slot) {
 u32 slotOffset = slot * 0x1228;
 switch (*(volatile unsigned char *)(D_800E2CC0 + slotOffset) & 0xff) {
 case 1:
  D_800E2CC0[slotOffset] = 0;
  if (!(sDataBankMode & 1)) { s32 value = *(volatile s32 *)(D_800E2CD0 + slotOffset); gDataBankFree((s32)value); }
  return;
 case 2:
  osRecvMesg(D_800E3F30, 0, 1);
  do {} while (0);
  func_8009D9D8(sDataBanks + slotOffset);
  ((volatile char *)D_800E2CC0)[slotOffset] = 3;
  D_800E2CD8[slot * 0x1228] = 4;
  osSendMesg((char *)&sDataBankMode + 4, 0, 0);
 }
}

