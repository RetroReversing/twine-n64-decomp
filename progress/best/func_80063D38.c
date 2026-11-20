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

extern char D_800EE380[];
extern char D_800EE400[];

void func_800968A4(s32 arg0, s32 arg1, s8 arg2) {
    s32 temp_v1;

    temp_v1 = arg1 & 0xFF;
    if (temp_v1 != 0xFF) {
        temp_v1 *= 0x10;
        temp_v1 += (s32)D_800EE380;
        {
            register s32 column = (u8)arg0;
            *(char *)(temp_v1 + column) = arg2;
        }
        return;
    }
    *(D_800EE400 + (arg0 & 0xFF)) = arg2;
}

s32 func_80000A30(s32, s32);
void func_8007AABC(void *arg0, s32 arg1, f32 arg2) {
    f32 *field = (f32 *)((u8 *)arg0 + 0x40);
    register f32 term = func_80000A30((s32)*field, arg1) * arg2;
    f32 value = *(volatile f32 *)field;
    value = term + value;
    *field = value;
}

extern u8 D_800C471C[];
s32 func_80063CFC(s32, s16);
s32 func_80063D38(s32 state, s16 index) {
    s32 offset = index * 0xE8;
    s32 result;
    if (*(s16 *)(state + D_800C471C[offset] * 2 + 0x1BC) != 0
        || (s16)func_80063CFC(state, index) != 0) {
        result = 1;
    } else {
        result = D_800C471C[offset] == 0;
    }
    return result;
}

extern u8 D_800C471C[];
extern volatile s8 D_800C46A0[];
extern u8 D_800C469E[];
s16 func_80063C7C(s32 arg0) {
    register s32 index = (s16)arg0;
    s32 offset = index * 0xE8;
    s8 present = D_800C46A0[offset];
    s32 next = *(volatile u16 *)(D_800C469E + offset);
    if (present != 0) {
        s32 nextOffset = (s16)next * 0xE8;
        if (D_800C471C[offset] == D_800C471C[nextOffset]) {
            arg0 = next;
        }
    }
    return (s16)arg0;
}
