void loadMeshFrame(s32,s32,s32,s32); void func_80005F5C(void *); void copyWords(s32,s32,s32);
extern s32 gDefaultMeshFrame;
typedef struct { s32 flags; u8 pad4[0x3c]; s32 a40,a44,a48; u8 pad4c[0x32]; s16 h7e,h80; u8 pad82[0x10]; s16 h92; } Sub;
/* Stores the start/end frame on the object's mesh state, reloads the mesh frame data and refreshes the object. */
void setObjectMeshFrameRange(void *object,s32 startFrame,s32 endFrame,s32 arg3) {
 u8 *obj=*(u8 **)((u8 *)object+0x68); Sub *s=(Sub *)(obj+0x14);
 if (s->flags & 0x4000) *(s16 *)(obj+0x90)=endFrame; else *(s16 *)(obj+0x90)=gDefaultMeshFrame;
 s->h7e=startFrame; s->h80=endFrame;
 copyWords(s->a40,s->a48,s->h92);
 loadMeshFrame(s->a44,startFrame,endFrame,s->flags&1);
 func_80005F5C(object);
}
