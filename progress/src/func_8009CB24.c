/* adapted from similar verified C in func_8009C7C4 in TWINE (matched), with its names changed by decompdecomp */
extern void workerLockAcquire(void);
extern void workerLockRelease(void);
extern s32 func_800989B8(s32);
extern void func_80095A80(u8, u8, u8, u8);
extern u8 gWorkerActive;
extern s32 gVoiceChannelTable, D_8010D748, D_8010D784;
extern u8 D_8010D76F, D_8010D779;

s32 func_8009CB24(s32 arg0, s32 arg1) {
    register s32 index;
    s32 offset, handle, result, end, parameter;
    handle = arg0;
    result = -1;
    parameter = arg1;
    if (gWorkerActive != 0) {
        workerLockAcquire();
        handle = func_800989B8(handle);
        if (handle == result) goto unlock;
        end = -1;
again:        {
            index = handle & 0xFF;
            offset = index * 0x1A0;
            if (*(s32 *)((s8 *)&D_8010D784 + offset) != handle) goto unlock;
            if (*(s32 *)((s8 *)&D_8010D748 + offset) & 2) {
                do { func_80095A80(64, index, *(&D_8010D779 + offset), parameter); } while (0);
            } else {
                func_80095A80(64, index, *(&D_8010D76F + index * 0x1A0), parameter);
            }
            handle = *(s32 *)((s8 *)&gVoiceChannelTable + index * 0x1A0);
            result = 0;
            if (handle != end) goto again;
        }
unlock:
        workerLockRelease();
    }
    return result;
}
