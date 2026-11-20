typedef struct { u8 pad[0x58]; u32 flags; } Record36B38;
extern Record36B38 *D_800E1718[];
extern u8 D_800E1758;
extern s32 D_800E1714;
void func_800090A4(Record36B38 *, s32, s32, s32);
void func_80036B38(s32 arg0) {
    u32 i;
    for (i = 0; i < D_800E1758; i++) {
        Record36B38 *p = D_800E1718[i];
        p->flags |= 4;
        func_800090A4(p, arg0, D_800E1714, 0);
    }
}
