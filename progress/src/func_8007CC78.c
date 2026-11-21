typedef struct { f32 x, y, z; } V3;
typedef struct { f32 x, y, z, c, d, e; } Pt;
typedef struct { u8 p0[0x5C]; u16 unk5C; u8 p1[0xA]; u16 unk68; u8 p2[0x7E]; } E8;
typedef struct { s32 a; u16 b; } CE;
struct BF { u32 b31:1, b30:1, b29:1, b28:1, b27:1, b26:1, b25:1, f21:4, f17:4, lo:17; };
struct W_ { s32 v; }; struct UW_ { u32 v; }; struct H_ { s16 v; }; struct UH_ { u16 v; }; struct B_ { s8 v; }; struct UB_ { u8 v; }; struct F_ { f32 v; }; struct P_ { u8 *v; }; struct V_ { V3 v; };
#define W(p,o) (((struct W_*)((u8*)(p)+(o)))->v)
#define UW(p,o) (((struct UW_*)((u8*)(p)+(o)))->v)
#define H(p,o) (((struct H_*)((u8*)(p)+(o)))->v)
#define UH(p,o) (((struct UH_*)((u8*)(p)+(o)))->v)
#define B(p,o) (((struct B_*)((u8*)(p)+(o)))->v)
#define UB(p,o) (((struct UB_*)((u8*)(p)+(o)))->v)
#define F(p,o) (((struct F_*)((u8*)(p)+(o)))->v)
#define P(p,o) (((struct P_*)((u8*)(p)+(o)))->v)
#define V(p,o) (((struct V_*)((u8*)(p)+(o)))->v)
#define M P(a,0x68)
#define BF21 (((struct BF*)(s+0x88))->f21)
#define BF17 (((struct BF*)(s+0x88))->f17)
#define SETPT(pp) F(s,0x24) = (pp)[B(s,0x86)].x; F(s,0x28) = (pp)[B(s,0x86)].y; F(s,0x2C) = (pp)[B(s,0x86)].z
#define ANIMEND (W(M,0x14) & 0x10)
#define CUE D_80100900 = 1
#define COND(e) (F(P(e,0x3C),0x20) < F(a,0x28) && F(a,0x28) < F(P(e,0x3C),0x24) && func_800828D0(F(e,0x44) - F(a,0x28)) < F(e,0x4C))

s8 func_8003D64C(u8 *, u8 *);
void func_80016A34(u8 *);
void func_8007947C(u8 *);
void func_80086C10(u8 *, s32);
s8 func_80086480(u8 *, s32);
void func_80077FA4(u8 *);
void func_80084CD8(u8 *, s32, s32);
void func_80077FF0(u8 *);
void func_80002BD0(u8 *, s32);
void func_80077960(u8 *, s32);
u32 func_80045CF8(u32);
void func_80078034(u8 *);
void func_800843CC(u8 *, s32, s32);
void func_8005F664(u8 *, u8 *, s32);
void func_800015AC(u8 *, s32);
void func_800848EC(u8 *, s32, s32);
void func_80076B30(u8 *);
void func_800175C0(u8 *, s32, s32, u8 *, f32, s32);
f32 func_80045590(u8 *, u8 *);
s32 func_80002D70(u8 *, s32, u8 *);
void func_800770E4(u8 *);
void func_80076E98(u8 *);
u8 *func_8007847C(u8 *);
void func_801177A8(u8 *, u8 *);
void func_80117740(u8 *, u8 *);
void func_80002D30(u8 *, s32);
void func_8003E6EC(s32, u8 *, s32);
void func_80077C00(u8 *);
f32 func_800461D4(u8 *, u8 *);
void func_800779C4(u8 *);
s32 func_800312F4(s32, s32);
void func_8007C93C(u8 *);
s8 func_8007898C(u8 *);
void func_8007AD88(u8 *);
s8 func_8007C72C(u8 *, u8 *, u8 *);
void func_80077ED8(u8 *);
void func_80077E94(u8 *);
s8 func_8007AA40(u8 *, u8 *, s32 *);
f32 func_8007AABC(u8 *, s32, f32);
s8 func_8007C890(u8 *, s32);
s8 func_8007C3F0(u8 *, s32);
void func_80084338(s32, u8 *);
f32 func_800829A0(f32);
f32 func_800829C8(f32);
s8 func_8007835C(u8 *);
s8 func_8007BAF8(u8 *, u8 *, s32, s32);
void func_8007B030(u8 *);
s8 func_80078274(u8 *);
void func_8007B3B8(u8 *, u8 *, u8 *, s32);
s8 func_80077E00(u8 *);
void func_8007AB18(u8 *, u8 *, f32);
void func_800177D4(u8 *, s32, u8 *, f32);
s8 func_8007AB60(u8 *);
f32 func_800828D0(f32);
s8 func_80077CB4(u8 *);
u32 func_80077D40(s32, u8 *);
f32 func_80045764(V3 *, V3 *);
s8 func_8004F430(u8 *, u8 *, V3 *, f32);
s8 func_8007B660(u8 *, u8 *);
void func_8007CA84(u8 *);
void func_8007CAFC(u8 *);
void func_80077D84(s32, u8 *);
s8 func_8007A9CC(u8 *, u8 *, s32 *, f32);
s8 func_800158A4(u8 *, u8 *, u8 *, V3 *, s32, s32, s32, s32, u8 *);
s8 func_8007C214(u8 *, u8 *);
f32 func_8008292C(f32);
f32 func_80082968(f32);
f32 func_80045D2C(f32);
void func_80117888(u8 *);
void func_80118188(u8 *);
void func_80079C14(u8 *);
s8 func_8007C094(u8 *, u8 *, f32);
void func_800847D4(u8 *, u8 *);
void func_8008168C(u8 *, u8 *);
void func_80081568(u8 *);
void func_80074C34(u8 *, s32, s32);
void func_8007CC00(u8 *);
void func_80017E14(u8 *, s32, s32, s32);
void func_80076C80(u8 *);
void func_80077B58(u8 *);
void func_800846A8(u8 *, u8 *);
s32 func_80087100(s32);
void func_80073AF8(s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
s32 func_80002EF0(u8 *);
void func_80079928(u8 *, u8 *, s32 *, s32 *, s32);
void func_80079B08(u8 *, u8 *, s32 *, s32 *, s32);
void func_800794C0(u8 *, u8 *);
f32 func_80082A70(f32, f32);
s32 func_80000A30(s32, s32);

extern s8 D_80100900;
extern u16 D_8010A91A;
extern u8 D_80109A60[];
extern f32 D_80117408;
extern u8 *D_8010A500;
extern E8 D_800C469C[];
extern u16 D_800C9BAC[];
extern u8 D_800CEEB0;
extern u8 D_80102EE8;
extern u16 D_801176E0;
extern u16 D_801176E2;
extern u16 D_801176EA;
extern s32 *D_800CA31C;
extern u8 D_80109B1E;
extern u16 D_80102F2A;
extern CE D_800CEB34[];
extern u16 D_800C9D38[];
extern s32 D_80109688;
extern u16 D_80113020;
extern s32 D_8010302C;
extern u8 D_80117734;
extern s32 D_80108F78;
extern u8 *D_80108788;
extern s8 D_80115319;
extern u16 D_8010090A;

void func_8007CC78(u8 *a) {
    u8 *s;
    u8 *z;
    s8 moved;
    s8 flag;
    s32 sp30, sp34, sp38, sp3C, sp40, sp68, sp90, spB8, spBC, spC0, spC4, spC8, spCC, spD0, spD4, spD8, spDC;

    (void)&sp30; (void)&sp34; (void)&sp38; (void)&sp3C; (void)&sp40;
    {
    V3 sp48; V3 sp58;
    (void)&sp68;
    {
    V3 sp70; V3 sp80;
    (void)&sp90;
    {
    V3 sp98; V3 spA8;
    (void)&spB8; (void)&spBC; (void)&spC0; (void)&spC4; (void)&spC8; (void)&spCC; (void)&spD0; (void)&spD4; (void)&spD8; (void)&spDC;

    s = P(a,0x6C);
    z = P(a,0x20);
    W(a,0x58) &= ~1;
    if (P(a,0x20) && !func_8003D64C(a + 0x24, P(a,0x20))) {
        func_80016A34(a);
    }
    switch (H(a,0x7A)) {
    case 0x27:
        if (D_80109A60[UB(s,0x84)] == UB(s,0x85)) {
            return;
        }
        break;
    case 0x0: case 0x9: case 0x15: case 0x17: case 0x19: case 0x1A: case 0x1B: case 0x1C: case 0x1D:
    case 0x28: case 0x29: case 0x2A: case 0x2B: case 0x2C: case 0x32: case 0x36: case 0x37: case 0x3E:
    case 0x43: case 0x44: case 0x45: case 0x4F: case 0x75: case 0x76: case 0x77: case 0x7C: case 0x7D:
    case 0x85: case 0x95: case 0xA1: case 0xA2: case 0xAD:
        break;
    default:
        if (UB(s,0x82) == 0x1E && P(s,0x40) && (W(s,0x88) & 0x40000000)) {
            break;
        }
        if (UB(s,0x82) != 0x28) {
            if (!(W(a,0x58) & 4) && !(W(a,0x60) & 0x7006)) {
                W(a,0x60) &= 1;
                func_8007947C(a);
                if (W(a,0x60) & 0x1000000) {
                    goto done;
                }
                return;
            }
            if (W(s,0x88) & 0x40000000) {
                D_8010A91A++;
            }
        }
        break;
    }
    D_80100900 = 0;
    if (H(s,0x7C) == 0 && H(s,0x78) != -1) {
        H(s,0x78)--;
    }
    if (H(a,0x7C) == 0xC && UB(s,0x7F) == 0xC) {
        F(a,0x74) -= 1.0f;
    }
    switch (UB(s,0x82)) {
    case 0x1B: case 0x1C:
        goto skip;
    case 0x1D:
        break;
    }
    {
        if (UB(s,0x83)) {
            func_80086C10(a, UB(s,0x83));
        }
        if (z && F(P(z,0x20),0x5C) >= F(P(M,0),0xAC)) {
            F(a,0x74) -= 1.0f;
        }
        if (W(a,0x60) & 0x40) {
            flag = 0;
            if (H(a,0x7C) == 8) {
                switch (UB(s,0x81)) {
                case 2: case 3:
                    F(a,0x74) = -1.0f;
                    break;
                case 1: case 4: case 5: case 6:
                    break;
                }
            }
            if (UB(s,0x82) == 0xC) flag = 1;
            if (H(a,0x7C) == 9) func_80077FA4(a);
            if (H(a,0x7C) == 0xB) flag = 1;
            if (H(a,0x7C) == 0xD) flag = 1;
            func_80084CD8(a + 0x24, 0, F(a,0x74) > 0.0f);
            if (flag) func_80077FF0(a);
        } else if (W(a,0x60) & 0x80) {
            s8 g = 1;
            if (H(a,0x7C) == 8) {
                switch (UB(s,0x81)) {
                case 1: case 2: case 3: case 5: case 6:
                    g = 0;
                    break;
                case 4:
                    break;
                }
            }
            switch (UB(s,0x82)) {
            case 4: case 6: case 7: case 8: case 0x12:
                g = 0;
                break;
            }
            if (g) {
                if (H(a,0x7C) != 0xC && H(a,0x7C) != 9 && H(a,0x7C) != 0xB) {
                    H(a,0x7C) = 7;
                    UB(s,0x7F) = 7;
                    if (UB(s,0x7E) == 0) UB(s,0x7E) = UH(a,0x7A);
                    UB(s,0x80) = 0;
                    switch (H(a,0x7A)) {
                    default:
                        F(s,0x34) = 0.0f;
                        func_80002BD0(a, 0x206);
                        func_80077960(a, 0x71);
                        break;
                    case 0x72: case 0x73: case 0x74:
                        func_80002BD0(a, 0x205);
                        func_80077960(a, 0x72);
                        break;
                    }
                }
            }
        } else if (W(a,0x60) & 0x100) {
            s8 g = 1;
            if (H(a,0x7C) == 8) {
                switch (UB(s,0x81)) {
                case 1: case 2: case 3: case 5: case 6:
                    g = 0;
                    break;
                case 4:
                    break;
                }
            }
            switch (UB(s,0x82)) {
            case 4: case 6: case 7: case 8: case 0x12:
                g = 0;
                break;
            }
            if (g && H(a,0x7C) != 0xC) {
                UH(s,0x76) = func_80045CF8(D_800C469C[W(s,0x64)].unk68 >> 1) + (D_800C469C[W(s,0x64)].unk68 >> 1);
                func_80078034(a);
            }
            W(a,0x60) &= ~2;
        } else if (W(a,0x60) & 0x04000000) {
            s8 g = 1;
            if (H(a,0x7C) == 8) {
                switch (UB(s,0x81)) {
                case 2: case 3:
                    F(a,0x74) = -1.0f;
                    break;
                case 1: case 4: case 5: case 6:
                    break;
                }
            }
            switch (UB(s,0x82)) {
            case 4: case 6: case 7: case 8: case 0x12:
                g = 0;
                break;
            }
            if (g && H(a,0x7C) != 0xC) {
                UH(s,0x76) = func_80045CF8(D_800C469C[W(s,0x64)].unk68 >> 1) + (D_800C469C[W(s,0x64)].unk68 >> 1);
                func_80078034(a);
            }
            W(a,0x60) &= ~2;
        } else if (!(W(a,0x60) & 0x02000000)) { if (W(a,0x60) & 2) {
            if (H(a,0x7C) == 8) {
                switch (UB(s,0x81)) {
                case 2: case 3:
                    F(a,0x74) = -1.0f;
                    break;
                case 1: case 4: case 5: case 6:
                    break;
                }
            }
            func_800843CC(a + 0x24, 0, F(a,0x74) > 0.0f);
        } }
        if (H(a,0x7C) != 0xC || UB(s,0x7F) != 0xC) {
            if (F(a,0x74) > 0.0f) {
                if (W(a,0x60) & 0x40000022) {
                    f32 d;
                    if (UB(s,0x82) == 0xC) F(a,0x74) = -1.0f;
                    if ((BF17 == 10 || BF17 == 9) && H(a,0x7C) == 1) {
                        if (B(M,0xE)) {
                            func_8005F664(a, 0, B(M,0xE));
                            func_800015AC(a, 0);
                        }
                    }
                    if (W(a,0x60) & 0x40000020) {
                        d = F(s,0x60);
                        F(s,0x60) = 0.0f;
                    } else {
                        d = F(s,0x60) * D_800C9BAC[BF17];
                        if (D_800CEEB0 == 2) d *= 2.0f;
                        F(s,0x60) = 0.0f;
                        switch (UB(&D_80102EE8,0)) {
                        case 0:
                            break;
                        case 1:
                            d *= 0.88f;
                            break;
                        case 2:
                            d *= 0.75f;
                            break;
                        }
                    }
                    F(a,0x74) -= d;
                    func_800848EC(a, 0, F(a,0x74) > 0.0f);
                } else if (W(a,0x60) & 4) {
                    func_80076B30(a);
                }
            }
            if (F(a,0x74) <= 0.0f) {
                flag = 0;
                if (UH(a,0x78) == 1 && (W(s,0x68) & 0x1000) && BF21 == 1 && !(W(a,0x60) & 0x40)) {
                    { u16 *cp = &D_801176E0; (*cp)++; }
                }
                W(a,0x5C) &= ~0x200;
                if (BF17 != 0xE) {
                    func_800175C0(z, 2, 0x20000, a + 0x24, 0, 1);
                } else {
                    func_800175C0(z, 2, 0x800000, a + 0x24, 0, 1);
                }
                F(a,0x74) = 0.0f;
                func_8007947C(a);
                D_80100900 = 1;
                if (UB(s,0x80) && func_80045590(a + 0x24, s) < 0.5f && func_80002D70(a, UB(s,0x80), s + 0xC)) {
                    UH(a,0x78) = 0x4C;
                    H(a,0x7C) = 0xC;
                    UB(s,0x7F) = 0xC;
                    V(a,0x24) = V(s,0);
                    func_80077960(a, 0x16);
                    flag = 1;
                }
                if (!flag) {
                    if (W(a,0x60) & 0x40) {
                        func_80077FF0(a);
                    } else {
                        func_800770E4(a);
                    }
                }
            } else if (W(a,0x60) & 2) {
                switch (UB(s,0x82)) {
                default:
                    func_80076E98(a);
                    break;
                case 4: case 6: case 7: case 8: case 18: case 22: case 43:
                    F(a,0x74) = -1.0f;
                    break;
                }
            }
        }
        if (UB(s,0x82) == 0x1E && P(s,0x40) && (W(s,0x88) & 0x40000000)) {
            if (D_80117408 <= H(s,0x74)) {
                func_8007847C(a);
            } else {
                H(s,0x74)++;
            }
        }
        if (H(a,0x7C) != 0xC) {
            if (UB(s,0x82) == 0xA) {
                u8 *z1 = P(a,0x20);
                u8 *z2 = P(D_8010A500,0x20);
                if (z1 && z2 && (s32)((UW(P(z1,0x3C),0x30) >> 4) & 0xFFFF) < (s32)((UW(P(z2,0x3C),0x30) >> 4) & 0xFFFF)) {
                    func_801177A8(a, z2);
                }
            }
            if (UB(s,0x82) == 0xB) {
                u8 *z1 = P(a,0x20);
                u8 *z2 = P(D_8010A500,0x20);
                if (z1 && z2 && (s32)((UW(P(z1,0x3C),0x30) >> 4) & 0xFFFF) < (s32)((UW(P(z2,0x3C),0x30) >> 4) & 0xFFFF)) {
                    func_80117740(a, z2);
                }
            }
        }
    }
skip:
    if (UB(s,0x83) && func_80086480(a, UB(s,0x83))) {
        goto done;
    }
    switch (H(a,0x7A)) {
    case 0:
        break;
    case 0x26:
        if (ANIMEND) {
            func_80002D30(a, 0x14F);
        }
        break;
    case 0x27: {
        Pt *pp = (Pt *)P(s,0x44);
        if (P(a,0x20) == 0) {
            flag = 1;
            func_8003E6EC(*D_800CA31C, a, 1);
            if (P(a,0x20) == 0) {
                W(a,0x60) |= 1;
                return;
            }
            switch (UB(s,0x82)) {
            case 0x15: case 0x16: case 0x22:
                flag = 0;
                break;
            }
            UH(M,0xC) &= ~8;
            if (flag && UB(s,0x80) == 0) {
                func_80077C00(a);
            } else {
                F(M,8) = F(P(P(a,0x20),0x3C),0x20);
            }
            V(s,0) = V(a,0x24);
            V(s,0xC) = V(a,0x3C);
        }
        if (pp) {
            SETPT(pp);
            F(s,0x3C) = func_800461D4(a + 0x24, s + 0x24);
            switch (UB(s,0x82)) {
            case 0x10:
                UB(s,0x82) = 0x11;
                func_80077960(a, 9);
                break;
            case 0xD: case 0xE:
                func_800779C4(a);
                func_800175C0(z, 2, 0x20000, a + 0x24, 0, 1);
                func_80077960(a, 0x3E);
                break;
            case 0x26:
                func_80077960(a, 0x3F);
                break;
            case 0x1C:
                if (func_800312F4(1, 0) == 2) {
                    W(a,0x60) |= 1;
                }
            case 0x1B: case 0x2B:
                func_80077960(a, 0x40);
                break;
            case 0x31:
                func_80077960(a, 0x97);
                break;
            case 0x2D:
                func_80077960(a, 0x8A);
                break;
            case 0x22:
                func_80077960(a, 3);
                break;
            case 0x15:
                func_8007C93C(a);
                break;
            case 0x1F:
                func_80002BD0(a, 0x1FE);
                func_80077960(a, 0x77);
                break;
            default:
                func_80077960(a, 1);
                break;
            }
        } else {
            switch (UB(s,0x82)) {
            case 0x22:
                func_80077960(a, 3);
                break;
            case 0x15:
                func_8007C93C(a);
                break;
            case 0x16:
                func_80002BD0(a, 0x20E);
                func_80077960(a, 0x47);
                break;
            case 0x1F:
                func_80002BD0(a, 0x1FE);
                func_80077960(a, 0x77);
                break;
            case 0x20:
                func_80077960(a, 0x78);
                break;
            case 0x21:
                func_80077960(a, 0x79);
                break;
            case 0x24:
                func_80077960(a, 0x7C);
                break;
            case 0x32:
                func_80077960(a, 0x9B);
                break;
            default:
                func_80077960(a, 1);
                break;
            }
        }
        break;
    }
    case 0xA3:
        CUE;
        if (BF21 != 3) {
            W(a,0x60) &= ~0x20000;
            if (func_8007898C(a)) {
                func_80002BD0(a, 0x223);
                func_80077960(a, 0x81);
            }
        }
        break;
    case 0x3: case 0xAD:
        CUE;
        if (ANIMEND) {
            func_80002BD0(a, 0x14D);
            func_80077960(a, 1);
        }
        break;
    case 0x4: case 0x81:
        if (ANIMEND) {
            func_80077960(a, 1);
        }
    case 0x1: case 0x2: {
        s8 r = 0;
        if (UB(s,0x82) != 2) {
            if (UB(s,0x82) != 0xF) {
                r = func_8007898C(a);
            }
        }
        switch (UB(s,0x82)) {
        case 0xD: case 0xE: case 0x26:
            if (r) {
                if (W(s,0x88) & 0x40000000) {
                    Pt *pp = (Pt *)P(s,0x44);
                    if (pp) {
                        SETPT(pp);
                        F(s,0x3C) = func_800461D4(a + 0x24, s + 0x24);
                        func_800779C4(a);
                        func_800175C0(z, 2, 0x20000, a + 0x24, 0, 1);
                        func_80077960(a, 0x3E);
                    }
                }
            }
            break;
        case 0x13: case 0x14:
            if (!r) {
                if (W(a,0x58) & 4) {
                    if (H(a,0x7A) == 1) {
                        func_8007AD88(a);
                    }
                    if (P(s,0x40) == 0 && P(a,0x20) == P(D_8010A500,0x20)) {
                        { u8 **pd = &D_8010A500; func_8007C72C(a, *pd, 0); }
                    }
                }
            }
            break;
        default:
            if (!r) {
                Pt *pp = (Pt *)P(s,0x44);
                u8 *q = s + 0x24;
                if (pp == 0) {
                    if ((W(a,0x58) & 4) && H(a,0x7A) == 1) {
                        func_8007AD88(a);
                    }
                } else {
                    SETPT(pp);
                    F(s,0x3C) = func_800461D4(a + 0x24, q);
                    func_80077960(a, 0x10);
                }
            }
            break;
        }
        if (!r) {
            if (H(a,0x7A) != 4) {
                if (H(a,0x7A) != 0x81) {
                    if (W(a,0x58) & 4) {
                        u8 t;
                        if (P(s,0x44) == 0 || (t = UB(s,0x82), (t == 0xD || t == 0x26)) || t == 0xE) {
                            func_8007AD88(a);
                        }
                    }
                }
            }
            if (H(a,0x7A) == 1) {
                if (H(a,0x7C) == 1) {
                    func_80077ED8(a);
                } else {
                    func_80077E94(a);
                }
            }
        }
        break;
    }
    case 0x2D:
        func_8007AA40(a, s + 0x18, &sp30);
        func_8007AABC(a, sp30, 0.1f);
        break;
    case 0x7:
        if (!func_8007C890(a, 1)) {
            V(s,0x18) = V(P(s,0x40),0x24);
            if (func_8007AA40(a, s + 0x18, &sp34)) {
                H(a,0x7C) = 1;
                UB(s,0x7F) = 1;
                func_80002BD0(a, 0x124);
                func_80077960(a, 1);
            } else {
                func_8007AABC(a, sp34, 0.1f);
            }
            func_8007C72C(a, P(s,0x40), 0);
        }
        break;
    case 0xE:
        if (ANIMEND) {
            func_80077E94(a);
        }
        func_8007C3F0(a, 0);
        break;
    case 0xA6:
        if (!func_8007C890(a, 1)) {
            if (!func_8007AA40(a, s + 0x18, &sp38) && !(func_80045590(a + 0x24, s + 0x18) < 1.0f)) {
                func_8007AABC(a, sp38, 0.2f);
            } else {
                func_80077E94(a);
            }
        }
        break;
    case 0xB:
        if (!func_8007C890(a, 1)) {
            if (func_8007AA40(a, s + 0x18, &sp3C) || func_80045590(a + 0x24, s + 0x18) < 1.0f) {
                if (!func_8007C3F0(a, 1)) {
                    func_80077E94(a);
                }
            } else {
                func_80002BD0(a, 0x14D);
                func_8007AABC(a, sp3C, 0.2f);
            }
            func_8007C72C(a, P(s,0x40), 0);
        }
        break;
    case 0xC:
        if (ANIMEND) {
            func_80077960(a, 0xD);
        }
        break;
    case 0xD: {
        s32 snd;
        flag = 1;
        switch (H(a,0x7C)) {
        case 6: case 10:
            UB(s,0x7F) = 0;
            func_80002BD0(a, 0x66);
            flag = 0;
            func_80077960(a, 0xC);
            break;
        case 2: case 5:
            UB(s,0x7F) = 0;
            func_80002BD0(a, 0x25);
            flag = 0;
            func_80077960(a, 0xC);
            break;
        case 0: case 1: case 3: case 4: case 7: case 8: case 9: case 11: case 12:
            break;
        }
        func_8007C72C(a, 0, s + 0x18);
        if (flag) {
            u8 *t = func_8007847C(a);
            P(s,0x40) = t;
            if (t) {
                V(s,0x18) = V(t,0x24);
            }
            if (func_8007AA40(a, s + 0x18, &sp40)) {
                if (!func_8007C3F0(a, 1)) {
                    switch (func_80045CF8(2)) {
                    case 0: {
                        snd = -1;
                        switch (H(a,0x7C)) {
                        case 1:
                            snd = func_80045CF8(2) + 0x1DE;
                            break;
                        case 0: case 3:
                            snd = B(M,0xE) ? 0x2ED : 0x2E9;
                            break;
                        case 2: case 4: case 5: case 6: case 7: case 8: case 9: case 10: case 11: case 12:
                            break;
                        }
                        if (snd != -1) {
                            func_80002BD0(a, snd);
                            func_80077960(a, 0xE);
                        } else {
                            func_80077E94(a);
                        }
                        break;
                    }
                    case 1: {
                        E8 *e = &D_800C469C[B(M,0xE)];
                        switch (H(a,0x7C)) {
                        case 0: case 1: case 3:
                            func_80002BD0(a, 0x110);
                            func_80084338(e->unk5C, a + 0x24);
                            break;
                        case 2:
                            func_80002BD0(a, 0x115);
                            func_80084338(e->unk5C, a + 0x24);
                            break;
                        case 10:
                            func_80002BD0(a, 0x11A);
                            func_80084338(e->unk5C, a + 0x24);
                            break;
                        case 4: case 5: case 6: case 7: case 8: case 9:
                            break;
                        }
                        func_80077960(a, 0xE);
                        break;
                    }
                    }
                }
            } else {
                func_8007AABC(a, sp40, 0.2f);
                func_80002BD0(a, 0x15F);
                H(a,0x7C) = 3;
                UB(s,0x7F) = 3;
                F(M,0x34) = 0.023926672f;
                F(a,0x24) += F(M,0x34) * func_800829A0(F(a,0x40));
                F(a,0x2C) += F(M,0x34) * func_800829C8(F(a,0x40));
            }
        }
        break;
    }
    case 0x5:
        if (!func_8007C890(a, 1)) {
            if (D_80109B1E == 0 || !(W(s,0x88) & 0x02000000) || !func_8007835C(a)) {
                V(s,0x18) = V(P(s,0x40),0x24);
                if (!func_8007BAF8(a, s + 0x18, 6, 0xB)) {
                    func_8007B030(a);
                    func_80077960(a, 0x21);
                }
            }
        }
        break;
    case 0x87:
        CUE;
        if (F(s,0x38) > 0.0f) {
            func_8007B3B8(a, s + 0x18, s + 0x38, 0);
        } else if (!func_80078274(a) && !func_8007898C(a)) {
            func_80077E94(a);
        }
        break;
    case 0xA4:
        if (ANIMEND) {
            func_80077E94(a);
        }
        break;
    case 0x6:
        CUE;
        if (!func_8007C3F0(a, 0)) {
            if (F(s,0x38) > 0.0f) {
                func_8007B3B8(a, s + 0x18, s + 0x38, 0);
            } else if (!func_8007898C(a)) {
                func_80077E94(a);
            }
        }
        break;
    case 0x12:
        CUE;
        if (!func_8007C890(a, 1)) {
            if (func_800461D4(P(s,0x40) + 0x24, a + 0x24) < F(s,0x38) && func_80077E00(a)) {
                func_80002BD0(a, 0x14D);
                func_80077960(a, 4);
            } else if (!func_8007C3F0(a, 0)) {
                if (F(s,0x38) > 0.0f) {
                    func_8007B3B8(a, s + 0x18, s + 0x38, 0);
                } else {
                    func_80077960(a, 0x13);
                }
            }
        }
        break;
    case 0x13:
    {
        u8 *q = s + 0x24;
        func_8007AB18(a, q, 0.2f);
        if (!func_8007C890(a, 1) && !func_8007C3F0(a, 0)) {
            u8 *t = P(s,0x30);
            if (t && H(t,0x7A) != 4) {
                H(a,0x7C) = 1;
                UB(s,0x7F) = 0;
                func_80002BD0(a, 0x14D);
                if (P(t,0x20) == P(a,0x20)) {
                    W(t,0x60) |= 8;
                } else {
                    W(t,0x60) &= ~8;
                }
                W(t,0x60) |= 0x100800;
            } else {
                F(s,0x34) = F(s,0x3C) = func_800461D4(a + 0x24, q);
                func_80077960(a, 0x14);
            }
        }
        break;
    }
    case 0x14:
        if (!func_8007C890(a, 1)) {
            u8 *t = P(s,0x30);
            if (t && H(t,0x7A) != 4) {
                func_80077960(a, 0x13);
            } else if (F(s,0x3C) > 0.0f) {
                func_8007B3B8(a, s + 0x24, s + 0x3C, 0);
            } else if (!func_8007C3F0(a, 1)) {
                V(s,0x18) = V(P(s,0x40),0x24);
                if (func_80077E00(a)) {
                    func_80002BD0(a, 0x14D);
                    func_80077960(a, 0xB);
                }
            }
        }
        break;
    case 0xF:
        CUE;
        if (ANIMEND) {
            func_80077960(a, 0x10);
        }
        func_8007898C(a);
        break;
    case 0x10:
        if (P(s,0x44)) {
            func_800177D4(P(a,0x20), 0x100800, a + 0x24, 1.5f);
            CUE;
            if (F(s,0x3C) > 0.0f) {
                if (W(a,0x60) & 0x1000000) {
                    if (func_80077E00(a)) {
                        func_80002BD0(a, 0x14D);
                    }
                } else {
                    func_8007B3B8(a, s + 0x24, s + 0x3C, 6);
                }
            } else {
                Pt *pp = (Pt *)P(s,0x44);
                B(s,0x86)++;
                flag = 1;
                if (B(s,0x87) < B(s,0x86)) {
                    switch (UB(s,0x82)) {
                    default:
                        B(s,0x86) = 0;
                        break;
                    case 0x28: case 0x2E:
                        UB(s,0x82) = 0;
                        goto L360;
                    case 0x2F:
                        UB(s,0x82) = 0x10;
                    L360:
                        flag = 0;
                        func_80077960(a, 0xAB);
                        break;
                    }
                }
                if (flag) {
                    SETPT(pp);
                    F(s,0x3C) = func_800461D4(a + 0x24, s + 0x24);
                }
            }
        }
        if (!func_8007898C(a)) {
            if (func_80045CF8(0x384) == 0) {
                H(a,0x7C) = 1;
                if (func_8007AB60(a)) {
                    func_80077960(a, 0xF);
                }
            }
        } else if (W(s,0x88) & 0x40000000) {
            P(s,0x44) = 0;
        }
        break;
    case 0xAB: {
        Pt *pp = (Pt *)P(s,0x44);
        func_80002BD0(a, 0x15F);
        if (func_800828D0(func_8007AABC(a, pp[B(s,0x87)].d * 0.0027777778f, 0.1f)) < 56.88889f) {
            P(s,0x44) = 0;
            func_80077E94(a);
        }
        break;
    }
    case 0x11:
        P(s,0x30) = 0;
        if (!func_8007C890(a, 1)) {
            u8 *n = P(P(P(a,0x20),0x20),0x58);
            u8 *cur = P(n,8);
            u8 *tz = P(P(s,0x40),0x20);
            u8 *best = 0;
            u8 *m;
            u8 *e;
            u8 *e2;
            while (n != 0) {
                if (cur == tz) {
                    if ((UH(n,0x26) & 0x2000) && func_80077CB4(n) && (e = P(n,4), COND(e))) {
                        best = n;
                        break;
                    }
                } else if ((UH(n,0x26) & 0x2000) && func_80077CB4(n) && (e = P(n,4), COND(e))) {
                    for (m = P(P(cur,0x20),0x58); m != 0; m = P(m,0)) {
                        if (tz == P(m,8) && (UH(m,0x26) & 0x2000) && func_80077CB4(m) && (e2 = P(m,4), COND(e2))) {
                            best = n;
                        }
                    }
                }
                n = P(n,0);
                if (n == 0) break;
                cur = P(n,8);
            }
            if (best) {
                if (func_80077D40(1, P(s,0x40)) >= 4) {
                    func_8007B030(a);
                    func_80077960(a, 0x21);
                    return;
                }
                V(s,0x24) = V(P(best,4),0x40);
                V(s,0x18) = V(s,0x24);
                F(s,0x18) += F(best,0xC) * 1.375f;
                F(s,0x1C) += F(best,0x10) * 1.375f;
                F(s,0x20) += F(best,0x14) * 1.375f;
                F(s,0x24) -= F(best,0xC) * 1.375f;
                F(s,0x28) -= F(best,0x10) * 1.375f;
                F(s,0x2C) -= F(best,0x14) * 1.375f;
                sp58.x = F(s,0x24) - F(a,0x24);
                sp58.y = F(s,0x28) - F(a,0x28);
                sp58.z = F(s,0x2C) - F(a,0x2C);
                if (func_8004F430(z, a + 0x24, &sp58, func_80045764(&sp58, &sp58))) {
                    if (!func_8007BAF8(a, s + 0x18, 6, 0xB)) {
                        P(s,0x30) = P(best,0x1C);
                        F(s,0x38) = func_800461D4(a + 0x24, s + 0x18);
                        func_80077960(a, 0x12);
                    }
                } else {
                    V(s,0x18) = V(s,0x24);
                    F(s,0x38) = func_800461D4(a + 0x24, s + 0x24);
                    func_80077960(a, 0x1E);
                }
            } else if (func_80077E00(a)) {
                V(s,0x18) = V(P(s,0x40),0x24);
                func_80002BD0(a, 0x14D);
                func_80077960(a, 0xB);
            }
        }
        break;
    case 0x1A:
        sp48.x = 2.0f * (F(P(M,4),0x78) - F(P(M,0),0x78)) + F(P(M,0),0x78);
        sp48.y = 2.0f * (F(P(M,4),0x7C) - F(P(M,0),0x7C)) + F(P(M,0),0x7C);
        sp48.z = 2.0f * (F(P(M,4),0x80) - F(P(M,0),0x80)) + F(P(M,0),0x80);
        if (!func_8007B660(a, (u8 *)&sp48)) {
            func_80077960(a, 0x15);
        }
        goto L17;
    case 0x16:
        func_80077960(a, 0x18);
    case 0x18:
        if (ANIMEND) {
            if (B(M,0xE)) {
                func_8005F664(a, 0, B(M,0xE));
                func_800015AC(a, 0);
            }
            func_8007947C(a);
            if (UB(s,0x82) != 0x1A) {
                UB(a,0x7E) = 0x10;
                W(a,0x5C) &= ~0x400;
                func_80077960(a, 0xA9);
            } else {
                func_80077960(a, 0xAA);
            }
        }
        break;
    case 0x85:
        if (BF21 == 1) {
            { u16 *cp = &D_801176E2; (*cp)++; }
        }
        func_80077960(a, 0xA2);
    case 0xA2:
        if (B(M,0xE)) {
            func_8005F664(a, 0, B(M,0xE));
            func_800015AC(a, 0);
        }
        if (ANIMEND) {
            func_8007CA84(a);
        } else {
            func_8007CAFC(a);
        }
        break;
    case 0x19:
        if (B(M,0xE)) {
            func_8005F664(a, s + 0x18, B(M,0xE));
            func_800015AC(a, 0);
        }
        goto L17;
    case 0x15:
        func_80077960(a, 0x17);
    case 0x17:
    L17:
        CUE;
        if (ANIMEND) {
            if (B(M,0xE)) {
                func_8005F664(a, 0, B(M,0xE));
                func_800015AC(a, 0);
            }
            func_8007CA84(a);
        } else {
            V(s,0x18) = V(P(M,0),0x78);
            if (B(M,0xE) && func_80045CF8(4) == 0) {
                func_80077960(a, 0x19);
            }
            func_8007CAFC(a);
        }
        break;
    case 0x1B:
        func_80077D84(0x4C, a);
        CUE;
        UB(a,0x7E) = 0x10;
        W(a,0x5C) &= ~0x400;
        func_80077960(a, 0x1C);
        break;
    case 0x1C: case 0xA9:
        if (UB(a,0x82)) {
            UB(a,0x82)--;
            break;
        }
        if (UB(s,0x82) == 4) {
            D_80102F2A--;
        }
        W(a,0x60) |= 1;
        return;
    case 0x1D:
        CUE;
        break;
    case 0x21:
        if (!func_8007C890(a, 1)) {
            func_8007A9CC(a, P(s,0x40) + 0x24, &sp68, 113.0f);
            func_8007AABC(a, sp68, 0.1f);
            if (ANIMEND) {
                s32 fl;
                if (P(s,0x40)) {
                    V3 *pv = &sp80;
                    fl = 0x20000;
                    *pv = V(a,0x24);
                    pv->y = F(P(M,4),0x7C);
                    if (BF21 == 2 || BF21 == 3) {
                        fl = 0x5E000;
                    }
                    if (!func_800158A4((u8 *)pv, P(P(P(s,0x40),0x68),4) + 0xA8, P(a,0x20), &sp70, 0, 0, fl, 1, a)) {
                        func_80077E94(a);
                    } else {
                        func_80077960(a, 0x22);
                    }
                } else {
                    func_80077E94(a);
                }
            }
        }
        break;
    case 0x1F:
        if (func_8007C890(a, 1)) {
            break;
        }
        if (W(M,0x14) & 0x40) {
            if (!func_8007B660(a, P(s,0x40) + 0x24)) {
                func_80077960(a, 0x20);
            }
        }
    case 0x1E: case 0x20:
        if (!func_8007C890(a, 1)) {
            if (F(s,0x38) > 0.0f) {
                func_8007B3B8(a, s + 0x18, s + 0x38, H(a,0x7A) == 0x1F || H(a,0x7A) == 0x20);
                if ((H(a,0x7A) == 0x1E || H(a,0x7A) == 0x20) && func_80045CF8(0xF) == 0) {
                    u8 *t = func_8007847C(a);
                    P(s,0x40) = t;
                    if (func_8007C214(a, t)) {
                        func_800175C0(z, 2, 0x20000, a + 0x24, 0, 1);
                        func_80077960(a, 0x1F);
                    }
                }
                if ((W(a,0x60) & 0x1000000) || (P(s,0x40) && func_800461D4(a + 0x24, P(s,0x40) + 0x24) < F(s,0x38))) {
                    func_8007947C(a);
                    if (P(s,0x40)) {
                        func_8007B030(a);
                        func_80077960(a, 0x21);
                    } else {
                        func_80077960(a, 1);
                        func_80077E94(a);
                    }
                }
            } else {
                func_8007947C(a);
                if (!func_8007C3F0(a, 0)) {
                    func_80077E94(a);
                }
            }
        }
        break;
    case 0x23:
        if (!func_8007C890(a, 1) && func_80045CF8(5) == 0) {
            func_80077960(a, 0x22);
        }
        break;
    case 0x22:
        if (!func_8007C890(a, 1)) {
            func_8007A9CC(a, P(s,0x40) + 0x24, &sp90, 113.0f);
            if (UB(s,0x82) != 0xA && UB(s,0x82) != 0xB) {
                func_8007AABC(a, sp90, 0.2f);
            }
            if (!func_8007C72C(a, P(s,0x40), 0) && UB(s,0x82) != 0xA && UB(s,0x82) != 0xB && !func_8007C3F0(a, 0)) {
                func_80077E94(a);
            }
            if (!func_8007B660(a, P(s,0x40) + 0x24)) {
                if (func_80045CF8(8) == 0) {
                    func_80077960(a, 0x23);
                } else if (func_80045CF8(0xF) == 0) {
                    func_80077960(a, 0x24);
                } else if (!func_8007C3F0(a, 0)) {
                    func_80077960(a, 1);
                }
            } else {
                u8 *m = M;
                if (W(m,0x14) & 0x10) {
                    if (H(a,0x7C) != 2) {
                        if (H(a,0x7C) < 3) {
                            if (H(a,0x7C) >= 0) {
                                switch (B(m,0xE)) {
                                default:
                                    func_80002BD0(a, 0x14D);
                                    break;
                                case 0x14: case 0x15:
                                    func_80002BD0(a, 0x1B4);
                                    break;
                                }
                            }
                        }
                    } else {
                        func_80002BD0(a, 0x10B);
                    }
                }
            }
        }
        break;
    case 0x24:
        if (ANIMEND) {
            E8 *e = &D_800C469C[B(M,0xE)];
            switch (H(a,0x7C)) {
            case 0: case 1: case 3:
                func_80002BD0(a, 0x110);
                func_80084338(e->unk5C, a + 0x24);
                break;
            case 2:
                func_80002BD0(a, 0x115);
                func_80084338(e->unk5C, a + 0x24);
                break;
            case 10:
                func_80002BD0(a, 0x11A);
                func_80084338(e->unk5C, a + 0x24);
                break;
            case 4: case 5: case 6: case 7: case 8: case 9:
                break;
            }
            func_80077960(a, 0x25);
        }
        break;
    case 0x25:
        if (ANIMEND) {
            if (!func_8007C3F0(a, 0)) {
                func_80077E94(a);
            }
        }
        break;
    case 0x35:
        if (!func_8007C890(a, 1)) {
            func_8007AB18(a, P(s,0x40) + 0x24, 0.2f);
            if (ANIMEND) {
                func_80077960(a, 1);
            }
        }
        break;
    case 0x2E:
        if (!func_8007C890(a, 1)) {
            u8 *o;
            f32 h;
            f32 bestd = 65536.0f;
            u8 *bo = 0;
            f32 d;
            f32 y;
            u8 *from;
            for (o = P(z,0x14); o != 0; o = P(o,0x14)) {
                V3 *pv = &sp70;
                if ((UW(o,0x5C) >> 17) & 2) {
                    d = 1.0f; d = 2.0f; d = 3.0f; d = 4.0f; d = 5.0f; d = 6.0f; d = 7.0f; d = 8.0f;
                    h = F(P(o,0x3C),0x2C);
                    h -= F(P(o,0x3C),0x28);
                    *pv = V(o,0x24);
                    pv->y += h;
                    pv->x -= h * func_8008292C(F(o,0x34));
                    h *= func_80082968(F(o,0x34));
                    pv->z -= h;
                    { f32 lim = F(s,0x1C); y = F(a,0x28);
                    if (y < lim) {
                        if (!(F(o,0x28) < y)) continue;
                        from = s + 0x18;
                    } else {
                        if (!(pv->y < y + 1.0)) continue;
                        from = a + 0x24;
                    } }
                    d = func_800461D4(from, (u8 *)pv);
                    if (d < bestd) {
                        bestd = d;
                        bo = o;
                    }
                }
            }
            if (bo == 0) {
                V(s,0x18) = V(P(s,0x40),0x24);
                if (!func_8007C3F0(a, 1)) {
                    V(s,0x18) = V(P(s,0x40),0x24);
                    if (func_80077E00(a)) {
                        func_80002BD0(a, 0x14D);
                        func_80077960(a, 0xB);
                    }
                }
            } else {
                f32 h2;
                h2 = F(P(bo,0x3C),0x2C);
                h2 -= F(P(bo,0x3C),0x28);
                sp98 = V(bo,0x24);
                spA8 = sp98;
                spA8.y += h2;
                sp98.x += func_8008292C(F(bo,0x34)) * 0.5f;
                sp98.z += func_80082968(F(bo,0x34)) * 0.5f;
                h2 += 0.5f;
                spA8.x -= h2 * func_8008292C(F(bo,0x34));
                h2 *= func_80082968(F(bo,0x34));
                spA8.z -= h2;
                if (F(s,0x1C) > F(a,0x28)) {
                    V(s,0x18) = sp98;
                    V(s,0x24) = spA8;
                } else {
                    V(s,0x18) = spA8;
                    V(s,0x24) = sp98;
                }
                F(s,0x38) = func_800461D4(a + 0x24, s + 0x18);
                F(s,0x3C) = func_800461D4(s + 0x18, s + 0x24);
                if (!func_8007BAF8(a, s + 0x18, 6, 0xB)) {
                    func_80077960(a, 0x2F);
                }
            }
        }
        break;
    case 0x2F:
        if (F(s,0x38) > 0.0f) {
            func_8007B3B8(a, s + 0x18, s + 0x38, 0);
        } else {
            func_80077960(a, 0x30);
        }
        break;
    case 0x30:
        if (F(s,0x3C) > 0.0f) {
            func_8007B3B8(a, s + 0x24, s + 0x3C, 6);
        } else {
            func_80077E94(a);
        }
        break;
    case 0x31:
        F(s,0x38) = func_80045D2C(60.0f) + 60.0f;
        func_80077960(a, 0x32);
        break;
    case 0x32:
        F(s,0x38) -= 1.0f;
        if (F(s,0x38) < 0.0f) {
            func_80077E94(a);
        }
        break;
    case 0x36:
        func_80117888(a);
        break;
    case 0x37:
        func_80118188(a);
        break;
    case 0x38:
        func_80079C14(a);
        func_80077960(a, 0x39);
        break;
    case 0x39:
        if (ANIMEND) {
            F(a,0x40) += 2048.0f;
            func_80002BD0(a, 0x1FE);
            UB(s,0x82) = 0xC;
            func_80077960(a, 0x3A);
        } else if (H(M,0x94) >= 0x1E && B(M,0xE)) {
            func_8005F664(a, 0, B(M,0xE));
            func_800015AC(a, 0);
        }
        break;
    case 0x3B:
        if (!func_8007A9CC(a, D_8010A500 + 0x24, &spB8, 56.88889f)) {
            moved = 1;
            F(a,0x24) += func_800829A0(F(a,0x40)) * 0.047853343f;
            F(a,0x2C) += func_800829C8(F(a,0x40)) * 0.047853343f;
            F(M,0x34) = 0.047853343f;
            func_8007AABC(a, spB8, 0.1f);
            goto post;
        } else {
            func_80002BD0(a, 0x1FE);
            func_80077960(a, 0x3A);
        }
        break;
    case 0x3A:
        V(s,0x18) = V(D_8010A500,0x24);
    {
        u8 **pd = &D_8010A500;
        if (!func_8007A9CC(a, *pd + 0x24, &spBC, 512.0f)) {
            func_80002BD0(a, 0x1FF);
            func_80077960(a, 0x3B);
        }
        if (!func_8007C094(a, *pd + 0x24, 4.0f) || (W(a,0x60) & 4)) {
            func_80002BD0(a, 0x11F);
            func_80077960(a, 0x3C);
        }
        break;
    }
    case 0x3C:
        if (ANIMEND) {
            func_800779C4(a);
            func_800015AC(a, 4);
            UB(s,0x82) = 0;
            if (func_80077E00(a)) {
                func_80002BD0(a, 0x14D);
                func_80077960(a, 0xB);
            }
        }
        break;
    case 0x3F:
        if (W(a,0x58) & 4) {
            func_800779C4(a);
        }
        break;
    case 0x3D:
        if (func_8007C890(a, 0) || !func_8007B660(a, P(s,0x40) + 0x24)) {
            func_80077960(a, 0x3E);
        }
    case 0x8: case 0x9: case 0x3E: {
        s32 n;
        u8 *t;
        Pt *pp;
        func_800177D4(P(a,0x20), 0x100800, a + 0x24, 3.5f);
        switch (H(a,0x7A)) {
        case 9:
            n = 5;
            if ((W(a,0x58) & 4) && func_80045CF8(0x96) == 0) {
                func_800847D4(a + 0x24, a);
            }
            break;
        default:
        case 0x3E:
            n = 4;
            if (func_80045CF8(0xF) == 0) {
                t = func_8007847C(a);
                P(s,0x40) = t;
                if (func_8007C214(a, t)) {
                    func_80077960(a, 0x3D);
                }
            }
        case 8:
            n = 4;
            break;
        }
        if (P(s,0x40) && func_800461D4(a + 0x24, P(s,0x40) + 0x24) < 4.0f) {
            switch (UB(s,0x82)) {
            default:
                P(s,0x44) = 0;
                UB(s,0x82) = 0;
                V(s,0x18) = V(P(s,0x40),0x24);
                if (func_80077E00(a)) {
                    func_80002BD0(a, 0x14D);
                    func_80077960(a, 0xB);
                }
                break;
            case 0xE:
                P(s,0x44) = 0;
                UB(s,0x82) = 9;
                func_80077960(a, 1);
                break;
            case 0x10: case 0x11: case 0x13: case 0x14: case 0x1B: case 0x1C: case 0x2B:
                break;
            }
        }
        pp = (Pt *)P(s,0x44);
        if (pp) {
            if (F(s,0x3C) > 0.0f) {
                func_8007B3B8(a, s + 0x24, s + 0x3C, n);
            } else {
                B(s,0x86)++;
                if (B(s,0x87) < B(s,0x86)) {
                    P(s,0x44) = 0;
                    switch (UB(s,0x82)) {
                    default:
                        func_8008168C(a, (u8 *)pp);
                        UB(s,0x82) = 0;
                        func_80077E94(a);
                        break;
                    case 0xE:
                        func_8008168C(a, (u8 *)pp);
                        UB(s,0x82) = 9;
                        func_80077E94(a);
                        break;
                    case 0x10:
                        func_80002BD0(a, 0x14D);
                        func_80077960(a, 4);
                        break;
                    case 0x11:
                        func_80002BD0(a, 0x2D9);
                        func_80077960(a, 0xA);
                        break;
                    case 0x13:
                        UB(s,0x82) = 0x14;
                    L13x:
                        func_80077E94(a);
                        break;
                    case 0x1B: case 0x1C: case 0x2B:
                        W(a,0x60) |= 1;
                        goto L13x;
                    }
                } else {
                    SETPT(pp);
                    F(s,0x3C) = func_800461D4(a + 0x24, s + 0x24);
                    func_8007B3B8(a, s + 0x24, s + 0x3C, n);
                }
            }
        }
        break;
    }
    case 0x41:
        if (P(s,0x40) == 0) {
            P(s,0x40) = func_8007847C(a);
            break;
        }
        if (!func_8007C890(a, 1)) {
            u8 *o = P(s,0x70);
            u8 *os = P(o,0x6C);
            V(os,0) = V(P(s,0x40),0x24);
            func_80002BD0(a, 0x20D);
            F(a,0x24) = F(o,0x24) - func_800829A0(F(o,0x40)) * 1.5f;
            F(a,0x2C) = F(o,0x2C) - func_800829C8(F(o,0x40)) * 1.5f;
            F(a,0x40) = F(o,0x40);
            if (H(o,0x7A) == 2 && (W(a,0x60) & 0x3000) && func_8007AA40(a, os, &spC0) && func_8007C214(a, P(s,0x40))) {
                H(o,0x7A) = 3;
            }
            CUE;
            if ((W(a,0x60) & 2) || func_800461D4(a + 0x24, os) < 8.0f) {
                H(o,0x7A) = 5;
                P(s,0x70) = 0;
                func_800015AC(a, 4);
                func_800779C4(a);
                func_80077E94(a);
            }
        }
        break;
    case 0x46:
        V(s,0x18) = V(D_8010A500,0x24);
        func_80081568(a);
        func_8007C72C(a, D_8010A500, 0);
        if (UB(s,0x81)) {
            func_80074C34(a, D_800CEB34[UB(s,0x81)].a, D_800CEB34[UB(s,0x81)].b);
            func_80002BD0(a, 0x2F0);
            UB(s,0x81) = 0;
            break;
        }
        if (!(W(a,0x60) & 0x10000000)) {
            Pt *pp = (Pt *)P(s,0x44);
            if (pp) {
                SETPT(pp);
                F(s,0x3C) = func_800461D4(a + 0x24, s + 0x24);
                if (!func_800158A4(a + 0x24, s + 0x24, P(a,0x20), &sp98, 0, 0, 0, 1, 0)) {
                    P(s,0x44) = 0;
                    UB(s,0x82) = 0x14;
                    func_80077E94(a);
                    break;
                }
                func_800779C4(a);
    case 0x40:
                func_80077960(a, 0x3E);
                break;
            }
            UB(s,0x82) = 0x14;
            func_80077E94(a);
        }
        break;
    case 0x47:
        F(s,0x48) = 0.0f;
        W(s,0x88) |= 0x40000000;
        F(s,0x38) = func_80045CF8(3);
        sp98 = V(a,0x24);
        func_80077C00(a);
        V(a,0x24) = sp98;
        func_80077960(a, 0x80);
        break;
    case 0x4A:
        if (!func_8007B660(a, D_8010A500 + 0x24)) {
            func_80077960(a, 0x80);
        }
    case 0x48: case 0x49: case 0x80:
        CUE;
        func_8007AB18(a, D_8010A500 + 0x24, 0.1f);
        switch (H(a,0x7A)) {
        case 0x80:
            if (func_80045CF8(0x3C) == 0 || F(a,0x28) < F(D_8010A500,0x28) + F(s,0x38)) {
                F(s,0x48) *= 0.5f;
            } else if (F(M,8) + 1.0f < F(a,0x28)) {
                if (F(s,0x48) > -3.0f) {
                    F(s,0x48) -= 0.65333337f;
                }
            } else {
                F(s,0x48) *= 0.25f;
            }
            break;
        case 0x49:
            F(s,0x48) *= 0.5f;
            if (func_80045CF8(0xF) == 0) {
                func_80077960(a, 0x48);
            }
            break;
        }
        F(a,0x28) += F(s,0x48) * 0.033333335f;
        if (func_80045CF8(0x1E) == 0 && func_800828D0(F(a,0x28) - (F(D_8010A500,0x28) + F(s,0x38))) < 2.0f && func_8007C214(a, D_8010A500)) {
            func_80077960(a, 0x4A);
        }
        if (F(a,0x28) < F(M,8) + (F(M,0x38) + 0.25)) {
            UB(s,0x82) = 0;
            func_80002BD0(a, 0x211);
            H(a,0x7C) = 0;
            UB(s,0x7F) = 0;
            func_80077960(a, 4);
        }
        break;
    case 0x4B:
        F(s,0x48) -= 0.32666668f;
        F(a,0x28) += F(s,0x48) * 0.033333335f;
        F(a,0x40) += func_80045CF8(0x40);
        if (F(a,0x28) < F(M,8) + F(M,0x38)) {
            F(a,0x28) = F(M,8);
            func_80002BD0(a, 0x210);
            func_80077960(a, 0x15);
        }
        break;
    case 0x71:
        CUE;
        if (ANIMEND) {
            if (B(M,0xE) && (B(M,0xE) != 4 || W(s,0x88) >= 0)) {
                W(s,0x88) |= 0x80000000;
                func_8005F664(a, 0, B(M,0xE));
                func_800015AC(a, 0);
            }
            func_80002BD0(a, 0x205);
            H(a,0x7C) = 0xD;
            UB(s,0x7F) = 0xD;
            func_80077960(a, 0x72);
        }
        if (!(W(a,0x60) & 0x80)) {
            F(s,0x34) += 1.0f;
            if (F(s,0x34) > 7.0f) {
                func_8007CC00(a);
                func_80077960(a, 0x74);
            }
        } else {
            s16 t = -func_80045CF8(0x20);
            func_80017E14(a, t, t, t);
            func_80017E14(a, 0, (s16)func_80045CF8(0x40), (s16)func_80045CF8(0x40));
            F(s,0x34) = 0.0f;
        }
        break;
    case 0x72:
        CUE;
        if (!(W(a,0x60) & 0x80)) {
            F(s,0x34) += 1.0f;
            if (F(s,0x34) > 7.0f) {
                func_80002BD0(a, 0x207);
                func_80077960(a, 0x73);
            }
        } else {
            s16 t = -func_80045CF8(0x20);
            func_80017E14(a, t, t, t);
            func_80017E14(a, 0, (s16)func_80045CF8(0x40), (s16)func_80045CF8(0x40));
            F(s,0x34) = 0.0f;
        }
        break;
    case 0x73:
        CUE;
        if (ANIMEND) {
            func_8007CC00(a);
            func_80077960(a, 0x74);
        }
        break;
    case 0x74:
        CUE;
        if (ANIMEND) {
            func_800779C4(a);
            H(a,0x7C) = 0;
            UB(s,0x7F) = 0;
            func_80076C80(a);
        }
        break;
    case 0x75:
        CUE;
        UH(s,0x76)--;
        if ((s16)UH(s,0x76) <= 0) {
            H(a,0x7C) = 0xB;
            UB(s,0x7F) = 0xB;
            func_80002BD0(a, 0x2D8);
            func_80077960(a, 0x76);
        }
        break;
    case 0x76:
        CUE;
        if (ANIMEND) {
            H(a,0x7C) = 0;
            UB(s,0x7F) = 0;
            W(a,0x5C) |= 0x200;
            if (B(M,0xE) == 0 && BF21 != 3) {
                func_800015AC(a, 4);
            }
            func_80002BD0(a, 0x14D);
            if (D_80117734 == 0 && !func_8007C214(a, P(s,0x40))) {
                func_80077B58(a);
            }
            if (UB(s,0x82) == 0x1E) {
                H(s,0x74) = D_80117408;
                func_800779C4(a);
                W(s,0x88) |= 0x08000000;
            }
            func_80076C80(a);
        }
        break;
    case 0x77: {
        u8 *t;
        if ((W(a,0x58) & 4) && func_80045CF8(0x96) == 0) {
            func_800846A8(a + 0x24, a);
        }
        t = func_8007847C(a);
        P(s,0x40) = t;
        if (t) {
            func_8007C72C(a, t, 0);
        } else {
            Pt *pp = (Pt *)P(s,0x44);
            D_80113020--;
            D_8010302C++;
            { s32 *pD = &D_80109688; func_80073AF8(0, *pD, func_80087100(0xF1), -1, -1, 1, 0, 0, 3, 0, 0); }
            if (pp) {
                SETPT(pp);
                F(s,0x3C) = func_800461D4(a + 0x24, s + 0x24);
                UB(s,0x82) = 0x10;
                func_80077960(a, 9);
            } else {
                UB(s,0x82) = 0x10;
                func_80002BD0(a, 0x14D);
                func_80077960(a, 4);
            }
        }
        if (W(a,0x60) & 2) {
            F(a,0x74) = 0.0f;
        }
        break;
    }
    case 0x83:
        func_80081568(a);
        if (!(W(a,0x60) & 0x10000000)) {
            if (H(a,0x7C) != 1) {
                func_80002BD0(a, 0x14D);
            } else {
                func_80002BD0(a, 0x124);
            }
            func_80077960(a, 4);
        }
        break;
    case 0x86:
        if (func_800828D0(func_8007AABC(a, F(s,0x10), 0.1f)) < 5.0f) {
            func_80077960(a, 1);
        }
        break;
    case 0xA8:
        if ((W(a,0x58) & 4) && func_80045CF8(0x96) == 0) {
            func_80002BD0(a, D_800C9D38[func_80045CF8(2)]);
            func_800847D4(a + 0x24, a);
        }
    case 0x88:
        if (W(a,0x60) & 0x3000) {
            u8 **pd = &D_8010A500;
            if (func_8007A9CC(*pd, a + 0x24, &spC4, 512.0f) && func_8007C094(a, *pd + 0x24, 15.0f)) {
                if (H(a,0x7A) == 0x88) {
                    func_80002BD0(a, 0x20A);
                    func_80077960(a, 0xA8);
                }
                func_80081568(a);
            } else {
                func_80077960(a, 0x88);
                func_80077E94(a);
            }
        }
        break;
    }
done:
    moved = 1;
post:
    if (func_80002EF0(a)) {
        D_801176EA++;
    }
    switch (H(a,0x7A)) {
    case 0x1B: case 0x1C: case 0x1D:
        if (!(UH(M,0xC) & 8)) {
            W(a,0x60) |= 0x1000000;
        }
    case 0x1: case 0x2: case 0x4: case 0x5: case 0x7: case 0xA: case 0xB: case 0xF: case 0x11:
    case 0x22: case 0x23: case 0x25: case 0x26: case 0x2E: case 0x31: case 0x32: case 0x33: case 0x35:
    case 0x3A: case 0x3F: case 0x40: case 0x42: case 0x4F: case 0x50: case 0x58: case 0x59: case 0x5A:
    case 0x66: case 0x77: case 0x81: case 0x8A: case 0x8B: case 0x94: case 0x95: case 0x96:
        if (!(W(a,0x60) & 0x1000000)) {
            if (UH(M,0xC) & 8) {
                F(a,0x28) = F(M,8) + F(M,0x38);
            }
            break;
        }
    case 0:
    default:
        func_80079928(z, a, &spC8, &spCC, 0x100010);
        func_800794C0(z, a);
        break;
    case 0x15: case 0x17: case 0x19: case 0x1A: case 0x85: case 0xA2:
        if (D_80108F78 == 0x1D) {
            func_80079B08(z, a, &spD0, &spD4, 0);
        } else {
            func_80079928(z, a, &spD0, &spD4, 0);
        }
        func_800794C0(z, a);
        break;
    case 0x37:
        func_80079928(z, a, &spD8, &spDC, 0);
    case 0x8: case 0x9: case 0x10: case 0x36: case 0x3D: case 0x3E:
        func_800794C0(z, a);
        break;
    case 0x2C:
        if (!func_8007B660(a, P(s,0x40) + 0x24)) {
            func_80077960(a, 0x2B);
        }
    case 0x2B:
        P(s,0x40) = D_8010A500;
        func_8007C72C(a, D_8010A500, 0);
        if (func_8007C214(a, P(s,0x40))) {
            func_80077960(a, 0x2C);
        }
        moved = 0;
        break;
    case 0x2A:
        if (!func_8007B660(a, P(s,0x40) + 0x24)) {
            func_80077960(a, 0x29);
        }
    case 0x29:
        P(s,0x40) = D_8010A500;
        F(a,0x40) += 2048.0f;
        func_8007C72C(a, P(s,0x40), 0);
        F(a,0x40) -= 2048.0f;
        if (func_800828D0(func_80000A30(func_80082A70(F(P(s,0x40),0x24) - F(a,0x24), F(P(s,0x40),0x2C) - F(a,0x2C)) * 651.8986f, F(a,0x40) + 2048.0f)) < 56.88889f) {
            func_80077960(a, 0x2A);
        }
        moved = 0;
        break;
    case 0x3: case 0x16: case 0x18: case 0x27: case 0x28: case 0x47: case 0x48: case 0x49: case 0x4A:
    case 0x4B: case 0x80: case 0x89: case 0xA3: case 0xA9: case 0xAA: case 0xAD:
        break;
    }
    D_80108788 = a;
    if ((W(s,0x88) & 0x40000000) && UH(a,0x78) == 1) {
        switch (H(a,0x7C)) {
        case 0: case 1: case 2: case 3: case 0xA: {
            u8 *t = P(s,0x40);
            if (t && (UH(t,0x78) == 1 || UH(t,0x78) == 2)) {
                func_8007C72C(a, t, 0);
            }
            break;
        }
        }
    }
    if (moved) {
        if (F(a,0x24) != F(a,0x30) || F(a,0x28) != F(a,0x34) || F(a,0x2C) != F(a,0x38)) {
            W(a,0x58) |= 1;
        }
        if (W(a,0x58) & 1) {
            D_8010090A++;
        }
    }
    if (D_80115319) {
        W(a,0x60) &= 0x30005;
    } else {
        W(a,0x60) &= 1;
    }
    }
    }
    }
}
