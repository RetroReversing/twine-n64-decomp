extern void updateActiveMenuState(void);
extern void formatTextEntry(void *, const char *, ...);
extern char *lookupDataEntry(int);
extern unsigned char gPauseFlag;
extern char *gMenuItems;
void func_8001E6C8(void) {
 int id;
 updateActiveMenuState();
 if (*(unsigned char *)(gMenuItems+0x2d)) {
 switch (gPauseFlag) {
 case 0: id=10; break;
 case 1: id=0x2e2; break;
 case 2: id=0x2e3; break;
 default: id=0x2e4; break;
 }
 formatTextEntry(*(char **)(gMenuItems+0x18)+0x28, "%s", lookupDataEntry(id));
 }
}
