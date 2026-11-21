extern s32 gSaveTotalSlots, gTrackMarkerSerial;
extern void *gBonusObjects[], *gTrackMarkerTable[];
extern char D_8011F3AC[];
void requestSound(s32);
void func_8002B150(void *,s32,s32);
s32 lookupDataEntry(s32);
void func_80073AF8(s32,void *,s32,s32,s32,s32,s32,s32,s32,s32,s32);
void func_8007089C(void *,s32,s32);
/* Starts a bonus-scene actor: plays the start sound, picks the slot layout from the saved slot count, and sets its timers */ void startBonusSceneActor(void *actor) {
 void *sceneHandle = gBonusObjects[*(s8*)((char*)actor+0x182)];
 s32 markerEntry;
 requestSound(0x224);
 switch(gSaveTotalSlots) {
 default: func_8002B150(D_8011F3AC,1,0); break;
 case 3: func_8002B150(D_8011F3AC,2,0); break;
 case 4: func_8002B150(D_8011F3AC,3,0); break;
 case 5: func_8002B150(D_8011F3AC,3,30); break;
 case 6: func_8002B150(D_8011F3AC,4,0); break;
 case 7: func_8002B150(D_8011F3AC,4,30); break;
 case 8: func_8002B150(D_8011F3AC,5,0); break;
 }
 *(s8*)((char*)actor+0x32c)=1;
 gTrackMarkerSerial++;
 markerEntry=lookupDataEntry(0x6026);
 func_80073AF8(0,gTrackMarkerTable[*(s8*)((char*)actor+0x183)],markerEntry,-1,-1,1,0,0,0,0,0);
 *(s16*)((char*)actor+0x1d8)=500;
 *(s8*)((char*)actor+0x32f)=5;
 func_8007089C(sceneHandle,0,0x26);
}
