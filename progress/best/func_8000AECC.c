/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

extern unsigned char D_800DD7A4;
extern unsigned char D_800DD7A5;
s32 func_800A2030();
s32 func_800A2270();
s32 osCreateMesgQueue();
s32 osRecvMesg();
s32 osSendMesg();
s32 osSetEventMesg();
s32 osSpTaskStartGo();
u32 osSpTaskYielded();
extern s8 D_800DD790;
extern s32 D_800DD798;
extern s32 D_800DD79C;
extern s32 D_800DD7A0;
extern u8 D_800E0710;
extern char D_8010090C[];
extern char D_80109C00[];
extern char D_8010A3A8[];
extern char D_8010A4AC[];
extern char D_8010A938[];
extern char D_80112E60[];
extern u8 D_80112FD0;

void func_8000AECC(void) {
    void *sp10;
    s32 temp_a0;
    s32 temp_a0_2;
    unsigned long temp_v0;
    u8 temp_v1;

    D_800DD790 = 0x81;
    osCreateMesgQueue(D_80109C00, D_80112E60, 8);
    osSetEventMesg(4, D_80109C00, &D_800DD790);
    osCreateMesgQueue(D_8010A3A8, D_8010A4AC);
    osCreateMesgQueue(D_8010A938, D_8010090C, 1);
    D_800DD798 = 0;
    D_800DD7A4 = 0U;
    D_800DD79C = 0;
    D_800E0710 = 0;
loop_1:
    D_80112FD0 = 0;
loop_2:
    osRecvMesg(D_80109C00, &sp10, 1);
    temp_v1 = (*(u8 *)((char *)(sp10) + 0));
    if (temp_v1 == 2) {
        if (D_800E0710 == 0) {
            register D_800E0710 = 1;
            if (D_80112FD0 == 0) {
                D_800DD7A5 = 1U;
                D_80112FD0 = 1;
                func_800A2030((*(s32 *)((char *)(sp10) + 4)));
                osSpTaskStartGo((*(s32 *)((char *)(sp10) + 4)));
            } else {
                func_800A2270(sp10);
                D_800DD79C = (*(s32 *)((char *)(sp10) + 4));
            }
        }
        goto loop_2;
    }
    if (temp_v1 < 3) {
        if (temp_v1 != 1) {

        } else if ((!D_80112FD0) && (D_800E0710 == 0)) {
            temp_a0 = (*(s32 *)((char *)(sp10) + 4));
            D_800DD7A4 = 1U;
            D_80112FD0 = 1;
            D_800DD7A0 = temp_a0;
            func_800A2030(temp_a0);
            osSpTaskStartGo(D_800DD7A0);
        } else {
            D_800DD798 = (*(s32 *)((char *)(sp10) + 4));
        }
        goto loop_2;
    }
    if (temp_v1 != 0x81) {
        goto loop_2;
    }
    if (D_800DD79C != 0) {
        do {
            temp_v0 = osSpTaskYielded(D_800DD7A0);
        } while (temp_v0 >= 2U);
        func_800A2030(D_800DD79C);
        osSpTaskStartGo(D_800DD79C);
        D_800DD79C = 0;
        if (temp_v0 == 0) {
            D_800DD7A5 = 0U;
        } else {
            D_800DD7A5 = 2U;
        }
        goto loop_2;
    }
    if (D_800DD7A5 == 2) {
        D_800E0710 = 0;
        osSendMesg(D_8010A938, 0, 1);
        func_800A2030(D_800DD7A0);
        osSpTaskStartGo(D_800DD7A0);
        D_800DD7A5 = 0U;
        goto loop_2;
    }
    if (D_800DD7A5 == 0) {
        if (D_800DD7A4 != 0) {
            D_800DD7A4 = 0U;
            osSendMesg(D_8010A3A8, 0, 0);
        }
        if (D_800E0710 != 0) {
            D_800E0710 = 0;
            osSendMesg(D_8010A938, 0, 0);
        }
    } else {
        D_800E0710 = 0;
        osSendMesg(D_8010A938, 0, 0);
        D_800DD7A5 = 0U;
    }
    temp_a0_2 = D_800DD798;
    if (temp_a0_2 == 0) {
        goto loop_1;
    }
    D_800DD7A0 = temp_a0_2;
    D_800DD798 = 0;
    func_800A2030(temp_a0_2);
    osSpTaskStartGo(D_800DD7A0);
    D_800DD7A4 = 1U;
    goto loop_2;
}
