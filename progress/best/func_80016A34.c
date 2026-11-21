extern int Probe_BoundsContainPoint(void *, int);
extern int actorLinkToSurface(void *, void *, unsigned char);
extern void actorUnlinkFromSurface(void *);
extern void *func_80047B44(int, void *, void *, int);
extern int func_80073304(void *, void *, int);
extern void markObjectsNearPos(void **, int, int, void *, float, int);
extern void objectListInsert(void *, void *);
extern void **gProbeObjectList;
extern unsigned char gTrackMarkerDone[];
struct V3 { int x,y,z; };
void func_80016A34(void *arg0) {
 int temp_s0, temp_s0_2;
 unsigned short temp_v1_2,temp_v1_3;
 unsigned char temp_v0_2,temp_v1;
 void *temp_s2,*temp_v0;
 temp_s2=(char *)arg0+0x24;
 temp_v0=func_80047B44(*(int *)((char *)arg0+0x20),(char *)arg0+0x30,temp_s2,0);
 if(temp_v0) {
  if(*(unsigned short *)((char *)temp_v0+0x26)&0x1000) {
   markObjectsNearPos((void **)*(int *)((char *)arg0+0x20),2,0x20000,temp_s2,0.0f,1);
   func_80073304(temp_v0,temp_s2,*(int *)((char *)arg0+0x20));
  }
  if(*(unsigned short *)((char *)arg0+0x78)==2 &&
     ((temp_v0_2=*((unsigned char *)temp_v0+0x29))==0 || gTrackMarkerDone[temp_v0_2]!=0)) {
   temp_v1=*((unsigned char *)temp_v0+0x28);
   if(temp_v1) gTrackMarkerDone[temp_v1]=1;
  }
  temp_s0=*(int *)((char *)temp_v0+8);
  actorUnlinkFromSurface(arg0);
  objectListInsert(arg0,(void *)temp_s0);
  *(int *)((char *)arg0+0x20)=temp_s0;
  *(int *)((char *)arg0+0x60)|=0x400;
  goto block_36;
 }
 temp_s0_2=*(int *)((char *)arg0+0x20);
 if(!temp_s0_2) {
  temp_v1_2=*(unsigned short *)((char *)arg0+0x78);
  if(temp_v1_2!=0x1f && temp_v1_2!=0x46) goto finish;
  goto block_39;
 } else if((Probe_BoundsContainPoint(temp_s2,temp_s0_2)<<24)==0) {
  actorUnlinkFromSurface(arg0);
  temp_v1_3=*(unsigned short *)((char *)arg0+0x78);
  if(temp_v1_3<8) {
   switch(temp_v1_3) {
   case 0:
    if((actorLinkToSurface(*gProbeObjectList,arg0,0)<<24)==0) goto block_38;
    goto block_36;
   }
  } else {
   switch(temp_v1_3) {
   case 0x24:
    if((actorLinkToSurface(*gProbeObjectList,arg0,0)<<24)==0) {
     *(int *)((char *)arg0+0x24)=*(int *)((char *)arg0+0x30);
     *(int *)((char *)arg0+0x28)=*(int *)((char *)arg0+0x34);
     *(int *)((char *)arg0+0x2c)=*(int *)((char *)arg0+0x38);
     *(int *)((char *)arg0+0x3c)=*(int *)((char *)arg0+0x48);
     *(int *)((char *)arg0+0x40)=*(int *)((char *)arg0+0x4c);
     *(int *)((char *)arg0+0x44)=*(int *)((char *)arg0+0x50);
block_38:
     objectListInsert(arg0,(void *)temp_s0_2);
    } else goto block_36;
    break;
   case 0x4c:
   case 1:
    if(!(*(int *)((char *)arg0+0x58)&0x80000)) {
     *(int *)((char *)arg0+0x24)=*(int *)((char *)arg0+0x30);
     *(int *)((char *)arg0+0x28)=*(int *)((char *)arg0+0x34);
     *(int *)((char *)arg0+0x2c)=*(int *)((char *)arg0+0x38);
     *(int *)((char *)arg0+0x3c)=*(int *)((char *)arg0+0x48);
     *(int *)((char *)arg0+0x40)=*(int *)((char *)arg0+0x4c);
     *(int *)((char *)arg0+0x44)=*(int *)((char *)arg0+0x50);
     goto block_38;
    }
block_34:
    if((actorLinkToSurface(*gProbeObjectList,arg0,0)<<24)==0) objectListInsert(arg0,(void *)temp_s0_2);
    goto block_36;
   case 0x4d:
   case 0x61:
    if(*(int *)((char *)arg0+0x58)&0x80000) goto block_34;
    *(int *)((char *)arg0+0x24)=*(int *)((char *)arg0+0x30);
    *(int *)((char *)arg0+0x28)=*(int *)((char *)arg0+0x34);
    *(int *)((char *)arg0+0x2c)=*(int *)((char *)arg0+0x38);
    *(int *)((char *)arg0+0x3c)=*(int *)((char *)arg0+0x48);
    *(int *)((char *)arg0+0x40)=*(int *)((char *)arg0+0x4c);
    *(int *)((char *)arg0+0x44)=*(int *)((char *)arg0+0x50);
    if((Probe_BoundsContainPoint((char *)arg0+0x24,temp_s0_2)<<24)!=0) goto block_38;
block_39:
    actorLinkToSurface(*gProbeObjectList,arg0,0);
    break;
   }
  }
 } else {
block_36:
  *(int *)((char *)arg0+0x30)=*(int *)((char *)arg0+0x24);
  *(int *)((char *)arg0+0x34)=*(int *)((char *)arg0+0x28);
  *(int *)((char *)arg0+0x38)=*(int *)((char *)arg0+0x2c);
  *(int *)((char *)arg0+0x48)=*(int *)((char *)arg0+0x3c);
  *(int *)((char *)arg0+0x4c)=*(int *)((char *)arg0+0x40);
  *(int *)((char *)arg0+0x50)=*(int *)((char *)arg0+0x44);
 }
finish:
 *(int *)((char *)arg0+0x58)&=~1;
}
