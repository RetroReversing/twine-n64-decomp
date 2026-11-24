/* identical to func_80071E08 in V-RALLY-PAL (local match library) (matched), with its names changed by decompdecomp */
s32 resetAllSlotStates(void);
s32 pollControllersAndRunSaveCommand(void);
s32 pollControllersAndRunSaveCommand(void);

/* Tears down the asset list and the two subsystems it depends on. */
/* Resets all slot states, then runs pollControllersAndRunSaveCommand twice. */ void resetSlotsAndRefreshAll(void)
{
    resetAllSlotStates();
    pollControllersAndRunSaveCommand();
    pollControllersAndRunSaveCommand();
}
