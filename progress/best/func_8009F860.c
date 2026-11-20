typedef struct { char pad[4]; u8 x4,x5,x6,x7,x8,x9; u8 pad2[2]; u32 address; } Dev;
extern Dev *D_800CFDA0[];
extern s32 osVirtualToPhysical(void *);
s32 func_8009F860(Dev *d, s32 dir, u32 offset, void *dram, s32 len) {
 Dev *old; u32 domain, value; volatile u32 *reg;
 while (*(volatile u32 *)0xA4600010 & 3) {}
 domain=d->x9; old=D_800CFDA0[domain];
 if(old->x4 != d->x4) {
  if(domain==0) {
   if(old->x5!=d->x5) *(volatile u32 *)0xA4600014=d->x5;
   if(old->x6!=d->x6) *(volatile u32 *)0xA460001C=d->x6;
   if(old->x7!=d->x7) *(volatile u32 *)0xA4600020=d->x7;
   reg=(volatile u32 *)0xA4600018;
  } else {
   if(old->x5!=d->x5) *(volatile u32 *)0xA4600024=d->x5;
   if(old->x6!=d->x6) *(volatile u32 *)0xA460002C=d->x6;
   reg=(volatile u32 *)0xA4600028;
   if(old->x7!=d->x7) *(volatile u32 *)0xA4600030=d->x7;
  }
  if(old->x8!=d->x8) *reg=d->x8;
  old->x4=d->x4; old->x5=d->x5; old->x6=d->x6; old->x7=d->x7; old->x8=d->x8;
 }
 *(volatile u32 *)0xA4600000=osVirtualToPhysical(dram);
 *(volatile u32 *)0xA4600004=(d->address|offset)&0x1fffffff;
 switch(dir) { case 0: reg=(volatile u32 *)0xA460000C; break; case 1: reg=(volatile u32 *)0xA4600008; break; default: return -1; }
 *reg=len-1; return 0;
}
