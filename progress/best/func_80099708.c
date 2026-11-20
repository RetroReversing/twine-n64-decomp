/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */
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

s32 func_8008C5DC();
s32 func_8009876C();
s32 func_80098A18();
extern u8 D_800CF540;
extern void *D_800FDB74;
extern u8 D_801002EA;
extern u8 D_8010A930;
extern u8 D_8010D720;
extern char D_8010D724[];
extern char D_8010D734[];
extern char D_8010D784[];
extern u8 D_80110DB0;
extern char D_80117388[];
extern char D_80117389[];

typedef struct { unsigned char field_0; unsigned char field_1; unsigned short field_2; } __repair_record_temp_a0_2;
s32 func_80099708(u32 arg0) {
int __repair_literal;

    
    s32 temp_s1;
    s32 temp_s3;
    s32 var_a1;
s32 __repair_phase_var_a1;
    s32 var_a2;
    
    u32 temp_v0;
    void *temp_a0_2;
    void *temp_s0;
    union { void * pointer; s32 value; } __repair_phase_storage;
    void *var_v1;

    var_a2 = -1;
    if (D_800CF540 != 0) {
        if (arg0 == -1U) {
            goto block_11;
        }
        var_v1 = D_800FDB74;
        __repair_phase_storage.pointer = NULL;
        if (var_v1 != NULL) {
            for (;;) {
                temp_v0 = M2C_FIELD(var_v1, u32 *, 8);
                if (temp_v0 == arg0) {
                    __repair_phase_storage.pointer = var_v1;
                } else {
                    __repair_phase_storage.pointer = NULL;
                    if (arg0 >= temp_v0) {
                        var_v1 = M2C_FIELD(var_v1, void **, 0);
                        if (var_v1 != NULL) {
                            continue;
                        }
                    }
                }
                break;
            }
        }
        if (__repair_phase_storage.pointer != NULL) {
            var_a1 = M2C_FIELD(__repair_phase_storage.pointer, s32 *, 0xC);
        } else {
block_11:
            var_a1 = -1;
        }
        __repair_phase_storage.value = -1;
        if (var_a1 != -1) {
            do {
                temp_s1 = var_a1 & 0xFF;
                __repair_phase_storage.value = temp_s1 * 0x1A0;
                temp_s3 = *(s32 *)(D_8010D734 + __repair_phase_storage.value);
                if (*(s32 *)(D_8010D784 + __repair_phase_storage.value) == var_a1) {
                    if (*(s32 *)(D_8010D724 + __repair_phase_storage.value) != 0) {
                        temp_s0 = __repair_phase_storage.value + D_8010D724;
                        func_8009876C(temp_s0, var_a1, var_a2);
                        M2C_FIELD(temp_s0, s32 *, 0x28) = 0;
                        M2C_FIELD(temp_s0, s32 *, 0x24) &= ~3;
                        func_80098A18(temp_s0);
                        __repair_phase_var_a1 = (s32) M2C_FIELD(temp_s0, u8 *, 0x63);
                        M2C_FIELD(temp_s0, s32 *, 0) = 0;
                        M2C_FIELD(temp_s0, s8 *, 0x2E) = 0;
                        temp_a0_2 = (__repair_phase_var_a1 * 4) + D_80117388;
                        if (((__repair_record_temp_a0_2*)temp_a0_2)->field_2 == 0) {
                            ((__repair_record_temp_a0_2*)temp_a0_2)->field_2 = 1U;
                            if (D_801002EA != 0xFF) {
                                ((__repair_record_temp_a0_2*)temp_a0_2)->field_1 = 0xFF;
                                ((__repair_record_temp_a0_2*)temp_a0_2)->field_0 = (u8) D_80110DB0;
__repair_phase_storage.value = 4;

                                *(D_80117389 + (D_80110DB0 * __repair_phase_storage.value)) = (s8) __repair_phase_var_a1;
                            } else {
                                ((__repair_record_temp_a0_2*)temp_a0_2)->field_1 = 0xFF;
                                ((__repair_record_temp_a0_2*)temp_a0_2)->field_0 = 0xFFU;
                                D_801002EA = (u8) __repair_phase_var_a1;
                            }
                            D_80110DB0 = (u8) __repair_phase_var_a1;
                            if (M2C_FIELD(temp_s0, u8 *, 0x4C) != 0) {
                                D_8010A930 -= 1;
                                M2C_FIELD(temp_s0, s32 *, 0x60) = -1;
                            } else {
                                D_8010D720 -= 1;
                                goto block_23;
                            }
                        } else {
block_23:
                            M2C_FIELD(temp_s0, s32 *, 0x60) = -1;
                        }
                    }
                    func_8008C5DC(temp_s1);
                    var_a2 = 0;
                }
                var_a1 = temp_s3;
            } while (var_a1 != -1);
            goto block_26;
        }
    } else {
block_26:
        __repair_phase_storage.value = var_a2;
    }
    return var_a2;
}
