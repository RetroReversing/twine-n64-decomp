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

s32 initTextFromTemplate();
s32 func_800283B0();
s32 func_8002B02C();
s32 func_8002B050();
s32 func_8002B150();
s32 func_8002EFD8();
s32 func_8002F068();
s32 func_8002F240();
s32 func_8002F2EC();
s32 updateObjectFade();
s32 func_8002F560();
s32 func_8002F718();
s32 func_8002FBD4();
s32 func_8003099C();
s32 func_80081730();
s32 func_80087E74();
extern u16 D_800BFC92;
extern char D_800BFD08[];
extern s32 D_800BFD74;
extern s8 D_800CEEB1;
extern char D_800E1584[];
extern u8 D_80102EDC;
extern u8 D_80102EE0;
extern u8 sDifficultyLevel;
extern char D_80102EFC[];

typedef struct { s32 w[4]; } __repair_words4;
void func_8002F868(void *arg0, void *arg1) {
    char *__base_D_800BFD08;
    s16 temp_v1;
    char *var_a2;
    char *var_a3;
    u16 temp_v1_2;
    void *temp_t0;

    func_8002F718();
    temp_v1 = M2C_FIELD(arg1, const s16 *, 0x7A);
    switch (temp_v1) {
    case 0:
        func_8002EFD8(arg0, arg1);
        func_8002F2EC(arg0, arg1);
        return;
    case 5:
        func_8002F068(arg0, arg1);
        func_8002F2EC(arg0, arg1);
        return;
    case 6:
        if (updateObjectFade(arg0) & 0xFF) {
            func_8002FBD4(arg1, 4);
        } else {
        default:
        tail:
        }
        func_8002F2EC(arg0, arg1);
        return;
    case 4:
        updateObjectFade(arg0);
        if (D_80102EDC != 0) {
            func_8002B050(D_800E1584, 1);
        }
        if (!(func_80081730() & 0xFFFF)) {
            goto tail;
        }
        goto block_19;
    case 3:
        func_8002FBD4(arg1, 1);
        func_8002F2EC(arg0, arg1);
        return;
    case 1:
        if (func_8002F560(arg0) & 0xFF) {
            func_8002FBD4(arg1, 2);
        }
        func_8002F2EC(arg0, arg1);
        return;
    case 7:
        if (func_8002F560(arg0) & 0xFF) {
            var_a3 = &D_800BFD74;
            temp_v1_2 = D_800BFC92 + 1;
            __base_D_800BFD08 = D_800BFD08;
            var_a2 = ((temp_v1_2 & 1) * 0x24) + __base_D_800BFD08;
            temp_t0 = var_a2 + 0x20;
            D_800BFC92 = temp_v1_2;
            do {
                M2C_FIELD(var_a3, __repair_words4 *, 0x0) = *(__repair_words4 *) ((s8 *) var_a2 + 0x0);
                var_a2 += 0x10;
                var_a3 += 0x10;
            } while (var_a2 != temp_t0);
            *(s32 *)var_a3 = *(s32 *)var_a2;
            D_800BFC92 += 1;
            initTextFromTemplate(M2C_FIELD(arg0, const s32 *, 0x2C), &D_800BFD74, var_a2, var_a3);
            func_8002FBD4(arg1, 0);
        }
        func_8002F2EC(arg0, arg1);
        return;
    case 8:
        func_8002F240(arg0, arg1);
        func_8002F2EC(arg0, arg1);
        return;
    case 9:
        updateObjectFade(arg0);
block_19:
        func_8002B150(D_800E1584, 0, 0);
        func_8002F2EC(arg0, arg1);
        return;
    case 11:
        if (func_8002F560(arg0) & 0xFF) {
            func_8002B02C(D_80102EFC);
            func_800283B0();
            D_800CEEB1 = 2;
            func_80087E74();
            func_8003099C(D_80102EE0, sDifficultyLevel);
            return;
        }
        func_8002F2EC(arg0, arg1);
        return;
    }
}


