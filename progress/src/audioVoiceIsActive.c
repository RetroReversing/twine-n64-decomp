extern unsigned char *gAudioVoiceTable;
int audioVoiceIsActive(int arg0) { return gAudioVoiceTable[arg0 * 0x68] != 0; }
