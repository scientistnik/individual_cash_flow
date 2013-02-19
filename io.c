#include "io.h"
#include <stdio.h>

void generalMenu(void);
static void clearScreen(void);
static void gotoxy(int x,int y);

void 
 generalMenu(void)
	{
		int x=10, y=10;
		clearScreen();
		return;
	}

void 
 clearScreen(void)
	{
		printf("\033[2J");
		printf("\033[0;0f");
		return;
	}

void
 gotoxy(int x,int y)
	{
		printf("\033[%d;%df",y,x);
		fflush(stdout);
	}
