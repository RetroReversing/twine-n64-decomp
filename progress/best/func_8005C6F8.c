extern s32 D_800C4470, D_800C4474;
extern u8 gPlayerActor[];
extern u8 gBonusObjectTable[];
void func_8005B5A8(void);
void func_8007092C(s32,s32);
void requestSound(s32);
void func_8005C6F8(void) {
s32 *a,*b, i, found, fallback; u32 w;
found=0;
if (gPlayerActor != 0) {
 fallback=0;
 if (*(void **)(gPlayerActor+0x70)!=0) {
 i=0; b=&D_800C4474; a=&D_800C4470;
 do {
 w=*(u32 *)(*(u8 **)(gPlayerActor+0x70)+0x30);
 if ((((w>>4)&0xffff)==*a) && ((w>>20)==*b) && (*(u16 *)(gPlayerActor+0x78)==0x12) && (*(s16 *)(gPlayerActor+0x7c)==0)) {
 *(s16 *)(gPlayerActor+0x7c)=1;
 *(s32 *)(gPlayerActor+0x60)|=0x08000000;
 requestSound(0x1d2); found=1; func_8007092C((s32)gBonusObjectTable,1);
 }
 b+=4; i++; a+=4;
 } while(i==0);
 goto done;
 }
} else {
done: fallback=found;
}
if(fallback==0) func_8005B5A8();
}
