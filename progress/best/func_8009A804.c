typedef struct { u8 pad0[0x24]; s32 f24; u8 pad28[8]; s32 f30; u8 pad34[0x50]; s32 f84; s32 f88; u8 pad8C[0x28]; s32 fB4; } VoiceA804;
typedef struct { u32 w0; u16 h4; u8 b6; u8 b7; } NoteA804;
void func_800957A8(s32 *, NoteA804 *);
void func_800957B8(s32 *, VoiceA804 *);
s32 func_80095818(s32);
u8 *func_8009846C(s32);

s32 func_8009A804(VoiceA804 *v, NoteA804 *n, s32 arg2) {
    s32 div;
    u32 pitch;
    u32 out;
    u8 *tbl;
    u32 hi;
    u32 lo;
    u16 id;
    u8 *p;
    u32 w;
    s32 unused[4];

    v->fB4 = n->h4;
    if ((*(u32 *)&n->h4 >> 8) & 1) {
        func_800957A8(&v->fB4, n);
    } else {
        func_800957B8(&v->fB4, v);
    }
    div = func_80095818(v->fB4);
    if (div == 0) {
        div = 1;
    }
    pitch = (u32)(((u8 *)n)[2] * v->f30) >> 7;
    pitch += ((u8 *)n)[1] << 16;
    w = n->w0;
    if (pitch > 0x7F0000) {
        pitch = 0x7F0000;
    }
    id = (w >> 24) | (n->b7 << 8);
    out = pitch;
    if (id != 0) {
        tbl = func_8009846C(id);
        if (tbl != NULL) {
            hi = pitch >> 16;
            lo = pitch & 0xFFFF;
            if (hi < 0x7F) {
                p = tbl + hi;
                { u32 d = (p[1] - p[0]) * lo; out = (p[0] << 16) + d; }
            } else {
                out = tbl[hi] << 16;
            }
        }
    }
    pitch = out;
    v->f88 = pitch;
    v->f30 = arg2;
    v->f24 |= 0x20000;
    v->f84 = (s32)(pitch - arg2) / div;
    return 0;
}
