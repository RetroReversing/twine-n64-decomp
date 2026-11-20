u64 func_800ABAB4(u32 lo1, u32 hi1, u32 lo2, u32 hi2) {
    u32 cross = hi1 * lo2;
    cross += lo1 * hi2;
    return (u64)lo1 * lo2 + ((u64)cross << 32);
}

extern volatile s16 D_800F38BC;
extern s32 *D_800F38C0;
extern volatile s32 D_800F3950;
extern s32 D_800F3954;
s32 func_800986DC(s32, s32);
s32 *func_800956E0(s32, s32 *, s32, s32, s32 (*)(s32, s32));
s32 func_8009846C(s16 arg0) {
    s32 count = D_800F3950;
    volatile s16 *base = &D_800F38BC;
    s32 *result;
    *base = arg0;
    result = func_800956E0((s32)base - 4, &D_800F3954, count, 8, func_800986DC);
    D_800F38C0 = result;
    return result != 0 ? *result : 0;
}

extern u8 D_800CEEC0, D_800E2CC0, D_800E2CE4;
s32 isSlotActiveById(s32 key) {
    u32 i;
    s32 offset;
    s32 slot;
    if (D_800CEEC0) {
        i = 0;
        offset = 0;
        do {
            if (*(&D_800E2CC0 + offset) != 0 &&
                *(s32 *)(&D_800E2CE4 + offset) == key) {
                slot = i;
                goto found;
            }
            i++;
            offset += 0x1228;
        } while (i < 2);
        slot = -1;
found:
        if (slot != -1) {
            return *(&D_800E2CC0 + slot * 0x1228) != 0;
        }
    }
    return 0;
}

extern f32 D_800CA350[];
typedef struct { f32 v[9]; } Matrix3;
void func_800834B8(s16 *angle, Matrix3 *out) {
    s32 y = angle[1];
    s32 z = angle[2];
    f32 cy = D_800CA350[y & 0xfff];
    f32 cz = D_800CA350[z & 0xfff];
    f32 sz = D_800CA350[(z - 0x400) & 0xfff];
    f32 m00 = cy * cz;
    f32 sy = D_800CA350[(y - 0x400) & 0xfff];
    f32 m21 = sy * sz;
    f32 m01 = -cy * sz;
    f32 m20 = -cz * sy;
    out->v[5] = 0;
    out->v[2] = sy;
    out->v[3] = sz;
    out->v[4] = cz;
    out->v[8] = cy;
    out->v[0] = m00;
    out->v[7] = m21;
    out->v[1] = m01;
    out->v[6] = m20;
}
