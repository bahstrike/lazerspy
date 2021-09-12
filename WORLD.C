#include "world.h"

static int numThings;
static struct thing things[MAXTHINGS];

void worldshutdown()
{

	numThings = 0;
}

void worldinit()
{
	unsigned short i;

	worldshutdown();

	for(i=0; i<MAXTHINGS; i++)
		thingreset(&things[i]);
}

void worlddraw()
{
	unsigned short x;
	for(x=0; x<numThings; x++)
	{
		const struct thing* th = &things[x];

		drawsprite(th->spr, th->x, th->y);
	}
}

void worldprocess(float dt)
{
	unsigned short x;
	for(x=0; x<numThings; x++)
	{
		struct thing* th = &things[x];

		th->x += th->vx * dt;
		th->y += th->vy * dt;
	}
}

struct thing* creatething(const struct sprite* spr, float x, float y)
{
	struct thing* th = 0;

	if(numThings >= MAXTHINGS)
		return 0;

	th = &things[numThings++];


	thingreset(th);
	th->x = x;
	th->y = y;
	th->spr = spr;

	return th;
}
