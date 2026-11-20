void func_80047068(f32 *p0, f32 *p1, f32 *p2, f32 *p3, s32 n, void *out) {
    f32 a,b,c,d,e,f,g,h,j,k,m,o,q,r,s; volatile f64 reserve[6];
    a=1.0f/(f32)n;
    b=a*a;
    c=p0[0]; d=p1[0]; e=p2[0]; f=p3[0];
    g=c * -0.5f;
    h=d * 2.5f;
    j=f * 0.5f;
    k=e * 2.0f;
    m=c-h;
    m=m+k;
    m=m-j;
    m=m*b;
    o=a*b;
    q=d*1.5f;
    r=e*1.5f;
    s=g+q;
    s=s-r;
    s=s+j;
    s=s*o;
    *(s32 *)out=n;
    *(f32 *)((char *)out+4)=d;
    *(f32 *)((char *)out+8)=s+m+((g+(e*0.5f))*a);
}
