typedef struct {
    f32 v;
    f32 x;
    f32 y;
    s32 rest[6];
} Entry;

extern f32 D_800C0740;
extern Entry *D_800E1770;
extern Entry D_800E1778;
extern Entry D_800E1780[];
extern Entry D_800E1898[];
extern Entry *D_800E19B8;
extern Entry *D_800E19BC;
extern Entry *D_800E19C0;
extern Entry *D_800E19C4;
extern s16 D_800E19C8;
extern s16 D_800E19CA;
extern s16 D_800E19CC;
extern s16 D_800E19CE;
extern u16 D_800E19D0;
extern u16 D_800E19D2;

s16 func_8003F328(s32 arg0) {
    Entry **__base_D_800E1770;
    register s16 ret;
    u8 sp[16];
    int n;
    int t1;
    int t2;
    int t3;
    int t4;
    int i;
    int j;
    int k;
    f32 thr;
    s32 *src;
    s32 *dst;
    int var_v0;

    D_800E19D2 = 0;
    n = arg0;
    D_800E19D0 = 0;
    D_800E19CE = 0;
    D_800E19CC = 0;
    D_800E19CA = 0;
    D_800E19C8 = 0;
    i = 0;
    if (n > 0) {
        k = 0;
        do {
            if (D_800E1780[k].v < 0.2f) {
                ++i;
                D_800E19D0 += 1;
            } else {
                i += 1;
                if (D_800C0740 < D_800E1780[k].v) {
                    D_800E19D2 += 1;
                }
            }
            k += 1;
        } while (i < n);
    }
    if ((s16)(D_800E19D0 + D_800E19D2) == 0) {
        __base_D_800E1770 = &D_800E1770;
        (*__base_D_800E1770) = &D_800E1778;
        ret = arg0;
    } else {
        var_v0 = 0;
        if ((s16)D_800E19D0 != n) {
            t4 = 0;
            if ((s16)D_800E19D2 != n) {
                D_800E19B8 = &D_800E1778;
                (*__base_D_800E1770) = &D_800E1778;
                D_800E19BC = D_800E1898;
                do {
                    if (t4 == 0 || t4 != 1) {
                        t4 += 0;
                    }
                    break;
                } while (0);
                (*__base_D_800E1770) = D_800E19B8;
                var_v0 = n;
            }
        }
        ret = var_v0;
    }
    return ret;
}
