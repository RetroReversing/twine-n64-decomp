#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((u8 *)(expr) + (offset)))
extern s16 D_800F38D4;
extern s32 *D_800F38DC;
extern s32 sLoadedSceneGroupCount;
extern s32 D_800F815C;
extern s32 func_800986EC(void *, void *);
extern s32 *func_800956E0(s16 *, s32 *, s32, s32, s32 (*)(void *, void *));
s32 func_8009852C(s16 arg0, u16 *arg1) {
    s32 ret;
    s16 *base;
    s32 *temp;
    s32 length = sLoadedSceneGroupCount;
    base = &D_800F38D4;
    *base = arg0;
    temp = func_800956E0(base - 2, &D_800F815C, length, 0xC, func_800986EC);
    D_800F38DC = temp;
    if (temp == NULL) {
        ret = 0;
    } else {
        *arg1 = M2C_FIELD(temp, u16 *, 6);
        ret = *D_800F38DC;
    }
    return ret;
}

extern s8 D_800CEEB0;
extern s32 D_80102CC8, D_80102CCC, gDemoFrame;
extern u16 D_8010D430, D_8010D432, D_8010D434;
extern vu16 D_8010D436;

typedef struct {
    u16 field_0, field_2, field_4, field_6;
    s32 field_8, field_C;
} CaptureRecord;
extern CaptureRecord *gDemoInputData;

void func_80087A80(void) {
    s32 index = gDemoFrame;
    CaptureRecord *base = gDemoInputData;
    u16 field_0 = D_8010D430;
    s32 field_8 = D_80102CC8;
    s32 field_C = D_80102CCC;
    u16 field_6;
    CaptureRecord *record = (CaptureRecord *)((index * 16) + (u32)base);

    *(volatile u16 *)&record->field_0 = field_0;
    *(volatile u16 *)&record->field_2 = D_8010D432;
    *(volatile u16 *)&record->field_4 = D_8010D434;
    field_6 = D_8010D436;
    gDemoFrame = ++index;
    *(volatile s32 *)&record->field_8 = field_8;
    *(volatile s32 *)&record->field_C = field_C;
    record->field_6 = field_6;
    if (index >= 0x384) {
        D_800CEEB0 = 0;
    }
}

typedef struct { u8 pad[9]; u8 w; u8 pad2[2]; } E2A;
typedef struct { E2A *e; u8 pad[0x14]; u8 x18; u8 x19; u8 x1A; u8 x1B; u8 x1C; u8 x1D; u8 x1E; } T2A;

s32 func_8002AB6C(T2A *t) {
    u8 start, end;
    s16 i;
    s16 sum;
    s32 r;

    if (t == NULL) {
        return 0;
    }
    start = t->x18;
    end = t->x19;
    if (start == end - 1) {
        return 1;
    }
    sum = 0;
    for (i = start; i < end; i++) {
        sum += t->e[i].w;
    }
    r = 0;
    if (t->x1E == 0) {
        r = sum <= t->x1B;
    }
    return r;
}

u64 func_800ABAE8(u64 numerator, u64 denominator);
u64 func_800ABBE4(u64 numerator, u64 denominator);

u64 func_800ABE20(u64 numerator, u64 denominator) {
    if ((u32)(denominator >> 32) == 0) {
        return func_800ABBE4(numerator, denominator);
    }
    return func_800ABAE8(numerator, denominator);
}
