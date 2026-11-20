extern u32 func_80045CC4(void);
void func_8002E9D0(u8 *buffer, u32 lengthArg)
{
    u32 index;
    u32 offset;
    s32 limit;
    u32 length;
    buffer[0] = '0';
    length = lengthArg;
    buffer[1] = '0';
    buffer[2] = '0';
    index = func_80045CC4() & 1;
    offset = (u16)index;
    if ((s32)offset < (s32)(u16)length - 3) {
        do {
            u8 *entry = buffer + offset;
            u32 random = func_80045CC4();
            s32 flag;
            random %= 255U;
            flag = (random < 128U) ^ 1;
            index += 3;
            offset = (u16)index;
            entry[1] = '0';
            entry[2] = '0';
            entry[0] = ((-flag) & 0x37) | 0x32;
            limit = (s32)(u16)length - 3;
        } while ((s32)offset < limit);
    }
    buffer[(u16)length - 1] = 0;
}
