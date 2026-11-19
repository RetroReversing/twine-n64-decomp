typedef struct { u8 b[0x68]; } Ent8008C1B0;
extern Ent8008C1B0 *D_800E41DC;

s32 func_8008C1B0(s32 arg0) {
    return D_800E41DC[arg0].b[0] != 0;
}
