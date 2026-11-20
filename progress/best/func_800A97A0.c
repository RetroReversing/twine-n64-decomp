#define FIELD(p, T, off) (*(T *)((p) + (off)))
typedef struct {
    s32 value;
    u16 field4;
    u16 field6;
} LookupResult;

extern u16 D_800F38D4[];
extern LookupResult *D_800F38DC;
extern volatile s32 D_800F8158;
extern s32 D_800F815C;
extern s32 func_800986EC(void *, void *);
extern LookupResult *func_800956E0(void *, void *, s32, s32, s32 (*)(void *, void *));

s32 func_8009852C(u16 key, u16 *out) {
    s32 count;
    u16 *record;
    LookupResult *result;
    s32 value;

    s32 (*compare)(void *, void *) = func_800986EC;
    count = D_800F8158;
    record = D_800F38D4;
    *(volatile u16 *)record = key;
    result = func_800956E0(record - 2, &D_800F815C, count, 12, compare);
    D_800F38DC = result;
    if (result == NULL) {
        value = 0;
    } else {
        *out = result->field6;
        value = D_800F38DC->value;
    }
    return value;
}
u32 func_8009D94C(u8 *state, u32 step) {
    u32 ret;
    s32 remaining;
    u32 progress;
    u32 delta;

    if ((s8)state[0x11dd] != 3) return 0;
    {
        remaining = FIELD(state, s32, 0x11a8);
        if (remaining > 0) {
            remaining = (u32)remaining - step;
            FIELD(state, s32, 0x11a8) = remaining;
            if (remaining <= 0) {
                state[0x11dd] = 4;
                FIELD(state, s32, 0x11a8) = 0;
            }
        }
        progress = FIELD(state, u32, 0x11d4);
        delta = FIELD(state, u32, 0x11d8) - progress;
        if (step < delta) ret = step;
        else ret = delta;
        FIELD(state, u32, 0x11d4) = progress + ret;
    }
    return ret;
}

void func_800A97A0(f32 *out, u32 *in) {
    u32 *end = in + 8;
    f32 scale = 0.0000152587890625f;
    do {
        u32 a = in[0];
        u32 b = in[8];
        s32 x = (a & 0xFFFF0000u) | (b >> 16);
        s32 y = (a << 16) | (b & 0xFFFFu);
        f32 first = (f32)x * scale;
        f32 second = (f32)y * scale;
        out[0] = first;
        out[1] = second;
        in++;
        out += 2;
    } while (in != end);
}

extern u8 D_801007D9[];
extern u8 D_80100C7C[];
s32 func_80099AF0(void *arg0) {
    u8 *base;
    s32 temp_v1;
    u8 temp_a1;
    u8 temp_v0;
    s32 var_v0;
    register u8 var_v1;
    s32 sentinel = 255;
    temp_v1 = *(s32 *)((char *)arg0 + 0x60);
    if (temp_v1 != -1) {
        temp_a1 = *(u8 *)((char *)arg0 + 0x4A);
        if (temp_a1 != sentinel) {
            temp_v0 = *(u8 *)((char *)arg0 + 0x4B);
            if (temp_v0 == sentinel) {
                var_v1 = temp_v1 & 0xFF;
                var_v0 = D_80100C7C[var_v1];
            } else {
                base = D_801007D9;
                var_v0 = temp_v1 & 0xFF;
                var_v1 = *((base + temp_v0 * 0x10) + temp_a1);
            }
            if (var_v1 == var_v0) return 1;
            goto done;
        }
        return 0;
    }
done:
    return 0;
}
