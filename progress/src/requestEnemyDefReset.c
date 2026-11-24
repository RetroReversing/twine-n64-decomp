/* adapted from similar verified C in race_entries_clear in V-RALLY-PAL (matched), with its names changed by decompdecomp */
void requestEnemyDefChange(int a, int b, int c);
/* Requests an enemy definition change with value 0 and code 45 for the given enemy. */ /* Zeroes the 0x118-byte race entry block at entries. */ void requestEnemyDefReset(int enemy) { requestEnemyDefChange(enemy, 0, 45); }
