/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

void *func_80083E90();
extern s32 D_80107ED0;
extern char D_80109EA0[];
extern s32 D_8010A510;

void func_800326BC(void *arg0) {
    s16 temp_lo;
    s32 temp_s1;
    s32 temp_s2;
    void *temp_v0;

    temp_s2 = (*(u16 *)((char *)(arg0) + 2)) + 1;
    temp_s1 = (*(u16 *)((char *)(arg0) + 4)) + 1;
    temp_v0 = func_80083E90(0x10, 0x20);
    {
    s32 index = D_80107ED0;
    s32 base;
    s32 value;
    ((void **)D_80109EA0)[index] = temp_v0;
    base = D_8010A510;
    value = *(s32 *)((char *)arg0 + 8);
    temp_lo = temp_s2 * temp_s1;
    *(s32 *)((char *)temp_v0) = base + 4;
    *(s8 *)((char *)temp_v0 + 8) = 0;
    *(s8 *)((char *)temp_v0 + 0xA) = 0;
    *(s32 *)((char *)temp_v0 + 4) = value;
    }
    (*(u8 *)((char *)(temp_v0) + 9)) = (u8) (*(u8 *)((char *)(arg0) + 6));
    (*(u8 *)((char *)(temp_v0) + 0xB)) = (u8) (*(u8 *)((char *)(arg0) + 7));
    (*(s16 *)((char *)(temp_v0) + 0xC)) = temp_lo;
    if (!((*(u8 *)((char *)(arg0) + 0)) & 1)) {
        (*(s16 *)((char *)(temp_v0) + 0xC)) = (s16) ((u32) ((unsigned)temp_lo & 0xFFFF) >> 1);
    }
    D_80107ED0 += 1;
}
