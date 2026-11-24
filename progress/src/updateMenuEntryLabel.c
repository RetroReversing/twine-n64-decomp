extern void updateActiveMenuState(void);
extern void formatTextEntry(void *, const char *, ...);
extern char *lookupDataEntry(int);
extern unsigned char gPauseFlag;
extern char *gSaveMenuState;
/* Updates the active menu, then if the menu is enabled, writes a label string chosen by gPauseFlag into the menu's text entry. */ void updateMenuEntryLabel(void) {
 int textId;
 updateActiveMenuState();
 if (*(unsigned char *)(gSaveMenuState+0x2d)) {
 switch (gPauseFlag) {
 case 0: textId=10; break;
 case 1: textId=0x2e2; break;
 case 2: textId=0x2e3; break;
 default: textId=0x2e4; break;
 }
 formatTextEntry(*(char **)(gSaveMenuState+0x18)+0x28, "%s", lookupDataEntry(textId));
 }
}
