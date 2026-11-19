/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O1, tried by autopilot */

extern s32 D_801002E0;
extern char D_80100BE0[];
extern char D_80108608[];
extern char D_8010860C[];
extern char D_80108610[];
extern char D_80110B28[];
typedef struct { s32 f0; u8 pad[8]; } Slot_80110B2C;
extern Slot_80110B2C D_80110B2C[];
typedef struct { s32 f0; u8 pad[8]; } Slot_80110B30;
extern Slot_80110B30 D_80110B30[];

void func_80064264(void *arg0, void *arg1, s8 arg2) {
char *__repair_addr;

    s32 temp_v0;
    register u32 temp_v0_2;

    temp_v0 = D_801002E0 * 0xC;
__repair_addr = (char *)(D_80110B28 + temp_v0);

    D_80110B2C[D_801002E0].f0 = (*(s32 *)((char *)(arg0) + 4));
    *(s32 *)(__repair_addr) = (*(s32 *)((char *)(arg0) + 0));
    temp_v0_2 = D_801002E0 * 0xC;
    D_80110B30[D_801002E0].f0 = (*(s32 *)((char *)(arg0) + 8));
    *(s32 *)(D_80108608 + temp_v0_2) = (*(s32 *)((char *)(arg1) + 0));
    *(s32 *)(D_80108610 + temp_v0_2) = (*(s32 *)((char *)((unsigned)arg1) + 8));
    *(s32 *)(D_8010860C + temp_v0_2) = (*(s32 *)((char *)(arg1) + 4));
    *(D_80100BE0 + D_801002E0) = arg2;
    ++D_801002E0;
}
