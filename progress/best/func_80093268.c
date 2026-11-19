typedef struct Ent {
    u8 flag;
    u8 pad[3];
    s32 (*fn)(u16 *, s32, s32, s32, s32);
    u16 *buf;
    u16 *end;
    u32 cur;
    s32 arg;
} Ent;

extern Ent D_801096E8[];
extern u8 D_801176E8;
u32 func_8008C6CC(s32);
void func_8008C6F4(s32, s32);

void func_80093268(void) {
    s32 var_s3;
    Ent *e;
    u32 temp_v0;
    u32 temp_t0;
    u32 temp_v1;

    var_s3 = 0;
    if ((s32) D_801176E8 > 0) {
        do {
            e = &D_801096E8[var_s3];
            if (e->flag == 1) {
                temp_v0 = func_8008C6CC(var_s3);
                temp_t0 = e->cur;
                if (temp_t0 != temp_v0) {
                    if (temp_t0 < temp_v0) {
                        if (e->fn((u16 *) e->buf + temp_t0, temp_v0 - temp_t0, 0, 0, e->arg) & 0xFF) {
                            func_8008C6F4((s32) ((u16 *) e->buf + temp_t0), temp_v0 - temp_t0);
                        }
                    } else {
                        if (e->fn((u16 *) e->buf + temp_t0, (s32) e->end - temp_t0, (s32) e->buf, temp_v0, e->arg) & 0xFF) {
                            temp_v1 = e->cur;
                            func_8008C6F4((s32) e->buf + temp_v1 * 2, (s32) e->end - temp_v1);
                            func_8008C6F4((s32) e->buf, temp_v0);
                        }
                    }
                }
                e->cur = temp_v0;
            }
            var_s3 += 1;
        } while (var_s3 < (s32) D_801176E8);
    }
}
