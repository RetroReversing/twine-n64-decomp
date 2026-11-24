extern int stepColorFadeOut(void), stepColorFadeIn(void);
extern void setStateMachineState(void *, short);
/* Advances a fade state machine: state 3 restarts as fade-out, fade-out finishing goes to state 2, fade-in finishing goes to state 4. */ void updateFadeTransitionState(int unused, void *machine) {
    int nextState;
    switch (*(short *)((char *)machine + 0x7a)) {
    case 3: *(short *)((char *)machine + 0x7a) = 1; break;
    case 1:
        if (stepColorFadeOut() & 255) setStateMachineState(machine, 2);
        break;
    case 0:
        if (stepColorFadeIn() & 255) { nextState = 4; call: setStateMachineState(machine, nextState); }
        break;
    case 2: case 4: break;
    }
}
