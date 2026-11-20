void func_8001751C(s32, s32, void *, void *);
u32 func_80045CF8(s32);
void func_8005D070(s32, s32, void *, void *);
void func_8005CFC8(char *a) {
 struct Vec { s32 x,y,z; } v; char *p;
 if ((*(s32 *)(a+0x58)&4 || *(s32 *)(a+0x60)&0x3000) && !func_80045CF8(*(s16 *)(a+0x7c))) {
 p=*(char **)(a+0x6c);
 v = *(struct Vec *)(a+0x24);
 func_8001751C(*(s32 *)p, *(u8 *)(p+5), &v, 0);
 func_8005D070(*(s32 *)(a+0x20),1,&v,&v);
 }
 *(s32 *)(a+0x60)=0;
}
