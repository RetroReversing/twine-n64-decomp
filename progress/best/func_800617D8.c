/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

void *func_80016410();
s32 func_80016990();
s32 func_8003E6EC();
s32 func_80044670();
s32 func_80045278();
extern s32 *D_800CA31C;

typedef struct { int value; } __repair_field_0;
void *func_800617D8(s32 arg0, s32 arg1, s32 arg2, void *arg3, f32 arg4, f32 arg5, s32 arg6, s32 arg7, s32 arg8, u32 arg9, u32 arg10) {
    void *temp_s1;
    void *temp_v0;

    if (!arg0) {
        return NULL;
    }
    temp_v0 = func_80016410(0x2C);
    if (temp_v0 != NULL) {
        register temp_s1 = (*(void **)((char *)(temp_v0) + 0x6C));
        if (arg3 == NULL) {
            func_80045278(temp_s1);
        } else {
            (*(s32 *)((char *)(temp_s1) + 4)) = (s32) (*(s32 *)((char *)(arg3) + 4));
            ((__repair_field_0 *)temp_s1)->value = (s32) ((__repair_field_0 *)arg3)->value;
            (*(s32 *)((char *)(temp_s1) + 8)) = (s32) (*(s32 *)((char *)(arg3) + 8));
        }
        (*(s16 *)((char *)(temp_v0) + 0x78)) = (s16) arg8;
        (*(f32 *)((char *)(temp_v0) + 0x54)) = arg4;
        (*(f32 *)((char *)(temp_s1) + 0x14)) = arg5;
        (*(s8 *)((char *)(temp_v0) + 0x7F)) = (s8) (arg9 >> 0x18);
        (*(s8 *)((char *)(temp_v0) + 0x80)) = (s8) (arg9 >> 0x10);
        (*(s8 *)((char *)(temp_v0) + 0x81)) = (s8) (arg9 >> 8);
        (*(s8 *)((char *)(temp_v0) + 0x82)) = (s8) arg9;
        (*(s8 *)((char *)(temp_s1) + 0x23)) = (s8) ((arg10 >> 0x18) + 0x80);
        (*(s8 *)((char *)(temp_s1) + 0x24)) = (s8) ((arg10 >> 0x10) + 0x80);
        (*(s8 *)((char *)(temp_s1) + 0x25)) = (s8) ((arg10 >> 8) + 0x80);
        (*(s8 *)((char *)(temp_s1) + 0x26)) = (s8) arg10;
        func_80044670(temp_v0, arg6, arg7);
        if (arg0) {
            func_80016990(temp_v0, arg0);
            return temp_v0;
        }
        do { func_8003E6EC(*D_800CA31C, temp_v0, 1); } while (0);
        goto block_9;
    }
block_9:
    return temp_v0;
}
