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

s32 releaseCountedEntry();
s32 releaseSceneGroupRef();
s32 releaseSortedEntry();
s32 func_80097B1C();
s32 func_80097E14();
s32 func_8009811C();
extern u8 gWorkerThreadActive;
extern s16 sSceneGroupStackCount;
extern char sSceneGroupStack[];

/* A scene group record: offsets to five ID lists (each 0xFFFF-terminated) plus a flag and an argument for func_80097E14. */
typedef struct { unsigned char pad_0[4]; unsigned short argument; unsigned short flag; int listOffsetA; int listOffsetB; int listOffsetC; int listOffsetD; int listOffsetE; } SceneGroupRecord;

/* Pops the newest scene group and unloads its ID lists; returns 1 if the group also needs its final unload call, else 0. */
s32 popAndUnloadSceneGroup(void) {
    s16 stackTop;
    s32 result;
    u16 *listB;
    char *cursor;
    char *cursorB;
    char *cursorC;
    char *cursorD;
    char *cursorE;
    u16 idB;
    u16 idA;
    u16 idC;
    u16 idD;
    u16 idE;
    void *group;
    void *groupEnd;
    void *groupC;
    void *groupD;
    void *groupE;
    void *groupB;

    if ((gWorkerThreadActive != 0) && (sSceneGroupStackCount != 0)) {
        stackTop = sSceneGroupStackCount - 1;
        group = *((s32 *)((s8 *)sSceneGroupStack + ((s32) (stackTop << 0x10) >> 0xE)));
        sSceneGroupStackCount = stackTop;
        groupEnd = (void *)(((SceneGroupRecord*)group)->listOffsetA); groupEnd = (void *)((char *)groupEnd + (s32)(group));
        groupEnd = (char *)groupEnd + 8;
        cursor = groupEnd;
        while ((idA = *(u16 *)cursor) != 0xFFFF) {
            cursor += 2;
            func_8009811C(idA);
        }
        groupB = (void *) ((((SceneGroupRecord*)group)->listOffsetB) + (s32) group);
        listB = groupB;
        listB += 4;
        cursorB = listB;
        while (*(u16 *)cursorB != 0xFFFF) {
            cursorB += 2;
        }
        cursorB = cursorB - 2;
        if ((u32) cursorB >= (u32) listB) {
            do {
                idB = *(u16 *)cursorB;
                cursorB -= 2;
                func_80097B1C(idB);
            } while ((u32) cursorB >= (u32) listB);
        }
        groupC = (void *)(((SceneGroupRecord*)group)->listOffsetC); groupC = (void *)((char *)groupC + (s32)(group));
        groupC = (char *)groupC + 8;
        cursorC = groupC;
        while ((idC = *(u16 *)cursorC) != 0xFFFF) {
            cursorC += 2;
            releaseSortedEntry(idC);
        }
        groupD = (void *) ((((SceneGroupRecord*)group)->listOffsetD) + (s32) group);
        groupD = (char *)groupD + 8;
        cursorD = groupD;
        while ((idD = *(u16 *)cursorD) != 0xFFFF) {
            cursorD += 2;
            releaseCountedEntry(idD);
        }
        groupE = (void *) ((((SceneGroupRecord*)group)->listOffsetE) + (s32) group);
        groupE = (char *)groupE + 8;
        cursorE = groupE;
        while ((idE = *(u16 *)cursorE) != 0xFFFF) {
            cursorE += 2;
            releaseSceneGroupRef(idE);
        }
        result = 1;
        if (((SceneGroupRecord*)group)->flag == 1) {
            func_80097E14(((SceneGroupRecord*)group)->argument);
            return 1;
        }
        /* Duplicate return node #21. Try simplifying control flow for better match */
        return result;
    }
    result = 0;
    return result;
}
