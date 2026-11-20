void func_800452AC(void *, void *, void *);
void func_800617D8(void *, void *, int, int, f32, f32, int, int, int, int, int);
extern f64 D_800D4138;
extern f64 D_800D4140;

void func_8005D238(void *arg0) {
    void *temp_s1;
    void *temp_v1;
    f32 temp_ft0;
    f32 temp_fv1;

    temp_s1 = *(void **)((char *)arg0 + 0x6C);
    temp_v1 = *(void **)((char *)arg0 + 0x20);
    *(unsigned short *)((char *)temp_s1 + 0x1C) = *(unsigned short *)((char *)temp_s1 + 0x1C) - 1;
    *(f32 *)((char *)arg0 + 0x54) = (f32)(*(f32 *)((char *)arg0 + 0x54) + D_800D4138);
    if (temp_v1 == 0) {
        *(int *)((char *)arg0 + 0x60) = *(int *)((char *)arg0 + 0x60) | 1;
        return;
    }
    temp_fv1 = *(f32 *)((char *)arg0 + 0x28);
    temp_ft0 = *(f32 *)((char *)*(void **)((char *)temp_v1 + 0x20) + 0x5C);
    if (temp_ft0 < temp_fv1) {
        *(f32 *)((char *)arg0 + 0x28) = temp_ft0;
        func_800617D8(*(void **)((char *)arg0 + 0x20), (char *)arg0 + 0x24, 0, 0, 0.25f, 1.05f, 0x1C, 0x1B, 0x2C, 0x40008080, 0x80808008);
        *(int *)((char *)arg0 + 0x60) = *(int *)((char *)arg0 + 0x60) | 1;
        return;
    }
    if (((short)*(unsigned short *)((char *)temp_s1 + 0x1C) <= 0) || (*(f32 *)((char *)*(void **)((char *)temp_v1 + 0x3C) + 0x24) < temp_fv1)) {
        *(int *)((char *)arg0 + 0x60) = *(int *)((char *)arg0 + 0x60) | 1;
        return;
    }
    func_800452AC((char *)temp_s1 + 4, (char *)arg0 + 0x24, (char *)arg0 + 0x24);
    {
        f32 t4;
        f32 t0;
        f32 t12;
        f32 t8;
        t4 = (f32)(*(f32 *)((char *)temp_s1 + 4) * D_800D4140);
        *(f32 *)((char *)temp_s1 + 4) = t4;
        t0 = *(f32 *)((char *)arg0 + 0x54) * 0.001f + 0.0012760417f;
        t12 = (f32)(*(f32 *)((char *)temp_s1 + 0xC) * D_800D4140);
        t8 = *(f32 *)((char *)temp_s1 + 8) + t0;
        *(f32 *)((char *)temp_s1 + 0xC) = t12;
        *(f32 *)((char *)temp_s1 + 8) = t8;
    }
    *(int *)((char *)arg0 + 0x58) = *(int *)((char *)arg0 + 0x58) | 1;
}
