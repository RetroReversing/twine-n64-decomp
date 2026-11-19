/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

s32 func_80034560();
s32 func_80034928();
s32 func_80039068();
extern char D_800B1CD0[];
extern s32 D_801032A0;
extern void *D_80109CB8;
extern s32 D_8010A4D8;
extern s32 D_8010A924;
extern s32 D_80112E40;
extern void *D_80115328;
extern void *D_80117728;

typedef struct { int value; } __repair_field_0;
void func_80037C84(s32 arg0) {
    void *temp_a2;
    void *temp_v1;
    void *temp_v1_2;

    func_80034560();
    if (D_80112E40 != 2) {
        D_80112E40 = 2;
        do { func_80039068(arg0); } while (0);
    }
    if (D_8010A924 != 6) {
        temp_v1 = D_80115328;
        D_8010A924 = 6;
        D_80115328 = temp_v1 + 8;
        ((__repair_field_0 *)temp_v1)->value = (u32)0xDE000000;
        (*(s32 **)((char *)(temp_v1) + 4)) = D_800B1CD0;
    }
    if ((unsigned)D_801032A0 != 2) {
        temp_v1_2 = D_80115328;
        D_801032A0 = 2;
        D_80115328 = temp_v1_2 + 8;
        ((__repair_field_0 *)temp_v1_2)->value = 0xFC419883;
        (*(s32 *)((char *)(temp_v1_2) + 4)) = 0xFF32FF7F;
    }
    func_80034928(arg0, 2);
    (*(s32 *)((char *)(D_80109CB8) + 4)) = 0;
    ((__repair_field_0 *)D_80115328)->value = 0xDE000000;
    ((__repair_field_0 *)D_80109CB8)->value = 0xDF000000;
    (*(s32 *)((char *)(D_80115328) + 4)) = (s32) (*(s32 *)((char *)(D_80117728) + 0x1A60));
    D_80109CB8 += 8;
    temp_a2 = D_80115328 + 8;
    D_80115328 = temp_a2;
    func_80034928(arg0, D_8010A4D8, temp_a2);
}
