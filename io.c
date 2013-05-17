#include "io.h"
#include <stdio.h>

void clearScreen(void);
void gotoxy(int x,int y);

void 
 clearScreen(void)
	{
		printf("\033[2J");
		printf("\033[0;0f");
	}

void
 gotoxy(int x,int y)
	{
		printf("\033[%d;%df",y,x);
		fflush(stdout);
	}
