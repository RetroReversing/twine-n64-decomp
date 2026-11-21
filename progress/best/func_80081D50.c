typedef struct { s8 idx; u8 flags; u16 mask; u16 val; u8 type; u8 pad; } SlotEnt;
typedef struct { u8 a; u8 b; } SlotOut;
typedef struct { u8 first; u8 pad[0x9F]; } BonusEnt;

s32 func_8002D0BC();
extern u16 D_800C9D40;
extern u8 D_800CEEB0;
extern s32 D_80112E98[];
extern BonusEnt sBonusSlots[];

void func_80081D50(SlotEnt *arg0, s32 arg1, s32 arg2, SlotOut *arg3) {
    u16 i = 0;
    s32 s1;
    s32 idx;
    u16 a2;
    u8 v;
    SlotOut *o;

    if (arg0[0].idx == -1) return;
    do {
        s1 = 0;
        idx = arg0[i].idx;
        if (D_800CEEB0 == 2 || (u16)func_8002D0BC(0xA3, arg1 & 0xFF)) {
            a2 = 0;
            if (arg0[i].flags & 0x10) {
                a2 = sBonusSlots[arg1 & 0xFF].first;
            }
            if ((arg0[i].mask == 0 && a2 == 0) || !((((arg2 & arg0[i].mask) != 0) == (arg0[i].flags & 1)) && a2 == 0)) {
                if (arg0[i].val != 0 || arg0[i].type != 0) {
                    if (arg0[i].type != 0) {
                        s1 = D_80112E98[arg0[i].type];
                    } else {
                        s1 = (arg2 & arg0[i].val) | a2;
                    }
                    if (arg0[i].flags & 8) {
                        s1 = (s1 == arg0[i].val);
                    }
                    if (arg0[i].flags & 2) {
                        arg3[idx].a |= 0x20;
                    } else {
                        arg3[idx].a &= 0xDF;
                    }
                } else {
                    o = &arg3[idx];
                    o->b = (arg0[i].flags & 4) ? 2 : 1;
                    if (arg0[i].flags & 2) {
                        o->a |= 0x40;
                    } else {
                        o->a &= 0xBF;
                    }
                }
            }
        }
        D_800C9D40 |= s1;
        s1 = s1 != 0;
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
        if ((v & 8) && (((v >> 2) ^ (v >> 3)) & 1)) {
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
    } while (arg0[i].idx != -1);
}
