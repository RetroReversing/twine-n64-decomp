
s32 func_8000B9B8(u16 *, void *, u32);
s32 packFadedRgb5A1(u32, s32, s32);
u32 func_8001499C(u16 *);
s32 func_80014A0C(u16 *, u16 *);
s32 func_80083E24();
s32 func_80083E44(s32);
u16 *func_80083E90(u32, s32);
s32 func_80084048(u16 *, s32);
s32 memcpy(u16 *, u16 *, u32);
extern s32 D_54D910;
extern u8 gColorFadeLevel;

void func_80041F68(void *arg0) {
    u16 *sp1C;
    s32 sp14;
    u16 *temp_fp;
    u16 *temp_s4;
    u16 *var_s2;
    u16 *var_s5;
    u16 *var_s7;
    u16 temp_s0;
    unsigned temp_a2;
    u32 temp_v0;
    
    u32 var_a0;
    u32 var_s0;
    unsigned long var_s1;
    u32 i;
    u8 *p;
    u32 n;
    volatile u64 frame_gap;

    sp14 = func_80083E24();
    sp1C = func_80083E90(*(u32 *)((u8 *)arg0 + 0x14) * 8, 0x18);
    temp_fp = func_80083E90(*(u32 *)((u8 *)arg0 + 0x1C) * 0xC, 0x19);
    var_a0 = *(u32 *)((u8 *)arg0 + 0x2C);
    if (var_a0 < *(u32 *)((u8 *)arg0 + 0x24)) {
        var_a0 = *(u32 *)((u8 *)arg0 + 0x24);
    }
    temp_s4 = func_80083E90(var_a0, 0x2D);
    func_8000B9B8(sp1C, (u8 *)*(u16 **)((u8 *)arg0 + 0x10) + (u32)&D_54D910, *(u32 *)((u8 *)arg0 + 0x14) * 8);
    do { func_8000B9B8(temp_fp, (u8 *)*(u16 **)((u8 *)arg0 + 0x18) + (u32)&D_54D910, *(u32 *)((u8 *)arg0 + 0x1C) * 0xC); } while (0);
    func_8000B9B8(temp_s4, (u8 *)*(u16 **)((u8 *)arg0 + 0x28) + (u32)&D_54D910, *(u32 *)((u8 *)arg0 + 0x2C));
    var_s0 = func_8001499C(temp_s4);
    if (var_s0 != 0) {
        var_s7 = func_80083E90(var_s0, 0x1A);
        func_80014A0C(var_s7, temp_s4);
    } else {
        var_s7 = func_80083E90(*(u32 *)((u8 *)arg0 + 0x2C), 0x1A);
        memcpy(var_s7, temp_s4, *(u32 *)((u8 *)arg0 + 0x2C));
    }
    func_8000B9B8(temp_s4, (u8 *)*(u16 **)((u8 *)arg0 + 0x20) + (u32)&D_54D910, *(u32 *)((u8 *)arg0 + 0x24));
    var_s0 = func_8001499C(temp_s4);
    if (var_s0 != 0) {
        var_s5 = func_80083E90(var_s0, 0x1B);
        func_80014A0C(var_s5, temp_s4);
    } else {
        var_s0 = *(u32 *)((u8 *)arg0 + 0x24);
        var_s5 = func_80083E90(var_s0, 0x1B);
        memcpy(var_s5, temp_s4, *(u32 *)((u8 *)arg0 + 0x24));
    }
    i = var_s0 >> 1;
    if (gColorFadeLevel != 0) {
        var_s1 = 0;
        if (i != 0) {
            var_s2 = var_s5;
            do {
                temp_s0 = *var_s2;
                var_s1 += 1;
                n = temp_s0 & 0xFFFF;
                *var_s2 = packFadedRgb5A1(n >> 0xB, (n >> 6) & 0x1F, (n >> 1) & 0x1F) + (temp_s0 & 1);
                var_s2 += 1;
            } while (var_s1 < (var_s0 >> 1));
        }
    }
    func_80084048(temp_s4, 0x2D);
    *(u16 **)((u8 *)arg0 + 0x10) = sp1C;
    *(u16 **)((u8 *)arg0 + 0x18) = temp_fp;
    for (i = 0; i < *(u32 *)((u8 *)arg0 + 0x14); i++) {
        p = (u8 *)sp1C + i * 8;
        *(s32 *)(p + 4) = *(s32 *)(p + 4) * 2;
        *(u8 **)(p + 4) = *(u8 **)(p + 4) + (u32)var_s5;
    }
    for (i = 0; i < *(u32 *)((u8 *)arg0 + 0x1C); i++) {
        p = (u8 *)temp_fp + i * 12;
        *(u8 **)(p + 8) = *(u8 **)(p + 8) + (u32)var_s7;
    }
    for (i = 0; i < *(u32 *)((u8 *)arg0 + 0x1C); i++) {
        p = (u8 *)temp_fp + i * 12;
        n = *(u16 *)(p + 4) + 1;
        if (p[6] >= 2) {
            n *= p[6];
        }
        {
            u32 sz = ((*(u16 *)(p + 2) + 1) * n) >> 1;
            if (!(p[0] & 1)) {
                if (sz != 0) {
                    u8 *q;
                    for (q = *(u8 **)(p + 8); (u32)q < (u32)(sz + *(u8 **)(p + 8)); q++) {
                        u8 v = *q;
                        *q = (v >> 4) | ((v & 0xF) * 0x10);
                    }
                }
            }
        }
    }
    func_80083E44(sp14);
}
