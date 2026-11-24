/* Resets an entity's state block: clears flags and counters and sets scale to 256. */
void resetEntityState(Entity *entity) {
    EntityState *state;

    state = entity->state;
    state->unk195 = 0;
    state->scale = 256.0f;
    state->unk11C = 0;
    state->unk120 = 0;
    state->unk124 = 0;
}
