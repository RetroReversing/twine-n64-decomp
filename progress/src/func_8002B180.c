typedef struct { s32 time; s16 pad4; s8 b6; } Rec2B180;
extern char D_800D2CF0[];
extern char D_800D2D00[];
s32 func_800A1B20(char *, const char *, ...);

void func_8002B180(Rec2B180 *arg0, char *arg1) {
    s32 t;

    if (arg1 != NULL) {
        if (arg0 != NULL) {
            t = arg0->time;
            if (t >= 60) {
                func_800A1B20(arg1, D_800D2CF0, (s16)(t / 60), (s16)((s16)t % 60), arg0->b6);
            } else {
                func_800A1B20(arg1, D_800D2D00, (s16)t, arg0->b6);
            }
        } else {
            *arg1 = 0;
        }
    }
}
