typedef struct { u8 pad0[0x22]; u16 h22; u8 pad24[2]; u16 h26; } Spr37DC;
typedef struct { u8 pad0[0x34]; f32 f34; u8 pad38[0x3B4]; Spr37DC *s3EC; Spr37DC *s3F0; u8 pad3F4[4]; Spr37DC *s3F8; Spr37DC *s3FC; u8 pad400[0x120]; u16 h520; } Obj37DC;

void func_800637DC(Obj37DC *a) {
    f32 t;

    if (a->s3EC != NULL) {
        t = a->f34 * 23.0f;
        a->s3EC->h22 = 120.0f - t - 8.0f;
        a->s3F0->h22 = 120.0f - t - 8.0f;
    }
    if (a->s3F8 != NULL) {
        a->s3F8->h22++;
        if (a->s3F8->h22 > 240) {
            a->s3F8->h22 = 0;
        }
    }
    if (a->s3FC != NULL) {
        a->s3FC->h26 = a->h520 * 0.0005561735f * 42.0f;
        if (a->s3FC->h26 == 0) {
            a->s3FC->h26 = 1;
        }
    }
}
