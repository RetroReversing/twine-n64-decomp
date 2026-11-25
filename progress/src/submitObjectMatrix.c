s32 drawObjectPart(s32);
s32 buildRotationTranslationMatrix(s32 *, f32, f32, f32, f32, f32, f32);
s32 guMtxF2L(s32 *, s32);
extern u32 sMatrixPoolLimit, sMatrixPoolUsed;
extern s32 sCurrentMatrixSlot, sObjectMatrixF;
extern void *sDisplayListCursor, *sRenderState;

typedef struct {
    u8 pad[24];
    s32 dlId;
    u8 pad1c[4];
    f32 posX, posY, posZ;
    f32 angleX, angleY, angleZ;
} ObjectMatrix;

/* Builds the object's transform in the matrix pool and appends a G_MTX display list command that loads it. */
void submitObjectMatrix(ObjectMatrix *obj, s32 arg1) {
    void *cmd;
    u32 dlId, used, newUsed;
    s32 base;

    dlId = obj->dlId;
    if (!dlId) {
        return;
    }
    used = sMatrixPoolUsed;
    if (used < sMatrixPoolLimit) {
        base = *(s32 *)((char *)sRenderState + 0x74c);
        newUsed = used + 1;
        sMatrixPoolUsed = newUsed;
        sCurrentMatrixSlot = base + (newUsed << 6);
        buildRotationTranslationMatrix(&sObjectMatrixF, obj->angleX * 0.0015339808f, obj->angleY * 0.0015339808f, obj->angleZ * 0.0015339808f, obj->posX * 64.0f, obj->posY * 64.0f, obj->posZ * 64.0f);
        guMtxF2L(&sObjectMatrixF, sCurrentMatrixSlot);
        {
            u32 opcode = 0xDA380003, address;
            cmd = sDisplayListCursor;
            address = sCurrentMatrixSlot;
            sDisplayListCursor = (char *)cmd + 8;
            ((u32 *)cmd)[0] = opcode;
            ((u32 *)cmd)[1] = address - 0x80000000u;
            drawObjectPart(dlId);
        }
    }
}
