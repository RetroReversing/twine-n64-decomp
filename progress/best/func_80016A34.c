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

s32 func_80016718();
s32 func_80016990();
s32 func_800175C0();
s32 func_8003D64C();
s32 func_8003E6EC();
void *func_80047B44();
s32 func_80073304();
extern s32 *D_800CA31C;
extern unsigned char D_80109A60[];

void func_80016A34(void *arg0) {
    s32 temp_s0;
    s32 temp_s0_2;
    u16 temp_v1_2;
    s32 temp_v1_3;
    u8 temp_v0_2;
    u8 temp_v1;
    void *temp_s2;
    void *temp_v0;

    temp_s2 = arg0 + 0x24;
    temp_v0 = func_80047B44(M2C_FIELD(arg0, s32 *, 0x20), arg0 + 0x30, temp_s2, 0);
    if (temp_v0 != NULL) {
        if (M2C_FIELD(temp_v0, u16 *, 0x26) & 0x1000) {
            func_800175C0(M2C_FIELD(arg0, s32 *, 0x20), 2, 0x20000, temp_s2, 0, 1);
            func_80073304(temp_v0, temp_s2, M2C_FIELD(arg0, s32 *, 0x20));
        }
        if ((M2C_FIELD(arg0, u16 *, 0x78) == 2) && ((temp_v0_2 = M2C_FIELD(temp_v0, u8 *, 0x29), (temp_v0_2 == 0)) || (*(D_80109A60 + temp_v0_2) != 0))) {
            temp_v1 = M2C_FIELD(temp_v0, u8 *, 0x28);
            if (temp_v1 != 0) {
                *(D_80109A60 + temp_v1) = 1;
            }
        }
        temp_s0 = M2C_FIELD(temp_v0, s32 *, 8);
        func_80016718(arg0);
        func_80016990(arg0, temp_s0);
        M2C_FIELD(arg0, s32 *, 0x20) = temp_s0;
        M2C_FIELD(arg0, s32 *, 0x60) |= 0x400;
        goto block_36;
    }
    temp_s0_2 = M2C_FIELD(arg0, s32 *, 0x20);
    if (temp_s0_2 == 0) {
        temp_v1_2 = M2C_FIELD(arg0, u16 *, 0x78);
        if ((temp_v1_2 != 0x1F) && (temp_v1_2 != 0x46)) {

        } else {
            goto block_39;
        }
    } else if ((func_8003D64C(temp_s2, temp_s0_2) << 0x18) == 0) {
        func_80016718(arg0);
        temp_v1_3 = M2C_FIELD(arg0, u16 *, 0x78);
        if ((s32) temp_v1_3 < 8) {
            switch ((s32) temp_v1_3) {              /* switch 1; irregular */
            case 0:                                 /* switch 1 */
                if ((func_8003E6EC(*D_800CA31C, arg0, 0) << 0x18) == 0) {
                    goto block_38;
                }
                goto block_36;
            }
        } else {
            switch (temp_v1_3) {                    /* switch 2; irregular */
            case 0x24:                              /* switch 2 */
                if ((func_8003E6EC(*D_800CA31C, arg0, 0) << 0x18) == 0) {
                    M2C_FIELD(arg0, s32 *, 0x24) = (s32) M2C_FIELD(arg0, s32 *, 0x30);
                    M2C_FIELD(arg0, s32 *, 0x28) = (s32) M2C_FIELD(arg0, s32 *, 0x34);
                    M2C_FIELD(arg0, s32 *, 0x2C) = (s32) M2C_FIELD(arg0, s32 *, 0x38);
                    M2C_FIELD(arg0, s32 *, 0x3C) = (s32) M2C_FIELD(arg0, s32 *, 0x48);
                    M2C_FIELD(arg0, s32 *, 0x40) = (s32) M2C_FIELD(arg0, s32 *, 0x4C);
                    M2C_FIELD(arg0, s32 *, 0x44) = (s32) M2C_FIELD(arg0, s32 *, 0x50);
block_38:
                    func_80016990(arg0, temp_s0_2);
                } else {
                    goto block_36;
                }
                break;
            case 0x4C:                              /* switch 2 */
            case 1:                                 /* switch 1 */
                if (!(M2C_FIELD(arg0, s32 *, 0x58) & 0x80000)) {
                    M2C_FIELD(arg0, s32 *, 0x24) = (s32) M2C_FIELD(arg0, s32 *, 0x30);
                    M2C_FIELD(arg0, s32 *, 0x28) = (s32) M2C_FIELD(arg0, s32 *, 0x34);
                    M2C_FIELD(arg0, s32 *, 0x2C) = (s32) M2C_FIELD(arg0, s32 *, 0x38);
                    M2C_FIELD(arg0, s32 *, 0x3C) = (s32) M2C_FIELD(arg0, s32 *, 0x48);
                    M2C_FIELD(arg0, s32 *, 0x40) = (s32) M2C_FIELD(arg0, s32 *, 0x4C);
                    M2C_FIELD(arg0, s32 *, 0x44) = (s32) M2C_FIELD(arg0, s32 *, 0x50);
                    {
                    func_80016990(arg0, temp_s0_2);break;}
                }
block_34:
                if ((func_8003E6EC(*D_800CA31C, arg0, 0) << 0x18) == 0) {
                    func_80016990(arg0, temp_s0_2);
                }
                goto block_36;
            case 0x4D:                              /* switch 2 */
            case 0x61:                              /* switch 2 */
                if (M2C_FIELD(arg0, s32 *, 0x58) & 0x80000) {
                    goto block_34;
                }
                M2C_FIELD(arg0, s32 *, 0x24) = (s32) M2C_FIELD(arg0, s32 *, 0x30);
                M2C_FIELD(arg0, s32 *, 0x28) = (s32) M2C_FIELD(arg0, s32 *, 0x34);
                M2C_FIELD(arg0, s32 *, 0x2C) = (s32) M2C_FIELD(arg0, s32 *, 0x38);
                M2C_FIELD(arg0, s32 *, 0x3C) = (s32) M2C_FIELD(arg0, s32 *, 0x48);
                M2C_FIELD(arg0, s32 *, 0x40) = (s32) M2C_FIELD(arg0, s32 *, 0x4C);
                M2C_FIELD(arg0, s32 *, 0x44) = (s32) M2C_FIELD(arg0, s32 *, 0x50);
                if ((func_8003D64C(arg0 + 0x24, temp_s0_2) << 0x18) != 0) {
                    {
                    func_80016990(arg0, temp_s0_2);break;}
                }
block_39:
                func_8003E6EC(*D_800CA31C, arg0, 0);
                break;
            }
        }
    } else {
block_36:
        M2C_FIELD(arg0, s32 *, 0x30) = (s32) M2C_FIELD(arg0, s32 *, 0x24);
        M2C_FIELD(arg0, s32 *, 0x34) = (s32) M2C_FIELD(arg0, s32 *, 0x28);
        M2C_FIELD(arg0, s32 *, 0x38) = (s32) M2C_FIELD(arg0, s32 *, 0x2C);
        M2C_FIELD(arg0, s32 *, 0x48) = (s32) M2C_FIELD(arg0, s32 *, 0x3C);
        M2C_FIELD(arg0, s32 *, 0x4C) = (s32) M2C_FIELD(arg0, s32 *, 0x40);
        M2C_FIELD(arg0, s32 *, 0x50) = (s32) M2C_FIELD(arg0, s32 *, 0x44);
    }
    M2C_FIELD(arg0, s32 *, 0x58) &= ~1;
}
