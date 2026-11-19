typedef struct { u16 a; u16 flags; u32 b; } Ent30C7C;
extern u32 D_800BFF10;
extern Ent30C7C *D_800BFF04;
extern u16 D_800E1608;
extern u16 D_800E160A;

s32 func_80030C7C(void) {
    u16 i;

    switch (D_800BFF10) {
    case 7:
        return 0x76;
    case 4:
        return 0x9F;
    case 9:
        return 0x75;
    }
    for (i = 0; D_800BFF04 != NULL && i < D_800E1608; i++) {
        u16 f = D_800BFF04[i].flags;
        if ((f & 0xF000) <= D_800E160A && !(f & 0x200)) {
            if ((f & 0xF) == 2) {
                return 0x9F;
            }
            if ((f & 0xF) == 0) {
                return 0x9E;
            }
        }
    }
    return 0xA0;
}
