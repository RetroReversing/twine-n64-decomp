typedef struct {
    f32 result[1];
    f32 middle;
    f32 last;
    f32 matrixStart[4];
    f32 y1, y2, z0, z1, z2, xOffset, yOffset, zOffset;
} TransformBlock;
extern TransformBlock D_80102E74;
extern f32 D_80102E6C, D_80102E70;
extern volatile f32 D_80102E78;
extern f32 D_80102E80, D_80102E84, D_80102E88, D_80102E8C, D_80102EA4;
/* Multiplies the global input vector by a 3x3 matrix plus translation and stores the transformed vector. */ void transformGlobalVec3(void) {
    extern u32 D_80102E6C_word;
    volatile TransformBlock *p = (volatile TransformBlock *)((u32)&D_80102E74 + (((u32)&D_80102E74 & 1) >> 1));
    f32 a = D_80102E80;
    f32 x = ((volatile f32 *)p)[-3];
    f32 xx = a*x;
    f32 b = D_80102E84;
    f32 y = D_80102E6C;
    f32 xy = b*y;
    f32 c = D_80102E88;
    f32 z = D_80102E70;
    f32 xz = c*z;
    f32 yx = D_80102E8C*x;
    f32 yy = p->y1*y;
    f32 yz = p->y2*z;
    f32 zx = p->z0*x;
    f32 zy = p->z1*y;
    f32 outX = xx+xy+xz+D_80102EA4;
    f32 outY = yx+yy+yz+p->yOffset;
    f32 zz = p->z2*z;
    f32 outZ = zx+zy+zz+p->zOffset;
    p->result[0] = outX;
    D_80102E78 = outY;
    p->last = outZ;
}
