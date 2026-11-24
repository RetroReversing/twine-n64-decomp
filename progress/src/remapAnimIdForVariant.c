typedef struct { u8 pad0[0xE]; s8 sE; u8 padF[5]; s32 f14; } Info299C;
typedef struct { u8 pad0[0x68]; Info299C *info; } Obj299C;
extern u8 gActorTypeKindTable[];
extern s32 gBorderSkipActive;

/* Remaps an animation id to the border-skip or per-variant equivalent for the object's type. */ s32 remapAnimIdForVariant(Obj299C *obj, s32 id) {
    s32 allowVariant = 1;
    s32 variant;

    if ((obj->info->f14 & 0x200000) && gBorderSkipActive == 0) {
        allowVariant = 0;
        switch (id) {
        default:
            allowVariant = 1;
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
        case 0x2:
        case 0x15F:
            id = 0x2FA;
            break;
        }
    }
joined:
    if (allowVariant && !(obj->info->f14 & 0x20000)) {
        variant = gActorTypeKindTable[obj->info->sE * 0xE8];
        if ((u32)(id - 1) < 0x14C) {
            if (variant == 5) {
                variant = 2;
            }
            id = id - (id - 2) % 5 + variant;
        } else if ((u32)(id - 0x14C) < 0x68) {
            id = id - (id - 0x14D) % 6 + variant;
        }
    }
    return id;
}


