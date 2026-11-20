typedef struct { u8 pad[0x20]; u16 x,y,unused,width; u8 gap,height; } TextBox27;
typedef struct { u8 pad[8]; TextBox27 *box; u16 align; u8 gap[14]; u8 flags; } TextStyle27;
u16 func_80018080(void *); u8 func_800182CC(void *);
void func_80027A7C(TextBox27 *out, TextStyle27 *style) {
 s32 combined=0, dx=0; TextStyle27 *previous=0; u16 width,measured,x,align,y; u8 height;
 if(out!=0) { if(style!=0) {
 if(style->flags&0x80) { measured=style->box->width; height=style->box->height; }
 else { measured=func_80018080(style->box); height=func_800182CC(style->box); }
 if(previous!=0) { if(previous->flags&0x80) combined=previous->box->width; else combined=func_80018080(previous->box);
 combined &= -((previous->align&0x40)==0);
 if(style->align&0x40) dx=previous->box->x-style->box->x;
 else dx=previous->box->x-(style->box->x+measured); }
 width=dx+(measured+combined); out->width=width; align=style->align;
 if(align&0x20) out->x=style->box->x-(width>>1);
 else { if(align&0x40) { x=style->box->x; if(previous==0)x-=width; else x-=measured; } else x=style->box->x; out->x=x; }
 if(style->flags&0x80)y=style->box->y-2; else y=style->box->y-4; out->y=y;
 x=out->x; width=out->width; out->height=height+4; out->x=x-2; out->width=width+4;
 } }
}
