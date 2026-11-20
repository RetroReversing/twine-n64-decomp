void func_80047068(f32 *p0, f32 *p1, f32 *p2, f32 *p3, s32 n, void *out) {
    volatile f32 frame[20];
    f32 inv, inv2, x, y, z, w;
    f32 qx, qy, qz;
    f32 rx, ry, rz;
    f32 sx, sy, sz;
    inv=1.0f/(f32)n;
    inv2=inv*inv;
    x=p0[0]; y=p0[1]; z=p0[2];
    w=p1[0]; qx=p1[1]; qy=p1[2];
    rx=p2[0]; ry=p2[1]; rz=p2[2];
    sx=p3[0]; sy=p3[1]; sz=p3[2];
    *(s32*)out=n;
    *(f32*)((u8*)out+4)=w;
    *(f32*)((u8*)out+8)=(s32)((x-w*2.5f+rx*2.0f-sx*0.5f)*inv2)*inv2*inv;
    *(f32*)((u8*)out+12)=0.0f;
    *(f32*)((u8*)out+16)=qx;
    *(f32*)((u8*)out+20)=(s32)((y-qx*2.5f+ry*2.0f-sy*0.5f)*inv2)*inv2*inv;
    *(f32*)((u8*)out+24)=0.0f;
    *(f32*)((u8*)out+28)=qy;
    *(f32*)((u8*)out+32)=(s32)((z-qy*2.5f+rz*2.0f-sz*0.5f)*inv2)*inv2*inv;
    *(f32*)((u8*)out+36)=0.0f;
}
