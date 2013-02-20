#include "io.h"
#include <stdio.h>

#define X_MAX	80
#define Y_MAX 25

void generalMenu(void);
static void clearScreen(void);
static void gotoxy(int x,int y);

void 
 generalMenu(void)
	{
		int x=X_MAX/2, y=Y_MAX/2;
		clearScreen();
		gotoxy(x,y);
		printf("Hello, World!");
	}

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
