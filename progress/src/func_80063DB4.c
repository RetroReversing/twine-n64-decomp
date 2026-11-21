typedef struct { s32 x,y,z; } Vec;
#define V(p,o) (*(Vec *)((s8 *)(p)+(o)))
#define P(p,o) (*(void **)((s8 *)(p)+(o)))
#define B(p,o) (*(s8 *)((s8 *)(p)+(o)))
extern s32 *gProbeObjectList;
extern s32 D_801002E0, D_80102F3C;
extern Vec D_80108608[], D_80110B28[];
extern void *gTrackMarkerTable[];
void func_80016718(void *);
void actorLinkToSurface();
void func_800635B4(void *, s16);
void func_80063DB4(void *a) {
void *s=P(a,0x6c),*v; s32 i,off,n; volatile u32 frame[2];
func_80016718(a); v=gTrackMarkerTable[B(s,0x182)];
V(a,0x24)=D_80110B28[D_80102F3C]; V(a,0x30)=V(a,0x24); V(v,0x10)=V(a,0x30); V(v,0x28)=V(v,0x10);
i=0; {void *p=P(a,0x68); if(B(p,0xb3)>0){off=0;do{
*(f32 *)((u32)off+(u32)P(p,0))=*(f32 *)((s8 *)a+0x24);
*(f32 *)((u32)off+(u32)P(P(a,0x68),0)+4)=*(f32 *)((s8 *)a+0x28);
*(f32 *)((u32)off+(u32)P(P(a,0x68),0)+8)=*(f32 *)((s8 *)a+0x2c);
*(f32 *)((u32)off+(u32)P(P(a,0x68),4))=*(f32 *)((s8 *)a+0x24);
*(f32 *)((u32)off+(u32)P(P(a,0x68),4)+4)=*(f32 *)((s8 *)a+0x28);
*(f32 *)((u32)off+(u32)P(P(a,0x68),4)+8)=*(f32 *)((s8 *)a+0x2c);
i++;off+=12;
}while(i<B((p=P(a,0x68)),0xb3));}}
V(a,0x3c)=D_80108608[D_80102F3C]; V(a,0x48)=V(a,0x3c);
actorLinkToSurface(*gProbeObjectList,a,0);
n=++D_80102F3C;if(n==D_801002E0)D_80102F3C=0;
*(s32 *)((s8 *)gTrackMarkerTable[B(s,0x182)]+0xf4)=*(s32 *)((s8 *)a+0x20);
func_800635B4(a,0);
}
