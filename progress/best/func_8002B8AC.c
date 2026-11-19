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

s32 func_80044538();
extern u16 D_800BF680;
extern char D_800C3CF8[];
extern u16 *D_80102F40;

typedef struct { unsigned char pad_0[5]; unsigned char field_5; unsigned short field_6; unsigned char pad_8[4]; unsigned short field_C; } __repair_record_D_80102F40;
void func_8002B8AC(void) {
    D_80102F40 = &D_800BF680;
    if (D_800BF680 != 0) {
        __repair_rows: {
            if (((__repair_record_D_80102F40*)D_80102F40)->field_6 & 1) {
                func_80044538(*(s32 *)*(s32 *)(D_800C3CF8 + (((__repair_record_D_80102F40*)D_80102F40)->field_5 * 0xC)));
            }
            D_80102F40 += 0xC;
        }
if (((__repair_record_D_80102F40*)D_80102F40)->field_C != 0) goto __repair_rows;
    }
}
