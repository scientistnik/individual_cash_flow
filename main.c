#include <stdio.h>
#include "io.h"

void generalMenu(void);

int active = 1;
int passive = 2;
int profit = 3;
int expanse = 4;
int balanse = -2;

void generalMenu(void);
void menuStrrings(void);
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
					case SETTINGS: menuSettings();break;
					default:break;
					}
			}
		return 0;
	}

enum Balanse_t {
	QNT_PROFIT,
	QNT_EXPANCE,
	QNT_ACTIVE,
	QNT_PASSIVE
};

void
 menuSettings(void)
	{
		FILE *file;
		char str[50];
		int i;
		char number;
		enum Balanse_t select_qnt=QNT_PROFIT;

		file = fopen("./history/0102013.hry","r");
		if(file == NULL)
			{
				printf("Error file!");
				return 1;
			}
		while(fgets(str, 50, file) )
			{
				if(*str == "[PROFIT]") 
					{
						select_qnt = QNT_PROFIT;
						continue;
					}
				else if(*str == "[EXPANCE]")
					{
						select_qnt = QNT_EXPANCE;
						continue;
					}
				else if(*str == "[ACTIVE]")
					{
						select_qnt = QNT_ACTIVE;
						continue;
					}
				else if(*str == "[PASSIVE]")
					{
						select_qnt = QNT_PASSIVE;
						continue;
					}

				for(i=0; str[i]!=':'; i++);
				while( (str[i]!='\0')&& (str[i]!='\n'))
					{
						number = number*10 + str[i] - '0';
						i++;
					}
				
				switch(select_qnt)
					{
					case QNT_PROFIT:	profit +=number; break;
					case QNT_EXPANCE:	expanse+=number; break;
					case QNT_ACTIVE:	active +=number; break;
					case QNT_PASSIVE:	passive+=number; break;
					default:break;
					}
			}
	}

void 
 generalMenu(void)
	{
		//unsigned int x, y;
		//clearScreen();
		//x = X_MAX/2; y = Y_MAX/2;
		//gotoxy(x,y);
		printf("//--------------------------------//\n");
		printf("Прибыть (Profit): %d\n", profit);
		printf("Расход (Expense): %d\n", expanse);
		printf("Баланс (Balanse): %d\n", profit - expanse);
		printf("Актив (active): %d\n", active);
		printf("Пассив (Passive): %d\n", passive);
		printf("//--------------------------------//\n");
		printf("Сделайте выбор:\n1.Расчет баланса\n2.Доходы\n3.Расходы\n4.Активы\n5.Пассивы\n6.Задать файл истории\n0.Выход\n");
		scanf("%d",&go_menu);
		if(go_menu == 0)	go_menu= EXIT;
	}

void
	menuBalans(void)
	{
		FILE* file;
		char* str;
		char* buf;
		int i;
		balanse = active - passive;
	  //file = fopen("./history/012013.hry","w");
		//fputc('k', file);
		//fclose(file);
		//file = openBalans("./history/012013.hry");
		//printf("Активы: %d\nПассивы: %d\nБаланс: %d\n", profit, expanse, balanse);
		if((file = fopen("./history/012013.hry","r"))==NULL)
			{
				printf("Error file!\n");
				go_menu = GENERAL;
				return;
			}
		/*
		for(i=0;(str = fgetc(file));i++)
			printf("%c",str);
		*/
		/*
		fgets(buf, 1, file);
		*(str+1) = *buf;
		*(str+2) = '\0';
		printf("%c\n",str);
		*/
		go_menu = GENERAL;
	}

void 
	menuProfit(void)
	{
		unsigned int key;
		printf("Profit: %d\n1)Добавить доход\n0)Выход\n", profit);
		scanf("%d", &key);
		if(key == 1)
			{
				printf("Введите величину добавляемого дохода:\n");
				scanf("%d",&key);
				profit += key;
				printf("Profit: %d\n", profit);
			}
		go_menu = GENERAL;
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
