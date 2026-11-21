typedef struct { u8 pad0[0x22]; u16 yPos; u8 pad24[2]; u16 barWidth; } HudSprite;
typedef struct { u8 pad0[0x34]; f32 progress; u8 pad38[0x3B4]; HudSprite *markerA; HudSprite *markerB; u8 pad3F4[4]; HudSprite *spinner; HudSprite *speedBar; u8 pad400[0x120]; u16 speed; } HudState;

/* Updates the track HUD: moves the two position markers with the lap progress, advances the spinner frame (wrapping at 240) and sizes the speed bar. */
void updateHudSprites(HudState *hud) {
    f32 t;

    if (hud->markerA != NULL) {
        t = hud->progress * 23.0f;
        hud->markerA->yPos = 120.0f - t - 8.0f;
        hud->markerB->yPos = 120.0f - t - 8.0f;
    }
    if (hud->spinner != NULL) {
        hud->spinner->yPos++;
        if (hud->spinner->yPos > 240) {
            hud->spinner->yPos = 0;
        }
    }
    if (hud->speedBar != NULL) {
        hud->speedBar->barWidth = hud->speed * 0.0005561735f * 42.0f;
        if (hud->speedBar->barWidth == 0) {
            hud->speedBar->barWidth = 1;
        }
    }
}
