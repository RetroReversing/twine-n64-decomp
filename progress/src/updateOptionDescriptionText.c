extern void updateActiveMenuState(void);
extern void formatTextEntry(void *, const char *, ...);
extern char *lookupDataEntry(int);
extern unsigned char gOptionChoice;
extern char *gSaveMenuState;
/* Writes the description string for the selected option (0-2) into the save menu's text buffer. */ void updateOptionDescriptionText(void) {
 int textId;
 updateActiveMenuState();
 if (*(unsigned char *)(gSaveMenuState+0x2d)) {
 switch (gOptionChoice) {
 case 0: textId=0x25; break;
 case 1: textId=0x26; break;
 case 2: textId=0x27; break;
 default: return;
 }
 formatTextEntry(*(char **)(gSaveMenuState+0x18)+0x28, "%s", lookupDataEntry(textId));
 }
}
