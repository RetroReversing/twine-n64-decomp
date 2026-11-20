typedef struct {
    s32 x, y, z;
} Position78860;

s32 func_8007C094(void *, void *, f32);
void func_80077960(void *, s32);
void func_800779C4(void *);
void func_80077A94(void *);
void func_8008461C(s32);
extern u8 *D_8010A500;

s32 func_80078860(u8 *actor) {
    s32 flags = *(s32 *)(actor + 0x60);
    u8 *state = *(u8 **)(actor + 0x6C);

    if (!((flags & 0x3000) && ((u32)func_8007C094(actor, D_8010A500 + 0x24, 2.0f) << 24)))
        return 0;
    if ((*(s32 *)(state + 0x88) & 0x41E00000) != 0x200000)
        return 0;

    switch (state[0x82]) {
    case 3:
    case 15:
    case 35:
    case 39:
    case 40:
        goto reset;
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 10:
    case 11:
    case 16:
    case 17:
    case 18:
    case 19:
    case 20:
    case 43:
    case 44:
        return 0;
    }
    switch (((s8 *)*(u8 **)(D_8010A500 + 0x68))[0xE]) {
    default:
        func_8008461C((s32)actor);
        func_80077960(actor, 0x38);
        return 1;
    case 0:
    case 0x1E:
    case 0x1F:
    case 0x21:
    case 0x22:
    case 0x23:
    case 0x24:
    case 0x25:
    case 0x2C:
    case 0x2D:
    case 0x2E:
    case 0x2F:
    case 0x30:
    case 0x37:
    case 0x38:
        func_80077A94(actor);
        *(Position78860 *)(state + 0x18) = *(Position78860 *)(D_8010A500 + 0x24);
        func_80077960(actor, 0xD);
        return 0;
    }
reset:
    func_800779C4(actor);
    return 0;
}
