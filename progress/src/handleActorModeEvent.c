extern s32 gGameMode;
void actorClearPendingFlags(void *);
void actorUpdateOwnerLink(void *);

void handleActorModeEvent(void *arg0, u8 arg1)
{
    switch (gGameMode) {
    case 1:
        if ((arg1 & 0xFF) == 1) break;
        goto shared_two;
    case 20:
        switch (arg1 & 0xFF) {
        case 1: break;
        case 2:
            actorClearPendingFlags(arg0);
            actorUpdateOwnerLink(arg0);
            break;
        case 4:
            actorClearPendingFlags(arg0);
            actorUpdateOwnerLink(arg0);
            break;
        case 5:
            actorClearPendingFlags(arg0);
            actorUpdateOwnerLink(arg0);
            break;
        case 6:
            actorClearPendingFlags(arg0);
            actorUpdateOwnerLink(arg0);
            break;
        case 8:
            actorClearPendingFlags(arg0);
            actorUpdateOwnerLink(arg0);
            break;
        case 11:
            actorClearPendingFlags(arg0);
            actorUpdateOwnerLink(arg0);
            break;
        case 13:
            actorClearPendingFlags(arg0);
            break;
        }
        break;
    case 33:
        if ((arg1 & 0xFF) == 1) {
            *(s32 *)((u8 *)arg0 + 0x60) &= 0xFBFFFE39;
        }
        break;
    case 16:
        if ((arg1 & 0xFF) == 1) break;
        if ((arg1 & 0xFF) == 3) {
            *(s32 *)((u8 *)arg0 + 0x60) &= -0xC1;
        }
        break;
    case 18:
        switch (arg1 & 0xFF) {
        case 1: break;
        case 2: break;
        case 3:
            actorClearPendingFlags(arg0);
            actorUpdateOwnerLink(arg0);
            break;
        }
        break;
    case 11:
        switch (arg1 & 0xFF) {
        case 1: case 2: case 4: case 5: case 6: case 8: case 9: case 10: case 11: break;
        case 3:
        case 7:
            actorClearPendingFlags(arg0);
            actorUpdateOwnerLink(arg0);
            break;
        }
        /* fall through */
    case 41:
        switch (arg1 & 0xFF) {
        case 1: break;
        case 2: break;
        case 3: actorClearPendingFlags(arg0); break;
        }
        break;
    case 40:
    shared_two:
        if ((arg1 & 0xFF) == 2) {
            actorClearPendingFlags(arg0);
        }
        break;
    }
}
