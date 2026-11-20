typedef struct { u8 pad[0x20]; u16 x,y,unused,width; u8 gap,height; } TextBox27;
typedef struct { u8 pad[8]; TextBox27 *box; u16 align; u8 gap[14]; u8 flags; } TextStyle27;
s32 func_80018080(void *); s32 func_800182CC(void *);
void func_80027A7C(TextBox27 *out, TextStyle27 *style) {
 s32 combined=0, dx=0; TextStyle27 *previous=0; u16 width,x,align,y; s32 measured; u8 height;
 if(out!=0) { if(style!=0) {
 if(style->flags&0x80) { measured=style->box->width; height=style->box->height; }
 else { measured=func_80018080(style->box); height=func_800182CC(style->box); }
 if(previous!=0) { if(previous->flags&0x80) combined=previous->box->width; else combined=func_80018080(previous->box);
 combined &= -((previous->align&0x40)==0);
 if(style->align&0x40) dx=previous->box->x-style->box->x;
 else dx=previous->box->x-(style->box->x+measured); }
 out->width=width=dx+(measured+combined); align=style->align;
 if(align&0x20) out->x=style->box->x-((u16)width>>1);
 else { s32 left;
 if(align&0x40) { s32 anchor=style->box->x; if(previous!=0) { left=anchor-(u16)measured; goto store_x; } left=anchor-(u16)width; } else left=style->box->x;
 store_x: out->x=left; }
 if(style->flags&0x80)y=style->box->y-2; else y=style->box->y-4;
 do { out->y=y; } while(0);
 { s32 left=out->x; s32 span=out->width; do { out->height=height+4; } while(0); left-=2; span+=4; do { out->x=left; out->width=span; } while(0); }
 } }
}
