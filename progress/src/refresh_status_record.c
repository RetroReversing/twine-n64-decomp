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

s32 func_800261A4();
void *findEntryById();
s8 func_800263B8();
s32 func_8003099C();
s32 func_80030C58();
extern u8 D_800BD9CC;
extern u8 D_80102EE0;
extern u8 D_80102EE8;
extern void *D_80109BB0;
extern u8 D_80112F6E;
extern char D_801176C7[];

typedef struct { unsigned char pad_0[12]; unsigned short field_C; unsigned char pad_E[24]; signed char field_26; signed char field_27; unsigned char pad_28[12]; unsigned short field_34; unsigned char pad_36[24]; signed char field_4E; signed char field_4F; unsigned char pad_50[12]; unsigned short field_5C; unsigned char pad_5E[24]; signed char field_76; signed char field_77; } __repair_record_temp_s0;
/* Refreshes the status record at D_80109BB0+0x10: clears flag bits, reloads the per-slot indices, then applies the table-selected layout. */ void refresh_status_record(void) {
    u8 table_code;
    void *rec;
    void *rec_second;
    void *rec_third;

    func_8003099C(D_80102EE0, D_80102EE8);
    rec = findEntryById(M2C_FIELD(D_80109BB0, s32 *, 0x10), 0x72);
    D_800BD9CC = D_80102EE8;
    if (rec != NULL) {
        ((__repair_record_temp_s0*)rec)->field_C &= 0xFFF0;
        ((__repair_record_temp_s0*)rec)->field_34 &= 0xFFF0;
        ((__repair_record_temp_s0*)rec)->field_5C &= 0xFFF0;
        ((__repair_record_temp_s0*)rec)->field_27 = func_800263B8(M2C_FIELD(D_80109BB0, s32 *, 0x10), 0x73);
        ((__repair_record_temp_s0*)rec)->field_4F = func_800263B8(M2C_FIELD(D_80109BB0, s32 *, 0x10), 0x74);
        ((__repair_record_temp_s0*)rec)->field_77 = func_800263B8(M2C_FIELD(D_80109BB0, s32 *, 0x10), 0x72);
        ((__repair_record_temp_s0*)rec)->field_26 = func_800263B8(M2C_FIELD(D_80109BB0, s32 *, 0x10), 0x74);
        ((__repair_record_temp_s0*)rec)->field_4E = func_800263B8(M2C_FIELD(D_80109BB0, s32 *, 0x10), 0x72);
        ((__repair_record_temp_s0*)rec)->field_76 = func_800263B8(M2C_FIELD(D_80109BB0, s32 *, 0x10), 0x73);
        rec_second = rec + 0x28;
        rec_third = rec + 0x50;
        if ((func_80030C58() != 2) && (D_80112F6E == 0)) {
            table_code = *(D_801176C7 + (func_800261A4(func_80030C58()) & 0xFFFF));
            switch (table_code) {                      /* irregular */
            case 0:
                ((__repair_record_temp_s0*)rec)->field_27 = func_800263B8(M2C_FIELD(D_80109BB0, s32 *, 0x10), 0x72);
                ((__repair_record_temp_s0*)rec)->field_26 = func_800263B8(M2C_FIELD(D_80109BB0, s32 *, 0x10), 0x72);
                ((__repair_record_temp_s0*)rec)->field_34 |= 0xD;
                ((__repair_record_temp_s0*)rec)->field_5C |= 0xD;
                break;
            case 1:
                ((__repair_record_temp_s0*)rec)->field_27 = func_800263B8(M2C_FIELD(D_80109BB0, s32 *, 0x10), 0x73);
                ((__repair_record_temp_s0*)rec)->field_4F = func_800263B8(M2C_FIELD(D_80109BB0, s32 *, 0x10), 0x72);
                ((__repair_record_temp_s0*)rec)->field_26 = func_800263B8(M2C_FIELD(D_80109BB0, s32 *, 0x10), 0x73);
                ((__repair_record_temp_s0*)rec)->field_4E = func_800263B8(M2C_FIELD(D_80109BB0, s32 *, 0x10), 0x72);
                ((__repair_record_temp_s0*)rec)->field_5C |= 0xD;
                break;
            default:
                ((__repair_record_temp_s0*)rec)->field_27 = func_800263B8(M2C_FIELD(D_80109BB0, s32 *, 0x10), 0x73);
                M2C_FIELD(rec_second, s8 *, 0x27) = func_800263B8(M2C_FIELD(D_80109BB0, s32 *, 0x10), 0x74);
                M2C_FIELD(rec_third, s8 *, 0x27) = func_800263B8(M2C_FIELD(D_80109BB0, s32 *, 0x10), 0x72);
                ((__repair_record_temp_s0*)rec)->field_26 = func_800263B8(M2C_FIELD(D_80109BB0, s32 *, 0x10), 0x74);
                M2C_FIELD(rec_second, s8 *, 0x26) = func_800263B8(M2C_FIELD(D_80109BB0, s32 *, 0x10), 0x72);
                M2C_FIELD(rec_third, s8 *, 0x26) = func_800263B8(M2C_FIELD(D_80109BB0, s32 *, 0x10), 0x73);
                break;
            }
            D_800BD9CC = *(D_801176C7 + (func_800261A4(func_80030C58()) & 0xFFFF));
        }
    }
}
