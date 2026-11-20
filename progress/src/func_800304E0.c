extern int func_80030108(void), func_8002FFAC(void);
extern void func_8002FBD4(void *, short);
void func_800304E0(int a, void *p) {
    int n;
    switch (*(short *)((char *)p + 0x7a)) {
    case 3: *(short *)((char *)p + 0x7a) = 1; break;
    case 1:
        if (func_80030108() & 255) func_8002FBD4(p, 2);
        break;
    case 0:
        if (func_8002FFAC() & 255) { n = 4; call: func_8002FBD4(p, n); }
        break;
    case 2: case 4: break;
    }
}
