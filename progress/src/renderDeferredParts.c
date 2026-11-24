static __inline__ u32 __repair_inline(u32 a) { return a; }
typedef struct { u32 w0; u32 w1; } Gfx;
typedef struct { unsigned char pad_0[24]; int field_18; void *field_1C; unsigned char pad_20[4]; float field_24; float field_28; float field_2C; int field_30; int field_34; int field_38; int field_3C; unsigned char pad_40[28]; unsigned int field_5C; } Rec;

s32 drawObjectPart(s32);
s32 func_8003438C(s32, void *);
s32 func_80034560();
s32 emitClippedScissor(s32, void *);
s32 buildRotationTranslationMatrix(s32 *, s32, s32, s32, f32, f32, f32);
s32 appendProjectionViewportCommands();
s32 guMtxF2L(s32 *, s32);
s32 guTranslateF(s32 *, f32, f32, f32);
extern s32 gGeometryModeSetupDL;
extern u32 sMatrixPoolLimit;
extern void *gDeferredPartList;
extern s32 gCurCombineSetup;
extern u32 sMatrixPoolUsed;
extern s32 gCurGeometryModeSetup;
extern s32 D_8010D538;
extern s32 D_80112E40;
extern s32 D_80112F90;
extern Gfx *D_80115328;
extern void *sRenderState;

/* Emits display-list commands for the deferred part list, setting up each part's translation/rotation matrix from the matrix pool. */ void renderDeferredParts(void *view) {
    s32 group;
    s32 lastGroup = 0;
    Rec *part;
    Gfx *cmd;
Gfx *__repair_phase_dl;
    u32 value;
    u32 matrixCount;
    u32 w0;
    Gfx *nx;
    

    part = (Rec *)gDeferredPartList;
    if (part != NULL) {
        func_80034560();
        if (D_80112E40 != 0) {
            D_80112E40 = 0;
            appendProjectionViewportCommands();
        }
        if (gCurGeometryModeSetup != 8) {
            __repair_phase_dl = D_80115328;
            gCurGeometryModeSetup = 8;
            D_80115328 = __repair_phase_dl + 1;
            __repair_phase_dl->w0 = 0xDE000000;
            __repair_phase_dl->w1 = (u32)&gGeometryModeSetupDL;
        }
        if (gCurCombineSetup != 4) {
            u32 second;
            value = *(s32 *)((char *)view + 0x100) & 7;
            gCurCombineSetup = 4;
            if (value == 1) {
                w0 = 0xFC121824;
                value = (u32)D_80115328;
                second = 0xFF33FFFF;
            } else if (value == 2) {
                w0 = 0xFC119823;
                value = (u32)D_80115328;
                second = 0xFF32FF7F;
            } else if (value == 4) {
                w0 = 0xFC119823;
                value = (u32)D_80115328;
                second = 0xFF32FF7F;
            } else {
                goto skip_cmd;
            }
            D_80115328 = (Gfx *)(value + 8);
            ((Gfx *)value)->w0 = w0;
            ((Gfx *)value)->w1 = second;
        }
skip_cmd:
        if (part != NULL) {
            for (;;) {
                group = part->field_18;
                if (group != lastGroup) {
                    func_8003438C(group, view);
                    emitClippedScissor(group, view);
                    lastGroup = group;
                }
                if ((part->field_5C >> 23) & 3) {
                    matrixCount = sMatrixPoolUsed;
                    if (sMatrixPoolLimit > matrixCount) {{ u32 __repair_value; __repair_value = matrixCount + 1; matrixCount = __repair_value; }
                        sMatrixPoolUsed = matrixCount;
                        D_8010D538 = *(s32 *)((char *)sRenderState + 0x74C) + (matrixCount << 6);
                        if ((part->field_5C >> 23) & 2) {
                            buildRotationTranslationMatrix(&D_80112F90, part->field_30, part->field_34, part->field_38, part->field_24 * 64.0f, part->field_28 * 64.0f, part->field_2C * 64.0f);
                        } else {
                            guTranslateF(&D_80112F90, part->field_24 * 64.0f, part->field_28 * 64.0f, part->field_2C * 64.0f);
                        }
                        do { guMtxF2L(&D_80112F90, D_8010D538); } while (0);
                        cmd = D_80115328;
                        value = D_8010D538;
                        nx = cmd + 1;
                        D_80115328 = nx;
                        cmd->w0 = 0xDA380003;
                        value -= 0x80000000;
                    } else {
                        break;
                    }
                } else {
                    cmd = D_80115328;
                    cmd->w0 = 0xDA380003;
                    value = *(s32 *)((char *)sRenderState + 0x74C);
                    nx = cmd + 1;
                    D_80115328 = nx;
                    value -= 0x80000000;
                }
                ((u32 *)cmd)[1] = value;
                drawObjectPart(part->field_3C);
                part = part->field_1C;
                if (part == NULL) {
                    break;
                }
            }
        }
    }
}



