typedef struct {
    s32 id;
    u8 pad4[0xFBC];
    u8 active;
    u8 busy;
    u8 padFC2[0x2C];
    u8 flags;
    u8 padFEF[9];
} Ent91254;

extern Ent91254 D_800E5AC4[];

static inline s32 find_91254(s32 id) {
    u32 i = 0;
    s32 key = id & 0x7FFFFFFF;
    s32 off = 0;

    for (; i < 8; i++, off += sizeof(Ent91254)) {
        if (*((u8 *)&D_800E5AC4[0].busy + off) == 0 && *(s32 *)((u8 *)&D_800E5AC4[0].id + off) == key) {
            return i | (id & 0x80000000);
        }
    }
    return -1;
}

void func_80091254(s32 arg0) {
    arg0 = find_91254(arg0);
    if (arg0 != -1) {
        if (arg0 >= 0) {
            D_800E5AC4[arg0].active = 1;
        } else {
            D_800E5AC4[arg0 & 0x7FFFFFFF].flags &= 0xF7;
        }
    }
}
