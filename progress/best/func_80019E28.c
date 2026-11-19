typedef struct { u8 b[8]; } Pk8;
extern u8 D_801002AD;
extern s32 D_801002B8;
extern s32 D_8010019C[];
extern u16 D_800BF688[];
extern Pk8 D_800D2914;
extern char D_800D290C[];
extern char D_800D291C[];
s32 func_8002BC28(s32);
u16 *func_80087100(u16);
void func_80026004(s32, char *, u16 *);
s32 sprintf(char *, char *, ...);

void func_80019E28(s32 arg0) {
    char sp10[32];
    Pk8 sp30;
    u16 *var_a2;
    u16 *temp_s1;
    s32 temp_a0;
    s32 temp_s0;
    u16 var_a0;

    if (D_801002AD < D_801002B8) {
        var_a0 = 0x15C;
        if (!(func_8002BC28(D_8010019C[D_801002AD * 6]) & 0xFF)) {
            var_a0 = 0x15B;
        }
        var_a2 = func_80087100(var_a0);
    } else {
        sp30 = D_800D2914;
        temp_a0 = D_8010019C[D_801002AD * 6];
        temp_s0 = D_800BF688[temp_a0 * 6] & 3;
        var_a0 = 0x15C;
        if (!(func_8002BC28(temp_a0) & 0xFF)) {
            var_a0 = 0x15B;
        }
        temp_s1 = func_80087100(var_a0);
        sprintf(sp10, D_800D291C, temp_s1, func_80087100(((u16 *)&sp30)[temp_s0]));
        var_a2 = (u16 *)sp10;
    }
    func_80026004(arg0, D_800D290C, var_a2);
}
