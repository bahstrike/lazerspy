#ifndef _THING_H
#define _THING_H

typedef struct _thing
{
	float x;
	float y;
	float vx;
	float vy;

} thing;

void thingreset(thing* t);

#endif