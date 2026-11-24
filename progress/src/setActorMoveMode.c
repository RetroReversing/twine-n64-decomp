/* Sets the actor's movement mode (halfword at offset 0x7A). */ void setActorMoveMode(char *actor, int mode) { *(short *)(actor + (122)) = mode; }
