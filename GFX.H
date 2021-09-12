#ifndef _GFX_H
#define _GFX_H

// mode13   320x200  8-bit
#define SCRWIDTH 320
#define SCRHEIGHT 200

#define MAXSPRITES 256

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

struct sprite
{
	char width;
	char height;
	unsigned char* data;
};

void gfxinit();
void gfxshutdown();

void gfxclear(unsigned char c);

void gfxsetbgcolor(unsigned char c);


void pset(short x, short y, unsigned char c);
void fillrect(short x0, short y0, short x1, short y1, unsigned char c);
void drawtext(short x, short y, const char* txt);


const struct sprite* createsprite(char width, char height, const char* sz);
void drawsprite(const struct sprite* spr, float ox, float oy);




#endif
