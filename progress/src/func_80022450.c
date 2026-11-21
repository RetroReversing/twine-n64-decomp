extern void updateActiveMenuState(void);
extern void formatTextEntry(void *, const char *, ...);
extern char *lookupDataEntry(int);
extern unsigned char gOptionChoice;
extern char *gSaveMenuState;
void func_80022450(void) {
 int id;
 updateActiveMenuState();
 if (*(unsigned char *)(gSaveMenuState+0x2d)) {
 switch (gOptionChoice) {
 case 0: id=0x25; break;
 case 1: id=0x26; break;
 case 2: id=0x27; break;
 default: return;
 }
 formatTextEntry(*(char **)(gSaveMenuState+0x18)+0x28, "%s", lookupDataEntry(id));
 }
}
