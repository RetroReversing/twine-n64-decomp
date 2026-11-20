extern u32 D_800D4240[3];
s32 func_8001751C(s32, u8, s32 *, f32 *);
void applyNearbyActorImpact(void *, f32, f32);
s32 func_80045CF8(s32);
s32 func_80061578(void *, s32 *);
s32 func_80082FE4(s16 *, void *);
s32 func_80083A6C(void *, s32 *);
extern u8 D_80109A60[];

void func_80061168(void *arg0) {
    s32 sp10[3];
    char sp20[0x30];
    s16 sp50[3];
    s32 sp58[3];
    s32 sp68[3];
    s16 st;
    void *s2;
    u8 t;
    u32 s0;
    void *v1;

    if (((*(s32 *)((char *)arg0 + 0x58)) & 4) || ((*(s32 *)((char *)arg0 + 0x60)) & 0x3000)) {
        st = *(s16 *)((char *)arg0 + 0x7A);
        s2 = *(void **)((char *)arg0 + 0x6C);
        switch (st) {
        case 0:
            sp10[0] = D_800D4240[0];
            sp10[1] = D_800D4240[1];
            sp10[2] = D_800D4240[2];
            sp50[0] = (s16)(s32)(*(f32 *)((char *)arg0 + 0x3C));
            sp50[1] = (s16)(s32)(*(f32 *)((char *)arg0 + 0x40));
            sp50[2] = (s16)(s32)(*(f32 *)((char *)arg0 + 0x44));
            func_80082FE4(sp50, sp20);
            func_80083A6C(sp20, sp10);
            *(f32 *)((char *)s2 + 0) = *(f32 *)&sp10[0];
            *(f32 *)((char *)s2 + 4) = *(f32 *)&sp10[1];
            *(f32 *)((char *)s2 + 8) = *(f32 *)&sp10[2];
            *(s16 *)((char *)arg0 + 0x7A) = 1;
            break;
        case 1:
            t = *(u8 *)((char *)s2 + 0x22);
            if ((!t) || (D_80109A60[t] != 0)) {
                if (func_80045CF8((*(s16 *)((char *)arg0 + 0x7C))) == 0) {
                    sp58[0] = *(s32 *)((char *)arg0 + 0x24);
                    sp58[1] = *(s32 *)((char *)arg0 + 0x28);
                    sp58[2] = *(s32 *)((char *)arg0 + 0x2C);
                    sp68[0] = *(s32 *)((char *)arg0 + 0x3C);
                    sp68[1] = *(s32 *)((char *)arg0 + 0x40);
                    sp68[2] = *(s32 *)((char *)arg0 + 0x44);
                    func_8001751C(*(s32 *)((char *)s2 + 0x18), *(u8 *)((char *)s2 + 0x21), sp58, (f32 *)sp68);
                    func_80061578(arg0, sp58);
                    applyNearbyActorImpact(arg0, 0.75f, 10.0f);
                    s0 = 0;
                    if ((s32)*(u16 *)((char *)arg0 + 0x78) >= 0x47) {
                        if ((s32)*(u16 *)((char *)arg0 + 0x78) >= 0x49) {
                            if (*(u16 *)((char *)arg0 + 0x78) == 0x49) {
                                s0 = 0x02000000;
                                goto loop;
                            }
                        } else {
loop:
                            v1 = *(void **)((char *)arg0 + 0x20);
                            if (v1 != NULL) {
                                v1 = *(void **)v1;
                                while (v1 != NULL) {
                                    *(u32 *)((char *)v1 + 0x60) |= s0;
                                    v1 = *(void **)v1;
                                }
                            }
                        }
                    }
                }
                if (func_80045CF8(*(u8 *)((char *)s2 + 0x27)) == 0) {
                    *(s16 *)((char *)arg0 + 0x7A) = 2;
                }
                break;
            }
            return;
        case 2:
            if (func_80045CF8(*(u8 *)((char *)s2 + 0x28)) == 0) {
                *(s16 *)((char *)arg0 + 0x7A) = 1;
            }
            break;
        default:
            *(s32 *)((char *)arg0 + 0x60) = 0;
            return;
        }
        *(s32 *)((char *)arg0 + 0x60) = 0;
    } else {
        *(s32 *)((char *)arg0 + 0x60) = 0;
    }
}
