extern s32 gVisibleSaveSlotCount, gHiResScreen;
extern u8 gBorderFlipFlag;
s32 DrawBorderRect(s32, s32, s32, s32);

/* Draws the border strips for the current border mode, using the 320x240 or 640x480 screen size. */
void DrawScreenBorderLines(void) {
    register f32 height, width;
    f32 full_height, half_width;
    int hires;

    height = 120.0f;
    full_height = 240.0f;
    hires = gHiResScreen;
    half_width = 160.0f;
    width = 320.0f;
    if (hires) {
        height = 240.0f;
        full_height = 480.0f;
    }

    switch (gVisibleSaveSlotCount) {
    case 2:
        if (gBorderFlipFlag == 1) {
            DrawBorderRect((u32) (half_width - 1.0f), 0, 3, (u32) full_height);
        } else {
            DrawBorderRect(0, (u32) (height - 1.0f), (u32) width, 3);
        }
        break;
    case 3:
    case 4:
        DrawBorderRect((u32) (half_width - 1.0f), 0, 3, (u32) full_height);
        DrawBorderRect(0, (u32) (height - 1.0f), (u32) width, 3);
        break;
    }
}
