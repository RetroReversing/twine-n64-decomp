extern s64 D_800D1250[]; extern f64 D_800D6EC0; extern f64 func_800ABFA0(s64);
void func_800AA5E0(s64 x, s64 y, f64 *out) { s64 z=0, t; int i; for(i=0;i<52;i++) { if(y>=0) { t=x+(y>>i); y-=x>>i; z+=D_800D1250[i]; } else { t=x-(y>>i); y+=x>>i; z-=D_800D1250[i]; } x=t; } *out=func_800ABFA0(z)/D_800D6EC0; }
