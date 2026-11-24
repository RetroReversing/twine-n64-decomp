typedef struct { s32 minutes; s16 ticks; s8 seconds; u8 ticksPerSecond; } PlayTime;
void addPlayTime(PlayTime *total, PlayTime *delta) {
 /* Adds delta to total, carrying ticks into seconds and seconds into minutes. */
 if ((total != 0) & (delta != 0)) {
  total->ticks += delta->ticks;
  while (total->ticks > total->ticksPerSecond) { total->ticks -= total->ticksPerSecond; total->seconds++; }
  total->seconds += delta->seconds;
  while (total->seconds > 60) { total->seconds -= 60; total->minutes++; }
  total->minutes += delta->minutes;
 }
}
