#include "def.h"
#include "gfx.h"

volatile unsigned char far *gfx = (volatile unsigned char far*)0xA0000000L;

void gfxinit()
{
	// initialize VGA
	asm {
		mov ah, 0
		mov al, 13h
		int 10h
	}

	gfxclear(bgColor);
}

void gfxclear(byte c)
{
	short x,y;

	// clear background
	for(y=0; y<SCRHEIGHT; y++)
		for(x=0; x<SCRWIDTH; x++)
			pset(x, y, c); //gfx[x + y*SCRWIDTH] = 15;
	//_fmemset(gfx, 3, scrWidth*scrHeight);
}

// dunno doesnt seem to work for printf() in
// graphics mode..  and  conio.h's   cprintf() doesnt
// seem to work in graphics mode at all..  so *shrug*
void gfxsetbgcolor(byte c)
{
	asm {
		push ax
		push bx

		mov ah, 0bh
		xor bh, bh
		mov bl, c

		int 10h

		pop bx
		pop ax
	}
}

void gfxshutdown()
{

	// restore text mode
	asm {
		mov ah, 0
		mov al, 3
		int 10h
	}
}

void pset(short x, short y, byte c)
{
	if(x < 0 || x >= SCRWIDTH ||
		y < 0 || y >= SCRHEIGHT)
		return;

	gfx[ x + y*SCRWIDTH ] = c;
}



