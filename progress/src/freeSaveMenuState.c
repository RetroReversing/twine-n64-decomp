#ifndef M2C_DEFINES
#define M2C_DEFINES
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define M2C_CARRY 0
#define M2C_OVERFLOW(a) (0)
#endif
void freeMenuItemRecord(void *);
void func_80022BB8(void);
void func_8002EB34(void *);
extern void *gSaveMenuState;
typedef struct { u8 pad[8]; void *value; } Record;
void freeSaveMenuState(void) {
    void *a;
    void *b;
    s32 i;
    u8 count;
    void *record;
    void (*callback)(void);
    if (gSaveMenuState != NULL) {
        func_8002EB34(M2C_FIELD(gSaveMenuState, void **, 0x20));
        M2C_FIELD(gSaveMenuState, void **, 0x20) = NULL;
        freeMenuItemRecord(M2C_FIELD(gSaveMenuState, void **, 0x24));
        M2C_FIELD(gSaveMenuState, void **, 0x24) = NULL;
        freeMenuItemRecord(M2C_FIELD(gSaveMenuState, void **, 0x1C));
        M2C_FIELD(gSaveMenuState, void **, 0x1C) = NULL;
        freeMenuItemRecord(M2C_FIELD(gSaveMenuState, void **, 0));
        b = M2C_FIELD(gSaveMenuState, void **, 0x10);
        M2C_FIELD(gSaveMenuState, void **, 0) = NULL;
        if (b != NULL) {
            callback = M2C_FIELD(b, void (**)(void), 0xC);
            if (callback != NULL) callback();
            a = gSaveMenuState;
            i = 0;
            count = M2C_FIELD(M2C_FIELD(a, void **, 0x10), u8 *, 5);
            if (count != 0) {
                do {
                    record = (void *)((s8 *)M2C_FIELD(M2C_FIELD(a, void **, 0x10), void **, 0) + ((i & 0xFF) * 0x28));
                    freeMenuItemRecord(((Record *)record)->value);
                    ((Record *)record)->value = NULL;
                    i++;
                    a = gSaveMenuState;
                    count = M2C_FIELD(M2C_FIELD(a, void **, 0x10), u8 *, 5);
                } while ((u32)(i & 0xFF) < count);
            }
        }
        func_80022BB8();
    }
}
