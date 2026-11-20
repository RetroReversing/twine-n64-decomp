s32 func_80045B58(f32 *arg0, f32 *arg1, f32 *arg2, f32 *arg3, f32 *arg4) {
 f32 * volatile v[3]; f32 e[3],c[3],d[3]; u32 i,prev;
 v[0]=arg1; v[1]=arg2; v[2]=arg3; i=0; prev=2;
 do {
 e[0]=v[i][0]-v[prev][0]; e[1]=v[i][1]-v[prev][1]; e[2]=v[i][2]-v[prev][2];
 c[0]=e[1]*arg4[2]-e[2]*arg4[1]; c[1]=e[2]*arg4[0]-e[0]*arg4[2]; c[2]=e[0]*arg4[1]-e[1]*arg4[0];
 d[0]=arg0[0]-v[i][0]; d[1]=arg0[1]-v[i][1]; d[2]=arg0[2]-v[i][2];
 if (d[0]*c[0]+d[1]*c[1]+d[2]*c[2]>0.0f) return 0;
 prev=i; i++; } while(i<3); return 1;
}
