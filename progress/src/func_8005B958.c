typedef struct { u8 pad0[0x30]; s32 w30; } Sub5B958;
typedef struct { u8 pad0[0x70]; Sub5B958 *sub; u8 pad74[4]; s32 w78; s16 h7C_pad; } Obj5B958x;
typedef struct { u8 pad0[0x70]; Sub5B958 *sub; u8 pad74[4]; s32 w78; } Obj5B958;

void func_8000A894(s32);
void func_8005B5A8(void);
void func_80073AF8(s32, s32, char *, s32, s32, s32, s32, s32, s32, s32, s32);
s32 func_80087100(s32);
s32 sprintf(char *, const char *, ...);
extern u8 D_80100300;
extern u8 D_801007D8;
extern Obj5B958 *D_80108788;
extern s32 gAimAxisTable;
extern char D_800D4110[];

static inline s32 check_5B958(void) {
    char buf[0x100];
    s32 r = 0;
    s32 v;
    s32 a;
    s32 b;
    Sub5B958 *sub;
    s32 m1;

    if (D_80108788 == NULL) {
        goto out;
    }
    sub = D_80108788->sub;
    if (sub == NULL) {
        goto out;
    }
    m1 = -1;
    if (D_80108788->w78 != 0x5A0000) {
        goto out;
    }
    v = sub->w30;
    if ((v & 0xFFFF0) != 0x670) {
        goto out;
    }
    if ((v & 0xFFF00000) != 0x02600000) {
        goto out;
    }
    D_80100300++;
    a = func_80087100(0xF3);
    b = func_80087100(0xFF);
    sprintf(buf, D_800D4110, a, D_80100300, b, D_801007D8, func_80087100(0xFD));
    func_80073AF8(0, gAimAxisTable, buf, m1, m1, 1, 0, 0, 3, 0, 0);
    *(s16 *)((u8 *)D_80108788 + 0x7A) = 1;
    func_8000A894(0x111);
    r = 1;
out:
    return (s16)r;
}

void func_8005B958(void) {
    s32 v = check_5B958();

    if (v == 0) {
        func_8005B5A8();
    }
}
