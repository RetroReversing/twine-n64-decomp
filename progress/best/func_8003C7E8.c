void func_8003C7E8(void *arg0, s32 arg1) {
    s32 temp_5C = *(s32 *)((char *)arg0 + 0x5C);
    s32 temp_58 = *(s32 *)((char *)arg0 + 0x58);
    s32 mask_58 = 0xFFFF0003;
    s32 mask_5C0 = 0x007FFFFF;
    s32 mask_5C1 = 0xFF81FFFF;
    f32 zero = 0.0f;
    temp_58 &= mask_58;
    temp_5C &= mask_5C0;
    temp_5C &= mask_5C1;
    *(s32 *)((char *)arg0 + 0) = 0;
    *(s32 *)((char *)arg0 + 4) = 0;
    *(s32 *)((char *)arg0 + 8) = 0;
    *(s32 *)((char *)arg0 + 0xC) = 0;
    *(s32 *)((char *)arg0 + 0x20) = 0;
    *(s32 *)((char *)arg0 + 0x10) = arg1;
    *(s32 *)((char *)arg0 + 0x14) = 0;
    *(s32 *)((char *)arg0 + 0x1C) = 0;
    *(s32 *)((char *)arg0 + 0x3C) = 0;
    *(f32 *)((char *)arg0 + 0x2C) = zero;
    *(f32 *)((char *)arg0 + 0x28) = zero;
    *(f32 *)((char *)arg0 + 0x24) = zero;
    *(f32 *)((char *)arg0 + 0x38) = zero;
    *(f32 *)((char *)arg0 + 0x34) = zero;
    *(f32 *)((char *)arg0 + 0x30) = zero;
    *(s32 *)((char *)arg0 + 0x58) = temp_58;
    *(s32 *)((char *)arg0 + 0x5C) = temp_5C;
}
