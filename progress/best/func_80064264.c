#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
extern s32 D_801002E0;
extern char D_80100BE0[];
extern char D_80108608[];
extern char D_8010860C[];
extern char D_80108610[];
extern char D_80110B28[];
extern char D_80110B2C[];
extern char D_80110B30[];
void func_80064264(void *arg0, void *arg1, s8 arg2) {
char *__repair_addr;

    s32 temp_v0;
    s32 temp_v0_2;
    temp_v0 = D_801002E0 * 0xC;
__repair_addr = (char *)(D_80110B28 + temp_v0);

    *(s32 *)(__repair_addr) = M2C_FIELD(arg0, s32 *, 0);
    *(s32 *)(D_80110B2C + temp_v0) = M2C_FIELD(arg0, s32 *, 4);
    *(s32 *)(D_80110B30 + temp_v0) = M2C_FIELD(arg0, s32 *, 8);
    temp_v0_2 = D_801002E0 * 0xC;
    *(s32 *)(D_80108608 + temp_v0_2) = M2C_FIELD(arg1, s32 *, 0);
    *(s32 *)(D_8010860C + temp_v0_2) = M2C_FIELD(arg1, s32 *, 4);
    *(s32 *)(D_80108610 + temp_v0_2) = M2C_FIELD(arg1, s32 *, 8);
    *(D_80100BE0 + D_801002E0) = arg2;
    D_801002E0 += 1;
}
