typedef struct Rec { unsigned short id; char pad[3]; unsigned char type; char rest[6]; } Rec;
extern Rec gSpawnTable[];
extern Rec *gCurrentSpawnRecordPtr;
/* Scans gSpawnTable (terminated by id 0) for the first record with the given type; returns it or NULL. */ int findRecordByType(int wantedType) {
    gCurrentSpawnRecordPtr = gSpawnTable;
    while (gCurrentSpawnRecordPtr->id != 0) {
        if (gCurrentSpawnRecordPtr->type == wantedType) break;
        gCurrentSpawnRecordPtr++;
    }
    return (int)gCurrentSpawnRecordPtr & -(gCurrentSpawnRecordPtr->id != 0);
}
