extern s32 func_8000DA08(void *arg0);
extern f32 D_80112F90;
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

void func_80008660(void *arg0) {
    const f32 *basis = (const f32 *)func_8000DA08(arg0);
    const f32 *translation = (const f32 *)((const u8 *)arg0 + 0x24);
    f32 value = basis[0];
    f32 scale = 64.0f;

    D_80112F90 = value;
    D_80112F94 = basis[3];
    value = basis[6];
    D_80112F9C = 0;
    D_80112F98 = value;
    D_80112FA0 = basis[1];
    D_80112FA4 = basis[4];
    value = basis[7];
    D_80112FAC = 0;
    D_80112FA8 = value;
    D_80112FB0 = basis[2];
    D_80112FB4 = basis[5];
    value = basis[8];
    D_80112FBC = 0;
    D_80112FB8 = value;
    D_80112FC0 = translation[0] * scale;
    D_80112FC4 = translation[1] * scale;
    value = translation[2] * scale;
    D_80112FCC = 1.0f;
    D_80112FC8 = value;
}
