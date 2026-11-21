void *spawnEffectObject();
s32 actorLinkToSurface();
s32 effectSetAnimFrame();
extern s32 *gProbeObjectList;

typedef struct EffectAnim {
    s32 bits;           /* bit-packed frame data: low 20 bits kept, bits 20+ from the descriptor */
    s8 tint0;           /* 0x04 */
    s8 tint1;           /* 0x05 */
    s8 tint2;           /* 0x06 */
} EffectAnim;

typedef struct EffectObject {
    u8 pad0[0x6C];
    EffectAnim *anim;   /* 0x6C */
    u8 pad1[0x78 - 0x70];
    s16 kind;           /* 0x78 */
    s16 animFrame;      /* 0x7A */
    u8 pad2[0x7F - 0x7C];
    u8 colorA;          /* 0x7F */
    u8 colorB;          /* 0x80 */
    u8 colorC;          /* 0x81 */
    u8 colorD;          /* 0x82 */
} EffectObject;

typedef struct EffectDesc {
    u16 param0;         /* 0x00 */
    u8 pad0[0x28 - 2];
    s16 *frames;        /* 0x28: frame list, first entry is the start frame */
    u16 param2C;        /* 0x2C */
    u16 param2E;        /* 0x2E */
    u16 param30;        /* 0x30 */
} EffectDesc;

/* Spawns an effect object of kind 0x52 at (arg0, arg1) and configures its animation and colours from a descriptor. */
void *spawnDescribedEffect(s32 arg0, s32 arg1, EffectDesc *arg2) {
    s32 temp_v0_2;
    EffectAnim *temp_a0;
    EffectObject *temp_v0;

    temp_v0 = spawnEffectObject(8, arg0, arg1);
    if (temp_v0 != NULL) {
        temp_a0 = temp_v0->anim;
        temp_v0->kind = 0x52;
        temp_v0_2 = (temp_a0->bits & 0xFFFFF) | (*arg2->frames << 0x14);
        temp_a0->bits = temp_v0_2;
        temp_a0->bits = (s32) ((temp_v0_2 & 0xFFF0000F) | (arg2->param0 * 0x10));
        temp_a0->tint0 = (s8) arg2->param2C;
        temp_a0->tint1 = (s8) arg2->param2E;
        temp_a0->tint2 = (s8) arg2->param30;
        temp_v0->colorA = 0xF0;
        temp_v0->colorB = 0xFF;
        temp_v0->colorC = 0xFF;
        temp_v0->animFrame = 0;
        temp_v0->colorD = 0x80;
        effectSetAnimFrame(temp_v0, arg2->param0, *arg2->frames);
        actorLinkToSurface(*gProbeObjectList, temp_v0, 1);
    }
    return temp_v0;
}
