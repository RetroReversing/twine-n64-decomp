typedef struct { s16 id; u16 flags; u16 c; u16 d; } E315;
typedef struct { u8 pad[2]; s8 ch; } O315;
s16 func_80030898(void);
O315 *func_80087100(u16);
extern E315 *D_800BFF04;
extern u16 D_800E1608;

void func_800315E0(s32 arg0) {
    s16 i = arg0 - 1;
    O315 *o;

    if (i < D_800E1608) {
        if (i >= 0 && (D_800BFF04[i].flags & 0x200)) {
            D_800BFF04[i].flags &= ~0x200;
            D_800BFF04[i].id = func_80030898();
            o = func_80087100(D_800BFF04[i].c);
            if (o != NULL) {
                o->ch = ((u8 *)&D_800BFF04[i])[1] + 'A';
            }
            o = func_80087100(D_800BFF04[i].d);
            if (o != NULL) {
                o->ch = ((u8 *)&D_800BFF04[i])[1] + 'A';
            }
        }
    }
}
