#include "def.h"
#include "gfx.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
//#include <graphics.h>

volatile unsigned char far *gfx = (volatile unsigned char far*)0xA0000000L;

unsigned char bgColor = C_LIGHTCYAN;

unsigned short numSprites = 0;
struct sprite sprites[MAXSPRITES];

void gfxpageflip()
{

}

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
	return;//dunno wuts breakin

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
	unsigned short x;

	for(x=0; x<numSprites; x++)
	{
		struct sprite* spr = &sprites[x];

		free(spr->data);
	}
	numSprites = 0;


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


void fillrect(short x0, short y0, short x1, short y1, byte c)
{
	int x, y;

	for(y=y0; y<y1; y++)
		for(x=x0; x<x1; x++)
			pset(x, y, c);
}

void drawtext(short x, short y, const char* txt)
{
	gotoxy(x, y);

	//gfxsetbgcolor(bgColor);

	printf(txt);
}

byte DecodeColor(char c)
{
	// handle 0..9
	if( c >= '0' && c <= '9' )
	{
		return (byte)( c - '0' );
	}

	// handle a..f
	if( c >= 'a' && c <= 'f' )
	{
		return (byte)( c - 'a' + 9 + 1/*base offset from 0..9;  a is 10*/ );
	}

	switch(c)
	{
		//case '3': return 3;
		case 'r': return 4;// red?
		case ' ': return bgColor;
		default: return 12;// some dumb shit for unrec colors
	}
}

const struct sprite* createsprite(char width, char height, const char* sz)
{
	struct sprite* spr;

	if(numSprites >= MAXSPRITES)
		return 0;

	spr = &sprites[numSprites++];

	spr->width = width;
	spr->height = height;
	spr->data = malloc(width*height);

	{
		short x, y;
		unsigned char* sd = spr->data;

		for(y=0; y<spr->height; y++)
			for(x=0; x<spr->width; x++)
			{
				//long fx, fy;
				char c = *(sz++);
				unsigned char fc = DecodeColor(c);

				//fx = (long)ox + (long)x;
				//fy = (long)oy + (long)y;

				//pset((short)fx, (short)fy, fc);
				*(sd++) = fc;
			}
	}

	return spr;
}

void drawsprite(const struct sprite* spr, float ox, float oy)
{
	short x, y;
	unsigned char* sd = spr->data;

	for(y=0; y<spr->height; y++)
		for(x=0; x<spr->width; x++)
		{
			long fx, fy;
			unsigned char fc = *(sd++);

			fx = (long)ox + (long)x;
			fy = (long)oy + (long)y;

			pset((short)fx, (short)fy, fc);
		}
}
