#define F(p,t,o) (*(t *)((s8 *)(p)+(o)))
extern f32 sTrackMarkerScale;
extern void *gTrackMarkerParents;
void computeTrackMarkerScale(void) {
 f32 a=99999.0f,b=-99999.0f,c=99999.0f,d=-99999.0f,x,y; void *p=*(void **)F(gTrackMarkerParents,void *,8),*q;
 while(p) { if(F(p,u16,0x58)==0x46) { q=F(p,void *,0x3c); x=F(q,f32,0x1c); if(d<x)d=x; x=F(q,f32,0x2c); if(b<x)b=x; x=F(q,f32,0x18); if(x<c)c=x; x=F(q,f32,0x28); if(x<a)a=x; } p=F(p,void *,0x10); }
 d-=c; b-=a; if(b<d)sTrackMarkerScale=d; else sTrackMarkerScale=b; sTrackMarkerScale*=0.75f;
}
