extern u16 gSaveStatus, D_800E097C;
extern s16 gSaveSlot, D_800BFC30;
extern s32 gSaveCmdResult;
extern u8 gSaveSlotTable[], D_800E096C[], D_800E0970[], D_800E0974[];
extern s8 D_80103030[], D_80103042[], D_8010A3C5[], D_80115308[];
extern u8 D_80107B68[], D_80108408[], gSaveSlotCodes[];
extern s8 D_80107B6A[];
extern s32 saveRefreshStatus(void), saveWaitCommand(void), func_80010B60(s32);
extern void saveSubmitCommand(s32,void *,s32,void *,s32,s32,s32,s32);
extern void func_800103B0(void *,void *,s32), saveDataEncodeName(void *,void *,s32);
extern s32 func_800AB770(void *,void *);
#define CMD(c,k,p) saveSubmitCommand(c,gSaveSlotTable+gSaveSlot*104,k,p,0,0,0,0)
u16 func_80012F50(void) {
    s32 i, j;
    s32 errorCode;
    s32 n, off, decodedOff, done;
    u8 *decoded, *raw;
    s8 *name, *code, *rawCode;
    s8 suffix;
    gSaveSlot = 0;
    D_800BFC30 = -1;
    if ((u16)saveRefreshStatus()) return gSaveStatus;
    CMD(7,gSaveSlot,0);
    if (saveWaitCommand()) goto setup_error;
    CMD(3,(s32)D_800E096C,D_800E0970);
    if (saveWaitCommand()) goto setup_error;
    CMD(4,(s32)D_800E0974,0);
    i = 0;
    if (!saveWaitCommand()) goto slots;
setup_error:
    errorCode = gSaveCmdResult;
slot_error:
      return func_80010B60(errorCode);
slots:
    raw = D_80108408;
    rawCode = (s8 *)raw + 10;
    name = D_80107B6A;
    code = name + 17;
    decoded = (u8 *)name - 2;
    off = 0;
    do {
        CMD(5,i,raw);
        n = 15;
        if (saveWaitCommand() == 5) {
            *(u16 *)decoded = 0;
            do { name[n] = ' '; } while (--n >= 0);
            name[16] = 0;
            n = 3;
            do { code[n] = ' '; } while (--n >= 0);
            code[4] = 0;
            *(u32 *)(D_80108408 + off) = 0;
            gSaveCmdResult = 0;
        } else if (!(errorCode = gSaveCmdResult)) {
            *(u16 *)decoded = 1;
            func_800103B0(name,D_80108408 + off + 14,16);
            func_800103B0(code,rawCode,4);
        } else goto slot_error;
        rawCode += 32;
        code += 24;
        name += 24;
        decoded += 24;
        off += 32;
        i++;
        raw += 32;
    } while (i < 16);
    if (D_800E097C) {
        *D_8010A3C5 = 'A';
        saveDataEncodeName(D_80115308,D_80103030,16);
        saveDataEncodeName(D_80103042,D_8010A3C5,4);
        do {
            j = 0;
            name = (s8 *)D_80107B68 + 2;
            off = 0;
            decodedOff = 0;
            done = 1;
            do {
                if (*(u16 *)(D_80107B68+decodedOff) && *(u32 *)(D_80108408+off+4) == 0x4e4f3745 &&
                    *(u16 *)(D_80108408+off+8) == 0x3639 && func_800AB770(name,D_80115308)) {
                    suffix = *(s8 *)(D_80108408+off+10);
                    if (suffix == *D_80103042) {
                        done = 0;
                        *D_80103042 = suffix + 1;
                        break;
                    }
                    D_800BFC30 = j;
                }
                name += 24;
                off += 32;
                j++;
                decodedOff += 24;
            } while (j < 16);
        } while (!(u16)done);
        func_800103B0(D_8010A3C5,D_80103042,4);
    }
    gSaveStatus = 0;
    return 0;
}
