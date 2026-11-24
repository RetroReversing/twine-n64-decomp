/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */
#ifndef M2C_DEFINES
#define M2C_DEFINES
typedef s32 M2C_UNK;
typedef s8 M2C_UNK8;
typedef s16 M2C_UNK16;
typedef s32 M2C_UNK32;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define M2C_CARRY 0
#define M2C_OVERFLOW(a) (0)
#endif

s32 setActorAssetIndexKeepByte();
s32 listUnlinkFree();
s32 rampMenuSoundChannelDown();
s32 requestSound();
s32 spawnTextNode();
s32 getSaveSlotIndex();
s32 spawnEnemyDefEffect();
s32 actorSetField7A();
s32 setActorStateAndReset();
s32 clearActorSubstateFields();
s32 resetEnemyAnimationAndEffects();
s32 startActorReactionByFacing();
s32 emptyStubB();
void *lookupDataEntry();
s32 updateActorPartnerLink();
s32 getViewportCenter();
s32 findLinkedObjectByFlagMask();
s32 sprintf();
extern char D_800C7CAC[];
extern s16 D_800C7CB4;
extern s16 D_800C7CC0;
extern char gPlayerNames[];
extern s32 gBorderSkipActive;

extern char D_800D42E0[];
extern char D_800D42E8[];
s32 actorFinishIfMatch(void *arg0, s32 arg1) {
    s32 *var_a1_2;
    s32 var_a1;
    s16 temp_a0_3;
    s32 temp_a0_4;
    s32 temp_s0;
    void *temp_a0;
    void *temp_a0_2;
    void *temp_s0_2;
    void *temp_s0_3;
    void *temp_s1;
    void *temp_s1_2;
    void *temp_s3;
    void *temp_v0;
    
    
    void *var_a3;

    temp_s3 = M2C_FIELD(arg0, void **, 0x6C);
    if (M2C_FIELD(arg0, f32 *, 0x74) <= 0.0f) {
        if (M2C_FIELD(arg0, u16 *, 0x78) == arg1) {
            clearActorSubstateFields();
            temp_a0 = M2C_FIELD(temp_s3, void **, 0xBC);
            if ((temp_a0 != NULL) && (M2C_FIELD(temp_a0, u16 *, 0x78) == 0x3D)) {
                M2C_FIELD(temp_a0, s16 *, 0x7A) = 5;
                M2C_FIELD(temp_s3, void **, 0xBC) = NULL;
            }
            M2C_FIELD(arg0, f32 *, 0x74) = 0.0f;
            emptyStubB(arg0, 1);
            spawnEnemyDefEffect(arg0, 0, M2C_FIELD(M2C_FIELD(arg0, void **, 0x68), s8 *, 0xE));
            startActorReactionByFacing(arg0);
            temp_v0 = M2C_FIELD(arg0, void **, 0x68);
            M2C_FIELD(temp_v0, s8 *, 0xF) = 0;
            M2C_FIELD(temp_v0, s8 *, 0xE) = 0;
            M2C_FIELD(temp_v0, s8 *, 0x10) = 0;
            resetEnemyAnimationAndEffects(arg0);
            M2C_FIELD(M2C_FIELD(temp_s3, void **, 0xA8), s16 *, 0x7A) = 0;
            setActorAssetIndexKeepByte(arg0, M2C_FIELD(M2C_FIELD(arg0, void **, 0x68), s8 *, 0xF));
            temp_a0_2 = M2C_FIELD(temp_s3, void **, 0x410);
            M2C_FIELD(temp_s3, s8 *, 0x5A8) = 2;
            if (temp_a0_2 != NULL) {
                M2C_FIELD(temp_a0_2, s32 *, 0x28) = (s32) ((M2C_FIELD(temp_a0_2, s32 *, 0x28) & ~0xFC) | 0x1C);
            }
            actorSetField7A(arg0, 2);
            if (!(M2C_FIELD(M2C_FIELD(arg0, void **, 0x68), u16 *, 0xC) & 0x200)) {
                var_a1 = 8;
            
            setActorStateAndReset(arg0, var_a1);} else {
                var_a1 = 0xA;
            
            setActorStateAndReset(arg0, var_a1);}
            if (gBorderSkipActive == 0) {
                rampMenuSoundChannelDown();
                requestSound(0x101);
            } else {
                if (M2C_FIELD(M2C_FIELD(temp_s3, void **, 0xB4), s32 *, 8) == 0) {
                    temp_s0 = findLinkedObjectByFlagMask(M2C_FIELD(temp_s3, s32 *, 4));
                    updateActorPartnerLink(arg0);
                    D_800C7CC0 = (s16) (s8) M2C_FIELD(temp_s3, u8 *, 0x182);
                    temp_a0_3 = (s8) M2C_FIELD(temp_s3, u8 *, 0x182) + 0x4013;
                    D_800C7CB4 = temp_a0_3;
                    if ((temp_s0 != 0) & (temp_s0 != (s32) temp_s3)) {
void *var_a2;

void *var_a0;

                        temp_s1 = lookupDataEntry(temp_a0_3 & 0xFFFF);
                        temp_s0_2 = lookupDataEntry(0x1B1);
                        var_a0 = temp_s1;
                        var_a1_2 = D_800D42E0;
                        var_a2 = temp_s0_2;
                        var_a3 = ((getSaveSlotIndex((s8) M2C_FIELD(temp_s0, volatile u8 *, 0x182) & 0xFFFF) & 0xFFFF) * 0x18) + gPlayerNames;
                    
                    sprintf(var_a0, var_a1_2, var_a2, var_a3);} else {
void *var_a2;

void *var_a0;

                        temp_s1_2 = lookupDataEntry(temp_a0_3 & 0xFFFF);
                        temp_s0_3 = ((getSaveSlotIndex((s8) M2C_FIELD(temp_s3, volatile u8 *, 0x182) & 0xFFFF) & 0xFFFF) * 0x18) + gPlayerNames;
                        var_a0 = temp_s1_2;
                        var_a1_2 = D_800D42E8;
                        var_a2 = temp_s0_3;
                        var_a3 = lookupDataEntry(0x1B2);
                    
                    sprintf(var_a0, var_a1_2, var_a2, var_a3);}
                    getViewportCenter(D_800C7CAC, D_800C7CAC + 2, M2C_FIELD(temp_s3, u8 *, 0x182));
                    M2C_FIELD(M2C_FIELD(temp_s3, void **, 0xB4), s32 *, 8) = spawnTextNode(D_800C7CAC - 0xC);
                }
                M2C_FIELD(arg0, s32 *, 0x5C) &= ~0x200;
            }
            temp_a0_4 = M2C_FIELD(temp_s3, s32 *, 8);
            if (temp_a0_4 != -1) {
                listUnlinkFree(temp_a0_4);
                M2C_FIELD(temp_s3, s32 *, 8) = -1;
            }
            return 1;
        }
    }
    return 0;
}

