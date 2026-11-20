extern char D_80115092[];
void func_80081BC4();
void func_80081CC0(s32 arg0) {
 s32 offset = arg0 * 0xA0;
 s32 v = *(s16 *)(D_80115092 + offset);
 *(s16 *)(D_80115092 + offset) = -1;
 func_80081BC4(arg0, v);
}
