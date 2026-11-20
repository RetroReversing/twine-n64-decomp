s32 func_800A9250(void); s32 osVirtualToPhysical(s32);
extern volatile s32 D_A4040000;
s32 func_800A92C0(s32 a,s32 b,s32 c,s32 d) {
 if (func_800A9250()) return -1;
 *(volatile s32 *)0xA4040000=b;
 *(volatile s32 *)0xA4040004=osVirtualToPhysical(c);
 if (a) *(volatile s32 *)0xA4040008=d-1;
 else *(volatile s32 *)0xA404000C=d-1;
 return 0;
}
