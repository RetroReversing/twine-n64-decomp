typedef struct { u8 pad[0x38]; s32 value; u8 pad3c[0x142]; s8 pending, mode; u8 pad180[2]; s8 index; } State698;
typedef struct { u8 pad[0x6c]; State698 *state; } Object698;
typedef struct { u8 enabled; u8 pad[0x9f]; } ModeEntry698;
extern ModeEntry698 D_8011508F[];
extern f32 func_800828D0(f32);
void func_800698D8(Object698 *object, f32 amount, s32 value) {
    State698 *state = object->state;
    s32 mode;
    s32 index;
    state->value = value;
    amount = func_800828D0(amount);
    mode = 0;
    if (amount <= 0.2f) {
        mode = 1;
    } else if (0.8f <= amount) {
        mode = 2;
    }
    if (mode != 0) {
        if (mode != state->mode) {
            index = state->index;
            state->mode = mode;
            if (D_8011508F[index].enabled != 0) {
                state->pending = 2;
            }
        }
    }
}

typedef struct { u8 pad[16]; u32 color, halfColor; } Colors6D;
typedef struct { u8 pad[0x414]; Colors6D *colors; } Inner6D;
typedef struct { u8 pad[0x6c]; Inner6D *inner; u32 unk70; f32 intensity; } Outer6D;
void func_8006D224(Outer6D *obj) {
    Colors6D *entry = obj->inner->colors;
    if (entry != 0) {
        Colors6D *colors = entry;
        f32 intensity = 2.55f * obj->intensity;
        u32 value = (u32)intensity;
        u32 red, blue, alpha;
        if (value >= 256U) value = 255U;
        alpha = 0xFF000000U;
        red = (value >> 1) << 16;
        blue = (255U - value) | 64U;
        value = red | alpha;
        alpha = 0x7F800000U;
        red >>= 1;
        value |= blue;
        blue >>= 1;
        colors->color = value;
        colors->halfColor = (red | alpha) | blue;
    }
}


f32 func_8009532C(f32 *v) {
    f32 x = v[0];
    f32 y = v[1];
    f32 z = v[2];
    f32 length = (f32)__builtin_sqrt(x*x + y*y + z*z);
    x /= length;
    y = v[1] / length;
    z = v[2] / length;
    v[0] = x;
    v[1] = y;
    v[2] = z;
    return length;
}

typedef struct { s32 value; u8 pad[36]; } AudioWord8EF;
typedef struct { u8 value; u8 pad[39]; } AudioByte8EF;
extern AudioWord8EF D_80107EDC[];
extern AudioWord8EF D_80107EE0[];
extern AudioByte8EF D_80107EE8[];
u32 func_8008EF18(s32 channel) {
    u32 index = channel & 0xff;
    u32 result = 0;
    if (D_80107EE8[index].value != 4) {
        if (D_80107EE0[index].value != 0) {
            result = D_80107EDC[index].value < 0;
        }
    }
    return result;
}
