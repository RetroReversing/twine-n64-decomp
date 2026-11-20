extern void func_8008C0D4(void);
extern void func_8008C11C(void);
extern s32 func_800989B8(s32);
extern void func_80095A80(u8, u8, u8, u8);
extern u8 D_800CF540;
extern s32 D_8010D734, D_8010D748, D_8010D784;
extern u8 D_8010D76F, D_8010D779;

s32 func_8009C7C4(s32 arg0, s32 arg1) {
    register s32 index;
    s32 offset, handle, result, end, parameter;
    handle = arg0;
    result = -1;
    parameter = arg1;
    if (D_800CF540 != 0) {
        func_8008C0D4();
        handle = func_800989B8(handle);
        if (handle == result) goto unlock;
        end = -1;
again:        {
            index = handle & 0xFF;
            offset = index * 0x1A0;
            if (*(s32 *)((s8 *)&D_8010D784 + offset) != handle) goto unlock;
            if (*(s32 *)((s8 *)&D_8010D748 + offset) & 2) {
                func_80095A80(0x5B, index, *(&D_8010D779 + offset), parameter);
            } else {
                func_80095A80(0x5B, index, *(&D_8010D76F + index * 0x1A0), parameter);
            }
            handle = *(s32 *)((s8 *)&D_8010D734 + index * 0x1A0);
            result = 0;
            if (handle != end) goto again;
        }
unlock:
        func_8008C11C();
    }
    return result;
}
