extern s32 func_8003D64C(void *, void *);
extern void *func_8003D848(void *);
extern void *func_80047B44(void *, void *, void *, s32);
extern void func_800484F8(void *, f32);
void func_8004830C(void *arg0) {
    void *saved;
    void *p;
    void *q;
    saved = *(void **)((u8 *)arg0 + 0xF4);
    if (!saved) {
        *(void **)((u8 *)arg0 + 0xF4) = func_8003D848((u8 *)arg0 + 0x10);
    } else {
        p = func_80047B44(saved, (u8 *)arg0 + 0x28, (u8 *)arg0 + 0x10, 0);
        if (p) *(void **)((u8 *)arg0 + 0xF4) = *(void **)((u8 *)p + 8);
    }
    p = *(void **)((u8 *)arg0 + 0xF4);
    if (p && (func_8003D64C((u8 *)arg0 + 0x10, p) << 24) == 0) {
        *(s32 *)((u8 *)arg0 + 0x10) = *(s32 *)((u8 *)arg0 + 0x28);
        *(s32 *)((u8 *)arg0 + 0x14) = *(s32 *)((u8 *)arg0 + 0x2C);
        *(s32 *)((u8 *)arg0 + 0x18) = *(s32 *)((u8 *)arg0 + 0x30);
    } else {
        *(s32 *)((u8 *)arg0 + 0x28) = *(s32 *)((u8 *)arg0 + 0x10);
        *(s32 *)((u8 *)arg0 + 0x2C) = *(s32 *)((u8 *)arg0 + 0x14);
        *(s32 *)((u8 *)arg0 + 0x30) = *(s32 *)((u8 *)arg0 + 0x18);
    }
    q = *(void **)((u8 *)arg0 + 0xF4);
    if (q == 0) goto done;
    if ((*(u32 *)((u8 *)q + 0x5C) >> 23) & 8) *(s32 *)((u8 *)arg0 + 0x100) |= 0x20;
    else *(s32 *)((u8 *)arg0 + 0x100) &= ~0x20;
    if (*(f32 *)((u8 *)arg0 + 0x14) <= *(f32 *)((u8 *)*(void **)((u8 *)q + 0x20) + 0x5C)) *(s32 *)((u8 *)arg0 + 0x100) |= 8;
    else *(s32 *)((u8 *)arg0 + 0x100) &= ~8;
    func_800484F8(arg0, *(f32 *)((u8 *)arg0 + 0x84));
    goto end;
done:
    *(void **)((u8 *)arg0 + 0xF4) = saved;
end:
    return;
}
