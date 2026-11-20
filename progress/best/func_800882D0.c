s32 func_8009D9D8();
s32 osRecvMesg();
s32 osSendMesg();
extern char D_800E1AC0[], D_800E2CC0[], D_800E2CD0[], D_800E2CD8[], D_800E3F30[];
extern s32 D_800E3F2C;
extern s32 (*D_80100180)(s32);
void func_800882D0(s32 arg0) {
 s32 off = arg0 * 0x1228;
 switch (*(volatile unsigned char *)(D_800E2CC0 + off) & 0xff) {
 case 1:
  D_800E2CC0[off] = 0;
  if (!(D_800E3F2C & 1)) { s32 value = *(volatile s32 *)(D_800E2CD0 + off); D_80100180(value); }
  return;
 case 2:
  osRecvMesg(D_800E3F30, 0, 1);
  func_8009D9D8(D_800E1AC0 + off);
  D_800E2CC0[off] = 3;
  D_800E2CD8[off] = 4;
  osSendMesg(D_800E3F30, 0, 0);
 }
}
