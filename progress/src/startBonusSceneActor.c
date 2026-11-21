extern void *gBonusObjects[], *gTrackMarkers[];
extern int gSaveTotalSlots, gTrackMarkerSerial;
extern char sMenuCountdown[];
extern void requestSound(int);
extern void func_8002B150(char *, int, int);
extern void *lookupDataEntry(int);
extern void func_80073AF8(int, void *, void *, int, int, int, int, int, int, int, int);
extern void func_8007089C(void *, int, int);
/* Starts the bonus scene for an actor: plays the scene sound, picks a text line from the total slot count, and arms the actor's timers. */ void startBonusSceneActor(TwineSlotEventActor *actor) {
 void *bonusObj = gBonusObjects[actor->index];
 void *sceneData;
 requestSound(0x224);
 switch (gSaveTotalSlots) {
 default: func_8002B150(sMenuCountdown,1,0); break;
 case 3: func_8002B150(sMenuCountdown,2,0); break;
 case 4: func_8002B150(sMenuCountdown,3,0); break;
 case 5: func_8002B150(sMenuCountdown,3,30); break;
 case 6: func_8002B150(sMenuCountdown,4,0); break;
 case 7: func_8002B150(sMenuCountdown,4,30); break;
 case 8: func_8002B150(sMenuCountdown,5,0); break;
 }
 *((u8 *)actor+0x32c)=1;
 gTrackMarkerSerial++;
 sceneData=lookupDataEntry(0x6026);
 func_80073AF8(0,gTrackMarkers[*((s8 *)actor+0x183)],sceneData,-1,-1,1,0,0,0,0,0);
 *((s16 *)((u8 *)actor+0x1d8))=500;
 *((u8 *)actor+0x32f)=5;
 func_8007089C(bonusObj,0,0x26);
}
