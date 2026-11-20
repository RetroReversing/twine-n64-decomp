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

s32 func_8000A454();
s32 func_8000A894();
void *func_80015DAC();
void *func_80015F74();
s32 func_80016314();
s32 func_80016718();
s32 func_80016990();
s32 func_80031700();
f32 func_80045590();
extern s16 D_800C7EA0;
extern char D_800C7EA4[];
extern char D_800C7EC4[];
extern char D_800E1A70[];
extern u8 D_80109A60[];
extern s32 D_80109B98;
extern s32 D_8010A500;
extern char D_8010D380[];
extern char D_8010D2C0[];

void func_800740D0(void *arg0) {
    s16 *__base_D_800C7EA0;
    char *__base_D_8010D380;
    char *__base_D_8010D2C0;
    char *__base_D_800C7EA4;
    volatile long long stack_pad;
    s32 temp_v1;
    s16 var_v0;
    s32 *temp_v1_8;
    s32 temp_a0_4;
    s32 temp_a1_3;
    s32 temp_s0;
    s32 temp_v0_2;
    s32 temp_v0_5;
    s32 temp_v0_7;
    s32 temp_v1_2;
    s32 temp_v1_3;
    s32 temp_v1_5;
    s32 temp_v1_6;
    u16 temp_v0_3;
    u16 temp_v0_4;
    u8 temp_a0;
    u8 temp_a0_3;
    u8 temp_a1_2;
    u8 temp_v1_4;
    void *temp_a0_2;
    void *temp_a0_5;
    void *temp_a0_6;
    void *temp_a0_7;
    void *temp_a1;
    void *temp_s1;
    void *temp_s3;
    void *temp_v0;
    void *temp_v0_6;
    void *temp_v1_7;
    void *var_s0;

    temp_s1 = M2C_FIELD(arg0, void **, 0x6C);
    temp_v0 = M2C_FIELD(temp_s1, void **, 0x2C);
    if ((temp_v0 != NULL) && (M2C_FIELD(temp_v0, u16 *, 0x78) != 1)) {
        M2C_FIELD(temp_s1, void **, 0x2C) = NULL;
    }
    temp_v1 = M2C_FIELD(arg0, s16 *, 0x7A);
    M2C_FIELD(arg0, f32 *, 0x40) += M2C_FIELD(temp_s1, f32 *, 0x14);
    switch (temp_v1) {
    case 0:
        __base_D_8010D380 = D_8010D380;
        if (*(s32 *)((M2C_FIELD(temp_s1, u8 *, 0x34) * 4) + ((M2C_FIELD(temp_s1, u8 *, 0x33) * 0x1C) + __base_D_8010D380)) == M2C_FIELD(temp_s1, s32 *, 0x18)) {
            temp_s3 = M2C_FIELD(temp_s1, void **, 4);
            if ((M2C_FIELD(temp_s1, f32 *, 0xC) != 65536.0f) && (func_80045590(temp_s1 + 8, D_8010A500 + 0x24) > (2.0f * M2C_FIELD(temp_s1, f32 *, 0x28)))) {
                var_s0 = func_80015DAC();
                if (var_s0 != NULL) {
do {
                    if ((M2C_FIELD(var_s0, u16 *, 0x78) == 0x19) && (M2C_FIELD(M2C_FIELD(var_s0, void **, 0x6C), s32 *, 0x20) == M2C_FIELD(temp_s1, s32 *, 0x20))) {
                        temp_a0 = M2C_FIELD(temp_s1, u8 *, 0x32);
                        if (temp_a0 != 0) {
                            func_80031700(temp_a0);
                        }
                        temp_v1_2 = M2C_FIELD(temp_s1, s32 *, 0x24);
                        if ((temp_v1_2 != 0) && !(temp_v1_2 & 0x80000000)) {
                            temp_v1_3 = temp_v1_2 & 0xFF;
                            *(D_80109A60 + temp_v1_3) = *(D_80109A60 + temp_v1_3) ^ 1;
                        }
                        M2C_FIELD(var_s0, s16 *, 0x7A) = 8;
                    }
                    var_s0 = M2C_FIELD(var_s0, void **, 0x10);
                    } while (var_s0 != NULL);
                }
            } else {
                temp_v0_2 = M2C_FIELD(temp_s1, s32 *, 0x24);
                if (temp_v0_2 < 0) {
                    D_80109B98 = func_8000A454(temp_v0_2 & 0xFFFFFF, 0x64);
                }
                M2C_FIELD(temp_s3, s32 *, 0x28) &= ~0xFC;
                temp_v1_4 = M2C_FIELD(temp_s1, u8 *, 0x34);
                if (temp_v1_4 == 3) {
                    var_v0 = 1;
                    M2C_FIELD(temp_s3, s32 *, 0x10) = 0;
                } else {
                    M2C_FIELD(temp_s3, s32 *, 0x10) = (s32) (*(s32 *)(D_800C7EC4 + (temp_v1_4 * 4)) | 0xF0);
                    var_v0 = 7;
                }
                M2C_FIELD(arg0, s16 *, 0x7A) = var_v0;
                M2C_FIELD(arg0, void **, 0x18) = (void *) M2C_FIELD(temp_s1, void **, 0);
                if ((M2C_FIELD(temp_s1, s8 *, 0x135) != 0) && (((*(__base_D_800C7EA0 = &D_800C7EA0)) = (s16) M2C_FIELD(temp_s1, u8 *, 0x33), (*(s32 *)(D_800E1A70 + (M2C_FIELD(temp_s1, u8 *, 0x34) * 4)) != 0)) || (*(void **)((M2C_FIELD(temp_s1, u8 *, 0x34) * 4) + D_800E1A70) = func_80015F74((char *)__base_D_800C7EA0 - 0x20), (*(void **)((M2C_FIELD(temp_s1, u8 *, 0x34) * 4) + D_800E1A70) != 0)))) {
                    M2C_FIELD(*(void **)((M2C_FIELD(temp_s1, u8 *, 0x34) * 4) + D_800E1A70), s8 *, 0x29) = 0x1C;
                    M2C_FIELD(*(void **)((M2C_FIELD(temp_s1, u8 *, 0x34) * 4) + D_800E1A70), s16 *, 0x22) = (s16) (M2C_FIELD(temp_s3, u16 *, 0x22) - 5);
                    M2C_FIELD(*(void **)((M2C_FIELD(temp_s1, u8 *, 0x34) * 4) + D_800E1A70), s32 *, 0x10) = 0x88;
                    temp_a0_2 = *(void **)((M2C_FIELD(temp_s1, u8 *, 0x34) * 4) + D_800E1A70);
                    M2C_FIELD(temp_a0_2, s32 *, 0x28) = (s32) ((M2C_FIELD(temp_a0_2, s32 *, 0x28) & ~0xFC) | 0x10);
                }
                temp_a0_3 = M2C_FIELD(temp_s1, u8 *, 0x32);
                if (temp_a0_3 != 0) {
                    func_80031700(temp_a0_3);
                }
                if (M2C_FIELD(temp_s1, s32 *, 0x24) >= 0) {
                    __base_D_800C7EA4 = D_800C7EA4;
                    temp_a0_4 = *(s32 *)(__base_D_800C7EA4 + (M2C_FIELD(temp_s1, u8 *, 0x34) * 4));
                    if (temp_a0_4 != 0) {
                        func_8000A894(temp_a0_4);
                    }
                }
            }
        }
        break;
    case 1:
        M2C_FIELD(M2C_FIELD(temp_s1, void **, 4), s32 *, 0x10) = ((M2C_FIELD(arg0, u16 *, 0x7C) & 2) && (M2C_FIELD(temp_s1, s8 *, 0x136) != 0)) ? (s32) (*(s32 *)(D_800C7EC4 + (M2C_FIELD(temp_s1, u8 *, 0x34) * 4)) | 0x10) : (s32) (*(s32 *)(D_800C7EC4 + (M2C_FIELD(temp_s1, u8 *, 0x34) * 4)) | 0xF0);
        temp_v0_3 = M2C_FIELD(arg0, u16 *, 0x7C) + 1;
        M2C_FIELD(arg0, u16 *, 0x7C) = temp_v0_3;
        if ((s16) temp_v0_3 == 0xE) {
            M2C_FIELD(arg0, s16 *, 0x7A) = 7;
        }
        break;
    case 7:
        temp_a1 = M2C_FIELD(arg0, void **, 0x18);
        if (temp_a1 != NULL) {
            temp_s0 = M2C_FIELD(temp_a1, s32 *, 0x20);
            if (temp_s0 != M2C_FIELD(arg0, s32 *, 0x20)) {
                func_80016718(arg0, temp_a1);
                func_80016990(arg0, temp_s0);
            }
        }
        temp_v0_4 = M2C_FIELD(temp_s1, u16 *, 0x30) - 1;
        M2C_FIELD(temp_s1, u16 *, 0x30) = temp_v0_4;
        if ((s16) temp_v0_4 < 0) {
            temp_a0_5 = M2C_FIELD(temp_s1, void **, 4);
            if (temp_a0_5 != NULL) {
                temp_v0_5 = M2C_FIELD(temp_a0_5, s32 *, 0x10) + 0xF7FFF7F0;
                M2C_FIELD(temp_a0_5, s32 *, 0x10) = temp_v0_5;
                if (!(temp_v0_5 & 0xFF)) {
                    temp_v1_5 = M2C_FIELD(temp_s1, s32 *, 0x24);
                    if (temp_v1_5 != 0) {
                        temp_v1_6 = temp_v1_5 & 0xFF;
                        if (temp_v1_5 >= 0) {
                            *(D_80109A60 + temp_v1_6) = *(D_80109A60 + temp_v1_6) ^ 1;
                        }
                    }
                    M2C_FIELD(arg0, s16 *, 0x7A) = 8;
                }
            }
        }
        temp_v1_7 = *(s32 *)(D_800E1A70 + (M2C_FIELD(temp_s1, u8 *, 0x34) * 4));
        if (temp_v1_7 != NULL) {
            temp_v0_6 = M2C_FIELD(temp_s1, void **, 4);
            if (temp_v0_6 != NULL) {
                M2C_FIELD(temp_v1_7, u32 *, 0x10) = (u32) ((u32) (M2C_FIELD(temp_v0_6, s32 *, 0x10) & 0xFE) >> 1);
            }
        }
        break;
    case 8:
        func_80016314(M2C_FIELD(temp_s1, void **, 4));
        M2C_FIELD(temp_s1, void **, 4) = NULL;
        if (M2C_FIELD(temp_s1, s32 *, 0x1C) & 1) {
            temp_v1_8 = (M2C_FIELD(temp_s1, u8 *, 0x34) * 4) + ((M2C_FIELD(temp_s1, u8 *, 0x33) * 0x1C) + __base_D_8010D380);
            *temp_v1_8 += 1;
        }
        temp_a1_2 = M2C_FIELD(temp_s1, u8 *, 0x34);
        temp_a1_3 = temp_a1_2 * 4;
        if (temp_a1_2 != 0) {
            temp_v0_7 = M2C_FIELD(temp_s1, u8 *, 0x33) * 0x1C;
            __base_D_8010D2C0 = D_8010D2C0;
            if (*(s32 *)(temp_a1_3 + (temp_v0_7 + __base_D_8010D380)) == *(s32 *)(temp_a1_3 + (temp_v0_7 + __base_D_8010D2C0))) {
                temp_a0_6 = *(s32 *)(D_800E1A70 + temp_a1_3);
                if (temp_a0_6 != NULL) {
                    func_80016314(temp_a0_6, temp_a1_3);
                    *(void **)((M2C_FIELD(temp_s1, u8 *, 0x34) * 4) + D_800E1A70) = 0;
                }
            }
        }
        M2C_FIELD(arg0, s32 *, 0x60) |= 1;
        break;
    }
    if (!(M2C_FIELD(arg0, s32 *, 0x60) & 1)) {
        temp_a0_7 = M2C_FIELD(temp_s1, void **, 0x2C);
        if (temp_a0_7 != NULL) {
            M2C_FIELD(temp_a0_7, s32 *, 0x60) |= 0x10000000;
        }
    }
}

