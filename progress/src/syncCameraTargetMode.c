#ifndef M2C_DEFINES
#define M2C_DEFINES
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define M2C_CARRY 0
#define M2C_OVERFLOW(a) (0)
#endif
extern u8 D_800C4736;
/* Copies the target's previous byte and sets the view mode to 1 or 3 depending on a per-target table flag. */ void syncCameraTargetMode(void *camera) {
    void *viewState;
    void *target;
    void *view;
    s32 mode;
    s32 targetIndex;
    target = M2C_FIELD(camera, void **, 0x68);
    view = M2C_FIELD(camera, void **, 0x6C);
    M2C_FIELD(target, u8 *, 0xF) = M2C_FIELD(target, u8 *, 0xE);
    
    targetIndex = M2C_FIELD((M2C_FIELD(camera, void **, 0x68)), s8 *, 0x10);
    mode = *((u16 *)((s8 *)&D_800C4736 + targetIndex * 0xE8));
    if (mode == 0) goto zero_case;
    mode = 1;
    viewState = M2C_FIELD(view, void **, 0xA8);
    goto finish;
zero_case:
    viewState = M2C_FIELD(view, void **, 0xA8);
    mode = 3;
finish:
    M2C_FIELD(viewState, s16 *, 0x7A) = mode;
}
