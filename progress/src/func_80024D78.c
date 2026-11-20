typedef struct { u8 pad0[0x18]; char *text; u16 len; } Txt4D78;
typedef struct { Txt4D78 *txt; s32 f4; } Item4D78;
typedef struct { u8 pad0[0x10]; s32 f10; } Sys4D78;
extern s32 D_80107EA8;
extern char D_800D2AD0[];
extern char D_800D2AE0[];
extern Sys4D78 *D_80109BB0;
Item4D78 **func_8002A920(s32 *, s8);
s8 func_8002CB98(u16);
s32 func_8002CB7C(u16);
u16 func_8002CBB8(u16);
u16 func_8002D09C(u16);
u16 func_8002D1F8(void);
s32 func_800448A4(s32, s32, s32);
s32 findEntryById(s32, s32);
s32 func_80087100(s32);
void formatTextEntry(s32, char *, s32, u16);
s32 sprintf(char *, const char *, ...);
s16 strlen(const char *);

void func_80024D78(void) {
    u16 i;
    Item4D78 **pp;
    Item4D78 *it;
    char buf[3];
    s32 n;
    Txt4D78 *t;
    s32 p;

    for (i = 0; i < 16; i++) {
        pp = func_8002A920(&D_80107EA8, i);
        if (pp == NULL) {
            continue;
        }
        it = *pp;
        if (it == NULL) {
            continue;
        }
        if (it->txt->text == NULL) {
            continue;
        }
        buf[2] = 0;
        buf[1] = 0;
        buf[0] = 0;
        buf[1] = func_8002CB98(i);
        if (buf[1]) {
            buf[0] = '.';
        } else {
            buf[0] = ' ';
        }
        sprintf(it->txt->text, D_800D2AD0, i + 1, func_8002CB7C(i), buf, func_8002CBB8(i));
        t = it->txt;
        t->len = strlen(t->text);
        if (func_8002D09C(i)) {
            func_800448A4(it->f4, 0xF, 0x24);
        } else {
            func_800448A4(it->f4, 0x10, 0x24);
        }
    }
    p = findEntryById(D_80109BB0->f10, 0x4010);
    if (p != 0) {
        n = func_80087100(0x300E);
        formatTextEntry(p, D_800D2AE0, n, func_8002D1F8());
    }
}
