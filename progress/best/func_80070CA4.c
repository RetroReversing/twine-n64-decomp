/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

s32 func_8000A894();
s32 func_80063D38();
s32 func_80084338();
extern char D_800C469C[];

void func_80070CA4(void *arg0) {
int __repair_constant = 0x26;

    s16 temp_v1;
    s8 temp_a1;
    s8 temp_a1_2;
    s8 temp_v0_2;
    s8 temp_v0_3;
    s8 temp_v1_2;
    void *temp_a0;
    void *temp_a2;
    
    void *temp_s4;
    
    void *temp_v1_3;
    void *temp_v1_4;

    temp_s4 = (*(void **)((char *)(arg0) + 0x6C));
    temp_v1 = (*(s16 *)((char *)((*(void **)((char *)(temp_s4) + 0xA8))) + 0x7A));
    switch (temp_v1) {
    default:
    case 0:
    case 1:
    case 2:
    case 4:
    case 8:
        if ((*(u16 *)((char *)(arg0) + 0x78)) == 3) {
            func_80084338(0x118, arg0 + 0x24);
        } else {
            func_8000A894(0x118);
        }
        temp_a0 = (*(void **)((char *)(arg0) + 0x68));
        (*(u8 *)((char *)((unsigned short)temp_a0) + 0x10)) = (u8) (*(u8 *)((char *)(temp_a0) + 0xE));
        temp_a0 = (*(void **)((char *)(arg0) + 0x68));
        temp_v1_2 = (*(s8 *)((char *)(temp_a0) + 0xF));
        if (temp_v1_2 >= 0x27) {
            (*(s8 *)((char *)(temp_a0) + 0xF)) = (s8) (*(u16 *)((char *)(temp_s4) + 0x134));
            return;
        }
        if (!(*(u16 *)(D_800C469C + (temp_v1_2 * 0xE8)) & 0x8000)) {
            do {
                temp_v1_3 = (*(void **)((char *)(arg0) + 0x68));
                temp_v0_2 = (u8) (*(s8 *)((char *)(temp_v1_3) + 0xF)) - 1;
                (*(s8 *)((char *)(temp_v1_3) + 0xF)) = temp_v0_2;
                if (temp_v0_2 & 0x80) {
                    (*(s8 *)((char *)((*(void **)((char *)(arg0) + 0x68))) + 0xF)) = __repair_constant;
                }
            } while (!(*(u16 *)(D_800C469C + ((*(s8 *)((char *)((*(void **)((char *)(arg0) + 0x68))) + 0xF)) * 0xE8)) & 0x8000));
        }
loop_13:
        temp_v1_4 = (*(void **)((char *)(arg0) + 0x68));
        temp_v0_3 = (u8) (*(s8 *)((char *)(temp_v1_4) + 0xF)) - 1;
        (*(s8 *)((char *)(temp_v1_4) + 0xF)) = temp_v0_3;
        if (temp_v0_3 & 0x80) {
            (*(s8 *)((char *)((*(void **)((char *)(arg0) + 0x68))) + 0xF)) = __repair_constant;
        }
        temp_a2 = (*(void **)((char *)(arg0) + 0x68));
        temp_a1 = (*(s8 *)((char *)(temp_a2) + 0xF));
        if (!(*(u16 *)(D_800C469C + (temp_a1 * 0xE8)) & 0x8000)) {
            goto loop_13;
        }
        (*(s8 *)((char *)(temp_a2) + 0xF)) = (s8) (temp_a1 + (*(u8 *)((char *)((temp_s4 + (temp_a1 * 8))) + 0x1FE)));
        temp_a0 = temp_s4 + (temp_a1 * 8);
        if ((*(u8 *)((char *)(temp_a0) + 0x1FC)) == 0) {
block_23:
            (*(s8 *)((char *)((*(void **)((char *)(arg0) + 0x68))) + 0xF)) = temp_a1;
            goto loop_13;
        }
        temp_a1_2 = (*(s8 *)((char *)((*(void **)((char *)(arg0) + 0x68))) + 0xF));
        if ((temp_a1_2) && ((func_80063D38(temp_s4, temp_a1_2, temp_a2) << 0x18) == 0)) {
            if ((*(u8 *)((char *)(temp_a0) + 0x1FE)) != 0) {
                if ((func_80063D38(temp_s4, temp_a1) << 0x18) != 0) {
                    (*(u8 *)((char *)(temp_a0) + 0x1FE)) = 0U;
                    (*(s8 *)((char *)((*(void **)((char *)(arg0) + 0x68))) + 0xF)) = temp_a1;
                    return;
                }
                goto block_23;
            }
            goto block_23;
        }
    case 3:
    case 5:
    case 6:
    case 7:
    case 9:
    case 10:
    case 11:
        return;
    }
}
