#ifndef _GFX_H
#define _GFX_H

// mode13   320x200  8-bit
#define SCRWIDTH 320
#define SCRHEIGHT 200

extern byte bgColor;

void gfxinit();
void gfxshutdown();

void gfxclear(byte c);

void gfxsetbgcolor(byte c);

void pset(short x, short y, byte c);


#endif
