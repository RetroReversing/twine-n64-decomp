extern void func_80029068(void);
extern void func_80026004(void *, const char *, ...);
extern char *func_80087100(int);
extern unsigned char D_801002D4;
extern char *D_80109BB0;
void func_8001E6C8(void) {
 int id;
 func_80029068();
 if (*(unsigned char *)(D_80109BB0+0x2d)) {
 switch (D_801002D4) {
 case 0: id=10; break;
 case 1: id=0x2e2; break;
 case 2: id=0x2e3; break;
 default: id=0x2e4; break;
 }
 func_80026004(*(char **)(D_80109BB0+0x18)+0x28, "%s", func_80087100(id));
 }
}
