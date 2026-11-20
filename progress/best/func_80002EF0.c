typedef struct Node { unsigned char pad[0x28]; f32 x; f32 y; f32 z; f32 w; unsigned char gap[0x64-0x38]; s16 h; unsigned char rest[0x100]; } Node;
typedef struct { unsigned char pad[0x68]; Node *node; unsigned char rest[0x100]; } Obj;
s32 func_80002EF0(Obj *arg0) { Node *p=arg0->node; volatile u32 scratch[0x2f0]; volatile u32 scratch2[4]; p->x=p->x+p->y; return 0; }
