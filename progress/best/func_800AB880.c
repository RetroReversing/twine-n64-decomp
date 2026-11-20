u8 *func_800AB880(u8 *arg0, u8 *arg1) {
    u32 temp_v1;
    u8 *var_a1 = arg1;
    u8 *var_a2 = arg0;
    if ((((u32)var_a1 - (u32)arg0) & 3) == 0) goto aligned;
    {
        u8 c = *var_a1++;
        *var_a2++ = c;
        while (c != 0) { c = *var_a1++; *var_a2++ = c; }
    }
    return arg0;
aligned:
    if (((s32)var_a2 & 3) != 0) {
        do { u8 c = *var_a1++; *var_a2++ = c; if (!c) return arg0; } while (1);
    }
    do {
        temp_v1 = *(u32 *)var_a1;
        var_a1 += 4;
        if (!(temp_v1 & 0xFF000000)) { *(u8 *)var_a2 = 0; return arg0; }
        if (!(temp_v1 & 0xFF0000)) { *(u16 *)var_a2 = (u16)(temp_v1 >> 16); return arg0; }
        if (temp_v1 & 0xFF00) { *(u32 *)var_a2 = temp_v1; var_a2 += 4; if (!(temp_v1 & 0xFF)) return arg0; }
        else { *(u16 *)var_a2 = (u16)(temp_v1 >> 16); *((u8 *)var_a2 + 2) = 0; return arg0; }
    } while (1);
}
