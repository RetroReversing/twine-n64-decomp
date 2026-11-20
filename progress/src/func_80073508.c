typedef struct { u8 pad0[0x120]; f32 f120; f32 f124; } Func80073508Obj;
extern Func80073508Obj *D_80109688[];
extern u8 D_8010A4C1;
f32 func_80045E34(s32, void *);

void func_80073508(s32 arg0, f32 arg1) {
    u32 i;
    u32 bit;
    f32 t;
    Func80073508Obj *obj;
    for (i = 0; i < 4; i++) {
        obj = D_80109688[i];
        if (obj != NULL) {
            t = (100.0f - func_80045E34(arg0, (u8 *)obj + 0x10));
            t = t * arg1;
            if (t > 0.0f) {
                D_80109688[i]->f120 = t;
            }
            bit = 1 << i;
            if (D_8010A4C1 & bit) {
                D_80109688[i]->f124 = D_80109688[i]->f124 + 2.0f * t;
            }
            if (D_80109688[i]->f124 > 1.0f) {
                D_80109688[i]->f124 = 1.0f;
            }
            if (D_80109688[i]->f124 < 0.0f) {
                D_80109688[i]->f124 = 0.0f;
            }
        }
    }
}
