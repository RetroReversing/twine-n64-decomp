#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
s32 voiceResetSlot();
s32 voiceListRemove();
s32 voiceReleaseHandles();
extern u8 D_801002EA;
extern u8 D_8010A930;
extern u8 D_8010D720;
extern char sVoiceTable[];
extern char D_8010D784[];
extern char gVoiceChannelTable[];
extern u8 D_80110DB0;
extern char D_80117388[];
extern char D_80117389[];
extern u8 gWorkerActive;
typedef struct VNode { struct VNode *next; s32 pad4; u32 key; s32 value; } VNode;
extern VNode *gVoiceListHead;

typedef struct { unsigned char field_0; unsigned char field_1; unsigned short field_2; } __repair_record_temp_a0;
s32 sndStopNode(u32 arg0) {
    s32 ret;
    s32 off;
    s32 next;
    s32 idx;
    VNode *node;
    VNode *found;
    char *voice;
    void *rec;

    ret = -1;
    if (gWorkerActive != 0) {
        if (arg0 != ret) {
            found = NULL;
            for (node = gVoiceListHead; node != NULL; node = node->next) {
                if (node->key == arg0) {
                    found = node;
                    break;
                }
                if (arg0 < node->key) {
                    break;
                }
            }
            if (found != NULL) {
                arg0 = found->value;
            } else {
                arg0 = -1;
            }
        }
        if (arg0 != -1) {
            do {
                idx = arg0 & 0xFF;
                off = idx * 0x1A0;
                next = *(s32 *)(gVoiceChannelTable + off);
                if (*(s32 *)(D_8010D784 + off) == arg0) {
                    if (*(s32 *)(sVoiceTable + off) != 0) {
                        voice = off + sVoiceTable;
                        voiceListRemove(voice);
                        M2C_FIELD(voice, s32 *, 0x28) = 0;
                        M2C_FIELD(voice, s32 *, 0x24) &= -4;
                        voiceReleaseHandles(voice);
                        arg0 = M2C_FIELD(voice, u8 *, 0x63);
                        M2C_FIELD(voice, s32 *, 0) = 0;
                        M2C_FIELD(voice, s8 *, 0x2E) = 0;
                        rec = (arg0 * 4) + D_80117388;
                        if (((__repair_record_temp_a0*)rec)->field_2 == 0) {
                            ((__repair_record_temp_a0*)rec)->field_2 = 1U;
                            if (D_801002EA != 0xFF) {
                                ((__repair_record_temp_a0*)rec)->field_1 = 0xFF;
                                ((__repair_record_temp_a0*)rec)->field_0 = (u8) D_80110DB0;
                                *(D_80117389 + (D_80110DB0 * 4)) = arg0;
                            } else {
                                ((__repair_record_temp_a0*)rec)->field_1 = 0xFF;
                                ((__repair_record_temp_a0*)rec)->field_0 = 0xFF;
                                D_801002EA = arg0;
                            }
                            D_80110DB0 = arg0;
                            if (M2C_FIELD(voice, u8 *, 0x4C) != 0) {
                                D_8010A930 -= 1;
                            } else {
                                D_8010D720 -= 1;
                            }
                        }
                        M2C_FIELD(voice, s32 *, 0x60) = -1;
                    }
                    voiceResetSlot(idx);
                    ret = 0;
                }
                arg0 = next;
            } while (arg0 != -1);
        }
    }
    return ret;
}
