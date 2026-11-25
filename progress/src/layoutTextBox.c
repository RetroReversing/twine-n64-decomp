typedef struct { u8 pad[0x20]; u16 x,y,unused,width; u8 gap,height; } TextBox27;
typedef struct { u8 pad[8]; TextBox27 *box; u16 align; u8 gap[14]; u8 flags; } TextStyle27;
s32 measureTextBoxWidth(void *); s32 getTextBoxHeight(void *);
/* Lays out a text box's position and size from its style, relative to the previous box (currently always none). */
void layoutTextBox(TextBox27 *out, TextStyle27 *style, s32 arg2) {
 s32 prevWidth=0, offsetX=0; TextStyle27 *previous=0; u16 totalWidth,x,align,top; s32 styleWidth; u8 styleHeight;
 if(out!=0) { if(style!=0) {
 if(style->flags&0x80) { styleWidth=style->box->width; styleHeight=style->box->height; }
 else { styleWidth=measureTextBoxWidth(style->box); styleHeight=getTextBoxHeight(style->box); }
 if(previous!=0) { if(previous->flags&0x80) prevWidth=previous->box->width; else prevWidth=measureTextBoxWidth(previous->box);
 prevWidth &= -((previous->align&0x40)==0);
 if(style->align&0x40) offsetX=previous->box->x-style->box->x;
 else offsetX=previous->box->x-(style->box->x+styleWidth); }
 out->width=totalWidth=offsetX+(styleWidth+prevWidth); align=style->align;
 if(align&0x20) out->x=style->box->x-((u16)totalWidth>>1);
 else { s32 leftX;
 if(align&0x40) { s32 anchorX=style->box->x; if(previous!=0) { leftX=anchorX-(u16)styleWidth; goto store_x; } leftX=anchorX-(u16)totalWidth; } else leftX=style->box->x;
 store_x: out->x=leftX; }
 if(style->flags&0x80)top=style->box->y-2; else top=style->box->y-4;
 do { out->y=top; } while(0);
 { s32 leftX=out->x; s32 spanW=out->width; do { out->height=styleHeight+4; } while(0); leftX-=2; spanW+=4; do { out->x=leftX; out->width=spanW; } while(0); }
 } }
}
