typedef struct { s32 a, b, c; } V3;
void func_80045278(void *);
u32 randomU32Next(void);
void copyVec3Pair(s32, void *, void *, s32);
void func_80060890(void *, s32, u16, s32);
void actorRespawnAtRandomPoint(void *);
void func_800643D8(void *);
void *spawnEffectObject(s32, s32, s32);
extern u8 sOptionCursor;

void *func_8005F960(s32 arg0, s32 *arg1, s32 arg2, s32 arg3, u16 arg4, u16 arg5, u16 arg6, u16 arg7, u16 arg8, u16 arg9, u16 arg10, u16 arg11, u16 arg12, u16 arg13, s32 arg14, s32 arg15) {
    u16 sel;
    u32 r;
    u8 *obj;
    u8 *d;
    s16 v;

    switch (sOptionCursor) {
    case 0: sel = arg4; break;
    case 1: sel = arg5; break;
    case 2: sel = arg6; break;
    case 3: sel = arg7; break;
    case 4: sel = arg8; break;
    case 5: sel = arg9; break;
    case 6: sel = arg10; break;
    case 7: sel = arg11; break;
    case 8: sel = arg12; break;
    default: sel = arg13; break;
    }
    if (sel != 0x1000) {
        obj = spawnEffectObject(0x40, 0, 0);
        if (obj != NULL) {
            d = *(u8 **)(obj + 0x6C);
            if (arg1 != NULL) {
                *(V3 *)(obj + 0x3C) = *(V3 *)arg1;
            } else {
                func_80045278(obj + 0x3C);
            }
            *(u32 *)(d + 0x38) = ((*(u32 *)(d + 0x38) & 0xFFF0000F & 0xF) | ((arg2 & 0xFFFF) << 4) | (arg3 << 20));
            v = 2;
            switch (sel & 0xF000) {
            case 0x1000:
                *(s16 *)(d + 0x3C) = 0;
                break;
            case 0x3000:
                v = 1;
            case 0x2000:
                *(s16 *)(d + 0x3C) = v;
                break;
            }
            *(s16 *)(d + 0x3E) = sel & 0xFFF;
            func_80060890(d, arg14, arg15, arg0);
            actorRespawnAtRandomPoint(obj);
            r = randomU32Next();
            *(s32 *)d = 0x384 - (r % 90);
            copyVec3Pair(arg0, obj + 0x24, obj + 0x30, (r / 90) * 3);
            *(u32 *)(obj + 0x5C) |= 0x400;
            func_800643D8(obj);
            return obj;
        }
    }
    return NULL;
}
