s32 workerLockAcquire();
s32 workerLockRelease();
extern s32 D_800FD560;
extern char D_800FD564[];
extern char sWorkerEntryFlags[];
extern char sWorkerEntryData[];

/* Registers a worker entry by id: reuses a matching slot or appends a new one (max 128), then tags the data block's byte 9 with 0x1F for each flag count. */ s32 registerWorkerEntry(s32 id, void *data, s16 flags) {
    s16 temp_s1;
    s16 flagsValue;
    u16 flagsArg;
    s32 offset;
s32 __repair_phase_temp_a2;
    s32 entryCount;
    s32 slot; volatile s32 reserved[4];
    s32 entryId;
s32 __repair_phase_var_v1_2;
    void *dataCursor;

    flagsArg = flags;
    dataCursor = data;
    offset = id;
    entryCount = D_800FD560;
    slot = 0;
    entryId = offset;
    flagsValue = flagsArg;
    if (entryCount > 0) {
        u32 masked_id = entryId & 0xFFFF;
        offset = 0;
        for (;;) {
            if (*(u16 *)(D_800FD564 + offset) != masked_id) {
                slot += 1;
                offset += 8;
                if (slot < entryCount) continue;
            }
            break;
        }
    }
    if (slot == D_800FD560) {
        if (slot < 0x80) {
            s32 entry_offset;
            workerLockAcquire(offset);
            __repair_phase_temp_a2 = flagsValue & 0xFFFF;
            entry_offset = D_800FD560 * 8;
            *(u16 *)(D_800FD564 + (unsigned)entry_offset) = entryId;
            *(u16 *)(sWorkerEntryFlags + entry_offset) = flagsValue;
            *(void **)(sWorkerEntryData + entry_offset) = dataCursor;
            __repair_phase_var_v1_2 = 0;
            if (__repair_phase_temp_a2 > 0) {
                do {
                    (*(s8 *)((char *)(dataCursor) + 9)) = 0x1F;
                    __repair_phase_var_v1_2 += 1;
                    dataCursor += 0xC;
                } while (__repair_phase_var_v1_2 < __repair_phase_temp_a2);
            }
            D_800FD560 += 1;
            workerLockRelease();
            return 1;
        }
    }
    return 0;
}
