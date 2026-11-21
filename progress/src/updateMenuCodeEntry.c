s32 requestSound(s32);
s32 setMenuTextRequest(void *);
s32 func_8002778C();
s32 func_800278AC(s32, s32, u16);
s32 func_80027C60(s32);
s32 menuItemIsActive(s32);
extern u8 sMenuCodeStep;
extern s32 sMenuCodeSequence;
extern u8 D_800BD854;
extern u8 D_800BD855;
extern s32 D_80102EC0;
extern u8 *sActiveMenu;
extern u8 *gMenuItems;

/* Advances the menu code entry through its four required item IDs; on completion, shows the reward text and resets the menu. */
void updateMenuCodeEntry(void) {
    u32 itemState20, itemState21, itemState1E, itemState1F;
    s32 itemId;

    itemState20 = func_80027C60(0x20);
    itemState21 = func_80027C60(0x21);
    itemState1E = func_80027C60(0x1E);
    itemState1F = func_80027C60(0x1F);
    if (!(menuItemIsActive(0x2A) & 0xFF)) {
        sMenuCodeStep = 0;
    }
    switch (*(&sMenuCodeSequence + sMenuCodeStep)) {
    case 32:
        if (((itemState21 & 0xFF) != 0) | ((itemState1F & 0xFF) != 0) || (itemState1E & 0xFF)) goto fail;
        itemId = 0x20;
        goto ok;
    case 33:
        if (((itemState20 & 0xFF) != 0) | ((itemState1F & 0xFF) != 0) || (itemState1E & 0xFF)) goto fail;
        itemId = 0x21;
        goto ok;
    case 30:
        if (((itemState21 & 0xFF) != 0) | ((itemState1F & 0xFF) != 0) || (itemState20 & 0xFF)) goto fail;
        itemId = 0x1E;
        goto ok;
    case 31:
        if (((itemState21 & 0xFF) != 0) | ((itemState20 & 0xFF) != 0) || (itemState1E & 0xFF)) goto fail;
        itemId = 0x1F;
        goto ok;
    default:
        goto done;
    }
fail:
    sMenuCodeStep = 0;
    requestSound(0xED);
    goto done;
ok:
    if (func_80027C60(itemId) & 0xFF) {
        requestSound(0xED);
        sMenuCodeStep += 1;
    }
done:
    if (sMenuCodeStep == 5) {
        requestSound(0xE8);
        setMenuTextRequest(&D_800BD854);
        *(u16 *)(sActiveMenu + 0x7A) = D_800BD855;
        *(s16 *)(sActiveMenu + 0x7C) = 0x78;
        func_800278AC(1, D_80102EC0 & ~0xFF, *(u16 *)(sActiveMenu + 0x7A));
        func_8002778C();
        *(s8 *)(gMenuItems + 0x2C) = 0;
    }
}
