extern void func_80065D90(void *arg0, void *);
extern void *func_801183F4(void *, s32);
void func_80118BCC(void *arg0) {
    void *state = *(void **)((s8 *)arg0 + 0x6C);
    func_80065D90(arg0, arg0);
    (void)func_801183F4(arg0, *(s16 *)((s8 *)arg0 + 0x7A));
    if ((u16)*(s16 *)((s8 *)arg0 + 0x7A) < 11) {
        (void)jtbl_8011EF48[(u16)*(s16 *)((s8 *)arg0 + 0x7A)];
    }
}
