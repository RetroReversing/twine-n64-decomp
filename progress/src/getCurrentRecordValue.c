void *findRecordByType(void); extern s32 gCurrentSpawnRecordPtr;
/* Finds the current record and returns its u16 field at +2, or 100 if none is found. */ s32 getCurrentRecordValue(void) { f32 valueF; register long value; register unsigned long result; void *record;
record=findRecordByType(); gCurrentSpawnRecordPtr=(s32)record;
if(record!=NULL){valueF=(f32)(*(u16*)((char*)record+2));value=(u16)valueF;result=value;}else result=0x64; return result;}
