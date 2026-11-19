#define PTR(x, off) (*(void **)((u8 *)(x) + (off)))
s16 func_8002B278(void *);
s32 func_8011A7C8(s32, void *, void *);
extern u8 D_801002A0;
extern s32 D_801002A8;
extern u8 D_801002AC;
extern s32 D_801002B4;
extern s32 D_801002B8;
extern void *D_8010A500[];
extern u8 D_8011F140[];
extern u16 D_8011F15C[];
extern s32 D_8011F3A8;

u8 func_8011A2A0(void *arg1, void *arg2) {
    u16 buf[2];
    s32 i;
    s32 j;
    s32 s0;
    s32 s2;
    s32 a0;
    s32 th;
    void *p;
    void *q;

    for (i = 0; i < 2; i++) {
        buf[i] = 0;
    }
    switch (D_801002A0) {
    case 6:
        if (D_801002A8 == 0) {
            D_801002AC = 0;
        }
        for (i = 0; i < 2; i++) {
            buf[i] = func_8002B278(D_8011F140 + i * 8) / 10;
        }
        for (i = 0; i < D_801002B4; i++) {
            p = D_8010A500[i];
            if (p != NULL) {
                q = PTR(PTR(p, 0x6C), 0xB4);
                buf[*(u8 *)((u8 *)q + 0x12)] += *(u16 *)((u8 *)q + 0xC) - *(u16 *)((u8 *)q + 0xE);
            }
        }
        th = D_801002A8;
        if (th != 0) {
            for (i = 0; i < 2; i++) {
                if ((s16)buf[i] >= th) {
                    D_8011F3A8 = 0x5A;
                    *((u8 *)&D_801002A8 + 4) = 1;
                }
            }
        }
        break;
    case 7:
    case 8:
        s0 = 0;
        s2 = 0;
        for (j = 0; j < D_801002B4; j++) {
            p = D_8010A500[j];
            if (p != NULL && ((*(u8 *)((u8 *)PTR(PTR(p, 0x6C), 0xB4) + 0x11) == 0) == 0)) {
                s2++;
                s0 += j < D_801002B8;
            }
        }
        if (s0 >= D_801002B8) {
            func_8011A7C8(D_801002B4, &D_801002B8, D_8010A500);
            if (s0 >= D_801002B8) {
                D_8011F3A8 = 0x5A;
                D_801002AC = 1;
                break;
            }
        }
        if (!(s2 < D_801002B4 - 1)) {
            D_8011F3A8 = 0x5A;
            D_801002AC = 1;
        }
        break;
    case 1:
    case 2:
    case 3:
    case 5:
        for (i = 0; i < D_801002B4; i++) {
            p = D_8010A500[i];
            if (p != NULL) {
                q = PTR(PTR(p, 0x6C), 0xB4);
                buf[*(u8 *)((u8 *)q + 0x12)] += *(u16 *)((u8 *)q + 0xC) - *(u16 *)((u8 *)q + 0xE);
            }
        }
        th = D_801002A8;
        if (th != 0) {
            for (i = 0; i < 2; i++) {
                if ((s16)buf[i] >= th) {
                    D_8011F3A8 = 0x5A;
                    *((u8 *)&D_801002A8 + 4) = 1;
                }
            }
        }
        break;
    default:
        a0 = 0;
        for (j = 0; j < D_801002B4; j++) {
            p = D_8010A500[j];
            if (p != NULL) {
                q = PTR(PTR(p, 0x6C), 0xB4);
                if (a0 < *(u16 *)((u8 *)q + 0xC) - *(u16 *)((u8 *)q + 0xE)) {
                    a0 = *(u16 *)((u8 *)q + 0xC) - *(u16 *)((u8 *)q + 0xE);
                }
            }
        }
        if (D_801002A8 != 0 && !(a0 < D_801002A8)) {
            D_8011F3A8 = 0x5A;
            D_801002AC = 1;
        }
        break;
    }
    for (i = 0; i < 2; i++) {
        D_8011F15C[i] = buf[i];
    }
    return D_801002AC;
}
