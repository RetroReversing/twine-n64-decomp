extern s32 D_800CE800; extern s32 *D_800CE804; extern s32 *D_800CE808; extern s32 *D_800CE80C; extern s32 *D_800CE810; extern s32 *D_800CE814; extern s32 *D_800CE818; extern s32 *D_800CE81C; extern s32 *D_800CE820; extern s32 *D_800CE824; extern s32 *D_800CE828; extern s32 *D_800CE82C; extern char D_8010A960[];
void *lookupDataEntry(s32 arg0) {
 u16 idx=arg0&0xfff;
 s32 group=arg0&0xf000;
 switch(group) {
 case 0x0000: if(idx<0x2ea && D_800CE804) return (void*)(D_800CE800+D_800CE804[idx]); break;
 case 0x1000: if(idx<0x92 && D_800CE808) return (void*)(D_800CE800+D_800CE808[idx]); break;
 case 0x2000: if(idx<0x2c && D_800CE80C) return (void*)(D_800CE800+D_800CE80C[idx]); break;
 case 0x3000: if(idx<0x25 && D_800CE810) return (void*)(D_800CE800+D_800CE810[idx]); break;
 case 0x4000: if(idx<0x23) return (void*)(idx*300+(u32)D_8010A960); break;
 case 0x6000: if(idx<0x38 && D_800CE814) return (void*)(D_800CE800+D_800CE814[idx]); break;
 case 0x7000: if(idx<0x1e && D_800CE81C) return (void*)(D_800CE800+D_800CE81C[idx]); break;
 case 0x8000: if(idx<0x17 && D_800CE820) return (void*)(D_800CE800+D_800CE820[idx]); break;
 case 0x9000: if(idx<0x21 && D_800CE824) return (void*)(D_800CE800+D_800CE824[idx]); break;
 case 0xA000: if(idx<0x38 && D_800CE818) return (void*)(D_800CE800+D_800CE818[idx]); break;
 case 0xB000: if(idx<0x6d && D_800CE828) return (void*)(D_800CE800+D_800CE828[idx]); break;
 case 0xC000: if(idx<0x78 && D_800CE82C) return (void*)(D_800CE800+D_800CE82C[idx]); break;
 }
 return lookupDataEntry(3);
}
