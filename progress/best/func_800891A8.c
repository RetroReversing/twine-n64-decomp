typedef struct {
    u16 rate;
    u16 lens[8];
    u8 vol[8];
    u8 count;
    u8 pan;
    u8 mode;
    u8 pad;
    s16 env[4];
} S891A8;
typedef struct {
    void *buf;
    s32 size;
    s16 count;
    s16 pan;
    s32 lens[8];
    s16 vol[10];
    s16 env[4];
} D891A8;
void func_800A0FA0(void *, s32);
void func_800A0220(void *, s32);
void func_8008C0D4(void);
void func_8008C11C(void);
extern u32 D_800E41D4;
extern void *D_800E4230;
extern s32 D_800E4234;
extern void *D_800E4238;
extern void *(*D_8010017C)(s32, s32);

void func_800891A8(S891A8 *arg0) {
    u32 rate;
    u32 size;
    s32 bytes;
    D891A8 *d;
    u32 i;

    if (D_800E4238 != NULL) {
        /*__repair_loop_weight*/do {
        rate = arg0->rate * D_800E41D4 / 1000;
        } while (0);
        rate = (rate / 192) * 192 + 192;
        d = D_8010017C(0x48, 0);
        bytes = rate * 2;
        d->buf = D_800E4238;
        func_800A0FA0(D_800E4238, bytes);
        func_800A0220(d->buf, bytes);
        d->size = rate;
        d->pan = arg0->pan << 8;
        d->count = arg0->count;
        for (i = 0; i < arg0->count; i++) {
            d->lens[i] = ((D_800E41D4 * arg0->lens[i]) / 1000 + 3) & 0xFFFC;
            d->vol[i] = arg0->vol[i] << 8;
        }
        if (arg0->mode == 1) {
            for (i = 0; i < 4; i++) {
                d->env[i] = arg0->env[i];
            }
        } else {
            d->env[0] = 0;
            d->env[1] = 0;
            d->env[2] = 0;
            d->env[3] = 0x7FFF;
        }
        func_800A0220(d, 0x48);
        func_8008C0D4();
        D_800E4234 = 0;
        D_800E4230 = d;
        func_8008C11C();
    }
}
