s32 requestSound(s32);
s32 setMenuTextRequest(void *);
s32 func_8002778C();
s32 func_800278AC(s32, s32, u16);
s32 func_80027C60(s32);
s32 menuItemIsActive(s32);
extern u8 D_800B60A6;
extern s32 D_800B60A8;
extern u8 D_800BD854;
extern u8 D_800BD855;
extern s32 D_80102EC0;
extern u8 *sActiveMenu;
extern u8 *gMenuItems;

void func_8001D424(void) {
    u32 a, b, c, d;
    s32 id;

    a = func_80027C60(0x20);
    b = func_80027C60(0x21);
    c = func_80027C60(0x1E);
    d = func_80027C60(0x1F);
    if (!(menuItemIsActive(0x2A) & 0xFF)) {
        D_800B60A6 = 0;
    }
    switch (*(&D_800B60A8 + D_800B60A6)) {
    case 32:
        if (((b & 0xFF) != 0) | ((d & 0xFF) != 0) || (c & 0xFF)) goto fail;
        id = 0x20;
        goto ok;
    case 33:
        if (((a & 0xFF) != 0) | ((d & 0xFF) != 0) || (c & 0xFF)) goto fail;
        id = 0x21;
        goto ok;
    case 30:
        if (((b & 0xFF) != 0) | ((d & 0xFF) != 0) || (a & 0xFF)) goto fail;
        id = 0x1E;
        goto ok;
    case 31:
        if (((b & 0xFF) != 0) | ((a & 0xFF) != 0) || (c & 0xFF)) goto fail;
        id = 0x1F;
        goto ok;
    default:
        goto done;
    }
fail:
    D_800B60A6 = 0;
    requestSound(0xED);
    goto done;
ok:
    if (func_80027C60(id) & 0xFF) {
        requestSound(0xED);
        D_800B60A6 += 1;
    }
done:
    if (D_800B60A6 == 5) {
        requestSound(0xE8);
        setMenuTextRequest(&D_800BD854);
        *(u16 *)(sActiveMenu + 0x7A) = D_800BD855;
        *(s16 *)(sActiveMenu + 0x7C) = 0x78;
        func_800278AC(1, D_80102EC0 & ~0xFF, *(u16 *)(sActiveMenu + 0x7A));
        func_8002778C();
        *(s8 *)(gMenuItems + 0x2C) = 0;
    }
}
