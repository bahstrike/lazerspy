#ifndef _WORLD_H
#define _WORLD_H

#include "thing.h"

#define MAXTHINGS 256

void worldinit();
void worldshutdown();

void worlddraw();
void worldprocess(float dt);

struct thing* creatething(const struct sprite* spr, float x, float y);

#endif