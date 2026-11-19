void func_800055CC(s32, s32, s32, s32);
void func_80005F5C(void *);
extern s32 D_800D9418;

typedef struct { s32 flags; u8 pad4[0x3C]; s32 a40; s32 a44; u8 pad48[0x36]; s16 h7E; s16 h80; } Sub600C;

void func_8000600C(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    u8 *obj = *(u8 **)((u8 *)arg0 + 0x68);
    Sub600C *s = (Sub600C *)(obj + 0x14);

    if (s->flags & 0x4000) {
        *(s16 *)(obj + 0x90) = arg2;
    } else {
        *(s16 *)(obj + 0x90) = D_800D9418;
    }
    s->h7E = arg1;
    s->h80 = arg2;
    func_800055CC(s->a40, arg1, arg2, s->flags & 1);
    func_800055CC(s->a44, arg1, arg3, s->flags & 1);
    func_80005F5C(arg0);
}
