/* Writes the RSP SP_STATUS register (0xA4040010). */ void __osSpSetStatus(s32 status) {
    *(volatile s32 *)0xA4040010 = status;
}
