void func_8001751C(s32, s32, void *, void *);
u32 randomIntBelow(s32);
void spawnSparkleLine(s32, s32, void *, void *);
void func_8005CFC8(char *a) {
 struct Vec { s32 x,y,z; } v; char *p;
 if ((*(s32 *)(a+0x58)&4 || *(s32 *)(a+0x60)&0x3000) && !randomIntBelow(*(s16 *)(a+0x7c))) {
 p=*(char **)(a+0x6c);
 v = *(struct Vec *)(a+0x24);
 func_8001751C(*(s32 *)p, *(u8 *)(p+5), &v, 0);
 spawnSparkleLine(*(s32 *)(a+0x20),1,&v,&v);
 }
 *(s32 *)(a+0x60)=0;
}
