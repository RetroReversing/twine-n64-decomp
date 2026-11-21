extern s32 D_800EE420;
extern s32 D_800F2720;
#define BANK ((u8 *)&D_800EE420 + bank * 0x860)
#define BASE ((u8 *)&D_800F2720)
#define PAIR(p, d) (p[0] << 7 | p[d])
s32 func_80096460(u8 code, u8 index, u8 bank) {
    u8 *p;
    u8 *row;
    u32 byteOffset;
    if (bank != 255) {
        if (code < 64) {
            row = (u8 *)&D_800EE420;
        row += bank * 0x860;
        byteOffset = index * 134;
        p = row + byteOffset;
        p += 0 + (code & 31);
            return PAIR(p, 32);
        }
        if ((u8)(code + 128) < 2) {
            row = (u8 *)&D_800EE420;
        row += bank * 0x860;
        byteOffset = index * 134;
        p = row + byteOffset;
        p += 0;
            goto pair;
        }
        if ((u8)(code + 124) < 2) {
            row = (u8 *)&D_800EE420;
        row += bank * 0x860;
        byteOffset = index * 134;
        p = row + byteOffset;
        p += 0;
            goto pair;
        }
        if (code < 70) {
            row = (u8 *)&D_800EE420;
        row += bank * 0x860;
        byteOffset = index * 134;
        p = row + byteOffset;
        p += 0 + code;
            return -(p[0] >= 64) & 0x3fff;
        }
        if ((u8)(code - 96) < 6) {
            return 0;
        }
        row = (u8 *)&D_800EE420;
        row += bank * 0x860;
        byteOffset = index * 134;
        p = row + byteOffset;
        p += 0 + code;
        return p[0] << 7;
    }
    if (code < 64) {
        row = (u8 *)&D_800F2720;
        byteOffset = index * 134;
        p = row + byteOffset;
        p += 0 + (code & 31);
        return PAIR(p, 32);
    }
    if ((u8)(code + 128) < 2 || (u8)(code + 124) < 2) {
        row = (u8 *)&D_800F2720;
        byteOffset = index * 134;
        p = row + byteOffset;
        p += 0;
pair:
        p += code & 254;
        return PAIR(p, 1);
    }
    if (code < 70) {
        row = (u8 *)&D_800F2720;
        byteOffset = index * 134;
        p = row + byteOffset;
        p += 0 + code;
        return -(p[0] >= 64) & 0x3fff;
    }
    if ((u8)(code - 96) < 6) {
        return 0;
    }
    row = (u8 *)&D_800F2720;
        byteOffset = index * 134;
        p = row + byteOffset;
        p += 0 + code;
    return p[0] << 7;
}
