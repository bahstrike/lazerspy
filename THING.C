#include "thing.h"

void thingreset(struct thing* t)
{
	if(t == 0)
		return;

	t->x = 0.0f;
	t->y = 0.0f;
	t->vx = 0.0f;
	t->vy = 0.0f;

	t->spr = 0;
}
