extern void *gBonusObjects[], *gTrackMarkers[];
extern int gSaveTotalSlots, gTrackMarkerSerial;
extern char D_8011F3AC[];
extern void requestSound(int);
extern void func_8002B150(char *, int, int);
extern void *lookupDataEntry(int);
extern void func_80073AF8(int, void *, void *, int, int, int, int, int, int, int, int);
extern void func_8007089C(void *, int, int);
void startBonusSceneActor(TwineSlotEventActor *a) {
 void *obj = gBonusObjects[a->index];
 void *data;
 requestSound(0x224);
 switch (gSaveTotalSlots) {
 default: func_8002B150(D_8011F3AC,1,0); break;
 case 3: func_8002B150(D_8011F3AC,2,0); break;
 case 4: func_8002B150(D_8011F3AC,3,0); break;
 case 5: func_8002B150(D_8011F3AC,3,30); break;
 case 6: func_8002B150(D_8011F3AC,4,0); break;
 case 7: func_8002B150(D_8011F3AC,4,30); break;
 case 8: func_8002B150(D_8011F3AC,5,0); break;
 }
 *((u8 *)a+0x32c)=1;
 gTrackMarkerSerial++;
 data=lookupDataEntry(0x6026);
 func_80073AF8(0,gTrackMarkers[*((s8 *)a+0x183)],data,-1,-1,1,0,0,0,0,0);
 *((s16 *)((u8 *)a+0x1d8))=500;
 *((u8 *)a+0x32f)=5;
 func_8007089C(obj,0,0x26);
}
