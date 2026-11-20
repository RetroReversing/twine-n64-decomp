extern s32 func_80022DBC(u16);
extern s32 D_8010019C[];
extern u16 D_800BF688[];
extern s32 D_8011ECB0[];
void func_801183F4(void *arg0, s32 arg1) {
    void *p = *(void **)((char *)arg0 + 0x6c);
    u16 index = func_80022DBC((u16)(s8)*(volatile u8 *)((char *)p + 0x182));
    s32 n = D_8010019C[index * 6];
    s32 kind = D_800BF688[n * 6] & 3;
    s32 value = D_8011ECB0[kind];
    index = func_80022DBC((u16)(s8)*(volatile u8 *)((char *)p + 0x182));
}
