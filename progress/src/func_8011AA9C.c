s32 func_8011AE4C();
s32 func_8011B3D8();
s32 func_8011C338();
s32 func_8011D0B4();
extern u8 gSceneType;
extern u8 gSaveKeyRelaxed;
extern u8 D_801002D5;
extern s16 D_8011F100[];

typedef struct Stats {
    u8 pad0[0xC];
    u16 f0C;
    u16 f0E;
    u8 f10;
    u8 f11;
    u8 f12;
} Stats;

typedef struct Ent {
    u8 pad0[4];
    struct Ent *f04;
    u8 pad1[0xB4 - 8];
    Stats *stats;
    u8 pad2[0x182 - 0xB8];
    s8 f182;
    u8 pad3[0x1B4 - 0x183];
    s32 f1B4;
} Ent;

typedef struct Arg {
    u8 pad[0x6C];
    Ent *f6C;
} Arg;

void func_8011AA9C(Arg *arg0) {
    Ent *a;
    Ent *b;

    a = arg0->f6C;
    b = (Ent *)func_8011B3D8(a->f04);
    switch (gSceneType) {
    case 8:
        if (a->f1B4 == 0x26 && b->stats->f10 == 7) {
            a->stats->f11 = 1;
            b->stats->f0C += 1;
        }
        func_8011AE4C(arg0, a, b);
        break;
    case 7:
        if (a->stats->f11 != 0) {
            a->stats->f0C -= 1;
            a->stats->f11 -= 1;
            if (a->stats->f0C == 0) {
                func_8011D0B4(a->f182);
            }
        }
        break;
    case 2:
    case 3:
        func_8011C338(arg0);
    default:
        if (b == a || b == 0) {
            a->stats->f0E += 1;
        } else if (b != 0) {
            if (gSaveKeyRelaxed != 0) {
                Stats *s = b->stats;
                if (s->f12 == a->stats->f12) {
                    if (D_801002D5 != 0) {
                        s->f0E += 1;
                    }
                } else {
                    s->f0C += 1;
                }
            } else {
                b->stats->f0C += 1;
            }
        }
        break;
    }
    if (a != 0) {
        if (b != 0) {
            D_8011F100[a->f182] = b->f182;
            a->f04 = 0;
            return;
        }
        D_8011F100[a->f182] = -1;
        a->f04 = 0;
    }
}
