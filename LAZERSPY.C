#include "def.h"
#include "gfx.h"
#include "util.h"

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <mem.h>


sprite* cratesprite4x4 = 0;
char* _cratesprite4x4 =
"3333"
"3  3"
"3  3"
"3333"
;

sprite* guy8x8 = 0;
char* _guy8x8 =
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
	thing* plr;

	gfxinit();

	cratesprite4x4 = createsprite(4, 4, _cratesprite4x4);
	guy8x8 = createsprite(8, 8, _guy8x8);


	worldinit();

	plr = creatething(


	for(;;)
	{
		float dt = 1.0f / 20.0f; // some standard 20fps dt

		if(kbhit())
			break;

		pset(10,10,1);	//gfx[ 10 + 10*scrWidth ] = 1;


		fillrect(0, SCRHEIGHT-30, SCRWIDTH, SCRHEIGHT, C_DARKGRAY);// TEST FILL
		fillrect(20, SCRHEIGHT-30, SCRWIDTH-20, SCRHEIGHT-15, C_BLUE);// TEST FILL

		for(x=10; x<300; x+=5)
			for(y=10; y<200; y+=130)
				drawsprite(cratesprite4x4, x, y);

		drawsprite(guy8x8, 100, 100);

		{
			int ver = 420;
			char sz[64];

			sprintf(sz, "lazerspy v%d.%d", (ver/100), (ver%100) );

			drawtext(1, 1, sz);
		}

		worldprocess(dt);
		gfxpageflip();
	}

//	waitforkey();

	worldshutdown();
	gfxshutdown();
}