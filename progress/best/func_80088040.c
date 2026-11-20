typedef struct {
    u32 offsetAndFlags;
} AudioFile;

typedef struct {
    u8 state[0x11DE];
    u8 volume;
    u8 pad11DF;
    u32 queue[6];
    void *messages[2];
    u8 active;
    u8 arg3;
    u8 arg4;
    u8 arg5;
    u8 arg2;
    u32 rate;
    s32 handle;
    void *buffer;
    u32 length;
    u8 pad1218;
    u8 arg6;
    u8 pad121A[14];
} AudioSlot;

extern s32 func_80087F60(s32);
extern s32 func_800936A8(void);
extern void func_8009D510(void *, u32, void *, u32, void (*)(void));
extern void func_800A0170(void *, s32);
extern void osCreateMesgQueue(void *, void **, s32);
extern s32 osRecvMesg(void *, void **, s32);
extern s32 osSendMesg(void *, void *, s32);
extern void func_80088F6C(void);

extern u8 D_800CEEC0;
extern AudioSlot D_800E1AC0[];
extern u8 D_800E2CC0[];
extern u32 D_800E3F18;
extern AudioFile *D_800E3F1C;
extern u32 D_800E3F20;
extern void *D_800E3F24[];
extern u32 D_800E3F2C;
extern u32 D_800E3F30[6];
extern void *(*D_8010017C)(s32, s32);
extern u8 D_8010086C;

s32 func_80088040(u32 file, u32 rate, u8 arg2, s32 arg3, u8 arg4, u8 arg5, u8 arg6)
{
    s32 index;
    s32 offset;
    AudioSlot *slot;
    u32 length;
    s32 allocationSize;
    void *buffer;

    if (D_800CEEC0 && file < D_800E3F20) {
        for (index = 0, offset = 0; index < 2; offset += sizeof(AudioSlot)) {
            if (!D_800E2CC0[offset]) {
                break;
            }
            index++;
        }
        if (index != 2) {
            slot = &D_800E1AC0[index];
            osCreateMesgQueue(slot->queue, slot->messages, 2);
            if (rate == 0) {
                rate = !*(u8 *)&D_800E3F1C[file] ? 8000 : 16000;
            }
            slot->arg2 = arg2;
            slot->arg3 = arg3;
            slot->arg4 = arg4;
            slot->arg5 = arg5;
            slot->arg6 = arg6;
            slot->rate = rate;
            length = (((rate * 8) / 30 + 159) / 160) * 160;
            slot->length = length;
            if (D_800E3F2C & 1) {
                slot->buffer = D_800E3F24[index];
            } else {
                allocationSize = func_800936A8();
                buffer = D_8010017C(allocationSize, 0);
                slot->buffer = buffer;
                func_800A0170(buffer, allocationSize);
            }
            if (slot->buffer != NULL) {
                osRecvMesg(D_800E3F30, NULL, 1);
                func_8009D510(slot, (D_800E3F1C[file].offsetAndFlags & 0xFFFFFF) + D_800E3F18,
                              slot->buffer, slot->length, func_80088F6C);
                if (D_8010086C) {
                    slot->volume *= 2;
                }
                slot->handle = -1;
                *(volatile u8 *)&slot->active = 1;
                osSendMesg(&D_800E3F24[3], NULL, 0);
                return func_80087F60(index);
            }
        }
    }
    return -1;
}
