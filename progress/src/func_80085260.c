u32 func_8000A8B4(u16, f32, s32); s32 func_8000AABC(s32,s32,s32,s32); u32 func_80045CF8(s32); f32 func_80084270(s32,s16*);
extern u16 D_800CE74C[], D_800CE750[], D_800CE754[], D_800CE758[]; extern s32 gTrackMarkerTable[];
void func_80085260(s32 arg0,s32 arg1) { u16 sp10; u16 *p; s32 n; f32 x;
switch(arg1&255){default:p=D_800CE750;n=2;break;case 2:p=D_800CE754;n=2;break;case 3:case 5:case 7:p=D_800CE74C;n=1;break;case 4:case 8:p=D_800CE758;n=1;break;}
x=func_80084270(arg0,(s16*)&sp10); func_8000AABC(func_8000A8B4(p[func_80045CF8(n)],x,255),gTrackMarkerTable[sp10],arg0,0);}
