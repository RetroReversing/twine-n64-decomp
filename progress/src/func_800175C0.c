typedef struct { s32 x, y, z; } V3i;
f32 func_80045E34(void *, void *);

void func_800175C0(void **arg0, s32 arg1, s32 arg2, V3i *arg3, f32 arg4, s32 arg5) {
    void **first = arg0;
    void *o;
    void *n;
    void *p;
    s32 v;

    if (arg0 == NULL) {
        return;
    }
    n = *(void **)((char *)*(void **)((char *)arg0 + 0x20) + 0x58);
    do {
        for (o = *arg0; o != NULL; o = *(void **)o) {
            switch (*(u16 *)((char *)o + 0x78)) {
            case 1:
            case 2:
            case 3:
            case 0xB:
            case 0x24:
            case 0x3B:
            case 0x4C:
                if (arg4 == 0.0f || func_80045E34(arg3, (char *)o + 0x24) < arg4) {
                    u16 t = *(u16 *)((char *)o + 0x78);
                    if ((t == 1 || t == 0x4C) && !(*(s32 *)((char *)o + 0x60) & arg1)) {
                        s32 w = *(s32 *)((char *)o + 0x60) | arg2;
                        s32 r;
                        p = *(void **)((char *)o + 0x6C);
                        *(s32 *)((char *)o + 0x60) = w;
                        if (arg0 == first) {
                            r = w | 0x1000;
                        } else {
                            r = w | 0x2000;
                        }
                        *(s32 *)((char *)o + 0x60) = r;
                        *(V3i *)((char *)p + 0x50) = *arg3;
                    } else if ((u32)(*(u16 *)((char *)o + 0x78) - 2) < 2U) {
                        v = *(s32 *)((char *)o + 0x60);
                        if (!(v & arg1)) {
                            void *q = *(void **)((char *)o + 0x6C);
                            *(s32 *)((char *)o + 0x60) = v | arg2;
                            *(V3i *)((char *)q + 0x1A0) = *arg3;
                        }
                    } else if ((s8)arg5 == 0) {
                        *(s32 *)((char *)o + 0x60) |= arg2;
                    }
                }
                break;
            }
        }
        arg0 = NULL;
        if (n != NULL) {
            arg0 = *(void ***)((char *)n + 8);
            n = *(void **)n;
        }
    } while (arg0 != NULL);
}
