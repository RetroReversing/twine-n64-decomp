s32 func_80018318(void *);
s32 func_80022B60(s32);
extern s32 D_800BD64C;
extern s32 D_800BD660;
extern u8 gMenuUseTextList;
typedef struct { u8 pad[0x1C]; u8 *p1C; u8 pad2[0x30-0x20]; u8 b30; } MItems;
extern MItems *gMenuItems;

typedef struct { u8 pad0[0x10]; s32 w10; u8 pad14[0xC]; u16 x20; u16 y22; u8 pad24[4]; u32 hi:24; u32 f:6; u32 lo:2; } Win;
typedef struct { Win *a; Win *b; } Pair;
typedef struct { Pair *pair; u16 x; u16 y; u8 mode; } Rec;

void func_8002255C(Rec *arg0, s32 arg1) {
    Pair *p = arg0->pair;
    if (p != NULL) {
        if (p->b != NULL) {
            u32 m = arg0->mode;
            if (m == 0xFE) {
                p->b->y22 = arg0->y;
                p->b->x20 = arg0->x + 0xD0;
            } else if (m == 0xFF) {
                p->b->y22 = arg0->y;
                p->b->x20 = arg0->x;
            } else {
                p->b->y22 = arg0->y + func_80018318(p->a) * 11;
                p->b->x20 = arg0->x;
            }
            if (gMenuUseTextList != 0) {
                p->b->f = -((arg1 & 0xFF) == 0) & 7;
            } else {
                p->b->f = (-((arg1 & 0xFF) == 0) & 7) | 2;
            }
            if (gMenuItems != NULL && gMenuItems->p1C != NULL) {
                p->b->w10 = (((D_800BD64C & ~0xFF) | gMenuItems->b30) & ~0xFF) | gMenuItems->p1C[0x13];
            }
        }
        if (p->a != NULL) {
            u16 xx = 0xA0;
            if (arg0->mode != 0xFF) {
                xx = arg0->x;
            }
            p->a->x20 = xx;
            p->a->y22 = arg0->y;
            if (gMenuUseTextList != 0) {
                p->a->f = -((arg1 & 0xFF) == 0) & 7;
            } else {
                p->a->f = (-((arg1 & 0xFF) == 0) & 7) | 2;
            }
            if (arg0->mode == 0x80) {
                p->a->w10 = (((D_800BD64C & ~0xFF) | gMenuItems->b30) & ~0xFF) | gMenuItems->p1C[0x13];
            } else if (arg0->mode == 0x81) {
                p->a->w10 = (((D_800BD660 & ~0xFF) | gMenuItems->b30) & ~0xFF) | gMenuItems->p1C[0x13];
            } else {
                p->a->w10 = (D_800BD64C & ~0xFF) | gMenuItems->b30;
            }
        }
        if (gMenuUseTextList != 0) { func_80022B60(0); } else { func_80022B60(2); }
    }
}
