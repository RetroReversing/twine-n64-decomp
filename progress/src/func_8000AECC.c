/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */
#ifndef M2C_DEFINES
#define M2C_DEFINES
typedef s32 M2C_UNK;
typedef s8 M2C_UNK8;
typedef s16 M2C_UNK16;
typedef s32 M2C_UNK32;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define M2C_CARRY 0
#define M2C_OVERFLOW(a) (0)
#endif

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
extern u8 D_800DD790[];
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

typedef struct { unsigned char field_0; unsigned char pad_1[3]; int field_4; } __repair_record_sp10;
void func_8000AECC(void) {
    s8 *__base_D_800DD790;
    void *sp10;
    s32 temp_a0;
    s32 temp_a0_2;
    u32 temp_v0;
    s32 temp_v1;

    __base_D_800DD790 = D_800DD790;
    (*D_800DD790) = 0x81;
    osCreateMesgQueue(D_80109C00, D_80112E60, 8);
    osSetEventMesg(4, D_80109C00, __base_D_800DD790);
    osCreateMesgQueue(D_8010A3A8, D_8010A4AC, 1);
    osCreateMesgQueue(D_8010A938, D_8010090C, 1);
    D_800DD798 = 0;
    D_800DD7A4 = 0U;
    D_800DD79C = 0;
    D_800E0710 = 0;
loop_1:
    D_80112FD0 = 0;
    for (;;) {
        osRecvMesg(D_80109C00, &sp10, 1);
        temp_v1 = ((__repair_record_sp10*)sp10)->field_0;
        switch (temp_v1) {
        case 1:
            if ((D_80112FD0 == 0) && (D_800E0710 == 0)) {
                temp_a0 = ((__repair_record_sp10*)sp10)->field_4;
                D_800DD7A4 = 1U;
                D_80112FD0 = 1;
                D_800DD7A0 = temp_a0;
                func_800A2030(temp_a0);
                osSpTaskStartGo(D_800DD7A0);
            } else {
                D_800DD798 = ((__repair_record_sp10*)sp10)->field_4;
            }
            continue;
        case 2:
            if (D_800E0710 == 0) {
                D_800E0710 = 1;
                if (D_80112FD0 != 0) {
                    func_800A2270(sp10);
                    D_800DD79C = ((__repair_record_sp10*)sp10)->field_4;
                } else {
                    D_800DD7A5 = 1U;
                    D_80112FD0 = 1;
                    func_800A2030(((__repair_record_sp10*)sp10)->field_4);
                    osSpTaskStartGo(((__repair_record_sp10*)sp10)->field_4);
                }
            }
            continue;
        case 0x81:
            break;
        default:
            continue;
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
            continue;
        }
        if (D_800DD7A5 == 2) {
            D_800E0710 = 0;
            osSendMesg(D_8010A938, 0, 1);
            func_800A2030(D_800DD7A0);
            osSpTaskStartGo(D_800DD7A0);
            D_800DD7A5 = 0U;
            continue;
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
            D_80112FD0 = 0;
            continue;
        }
        D_800DD7A0 = temp_a0_2;
        D_800DD798 = 0;
        func_800A2030(temp_a0_2);
        osSpTaskStartGo(D_800DD7A0);
        D_800DD7A4 = 1U;
        continue;
        break;
    }
}
