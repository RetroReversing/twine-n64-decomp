extern s32 allocTextNodeObject();
extern s32 linkNodeAfter(s32, s32);
extern s32 gTrackMarkerParents[];
/* Allocates a text node object and links it after the parent node for the given marker index; returns 0 on failure. */ s32 spawnTrackMarker(s32 markerIndex) {
 s32 marker = allocTextNodeObject();
 if (marker == 0) return 0;
 linkNodeAfter(marker, gTrackMarkerParents[markerIndex]);
 return marker;
}
