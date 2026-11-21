extern void updateActiveMenuState(void);
extern void formatTextEntry(void *, const char *, ...);
extern char *lookupDataEntry(int);
extern unsigned char D_801002F2;
extern char *gMenuState;
void func_80022450(void) {
 int id;
 updateActiveMenuState();
 if (*(unsigned char *)(gMenuState+0x2d)) {
 switch (D_801002F2) {
 case 0: id=0x25; break;
 case 1: id=0x26; break;
 case 2: id=0x27; break;
 default: return;
 }
 formatTextEntry(*(char **)(gMenuState+0x18)+0x28, "%s", lookupDataEntry(id));
 }
}
