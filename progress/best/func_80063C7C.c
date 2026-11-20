extern char D_800C469E[], D_800C46A0[], D_800C471C[];
s16 func_80063C7C(s16 arg0) {
 int var_a0 = arg0; s32 offset = var_a0 * 0xE8; s8 flag = *(s8 *)(D_800C46A0 + offset);
 u16 idx = *(u16 *)(D_800C469E + offset);
 if (flag && *(u8 *)(D_800C471C + offset) == *(u8 *)(D_800C471C + (s16)idx * 0xE8)) var_a0 = idx;
 return var_a0;
}
