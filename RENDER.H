#ifndef _RENDER_H
#define _RENDER_H

enum color
{
	C_BLACK = 0,
	C_BLUE = 1,
	C_GREEN = 2,
	C_CYAN = 3,
	C_RED = 4,
	C_MAGENTA = 5,
	C_BROWN = 6,
	C_LIGHTGRAY = 7,
	C_DARKGRAY = 8,
	C_LIGHTBLUE = 9,
	C_LIGHTGREEN = 10,
	C_LIGHTCYAN = 11,
	C_LIGHTRED = 12,
	C_LIGHTMAGENTA = 13,
	C_YELLOW = 14,
	C_WHITE = 15
};

void drawtext(short x, short y, const char* txt);

void fillrect(short x0, short y0, short x1, short y1, byte c);

byte DecodeColor(char c);
void drawsprite(const char* spr, short sprW, short sprH, short ox, short oy);

#endif