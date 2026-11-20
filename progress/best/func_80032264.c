extern void *D_8010968C;
void func_80032264(void *arg0) {
    f32 temp_fv0, temp_fv0_2;
    s16 temp_v0_2, temp_v0_4, temp_v1;
    u8 temp_v0, temp_v0_3, var_v0;
    void *temp_a1;
    temp_v1 = *(s16 *)((s8 *)arg0 + 0x7A);
    temp_a1 = *(void **)((s8 *)arg0 + 0x6C);
    switch (temp_v1) {
    case 0:
        temp_fv0 = *(f32 *)((s8 *)arg0 + 0x40) + 3.0f;
        { f32 t = temp_fv0 * 0.0015339808f;
        *(f32 *)((s8 *)arg0 + 0x40) = temp_fv0;
        *(f32 *)((s8 *)D_8010968C + 0x38) = t; }
    case 1:
        temp_v0 = *(u8 *)((s8 *)temp_a1 + 2) - 1;
        *(u8 *)((s8 *)temp_a1 + 2) = temp_v0;
        if (!(temp_v0 & 0xFF)) {
            temp_v0_2 = *(s16 *)((s8 *)arg0 + 0x7A) + 1;
            *(s16 *)((s8 *)arg0 + 0x7A) = temp_v0_2;
            var_v0 = 0x78;
            if (temp_v0_2 == 1) var_v0 = 5;
            *(u8 *)((s8 *)temp_a1 + 2) = var_v0;
        }
        return;
    case 2:
        temp_fv0_2 = *(f32 *)((s8 *)arg0 + 0x40) + -3.0f;
        { f32 t = temp_fv0_2 * 0.0015339808f;
        *(f32 *)((s8 *)arg0 + 0x40) = temp_fv0_2;
        *(f32 *)((s8 *)D_8010968C + 0x38) = t; }
    case 3:
        temp_v0_3 = *(u8 *)((s8 *)temp_a1 + 2) - 1;
        *(u8 *)((s8 *)temp_a1 + 2) = temp_v0_3;
        if (!(temp_v0_3 & 0xFF)) {
            *(u8 *)((s8 *)temp_a1 + 2) = 0;
            temp_v0_4 = (*(s16 *)((s8 *)arg0 + 0x7A) + 1) & 3;
            *(s16 *)((s8 *)arg0 + 0x7A) = temp_v0_4;
            *(u8 *)((s8 *)temp_a1 + 2) = (temp_v0_4 != 3 ? 0x78 : 5);
        }
        break;
    }
}
