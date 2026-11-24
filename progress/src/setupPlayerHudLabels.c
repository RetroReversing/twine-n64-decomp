void *func_800162BC(s32);
void func_800448A4(void *, s32, s32);
void initTextBuffer(void *, void *, s32, s32, s32, s32);
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
    u8 pad10[2];
    u8 flag10;
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
extern u8 D_801001A0[];
extern u8 D_801002A1;
typedef struct { s32 n; } SaveSlots;
extern SaveSlots D_801002B4;
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
/* Creates the per-player HUD labels (name text buffers, timer, and marker icons) laid out for the current 1-4 player split-screen mode. */ void setupPlayerHudLabels(void)
{
    u32 rmw1;
    volatile s32 *pc;
    f32 centerX = 160.0f;
    f32 centerY = 120.0f;
    u16 playerIdx;
    u16 k;
    s16 j;
    s32 jj;
    s16 x;
    s16 y;
    u8 kind;
    Ent *ent;
    Ent *other;
    Label *lab;
    Label *q;
    void *s;
    void *s2;
    s32 xx;
    s32 yy;

    switch (D_801002C0) {
    case 2:
        if (D_8010A4FD == 1) {
            do { do { centerX = 80.0f; } while (0); } while (0);
        } else {
            do { do { do { centerY = 60.0f; } while (0); } while (0); } while (0);
        }
        break;
    case 3:
    case 4:
        centerX = 80.0f;
        do { do { do { centerY = 60.0f; } while (0); } while (0); } while (0);
        break;
    }
    do { func_8011CFB0(); } while (0);
    for (playerIdx = 0; playerIdx < *(pc = &D_801002C0); playerIdx++) {
        if (D_80109688[playerIdx] == 0) {
            continue;
        }
        ent = D_8010A500[playerIdx]->ent;
        switch (*pc) {
        case 1:
        default:
            do { x = -4; } while (0);
            y = 4;
            break;
        case 2:
            if (D_8010A4FD == 0) {
                x = -4;
                y = ((-(playerIdx != 0)) & -4) | 4;
            } else {
                y = 4;
                x = ((-(playerIdx != 0)) & -4) | 8;
            }
            break;
        case 3:
        case 4:
            x = ((-(((playerIdx == 0) | (playerIdx == 2)) == 0)) & -4) | 8;
            do { do { y = ((-(playerIdx >= 2)) & -4) | 4; } while (0); } while (0);
            break;
        }
        for (j = 0; j < 3; j++) {
            do { jj = j; } while (0);
            SLOT(jj) = NULL;
            if (D_801002D4 != 0) {
                if (jj == 1) {
                    continue;
                }
            }
            {
                do { SLOT(jj) = func_800162BC(ent->kind182); } while (0);
                if (SLOT(jj) != NULL) {
                    switch (jj) {
                    case 0:
                        initTextBuffer(SLOT(jj), BUF(jj), (u16) (u32) ((2.0f * centerX - 16.0f) + x), (u16) (u32) (2.0f * centerY - 34.0f), 0xA60, 0xAAAA00FF);
                        break;
                    case 1:
                        do { do { initTextBuffer(SLOT(jj), BUF(jj), 0x16, (u16) (u32) (2.0f * centerY - 34.0f), 0x860, 0xAAAA00FF); } while (0); } while (0);
                        break;
                    case 2:
                        {
                        { f32 sx = (2.0f * centerX - 16.0f) + x; do { do { initTextBuffer(SLOT(jj), BUF(jj), (u16) (u32) sx, (u16) (u32) (2.0f * centerY - 24.0f), 0xA60, 0xAAAA00FF); } while (0); } while (0); }
                        }
                        break;
                    }
                }
            }
        }
        s = D_8011F378[playerIdx];
        q = func_8011E304(0x18, 0x1E, s, playerIdx);
        (*(u16 *)((char *)q + 0x1E)) = 0x20;
        sprintf(s, &D_8011F018);
        (*(u16 *)((char *)q + 0x1C)) = 1;
        D_8011F3D0[playerIdx] = q;
        xx = (u16) (u32) centerX;
        yy = (u16) (u32) centerY;
        s2 = D_8011F2B8[playerIdx];
        q = func_8011E304(xx, yy, s2, playerIdx);
        (*(u16 *)((char *)q + 0x1E)) = (*(u16 *)((char *)q + 0x1E)) | 0x20;
        sprintf(s2, func_80087100(0x2E5));
        (*(u16 *)((char *)q + 0x1C)) = 3;
        rmw1 = (*(u32 *)((char *)q + 0x28)); rmw1 &= ~0xFC; rmw1 |= 0x1C; (*(u32 *)((char *)q + 0x28)) = rmw1;
        D_8011F3E8[playerIdx] = q;
        D_8011F3E0[playerIdx] = 0;
        kind = D_801001A0[playerIdx * 0x18 + 2];
        if (kind != 0) {
            do { do { do { q = func_800162BC(playerIdx); } while (0); } while (0); } while (0);
            if (q != NULL) {
                do { do { func_800448A4(q, 0x13, 0x2A); } while (0); } while (0);
                (*(u16 *)((char *)q + 0x1E)) = 2;
                (*(u16 *)((char *)q + 0x22)) = y + 0xC;
                rmw1 = (*(u32 *)((char *)q + 0x28)); rmw1 &= ~0xFC; rmw1 |= 0x10; (*(u32 *)((char *)q + 0x28)) = rmw1;
                (*(u16 *)((char *)q + 0x20)) = D_8011F0EC + (u16) (x + 0xFFC7U);
                do { do { (*(u32 *)((char *)q + 0x10)) = (D_800BD66C & ~0xFF) | 0x88; } while (0); } while (0);
                D_8011F0F0[playerIdx] = D_8011F0EC + (x + 0xFFDBU);
                D_8011F0F8[playerIdx] = y + 0x20;
                D_8011F2E8[0][playerIdx] = q;

                    for (k = 0; k < D_801002B4.n; k++) {
                        other = D_8010A500[k]->ent;
                        if (playerIdx == k) {
                            continue;
                        }
                        if (kind == 5) {
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
                        do { do { do { q = func_800162BC(playerIdx); } while (0); } while (0); } while (0);
                        if (q == NULL) {
                            continue;
                        }
                        if (D_801002A1 != 0) {
                            if (other->info->flag10 == 0) {
                                do { do { do { (*(u32 *)((char *)q + 0x10)) = D_800BD678; } while (0); } while (0); } while (0);
                            } else {
                                do { do { do { (*(u32 *)((char *)q + 0x10)) = D_800BD654; } while (0); } while (0); } while (0);
                            }
                        } else {
                            (*(u32 *)((char *)q + 0x10)) = D_800BD644;
                        }
                        rmw1 = (*(u32 *)((char *)q + 0x28)); rmw1 &= ~0xFC; rmw1 |= 0xC; (*(u32 *)((char *)q + 0x28)) = rmw1;
                        func_800448A4(q, 0x17, 0x1B);
                        do { D_8011F2E8[k + 1][playerIdx] = q; } while (0);
                    }
                
            }
        }
    }
}

