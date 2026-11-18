/* adapted from similar verified C in race_entries_clear in V-RALLY-PAL (matched), with its names changed by decompdecomp */
void func_8007089C(int a, int b, int c);
/* Zeroes the 0x118-byte race entry block at entries. */ void func_8005C8A4(int entries) { func_8007089C(entries, 0, 54); }
