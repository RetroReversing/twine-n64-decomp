/* identical to list_unlink_free in V-RALLY-PAL (local match library) (matched), with its names changed by decompdecomp */
s32 setEffectPairAnimFrames(s32);
void applyEnemyDefAnimation();

/* Unlinks the current node from its list, then frees the memory block it sits in. */
void resetEnemyAnimationAndEffects(s32 block) {
    applyEnemyDefAnimation();
    setEffectPairAnimFrames(block);
}
