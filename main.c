#include <stdio.h>
#include "io.h"

void generalMenu(void);

int active = 1;
int passive = 2;
int profit = 3;
int expanse = 4;
int balanse = -2;

void generalMenu(void);
void menuBalans(void);
void menuProfit(void);
void menuExpanse(void);
void menuActive(void);
void menuPassive(void);
FILE* openBalans(char* path);

unsigned int go_menu = GENERAL;
int main(void)
	{
		while(go_menu != EXIT )
			{
				switch(go_menu)
					{
					case GENERAL:	generalMenu();	break;
					case BALANS:	menuBalans();		break;
					case PROFIT:	menuProfit();		break;
					case EXPANSE:	menuExpanse();	break;
					case ACTIVE:	menuActive();		break;
					case PASSIVE: menuPassive();	break;
					default:break;
					}
			}
		return 0;
	}

void 
 generalMenu(void)
	{
		//unsigned int x, y;
		//clearScreen();
		//x = X_MAX/2; y = Y_MAX/2;
		gotoxy(x,y);
		printf("//--------------------------------//\n");
		printf("Сделайте выбор:\n1.Расчет баланса\n2.Доходы\n3.Расходы\n4.Активы\n5.Пассивы\n");
		printf("6.Задать файл истории\n");
		scanf("%d",&go_menu);
		getchar();
		if(go_menu == 0)	go_menu= EXIT;
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
