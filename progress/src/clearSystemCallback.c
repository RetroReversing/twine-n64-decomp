extern s32 gSystemCallback;

/* Clears the registered system callback. */
void clearSystemCallback(void) {
    gSystemCallback = 0;
}
