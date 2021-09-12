#ifndef _THING_H
#define _THING_H

#include "gfx.h"

struct thing
{
	float x;
	float y;
	float vx;
	float vy;

	const struct sprite* spr;
};

void thingreset(struct thing* t);

#endif