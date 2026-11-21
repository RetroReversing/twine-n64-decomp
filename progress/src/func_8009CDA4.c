s32 func_800A9250(void);
s32 osVirtualToPhysical(s32);
extern volatile s32 D_A4040000;
s32 func_800A92C0(s32 direction, s32 spAddress, s32 dramAddress, s32 length) {
    volatile s32 *lengthRegister;
    if (func_800A9250()) return -1;
    D_A4040000 = spAddress;
    *(volatile s32 *)0xA4040004 = osVirtualToPhysical(dramAddress);
    if (direction == 0) lengthRegister = (volatile s32 *)0xA404000C;
    else lengthRegister = (volatile s32 *)0xA4040008;
    *lengthRegister = length - 1;
    return 0;
}

s32 audioVoiceIsActive(s32);
unsigned int func_8008C1DC(void);
extern u8 gWorkerThreadActive;
extern s8 D_80112DC0;
extern u8 sVoiceCount;

s32 func_8009CDA4(void) {
    s32 i;
    s32 status = 0;
    s32 count;
    s32 result;
    s64 checkState;
    s64 *checkStatePtr = &checkState;
    if (gWorkerThreadActive == 0) goto done;
    D_80112DC0 = 1;
    if ((u8)func_8008C1DC() == 0) {
        if ((count = sVoiceCount) > 0) {
            i = 0;
            do {
                status |= audioVoiceIsActive(i);
                i++;
            } while (i < sVoiceCount);
        }
    } else {
        status = 1;
    }
clear:
    D_80112DC0 = 0;
done:
    return (u8)status == 0;
}

#ifndef M2C_DEFINES
#define M2C_DEFINES
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define M2C_CARRY 0
#define M2C_OVERFLOW(a) 0
#endif
void cordicSinCos(f64, f64 *, f64 *); extern f64 D_800D6FE0,D_800D6FE8,D_800D6FF0,D_800D6FF8;
f64 func_800AB330(f64 arg0) { f64 sp10; f64 sp18; f64 ratio; f64 bias; f64 r; s32 n; ratio=arg0/D_800D6FE0; bias=D_800D6FE8; if(arg0>=0.0) bias=D_800D6FF0; n=(s32)(ratio+bias); do { cordicSinCos(arg0-((f64)n*D_800D6FF8),&sp10,&sp18); } while (0); r=sp18; if(n&1) r=-r; return r; }

void func_80011938(s32, s16);
void func_80081758(s32);
extern s16 D_800E1A80[];
extern s8 D_8010D434[], D_8010D436[], D_80115108[], D_8011510C[];
void func_800820BC(void) {
    s32 i = 0;
    s16 *slot = D_800E1A80;
    s32 src = 0;
    s32 dst = 0;
    do {
        s32 value;
        func_80011938((u16)i, 0);
        func_80081758(i);
        *(volatile s32 *)(D_80115108 + dst) = *(s16 *)(D_8010D434 + src);
        value = *(volatile s16 *)(D_8010D436 + src);
        i++;
        src += 8;
        *(s32 *)(D_8011510C + dst) = value;
        *slot++ = 0;
        dst += 0xA0;
    } while (i < 4);
}
