void *func_800162BC(s32);
void func_800448A4(void *, s32, s32);
void func_80070ECC(void *, void *, s32, s32, s32, s32);
char *func_80087100(s32);
void func_8011CFB0(void);
void *func_8011E304(s32, s32, void *, s32);
s32 sprintf(void *, const void *, ...);
extern s32 D_800BD644;
extern s32 D_800BD654;
extern s32 D_800BD66C;
extern s32 D_800BD678;
typedef struct Label {
    u8 pad0[0x10];
    u32 color;
    u8 pad14[0x8];
    u16 f1C;
    u16 f1E;
    u16 f20;
    u16 f22;
    u8 pad24[4];
    u32 flags;
} Label;
typedef struct Info {
    u8 pad0[0x10];
    u8 flag10;
    u8 pad11;
    u8 kind;
} Info;
typedef struct Ent {
    u8 pad0[0xB4];
    Info *info;
    u8 padB8[0x182 - 0xB8];
    s8 kind182;
    u8 pad183[0x418 - 0x183];
    Label *label[3];
    u8 pad424[0x438 - 0x424];
    char buf[3][16];
} Ent;
typedef struct Obj {
    u8 pad0[0x6C];
    Ent *ent;
} Obj;
typedef struct Rec {
    u8 f0;
    u8 pad[23];
} Rec;
extern Rec D_801001A2[];
extern u8 D_801002A1;
extern s32 D_801002B4;
extern s32 D_801002C0;
extern u8 D_801002D4;
extern s32 D_80109688[];
extern u8 D_8010A4FD;
extern Obj *D_8010A500[];
extern s32 D_8011F018;
extern u16 D_8011F0EC;
extern u16 D_8011F0F0[];
extern u16 D_8011F0F8[];
extern char D_8011F2B8[][12];
extern char D_8011F378[][12];
extern Label *D_8011F2E8[][4];
extern Label *D_8011F3D0[];
extern s16 D_8011F3E0[];
extern Label *D_8011F3E8[];

#define SLOT(j) (*(Label **)((char *)ent + 0x418 + (j) * 4))
#define BUF(j) ((char *)ent + 0x438 + (j) * 16)
void func_8011D3C0(void)
{
    f32 cx = 160.0f;
    f32 cy = 120.0f;
    u16 i;
    u16 k;
    s16 j;
    u16 x;
    u16 y;
    u8 kind;
    Ent *ent;
    Ent *other;
    Label *lab;
    Label *q;
    void *s;
    u16 xx;
    u16 yy;

    switch (D_801002C0) {
    case 2:
        if (D_8010A4FD == 1) {
            cx = 80.0f;
        } else {
            cy = 60.0f;
        }
        break;
    case 3:
    case 4:
        cx = 80.0f;
        cy = 60.0f;
        break;
    }
    func_8011CFB0();
    for (i = 0; i < D_801002C0; i++) {
        if (D_80109688[i] == 0) {
            continue;
        }
        ent = D_8010A500[i]->ent;
        switch (D_801002C0) {
        default:
            x = -4;
            y = 4;
            break;
        case 2:
            if (D_8010A4FD == 0) {
                x = -4;
                y = ((-(i != 0)) & -4) | 4;
            } else {
                y = 4;
                x = ((-(i != 0)) & -4) | 8;
            }
            break;
        case 3:
        case 4:
            x = ((-(((i == 0) | (i == 2)) == 0)) & -4) | 8;
            y = ((-(i >= 2)) & -4) | 4;
            break;
        }
        for (j = 0; j < 3; j++) {
            SLOT(j) = NULL;
            if (D_801002D4 != 0) {
                if (j == 1) {
                    continue;
                }
            }
            {
                SLOT(j) = func_800162BC(ent->kind182);
                if (SLOT(j) != NULL) {
                    switch (j) {
                    case 0:
                        func_80070ECC(SLOT(j), BUF(j), (u16) (u32) ((2.0f * cx - 16.0f) + (s16) x), (u16) (u32) (2.0f * cy - 34.0f), 0xA60, 0xAAAA00FF);
                        break;
                    case 1:
                        func_80070ECC(SLOT(j), BUF(j), 0x16, (u16) (u32) (2.0f * cy - 34.0f), 0x860, 0xAAAA00FF);
                        break;
                    case 2:
                        func_80070ECC(SLOT(j), BUF(j), (u16) (u32) ((2.0f * cx - 16.0f) + (s16) x), (u16) (u32) (2.0f * cy - 24.0f), 0xA60, 0xAAAA00FF);
                        break;
                    }
                }
            }
        }
        s = D_8011F378[i];
        q = func_8011E304(0x18, 0x1E, s, i);
        q->f1E = 0x20;
        sprintf(s, &D_8011F018);
        q->f1C = 1;
        D_8011F3D0[i] = q;
        xx = (u16) (u32) cx;
        yy = (u16) (u32) cy;
        s = D_8011F2B8[i];
        q = func_8011E304(xx, yy, s, i);
        q->f1E = q->f1E | 0x20;
        sprintf(s, func_80087100(0x2E5));
        q->f1C = 3;
        q->flags = (q->flags & ~0xFC) | 0x1C;
        D_8011F3E8[i] = q;
        D_8011F3E0[i] = 0;
        kind = D_801001A2[i].f0;
        if (kind != 0) {
            q = func_800162BC(i);
            if (q != NULL) {
                func_800448A4(q, 0x13, 0x2A);
                q->f1E = 2;
                q->f22 = y + 0xC;
                q->flags = (q->flags & ~0xFC) | 0x10;
                q->f20 = D_8011F0EC + (x + 0xFFC7);
                q->color = (D_800BD66C & ~0xFF) | 0x88;
                D_8011F0F0[i] = D_8011F0EC + (x + 0xFFDB);
                D_8011F0F8[i] = y + 0x20;
                D_8011F2E8[0][i] = q;
                if (D_801002B4 > 0) {
                    for (k = 0; k < D_801002B4; k++) {
                        other = D_8010A500[k]->ent;
                        if (i == k || kind == 5) {
                            continue;
                        }
                        if (D_801002A1 == 1) {
                            if (kind == 2 && ent->info->flag10 != other->info->flag10) {
                                continue;
                            }
                            if (kind == 3 && ent->info->flag10 == other->info->flag10) {
                                continue;
                            }
                        }
                        q = func_800162BC(i);
                        if (q == NULL) {
                            continue;
                        }
                        if (D_801002A1 != 0) {
                            if (other->info->flag10 == 0) {
                                q->color = D_800BD678;
                            } else {
                                q->color = D_800BD654;
                            }
                        } else {
                            q->color = D_800BD644;
                        }
                        q->flags = (q->flags & ~0xFC) | 0xC;
                        func_800448A4(q, 0x17, 0x1B);
                        D_8011F2E8[k + 1][i] = q;
                    }
                }
            }
        }
    }
}
