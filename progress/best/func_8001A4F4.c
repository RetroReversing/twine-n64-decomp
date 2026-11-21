extern int formatTextEntry(void *, const char *, ...);
extern int func_8002638C(void *, int);
extern int func_80027CE0(int);
extern int func_80087100(int);
extern void updateActiveMenuState(void);
extern unsigned char D_80112F7F,D_80112F80,D_80112F81;
extern void *gSaveMenuState;
extern signed char gSaveKeyRelaxed;
extern unsigned char gSceneType;
void func_8001A4F4(void) {
 int index;
 int selector;
 unsigned char newSelector;
 if (*((unsigned char *)gSaveMenuState+0x2f)==0) updateActiveMenuState();
 if (*((unsigned char *)gSaveMenuState+0x2d)!=0) {
  index=func_8002638C(*(void **)((char *)gSaveMenuState+0x10),0x5d);
  if(index!=0) {
   gSaveKeyRelaxed=0;
   selector=index+0x28;
   switch(gSceneType) {
   case 0:
    formatTextEntry((void *)index,"%s",func_80087100(0x81));
    formatTextEntry((void *)selector,"%s",func_80087100(0x8a));
    break;
   case 1:
    gSaveKeyRelaxed=1;
    formatTextEntry((void *)index,"%s",func_80087100(0x82));
    formatTextEntry((void *)selector,"%s",func_80087100(0x8b));
    break;
   case 2:
    gSaveKeyRelaxed=1;
    formatTextEntry((void *)index,"%s",func_80087100(0x84));
    formatTextEntry((void *)selector,"%s",func_80087100(0x8d));
    break;
   case 3:
    gSaveKeyRelaxed=1;
    formatTextEntry((void *)index,"%s",func_80087100(0x85));
    formatTextEntry((void *)selector,"%s",func_80087100(0x8e));
    if(D_80112F80==0) {
     *((unsigned char *)gSaveMenuState+0x2f)=1;
     if(func_80027CE0(0x21)&0xff) newSelector=gSceneType+1;
     else newSelector=gSceneType-1;
     gSceneType=newSelector;
     func_8001A4F4();
    }
    break;
   case 4:
    formatTextEntry((void *)index,"%s",func_80087100(0x83));
    formatTextEntry((void *)selector,"%s",func_80087100(0x8c));
    break;
   case 5:
    gSaveKeyRelaxed=1;
    formatTextEntry((void *)index,"%s",func_80087100(0x182));
    formatTextEntry((void *)selector,"%s",func_80087100(0x183));
    if(D_80112F7F==0) {
     *((unsigned char *)gSaveMenuState+0x2f)=1;
     if(func_80027CE0(0x21)&0xff) newSelector=gSceneType+1;
     else newSelector=gSceneType-1;
     gSceneType=newSelector;
     func_8001A4F4();
    }
    break;
   case 6:
    gSaveKeyRelaxed=1;
    formatTextEntry((void *)index,"%s",func_80087100(0x87));
    formatTextEntry((void *)selector,"%s",func_80087100(0x90));
    break;
   case 7:
    formatTextEntry((void *)index,"%s",func_80087100(0x86));
    formatTextEntry((void *)selector,"%s",func_80087100(0x8f));
    break;
   case 8:
    formatTextEntry((void *)index,"%s",func_80087100(0x88));
    formatTextEntry((void *)selector,"%s",func_80087100(0x91));
    if(D_80112F81==0) {
     *((unsigned char *)gSaveMenuState+0x2f)=1;
     if(func_80027CE0(0x21)&0xff) gSceneType=0;
     else gSceneType--;
     func_8001A4F4();
    }
    break;
   }
  } else *((unsigned char *)gSaveMenuState+0x2f)=0;
 } else *((unsigned char *)gSaveMenuState+0x2f)=0;
}
