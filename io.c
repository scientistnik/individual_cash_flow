#include "io.h"
#include <stdio.h>

#define X_MAX	80
#define Y_MAX 25

void generalMenu(void);
void menuBalans(void);
void menuProfit(void);
void menuExpanse(void);
void menuActive(void);
void menuPassive(void);
FILE* openBalans(char* path);

static void clearScreen(void);
static void gotoxy(int x,int y);

int active = 1;
int passive = 2;
int profit = 3;
int expanse = 4;
int balanse = -2;
void 
 generalMenu(void)
	{
		//int x=X_MAX/2, y=Y_MAX/2;
		//clearScreen();
		int go_menu = 0;
		//gotoxy(x,y);
		printf("//--------------------------------//\n");
		printf("Сделайте выбор:\n1.Расчет баланса\n2.Доходы\n3.Расходы\n4.Активы\n5.Пассивы\n");
		printf("6.Задать файл истории\n");
		scanf("%d",&go_menu);
		getchar();
		switch(go_menu)
			{
			case 1:	menuBalans();		break;
			case 2: menuProfit(); 	break;
			case 3: menuExpanse();	break;
			case 4: menuActive();		break;
			case 5: menuPassive();	break;
			case 6: openBalans("./history/012013.hry");		break;
			default:									break;
			}
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

void
	menuBalans(void)
	{
		FILE* file;
		balanse = active - passive;
	  file = fopen("./history/012013.hry","w");
		fputc('k', file);
		fclose(file);
		file = openBalans("./history/012013.hry");
		printf("Активы: %d\nПассивы: %d\nБаланс: %d\n", profit, expanse, balanse);
	}

void 
	menuProfit(void)
	{
		printf("%d\n", profit);
		scanf("%d", &profit);
		getchar();
	}

void
	menuExpanse(void)
	{
		printf("%d\n",expanse);
		scanf("%d", &expanse);
		getchar();
	}

void 
	menuActive(void)
	{
		printf("%d\n", active);
		scanf("%d", &active);
		getchar();
	}

void menuPassive(void)
	{
		printf("%d\n", passive);
		scanf("%d", &passive);
		getchar();
	}

FILE* openBalans(char* path)
	{
		FILE* f;
		f = fopen(path,"r");
		return f;
	}
