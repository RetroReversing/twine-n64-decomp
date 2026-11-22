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
    f32 x;
    f32 y;
    f32 dx;
    f32 dy;
    f32 tx;
f32 __repair_phase_tx;
    f32 ty;
    f32 rate;
    f32 fx;
f32 __repair_phase_fx;
    f32 fy;
f32 __repair_phase_fy;
    f32 fdx;
    f32 fdy;
f32 __repair_phase_fdy;
    void *marker;
    if (gGameMode == 0x19)
        target = D_800C0740;
    if (*(&D_80115089 + slot*0xa0)) {
        marker = sTrackMarkerTable[slot];
        if (F(marker,0x11c) != target) {
            f32 __repair_clamped_float = F(marker,0x110)/F(marker,0x78);
            ty = -F(marker,0x114)/F(marker,0x7c);
            if (__repair_clamped_float < -1.0f) __repair_clamped_float = -1.0f;
            else if (__repair_clamped_float > 1.0f) __repair_clamped_float = 1.0f;
            if (ty < -1.0f) ty = -1.0f;
            else if (ty > 1.0f) ty = 1.0f;
            rate = 0.5f;
            if (gGameMode == 0x19) rate = 1.01f;
            x = F(state,0x24);
            dx = __repair_clamped_float-x;
            y = F(state,0x28);
            dx *= rate;
            goto steer;
        }
    }
    if (*(u16 *)((char *)P(arg0,0x68)+0xc)&1) {
        f32 temp;
        tx = F(state,0x1c);
        fx = F(state,0x24);
        temp = (tx-fx)*0.5f;
        tx = temp;
        fy = F(state,0x28);
        fdy = (F(state,0x20)-0.05f-fy)*0.5f;
        {
F(state,0x24) = fx + tx;
F(state,0x28) = fy + fdy;
return;
}
    }
    if (gGameMode == 0x19) {
        __repair_phase_tx = F(state,0x1c);
        __repair_phase_fx = F(state,0x24);
        __repair_phase_tx -= __repair_phase_fx;
        __repair_phase_fdy = F(state,0x20);
        __repair_phase_fy = F(state,0x28);
        __repair_phase_tx *= 0.5f;
        __repair_phase_fdy -= __repair_phase_fy;
        __repair_phase_fdy *= 0.5f;

        F(state,0x24) = __repair_phase_fx + __repair_phase_tx;
        F(state,0x28) = __repair_phase_fy + __repair_phase_fdy;
        return;
    }
    x = F(state,0x24);
    rate = 0.5f;
    y = F(state,0x28);
    ty = -0.05f;
    dx = -x;
    dx *= rate;
steer:
    dy = (ty-y)*rate;
    x += dx;
    y += dy;
    F(state,0x24) = x;
    F(state,0x28) = y;
}
#undef F
#undef P

