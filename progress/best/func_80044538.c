#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
s32 func_80084048();
typedef struct { u32 f0; u8 pad[12]; } Slot_800C0784;
extern Slot_800C0784 D_800C0784[];
typedef struct { u32 f0; u8 pad[12]; } Slot_800C0788;
extern Slot_800C0788 D_800C0788[];
typedef struct { u32 f0; u8 pad[12]; } Slot_800C078C;
extern Slot_800C078C D_800C078C[];
void func_80044538(s32 arg0) {
    s32 temp_s0, temp_v1, var_a2;
    volatile u64 stack_pad;
    u32 var_a1;
    void *temp_a3, *var_v1;
    temp_v1 = arg0 * 0x10;
    var_a2 = 1;
    if (D_800C0784[arg0].f0 != 0) {
        temp_a3 = D_800C0788[arg0].f0;
        var_a1 = 0;
        if (D_800C078C[arg0].f0 != 0) {
            var_v1 = temp_a3;
            do {
                if (M2C_FIELD(var_v1, s32 *, 0) != 0) {
                    if ((u8) M2C_FIELD(var_v1, u8 *, 0x46) >= 5U)
                        M2C_FIELD(var_v1, u8 *, 0x46) = 4U;
                    var_a2 = 0;
                }
                var_a1 += 1;
                var_v1 += 0x4C;
            } while (var_a1 < (u32) D_800C078C[arg0].f0);
        }
        temp_s0 = arg0 * 0x10;
        if (var_a2 != 0) {
            func_80084048(D_800C0788[arg0].f0, 0xA, var_a2, temp_a3);
            func_80084048(M2C_FIELD(M2C_FIELD(D_800C0784[arg0].f0, void **, 0x10), s32 *, 4), 0x1B);
            func_80084048(M2C_FIELD(M2C_FIELD(D_800C0784[arg0].f0, void **, 0x18), s32 *, 8), 0x1A);
            func_80084048(M2C_FIELD(D_800C0784[arg0].f0, s32 *, 0x10), 0x18);
            func_80084048(M2C_FIELD(D_800C0784[arg0].f0, s32 *, 0x18), 0x1A);
            D_800C0784[arg0].f0 = 0;
        }
    }
}
