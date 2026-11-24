extern void evalCatmullRomVec3(void *, void *, void *, void *, f32, void *);
extern s32 gZeroVec3, gCatmullRomResult;
/* Samples a Catmull-Rom path of 12-byte vec3 points at normalized progress 0..1; returns the result vector. */ s32 *sampleCatmullRomPath(f32 progress, s32 pointCount, char *points) {
 f32 segmentCount; s32 segment;
 if (pointCount-3 <= 0) return &gZeroVec3;
 segmentCount=0.0f;
 if (progress < 0.0f) progress=segmentCount;
 else {
   segmentCount=(f32)(pointCount-3);
   if (progress > 1.0f) progress=segmentCount;
   else progress=progress*segmentCount;
 }
 segment=(s32)progress;
 if (segment>=pointCount-3) segment=pointCount-3;
 progress -= (f32)segment;
 points += segment*12;
 evalCatmullRomVec3(points,points+12,points+24,points+36,progress,&gCatmullRomResult);
 return &gCatmullRomResult;
}
