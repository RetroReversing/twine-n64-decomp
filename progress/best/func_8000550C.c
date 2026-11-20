extern f32 *D_800D93C0, *D_800D93CC, *D_800D93D8, *D_800D9404, *D_800D9408;
f32 func_8000550C(void *a, s32 i, s32 kind) {
 s32 flag = *(s32 *)(*(char **)((char *)a+0x68)+0x14) & 0x200000;
 f32 *p = 0;
 switch (kind) {
 case 0x15f: p = D_800D93C0; if (flag) p = D_800D9404; break;
 case 0x165: p = D_800D93CC; if (flag) p = D_800D9408; break;
 default: p = 0; break; case 0x16b: p = D_800D93D8; break;
 }
 { s32 bad = (p == NULL) | (i == 0); f32 value;
 if (bad) value = 0.0f;
 else value = p[i + 1];
 return value; }
}
