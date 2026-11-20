typedef struct { s32 a; s32 b; u32 c; u32 max; } EnvA20C;
typedef struct { u8 pad0[0x24]; s32 f24; u8 pad28[8]; u16 h30; u8 pad32[0x26]; s32 f58; s32 f5C; u8 pad60[3]; u8 b63; } VoiceA20C;
typedef struct { u32 w0; s32 w4; } EvA20C;
extern s32 D_800FDB80;
extern s32 D_800FDB84;
extern u32 D_800FDB88;
extern u32 D_800FDB8C;
s32 func_8009835C(u16, s32 *);
void func_8008C1E4(u8, u32 *, s32);

s32 func_8009A20C(VoiceA20C *v, EvA20C *e) {
    s32 flag;
    u32 *p;
    u8 ch;

    if (func_8009835C(e->w0 >> 8, &D_800FDB80) != 0) {
        return 0;
    }
    switch (*(u8 *)e) {
    case 0:
        D_800FDB88 = e->w4;
        break;
    case 1:
        { s32 h = v->h30; s32 w = e->w4; D_800FDB88 = (u32)((0x7F - h) * w) / 127; }
        break;
    case 2:
        D_800FDB88 = (u32)(v->h30 * e->w4) / 127;
        break;
    default:
        D_800FDB88 = 0;
        break;
    }
    p = &D_800FDB88;
    if (*p >= D_800FDB8C) {
        *p = D_800FDB8C - 1;
    }
    ch = v->b63;
    if (!(v->f24 & 0x200)) {
        func_8008C1E4(ch, p - 2, 1);
    } else {
        func_8008C1E4(ch, p - 2, 0);
    }
    v->f5C = D_800FDB80;
    v->f24 |= 0x20;
    v->f58 = D_800FDB84;
    return 0;
}
