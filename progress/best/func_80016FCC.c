typedef void (*FnP)(void *);
extern u8 D_800B35C0[];
extern s16 D_800C9D42;
extern u8 D_800CA310;
extern u8 D_800CA338;
extern u8 D_801002AE;
extern s8 gBorderSkipFlag;
extern u8 D_80102EFC[];
extern s8 D_80103EB0;
extern s32 D_80108F78;
extern void *gTrackMarkerTable[];
extern void *D_8010A410;
extern void *D_8010A500;
extern s8 D_80115319;
void func_80016718(void *, void *);
void func_80016740(void *);
void func_800167B4(void *);
void func_80016990(void *, s32);
void func_80016A34(void *);
void func_80016EE0(void);
void func_80027260(void *);
void func_8002B050(void *, s32);
void func_8002EAC4(void *);
void func_8004830C(void);
void func_80069DCC(void *);
void func_8007BA98(void);
void func_80117740(void);
void func_801177AC(void);
void func_801177B0(void);
void func_801177D4(void);
void func_80117A18(void);
void func_80117B58(void);
void func_80118098(void);
void func_80118110(void);
void func_801181B0(void);
void func_80118228(void);
void func_8011E634(void);

void func_80016FCC(s8 arg0) {
    FnP fn;
    u8 *s2;
    s32 s1;
    void *node;
    void *p;
    
    s16 t;

    D_80115319 = arg0;
    func_80016EE0();
    if (D_801002AE == 0 && D_800CA338 == 0 && D_80103EB0 != 0) {
        func_8002B050(D_80102EFC, 1);
    }
    s1 = 0;
    if (D_800C9D42 == 0) {
        func_8007BA98();
        node = D_8010A410;
        if (D_801002AE == 0) {
            s2 = D_800B35C0;
            if (D_800CA338 != 0) {
                s2 = D_800B35C0 + 4;
            }
            while (node != NULL) {
                fn = *(FnP *)(s2 + *(u16 *)((u8 *)node + 0x78) * 8);
                if (fn != NULL) {
                    if (*(s32 *)((u8 *)node + 0x58) & 1) {
                        func_80016A34(node);
                    } else {
                        *(s32 *)((u8 *)node + 0x30) = *(s32 *)((u8 *)node + 0x24);
                        *(s32 *)((u8 *)node + 0x34) = *(s32 *)((u8 *)node + 0x28);
                        *(s32 *)((u8 *)node + 0x38) = *(s32 *)((u8 *)node + 0x2C);
                        *(s32 *)((u8 *)node + 0x48) = *(s32 *)((u8 *)node + 0x3C);
                        *(s32 *)((u8 *)node + 0x4C) = *(s32 *)((u8 *)node + 0x40);
                        *(s32 *)((u8 *)node + 0x50) = *(s32 *)((u8 *)node + 0x44);
                    }
                    fn(node);
                }
                node = *(void **)((u8 *)node + 0x10);
            }
            if (D_800CA338 == 0 && D_8010A500 != NULL && ((t = *(s16 *)((u8 *)D_8010A500 + 0x7A)) >= 4 || t < 2)) {
                switch (D_80108F78) {
                case 25: s1 = 0; func_80118098(); break;
                case 20: s1 = 0; func_801181B0(); break;
                case 28: s1 = 0; func_80117740(); break;
                case 16: s1 = 0; func_801177B0(); break;
                case 34: s1 = 0; func_801177AC(); break;
                case 29: s1 = 0; func_80118110(); break;
                case 33: s1 = 0; func_80117740(); break;
                case 18: s1 = 0; func_80117B58(); break;
                case 38: s1 = 0; func_80117A18(); break;
                case 2: s1 = 0; func_80118228(); break;
                case 11: s1 = 0; func_801177D4(); break;
                case 41: s1 = 0; func_80117740(); break;
                case 40: s1 = 0; func_80117740(); break;
                }
            } else {
                s1 = 0;
            }
        } else {
            while (node != NULL) {
                switch (*(u16 *)((u8 *)node + 0x78)) {
                case 0x25: func_80027260(node); break;
                default: func_8002EAC4(node); break;
                case 0x4D:
                case 0x2: func_80069DCC(node); break;
                }
                node = *(void **)((u8 *)node + 0x10);
            }
            s1 = 0;
        }
    }
    p = (void *)gTrackMarkerTable;
    do {
        p = gTrackMarkerTable[s1];
        s1 += 1;
        if (p != NULL && *(s32 *)((u8 *)p + 0xFC) == 0) {
            func_8004830C();
        }
    } while (s1 < 6);
    node = D_8010A410;
    while (node != NULL) {
        p = *(void **)((u8 *)node + 0x10);
        if (!(*(s32 *)((u8 *)node + 0x60) & 1)) {
            u16 ty = *(u16 *)((u8 *)node + 0x78);
            if (ty == 0x30 || ty == 0x50) {
                void *tgt = *(void **)((u8 *)node + 0x18);
                if (tgt != NULL) {
                    s32 v;
                    if (*(s32 *)((u8 *)node + 0x58) & 0x1000) {
                        u16 tt = *(u16 *)((u8 *)tgt + 0x78);
                        if (tt != 0x4D) {
                            if ((s32)tt < 0x4E) {
                                if ((s32)tt < 4 && (s32)tt >= 2) goto L71;
                            } else if (tt == 0x61) {
                                goto L71;
                            }
                        } else {
L71:
                            {
                                void *t0 = gTrackMarkerTable[*(s8 *)((u8 *)*(void **)((u8 *)node + 0x18) + 0x6C) + 0x182 - 0x182];
                                (void)t0;
                            }
                        }
                    } else {
                        v = *(s32 *)((u8 *)tgt + 0x20);
                        if (v != *(s32 *)((u8 *)node + 0x20)) {
                            func_80016718(node, tgt);
                            func_80016990(node, v);
                        }
                    }
                }
            }
            node = p;
        } else {
            void *a = *(void **)((u8 *)node + 8);
            void *n;
            if (a != NULL) {
                do {
                    func_800167B4(a);
                    n = *(void **)((u8 *)a + 8);
                    a = n;
                } while (a != NULL);
            }
            func_80016740(node);
            node = p;
        }
    }
    if (gBorderSkipFlag != 0 && D_800CA310 != 0) {
        func_8011E634();
    }
}
