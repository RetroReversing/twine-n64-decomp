extern s32 D_800CE800; extern s32 D_800CE804; extern s32 D_800CE808; extern s32 D_800CE80C; extern s32 D_800CE810; extern s32 D_800CE814; extern s32 D_800CE818; extern s32 D_800CE81C; extern s32 D_800CE820; extern s32 D_800CE824; extern s32 D_800CE828; extern s32 D_800CE82C; extern char D_8010A960[];
void *lookupDataEntry(s32 arg0,s32 arg1) {
 s32 group=(u32)arg0&0xf000;
 s32 *base;
 switch(group) {
 case 0x0000: if(((u32)arg0&0xffff)>=0x2ea) goto fail; base=(s32*)D_800CE804; goto tab;
 case 0x1000: if(((u32)arg0&0xffff)>=0x92) goto fail; base=(s32*)D_800CE808; goto tab;
 case 0x2000: if(((u32)arg0&0xffff)>=0x2c) goto fail; base=(s32*)D_800CE80C; goto tab;
 case 0x3000: if(((u32)arg0&0xffff)>=0x25) goto fail; base=(s32*)D_800CE810; goto tab;
 case 0x4000: { u32 i=(u32)arg0&0xffff; if(i>=0x23) goto fail; return (void*)(i*300+(u32)D_8010A960); }
 case 0x6000: if(((u32)arg0&0xffff)>=0x38) goto fail; base=(s32*)D_800CE814; goto tab;
 case 0x7000: if(((u32)arg0&0xffff)>=0x1e) goto fail; base=(s32*)D_800CE81C; goto tab;
 case 0x8000: if(((u32)arg0&0xffff)>=0x17) goto fail; base=(s32*)D_800CE820; goto tab;
 case 0x9000: if(((u32)arg0&0xffff)>=0x21) goto fail; base=(s32*)D_800CE824; goto tab;
 case 0xA000: if(((u32)arg0&0xffff)>=0x38) goto fail; base=(s32*)D_800CE818; goto tab;
 case 0xB000: if(((u32)arg0&0xffff)>=0x6d) goto fail; base=(s32*)D_800CE828; goto tab;
 case 0xC000: if(((u32)arg0&0xffff)>=0x78) goto fail; base=(s32*)D_800CE82C; goto tab;
 }
 goto fail;
tab:
 if(base) return (void*)(D_800CE800+base[(u32)arg0&0xffff]);
fail:
 return lookupDataEntry(3,arg1);
}
