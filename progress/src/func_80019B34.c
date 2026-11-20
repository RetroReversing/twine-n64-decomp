extern struct { s32 value; char pad[20]; } D_8010019C[];
extern u8 D_801001A1[];
extern u8 D_801002A1;
extern s32 D_801002B8, D_801002BC;
u8 func_8002BC28(s32);
s32 func_80019B34(s32 arg0) {
    u16 i = 0;
    s32 count;
    s32 value;
    s32 index = (u16)arg0 * 24;
    count = D_801002B8;
    value = *(s32 *)((s8 *)D_8010019C + index);
    for (i = 0; i < count; i++) {
        if (i != (u16)arg0 && D_8010019C[i].value == value) return 0x15a;
    }
    for (i = 4; i < D_801002BC + 4; i++) {
        if (i != (u16)arg0 && D_8010019C[i].value == value) return 0x15a;
    }
    if (D_801002A1) {
        if (func_8002BC28(value) & 0xff) goto __shared_return_345;
        if (!D_801001A1[(u16)arg0 * 24]) return 0x15a;
        goto __shared_return_345;
    }
    if ((func_8002BC28(value) & 0xff)) goto __shared_return_345;
    for (i = 0; i < D_801002B8; i++) {
        if (i != (u16)arg0 && !func_8002BC28(D_8010019C[i].value)) return 0x15a;
    }
    for (i = 4; D_801002BC + 4 > i; i++) {
        if (i != (u16)arg0 && !func_8002BC28(D_8010019C[i].value)) return 0x15a;
    }
    __shared_return_345:
    return 0x159;
}
