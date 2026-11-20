/* adapted from similar verified C in func_800843CC in TWINE (matched), with its names changed by decompdecomp */
s32 func_8000A8B4(s32, f32, s32);
s32 func_8000AABC(s32, s32, s32, s32);
u32 func_80045CF8(s32);
f32 func_80084270(s32, s16 *);
extern u16 D_800CE6E8[], D_800CE6F0[];
extern s32 D_80109688[];

void func_80084CD8(s32 object, u32 variant) {
    s16 index;
    f32 factor = func_80084270(object, &index);
    s32 item;
    s32 result;
    s32 *entry;
    if (variant << 24) {
        item = D_800CE6E8[func_80045CF8(4)];
    
    result = func_8000A8B4(item, factor, 255);} else {
        item = D_800CE6F0[func_80045CF8(4)];
    
    result = func_8000A8B4(item, factor, 255);}
    entry = D_80109688 + (u16)index;
    func_8000AABC(result, *entry, object, 0);
}

