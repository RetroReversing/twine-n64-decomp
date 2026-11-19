typedef struct { u8 pad[0x68]; } Pfs10690;
s32 osMotorInit(void *, Pfs10690 *, s32);
s32 __osMotorAccess(Pfs10690 *, s32);
extern Pfs10690 D_800E0790[];
extern u16 D_80109DC8[];
extern u16 D_8010A3A0[];
extern u8 D_8010D298[];

void func_80010690(s32 arg0) {
    s32 i;

    if (osMotorInit(D_8010D298, &D_800E0790[(u16)arg0], (u16)arg0) == 0) {
        for (i = 0; i < 3; i++) {
            __osMotorAccess(&D_800E0790[(u16)arg0], 0);
        }
        D_8010A3A0[(u16)arg0] &= 0xFFFC;
    } else {
        D_80109DC8[(u16)arg0] = 0;
    }
}
