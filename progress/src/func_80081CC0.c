extern char D_80115092[];
void setBonusSlotState();
void func_80081CC0(s32 arg0) {
 s32 offset = arg0 * 0xA0;
 s32 v = *(s16 *)(D_80115092 + offset);
 *(s16 *)(D_80115092 + offset) = -1;
 setBonusSlotState(arg0, v);
}
