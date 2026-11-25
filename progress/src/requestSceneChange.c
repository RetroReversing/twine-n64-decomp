extern s8 gNextSceneId, D_800CA310;
extern s32 gSceneChangePending, gSceneLoaded;
void resetSlotsAndRefreshAll(void);
/* Refreshes hiscores and flags a scene change, marking the current scene unloaded. */
void requestSceneChange(s8 nextSceneId, s32 arg1) { resetSlotsAndRefreshAll(); gNextSceneId=nextSceneId; gSceneChangePending=1; gSceneLoaded=0; D_800CA310=0; }
