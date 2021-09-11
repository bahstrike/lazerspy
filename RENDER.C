#include "def.h"
#include "render.h"
#include "gfx.h"
#include <conio.h>
#include <graphics.h>

extern unsigned char bgColor;

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

void drawsprite(const char* spr, short sprW, short sprH, short ox, short oy)
{
	short x, y;

	for(y=0; y<sprH; y++)
		for(x=0; x<sprW; x++)
		{
			long fx, fy;
			char c = *(spr++);
			unsigned char fc = DecodeColor(c);

			fx = (long)ox + (long)x;
			fy = (long)oy + (long)y;

			pset((short)fx, (short)fy, fc);
		}
}
