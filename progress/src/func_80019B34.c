extern struct { s32 value; char pad[20]; } D_8010019C[];
extern u8 D_801001A1[];
extern u8 D_801002A1;
extern s32 D_801002B8, D_801002BC;
u8 func_8002BC28(s32);

// Returns 0x159 if slot 'slot' can be used, or 0x15a if its key clashes with another slot's key or fails the func_8002BC28 check.
s32 func_80019B34(s32 slot) {
    u16 i = 0;
    s32 count;
    s32 key;
    s32 offset = (u16)slot * 24;
    count = D_801002B8;
    key = *(s32 *)((s8 *)D_8010019C + offset);
    for (i = 0; i < count; i++) {
        if (i != (u16)slot && D_8010019C[i].value == key) return 0x15a;
    }
    for (i = 4; i < D_801002BC + 4; i++) {
        if (i != (u16)slot && D_8010019C[i].value == key) return 0x15a;
    }
    if (D_801002A1) {
        if (func_8002BC28(key) & 0xff) goto __shared_return_345;
        if (!D_801001A1[(u16)slot * 24]) return 0x15a;
        goto __shared_return_345;
    }
    if ((func_8002BC28(key) & 0xff)) goto __shared_return_345;
    for (i = 0; i < D_801002B8; i++) {
        if (i != (u16)slot && !func_8002BC28(D_8010019C[i].value)) return 0x15a;
    }
    for (i = 4; D_801002BC + 4 > i; i++) {
        if (i != (u16)slot && !func_8002BC28(D_8010019C[i].value)) return 0x15a;
    }
    __shared_return_345:
    return 0x159;
}
