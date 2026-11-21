extern u16 D_800BFC92;
extern s16 D_800BFCBC;
extern s16 D_800BFCE0;
extern s16 D_800BFD04;
extern char D_800BFD08[];
extern s16 D_800BFD70;
extern s32 D_800BFD74;
extern s16 D_800BFD94;
extern s16 D_800BFDB8;
extern s16 D_800BFDDC;
extern char D_800E1584[];
extern char sMenuAnimSlots[];
extern u8 gPendingMenuCommand;
extern char gTrackMarkers[];

/* Spawns the per-track HUD object: a 0x48-byte effect with nine timed text slots, a marker child and a sound cue. */
typedef struct {
    void *titleNode;
    void *slots[9];
    s32 timer;
    void *counterNode;
    void *markerObj;
    void *valueNode;
    void *subtitleNode;
    void *lapNode;
    s16 offsetX;
    s16 offsetY;
    s16 trackId;
} TrackHudState;

void *spawnTrackHudObject(s32 trackIndex) {
    s16 *argsBase;
    char *descriptorTable;
    char *descriptorSrc;
    char *descriptorDst;
    char *descriptorArg;
    s32 slotOffset;
    s32 brightness;
    void *slotEntry;
    void *node;
    s32 trackIdx;
    void *textNode;
    void *objState;
    void *obj;
    void *markerObj;
    void *slotPtr;
    s32 glyphBuf;
    u16 i;
    s32 slot;

    obj = spawnEffectObject(0x48, 0, 0);
    if (obj == NULL) {
        return NULL;
    }
    (*(s16 *)((char *)(obj) + 0x78)) = 0x39;
    (*(s16 *)((char *)(obj) + 0x7A)) = (s16) ((gPendingMenuCommand != 0) * 4);
    func_8000A310();
    func_8000A5D0(0xC);
    do { func_80064318(obj, trackIndex & 0xFFFF); } while (0);
    objState = (*(void **)((char *)(obj) + 0x6C));
    (((TrackHudState *)objState)->titleNode) = NULL;
    (((TrackHudState *)objState)->markerObj) = NULL;
    (((TrackHudState *)objState)->timer) = 0;
    (((TrackHudState *)objState)->counterNode) = NULL;
    (((TrackHudState *)objState)->trackId) = trackIndex;
    (((TrackHudState *)objState)->valueNode) = NULL;
    (((TrackHudState *)objState)->offsetX) = 0;
    (((TrackHudState *)objState)->offsetY) = 0;
    (((TrackHudState *)objState)->subtitleNode) = NULL;
    (((TrackHudState *)objState)->lapNode) = NULL;
    {
        s16 *argsIndex = &D_800BFDDC;
        *argsIndex = trackIndex;
        (((TrackHudState *)objState)->lapNode) = spawnTextNode((char *)argsIndex - 0x20);
    }
    descriptorDst = (char *)&D_800BFD74;
    D_800BFD70 = trackIndex;
    descriptorTable = D_800BFD08;
    descriptorSrc = (void *) ((((D_800BFC92 & 1) * 0x24)) + (s32) descriptorTable);
    {
        typedef struct { u32 words[9]; } MenuDescriptor;
        *(MenuDescriptor *)descriptorDst = *(MenuDescriptor *)descriptorSrc;
    }
    {
        s16 *descriptorMode = &D_800BFD94;
        *descriptorMode = trackIndex;
        D_800BFDB8 = trackIndex;
        D_800BFC92 += 1;
        descriptorArg = (char *)descriptorMode - 0x20;
        if (gPendingMenuCommand != 0) {
            descriptorArg = (char *)descriptorMode + 4;
        }
    }
    (((TrackHudState *)objState)->counterNode) = spawnTextNode(descriptorArg);
    {
        s16 *argsIndex = &D_800BFD04;
        *argsIndex = trackIndex;
        textNode = spawnTextNode((char *)argsIndex - 0x20);
    }
    (((TrackHudState *)objState)->valueNode) = textNode;
    glyphBuf = (*(s32 *)((char *)(textNode) + 8));
    if (glyphBuf != 0) {
        memset(glyphBuf, 0, (*(u16 *)((char *)(textNode) + 0x24)) * (*(u8 *)((char *)(textNode) + 0x28)));
    }
    {
        for (i = 0; i < 9; i++) {
            textNode = spawnTrackMarker(trackIndex & 0xFFFF);
            slot = i;
            slotPtr = (void *) (((slot * 4)) + (s32) objState);
            (*(void **)((char *)(slotPtr) + 4)) = textNode;
            if (textNode != NULL) {
            (*(void **)((char *)(textNode) + 0x18)) = (void *) ((slot * 0xC) + sMenuAnimSlots);
            (*(s16 *)((char *)((*(void **)((char *)(slotPtr) + 4))) + 0x1C)) = 0xB;
            node = (*(void **)((char *)(slotPtr) + 4));
            (*(s32 *)((char *)(node) + 0x28)) = (s32) (((*(s32 *)((char *)(node) + 0x28)) & ~0xFC) | 0x14);
            node = (*(void **)((char *)(slotPtr) + 4));
            brightness = 0x100 - (slot * slot * 2);
            if (brightness >= 0) {
            if (brightness < 0x100) {
            (*(s32 *)((char *)(node) + 0x10)) = (s32) ((brightness << 8) | 0x800000);
            } else {
            (*(s32 *)((char *)(node) + 0x10)) = 0x80FF00;
            }
            } else {
            (*(s32 *)((char *)(node) + 0x10)) = 0x800000;
            }
            slotPtr = (void *) i;
            slotOffset = (s32) slotPtr * 4;
            slotEntry = (void *) ((slotOffset) + (s32) objState);
            (*(s16 *)((char *)((*(void **)((char *)(slotEntry) + 4))) + 0x1E)) = 0x40;
            (*(s16 *)((char *)((*(void **)((char *)(slotEntry) + 4))) + 0x20)) = 0xF0;
            (*(s16 *)((char *)((*(void **)((char *)(slotEntry) + 4))) + 0x22)) = (s16) (((s32) ((s32)slotPtr * 5) * 2) + 0x28);
            }
            fillRandomCodeString((i * 0xC) + sMenuAnimSlots, 0xB, (s32) slotPtr);
        }
    }
    argsBase = &D_800BFCBC;
    (*argsBase) = (s32)trackIndex;
    (((TrackHudState *)objState)->titleNode) = spawnTextNode((char *)argsBase - 0x20);
    markerObj = spawnEffectObject(0, 0, 0);
    (((TrackHudState *)objState)->markerObj) = markerObj;
    if (markerObj != NULL) {
        (*(s16 *)((char *)(markerObj) + 0x78)) = 0x1F;
        (*(s16 *)((char *)((((TrackHudState *)objState)->markerObj)) + 0x7A)) = 0;
        (*(f32 *)((char *)((((TrackHudState *)objState)->markerObj)) + 0x24)) = 4.1f;
        (*(f32 *)((char *)((((TrackHudState *)objState)->markerObj)) + 0x28)) = -3.5f;
        (*(f32 *)((char *)((((TrackHudState *)objState)->markerObj)) + 0x2C)) = -9.0f;
        (*(f32 *)((char *)((((TrackHudState *)objState)->markerObj)) + 0x44)) = -284.44446f;
        (*(s8 *)((char *)((((TrackHudState *)objState)->markerObj)) + 0x7F)) = 0;
        (*(s8 *)((char *)((((TrackHudState *)objState)->markerObj)) + 0x80)) = 0;
        (*(s8 *)((char *)((((TrackHudState *)objState)->markerObj)) + 0x81)) = 0;
        (*(f32 *)((char *)((((TrackHudState *)objState)->markerObj)) + 0x54)) = 0.95f;
        effectSetAnimFrame((((TrackHudState *)objState)->markerObj), 2, 0x24);
        trackIdx = trackIndex & 0xFFFF;
        func_80064318((((TrackHudState *)objState)->markerObj), trackIdx);
        objectListInsert((((TrackHudState *)objState)->markerObj), (*(s32 *)((char *)(*(s32 *)(gTrackMarkers + (trackIdx * 4))) + 0xF4)));
        {
            s16 *argsIndex = &D_800BFCE0;
            *argsIndex = trackIndex;
            (((TrackHudState *)objState)->subtitleNode) = spawnTextNode((char *)argsIndex - 0x20);
        }
        func_8002B000(D_800E1584, 0x1E);
    }
    return obj;
}
