s32 func_8009D9D8();
s32 osRecvMesg();
s32 osSendMesg();
extern char sDataBanks[], D_800E2CC0[], D_800E2CD0[], D_800E2CD8[], D_800E3F30[];
extern s32 sDataBankMode;
extern s32 (*gDataBankFree)(s32);
void func_800882D0(s32 arg0) {
 u32 off = arg0 * 0x1228;
 switch (*(volatile unsigned char *)(D_800E2CC0 + off) & 0xff) {
 case 1:
  D_800E2CC0[off] = 0;
  if (!(sDataBankMode & 1)) { s32 value = *(volatile s32 *)(D_800E2CD0 + off); gDataBankFree((s32)value); }
  return;
 case 2:
  osRecvMesg(D_800E3F30, 0, 1);
  do {} while (0);
  func_8009D9D8(sDataBanks + off);
  ((volatile char *)D_800E2CC0)[off] = 3;
  D_800E2CD8[arg0 * 0x1228] = 4;
  osSendMesg((char *)&sDataBankMode + 4, 0, 0);
 }
}

