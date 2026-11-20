extern void updateActiveMenuState(void);
extern void formatTextEntry(void *, const char *, ...);
extern char *func_80087100(int);
extern unsigned char D_801002F2;
extern char *D_80109BB0;
void func_80022450(void) {
 int id;
 updateActiveMenuState();
 if (*(unsigned char *)(D_80109BB0+0x2d)) {
 switch (D_801002F2) {
 case 0: id=0x25; break;
 case 1: id=0x26; break;
 case 2: id=0x27; break;
 default: return;
 }
 formatTextEntry(*(char **)(D_80109BB0+0x18)+0x28, "%s", func_80087100(id));
 }
}
