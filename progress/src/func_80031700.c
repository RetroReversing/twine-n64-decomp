s32 func_800312F4(s16, u16);
s32 func_800313DC(s16, s32);
s32 func_800314E0(s16, s32);
void func_80031548(s32,s32,s32);
void func_800315E0(s16);
void func_80073AF8(s32,s32,s32,s32,s32,s32,s32,s32,s32,s32,s32);
void func_80074F04(void);
s32 func_80087100(s32);
extern s32 D_8010302C, gTrackMarkerTable;

void func_80031700(u32 arg0) {
    if (!arg0) return;
    if (arg0 < 10) {
        s16 n = arg0;
        s32 result, *table;
        if (func_800312F4(n,0)==3 || func_800312F4(n,0)==1) return;
        func_80031548(n,1,0);
        D_8010302C++;
        result = func_800313DC(n,0);
        table = &gTrackMarkerTable;
        func_80073AF8(0,*table,result,-1,-1,0,0,0,3,0,0);
        result = func_800314E0(n,0);
        func_80073AF8(0,*table,result,-1,-1,1,0,0,3,0,0);
    } else if (arg0 < 20) {
        s16 n;
        s32 result, *table;
        arg0 -= 10;
        n = arg0;
        if (func_800312F4(n,0)==3 || func_800312F4(n,0)==2) return;
        func_80074F04();
        func_80031548(n,2,0);
        D_8010302C++;
        result = func_800313DC(n,0);
        table = &gTrackMarkerTable;
        func_80073AF8(0,*table,result,-1,-1,0,0,0,3,0,0);
        result = func_800314E0(n,0);
        func_80073AF8(0,*table,result,-1,-1,1,0,0,3,0,0);
    } else {
        s16 n;
        s32 result, *table;
        arg0 -= 20;
        n = arg0;
        func_800315E0(n);
        D_8010302C++;
        result = func_80087100(0xA3);
        table = &gTrackMarkerTable;
        func_80073AF8(0,*table,result,-1,-1,0,0,0,3,0,0);
        result = func_800314E0(n,0);
        func_80073AF8(0,*table,result,-1,-1,1,0,0,3,0,0);
    }
}
