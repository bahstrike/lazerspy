#include "def.h"
#include "gfx.h"
#include "util.h"
#include "render.h"

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <mem.h>


char* cratesprite4x4 =
"3333"
"3  3"
"3  3"
"3333"
;

char* guy8x8 =
"   r    "
"  r r   "
"   rr   "
" rrrrrr "
"    r   "
"   r r  "
"  r   r "
"  r   r "
;

unsigned char bgColor = C_LIGHTCYAN;

void main()
{
	short x, y;

	gfxinit();

	pset(10,10,1);	//gfx[ 10 + 10*scrWidth ] = 1;


	fillrect(0, SCRHEIGHT-30, SCRWIDTH, SCRHEIGHT, C_DARKGRAY);// TEST FILL
	fillrect(20, SCRHEIGHT-30, SCRWIDTH-20, SCRHEIGHT-15, C_BLUE);// TEST FILL

	for(x=10; x<300; x+=5)
		for(y=10; y<200; y+=130)
			drawsprite(cratesprite4x4, 4, 4, x, y);

	drawsprite(guy8x8, 8, 8, 100, 100);

	{
		int ver = 420;
		char sz[64];

		sprintf(sz, "lazerspy v%d.%d", (ver/100), (ver%100) );

		drawtext(1, 1, sz);

	}


	waitforkey();

	gfxshutdown();
}