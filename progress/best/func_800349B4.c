extern void *sDisplayListCursor;
extern u8 D_801002E5;
extern u8 D_80100774;
extern u8 D_80100775;
extern u8 D_80100776;
extern u8 D_80100777;
extern u8 D_80100778;
extern u8 D_80100779;
extern u8 D_8010077A;
extern u8 D_8010077B;
extern u8 D_8010077C;
extern u8 D_801007CC;
extern u8 D_801007CD;
extern u8 D_801007CE;
extern u8 D_801007CF;
extern u8 D_801007D0;
extern u8 D_801007D1;
extern u8 D_801007D2;
extern u8 D_801007D3;
extern u8 D_801007D4;
extern u8 D_80102F38;
extern u8 D_801032A4;
extern u8 D_80108F74;
extern u8 D_801093A0;
extern u8 D_8010A3C4;
extern u8 D_8010A4B8;
extern s32 D_8010A4D8;
extern u8 D_80110CA8;
extern u8 D_80110DB1;


typedef struct { char pad[0x100]; s32 unk100; char pad2[0x3f]; u8 unk143, unk144, unk145, unk146; } Obj;
typedef struct { u32 unk0, unk4, unk8, unkC; } Cmd;
extern void func_80034928(s32, s32);
void func_800349B4(Obj *arg0) {
    int temp_v1;
    Cmd *temp_a3;
    s32 var_s2;
    u32 var_s3;
    int var_s1;
    Cmd *temp_a0;

    var_s1 = 0;
    var_s3 = 0;
    var_s2 = 0;
    if (arg0->unk100 & 1) {
        arg0->unk145 = 0U;
        arg0->unk144 = 0U;
        arg0->unk143 = 0U;
        arg0->unk146 = 0xFFU;
        func_80034928(arg0, D_8010A4D8);
    }
    if (arg0->unk100 & 4) {
        arg0->unk143 = (u8) D_801093A0;
        arg0->unk144 = (u8) D_801002E5;
        arg0->unk145 = (u8) (unsigned)D_80110CA8;
        arg0->unk146 = 0xFFU;
        func_80034928(arg0, D_8010A4D8);
    }
    if (arg0->unk100 & 2) {
        arg0->unk143 = (u8) D_8010A3C4;
        arg0->unk144 = (u8) D_8010A4B8;
        arg0->unk145 = (u8) D_80110DB1;
        arg0->unk146 = 0xFFU;
        func_80034928(arg0, 2);
    }
    temp_a3 = sDisplayListCursor;
    sDisplayListCursor = (void *)temp_a3 + 8;
    temp_a3->unk0 = 0xFB000000;
    temp_a3->unk4 = (s32) ((arg0->unk143 << 0x18) | (arg0->unk144 << 0x10) | (arg0->unk145 << 8) | arg0->unk146);
    temp_v1 = arg0->unk100;
    if (temp_v1 & 2) {
        var_s2 = 0;
        temp_a3->unk8 = 0xDB080000;
        var_s1 = (D_801007CF + D_801007D0 + D_801007D1) / 3;
        temp_a3->unkC = (s32) (((D_801007CD + 0x7530) << 0x10) | ((D_801007CE - 0x7530) & 0xFFFF));
        sDisplayListCursor = (void *)temp_a3 + 0x10;
    } else if (temp_v1 & 4) {
        var_s1 = 0;
        var_s2 = 0;
        temp_a3->unk8 = 0xDB080000;
        D_80108F74 = D_801007D3;
        temp_a3->unkC = (s32) (((D_801007CD << 0x10) + ((D_801007CC * 0x78) << 0x10)) | (((D_801007CC * -0x78) + D_801007CE) & 0xFFFF));
        sDisplayListCursor = (void *)temp_a3 + 0x10;
        D_80102F38 = D_801007D2;
        D_801032A4 = D_801007D4;
        var_s3 = 0x40;
    } else {
        if (temp_v1 & 1) {
            var_s2 = D_801007CF;
            var_s1 = D_801007D0;
            var_s3 = D_801007D1;
            temp_a3->unk8 = 0xDB080000;
            temp_a3->unkC = (s32) (((D_801007CD << 0x10) + ((D_801007CC * 0x78) << 0x10)) | (((D_801007CC * -0x78) + D_801007CE) & 0xFFFF));
            sDisplayListCursor = (void *)temp_a3 + 0x10;
            D_80102F38 = D_801007D2;
            D_801032A4 = D_801007D4;
            D_80108F74 = D_801007D3;
        }
        if (arg0->unk100 & 8) {
            var_s2 = D_80100777;
            var_s1 = D_80100778;
            ((Cmd *)sDisplayListCursor)->unk0 = 0xDB080000;
            var_s3 = D_80100779;
            ((Cmd *)sDisplayListCursor)->unk4 = (s32) (((D_80100775 + (D_80100774 * 0x78)) << 0x10) | (((D_80100774 * -0x78) + D_80100776) & 0xFFFF));
            sDisplayListCursor += 8;
            D_80102F38 = D_8010077A;
            D_80108F74 = D_8010077B;
            D_801032A4 = D_8010077C;
        }
    }
    temp_a0 = sDisplayListCursor;
    sDisplayListCursor = (void *)temp_a0 + 8;
    temp_a0->unk0 = 0xF8000000;
    temp_a0->unk4 = (s32) ((var_s2 << 0x18) | ((var_s1 & 0xFF) << 0x10) | ((var_s3 <<= 8)) | 0xFF);
}
