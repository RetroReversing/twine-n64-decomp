extern void func_80065D90(void *arg0, void *);
extern void *func_801183F4(void *, s32);
extern s32 func_80022DBC(s32, s32);
extern u8 gSaveSlotInfo[];
extern u8 D_800BF68B[];
extern u8 D_800BF688[];
void func_80118BCC(void *arg0, s32 arg1) {
    extern u8 gSceneType;
    extern u8 D_8011F168[];
    extern f32 func_800461D4(void *, void *);
    volatile s32 frame[24];
    u8 *self = (u8 *)arg0;
    u8 *state = *(u8 **)(self + 0x6C);
    s32 entry = *(s32 *)(self + 0x20);
    s32 slot = func_80022DBC(((s32)*(volatile u8 *)(state + 0x182) << 24) >> 24, arg1);
    s32 rate = *(s32 *)(gSaveSlotInfo + (slot & 0xFFFF) * 0x18);
    u8 flags = D_800BF68B[(s16)rate * 12];
    f32 speed = *(f32 *)(self + 0x74);
    if ((speed > 0.0f) && (flags & 0x10)) {
        speed += 0.5f;
        *(f32 *)(self + 0x74) = speed;
        if ((f32)(D_800BF688[(s16)rate * 12] * 5) < speed) {
            *(f32 *)(self + 0x74) = (f32)(D_800BF688[(s16)rate * 12] * 5);
        }
    }
    *(s32 *)(*(u8 **)(self + 0x68) + 0x34) = 0;
    {
    s16 mode = *(s16 *)(self + 0x7A);
    s32 request = 1;
    void *target = *(void **)(state + 0xC0);
    if (mode == 2 && target != NULL) {
        u16 type = *(u16 *)((u8 *)target + 0x78);
        if (((type == 0x55) || (type == 0x28)) &&
            func_800461D4(self + 0x24, (u8 *)target + 0x24) > 2.0f) {
            request = 0;
        }
    }
    *(void **)(state + 0xC0) = func_801183F4(arg0, request);
    if (mode != 6 && (target = *(void **)(state + 0xC0)) != NULL) {
        u16 type = *(u16 *)((u8 *)target + 0x78);
        if (type == 0x4D || type == 0x61) {
            *(s16 *)(self + 0x7A) = 2;
            *(void **)(state + 0xC0) = func_801183F4(arg0, 1);
        } else if (type == 0x29) {
            if (func_800461D4(self + 0x24, (u8 *)target + 0x24) < 1.0f) {
                *(s16 *)(self + 0x7A) = 7;
            }
        } else if (type == 0x45 && gSceneType == 3) {
            s16 index = *(s16 *)((u8 *)target + 0x7A);
            u8 *room = *(u8 **)(state + 0xB4);
            if (index == *(s16 *)(room + 0x12) && D_8011F168[index] == 0) {
                if (func_800461D4(self + 0x24, (u8 *)target + 0x24) < 2.0f) {
                    *(s16 *)(self + 0x7A) = 7;
                }
            }
        }
    }
    {
        extern void func_8006CD34(void *);
        extern f32 approxDistance(void *, void *);
        extern s32 func_8007A9CC(void *, void *, void *, s32);
        extern s32 func_800158A4(void *, void *, s32, void *, s32, s32, s32, s32, s32);
        extern void *gTrackAxisTable[];
        s32 lock = 0;
        func_8006CD34(arg0);
        target = *(void **)(state + 0xC0);
        if (target != NULL) {
            u16 kind = *(u16 *)((u8 *)target + 0x78);
            if ((u32)(kind - 2) < 2U) {
                f32 distance = approxDistance(self + 0x24, (u8 *)target + 0x24);
                if ((distance < 25.0f) &&
                    ((distance < 6.0f) || (flags & 1) ||
                     func_8007A9CC(arg0, self + 0x24, (u8 *)target + 0x24, 0x448E38E4)) &&
                    func_800158A4((u8 *)gTrackAxisTable[(s8)state[0x182]] + 0x10,
                                  (u8 *)target + 0x24, entry, frame, 0, 0, 0x20000, 1, 0)) {
                    lock = 1;
                }
            }
        }
        func_80065D90(arg0, (u8 *)target + 0x24);
        if ((u16)*(s16 *)(self + 0x7A) < 11) {
            (void)jtbl_8011EF48[(u16)*(s16 *)(self + 0x7A)];
        }
    }
    }
}
