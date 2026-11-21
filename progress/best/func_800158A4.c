s32 Ray_CastObjects(s32 *, void *, f32 *, f32 *, f32 *, f32, s32, s32, s32);
f32 Vec3_DistanceSq(f32 *, f32 *);
s32 findActorCapsuleHit(void *, f32 *, f32 *, s32, f32 *, s32, s32, s32);
f32 func_80045764(f32 *, f32 *);
void *func_80047B44(void *, f32 *, f32 *, f32 *);
extern s32 func_8004D910;
extern u16 gSurfaceQueryStamp;
typedef struct { f32 x,y,z; } V3;
s32 func_800158A4(const void *a, const void *b, const void *c, void *out, s32 *hit, s32 flags, s32 mask, s32 mode, s32 arg8) {
 V3 hitPoint, zeroPoint, start, end, dir, nextPoint;
 f32 limit=65536.0f, distance;
 s32 result=0;
 void *obj=(void*)c, *saved=obj;
 gSurfaceQueryStamp++;
 start=*(V3*)a; end=*(V3*)b; zeroPoint.x=0.0f;
 if(saved==0){*(V3*)out=*(V3*)a; return 0;}
 while(1){
   dir.x=end.x-start.x; dir.y=end.y-start.y; dir.z=end.z-start.z;
   distance=func_80045764(&dir.x,&dir.x);
   if(*(u16*)((char*)obj+0x58)==0x46){
     if(Ray_CastObjects(&func_8004D910,obj,&start.x,&dir.x,&hitPoint.x,distance,flags,(s8)mode,arg8)!=0){limit=Vec3_DistanceSq(&start.x,&hitPoint.x);result=1;}
     if(mask && findActorCapsuleHit(obj,&start.x,&end.x,mask,&zeroPoint.x,0,0,arg8)!=0 && (result!=1 || Vec3_DistanceSq(&start.x,&zeroPoint.x)<limit)) result=2;
     if(result==1){*(V3*)out=hitPoint;} else if(result==2){*(V3*)out=zeroPoint;}
     if(hit) *hit=result;
     return 0;
   }
   obj=func_80047B44(obj,&start.x,&end.x,&nextPoint.x);
   saved=0;
   if(obj){start=nextPoint;saved=*(void**)((char*)obj+8);}
   if(!saved)return 1;
 }
}
