/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

s32 func_80016718();
s32 func_80016990();
s32 func_800175C0();
s32 func_8003D64C();
s32 func_8003E6EC();
void *func_80047B44();
s32 func_80073304();
extern s32 *D_800CA31C;
extern u8 D_80109A60[];

void func_80016A34(void *arg0) {
int __repair_literal;

    void *temp_s2;
    unsigned temp_s0_2;
    u8 temp_v1;
    unsigned temp_s0;
    u16 temp_v1_3;
    register u16 temp_v1_2;
    u8 temp_v0_2;
    void *temp_v0;

    temp_s2 = arg0 + 0x24;
    temp_v0 = func_80047B44((*(s32 *)((char *)(arg0) + 0x20)), arg0 + 0x30, temp_s2, 0);
    if (temp_v0 != NULL) {
        if ((*(u16 *)((char *)(temp_v0) + 0x26)) & 0x1000) {
            func_800175C0((*(s32 *)((char *)(arg0) + 0x20)), 2, 0x20000, temp_s2, 0, 1);
            func_80073304(temp_v0, temp_s2, (*(s32 *)((char *)(arg0) + 0x20)));
        }
        if (((*(u16 *)((char *)(arg0) + 0x78)) == 2) && ((temp_v0_2 = (*(u8 *)((char *)(temp_v0) + 0x29)), (temp_v0_2 == 0)) || (*(D_80109A60 + temp_v0_2) != 0))) {
            temp_v1 = (*(u8 *)((char *)(temp_v0) + 0x28));
            if (temp_v1) {
                *(D_80109A60 + temp_v1) = 1;
            }
        }
        temp_s0 = (*(s32 *)((char *)(temp_v0) + 8));
        func_80016718(arg0);
        func_80016990(arg0, temp_s0);
        (*(s32 *)((char *)(arg0) + 0x60)) |= 0x400;
        (*(s32 *)((char *)((int)arg0) + 0x20)) = temp_s0;
        goto block_36;
    }
    temp_s0_2 = (*(s32 *)((char *)(arg0) + 0x20));
    if (temp_s0_2 == 0) {
        temp_v1_2 = (*(u16 *)((char *)(arg0) + 0x78));
        if ((temp_v1_2 != 0x1F) && (temp_v1_2 != 0x46)) {

        } else {
            goto block_39;
        }
    } else if ((func_8003D64C(temp_s2, temp_s0_2) << 0x18) == 0) {
        func_80016718(arg0);
        temp_v1_3 = (*(u16 *)((char *)(arg0) + 0x78));
__repair_literal = 8;

        if (temp_v1_3 >= __repair_literal) {
            switch (temp_v1_3) {                    /* switch 2; irregular */
            case 0x24:                              /* switch 2 */
                if ((func_8003E6EC(*D_800CA31C, arg0, 0) << 0x18) == 0) {
                    (*(s32 *)((char *)(arg0) + 0x24)) = (s32) (*(s32 *)((char *)(arg0) + 0x30));
                    (*(s32 *)((char *)(arg0) + 0x28)) = (s32) (*(s32 *)((char *)(arg0) + 0x34));
                    (*(s32 *)((char *)(arg0) + 0x3C)) = (s32) (*(s32 *)((char *)((unsigned short)arg0) + 0x48));
                    (*(s32 *)((char *)(arg0) + 0x2C)) = (s32) (*(s32 *)((char *)(arg0) + 0x38));
                    (*(s32 *)((char *)(arg0) + 0x40)) = (s32) (*(s32 *)((char *)(arg0) + 0x4C));
                    (*(s32 *)((char *)(arg0) + 0x44)) = (s32) (*(s32 *)((char *)(arg0) + (int)0x50));
block_38:
                    func_80016990(arg0, temp_s0_2);
                } else {
                    goto block_36;
                }
                break;
            case 0x4C:                              /* switch 2 */
            case 1:                                 /* switch 1 */
                if (!((*(s32 *)((char *)(arg0) + 0x58)) & 0x80000)) {
                    (*(s32 *)((char *)(arg0) + 0x28)) = (s32) (*(s32 *)((char *)(arg0) + 0x34));
                    (*(s32 *)((char *)(arg0) + (unsigned)0x24)) = (s32) (*(s32 *)((char *)(arg0) + 0x30));
                    (*(s32 *)((char *)(arg0) + 0x2C)) = (s32) (*(s32 *)((char *)(arg0) + 0x38));
                    (*(s32 *)((char *)((short)arg0) + 0x40)) = (s32) (*(s32 *)((char *)(arg0) + 0x4C));
                    (*(s32 *)((char *)(arg0) + 0x3C)) = (s32) (*(s32 *)((char *)(arg0) + 0x48));
                    (*(s32 *)((char *)(arg0) + 0x44)) = (s32) (*(s32 *)((char *)(arg0) + 0x50));
                    {
                    func_80016990(arg0, ((*(s32 *)((char *)(arg0) + 0x20))));break;}
                }
block_34:
                if ((func_8003E6EC(*D_800CA31C, arg0, 0) << 0x18) == 0) {
                    func_80016990(arg0, temp_s0_2);
                }
                goto block_36;
            case 0x4D:                              /* switch 2 */
            case 0x61:                              /* switch 2 */
                if ((*(s32 *)((char *)(arg0) + 0x58)) & 0x80000) {
                    goto block_34;
                }
                (*(s32 *)((char *)((short)arg0) + 0x24)) = (s32) (*(s32 *)((char *)(arg0) + 0x30));
                (*(s32 *)((char *)(arg0) + 0x40)) = (s32) (*(s32 *)((char *)(arg0) + (u32)0x4C));
                (*(s32 *)((char *)(arg0) + 0x28)) = (s32) (*(s32 *)((char *)(arg0) + 0x34));
                (*(s32 *)((char *)(arg0) + 0x2C)) = (s32) (*(s32 *)((char *)((int)arg0) + 0x38));
                (*(s32 *)((char *)(arg0) + 0x3C)) = (s32) (*(s32 *)((char *)(arg0) + 0x48));
                (*(s32 *)((char *)(arg0) + 0x44)) = (s32) (*(s32 *)((char *)(arg0) + 0x50));
                if ((func_8003D64C(arg0 + 0x24, ((*(s32 *)((char *)(arg0) + 0x20)))) << 0x18) != 0) {
                    {
                    func_80016990(arg0, temp_s0_2);break;}
                }
block_39:
                func_8003E6EC(*D_800CA31C, arg0, 0);
                break;
            }
        } else {
            switch (temp_v1_3) {              /* switch 1; irregular */
            case 0:                                 /* switch 1 */
                if ((func_8003E6EC(*D_800CA31C, arg0, 0) << 0x18) == 0) {
                    goto block_38;
                }
                goto block_36;
            }
        }
    } else {
block_36:
        (*(s32 *)((char *)(arg0) + 0x30)) = (s32) (*(s32 *)((char *)(arg0) + 0x24));
        (*(s32 *)((char *)(arg0) + 0x38)) = (s32) (*(s32 *)((char *)((short)arg0) + 0x2C));
        (*(s32 *)((char *)(arg0) + 0x34)) = (s32) (*(s32 *)((char *)((unsigned)arg0) + 0x28));
        (*(s32 *)((char *)(arg0) + 0x48)) = (s32) (*(s32 *)((char *)(arg0) + 0x3C));
        (*(s32 *)((char *)(arg0) + 0x4C)) = (s32) (*(s32 *)((char *)(arg0) + 0x40));
        (*(s32 *)((char *)(arg0) + 0x50)) = (s32) (*(s32 *)((char *)(arg0) + 0x44));
    }
    (*(s32 *)((char *)(arg0) + 0x58)) &= ~1;
}
