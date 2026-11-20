extern void updateActiveMenuState(void);
extern void formatTextEntry(void *, const char *, ...);
extern char *func_80087100(int);
extern unsigned char gPauseFlag;
extern char *D_80109BB0;
void func_8001E6C8(void) {
 int id;
 updateActiveMenuState();
 if (*(unsigned char *)(D_80109BB0+0x2d)) {
 switch (gPauseFlag) {
 case 0: id=10; break;
 case 1: id=0x2e2; break;
 case 2: id=0x2e3; break;
 default: id=0x2e4; break;
 }
 formatTextEntry(*(char **)(D_80109BB0+0x18)+0x28, "%s", func_80087100(id));
 }
}
