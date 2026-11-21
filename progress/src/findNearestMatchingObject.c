f32 approxDistance(void *,void *); f32 absFloat(f32);
/* Walks the linked object list from *listHead and finds the nearest type-1 object that pairs with subject by flag bits and height; stores it in *bestObj and *bestDist. Returns 1 if one was found. */
s32 findNearestMatchingObject(void **listHead,void *subject,void **bestObj,f32 *bestDist) {
 f32 dist; s32 found,flagBits; void *subjectFlags,*obj;
 obj=*listHead;subjectFlags=*(void **)((char *)subject+0x6c);found=0;
 if(obj!=NULL)do {
 if(*(u16 *)((char *)obj+0x78)==1) {
 if((obj!=subject)&&(*(s32 *)((char *)obj+0x20)!=0)&&
 (((flagBits=(*(s32 *)((char *)(*(void **)((char *)obj+0x6c))+0x88)&0x01e00000),(flagBits==0x400000)&&((*(s32 *)((char *)subjectFlags+0x88)&0x01e00000)==0x200000))||((flagBits==0x200000)&&((*(s32 *)((char *)subjectFlags+0x88)&0x01e00000)==0x400000)))&&((absFloat(*(f32 *)((char *)subject+0x28)-*(f32 *)((char *)obj+0x28))<1.0f)||(*(s32 *)((char *)subject+0x20)==*(s32 *)((char *)obj+0x20))))) {
 dist=approxDistance((char *)subject+0x24,(char *)obj+0x24);
 if(dist<*bestDist){found=1;*bestDist=dist;*bestObj=obj;}
 }
 }
 obj=*(void **)obj;
 } while(obj!=NULL);
 return found;
}
