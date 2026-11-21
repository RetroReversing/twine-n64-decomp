typedef struct { u16 id; u8 lo; u8 hi; s8 off; u8 vol; s16 pan; u8 pri; u8 pad[3]; } Ent;
s32 func_8008CEB0();
s32 func_80096970();
Ent *func_8009852C();
s32 func_800988D8();
s32 func_8009C420();
extern char sVoiceTable[];
extern char gVoiceChannelTable[];
extern char D_8010D738[];

s32 func_8008D138(u32 arg0, u16 arg1, u8 arg2, u32 arg3, u8 arg4, u8 arg5, u8 arg6, u16 arg7, u16 arg8, u8 arg9) {
int __repair_constant = -1;

    u16 count;
    Ent *e;
    s32 i;
    s32 ret;
    u32 voice;
    u32 key;
    s32 note, r, t, pan, pri;
    u32 a, b;
    u32 c;
    u32 v;
    u16 id;
    s32 vol;

    ret = __repair_constant;
    e = func_8009852C(arg0 >> 16, &count);
    if (e != 0 && count > 0) {
        c = arg3 & 0xFF;
        key = arg2 & 0x7F;
        a = arg5;
        b = arg6;
        i = 0;
loop:
        if (e->id == 0xFFFF || key < e->lo || e->hi < key) goto next;
            note = key + e->off;
            if (note < 0x80) {
                note = note & ~(note >> 31);
            } else {
                note = 0x7F;
            }
            if (a == 0xFF || !(func_80096970(a, b) & 0xFF) || (r = func_8008CEB0(note & 0x7F, a, b), r == -1)) r = __repair_constant;
            if (r != -1) return r;
            if (e->pri & 0x80) {
                pri = 0x80;
            } else {
                pri = arg4 + (e->pri - 0x40);
                pri = pri < 0 ? 0 : pri < 0x80 ? pri : 0x7F;
            }
            vol = (c * e->vol) / 127;
            pan = ((arg0 >> 8) & 0xFF) + e->pan;
            if (pan < 0x100) pan = pan & ~(pan >> 31);
            else pan = 0xFF;
            id = e->id;
            v = (arg0 & 0xFF) | (pan << 8) | (id << 16);
            if (id & 0xC000) goto next;
            if (ret == -1) {
                voice = func_8009C420(v, arg1, (note | (arg2 & 0x80)) & 0xFF, vol & 0xFF, pri & 0xFF, a, b, arg7, arg8, 0, arg9);
                if (voice != -1) {
                    ret = func_800988D8(sVoiceTable + (voice & 0xFF) * 0x1A0);
                }
            } else {
                t = func_8009C420(v, arg1, (note | (arg2 & 0x80)) & 0xFF, vol & 0xFF, pri & 0xFF, a, b, arg7, arg8, 0, arg9);
                if (t != -1) {
                    *(s32 *)(gVoiceChannelTable + (voice & 0xFF) * 0x1A0) = t;
                    *(s32 *)(D_8010D738 + (t & 0xFF) * 0x1A0) = voice;
                    voice = t;
                }
            }
next:
        i++; e++;
        if (i < count) goto loop;
    }
    return ret;
}
