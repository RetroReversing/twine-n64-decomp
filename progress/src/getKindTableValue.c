extern f32 *D_800D93C0, *D_800D93CC, *D_800D93D8, *D_800D9404, *D_800D9408;
/* Returns table[index + 1] from the float table chosen by kindId (alternate table when the flag in the object's data is set), or 0 if the table is missing or index is 0. */
f32 getKindTableValue(void *object, s32 index, s32 kindId) {
 s32 altTableFlag = *(s32 *)(*(char **)((char *)object+0x68)+0x14) & 0x200000;
 f32 *table = 0;
 switch (kindId) {
 default: table = 0; break; case 0x15f: table = D_800D93C0; if (altTableFlag) table = D_800D9404; break;
 case 0x165: table = D_800D93CC; if (altTableFlag) table = D_800D9408; break;
 case 0x16b: table = D_800D93D8; break;
 }
 { s32 invalid = (table == NULL) | (index == 0); f32 result;
 if (invalid) result = 0.0f;
 else result = table[index + 1];
 return result; }
}
