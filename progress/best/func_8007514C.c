extern f32 Vec3_DistanceSq(void *, void *);
extern s32 findActionSlot(s32, s32, s32);
extern s32 func_800312F4(s32, s32);
extern void func_80074C34(s32, s32 *, s32);
extern void func_801183F4(void);
extern u8 D_800CEEB0, D_800C7EE8[], D_800C7EE9[], D_80115091[];
extern s32 D_800C7EE4;
extern s32 *D_800C7EEC[];
extern void *sBonusObjectTable;
#define F(p,t,o) (*(t *)((u8 *)(p) + (o)))

void func_8007514C(void *object) {
    void *bonusData;
    s32 bypass, check, variant, byteOffset;
    f32 radius;
    if (D_800CEEB0 != 0)
        return;
    if ((u32)sBonusObjectTable == 0)
        return;
    radius = 3.0f;
    byteOffset = F(object, s16, 0x7C) * 12;
    bonusData = F(sBonusObjectTable, void *, 0x6C);
    bypass = 0;
    switch (D_800C7EE8[byteOffset]) {
    case 1:
        if ((findActionSlot((s32)bonusData, 2, 1) << 24) == 0)
            return;
        bypass = 1;
        if (F(&func_801183F4, s8, 0x55F) == 0)
            return;
        break;
    case 2:
        if (func_800312F4(2, 0) == 3)
            return;
        check = bypass;
        goto compare;
    case 4:
        bypass = 1;
        if (F(bonusData, u8, 0x23C) == 0)
            return;
        break;
    case 5:
        bypass = 1;
        if (F(F(sBonusObjectTable, void *, 0x68), s8, 0xE) != 0x29)
            return;
        break;
    case 0:
    case 3:
    default:
        break;
    }
    check = bypass;
compare:
    if (check || Vec3_DistanceSq((u8 *)object + 0x24, (u8 *)sBonusObjectTable + 0x24) < radius) {
        switch (D_80115091[F(bonusData, s8, 0x182) * 160]) {
        case 2:
        case 4:
        case 6:
        default:
            variant = 0;
            break;
        case 1:
        case 3:
        case 5:
        case 7:
            variant = 1;
            break;
        }
        byteOffset = F(object, s16, 0x7C) * 12;
        if (D_800C7EE9[byteOffset] == 0) {
            D_800C7EE9[byteOffset] = 1;
            {
                u8 *entries = (u8 *)D_800C7EEC;
                s32 variantOffset = variant * 4;
                if (**(s32 **)(entries + F(object, s16, 0x7C) * 12 + variantOffset) >= 0)
                    D_800C7EE4 = 1;
                func_80074C34(0, *(s32 **)(entries + F(object, s16, 0x7C) * 12 + variantOffset), 1);
            }
            D_800C7EE4 = 2;
        }
        F(object, s32, 0x60) |= 1;
    }
}

