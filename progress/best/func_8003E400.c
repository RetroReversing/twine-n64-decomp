struct triple { s32 x, y, z; };
s32 func_8003D64C(void *, void *);
s32 func_8004886C(void *, void *, f32);
s32 func_8004E6E4(void *, void *, void *, s32 *, void *, f32, s32, s32, s32);
extern s32 D_800D2FC8[];
extern s32 D_800D2FD4[];
extern u8 func_8004DBD8[];

void func_8003E400(void *arg0) {
    s32 sp28[3];
    s32 sp38[3];
    struct { void *p; f32 y; f32 z; f32 w; } sp;
#define sp48 sp.p
#define sp4C sp.y
    void *s0, *s1, *s2, *s3, *s4;
    f32 fs0, fs1, fv1;

    s4 = NULL;
    s1 = arg0;
    while (s1 != (int)NULL) {
        s2 = NULL;
        if (*(u16 *)((u8 *)s1 + 0x58) == 0x18) {
            fs1 = 65536.0f;
            s0 = arg0;
            fs0 = 65536.0f;
            if (s0 != NULL) {
                s3 = (u8 *)s1 + 0x40;
            do {
                if (*(u16 *)((u8 *)s0 + 0x58) == 0x46) {
                    fv1 = *(f32 *)((u8 *)s1 + 0x4C);
                    if (*(f32 *)((u8 *)s0 + 0x4C) >= fv1
                        && ((func_8004886C((u8 *)s0 + 0x40, s3, fv1) << 0x18) != 0)
                        && ((func_8003D64C(s3, s0) << 0x18) != 0)
                        && *(f32 *)((u8 *)s0 + 0x4C) >= *(f32 *)((u8 *)s1 + 0x4C)) {
                        *(struct triple *)sp28 = *(struct triple *)D_800D2FC8;
                        *(struct triple *)sp38 = *(struct triple *)D_800D2FD4;
                        if (*(f32 *)((u8 *)s0 + 0x4C) < fs1) {
                            s4 = s0;
                            fs1 = *(f32 *)((u8 *)s0 + 0x4C);
                        }
                        if ((func_8004E6E4(func_8004DBD8, s0, s3, (u32)sp38, &sp48, 256.0f, 0, 1, 0) << 24) != 0) {
                            fv1 = *(f32 *)((u8 *)s1 + 0x44) - sp4C;
                            if (fv1 < fs0) {
                                fs0 = fv1;
                                s2 = s0;
                            }
                        } else {
                            if ((func_8004E6E4((int)func_8004DBD8, s0, s3, sp28, &sp48, 256.0f, 0, 1, 0) << 24) != 0) {
                                fv1 = sp4C - *(f32 *)((u8 *)s1 + 0x44);
                                if (fv1 < fs0) {
                                    fs0 = fv1;
                                    s2 = s0;
                                }
                            }
                        }
                    }
                }
                s0 = *(void **)((u8 *)s0 + 0x10);
            } while (s0 != NULL);
            }
            if (s2 != (unsigned)NULL) {
                if ((*(u32 *)((u8 *)s1 + 0x58) >> 2) & 4) {
                    *(f32 *)(*(u8 **)((u8 *)s2 + 0x20) + 0x5C) = *(f32 *)((u8 *)s1 + 0x28);
                }
                *(void **)((u8 *)s1 + 0x18) = s2;
                *(void **)((u8 *)s1 + 0x14) = *(void **)((u8 *)s2 + 0x14);
                *(void **)((u8 *)s2 + 0x14) = s1;
            } else if (s4 != NULL) {
                if ((*(u32 *)((u8 *)s1 + 0x58) >> 2) & 4) {
                    *(f32 *)(*(u8 **)((u8 *)s4 + 0x20) + 0x5C) = *(f32 *)((u8 *)s1 + 0x28);
                }
                *(void **)((u8 *)s1 + 0x18) = s4;
                *(void **)((u8 *)s1 + 0x14) = *(void **)((u8 *)s4 + 0x14);
                *(void **)((u8 *)s4 + 0x14) = s1;
                s4 = NULL;
            }
        }
        s1 = *(void **)((u8 *)s1 + 0x10);
    }
}
