typedef struct { u8 pad0[0xE]; s8 sE; u8 padF[5]; s32 f14; } Info299C;
typedef struct { u8 pad0[0x68]; Info299C *info; } Obj299C;
extern u8 D_800C470A[];
extern s32 D_80102ED8;

s32 func_8000299C(Obj299C *o, s32 id) {
    s32 other = 1;
    u8 t;

    if ((o->info->f14 & 0x200000) && D_80102ED8 == 0) {
        other = 0;
        switch (id) {
        case 0x2:
        case 0x15F:
            id = 0x2FA;
            break;
        case 0x106:
        case 0x10B:
        case 0x124:
        case 0x125:
        case 0x128:
        case 0x129:
        case 0x14D:
        case 0x153:
        case 0x46D:
            id = 0x2FC;
            break;
        case 0x7:
        case 0x165:
            id = 0x2FB;
            break;
        case 0x2A9:
            id = 0x302;
            break;
        case 0x209:
            id = 0x20B;
            break;
        case 0x20A:
            id = 0x20C;
            break;
        case 0x2E9:
            id = 0x304;
            break;
        case 0x2EA:
            id = 0x305;
            break;
        case 0x2EB:
            id = 0x306;
            break;
        default:
            other = 1;
            break;
        }
    }
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
