extern s32 D_800CE800, D_800CE804, D_800CE808, D_800CE80C, D_800CE810, D_800CE814, D_800CE818, D_800CE81C, D_800CE820, D_800CE824, D_800CE828, D_800CE82C;
extern char D_8010A960[];
void *func_80087100(s32 id, s32 base) {
 u16 index = id & 0xfff;
 s32 *p;
 switch (id & 0xf000) {
 case 0: if (index < 0x2ea && D_800CE804) { p = (s32 *)(index * 4 + (int)D_800CE804); return (void *)(D_800CE800 + *p); } break;
 case 0x1000: if (index < 0x92 && D_800CE808) { p = (s32 *)(index * 4 + (int)D_800CE808); return (void *)(D_800CE800 + *p); } break;
 case 0x2000: if (index < 0x2c && D_800CE80C) { p = (s32 *)(index * 4 + (int)D_800CE80C); return (void *)(D_800CE800 + *p); } break;
 case 0x3000: if (index < 0x25 && D_800CE810) { p = (s32 *)(index * 4 + (int)D_800CE810); return (void *)(D_800CE800 + *p); } break;
 case 0x4000: if (index < 0x23) return D_8010A960 + index * 0x12c; break;
 case 0x6000: if (index < 0x38) { base = D_800CE814; goto common; } break;
 case 0x7000: if (index < 0x1e) { base = D_800CE81C; goto common; } break;
 case 0x8000: if (index < 0x17) { base = D_800CE820; goto common; } break;
 case 0x9000: if (index < 0x21) { base = D_800CE824; goto common; } break;
 case 0xa000: if (index < 0x38) { base = D_800CE818; goto common; } break;
 case 0xb000: if (index < 0x6d) { base = D_800CE828; goto common; } break;
 case 0xc000: if (index < 0x78) { base = D_800CE82C; goto common; } break;
 }
 goto fail;
 common:
 if (base) { p = (s32 *)base + index;  return (void *)(D_800CE800 + *p); }
 fail: return func_80087100(3, base);
}
