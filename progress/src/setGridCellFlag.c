extern u8 gInputBindingTables[];

void setGridCellFlag(s32 row, s32 col) {
    u8 (*base)[2];
    base = (u8 (*)[2])(gInputBindingTables + row * 0xA0);
    base[col][0] |= 0x80;
}
