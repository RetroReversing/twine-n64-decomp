static __inline__ s32 __repair_inline(s32 a) { return a; }
typedef struct { u32 w0; u32 w1; } Gfx;
typedef struct { unsigned char pad_0[24]; int field_18; void *field_1C; unsigned char pad_20[4]; float field_24; float field_28; float field_2C; int field_30; int field_34; int field_38; int field_3C; unsigned char pad_40[28]; unsigned int field_5C; } Rec;

s32 func_80032630(s32);
s32 func_8003438C(s32, void *);
s32 func_80034560();
s32 func_80034630(s32, void *);
s32 func_800347B0(s32 *, s32, s32, s32, f32, f32, f32);
s32 emit_projection_viewport_commands();
s32 guMtxF2L(s32 *, s32);
s32 guTranslateF(s32 *, f32, f32, f32);
extern s32 D_800B1AC8;
extern u32 D_800B1D84;
extern void *D_801007BC;
extern s32 D_801032A0;
extern u32 D_80107EA0;
extern s32 D_8010A924;
extern s32 D_8010D538;
extern s32 D_80112E40;
extern s32 D_80112F90;
extern Gfx *D_80115328;
extern void *D_80117728;

void func_800371E0(void *arg0) {
    s32 temp_s0;
    s32 var_s4 = 0;
    Rec *rec;
    Gfx *dl;
    u32 sel;
    u32 cnt;
    u32 w0;
    s32 w1;

    rec = (Rec *)D_801007BC;
    if (rec != NULL) {
        func_80034560();
        if (D_80112E40 != 0) {
            D_80112E40 = 0;
            emit_projection_viewport_commands();
        }
        if (D_8010A924 != 8) {
            dl = D_80115328;
            D_8010A924 = 8;
            D_80115328 = dl + 1;
            dl->w0 = 0xDE000000;
            dl->w1 = (u32)&D_800B1AC8;
        }
        if (D_801032A0 != 4) {
            sel = *(s32 *)((char *)arg0 + 0x100) & 7;
            D_801032A0 = 4;
            if (sel == 1) {
                w0 = 0xFC121824;
                dl = D_80115328;
                w1 = 0xFF33FFFF;
            } else if (sel == 2) {
                w0 = 0xFC119823;
                dl = D_80115328;
                w1 = 0xFF32FF7F;
            } else if (sel == 4) {
                w0 = 0xFC119823;
                dl = D_80115328;
                w1 = 0xFF32FF7F;
            } else {
                goto skip_cmd;
            }
            D_80115328 = dl + 1;
            dl->w0 = w0;
            dl->w1 = w1;
        }
skip_cmd:
        if (rec != NULL) {
            for (;;) {
                temp_s0 = rec->field_18;
                if (temp_s0 != var_s4) {
                    func_8003438C(temp_s0, arg0);
                    func_80034630(temp_s0, arg0);
                    var_s4 = temp_s0;
                }
                if ((rec->field_5C >> 23) & 3) {
                    cnt = D_80107EA0;
                    if (D_800B1D84 > cnt) {{ u32 __repair_value; __repair_value = cnt + 1; cnt = __repair_value; }
                        D_80107EA0 = cnt;
                        D_8010D538 = *(s32 *)((char *)D_80117728 + 0x74C) + (cnt << 6);
                        if ((rec->field_5C >> 23) & 2) {
                            func_800347B0(&D_80112F90, rec->field_30, rec->field_34, rec->field_38, rec->field_24 * 64.0f, rec->field_28 * 64.0f, rec->field_2C * 64.0f);
                        } else {
                            guTranslateF(&D_80112F90, rec->field_24 * 64.0f, rec->field_28 * 64.0f, rec->field_2C * 64.0f);
                        }
                        guMtxF2L(&D_80112F90, D_8010D538);
                        dl = D_80115328;
                        D_80115328 = dl + 1;
                        dl->w0 = 0xDA380003;
                        dl->w1 = D_8010D538 - 0x80000000;
                    } else {
                        break;
                    }
                } else {
                    dl = D_80115328;
                    D_80115328 = dl + 1;
                    dl->w0 = 0xDA380003;
                    dl->w1 = __repair_inline(*(s32 *)((char *)D_80117728 + 0x74C) - 0x80000000);
                }
                func_80032630(rec->field_3C);
                rec = rec->field_1C;
                if (rec == NULL) {
                    break;
                }
            }
        }
    }
}
