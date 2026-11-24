typedef struct { u32 *dst; u32 src; u8 idx; u8 cnt; u8 cur; u8 lim; u16 sz; } Anim;
extern u32 gTextureEntryCount;
extern Anim *gTextureEntryTable[];

void updateAnimatedTextures(void) {
    u8 __repair_frame[1];
    u32 i;
    for (i = 0; i < gTextureEntryCount; i++) {
        Anim *a = gTextureEntryTable[i];
        a->cur++;
        if (a->lim < a->cur) {
            a->cur = 0;
            a->idx++;
            if (a->idx == a->cnt) a->idx = 0;
            *a->dst = a->src + a->idx * a->sz;
        }
    }
}
