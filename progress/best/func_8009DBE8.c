void func_8009DBE8(s32 arg0, s32 arg1, s16 *arg2, s16 *arg3, s16 *arg4, s16 *arg5, s32 arg6, s32 arg7) {
    struct { u8 pad[0x44]; s32 buf[1]; } local;
    s32 i;
    for (i=0;i<4;i++) {
      func_8009EE60(*arg5,*arg4,arg6,&local.buf[0]);
      do { func_8009EF54(arg0,*arg2,*arg3,&local.buf[0]); } while (0);
      arg5++;arg3++;arg2++;arg4++;arg6+=0x1A;
    }
    func_8009D9F0(arg0,arg1,arg0,arg7);
}
