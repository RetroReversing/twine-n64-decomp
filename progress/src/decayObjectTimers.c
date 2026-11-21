/* Decays the timer bytes of an object's timer records by 0x10 (saturating at zero). Returns 1 when the record at +0x2C had no timer left. */
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

s32 decayObjectTimers(void *obj) {
    s32 timerWord;
    s32 timerWord2;
    s32 timerWord3;
    s32 timerWord4;

    s32 temp_v0_3;
    s32 temp_v0_4;
    s32 temp_v0_5;
    s32 temp_v0_6;
    s32 temp_v0_7;
    s32 lowByte;

    s32 lowByteDec;
    s32 temp_v1_6;
    s32 temp_v1_7;
    s32 var_a0;
    s32 var_a1;
    s32 var_t0;
    s32 var_v0;
    s32 var_v0_2;

    s32 var_v0_4;
    u8 temp_v1_5;
    u8 var_v1;
    void *temp_a0_5;
    void *temp_a1;
    void *temp_a1_2;
    void *temp_v0;
    void *temp_v1_8;

    temp_v0 = M2C_FIELD(obj, void **, 0x2C);
    timerWord = M2C_FIELD(temp_v0, s32 *, 0x10);
    lowByte = timerWord & 0xFF;
    var_t0 = 1;

    if (lowByte != 0) {
        var_t0 = 0;
        temp_a1 = temp_v0;
        timerWord &= ~0xFF;
        lowByte -= 0x10;
        if (lowByte >= 0) {
            if (lowByte < 0x100) {
                var_v0 = timerWord | lowByte;
            } else {
                var_v0 = timerWord | 0xFF;
            }
        } else {
            var_v0 = timerWord;
        }
        M2C_FIELD(temp_a1, s32 *, 0x10) = var_v0;
        temp_a1 = M2C_FIELD(obj, void **, 0x3C);
        {
        s32 raw = M2C_FIELD(temp_a1, s32 *, 0x10);
        timerWord = raw & ~0xFF;
        lowByte = (raw & 0xFF) - 0x10;
        }
        if (lowByte >= 0) {
            if (lowByte < 0x100) {
                var_v0 = timerWord | lowByte;
            } else {
                var_v0 = timerWord | 0xFF;
            }
        } else {
            var_v0 = timerWord;
        }
        M2C_FIELD(temp_a1, s32 *, 0x10) = var_v0;
        temp_a1 = M2C_FIELD(obj, void **, 0);
        {
        s32 raw = M2C_FIELD(temp_a1, s32 *, 0x10);
        timerWord = raw & ~0xFF;
        lowByte = (raw & 0xFF) - 0x10;
        }
        if (lowByte >= 0) {
            if (lowByte < 0x100) {
                var_v0 = timerWord | lowByte;
            } else {
                var_v0 = timerWord | 0xFF;
            }
        } else {
            var_v0 = timerWord;
        }
        M2C_FIELD(temp_a1, s32 *, 0x10) = var_v0;
        temp_v1_5 = M2C_FIELD(M2C_FIELD(obj, void **, 0x30), u8 *, 0x7F);
        temp_v0_4 = temp_v1_5 - 0x10;
        if (temp_v0_4 >= 0) {
            var_v1 = temp_v1_5 - 0x10;
            if (temp_v0_4 >= 0x100) {
                var_v1 = 0xFF;
            }
        } else {
            var_v1 = 0;
        }
        M2C_FIELD(M2C_FIELD(obj, void **, 0x30), u8 *, 0x7F) = var_v1;
        M2C_FIELD(M2C_FIELD(obj, void **, 0x30), u8 *, 0x80) = var_v1;
        M2C_FIELD(M2C_FIELD(obj, void **, 0x30), u8 *, 0x81) = var_v1;
        temp_v1_6 = M2C_FIELD(M2C_FIELD(obj, void **, 0x34), s32 *, 0x10);
        lowByteDec = temp_v1_6 & 0xFF;
        temp_v0_5 = lowByteDec - 8;
        if (temp_v0_5 >= 0) {
            var_a1 = temp_v1_6 - 8;
            if (temp_v0_5 >= 0x31) {
                var_a1 = 0x30;
            }
        } else {
            var_a1 = 0;
        }
        temp_a0_5 = M2C_FIELD(obj, void **, 0x34);
        M2C_FIELD(temp_a0_5, s32 *, 0x10) = (s32) ((M2C_FIELD(temp_a0_5, s32 *, 0x10) & ~0xFF) | (var_a1 & 0xFF));
        temp_v1_7 = M2C_FIELD(M2C_FIELD(obj, void **, 4), s32 *, 0x10);
        temp_v0_6 = (temp_v1_7 & 0xFF) - 8;
        if (temp_v0_6 >= 0) {
            if (temp_v0_6 >= 0x31) {
                var_v0_4 = 0x30;
            } else {
                var_v0_4 = temp_v1_7 - 8;
            }
        } else {
            var_v0_4 = 0;
        }
        var_a0 = 0;
        do {
            temp_v1_8 = M2C_FIELD((((var_a0 & 0xFF) * 4) + obj), void **, 4);
            temp_v0_7 = M2C_FIELD(temp_v1_8, s32 *, 0x10);
            var_a0 += 1;
            M2C_FIELD(temp_v1_8, s32 *, 0x10) = (s32) ((temp_v0_7 & ~0xFF) | (var_v0_4 & 0xFF));
        } while ((u32) (var_a0 & 0xFF) < 9U);
    }
    return var_t0;
}
