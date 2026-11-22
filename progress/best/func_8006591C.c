extern f32 D_800C0740, D_800C7C9C, D_800C46AC;
extern u8 D_80115089;
extern s32 gGameMode;
extern void *sTrackMarkerTable[];
#define F(p,o) (*(f32 *)((char *)(p)+(o)))
#define P(p,o) (*(void **)((char *)(p)+(o)))
void func_8006591C(void *arg0)
{
    void *state = P(arg0, 0x6c);
    s32 slot = *(s8 *)((char *)state+0x182);
    f32 target = F(&D_800C46AC, *(s8 *)((char *)P(arg0,0x68)+0xe)*0xe8)*D_800C7C9C;
    f32 x, y, dx, dy, tx, ty, rate;
    f32 fx, fy, fdx, fdy;
    void *marker;
    if (gGameMode == 0x19)
        target = D_800C0740;
    if (*(&D_80115089 + slot*0xa0)) {
        marker = sTrackMarkerTable[slot];
        if (F(marker,0x11c) != target) {
            tx = F(marker,0x110)/F(marker,0x78);
            ty = -F(marker,0x114)/F(marker,0x7c);
            if (tx < -1.0f) tx = -1.0f;
            else if (tx > 1.0f) tx = 1.0f;
            if (ty < -1.0f) ty = -1.0f;
            else if (ty > 1.0f) ty = 1.0f;
            rate = 0.5f;
            if (gGameMode == 0x19) rate = 1.01f;
            x = F(state,0x24);
            dx = tx-x;
            y = F(state,0x28);
            dx *= rate;
            goto steer;
        }
    }
    if (*(u16 *)((char *)P(arg0,0x68)+0xc)&1) {
        tx = F(state,0x1c);
        x = F(state,0x24);
        tx = (tx-x)*0.5f;
        dx = F(state,0x28);
        ty = (F(state,0x20)-0.05f-dx)*0.5f;
        goto follow;
    }
    if (gGameMode == 0x19) {
        tx = F(state,0x1c);
        x = F(state,0x24);
        tx -= x;
        ty = F(state,0x20);
        dx = F(state,0x28);
        tx *= 0.5f;
        ty -= dx;
        ty *= 0.5f;
follow:
        x += tx;
        dx += ty;
        F(state,0x24) = x;
        F(state,0x28) = dx;
        return;
    }
    x = F(state,0x24);
    rate = 0.5f;
    y = F(state,0x28);
    ty = -0.05f;
    dx = (-x) * rate;
steer:
    ty = (ty-y)*rate;
    x += dx;
    y += ty;
    F(state,0x24) = x;
    F(state,0x28) = y;
}
#undef F
#undef P
