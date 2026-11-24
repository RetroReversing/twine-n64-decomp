void playMidMarkerSound(void);
void playRandomAmbientSoundNearTrackMarker(void);
void playRandomMarkerPannedSound(void);
void playRandomAmbientSoundAtNearestMarker(void);
void playRandomSoundNearTrackMarkerB(void);
void playMarkerSoundAtNearestMarkerActor(void);
void emptyStubC(void);

/* Calls the handler for the given state (1-9); unknown states use the state 1 handler. */ void dispatchStateHandler(s32 arg0, s32 state) {
    switch (state) {
    default:
    case 1:
    case 9:
        playMidMarkerSound();
        break;
    case 2:
        playRandomAmbientSoundNearTrackMarker();
        break;
    case 3:
        playRandomMarkerPannedSound();
        break;
    case 4:
    case 8:
        playRandomAmbientSoundAtNearestMarker();
        break;
    case 5:
        playRandomSoundNearTrackMarkerB();
        break;
    case 6:
        playMarkerSoundAtNearestMarkerActor();
        break;
    case 7:
        emptyStubC();
        break;
    }
}
