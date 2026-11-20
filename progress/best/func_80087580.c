/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

void *func_80016410();
s32 func_80044670();
s32 func_80076340(s32, s32, f32);
s32 func_80087380();
extern u8 D_800B21CF;
extern u8 D_800B241F;

typedef struct { int value; } __repair_field_0;
typedef struct { s32 x,y,z; } Vec3;
void *func_80087580(void *arg0, void *arg1, void *arg2, void *arg3, s32 arg4) {
    void *temp_s0;
    void *temp_v0;
    void *var_s2;
    s32 var_s4;
    void *temp_v0_2;
    void *temp_v0_3;
    void *temp_v0_4;

    temp_v0 = func_80016410(0x4C, 0, 0);
    if (temp_v0 != NULL) {
        temp_s0 = (*(void **)((char *)(temp_v0) + 0x6C));
        (*(s8 *)((char *)(temp_s0) + 0x44)) = (s8) (*(u16 *)((char *)(arg2) + 0x2C));
        (*(s8 *)((char *)(temp_s0) + 0x45)) = (s8) (*(u16 *)((char *)(arg2) + 0x2E));
        (*(s8 *)((char *)(temp_s0) + 0x46)) = (s8) (*(u16 *)((char *)(arg2) + 0x30));
        (*(s8 *)((char *)(temp_s0) + 0x47)) = (s8) (*(u16 *)((char *)(arg2) + 0x32));
        (*(s8 *)((char *)(temp_s0) + 0x48)) = (s8) (*(u16 *)((char *)(arg2) + 0x34));
        (*(s8 *)((char *)(temp_s0) + 0x49)) = (s8) (*(u16 *)((char *)(arg2) + 0x36));
        (*(s8 *)((char *)(temp_s0) + 0x4A)) = (s8) (*(u16 *)((char *)(arg2) + 0x38));
        (*(void **)((char *)(temp_s0) + 0x1C)) = arg3;
        (*(s8 *)((char *)(temp_s0) + 0x4B)) = (s8) (*(u16 *)((char *)(arg2) + 0x40));
        if (arg3 != NULL) {
            (*(s16 *)((char *)(temp_s0) + 0x28)) = (s16) arg4;
            (*(s16 *)((char *)(temp_s0) + 0x2A)) = 0;
            (*(s32 *)((char *)(temp_s0) + 0x20)) = 0;
            (*(f32 *)((char *)(temp_s0) + 0x24)) = 0.01f;
            func_80076340(temp_s0 + 0x1C, 1, 2.1f);
            temp_v0_2 = (*(void **)((char *)(temp_s0) + 0x1C));
            *(Vec3 *)(temp_v0 + 0x30) = *(Vec3 *)temp_v0_2;
            *(Vec3 *)(temp_v0 + 0x24) = *(Vec3 *)(temp_v0 + 0x30);
            *(Vec3 *)(temp_v0 + 0x48) = *(Vec3 *)(temp_v0_2 + 0xC);
        } else {
            *(Vec3 *)(temp_v0 + 0x30) = *(Vec3 *)arg0;
            *(Vec3 *)(temp_v0 + 0x24) = *(Vec3 *)(temp_v0 + 0x30);
            *(Vec3 *)(temp_v0 + 0x48) = *(Vec3 *)arg1;
        }
        *(Vec3 *)(temp_v0 + 0x3C) = *(Vec3 *)(temp_v0 + 0x48);
        (*(s16 *)((char *)(temp_v0) + 0x78)) = 0x3B;
        (*(s16 *)((char *)(temp_v0) + 0x7A)) = 0;
        var_s4 = 0;
        (*(s16 *)((char *)(temp_v0) + 0x7C)) = 0;
        var_s2 = temp_s0;
        func_80044670(temp_v0, (*(u16 *)((char *)(arg2) + 0)), *(*(s16 **)((char *)(arg2) + 0x28)));
        (*(s32 *)((char *)(temp_v0) + 0x5C)) |= 0x600;
        (*(s32 *)((char *)(temp_v0) + 0x58)) |= 0x20000;
        do {
            temp_v0_4 = func_80016410(0, 0, 0);
            (*(void **)((char *)(var_s2) + 0x2C)) = temp_v0_4;
            if (temp_v0_4 != NULL) {
                (*(void **)((char *)(temp_v0_4) + 0x18)) = temp_v0;
                (*(s16 *)((char *)(temp_v0_4) + 0x78)) = 0x30;
                (*(s32 *)((char *)(temp_v0_4) + 0x5C)) |= 0x600;
                func_80044670(temp_v0_4, 3U, *(*(s16 **)((char *)(arg2) + 0x28)));
            }
            var_s4 += 1;
            var_s2 += 4;
        } while (var_s4 < 6U);
        func_80087380(temp_v0);
        (*(s16 *)((char *)(temp_s0) + 0x14)) = 0x1EF;
        (*(u8 *)((char *)(temp_s0) + 0x19)) = 0xFF;
        (*(s8 *)((char *)(temp_s0) + 0x18)) = 0;
        (*(s8 *)((char *)(temp_s0) + 0x16)) = 0;
        (*(s8 *)((char *)(temp_s0) + 0x17)) = 0;
        (*(s8 *)((char *)(temp_s0) + 0x1A)) = 1;
        (*(f32 *)((char *)(temp_s0) + 0xC)) = (f32) D_800B21CF;
        ((__repair_field_0 *)temp_s0)->value = -1;
        (*(f32 *)((char *)(temp_s0) + 0x10)) = (f32) D_800B241F;
        (*(f32 *)((char *)(temp_s0) + 4)) = 1000.0f;
        (*(f32 *)((char *)(temp_s0) + 8)) = 1000.0f;
    }
    return temp_v0;
}

