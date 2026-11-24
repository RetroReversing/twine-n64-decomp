#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
s32 applyFlagsToPartList(); extern u16 gSurfaceQueryStamp;
/* Breadth-first walk over an object's linked neighbours (up to 3 rings), applying flags to each once per query stamp; clearRing selects the ring at which the 0x30000 flag bits are dropped. */
void propagateFlagsToLinkedObjects(s32 pos,void *root,s32 flags,s32 clearRing){
 void *visited[0x80];  u32 ringStart;
 u32 ringEnd,ringIdx,visitedCount,first; void *tmpA,*neighbor,*data,*data2,*link;
 ringStart=0; gSurfaceQueryStamp++; visitedCount=0;
 if(root){
 if(clearRing==0)flags&=0xFFFCFFFF;
 applyFlagsToPartList(root,2,flags|0x1000,pos); M2C_FIELD(M2C_FIELD(root,void **,0x20),u16 *,0x60)=gSurfaceQueryStamp;
 if(clearRing==1)flags&=0xFFFCFFFF;
 link=M2C_FIELD(M2C_FIELD(root,void **,0x20),void **,0x58);
 if(link){do{neighbor=M2C_FIELD(link,void **,8);data=M2C_FIELD(neighbor,void **,0x20);
 if(M2C_FIELD(data,u16 *,0x60)!=gSurfaceQueryStamp){M2C_FIELD(data,u16 *,0x60)=gSurfaceQueryStamp;applyFlagsToPartList(neighbor,2,flags|0x2000,pos);visited[visitedCount]=neighbor;visitedCount++;}
 link=M2C_FIELD(link,void **,0);
 }while(link);}
 if(clearRing==2)flags&=0xFFFCFFFF;
 first=ringStart; ringEnd=visitedCount; ringStart=ringEnd; ringIdx=first;
 for(;ringIdx<ringEnd;ringIdx++){link=M2C_FIELD(M2C_FIELD(visited[ringIdx],void **,0x20),void **,0x58);
 if(link){do{neighbor=M2C_FIELD(link,void **,8);data2=M2C_FIELD(neighbor,void **,0x20);
 if(M2C_FIELD(data2,u16 *,0x60)!=gSurfaceQueryStamp){M2C_FIELD(data2,u16 *,0x60)=gSurfaceQueryStamp;applyFlagsToPartList(neighbor,2,flags|0x4000,pos);visited[visitedCount]=neighbor;visitedCount++;}
 link=M2C_FIELD(link,void **,0);
 }while(link);}
 }
 if(clearRing==3)flags&=0xFFFCFFFF;
 ringIdx=ringStart; ringEnd=visitedCount;
 if(ringIdx<ringEnd){do{link=M2C_FIELD(M2C_FIELD(visited[ringIdx],void **,0x20),void **,0x58);
 if(link){do{neighbor=M2C_FIELD(link,void **,8);tmpA=M2C_FIELD(neighbor,void **,0x20);
 if(M2C_FIELD(tmpA,u16 *,0x60)!=gSurfaceQueryStamp){M2C_FIELD(tmpA,u16 *,0x60)=gSurfaceQueryStamp;applyFlagsToPartList(neighbor,2,flags|0x8000,pos);}
 link=M2C_FIELD(link,void **,0);
 }while(link);}
 ringIdx++;
 }while(ringIdx<ringEnd);}
 }
}
