extern unsigned char *gAudioVoiceTable;
/* Returns nonzero if the voice slot (0x68-byte entries) has a nonzero first byte. */ int audioVoiceIsActive(int voiceIndex) { return gAudioVoiceTable[voiceIndex * 0x68] != 0; }
