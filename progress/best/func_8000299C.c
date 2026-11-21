typedef struct { u8 pad0[0xE]; s8 sE; u8 padF[5]; s32 f14; } Info299C;
typedef struct { u8 pad0[0x68]; Info299C *info; } Obj299C;
extern u8 D_800C470A[];
extern s32 gBorderSkipActive;

s32 func_8000299C(Obj299C *o, s32 id) {
    s32 other = 1;
    s32 t;

    if ((o->info->f14 & 0x200000) && gBorderSkipActive == 0) {
        s32 finalCase;
        other = 0;
        if (id == 0x153) goto to2FC;
        if (id < 0x154) {
            if (id < 0x126) {
                if (id >= 0x124) goto to2FC;
                if (id == 7) goto to2FB;
                if (id < 8) {
                    if (id == 2) id = 0x2FA;
                    else other = 1;
                    goto joined;
                }
                if (id == 0x106) goto to2FC;
                finalCase = 0x10B;
                goto lastCheck;
            }
            if (id < 0x128) goto useOther;
            if (id < 0x12A) goto setInline;
            finalCase = 0x14D;
            goto lastCheck;
        }
        if (id == 0x2A9) goto to302;
        if (id < 0x2AA) {
            if (id == 0x165) goto to2FB;
            if (id < 0x166) {
                if (id == 0x15F) id = 0x2FA;
                else other = 1;
                goto joined;
            }
            if (id == 0x209) goto to20B;
            if (id == 0x20A) id = 0x20C;
            else other = 1;
            goto joined;
        }
        if (id == 0x2EA) goto to305;
        if (id < 0x2EB) {
            if (id == 0x2E9) id = 0x304;
            else other = 1;
            goto joined;
        }
        if (id == 0x2EB) goto to306;
        finalCase = 0x46D;
    lastCheck:
        if (id == finalCase) {
    setInline:
            id = 0x2FC;
            goto joined;
        }
    useOther:
        other = 1;
        goto joined;
    to2FC: id = 0x2FC; goto joined;
    to2FB: id = 0x2FB; goto joined;
    to302: id = 0x302; goto joined;
    to20B: id = 0x20B; goto joined;
    to305: id = 0x305; goto joined;
    to306: id = 0x306;
    }
joined:
    if (other && !(o->info->f14 & 0x20000)) {
        t = D_800C470A[o->info->sE * 0xE8];
        if ((u32)(id - 1) < 0x14C) {
            if (t == 5) {
                t = 2;
            }
            id = id - (id - 2) % 5 + t;
        } else if ((u32)(id - 0x14C) < 0x68) {
            id = id - (id - 0x14D) % 6 + t;
        }
    }
    return id;
}

