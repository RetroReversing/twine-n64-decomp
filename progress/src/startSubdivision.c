s32 subdivideDisplayListTriangles();
void buildRotationMatrixS16(const s16 *angles, void *mtx);
extern u8 sSubdivideFlags;
extern f64 D_800D4838;
extern s32 sSubdivideMode;
extern f32 gSubdivideMinSize;
extern u32 sSubdivideBank;
extern s32 sSubdivideCount;

/* Starts a subdivision pass for an object: stores the bank, flags, mode and minimum size
   (negative sizes are biased by 2^32), builds a rotation from the direction, and runs the pass. */
void startSubdivision(void *object, s32 auxA, s32 auxB, f32 dirX, f32 dirY, f32 dirZ, s32 minSize, s32 mode) {
    char rotMtx[0x30];
    s16 angles[3];
    f32 dir[3];
    f64 size;

    dir[0] = dirX;
    dir[1] = dirY;
    dir[2] = dirZ;
    size = (f64) minSize;
    sSubdivideBank = (u32) *(u32 *)((u8 *)object + 0x30) >> 0x14;
    if (minSize < 0) {
        size += D_800D4838;
    }
    gSubdivideMinSize = (f32) size;
    sSubdivideMode = mode;
    sSubdivideFlags = *(u8 *)((u8 *)object + 0x44);
    angles[0] = dirX;
    angles[1] = dirY;
    angles[2] = dirZ;
    buildRotationMatrixS16(angles, rotMtx);
    sSubdivideCount = 0;
    subdivideDisplayListTriangles(object, auxA, auxB, dir, 0);
}
