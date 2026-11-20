/* Refreshes the menu list for the current slot: resets the list, loads entries and graphics, and updates the selection state. */
#ifndef M2C_DEFINES
#define M2C_DEFINES
typedef s32 M2C_UNK;
typedef s8 M2C_UNK8;
typedef s16 M2C_UNK16;
typedef s32 M2C_UNK32;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define M2C_CARRY 0
#define M2C_OVERFLOW(a) (0)
#endif

M2C_UNK func_800160FC(s32, s32, M2C_UNK);           /* extern */
s32 func_800162BC(u8);                              /* extern */
s32 func_80018318(s32);                             /* extern */
s16 func_8001E760(M2C_UNK, u8);                     /* extern */
M2C_UNK func_8002135C(s16, s16);                    /* extern */
M2C_UNK func_80022A30(u8, M2C_UNK, M2C_UNK, M2C_UNK, s32); /* extern */
M2C_UNK func_80022AD8(u8);                          /* extern */
M2C_UNK func_80022E18(u8);                          /* extern */
void *func_800262A8(s32, M2C_UNK);                  /* extern */
void *func_8002638C(s32, M2C_UNK);                  /* extern */
M2C_UNK func_8002A644(M2C_UNK *, M2C_UNK *, M2C_UNK, M2C_UNK, s32, s32, s32, s32, s32, M2C_UNK *, M2C_UNK *); /* extern */
M2C_UNK func_8002A7CC(M2C_UNK *, s32, s32, s32);    /* extern */
void *func_8002A9A8(M2C_UNK *, s16);                /* extern */
M2C_UNK func_8002AC04(M2C_UNK *, M2C_UNK);          /* extern */
s32 func_80087100(s32);                             /* extern */
extern s16 D_800B60E2;
extern M2C_UNK *D_800B60E4;
extern u8 D_800BD68E;
extern u8 D_800BD68F;
extern M2C_UNK D_800C469E;
extern M2C_UNK D_800C46D8;
extern M2C_UNK D_800C46DA;
extern M2C_UNK D_800E0ECC;
extern M2C_UNK D_801003E0;
extern M2C_UNK D_801093A8;
extern void *D_80109BB0;
extern M2C_UNK D_80109D28;
extern M2C_UNK D_8010A500;
extern M2C_UNK func_8001E898;
extern M2C_UNK func_8001EAF0;

void menuRefreshSlot(void) {
    char *__repair_addr;
    s16 var_s3;
    union { s32 * pointer; s32 value; } __repair_phase_storage;
    s32 temp_s5;
    s32 temp_v0_2;
    u16 var_s1;
    s32 var_s2;
    s8 var_v0;
    u16 *temp_a1;
    u16 *temp_v1;
    u16 temp_a0;
    void *temp_s0_2;
    void *temp_s1;
    void *temp_v0;
    void *var_s4;

    D_800B60E4 = &D_801003E0;
    (*(u16 *)&D_800B60E2) = 0;
    func_8002A644(&D_801003E0, &D_801093A8, 0x1D4, 6, 0x22, 0xB4, 0x46, 0xD, 1, &func_8001E898, &func_8001EAF0);
    temp_v0 = *((M2C_UNK *)((s8 *)&D_8010A500 + (D_800BD68F * 4)));
    var_s4 = NULL;
    if (temp_v0 != NULL) {
        temp_s5 = M2C_FIELD(temp_v0, s32 *, 0x6C);
        if (temp_s5 != 0) {
            func_80022A30(D_800BD68E, 0x20, 0x42, 0x72, 0x50);
            temp_v1 = (void *)((D_800BD68F * 2)); temp_v1 = (void *)((char *)temp_v1 + (s32)(&D_800E0ECC));
            if ((u16) *temp_v1 >= 0x28U) {
                *temp_v1 = 0;
            }
            temp_a1 = (void *)((D_800BD68F * 2)); temp_a1 = (void *)((char *)temp_a1 + (s32)(&D_800E0ECC));
            temp_a0 = *((u16 *)((s8 *)&D_800C469E + (*temp_a1 * 0xE8)));
            if ((temp_a0 & 0xFFFF) != 0x21) {
                *temp_a1 = temp_a0;
            }
            var_s2 = 0;
            var_s3 = 0;
            do {
                var_s1 = var_s2 & 0xFFFF;
__repair_addr = (char *)((temp_s5 + (var_s1 * 8)));

                if (((M2C_FIELD(__repair_addr, u8 *, 0x1FC) != 0) | (var_s1 == 0)) != 0) {
                    temp_v0_2 = func_800162BC(D_800BD68E);
                    __repair_phase_storage.pointer = var_s1 + &D_80109D28;
                    *__repair_phase_storage.pointer = temp_v0_2;
                    if (temp_v0_2 != 0) {
                        func_800160FC(*__repair_phase_storage.pointer, func_80087100((var_s2 | 0x6000) & 0xFFFF), 0x40);
                        func_8002A7CC(D_800B60E4, *__repair_phase_storage.pointer, var_s2 & 0xFF, func_80018318(*__repair_phase_storage.pointer) & 0xFF);
                    }
                    if (var_s1 == *((u16 *)&D_800E0ECC + D_800BD68F)) {
                        var_s4 = func_8002A9A8(D_800B60E4, var_s3);
                    }
                    var_s3 += 1;
                }
                var_s2 += 1;
            } while ((u32) (var_s2 & 0xFFFF) < 0x25U);
            if (var_s4 != NULL) {
                s32 offset;
                temp_s1 = func_8002638C(M2C_FIELD(D_80109BB0, s32 *, 0x10), 0x62);
                temp_s0_2 = func_800262A8(M2C_FIELD(D_80109BB0, s32 *, 0x10), 0x1E);
                offset = M2C_FIELD(var_s4, u8 *, 8) * 0xE8;
                func_8002135C(*((s16 *)((s8 *)&D_800C46D8 + offset)), *((s16 *)((s8 *)&D_800C46DA + offset)));
                if (temp_s1 != NULL) {
                    M2C_FIELD(temp_s1, s16 *, 0) = func_8001E760(0, M2C_FIELD(var_s4, u8 *, 8));
                    M2C_FIELD(temp_s1, u16 *, 0x28) = func_8001E760(1, M2C_FIELD(var_s4, u8 *, 8));
                }
                if (temp_s0_2 != NULL) {
                    if (M2C_FIELD(var_s4, u8 *, 8) == 0x24) {
                        M2C_FIELD(temp_s0_2, u8 *, 0x1C) = 0x80;
                    } else {
                        M2C_FIELD(temp_s0_2, u8 *, 0x1C) = 0x90;
                    }
                }
                M2C_FIELD(D_80109BB0, u8 *, 0x30) = 0xFF;
            }
            func_80022E18(D_800BD68E);
            func_80022AD8(D_800BD68E);
            func_8002AC04(D_800B60E4, 1);
        }
    }
}
