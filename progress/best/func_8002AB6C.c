typedef struct {u8 pad[9];u8 w;u8 pad2[2];} E2A; typedef struct {E2A *e;u8 pad[0x14];u8 x18,x19,x1a,x1b,x1c,x1d,x1e;} T2A;
s32 func_8002AB6C(T2A *t) {
 s16 i,sum;
 if(!t) __shared_return_0:
    return 0;
 if(t->x18 == t->x19-1) return 1;
 sum=0;
 for(i=t->x18;i<t->x19;i++) sum+=t->e[i].w;
 if(t->x1e==0) return sum<=t->x1b;
 goto __shared_return_0;
}
