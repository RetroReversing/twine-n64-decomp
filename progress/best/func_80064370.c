/* adapted from similar verified C in func_80064318 in TWINE (matched), with its names changed by decompdecomp */
typedef struct { u8 pad[0x58]; s32 flags; } S64318;
void func_80064370(S64318 *arg0, u32 arg1) {
    s32 w;
    s32 v = arg0->flags & ~0xF0;
    arg0->flags = v;
    switch (arg1) {
    case 0: w = v | 0x10; break;
    case 1: w = v | 0x20; break;
    case 2: w = v | 0x40; break;
    case 3: w = v | 0x80; break;
    default: return;
    }
    arg0->flags = w;
}
