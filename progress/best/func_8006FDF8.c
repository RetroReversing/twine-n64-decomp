void *func_80015F0C();
void func_800165E0(void *, s32);
void func_800448A4(void *, s32, s32);
extern u16 D_800C7E08[];
extern u32 D_800D46E4[];
extern u32 D_800D46EC[];
extern void *jtbl_800D46F8[];
typedef struct { u32 a, b; } PairWords;
extern s32 D_801002C0;
extern s32 D_80102ED8;
extern void *D_80109688[];
extern u8 D_8010A4FD;

void func_8006FDF8(void *arg0, s32 arg1) {
    u32 sp10[4];
    s32 sp2C;
    u16 *var_s4;
    u16 *var_s3;
    void *var_s1;
    void *temp_s0;
    void *temp_v0;
    void *temp_v1;
    void *temp_a0;
    s16 var_s6;
    s32 var_s7;
    s32 var_a0;
    s16 var_v1;
    
    s32 var_s1_2;
    unsigned long var_s2;
    s32 var_s2_2;
    void **var_s0;
    void *var_s0_2;
    s32 k;

    *(PairWords *)sp10 = *(PairWords *)D_800D46E4;
    *(PairWords *)(sp10 + 2) = *(PairWords *)D_800D46EC;
    var_s6 = 0x78;
    var_s7 = 0xA0;
    sp2C = *((u8 *)arg0 + 0x182);
    var_s2 = 0;
    if (D_80102ED8 != 0) {
        if (D_801002C0 != 2) {
            if (D_801002C0 >= 2) {
                if (D_801002C0 < 5) {
                    var_s6 = 0x3C;
                    var_s7 = 0x50;
                }
            }
        } else {
            if (D_8010A4FD == 1) {
                var_s7 = 0x50;
            }
            var_s6 = 0x3C;
        }
    }
    var_s4 = D_800C7E08;
    var_s3 = (u16 *)sp10;
    var_s1 = arg0;
    do {
        if (*(void **)((u8 *)var_s1 + 0x3D4) != NULL || (temp_v0 = func_80015F0C(), *(void **)((u8 *)var_s1 + 0x3D4) = temp_v0, temp_v0 != NULL)) {
            temp_s0 = *(void **)((u8 *)var_s1 + 0x3D4);
            func_800448A4(temp_s0, arg1, 0x2A);
            *(s32 *)((u8 *)temp_s0 + 0x10) = 0xFF;
            *(s32 *)((u8 *)temp_s0 + 0x28) = (*(s32 *)((u8 *)temp_s0 + 0x28) & ~0xFC) | 0x10;
            *(s16 *)((u8 *)temp_s0 + 0x26) = var_s7;
            *(u16 *)((u8 *)temp_s0 + 0x20) = var_s3[0];
            *(s8 *)((u8 *)temp_s0 + 0x29) = var_s6;
            *(u16 *)((u8 *)temp_s0 + 0x22) = var_s3[4];
            func_800165E0(temp_s0, (s32)D_80109688[sp2C]);
            *(u16 *)((u8 *)temp_s0 + 0x1E) = *var_s4;
        }
        var_s4 += 2;
        var_s3 += 2;
        ++var_s2;
        var_s1 = (u8 *)var_s1 + 4;
    } while (var_s2 < 4);
    if (D_80102ED8 == 0) {
        if (arg1 == 5) {
            var_s0 = arg0;
            var_s1_2 = 0;
            do {
                if (var_s0[0x3E4/4] == NULL) {
                    var_s0[0x3E4/4] = func_80015F0C();
                }
                *(s32 *)((u8 *)var_s0[0x3E4/4] + 0x10) = 0xFF008F;
                temp_a0 = var_s0[0x3E4/4];
                *(s32 *)((u8 *)temp_a0 + 0x28) = (*(s32 *)((u8 *)temp_a0 + 0x28) & ~0xFC) | 0x10;
                func_800165E0(var_s0[0x3E4/4], (s32)D_80109688[sp2C]);
                *(u16 *)((u8 *)var_s0[0x3E4/4] + 0x1E) = 2;
                k = var_s1_2 >> 2;
                switch (k) {
                case 0:
                case 1:
                    func_800448A4(var_s0[0x3E4/4], 0xF, 0x2A);
                    if (var_s1_2 == 0) {
                        *(s16 *)((u8 *)((void **)arg0)[0x3E4/4] + 0x20) = 0x50;
                    } else {
                        *(s16 *)((u8 *)var_s0[0x3E4/4] + 0x20) = 0xE0;
                        temp_v1 = var_s0[0x3E4/4];
                        *(u16 *)((u8 *)temp_v1 + 0x1E) = *(u16 *)((u8 *)temp_v1 + 0x1E) | 0x80;
                    }
                    *(s16 *)((u8 *)var_s0[0x3E4/4] + 0x22) = 0x58;
                    break;
                case 2:
                case 3:
                    func_800448A4(var_s0[0x3E4/4], 0x10, 0x2A);
                    if (var_s0 == (void **)((u8 *)arg0 + 8)) {
                        *(s16 *)((u8 *)((void **)arg0)[0x3EC/4] + 0x20) = 0x58;
                    } else {
                        *(s16 *)((u8 *)var_s0[0x3E4/4] + 0x20) = 0xD8;
                        temp_v1 = var_s0[0x3E4/4];
                        *(u16 *)((u8 *)temp_v1 + 0x1E) = *(u16 *)((u8 *)temp_v1 + 0x1E) | 0x80;
                    }
                    *(s16 *)((u8 *)var_s0[0x3E4/4] + 0x22) = 0x78;
                    break;
                case 4:
                    func_800448A4(var_s0[0x3E4/4], 0x11, 0x2A);
                    *(s16 *)((u8 *)var_s0[0x3E4/4] + 0x20) = 0x80;
                    *(s16 *)((u8 *)var_s0[0x3E4/4] + 0x22) = 0x20;
                    break;
                case 5:
                    func_800448A4(var_s0[0x3E4/4], 3, 0x2A);
                    *(s16 *)((u8 *)var_s0[0x3E4/4] + 0x20) = 0;
                    *(s16 *)((u8 *)var_s0[0x3E4/4] + 0x22) = 0x78;
                    *(s8 *)((u8 *)var_s0[0x3E4/4] + 0x29) = 8;
                    *(s16 *)((u8 *)var_s0[0x3E4/4] + 0x26) = 0x140;
                    *(s32 *)((u8 *)var_s0[0x3E4/4] + 0x10) = 0xFF001F;
                    break;
                }
                var_s1_2 += 4;
                ++var_s0;
            } while (var_s1_2 < 0x18);
        }
        var_s2_2 = 0;
        if (arg1 == 8) {
            var_s0_2 = arg0;
            do {
                var_s1_2 = 0;
                if (*(void **)((u8 *)var_s0_2 + 0x3E4) == NULL) {
                    *(void **)((u8 *)var_s0_2 + 0x3E4) = func_80015F0C();
                }
                *(s32 *)((u8 *)*(void **)((u8 *)var_s0_2 + 0x3E4) + 0x10) = 0xFF7F;
                temp_v1 = *(void **)((u8 *)var_s0_2 + 0x3E4);
                *(s32 *)((u8 *)temp_v1 + 0x28) = (*(s32 *)((u8 *)temp_v1 + 0x28) & ~0xFC) | 0x10;
                func_800165E0(*(void **)((u8 *)var_s0_2 + 0x3E4), (s32)D_80109688[sp2C]);
                var_a0 = 0x50;
                if (var_s2_2 >= 2) {
                    var_a0 = (var_s7 * 2) - 0x70;
                    var_s1_2 = 0x80;
                }
                var_v1 = 0x37;
                if (((var_s2_2 == 0) | (var_s2_2 == 2)) == 0) {
                    var_v1 = (var_s6 * 2) - 0x57;
                    var_s1_2 |= 0x100;
                }
                *(s16 *)((u8 *)*(void **)((u8 *)var_s0_2 + 0x3E4) + 0x20) = var_a0;
                *(s16 *)((u8 *)*(void **)((u8 *)var_s0_2 + 0x3E4) + 0x22) = var_v1;
                *(s16 *)((u8 *)*(void **)((u8 *)var_s0_2 + 0x3E4) + 0x1E) = (s16)(var_s1_2 | 2);
                temp_a0 = *(void **)((u8 *)var_s0_2 + 0x3E4);
                var_s2_2 += 1;
                var_s0_2 = (u8 *)var_s0_2 + 4;
                func_800448A4(temp_a0, 0x12, 0x2A);
            } while (var_s2_2 < 4);
        }
    }
}
