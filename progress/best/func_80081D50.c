typedef struct { s8 idx; u8 flags; u16 mask; u16 val; u8 type; u8 pad; } SlotEnt;
typedef struct { u8 a; u8 b; } SlotOut;
typedef struct { u8 first; u8 pad[0x9F]; } BonusEnt;

s32 func_8002D0BC();
extern u16 D_800C9D40;
extern u8 D_800CEEB0;
extern s32 D_80112E98[];
extern BonusEnt sBonusSlots[];

#define E(n) arg0[(u16)(n)]

void func_80081D50(SlotEnt *arg0, u8 arg1, s32 arg2, SlotOut *arg3) {
    s32 i = 0;
    s32 s1;
    s32 idx;
    u8 bonus;
    s32 a2;
    u8 v;
    SlotOut *o;
    SlotEnt *e;
    s32 t1, t2, t3;
    s32 one;

    if (arg0[0].idx == -1) return;
    do {
        s1 = 0;
        idx = E(i).idx;
        if (D_800CEEB0 == 2 || (u16)func_8002D0BC(0xA3, arg1 & 0xFF)) {
            a2 = 0;
            if (E(i).flags & 0x10) {
                a2 = sBonusSlots[arg1 & 0xFF].first;
            }
            t1 = (E(i).mask != 0) | (a2 != 0);
            if (!(t1 && (t2 = ((((arg2 & E(i).mask) != 0) ^ (E(i).flags & 1)) == 0), t3 = (a2 == 0), t2 & t3))) {
                if (E(i).val != 0 || E(i).type != 0) {
                    if (E(i).type != 0) {
                        s1 = D_80112E98[E(i).type];
                    } else {
                        s1 = (arg2 & E(i).val) | a2;
                    }
                    if (E(i).flags & 8) {
                        if (s1 == E(i).val) s1 = 1; else s1 = 0;
                    }
                    if (E(i).flags & 2) {
                        arg3[idx].a |= 0x20;
                    } else {
                        arg3[idx].a &= 0xDF;
                    }
                } else {
                    o = (SlotOut *)(((unsigned int)idx * (unsigned int)sizeof(*arg3)) + (unsigned int)arg3);
                    o->b = (E(i).flags & 4) ? 2 : 1;
                    if (E(i).flags & 2) {
                        o->a |= 0x40;
                    } else {
                        o->a &= 0xBF;
                    }
                }
            }
        }
        s1 = s1 != 0;
        D_800C9D40 |= s1;
        v = arg3[idx].a;
        if (((v & 1) ^ s1) & s1) {
            arg3[idx].a = v | 2;
        } else {
            arg3[idx].a = v & 0xFD;
        }
        if (s1) {
            arg3[idx].a |= 1;
        } else {
            arg3[idx].a &= 0xFE;
        }
        if (s1) {
            arg3[idx].a |= 8;
        }
        v = arg3[idx].a;
        if ((v & 8) && ((((v >> 2) & 1) ^ ((v >> 3) & 1)) & 1)) {
            arg3[idx].a = v | 0x10;
        } else {
            arg3[idx].a &= 0xEF;
        }
        v = arg3[idx].a;
        if (v & 8) {
            arg3[idx].a = v | 4;
        } else {
            arg3[idx].a = v & 0xFB;
        }
        arg3[idx].a &= 0xF7;
        i++;
    } while (E(i).idx != -1);
}
