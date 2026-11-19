void func_8000B9B8(void *, void *, s32);
void func_800426B8(s32, s16, s32);
s32 func_80083E24(void);
void func_80083E44(s32, s32);
void *func_80083E90(s32, s32);
void func_80084048(void *, s32);
extern u8 D_54D910[];
extern u8 D_800C0780[];
extern u8 D_800C0784[];
extern u8 D_800C3CF8[];
extern u8 D_800C447A[];
extern u8 D_800C46DC[];
extern void *D_80109688;

void func_800422F4(s32 arg0) {
int __repair_literal;

    u8 sp10[0x20];
    s32 temp_s6, temp_s0, temp_s2, c;
    u8 *temp_v0, *temp_v0_2, *var_s0;
    s16 id;
    u16 v;

    temp_s6 = func_80083E24();
    temp_s0 = *(s32 *)(D_800C0780 + arg0 * 0x10);
    temp_v0 = (u8 *)func_80083E90(0x30, 0x2D);
    func_8000B9B8(temp_v0, D_54D910 + temp_s0, 0x30);
    temp_s2 = *(s32 *)(temp_v0 + 4);
    temp_v0_2 = (u8 *)func_80083E90(temp_s2 * 0x44, 0x2D);
    func_8000B9B8(temp_v0_2, D_54D910 + *(s32 *)(temp_v0 + 0), *(s32 *)(temp_v0 + 4) * 0x44);
    if (temp_s2 != 0) {
        var_s0 = temp_v0_2;
        __repair_rows: {
            id = **(s16 **)(var_s0 + 0x28);
            if (id != arg0) {
__repair_literal = 0x10;

                if (*(s32 *)(D_800C0784 + id * __repair_literal) == 0) {
                    func_800426B8(*(s32 *)((u8 *)D_80109688 + 8), id, 0);
                }
            }
            func_8000B9B8(sp10, D_54D910 + *(s32 *)(var_s0 + 0x24), 0x20);
            c = sp10[0x1E];
            if (c >= 0xD) {
                if (c >= 0x12) {
                    if (c < 0x27 && c >= 0x23) {
                        v = *(u16 *)(var_s0 + 0x2C);
                        if (v != 0) {
                            id = *(s16 *)(D_800C46DC + v * 0xE8);
                            if (id != -1 && *(s32 *)(D_800C0784 + id * 0x10) == 0) {
                                func_800426B8(*(s32 *)((u8 *)D_80109688 + 8), id, 1);
                            }
                        }
                        v = *(u16 *)(var_s0 + 0x30);
                        if (v != 0) {
                            id = *(s16 *)(D_800C46DC + v * 0xE8);
                            if (id != -1 && *(s32 *)(D_800C0784 + id * 0x10) == 0) {
                                func_800426B8(*(s32 *)((u8 *)D_80109688 + 8), id, 1);
                            }
                        }
                        v = *(u16 *)(var_s0 + 0x34);
                        if (v != 0) {
                            func_800426B8(*(s32 *)((u8 *)D_80109688 + 8), *(s16 *)(D_800C447A + v * 0x10), 1);
                        }
                        v = *(u16 *)(var_s0 + 0x36);
                        if (v != 0) {
                            func_800426B8(*(s32 *)((u8 *)D_80109688 + 8), *(s16 *)(D_800C447A + v * 0x10), 1);
                        }
                        v = *(u16 *)(var_s0 + 0x38);
                        if (v != 0) {
                            func_800426B8(*(s32 *)((u8 *)D_80109688 + 8), *(s16 *)(D_800C447A + v * 0x10), 1);
                        }
                        v = *(u16 *)(var_s0 + 0x3A);
                        if (v != 0) {
                            func_800426B8(*(s32 *)((u8 *)D_80109688 + 8), *(s16 *)(D_800C447A + v * 0x10), 1);
                        }
                        c = *(s32 *)(var_s0 + 0x3C);
                        if (c != 0) {
                            func_800426B8(*(s32 *)((u8 *)D_80109688 + 8), *(s16 *)(D_800C447A + c * 0x10), 1);
                        }
                    }
                } else {
                    v = *(u16 *)(var_s0 + 0x3A);
                    if (v != 0) {
                        id = *(s16 *)(D_800C46DC + v * 0xE8);
                        if (id != -1 && *(s32 *)(D_800C0784 + id * 0x10) == 0) {
                            func_800426B8(*(s32 *)((u8 *)D_80109688 + 8), id, 1);
                        }
                    }
                    id = **(s16 **)(D_800C3CF8 + *(u16 *)(var_s0 + 0x38) * 0xC);
                    if (*(s32 *)(D_800C0784 + id * 0x10) == 0) {
                        func_800426B8(*(s32 *)((u8 *)D_80109688 + 8), id, 1);
                    }
                }
            }
            var_s0 += 0x44;
        }
if ((u32)var_s0 < (u32)(temp_s2 * 0x44 + temp_v0_2)) goto __repair_rows;
    }
    do { func_80084048(temp_v0_2, 0x2D); } while (0);
    func_80084048(temp_v0, 0x2D);
    func_80083E44(arg0, temp_s6);
}
