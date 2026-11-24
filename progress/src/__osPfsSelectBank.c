/* identical to __osPfsSelectBank in V-RALLY-PAL (local match library) (matched), with its names changed by decompdecomp */
int __osContRamWrite(int a, int b, int c, char *d, int e);

/* Selects bank `bank` of the controller pak: fills a 32-byte block with the bank number and
 * writes it to the pak at 0x400 (the bank-select page). On success, records the bank in
 * the pak state at +0x65. */
/* Selects a controller pak bank by writing a block filled with the bank number to the bank-select page. */ void __osPfsSelectBank(char *pfs, char bank) {
    char bankBlock[32];
    int idx;

    for (idx = 31; idx >= 0; idx--) {
        bankBlock[idx] = bank;
    }
    if (__osContRamWrite(*(int *)(pfs + 4), *(int *)(pfs + 8), 0x400, bankBlock, 0) == 0) {
        pfs[0x65] = bank;
    }
}
