typedef struct {
    u16 key;
    s16 len;
    s32 off;
} TextBankRow;

extern TextBankRow *sTextBankTables[];
extern s32 sTextBankRomOffsets[];
extern u8 D_148B400[];
void dmaRomToRamUnaligned(void *, void *, s32);
s16 strlen(void *);

/* For each of the three text banks, walks its row list until the 0xFFFF key: each row reads its text
   block offset from the ROM index table, DMAs that text block into a buffer and stores its length and offset. */
void loadTextBanks(void) {
    u8 textBuf[0x400];
    s32 textOffset;
    u32 bank;
    TextBankRow *row;
    s32 indexOffset;

    textOffset = 0;
    for (bank = 0; bank < 3; bank++) {
        row = sTextBankTables[bank];
        indexOffset = sTextBankRomOffsets[bank];
        if (row->key != 0xFFFF) {
            u16 sentinel = 0xFFFF;
            TextBankRow *p = row;
            s32 q = indexOffset;
            rows: {
                dmaRomToRamUnaligned(&textOffset, D_148B400 + q, 4);
                dmaRomToRamUnaligned(textBuf, D_148B400 + textOffset, 0x400);
                p->len = strlen(textBuf);
                p->off = textOffset;
                p++;
                q += 4;
            }
            if (p->key != sentinel) goto rows;
        }
    }
}
