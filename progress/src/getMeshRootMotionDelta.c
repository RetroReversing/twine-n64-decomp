s16 *findOrLoadCacheBlock();
void getMeshFrameBonePositions(s32, s32, f32 *, s32);
/* Writes the displacement of the first bone between the mesh's last frame and its first frame to delta[0..2]. */
void getMeshRootMotionDelta(s32 mesh, f32 *delta) {
 f32 positions[148]; f32 endX,endY,endZ;
 getMeshFrameBonePositions(mesh,*findOrLoadCacheBlock(mesh)-1,positions,1);
 endX=positions[0]; endY=positions[1]; endZ=positions[2];
 getMeshFrameBonePositions(mesh,0,positions,1);
 delta[0]=endX-positions[0]; delta[1]=endY-positions[1]; delta[2]=endZ-positions[2];
}
