#include "def.h"
#include "util.h"
#include <conio.h>

void waitforkey()
{
	while( !kbhit() );
}
