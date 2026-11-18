/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

s32 func_800179E8();
s32 func_80031A84();
s32 func_800624A8();
s32 func_80084338();
extern u8 D_80109A60[];

void func_80031C70(void *arg0) {
    s16 temp_v0_3;
    s16 temp_v0_5;
    s16 temp_v0_4;
    s16 temp_v0_6;
    s16 temp_v1_3;
    int temp_v1;
    register u8 temp_v0;
    
    u8 temp_v0_7;
    u8 temp_v1_2;
    register u8 temp_v1_4;
    union { void * pointer; unsigned int value; } __repair_phase_storage;
    void *temp_s2;

    temp_v1 = (*(s32 *)((char *)(arg0) + 0x60));
    temp_s2 = (*(void **)((char *)(arg0) + 0x6C));
    __repair_phase_storage.pointer = arg0 + 0x24;
    if (temp_v1 & 2) {
        (*(s32 *)((char *)(arg0) + 0x60)) = (s32) (temp_v1 & ~2);
        do { func_800624A8(arg0, __repair_phase_storage.pointer, 0x3DCCCCCD, 1); } while (0);
        func_800179E8(__repair_phase_storage.pointer, (*(s32 *)((char *)(arg0) + 0x20)), 0x10000, 2);
        (*(s32 *)((char *)(arg0) + 0x60)) |= 1;
        temp_v0 = (*(u8 *)((char *)(temp_s2) + 4));
        if (temp_v0 != 0) {
            if ((*(u8 *)((char *)(temp_s2) + 5)) == *(D_80109A60 + temp_v0)) {
                temp_v1_2 = (*(u8 *)((char *)(temp_s2) + 6));
                if (temp_v1_2 != 0) {
                    *(D_80109A60 + temp_v1_2) = 1;
                }
            }
            goto block_5;
        }
        goto block_7;
    }
block_5:
    __repair_phase_storage.value = (u8)( (*(u8 *)((char *)(temp_s2) + 4)));
    if ((((u8)__repair_phase_storage.value) == 0) || ((*(u8 *)((char *)(temp_s2) + 5)) == *(D_80109A60 + ((u8)__repair_phase_storage.value)))) {
block_7:
        temp_v1_3 = (*(s16 *)((char *)(arg0) + 0x7A));
        switch (temp_v1_3) {                        /* irregular */
        case 0:
            if ((*(u16 *)((char *)(temp_s2) + 0)) == 0) {
                (*(f32 *)((char *)(arg0) + 0x40)) += 9.0f;
            case 1:
                if ((*(u16 *)((char *)(temp_s2) + 0)) == 0) {
                    (*(u8 *)((char *)(temp_s2) + 2)) -= 1;
                }
            }
            if ((*(u8 *)((char *)(temp_s2) + 2)) == 0) {
                temp_v0_3 = (u16) (*(s16 *)((char *)(arg0) + 0x7A)) + 1;
                (*(s16 *)((char *)(arg0) + 0x7A)) = temp_v0_3;
                if (temp_v0_3 != 1) {
block_32:
                    (*(u8 *)((char *)(temp_s2) + 2)) = 0x50U;
                } else {
block_30:
                    (*(u8 *)((char *)(temp_s2) + 2)) = 0xAU;
                    func_80084338(0x10F, arg0 + 0x24);
                }
            }
block_33:
            func_80031A84(arg0);
            break;
        case 2:
            if ((*(u16 *)((char *)(temp_s2) + 0)) == 0) {
                (*(f32 *)((char *)(arg0) + 0x40)) += -9.0f;
            case 3:
                if ((*(u16 *)((char *)(temp_s2) + 0)) == 0) {
                    (*(u8 *)((char *)(temp_s2) + 2)) -= 1;
                }
            }
            if ((*(u8 *)((char *)(temp_s2) + 2)) == 0) {
                (*(u8 *)((char *)(temp_s2) + 2)) = 0U;
                temp_v0_4 = ((u16) (*(s16 *)((char *)(arg0) + 0x7A)) + 1) & 3;
                (*(s16 *)((char *)(arg0) + 0x7A)) = temp_v0_4;
                if (temp_v0_4 == 3) {
                    goto block_30;
                }
                goto block_32;
            }
            goto block_33;
        }
        temp_v0_5 = (*(s16 *)((char *)(arg0) + 0x7C));
        if (0 < temp_v0_5) {
            temp_v0_6 = temp_v0_5 + 1;
            if ((*(u16 *)((char *)(arg0) + 0x78)) == 0x1B) {
                (*(s16 *)((char *)((unsigned short)arg0) + 0x7C)) = temp_v0_6;
                if (0x385 <= (s32)temp_v0_6) {
                    (*(s16 *)((char *)((unsigned)arg0) + 0x7C)) = 0;
                }
            }
            temp_v1_4 = (*(u8 *)((char *)(temp_s2) + 3));
            if (temp_v1_4) {
                *(D_80109A60 + temp_v1_4) = 1;
            }
        } else {
            goto block_40;
        }
    } else {
block_40:
        temp_v0_7 = (*(u8 *)((char *)(temp_s2) + 3));
        if (temp_v0_7 != 0) {
            *(D_80109A60 + temp_v0_7) = 0;
        }
    }
}
