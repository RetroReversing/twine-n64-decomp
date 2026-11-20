extern volatile u16 D_800E41F0;
extern u32 D_800E41F4;
extern char D_800E41F8[], D_800E4210[];
extern s8 D_800E4214;
extern s32 (*D_8010017C)(s32,s32);
extern u8 D_8010086C;
extern s32 D_80103EB4;
extern u16 D_800CEED0[];
extern f64 D_800D6700, D_800D6708, D_800D6710;
void func_80089C10(s32);
void func_80089E64(u16);
void osCreateMesgQueue(void *, void *, s32);
void func_800895F8(u16 a, u32 b, u8 c) {
    u32 x; u32 a0;
    if (D_8010086C == 0) {
        a0 = a;
        x = (u32)((f32)b * 0.000125f);
    } else {
        f64 d = (s32)b;
        a0 = a;
        if ((s32)b < 0) d += D_800D6708;
        x = (u32)((f32)d * 0.00025f);
    }
    D_800E41F0 = a0 * ((u16)x + 1);
    { u32 size = 0x310; u32 total = D_800E41F0 * size; f64 d = (s32)total;
    D_800E41F4 = size;
    if ((s32)total < 0) d += D_800D6710;
    D_800E41F4 = (((((u32)((f32)d * 0.9f) + 63) >> 6) * 0x28) + 15) & 0xFFF0; }
    D_80103EB4 = D_8010017C(D_800E41F0 * 0x18, 0);
    osCreateMesgQueue(D_800E41F8, D_800E4210, 1);
    D_800E4214 = 0;
    func_80089C10(D_800E41F0);
    func_80089E64(D_800CEED0[c] * a);
}
