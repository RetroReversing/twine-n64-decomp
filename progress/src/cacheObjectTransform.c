void *getObjectRecordSubPtr();
extern f32 sObjectMatrixF;
extern f32 D_80112F94;
extern f32 D_80112F98;
extern s32 D_80112F9C;
extern f32 D_80112FA0;
extern f32 D_80112FA4;
extern f32 D_80112FA8;
extern s32 D_80112FAC;
extern f32 D_80112FB0;
extern f32 D_80112FB4;
extern f32 D_80112FB8;
extern s32 D_80112FBC;
extern f32 D_80112FC0;
extern f32 D_80112FC4;
extern f32 D_80112FC8;
extern f32 D_80112FCC;

/* Caches the 3x3 rotation of the current object matrix (column-wise) and the object position scaled by 64 into the global transform slots; the last slot is set to 1.0. */
void cacheObjectTransform(void *object) {
    void *matrix;

    matrix = getObjectRecordSubPtr();
    sObjectMatrixF = *(f32 *)((char *)matrix + 0);
    D_80112F94 = *(f32 *)((char *)matrix + 0xC);
    D_80112F98 = *(f32 *)((char *)matrix + 0x18);
    D_80112F9C = 0;
    D_80112FA0 = *(f32 *)((char *)matrix + 4);
    D_80112FA4 = *(f32 *)((char *)matrix + 0x10);
    D_80112FA8 = *(f32 *)((char *)matrix + 0x1C);
    D_80112FAC = 0;
    D_80112FB0 = *(f32 *)((char *)matrix + 8);
    D_80112FB4 = *(f32 *)((char *)matrix + 0x14);
    D_80112FB8 = *(f32 *)((char *)matrix + 0x20);
    D_80112FBC = 0;
    D_80112FC0 = *(f32 *)((char *)object + 0x24) * 64.0f;
    D_80112FC4 = *(f32 *)((char *)object + 0x28) * 64.0f;
    D_80112FC8 = *(f32 *)((char *)object + 0x2C) * 64.0f;
    D_80112FCC = 1.0f;
}
