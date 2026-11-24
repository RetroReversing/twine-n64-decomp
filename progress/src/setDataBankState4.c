/* Sets the data bank's state byte (offset 0x11DD) to 4. */ void setDataBankState4(void *bank) { *(u8 *)((char *)bank + 0x11DD) = 4; }
