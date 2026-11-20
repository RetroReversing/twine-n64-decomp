typedef struct { u16 key; s16 len; s32 off; } E7539C;
extern E7539C *D_800C994C[];
extern s32 D_800C9958[];
extern u8 D_148B400[];
void func_8000B9B8(void *, void *, s32);
s16 func_800A1080(void *);

void func_8007539C(void) {
    u8 buf[0x400];
    s32 off;
    u32 i;
    E7539C *e;
    s32 src;
    u8 *__base_D_148B400;

    __base_D_148B400 = D_148B400;

    off = 0;
    for (i = 0; i < 3; i++) {
        e = D_800C994C[i];
        src = D_800C9958[i];
        if (e->key != 0xFFFF) {
            E7539C *p = e;
            s32 q = src;
            __repair_rows: {
                func_8000B9B8(&off, D_148B400 + q, 4);
                func_8000B9B8(buf, __base_D_148B400 + off, 0x400);
                p->len = func_800A1080(buf);
                p->off = off;
                p++;
                q += 4;
            }
if (p->key != 0xFFFF) goto __repair_rows;
        }
    }
}
