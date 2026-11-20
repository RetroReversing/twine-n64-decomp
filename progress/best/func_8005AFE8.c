/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

void *func_80016410();
s32 actorLinkToSurface();
s32 func_80044670();
s32 func_80076340();
extern u8 D_800B1FE0[];
extern u8 D_800B2230[];
extern s32 *gProbeObjectList;

typedef struct { unsigned char pad[76]; int value; } __repair_field_4C;
void *func_8005AFE8(void *arg0, void *arg1, s32 arg2) {
    void *temp_s0;
    void *temp_v0;
    register void *temp_v0_3;
    register void *temp_v0_2;

    temp_v0 = func_80016410(0x34, 0, 0);
    if (temp_v0 != NULL) {
        temp_s0 = (*(void **)((char *)(temp_v0) + 0x6C));
        (*(s8 *)((char *)(temp_s0) + 0x30)) = (s8) (*(u16 *)((char *)(arg0) + 0x2C));
        (*(s8 *)((char *)(temp_s0) + 0x31)) = (s8) (*(u16 *)((char *)(arg0) + 0x38));
        do {
        if ((*(u16 *)((char *)(arg0) + 4)) == 0) {
            (*(volatile u16 *)((char *)(arg0) + 4)) = 0xF0U;
        }
        } while (0);
        do {
        (*(void **)((char *)(temp_s0) + 0x1C)) = arg1;
        (*(s16 *)((char *)(temp_s0) + 0x28)) = arg2;
        } while (0);
        (*(f32 *)((char *)(temp_s0) + 0x2C)) = (f32) (1.0f / (f32) (*(volatile u16 *)((char *)(arg0) + 4)));
        (*(f32 *)((char *)(temp_s0) + 0x24)) = 0.01f; (*(s16 *)((char *)(temp_s0) + 0x2A)) = 0;
        (*(s32 *)((char *)(temp_s0) + 0x20)) = 0;
        (*(s8 *)((char *)(temp_s0) + 0x32)) = (s8) (*(u16 *)((char *)(arg0) + 0x2E));
        (*(u8 *)((char *)(temp_s0) + 0x19)) = 0xFF;
        (*(s8 *)((char *)(temp_s0) + 0x18)) = 0;
        (*(s8 *)((char *)(temp_s0) + 0x33)) = (s8) (*(u16 *)((char *)(arg0) + 0x32));
        (*(s8 *)((char *)(temp_s0) + 0x1A)) = 1;
        (*(s8 *)((char *)(temp_s0) + 0x16)) = 0;
        (*(s8 *)((char *)(temp_s0) + 0x17)) = 0;
        (*(u16 *)((char *)(temp_s0) + 0x14)) = (u16) (*(u16 *)((char *)(arg0) + 0x30));
        (*(f32 *)((char *)(temp_s0) + 0xC)) = (f32) *(D_800B1FE0 + (*(u16 *)((char *)(arg0) + 0x30)));
        (*(f32 *)((char *)(temp_s0) + 8)) = 1000.0f;
        (*(s32 *)((char *)(temp_s0) + 0)) = -1;
        (*(f32 *)((char *)(temp_s0) + 4)) = 1000.0f;
        (*(f32 *)((char *)(temp_s0) + 0x10)) = (f32) *(D_800B2230 + (*(u16 *)((char *)(arg0) + 0x30)));
        func_80076340(temp_s0 + 0x1C, 0);
        (*(s16 *)((char *)(temp_v0) + 0x78)) = 0x3F;
        (*(s16 *)((char *)(temp_v0) + 0x7A)) = 0;
        (*(s16 *)((char *)(temp_v0) + 0x7C)) = 0;
        func_80044670(temp_v0, (*(u16 *)((char *)(arg0) + 0)), *(*(s16 **)((char *)(arg0) + 0x28)));
        temp_v0_2 = (*(void **)((char *)(temp_s0) + 0x1C));
        { typedef struct { s32 x, y, z; } Vec;
          *(Vec *)((char *)temp_v0 + 0x30) = *(Vec *)temp_v0_2;
          *(Vec *)((char *)temp_v0 + 0x24) = *(Vec *)((char *)temp_v0 + 0x30);
        }
        temp_v0_3 = (*(void **)((char *)(temp_s0) + 0x1C));
        { typedef struct { s32 x, y, z; } Vec;
          *(Vec *)((char *)temp_v0 + 0x48) = *(Vec *)((char *)temp_v0_3 + 0xC);
          *(Vec *)((char *)temp_v0 + 0x3C) = *(Vec *)((char *)temp_v0 + 0x48);
        }
        (*(s32 *)((char *)(temp_v0) + 0x5C)) |= 0x600;
        (*(s32 *)((char *)(temp_v0) + 0x58)) |= 0x20000;
        actorLinkToSurface(*gProbeObjectList, temp_v0, 0);
    }
    return temp_v0;
}
