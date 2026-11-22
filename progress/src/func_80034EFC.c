typedef s32 M2C_UNK;
s32 osVirtualToPhysical(s32);
extern s32 D_80100304[];
extern s16 D_80108F80;
extern s16 D_8010A4B0;
extern s32 D_8010A4E8;
extern s32 D_8010A4EC[];
extern s16 D_8010D6F8;
extern void *D_80115328;

typedef struct { int field_0; int field_4; int field_8; int field_C; int field_10; int field_14; int field_18; int field_1C; } __repair_record_temp_s0;
void func_80034EFC(void) {
    s32 temp_s1;
    s32 temp_s2;
    s32 var_a2;
    void *temp_a1;
    void *temp_s0;
    s32 phys;

    temp_s0 = D_80115328;
    D_80115328 = temp_s0 + 8;
    ((__repair_record_temp_s0*)temp_s0)->field_0 = 0xE7000000;
    D_80115328 = temp_s0 + 0x10;
    ((__repair_record_temp_s0*)temp_s0)->field_C = 0x300000;
    ((__repair_record_temp_s0*)temp_s0)->field_8 = 0xE3000A01;
    D_80115328 = temp_s0 + 0x18;
    ((__repair_record_temp_s0*)temp_s0)->field_4 = 0;
    ((__repair_record_temp_s0*)temp_s0)->field_10 = 0xE200001C;
    ((__repair_record_temp_s0*)temp_s0)->field_14 = 0x0F0A4000;
    temp_s1 = D_8010D6F8 - 1;
    temp_s2 = D_80108F80 - 1;
    var_a2 = 2;
    if (D_8010A4EC[0] != 0) {
        var_a2 = (-(D_8010A4E8 == 0) & 3) | 2;
    }
    ((__repair_record_temp_s0*)temp_s0)->field_18 = 0xFF000000 | (var_a2 << 0x13) | (temp_s1 & 0xFFF);
    D_80115328 = temp_s0 + 0x20;
    phys = osVirtualToPhysical(D_80100304[D_8010A4B0]);
    temp_a1 = D_80115328;
    ((__repair_record_temp_s0*)temp_s0)->field_1C = phys;
    D_80115328 = temp_a1 + 8;
    *(s32 *)((char *)temp_a1 + 0) = 0xF7000000;
    D_80115328 = temp_a1 + 0x10;
    *(s32 *)((char *)temp_a1 + 4) = 0;
    *(s32 *)((char *)temp_a1 + 8) = 0xF6000000 | (temp_s1 & 0x3FF) << 0xE | (temp_s2 & 0x3FF) * 4;
    *(s32 *)((char *)temp_a1 + 0xC) = 0;
}
