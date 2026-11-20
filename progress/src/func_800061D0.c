#define F(p,t,o) (*(t *)((u8 *)(p)+(o)))
extern s32 D_800D9418;
extern void func_80005F5C(void *);
extern void func_80084180(s32 *, s32 *, s32);
extern void func_800055CC(s32 *, s32, s32, s32);
void func_800061D0(void *obj, s32 a, s32 b) {
    u8 *base = F(obj,u8 *,0x68);
    u8 *state = base + 0x14;
    s32 flags;
    s32 *item;
    if (F(base,s32,0x14) & 0x4000) F(base,s16,0x90) = b;
    else F(base,s16,0x90) = D_800D9418;
    flags = F(state,s32,0);
    F(state,s16,0x7E) = a;
    F(state,s16,0x80) = b;
    if (!(flags & 0x40000)) {
        func_80084180(F(state,s32 *,0x40), F(state,s32 *,0x44), F(state,s16,0x92));
        item = F(state,s32 *,0x44);
        flags = F(state,s32,0);
    } else {
        item = F(state,s32 *,0x44);
    }
    func_800055CC(item, a, b, flags & 1);
    func_80005F5C(obj);
}
