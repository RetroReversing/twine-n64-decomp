#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
s32 func_8008C1B0(u32);
void setClipSlotValue(u8, u8, u8);
void func_8009876C(void *, s32);
s32 allocVoiceSerial(void *);
void registerVoiceHandle(void *);
extern u8 D_8010D724[];
extern u8 D_8010D734[];
extern u8 D_801176E8;
/* Retargets every active voice whose two ids match (matchIdA, matchIdB): resets its envelope state, links the voices into a chain and starts them; returns the first voice handle or -1. */ s32 retargetMatchingVoices(s32 newValue, u8 matchIdA, u8 matchIdB) {
u8 idA;
u8 idB;
u8 *lastVoice;
u8 *voiceEntry;
s32 byteOffset;
u8 *voiceField;
s16 newValueS16;
s32 temp_a0;
s32 temp_a1_2;
s32 temp_a2;
s32 firstVoiceHandle;
s32 prevHandle;
u16 temp_a1;
u32 voiceIndex;
u8 temp_a3;
void *temp_s2;
firstVoiceHandle = -1;
voiceEntry = D_8010D724;
voiceIndex = 0;
idA = matchIdA;
idB = matchIdB;
if (voiceIndex < D_801176E8) {
newValueS16 = newValue & 0xFF;
voiceField = D_8010D724 + 0x24;
byteOffset = 0;
do {
            if ((M2C_FIELD(voiceField, s32 *, 0x3C) != -1) && (M2C_FIELD(voiceField, u8 *, 0x26) == idA) && (M2C_FIELD(voiceField, u8 *, 0x27) == idB)) {
                temp_a0 = M2C_FIELD(voiceField, s32 *, 0x0);
                if ((temp_a0 & 0x10) && ((temp_a0 & 0x40000008) != 8) && (func_8008C1B0(voiceIndex) & 0xFF)) {
                    temp_a2 = M2C_FIELD(voiceField, s8 *, 0x9C) << 0x10;
                    M2C_FIELD(voiceField, s8 *, 0x9D) = (s8) M2C_FIELD(voiceField, u16 *, 0x2C);
                    temp_a3 = M2C_FIELD(voiceField, u8 *, 0x2B);
                    temp_s2 = byteOffset + D_8010D724;
                    temp_a1 = M2C_FIELD(voiceField, u16 *, 0x2C);
                    lastVoice = voiceEntry;
                    M2C_FIELD(voiceField, s16 *, 0x2A) = newValueS16;
                    M2C_FIELD(voiceField, s8 *, 0x9C) = 0;
                    M2C_FIELD(voiceField, s32 *, 0x68) = 0;
                    M2C_FIELD(voiceField, u16 *, 0x2C) = (u16) (newValueS16 + (M2C_FIELD(voiceField, u8 *, 0x2D) - temp_a3));
                    temp_a1_2 = (temp_a1 << 0x10) + temp_a2 / 100;
                    M2C_FIELD(voiceField, s32 *, 0x0) = (s32) (M2C_FIELD(voiceField, s32 *, 0x0) | 0x80800);
                    M2C_FIELD(voiceField, s32 *, 0x70) = temp_a1_2;
                    func_8009876C(temp_s2, temp_a1_2);
                    if (firstVoiceHandle == -1) {
                        M2C_FIELD(lastVoice, s32 *, 0x10) = firstVoiceHandle;
                        M2C_FIELD(lastVoice, s32 *, 0x14) = firstVoiceHandle;
                        firstVoiceHandle = allocVoiceSerial(temp_s2);
                    } else {
                        { s32 *q; q = (s32 *)(D_8010D734 + ((prevHandle & 0xFF) * 0x1A0)); *q = M2C_FIELD(lastVoice, s32 *, 0x60); }
M2C_FIELD(lastVoice, s32 *, 0x14) = prevHandle;
                    }
  do { do { prevHandle = M2C_FIELD(lastVoice, s32 *, 0x60); } while (0); } while (0);
                }
            }
byteOffset += 0x1A0;
voiceIndex += 1;
voiceField += 0x1A0;
voiceEntry += 0x1A0;
} while (voiceIndex < (u8) D_801176E8);
}
if (firstVoiceHandle != -1) {
registerVoiceHandle(lastVoice);
setClipSlotValue(M2C_FIELD(lastVoice, u8 *, 0x4A), M2C_FIELD(lastVoice, u8 *, 0x4B), M2C_FIELD(lastVoice, u8 *, 0x51));
}
return firstVoiceHandle;
}
