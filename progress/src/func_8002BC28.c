extern u16 D_800BF686;
s32 func_8002BC28(s32 arg0) {
    return (*(u16 *)((char *)&D_800BF686 + arg0 * 12) >> 7) & 1;
}
